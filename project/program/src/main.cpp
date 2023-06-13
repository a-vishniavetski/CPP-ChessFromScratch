#include <iostream>
#include <Game.h>
#include <Player.h>
#include <Board.h>
#include <Field.h>
#include "Unit.h"
#include <typedefs.h>
#include <memory>
#include <sstream>
#include "wx/stdpaths.h"

#include "App.h"


#include "wx/wx.h"
#include "UI.h"

using namespace std;


void _print(BoardPtr board){
    int _len = 10;
    stringstream _prompt;

    for (int j = 7; j >= 0; j--){
        cout << "\n|";
        for (int i = 0; i < 8; i++){
            cout << " " << board->get_field(i, j)->get_field_info() << " |";
        }
    }
}

wxIMPLEMENT_APP_NO_MAIN(App);

int main(int argc, char *argv[]){

    wxString path = wxStandardPaths::Get().GetResourcesDir() + "/images/link.jpg";
    cout << path << endl;

    App* app = new App();
    wxApp::SetInstance(app);
    wxEntryStart(argc, argv);
//    wxTheApp->CallOnInit();

    app->CallOnInit();

//    app->getMainFrame()->Hide();

    //Player player_one("Player 1", 0, )
//    GamePtr g1 = make_shared<Game>(Game());
//
//    g1->new_game();
//    _print(g1->getBoard());
//
//    cout << "\nUnit stuff";
//    vector<PlayerPtr> temp = g1->getPlayers();
//    cout << temp[0]->get_all_units_info();
//    cout << "\n";
//    cout << g1->getPlayers()[1]->get_all_units_info();

    app->OnRun();


//
//    wxTheApp->OnRun();
    wxEntryCleanup();
    return 0;
}
