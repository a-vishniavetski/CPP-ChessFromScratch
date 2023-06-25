//
// Created by Hubert Klonowski on 11/06/2023.
//
#include "model/ui/GameFrame.h"
#include "model/ui/UI.h"
#include "wx/wx.h"
#include "wx/stdpaths.h"
#include <filesystem>
#include "Board.h"
#include "typedefs.h"
#include "Field.h"
#include "Unit.h"
#include <string>
#include "ui/MainFrame.h"
#include "SaveManager.h"
#include <exceptions.h>

const wxColour BLACK_TILE = wxColour(59, 59, 59);
const wxColour WHITE_TILE = wxColour(196, 196, 196);
const wxColour SELECTED_UNIT = wxColour(0, 155, 0);
const wxColour POSSIBLE_MOVE = wxColour(45, 0, 155);
const wxColour DANGER = wxColour(200, 0, 100);


enum Ids{
    //wxwidgets nie pozwala na uzycie id = 0, wiec pierwsze pole ma id = 78 (niestety)
    A1 = 78,    A2 = 10,    A3 = 20,    A4 = 30,    A5 = 40,    A6 = 50,    A7 = 60,    A8 = 70,
    B1 = 01,    B2 = 11,    B3 = 21,    B4 = 31,    B5 = 41,    B6 = 51,    B7 = 61,    B8 = 71,
    C1 = 02,    C2 = 12,    C3 = 22,    C4 = 32,    C5 = 42,    C6 = 52,    C7 = 62,    C8 = 72,
    D1 = 03,    D2 = 13,    D3 = 23,    D4 = 33,    D5 = 43,    D6 = 53,    D7 = 63,    D8 = 73,
    E1 = 04,    E2 = 14,    E3 = 24,    E4 = 34,    E5 = 44,    E6 = 54,    E7 = 64,    E8 = 74,
    F1 = 05,    F2 = 15,    F3 = 25,    F4 = 35,    F5 = 45,    F6 = 55,    F7 = 65,    F8 = 75,
    G1 = 06,    G2 = 16,    G3 = 26,    G4 = 36,    G5 = 46,    G6 = 56,    G7 = 66,    G8 = 76,
    H1 = 07,    H2 = 17,    H3 = 27,    H4 = 37,    H5 = 47,    H6 = 57,    H7 = 67,    H8 = 77,

    KNOCKED_OFF_UNITS_1 = 80,
    KNOCKED_OFF_UNITS_2 = 81,
    WHOSE_TURN_TEXT = 82,
    SURRENDER_BTN = 83,
    SAVE_GAME_BTN = 84
};

wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)
    EVT_CLOSE(GameFrame::OnClose)
    EVT_BUTTON(wxID_ANY, GameFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

GameFrame::GameFrame(const wxString &title, wxFrame& parent, GamePtr game, UI* ui): wxFrame(&parent, 101, title), parent(parent), game(game), ui(ui) {
    wxPanel *panel = new wxPanel(this);
    SetMinClientSize(wxSize(1120, 750));
    SetMaxClientSize(wxSize(1120, 750));
    SetOwnBackgroundColour(wxColour(179, 179, 179));

    wxFont infoFont = wxFont(wxFontInfo());
    infoFont.Scale(1.5);

    wxFont detailsFont = wxFont(wxFontInfo());
    detailsFont.Scale(1.2).MakeBold();

    wxFont chessFont = wxFont(wxFontInfo());
    chessFont.Scale(2).MakeBold();

    //buttons

    wxButton* surrenderBtn = new wxButton(this, SURRENDER_BTN, "SURRENDER", wxPoint(900, 20), wxSize(200, 70));
    surrenderBtn->SetFont(detailsFont);

    wxButton* saveGameBtn = new wxButton(this, SAVE_GAME_BTN, "SAVE GAME", wxPoint(900, 100), wxSize(200, 70));


    //text
    wxStaticText* text = new wxStaticText(this, wxID_ANY, "TURN: ", wxPoint(700, 20), wxSize(100,50));
    text->SetFont(infoFont);

    wxStaticText* whose_turn_text = new wxStaticText(this, WHOSE_TURN_TEXT, "WHITE", wxPoint(795, 21), wxSize(140,50));
    whose_turn_text->SetFont(detailsFont);

    wxStaticText* knocked_units_1_text = new wxStaticText(this, wxID_ANY, "KNOCKED:", wxPoint(700, 55), wxSize(140,50));
    knocked_units_1_text->SetFont(infoFont);

    wxStaticText* knocked_units_1 = new wxStaticText(this, KNOCKED_OFF_UNITS_1, "", wxPoint(720, 40), wxSize(100,600));
    knocked_units_1->SetFont(chessFont);
    knocked_units_1->SetForegroundColour(wxColour(255,255,255));

//    wxStaticText* knocked_units_2_text = new wxStaticText(this, wxID_ANY, "KNOCKED OFF BLACK:", wxPoint(700, 160), wxSize(100,50));
//    knocked_units_2_text->SetFont(infoFont);

    wxStaticText* knocked_units_2 = new wxStaticText(this, KNOCKED_OFF_UNITS_2, "", wxPoint(760, 40), wxSize(100,50));
    knocked_units_2->SetFont(chessFont);
    knocked_units_2->SetForegroundColour(wxColour(0,0,0));

    CreateStatusBar();

}
GameFrame::~GameFrame() noexcept {
}

void GameFrame::OnClose(wxCloseEvent &event) {
    parent.Show();
    ui->getMainFrame().checkForSaveFile();
    Destroy();
    delete this;
    return;
}

wxColour getColour(Color color)
{
    switch (color) {
        case BLACK:
            return *wxBLACK;
        case WHITE:
            return *wxWHITE;
    }
}

vector<Ids> getVectorOfIds()
{
    const Ids all[] = {A1, B1, C1, D1, E1, F1, G1, H1,
                       A2, B2, C2, D2, E2, F2, G2, H2,
                       A3, B3, C3, D3, E3, F3, G3, H3,
                       A4, B4, C4, D4, E4, F4, G4, H4,
                       A5, B5, C5, D5, E5, F5, G5, H5,
                       A6, B6, C6, D6, E6, F6, G6, H6,
                       A7, B7, C7, D7, E7, F7, G7, H7,
                       A8, B8, C8, D8, E8, F8, G8, H8};

    return vector<Ids>(all, all + sizeof(all) / sizeof(Ids));
}

void GameFrame::populateBoard(BoardPtr board) {
    int xDim = board->getXDimension();
    int yDim = board->getYDimension();

    vector<Ids> ids = getVectorOfIds();
    int i = 0;
    for(int y = 0; y < xDim; y++)
    {
        for(int x = 0; x < yDim; x++)
        {
            FieldPtr field = board->getField(y, x);

            wxButton* btn = (wxButton*) wxWindow::FindWindowById(ids[i]);
            if(field->isOccupied() == true)
            {
                UnitPtr unit = field->getOccupiedByUnit();
                string icon = unit->getIcon();
                Color color = unit->getColor();
                btn->wxControl::SetForegroundColour(wxColor(getColour(color)));
                btn->SetLabelText(icon);
                cout << endl << "FIELD: " << field->getOccupiedByUnit()->getIcon() << endl << "COORDS: " << "x=" << x << ", y=" << y << endl << "BTN ID=" << btn->GetId() << ", icon= " << btn->GetLabelText() << endl << "COLOR=" << color;
            }

            btn->Update();
            btn->Refresh();


            i++;
        }
    }
//    wxButton* a = getButtonOfId(ids[0]);
//    a->SetLabelText("TEST");
//    a->Update();
//    a->Refresh();
    this->Update();
    this->Refresh();

}


void GameFrame::createBoard(int xDim, int yDim) {
    wxFont largeFont = wxFont(wxFontInfo()); largeFont.MakeBold().Scale(2.2);
    wxFont coordsFont = wxFont(wxFontInfo()); coordsFont.Scale(1.5);

    vector<Ids> ids = getVectorOfIds();

    vector<char> literal_coords = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    vector<vector<wxButton*>> buttons;
    int i = 1;
    int k = 0;
    for(int x = 0; x < xDim; x++)
    {
        vector<wxButton*> xBtns;
        wxStaticText* coordsNum = new wxStaticText(this, wxID_ANY, to_string(xDim - x), wxPoint(20, 45 + (x * 80)), wxSize(70,70));
        coordsNum->SetFont(coordsFont);
        for(int y = yDim - 1; y >= 0 ; y--)
        {
            wxButton* btn = new wxButton(this, ids[k], "\n\n", wxPoint(50 + (x * 80), 20 + (y * 80)), wxSize(70, 70));
            btn->SetFont(largeFont);
            if(i == 1)
            {
                btn->SetBackgroundColour(WHITE_TILE);
            }
            else
            {
                btn->SetBackgroundColour(BLACK_TILE);
            }


            btn->Update();
            btn->Refresh();

            i = 1 - i;
            xBtns.push_back(btn);
            k++;
            if(x == xDim - 1)
            {
                wxStaticText* coordsLiterals = new wxStaticText(this, wxID_ANY, literal_coords[y], wxPoint(80 + (y * 80), 100 + (x * 80)), wxSize(70,70));
                coordsLiterals->SetFont(coordsFont);
            }
        }
        i = 1 - i;
        buttons.push_back(xBtns);
    }
    cout << "BTNS LENGTH " << k;

}

wxButton* GameFrame::getButtonOfId(int id) {
    return (wxButton*) wxWindow::FindWindowById(id);
}

void GameFrame::setSelectedField(FieldPtr field) {
    selected_field = field;
    string x = to_string(field->getXCoord());
    string y = to_string(field->getYCoord());

    string XY = x + y;

    int id = stoi(XY);

    wxButton* btn = getButtonOfId(id);
    btn->SetBackgroundColour(SELECTED_UNIT);
    btn->Update();
    btn->Refresh();
}

int getIdFromCoords(int xCoord, int yCoord)
{
    string x = to_string(xCoord);
    string y = to_string(yCoord);

    string XY = x + y;

    int id = stoi(XY);

    if(id == 0)
        id = 78;

    return id;
}

void GameFrame::highlightField(FieldPtr field, wxColour color) {
    if(field == nullptr)
        return;
    wxButton* btn = getButtonOfId(getIdFromCoords(field->getXCoord(), field->getYCoord()));
    btn->SetBackgroundColour(color);
    btn->Update();
    btn->Refresh();
}


void GameFrame::revertFieldsColors() {
    vector<Ids> ids = getVectorOfIds();

    int xDim = game->getBoard()->getXDimension();
    int yDim = game->getBoard()->getYDimension();

    int i = 1;
    int k = 0;
    for(int x = 0; x < xDim; x++)
    {
        for(int y = 0; y < yDim; y++)
        {
            int id = getIdFromCoords(x, y);
            wxButton* btn = getButtonOfId(id);
            if(i == 1)
            {
                btn->SetBackgroundColour(WHITE_TILE);
            }
            else
            {
                btn->SetBackgroundColour(BLACK_TILE);
            }

            btn->Update();
            btn->Refresh();
            i = 1 - i;
            k++;
        }
        i = 1 - i;
    }
    if(game->isCheckBlack())
    {
        FieldPtr king = game->findKingByColor(BLACK);
        highlightField(king, DANGER);
    }
    if(game->isCheckWhite())
    {
        FieldPtr king = game->findKingByColor(WHITE);
        highlightField(king, DANGER);
    }
}

void GameFrame::unsetSelectedField() {
    string x = to_string(selected_field->getXCoord());
    string y = to_string(selected_field->getYCoord());
//
    int xi = stoi(x);
    int yi = stoi(y);
//
//    string XY = x + y;
    int id = getIdFromCoords(xi, yi);
    wxButton* btn = getButtonOfId(id);

//    if(xi % 2 == 0 && yi % 2 == 0)
//        btn->SetBackgroundColour(WHITE_TILE);
//    if(xi % 2 == 0 && yi % 2 == 1)
//        btn->SetBackgroundColour(BLACK_TILE);
//    if(xi % 2 == 1 && yi % 2 == 0)
//        btn->SetBackgroundColour(BLACK_TILE);
//    if(xi % 2 == 1 && yi % 2 == 1)
//        btn->SetBackgroundColour(WHITE_TILE);

    revertFieldsColors();

    btn->Update();
    btn->Refresh();
    selected_field = nullptr;
}

void GameFrame::OnButtonClicked(wxCommandEvent &event) {
    int id = event.GetId();
    if(id == SURRENDER_BTN)
    {
        Color color;
        if(game->isWhiteTurn())
            color = WHITE;
        else color = BLACK;
        surrender(color);
        return;
    }

    if(id == SAVE_GAME_BTN)
    {
        SaveManager* saveManager = new SaveManager(game, game->getBoard());
        if(saveManager->SaveGame())
        {
            SetStatusText("Game saved!");
        }

        cout << endl << endl << "SAVING: " << saveManager->SaveGame();
        return;
    }
    //obsluga tylko przyciskow planszy
    if(id < 0 || id > 78)
        return;
    vector<int> coords = getCoordsFromId(id);
    FieldPtr f = game->getBoard()->getField(coords[0], coords[1]);

    if(game->isWhiteTurn() && selected_field == nullptr)
    {
        // OLD CODE
        //vector<FieldPtr> blacks = game->getBoard()->getFieldsOccupiedByColor(BLACK);
        // NEW CODE
        vector<FieldPtr> blacks;
        try {
            blacks = game->getBoard()->getFieldsOccupiedByColor(BLACK);
        }
        catch (NoUnitFoundException &e){
            cout << "NoUnitFoundException while trying to getFieldsOccupiedByColor in GameFrame";
            exit(1);
        }

        for(int i = 0; i < blacks.size(); i++)
        {
            if(f == blacks[i])
                return;
        }
    }

    if(game->isWhiteTurn() == false && selected_field == nullptr)
    {
        vector<FieldPtr> whites = game->getBoard()->getFieldsOccupiedByColor(WHITE);
        for(int i = 0; i < whites.size(); i++)
        {
            if(f == whites[i])
                return;
        }
    }


    wxButton* btn = getButtonOfId(id);
    if(selected_field == nullptr && f->isOccupied() == false)
        return;

    cout << endl << "x: " << coords[0] << ", y: " << coords[1];

    int x = coords[0];
    int y = coords[1];

    BoardPtr board = game->getBoard();
    FieldPtr field = board->getField(x, y);
    vector<FieldPtr> possible_moves;

    if(selected_field != nullptr)
    {
        UnitPtr unit = selected_field->getOccupiedByUnit();
        possible_moves = game->getLegalMoves(unit);
    }

    if(selected_field == nullptr)
    {
        setSelectedField(field);
        UnitPtr unit = field->getOccupiedByUnit();

         possible_moves = game->getLegalMoves(unit);
        //pokaz gdzie moge sie ruszyc

        for(int i = 0; i < possible_moves.size(); i++)
        {
            highlightField(possible_moves[i], POSSIBLE_MOVE);
        }

        return;
    }
    FieldPtr clicked_field = board->getField(x, y);
    if(clicked_field == selected_field) {
        unsetSelectedField();
        return;
    }

    for(int i = 0; i < possible_moves.size(); i++)
    {
        if(clicked_field == possible_moves[i])
        {
            UnitPtr tempUnit = selected_field->getOccupiedByUnit();
            Color color = tempUnit->getColor();
            //game->placeUnitAt(clicked_field->getXCoord(), clicked_field->getYCoord(), selected_field->getOccupiedByUnit());
            /* OLD CODE
            game->makeMove(selected_field->getOccupiedByUnit(), clicked_field, game->getBoard(), game);
            game->updateGameStatus(game, game->getBoard());*/
            // NEW CODE
            try {
                game->makeMove(selected_field->getOccupiedByUnit(), clicked_field, game->getBoard(), game);
                game->updateGameStatus(game, game->getBoard());
            }
            catch (NoUnitFoundException& e){
                cout << "NoUnitFoundException happened while trying to make a move";
                exit(1);
            }

            vector<UnitPtr> units;
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if(game->getBoard()->getField(i, j)->isOccupied())
                        units.push_back(game->getBoard()->getField(i, j)->getOccupiedByUnit());
                }
            }
//            updateUnitPos(clicked_field->getOccupiedByUnit());
            updateUnitPosArr(units);

            unsetSelectedField();
            setTurnText();
            updateAliveUnits();

            //check
            checkForCheck();

            if(game->isStalemate())
            {
                cout << endl << "GAME OVER, TIE (stalemate)" << endl;
                showResultsScreen("Stalemate");
            }

            checkForKnocks();
        }
    }
}

