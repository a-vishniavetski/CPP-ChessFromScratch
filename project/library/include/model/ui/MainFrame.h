//
// Created by Hubert Klonowski on 11/06/2023.
//

#ifndef CHESS_MAINFRAME_H
#define CHESS_MAINFRAME_H

#include "wx/wx.h"
#include "UI.h"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);

    UI* getUI();
    bool getGameStarted();
private:
    UI* ui;
    bool gameStarted = false;

    void OnMouseEvent(wxMouseEvent& event);
    void OnButtonClicked(wxCommandEvent& event);
//    void OnClose(wxCloseEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif //CHESS_MAINFRAME_H
