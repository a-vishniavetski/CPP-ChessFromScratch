//
// Created by Hubert Klonowski on 11/06/2023.
//

#ifndef CHESS_GAMEFRAME_H
#define CHESS_GAMEFRAME_H

#include "wx/wx.h"
#include <vector>
#include "UI.h"
#include "typedefs.h"

class GameFrame : public wxFrame
{
public:
    GameFrame(const wxString& title, wxFrame& parent);
    ~GameFrame();
    void update_unit_pos(vector<UnitPtr> units);
    void create_board(int xDim, int yDim);
    void populate_board(BoardPtr board);

private:
    wxFrame& parent;
    void OnMouseEvent(wxMouseEvent& event);
    void OnButtonClicked(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);



wxDECLARE_EVENT_TABLE();

};


#endif //CHESS_GAMEFRAME_H
