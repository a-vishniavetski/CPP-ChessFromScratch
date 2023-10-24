//
// Created by Hubert Klonowski on 11/06/2023.
//

#ifndef CHESS_APP_H
#define CHESS_APP_H

#include "wx/wx.h"
#include "MainFrame.h"
class App : public wxApp
{
public:
    App();
    MainFrame* mainFrame;

    bool OnInit();

    MainFrame* getMainFrame();

private:
};

#endif //CHESS_APP_H
