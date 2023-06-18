//
// Created by Hubert Klonowski on 11/06/2023.
//

#include "model/ui/App.h"
#include "model/ui/MainFrame.h"
#include "wx/wx.h"
#include "typedefs.h"

App::App(){
//    OnInit();
};

bool App::OnInit() {
    mainFrame = new MainFrame("Main Window");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}

MainFrame* App::getMainFrame() {
    return mainFrame;
}