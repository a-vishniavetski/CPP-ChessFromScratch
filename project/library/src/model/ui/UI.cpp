//
// Created by Hubert Klonowski on 11/06/2023.
//

#include "model/ui/UI.h"
#include "model/ui/GameFrame.h"
#include "wx/wx.h"
#include "typedefs.h"
#include "model/ui/ResultsFrame.h"

UI::UI(const wxString& title, wxFrame& parent, GamePtr game, MainFrame& mainFrame): wxFrame(&parent, 200, title), parent(parent), game(game), mainFrame(mainFrame) {
    gameFrame = new GameFrame("Game", parent, game, this);
    gameFrame->SetClientSize(1120, 700);
    gameFrame->Center();
    gameFrame->Show();
}

UI::~UI() noexcept {
//    delete this;
}

MainFrame& UI::getMainFrame() {
    return mainFrame;
}

void UI::create_board(int xDim, int yDim) {
    gameFrame->create_board(xDim, yDim);
}

void UI::populate_board(BoardPtr board) {
    gameFrame->populate_board(board);
}

void UI::showResults() {
    resultsFrame = new ResultsFrame(wxT("GAME OVER"), *this, game, gameFrame);
    resultsFrame->SetClientSize(330, 200);
    resultsFrame->Center();
    resultsFrame->Show();

}

ResultsFrame* UI::getResultsFrame() {
    return resultsFrame;
}

GameFrame* UI::getGameFrame() {
    return gameFrame;
}