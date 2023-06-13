//
// Created by Hubert Klonowski on 11/06/2023.
//

#include "UI.h"
#include "GameFrame.h"
#include "wx/wx.h"
#include "typedefs.h"

UI::UI(const wxString& title, wxFrame& parent): wxFrame(&parent, 200, title), parent(parent) {
    gameFrame = new GameFrame("Game", parent);
    gameFrame->SetClientSize(1280, 720);
    gameFrame->Center();
    gameFrame->Show();
}

UI::~UI() noexcept {
//    delete this;
}

void UI::update_units_pos(vector<UnitPtr> units) {
    gameFrame->update_unit_pos(units);
}

void UI::create_board(int xDim, int yDim) {
    gameFrame->create_board(xDim, yDim);
}

void UI::populate_board(BoardPtr board) {
    gameFrame->populate_board(board);
}