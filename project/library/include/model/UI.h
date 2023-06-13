//
// Created by Hubert Klonowski on 11/06/2023.
//

#ifndef CHESS_UI_H
#define CHESS_UI_H

#include "GameFrame.h"
#include "wx/wx.h"
#include <vector>
#include "typedefs.h"

class UI : public wxFrame{
public:
    UI(const wxString& title, wxFrame& parent);
    ~UI();

    void update_units_pos(vector<UnitPtr> units);
    virtual void create_board(int xDim, int yDim);
    virtual void populate_board(BoardPtr board);
private:
    GameFrame* gameFrame;
    wxFrame& parent;
};

#endif //CHESS_UI_H