void GameFrame::checkForCheck() {
    if(game->isCheckBlack())
    {
        FieldPtr king = game->findKingByColor(BLACK);
        highlightField(king, DANGER);
        if(game->isCheckmateState(game, game->getBoard(), BLACK)){
            cout << endl <<  "GAME OVER, WHITE WON" << endl;
            showResultsScreen("Checkmate");
        }
    }

    if(game->isCheckWhite()){
        FieldPtr king = game->findKingByColor(WHITE);
        highlightField(king, DANGER);
        if(game->isCheckmateState(game, game->getBoard(), WHITE)) {
            cout << endl << "GAME OVER, BLACK WON" << endl;
            showResultsScreen("Checkmate");
        }
    }
}

void GameFrame::updateUnitPosArr(vector<UnitPtr> units) {
    for(int i = 0; i < units.size(); i++)
    {
        UnitPtr unit = units[i];
        FieldPtr field = unit->getField();

        int x = field->getXCoord();
        int y = field->getYCoord();
        int id = getIdFromCoords(x, y);

        int x1 = selected_field->getXCoord();
        int y1 = selected_field->getYCoord();
        int id1 = getIdFromCoords(x1, y1);

        wxButton* btnTo = getButtonOfId(id);
        wxButton* btnFrom = getButtonOfId(id1);
        btnTo->SetLabelText("\n\n");
        btnTo->Update();
        btnTo->Refresh();

        btnFrom->SetLabelText("\n\n");
        btnFrom->Update();
        btnFrom->Refresh();

        btnTo->wxButton::SetForegroundColour(wxColour(getColour(unit->getColor())));
        btnTo->SetLabelText(unit->getIcon());
        btnTo->Update();
        btnTo->Refresh();
    }
}


