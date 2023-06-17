//
// Created by Hubert Klonowski on 11/06/2023.
//
#include "GameFrame.h"
#include "UI.h"
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


enum Ids{
    A1 = 00,    A2 = 10,    A3 = 20,    A4 = 30,    A5 = 40,    A6 = 50,    A7 = 60,    A8 = 70,
    B1 = 01,    B2 = 11,    B3 = 21,    B4 = 31,    B5 = 41,    B6 = 51,    B7 = 61,    B8 = 71,
    C1 = 02,    C2 = 12,    C3 = 22,    C4 = 32,    C5 = 42,    C6 = 52,    C7 = 62,    C8 = 72,
    D1 = 03,    D2 = 13,    D3 = 23,    D4 = 33,    D5 = 43,    D6 = 53,    D7 = 63,    D8 = 73,
    E1 = 04,    E2 = 14,    E3 = 24,    E4 = 34,    E5 = 44,    E6 = 54,    E7 = 64,    E8 = 74,
    F1 = 05,    F2 = 15,    F3 = 25,    F4 = 35,    F5 = 45,    F6 = 55,    F7 = 65,    F8 = 75,
    G1 = 06,    G2 = 16,    G3 = 26,    G4 = 36,    G5 = 46,    G6 = 56,    G7 = 66,    G8 = 76,
    H1 = 07,    H2 = 17,    H3 = 27,    H4 = 37,    H5 = 47,    H6 = 57,    H7 = 67,    H8 = 77
};

wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)
    EVT_CLOSE(GameFrame::OnClose)
    EVT_BUTTON(wxID_ANY, GameFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

GameFrame::GameFrame(const wxString &title, wxFrame& parent, GamePtr game): wxFrame(&parent, wxID_ANY, title), parent(parent), game(game) {
    wxPanel *panel = new wxPanel(this);

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

void GameFrame::update_unit_pos(vector<UnitPtr> units) {

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

            }

            btn->Refresh();
            btn->Update();


            i++;
            cout << btn->GetLabelText();
        }
    }
    this->Refresh();
    this->Update();

}


void GameFrame::create_board(int xDim, int yDim) {
    wxFont largeFont = wxFont(wxFontInfo()); largeFont.MakeBold().Scale(2);

    vector<Ids> ids = getVectorOfIds();

    vector<vector<wxButton*>> buttons;
    int i = 1;
    int k = 0;
    for(int x = 0; x < xDim; x++)
    {
        vector<wxButton*> xBtns;
        for(int y = 0; y < yDim; y++)
        {
            wxButton* btn = new wxButton(this, ids[k], "\n\n", wxPoint(0 + (x * 80), 0 + (y * 80)), wxSize(70, 70));
            btn->SetFont(largeFont);
            if(i == 1)
            {
                btn->SetBackgroundColour(WHITE_TILE);
            }
            else
            {
                btn->SetBackgroundColour(BLACK_TILE);
            }


            btn->Refresh();
            btn->Update();

            i = 1 - i;
            xBtns.push_back(btn);
            k++;
        }
        i = 1 - i;
        buttons.push_back(xBtns);
    }


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

    return id;
}

void GameFrame::highlight_field(FieldPtr field) {
    if(field == nullptr)
        return;
    wxButton* btn = getButtonOfId(getIdFromCoords(field->getXCoord(), field->getYCoord()));
    btn->SetBackgroundColour(POSSIBLE_MOVE);
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
}

void GameFrame::unsetSelectedField() {
    string x = to_string(selected_field->getXCoord());
    string y = to_string(selected_field->getYCoord());

    int xi = stoi(x);
    int yi = stoi(y);

    string XY = x + y;
    int id = stoi(XY);
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
    if(id < 0 || id > 77)
        return;
    vector<int> coords = getCoordsFromId(id);
    FieldPtr f = game->getBoard()->get_field(coords[0], coords[1]);

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
            highlight_field(possible_moves[i]);
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
            //game->place_unit_at(clicked_field->getXCoord(), clicked_field->getYCoord(), selected_field->getOccupiedByUnit());
            game->makeMove(selected_field->getOccupiedByUnit(), clicked_field, game->getBoard(), game);
            update_unit_pos(tempUnit);
            unsetSelectedField();
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

    btnFrom->SetLabelText("\n\n\n");
    btnFrom->Update();
    btnFrom->Refresh();

    btnTo->SetForegroundColour(getColour(unit->getColor()));
    btnTo->SetLabelText(unit->getIcon());
    btnTo->Update();
    btnFrom->Refresh();

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
    coords.push_back(x);
    coords.push_back(y);
    return coords;
}