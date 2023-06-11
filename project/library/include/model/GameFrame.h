//
// Created by Hubert Klonowski on 11/06/2023.
//

#ifndef CHESS_GAMEFRAME_H
#define CHESS_GAMEFRAME_H

#include "wx/wx.h"

class GameFrame : public wxFrame
{
public:
    GameFrame(const wxString& title, wxFrame& parent);


private:
    wxFrame& parent;
    void OnMouseEvent(wxMouseEvent& event);
    void OnButtonClicked(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);

    void update_unit_pos();


wxDECLARE_EVENT_TABLE();

};


#endif //CHESS_GAMEFRAME_H