void GameFrame::updateUnitPos(UnitPtr unit) {
    FieldPtr field = unit->getField();

    int x = field->getXCoord();
    int y = field->getYCoord();
    int id = getIdFromCoords(x, y);

    int x1 = selected_field->getXCoord();
    int y1 = selected_field->getYCoord();
    int id1 = getIdFromCoords(x1, y1);

    wxButton* btnTo = getButtonOfId(id);
    wxButton* btnFrom = getButtonOfId(id1);
    btnTo->SetLabelText("\n\n");
    btnTo->Update();
    btnTo->Refresh();

    btnFrom->SetLabelText("\n\n");
    btnFrom->Update();
    btnFrom->Refresh();

    btnTo->wxButton::SetForegroundColour(wxColour(getColour(unit->getColor())));
    btnTo->SetLabelText(unit->getIcon());
    btnTo->Update();
    btnTo->Refresh();
}

vector<int> GameFrame::getCoordsFromId(int id) {
    vector<int> coords;
    if(id < 10 && id >= 0)
    {
        coords.push_back(0);
        coords.push_back(id);
        return coords;
    }

    int x = id / 10 % 10;
    int y = id % 10;
    if(x == 7 && y == 8)
        {x = 0; y = 0;}
    coords.push_back(x);
    coords.push_back(y);
    return coords;
}

