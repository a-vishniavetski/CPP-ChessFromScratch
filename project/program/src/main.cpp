#include <iostream>
#include <Game.h>
#include <Player.h>
#include <Board.h>
#include <Field.h>
#include "Unit.h"
#include "Pawn.h"
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
    FieldPtr temp = nullptr;

    for (int j = 7; j >= 0; j--){
        cout << "\n|";
        for (int i = 0; i < 8; i++){
            if (!board->get_field(i, j)->isOccupied()){
                cout << " " << "    " << " |";
            }
            else{
                cout << " " << board->get_field(i, j)->getOccupiedByUnit()->getName() << " |";
            }
        }
    }
}

wxIMPLEMENT_APP_NO_MAIN(App);

int main(int argc, char *argv[]){
    std::setlocale(LC_CTYPE, "");
//    wxString path = wxStandardPaths::Get().GetResourcesDir() + "/images/link.jpg";
//    cout << path << endl;
//
//    App* app = new App();
//    wxApp::SetInstance(app);
    wxEntryStart(argc, argv);

    wxTheApp->CallOnInit();
//    app->CallOnInit();

//    app->getMainFrame()->Hide();



//    app->OnRun();


//
    wxTheApp->OnRun();
    wxEntryCleanup();
//    return wxEntry(argc, argv);
    return 0;
}
