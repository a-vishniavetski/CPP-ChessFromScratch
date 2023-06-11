//
// Created by Hubert Klonowski on 11/06/2023.
//

#include "model/App.h"
#include "MainFrame.h"
#include "wx/wx.h"
#include "typedefs.h"

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("Main Window");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}