void GameFrame::setTurnText() {
    wxStaticText* text = (wxStaticText*) wxWindow::FindWindowById(WHOSE_TURN_TEXT);
    if(game->isWhiteTurn() == false)
        text->SetLabelText("BLACK");
    else
        text->SetLabelText("WHITE");

    text->Update();
    text->Refresh();
}

void GameFrame::updateAliveUnits() {
    wxStaticText* knockedWhite = (wxStaticText*) wxWindow::FindWindowById(KNOCKED_OFF_UNITS_1);
    wxStaticText* knockedBlack = (wxStaticText*) wxWindow::FindWindowById(KNOCKED_OFF_UNITS_2);

    vector<UnitPtr> knockedWhiteUnits = game->getTakenUnitsByColor(WHITE);
    vector<UnitPtr> knockedBlackUnits = game->getTakenUnitsByColor(BLACK);

    string x = "";
    for(int i = 0; i < knockedWhiteUnits.size(); i++)
    {
        x.append("\n");
        x.append(knockedWhiteUnits[i]->getIcon());
    }

    knockedWhite->SetLabel(x);
    knockedWhite->Update();
    knockedWhite->Refresh();

    x = "";
    for(int i = 0; i < knockedBlackUnits.size(); i++)
    {
        x.append("\n");
        x.append(knockedBlackUnits[i]->getIcon());
    }

    knockedBlack->SetLabel(x);
    knockedBlack->Update();
    knockedBlack->Refresh();

}

