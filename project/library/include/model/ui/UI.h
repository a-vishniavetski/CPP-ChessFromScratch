//
// Created by Hubert Klonowski on 11/06/2023.
//

#ifndef CHESS_UI_H
#define CHESS_UI_H

#include "GameFrame.h"
#include "wx/wx.h"
#include <vector>
#include "typedefs.h"
#include "Game.h"
#include "ResultsFrame.h"
#include "MainFrame.h"

class UI : public wxFrame{
public:
    UI(const wxString& title, wxFrame& parent, GamePtr game, MainFrame& mainFrame);
    ~UI();
//
//    void update_units_pos(vector<UnitPtr> units);
    virtual void createBoard(int xDim, int yDim);
    virtual void populateBoard(BoardPtr board);

    void showResults();
    ResultsFrame* getResultsFrame();
    GameFrame* getGameFrame();
    MainFrame& getMainFrame();

private:
    GameFrame* gameFrame;
    ResultsFrame* resultsFrame;
    GamePtr game;
    wxFrame& parent;
    MainFrame& mainFrame;
};

#endif //CHESS_UI_H
