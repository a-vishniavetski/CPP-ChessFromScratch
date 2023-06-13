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

namespace fs = std::__fs::filesystem;

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
    EVT_BUTTON(200, GameFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

GameFrame::GameFrame(const wxString &title, wxFrame& parent): wxFrame(&parent, wxID_ANY, title), parent(parent) {
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
            UnitPtr unit = field->getOccupiedByUnit();
            string icon = unit->getIcon();
            btn->SetLabelText(icon);



            btn->Update();
            btn->Refresh();
            i++;
        }
    }

}

void GameFrame::create_board(int xDim, int yDim) {
    wxFont largeFont = wxFont(wxFontInfo()); largeFont.MakeLarger().MakeLarger().MakeBold().Scale(2);

    vector<Ids> ids = getVectorOfIds();

    vector<vector<wxButton*>> buttons;
    int i = 1;
    int k = 0;
    for(int x = 0; x < xDim; x++)
    {
        vector<wxButton*> xBtns;
        for(int y = 0; y < yDim; y++)
        {
            wxButton* btn = new wxButton(this, ids[k], "\n_\n", wxPoint(0 + (x * 80), 0 + (y * 80)), wxSize(70, 70));
            btn->SetFont(largeFont);
            if(i == 1)
            {
                btn->SetBackgroundColour(wxColour(196, 196, 196));
            }
            else
            {
                btn->SetBackgroundColour(wxColour(59, 59, 59));
            }

            btn->Update();
            btn->Refresh();
            i = 1 - i;
            xBtns.push_back(btn);
            cout << btn->GetId();
            k++;
        }
        i = 1 - i;
        buttons.push_back(xBtns);
    }


}

void GameFrame::OnButtonClicked(wxCommandEvent &event) {
    int id = event.GetId();
    cout << endl << id << endl;
}