void GameFrame::checkForKnocks() {
    int xDim = game->getBoard()->getXDimension();
    int yDim = game->getBoard()->getYDimension();

    for(int x = 0; x < xDim; x++)
    {
        for(int y = 0; y < yDim; y++)
        {
            FieldPtr field = game->getBoard()->getField(x, y);
            if(!field->isOccupied())
            {
                int id = getIdFromCoords(x, y);
                wxButton* btn = getButtonOfId(id);
                if(btn->GetLabelText() != "\n\n" || btn->GetLabelText() != "")
                {
                    btn->SetLabelText("\n\n");
                    btn->Update();
                    btn->Refresh();
                }
            }
        }
    }
}

void GameFrame::surrender(Color color) {
    string victoryColor = "";
    if(color == BLACK) {
        victoryColor = "WHITE";
        game->setVictoryColor(WHITE);
    }
    else {
        victoryColor = "BLACK";
        game->setVictoryColor(BLACK);
    }

    cout << endl << endl<< color << " GAVE UP" << endl << victoryColor << " WON!";
    setEnabledEveryButton(false);
    showResultsScreen("Surrender");
}

void GameFrame::setEnabledEveryButton(bool state) {
    vector<Ids> ids = getVectorOfIds();

    for(int i = 0; i < ids.size(); i++)
    {
        wxButton* btn = getButtonOfId(ids[i]);
        btn->Enable(state);
        btn->Update();
        btn->Refresh();
    }
    wxButton* surr = getButtonOfId(SURRENDER_BTN);
    surr->Enable(state);
    surr->Update();
    surr->Refresh();
}

void GameFrame::showResultsScreen(string outcome) {
    ui->showResults();
    string colorString;
    Color color = game->getVictoryColor();
    switch(color){
        case BLACK:
            colorString = "Black";
            break;
        case WHITE:
            colorString = "White";
            break;
    }
    ui->getResultsFrame()->setWonText(colorString + " WIN!");
    ui->getResultsFrame()->setOutcomeText(outcome);
}