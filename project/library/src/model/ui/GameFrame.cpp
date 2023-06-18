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
    WHOSE_TURN_TEXT = 82
};

wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)
    EVT_CLOSE(GameFrame::OnClose)
    EVT_BUTTON(wxID_ANY, GameFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

GameFrame::GameFrame(const wxString &title, wxFrame& parent, GamePtr game): wxFrame(&parent, 101, title), parent(parent), game(game) {
    wxPanel *panel = new wxPanel(this);

    wxFont infoFont = wxFont(wxFontInfo());
    infoFont.Scale(1.5);

    wxFont detailsFont = wxFont(wxFontInfo());
    detailsFont.Scale(1.5).MakeBold();

    wxFont chessFont = wxFont(wxFontInfo());
    chessFont.Scale(2.5).MakeBold();

    wxStaticText* text = new wxStaticText(this, wxID_ANY, "TURN: ", wxPoint(700, 40), wxSize(100,50));
    text->SetFont(infoFont);

    wxStaticText* whose_turn_text = new wxStaticText(this, WHOSE_TURN_TEXT, "WHITE", wxPoint(770, 40), wxSize(100,50));
    whose_turn_text->SetFont(detailsFont);

    wxStaticText* knocked_units_1_text = new wxStaticText(this, wxID_ANY, "KNOCKED OFF WHITE:", wxPoint(700, 100), wxSize(100,50));
    knocked_units_1_text->SetFont(infoFont);

    wxStaticText* knocked_units_1 = new wxStaticText(this, KNOCKED_OFF_UNITS_1, "", wxPoint(920, 90), wxSize(200,100));
    knocked_units_1->SetFont(chessFont);
    knocked_units_1->SetForegroundColour(wxColour(255,255,255));

    wxStaticText* knocked_units_2_text = new wxStaticText(this, wxID_ANY, "KNOCKED OFF BLACK:", wxPoint(700, 160), wxSize(100,50));
    knocked_units_2_text->SetFont(infoFont);

    wxStaticText* knocked_units_2 = new wxStaticText(this, KNOCKED_OFF_UNITS_2, "", wxPoint(920, 150), wxSize(200,100));
    knocked_units_2->SetFont(chessFont);
    knocked_units_2->SetForegroundColour(wxColour(0,0,0));

    CreateStatusBar();

}
GameFrame::~GameFrame() noexcept {
}

void GameFrame::OnClose(wxCloseEvent &event) {
    parent.Show();
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

void GameFrame::populate_board(BoardPtr board) {
    int xDim = board->getXDimension();
    int yDim = board->getYDimension();

    vector<Ids> ids = getVectorOfIds();
    int i = 0;
    for(int x = 0; x < xDim; x++)
    {
        for(int y = 0; y < yDim; y++)
        {
            FieldPtr field = board->get_field(x, y);

            wxButton* btn = (wxButton*) wxWindow::FindWindowById(ids[i]);
            if(field->isOccupied() == true)
            {

                UnitPtr unit = field->getOccupiedByUnit();
                string icon = unit->getIcon();
                Color color = unit->getColor();
                btn->wxControl::SetForegroundColour(wxColor(getColour(color)));
                btn->SetLabelText(icon);
                cout << endl << "FIELD: " << field->getOccupiedByUnit()->getIcon() << endl << "COORDS: " << "x=" << x << ", y=" << y << endl << "BTN ID=" << btn->GetId() << ", icon= " << btn->GetLabelText();
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


void GameFrame::create_board(int xDim, int yDim) {
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
        wxStaticText* coordsNum = new wxStaticText(this, wxID_ANY, to_string(x + 1), wxPoint(20, 45 + (x * 80)), wxSize(70,70));
        coordsNum->SetFont(coordsFont);
        for(int y = 0; y < yDim; y++)
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

void GameFrame::highlight_field(FieldPtr field, wxColour color) {
    if(field == nullptr)
        return;
    wxButton* btn = getButtonOfId(getIdFromCoords(field->getXCoord(), field->getYCoord()));
    btn->SetBackgroundColour(color);
    btn->Update();
    btn->Refresh();
}


void GameFrame::revert_fields_colors() {
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
        highlight_field(king, DANGER);
    }
    if(game->isCheckWhite())
    {
        FieldPtr king = game->findKingByColor(WHITE);
        highlight_field(king, DANGER);
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

    revert_fields_colors();

    btn->Update();
    btn->Refresh();
    selected_field = nullptr;
}

void GameFrame::OnButtonClicked(wxCommandEvent &event) {
    int id = event.GetId();
    //obsluga tylko przyciskow planszy
    if(id < 0 || id > 78)
        return;
    vector<int> coords = getCoordsFromId(id);
    FieldPtr f = game->getBoard()->get_field(coords[0], coords[1]);

    if(game->isWhiteTurn() && selected_field == nullptr)
    {
        vector<FieldPtr> blacks = game->getBoard()->getFieldsOccupiedByColor(BLACK);
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
    FieldPtr field = board->get_field(x, y);
    vector<FieldPtr> possible_moves;

    if(selected_field != nullptr)
    {
        UnitPtr unit = selected_field->getOccupiedByUnit();
        possible_moves = game->get_legal_moves(unit);
    }

    if(selected_field == nullptr)
    {
        setSelectedField(field);
        UnitPtr unit = field->getOccupiedByUnit();

         possible_moves = game->get_legal_moves(unit);
        //pokaz gdzie moge sie ruszyc

        for(int i = 0; i < possible_moves.size(); i++)
        {
            highlight_field(possible_moves[i], POSSIBLE_MOVE);
        }

        return;
    }
    FieldPtr clicked_field = board->get_field(x, y);
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
            //game->place_unit_at(clicked_field->getXCoord(), clicked_field->getYCoord(), selected_field->getOccupiedByUnit());
            game->makeMove(selected_field->getOccupiedByUnit(), clicked_field, game->getBoard(), game);
            game->updateGameStatus(game, game->getBoard());
            update_unit_pos(clicked_field->getOccupiedByUnit());


            unsetSelectedField();
            setTurnText();
            updateAliveUnits();

            //check
            if(game->isCheckBlack())
            {
                FieldPtr king = game->findKingByColor(BLACK);
                highlight_field(king, DANGER);
            }

            if(game->isCheckWhite()){
                FieldPtr king = game->findKingByColor(WHITE);
                highlight_field(king, DANGER);
            }
        }
    }
}

void GameFrame::update_unit_pos(UnitPtr unit) {
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
        x.append(" ");
        x.append(knockedWhiteUnits[i]->getIcon());
    }

    knockedWhite->SetLabel(x);
    knockedWhite->Update();
    knockedWhite->Refresh();

    x = "";
    for(int i = 0; i < knockedBlackUnits.size(); i++)
    {
        x.append(" ");
        x.append(knockedBlackUnits[i]->getIcon());
    }

    knockedBlack->SetLabel(x);
    knockedBlack->Update();
    knockedBlack->Refresh();

}