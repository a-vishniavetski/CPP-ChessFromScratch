//
// Created by Hubert Klonowski on 11/06/2023.
//
#include "GameFrame.h"
#include "UI.h"
#include "wx/wx.h"

enum IDs{
};
wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)
    EVT_CLOSE(GameFrame::OnClose)
wxEND_EVENT_TABLE()

GameFrame::GameFrame(const wxString &title, wxFrame& parent): wxFrame(&parent, wxID_ANY, title), parent(parent) {
    wxPanel *panel = new wxPanel(this);

    CreateStatusBar();

}

void GameFrame::OnClose(wxCloseEvent &event) {
    parent.Show();
    Destroy();
    delete this;
    return;
}