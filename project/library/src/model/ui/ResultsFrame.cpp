//
// Created by Hubert Klonowski on 18/06/2023.
//

#include "Game.h"
#include "typedefs.h"
#include "wx/wx.h"
#include "ui/ResultsFrame.h"
#include "ui/UI.h"

#include <utility>

enum Ids{
    WHOWON_TEXT = 300,
    OUTCOME_TEXT = 301,
    MENU_BUTTON = 302
};

ResultsFrame::ResultsFrame(const wxString &title, wxFrame &parent, GamePtr game, GameFrame* gameFrame): wxFrame(&parent, 102, title), parent(parent), game(std::move(game)), gameFrame(gameFrame) {
    wxPanel *panel = new wxPanel(this);
    wxFont titleFont = wxFont(wxFontInfo());
    SetMinClientSize(wxSize(450, 250));
    SetMaxClientSize(wxSize(450, 250));
    titleFont.Scale(2.1).MakeBold();

    wxFont italic = wxFont(wxFontInfo());
    italic.Scale(2).MakeItalic();

    wxStaticText* text = new wxStaticText(this, wxID_ANY, "GAME OVER", wxPoint(100,50), wxSize(400,100));
    text->SetFont(titleFont);

    wxStaticText* whoWonText = new wxStaticText(this, WHOWON_TEXT, "", wxPoint(180,100), wxSize(100,50));
    whoWonText->SetFont(italic);

    wxStaticText* outcomeText = new wxStaticText(this, OUTCOME_TEXT, "", wxPoint(190,120), wxSize(100,50));
    whoWonText->SetFont(italic.Scale(0.5));

    wxButton* menuBtn = new wxButton(this, MENU_BUTTON, "Main Menu", wxPoint(180, 170), wxSize(100,50));
}
ResultsFrame::~ResultsFrame() {}

wxBEGIN_EVENT_TABLE(ResultsFrame, wxFrame)
                EVT_CLOSE(ResultsFrame::OnClose)
                EVT_BUTTON(wxID_ANY, ResultsFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

void ResultsFrame::OnButtonClicked(wxCommandEvent &event) {
    int id = event.GetId();
    switch(id){
        case MENU_BUTTON:
            this->Close();
            return;
    }
}

void ResultsFrame::OnClose(wxCloseEvent &event) {
    gameFrame->Close();
    Destroy();
    cout << "CLOSE";
    delete this;
    return;
}

void ResultsFrame::setWonText(string text) {
    wxStaticText* whowontxt = (wxStaticText*) wxWindow::FindWindowById(WHOWON_TEXT);
    whowontxt->SetLabelText(text);
    whowontxt->Update();
    whowontxt->Refresh();
}

void ResultsFrame::setOutcomeText(string text) {
    wxStaticText* outcometxt = (wxStaticText*) wxWindow::FindWindowById(OUTCOME_TEXT);
    outcometxt->SetLabelText(text);
    outcometxt->Update();
    outcometxt->Refresh();
}