//
// Created by Hubert Klonowski on 11/06/2023.
//

#include "MainFrame.h"
#include "UI.h"
#include "wx/wx.h"

enum IDs{
    NEWGAME_BUTTON = 1,
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(NEWGAME_BUTTON, MainFrame::OnButtonClicked)
//    EVT_CLOSE(MainFrame::OnClose)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString &title): wxFrame(nullptr, 99, title) {
    wxPanel* panel = new wxPanel(this);
    wxFont font(36, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL);
    wxButton* newGameBtn = new wxButton(panel, NEWGAME_BUTTON, "New Game", wxPoint(300, 50), wxSize(200, 150));
//    newGameBtn->SetFont(font);

    CreateStatusBar();

    panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);
}

void MainFrame::OnMouseEvent(wxMouseEvent &event) {
    wxPoint mousePos = event.GetPosition();
    wxString msg = wxString::Format("Mouse Event Detected on: x=%d, y=%d", mousePos.x, mousePos.y);
    wxLogStatus(msg);
}

void MainFrame::OnButtonClicked(wxCommandEvent &event) {
    int id = event.GetId();
    if(id == NEWGAME_BUTTON)
    {
        this->Hide();

        UI* ui = new UI("Game", *this);

    }
    wxString msg = wxString::Format("Button clicked, ID=%d", event.GetId());
    wxLogStatus(msg);
}
//
//void MainFrame::OnClose(wxCloseEvent &event) {
//
//}