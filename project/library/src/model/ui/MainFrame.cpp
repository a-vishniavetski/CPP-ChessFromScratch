//
// Created by Hubert Klonowski on 11/06/2023.
//

#include "model/ui/MainFrame.h"
#include "model/ui/UI.h"
#include "Unit.h"
#include "wx/wx.h"
#include "Game.h"
#include "SaveManager.h"

#include <iostream>
#include <fstream>

#include "typedefs.h"

enum IDs{
    NEWGAME_BUTTON = 100,
    LOADGAME_BTN = 101
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MainFrame::OnButtonClicked)
//    EVT_CLOSE(MainFrame::OnClose)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString &title): wxFrame(nullptr, 99, title) {
    wxPanel* panel = new wxPanel(this);
    wxFont font(36, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL);

    wxStaticText* titleText = new wxStaticText(panel, wxID_ANY, "Chess", wxPoint(175, 50), wxSize(300,80));
    titleText->SetFont(font.MakeBold());

    wxButton* newGameBtn = new wxButton(panel, NEWGAME_BUTTON, "New Game", wxPoint(175, 140), wxSize(200, 50));
//    newGameBtn->SetFont(font);
    wxButton* loadGameBtn = new wxButton(panel, LOADGAME_BTN, "Load Game", wxPoint(175, 190), wxSize(200, 50));

    checkForSaveFile();

    SetMinClientSize(wxSize(600, 350));
    SetMaxClientSize(wxSize(600, 350));
//    CreateStatusBar();

//    panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);
}

void MainFrame::checkForSaveFile() {
    ifstream saveFile;
    saveFile.open("SaveData.txt");
    wxButton* btn = (wxButton*) wxWindow::FindWindowById(LOADGAME_BTN);
    if(saveFile) {
        btn->Enable(true);
    } else {
        btn->Enable(false);
    }
    btn->Update();
    btn->Refresh();
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
        gameStarted = true;

        GamePtr game = make_shared<Game>(Game());
        game->new_game(false, WHITE);
        BoardPtr board = game->getBoard();

        int x = board->getXDimension();
        int y = board->getYDimension();

        ui = new UI("Game", *this, game, *this);
        ui->create_board(x, y);
        ui->populate_board(board);
        return;
    }
    if(id == LOADGAME_BTN)
    {
        GamePtr game = make_shared<Game>(Game());
        game->new_game(false, WHITE);
        BoardPtr board = game->getBoard();
        int x = board->getXDimension();
        int y = board->getYDimension();
        ui = new UI("Game", *this, game, *this);
        ui->create_board(x, y);
        SaveManager* saveManager = new SaveManager(game, board);
        saveManager->LoadGame(game);
        ui->populate_board(board);
        ui->getGameFrame()->setTurnText();
        ui->getGameFrame()->updateAliveUnits();
        ui->getGameFrame()->checkForCheck();
        cout << endl << game->getTakenUnitsByColor(BLACK).size();
        cout << endl << game->getTakenUnitsByColor(WHITE).size();
    }

}

UI* MainFrame::getUI() {
    return ui;
}

bool MainFrame::getGameStarted() {
    return gameStarted;
}
//
//void MainFrame::OnClose(wxCloseEvent &event) {
//
//}