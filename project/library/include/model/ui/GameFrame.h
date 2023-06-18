//
// Created by Hubert Klonowski on 11/06/2023.
//

#ifndef CHESS_GAMEFRAME_H
#define CHESS_GAMEFRAME_H

#include "wx/wx.h"
#include <vector>
#include "UI.h"
#include "typedefs.h"
#include "Game.h"

class GameFrame : public wxFrame
{
public:
    GameFrame(const wxString& title, wxFrame& parent, GamePtr game);
    ~GameFrame();
//    void update_unit_pos(vector<UnitPtr> units);
    void create_board(int xDim, int yDim);
    void populate_board(BoardPtr board);


    void setSelectedField(FieldPtr field);
    void unsetSelectedField();

    void update_unit_pos(UnitPtr unit);

    vector<int> getCoordsFromId(int id);

    wxButton* getButtonOfId(int id);


private:
    wxFrame& parent;
    GamePtr game;
    void OnMouseEvent(wxMouseEvent& event);
    void OnButtonClicked(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    FieldPtr selected_field = nullptr;
    void highlight_field(FieldPtr field, wxColour color);
    void revert_fields_colors();
    void setTurnText();

    void updateAliveUnits();



wxDECLARE_EVENT_TABLE();

};


#endif //CHESS_GAMEFRAME_H
