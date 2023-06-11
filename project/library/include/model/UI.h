//
// Created by Hubert Klonowski on 11/06/2023.
//

#ifndef CHESS_UI_H
#define CHESS_UI_H

#include "GameFrame.h"
#include "wx/wx.h"

class UI : public wxFrame{
public:
    UI(const wxString& title, wxFrame& parent);
private:
    wxFrame& parent;
};

#endif //CHESS_UI_H
