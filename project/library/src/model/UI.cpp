//
// Created by Hubert Klonowski on 11/06/2023.
//

#include "UI.h"
#include "GameFrame.h"
#include "wx/wx.h"
#include "typedefs.h"

UI::UI(const wxString& title, wxFrame& parent): wxFrame(&parent, wxID_ANY, title), parent(parent) {
    GameFrame* gameFrame = new GameFrame("Game", parent);
    gameFrame->SetClientSize(1280, 720);
    gameFrame->Center();
    gameFrame->Show();
}