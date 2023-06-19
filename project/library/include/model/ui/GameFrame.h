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
#include "MainFrame.h"

class GameFrame : public wxFrame
{
public:
    GameFrame(const wxString& title, wxFrame& parent, GamePtr game, UI* ui);
    ~GameFrame();
//    void updateUnitPos(vector<UnitPtr> units);
    void createBoard(int xDim, int yDim);
    void populateBoard(BoardPtr board);


    void setSelectedField(FieldPtr field);
    void unsetSelectedField();

    void updateUnitPos(UnitPtr unit);
    void updateUnitPosArr(vector<UnitPtr> units);

    vector<int> getCoordsFromId(int id);

    wxButton* getButtonOfId(int id);

    void checkForKnocks();
    void updateAliveUnits();

    void setTurnText();
    void checkForCheck();

private:
    wxFrame& parent;
    GamePtr game;
    void OnMouseEvent(wxMouseEvent& event);
    void OnButtonClicked(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    FieldPtr selected_field = nullptr;
    void highlight_field(FieldPtr field, wxColour color);
    void revert_fields_colors();

    void surrender(Color color);
    void showResultsScreen(string outcome);

    void set_enabled_every_button(bool state);

    UI* ui;



wxDECLARE_EVENT_TABLE();

};


#endif //CHESS_GAMEFRAME_H
