//
// Created by Hubert Klonowski on 11/06/2023.
//

#include "model/ui/UI.h"
#include "model/ui/GameFrame.h"
#include "wx/wx.h"
#include "typedefs.h"

UI::UI(const wxString& title, wxFrame& parent, GamePtr game): wxFrame(&parent, 200, title), parent(parent), game(game) {
    gameFrame = new GameFrame("Game", parent, game);
    gameFrame->SetClientSize(1280, 720);
    gameFrame->Center();
    gameFrame->Show();
}

UI::~UI() noexcept {
//    delete this;
}

//void UI::update_units_pos(vector<UnitPtr> units) {
//    gameFrame->update_unit_pos(units);
//}

void UI::create_board(int xDim, int yDim) {
    gameFrame->create_board(xDim, yDim);
}

void UI::populate_board(BoardPtr board) {
    gameFrame->populate_board(board);
}