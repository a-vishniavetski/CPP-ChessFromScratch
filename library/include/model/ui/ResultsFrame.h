//
// Created by Hubert Klonowski on 18/06/2023.
//

#ifndef CHESS_RESULTSFRAME_H
#define CHESS_RESULTSFRAME_H

#include "Game.h"
#include "wx/wx.h"
#include "typedefs.h"

class UI;

class ResultsFrame : public wxFrame{
public:
    ResultsFrame(const wxString& title, wxFrame& parent, GamePtr game, GameFrame* gameFrame);

    ~ResultsFrame();

    void setWonText(string text);
    void setOutcomeText(string text);
private:
    GameFrame* gameFrame;
    wxFrame& parent;
    GamePtr game;
    void OnButtonClicked(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);

wxDECLARE_EVENT_TABLE();
};

#endif //CHESS_RESULTSFRAME_H
