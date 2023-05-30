#include <iostream>
#include <Game.h>
#include <Player.h>
#include <Board.h>
#include <Field.h>
#include <typedefs.h>
#include <memory>
#include <sstream>

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
int main(){
    //Player player_one("Player 1", 0, )
    GamePtr g1 = make_shared<Game>(Game());
    g1->new_game();
    _print(g1->getBoard());

    cout << "\nUnit stuff";
    vector<PlayerPtr> temp = g1->getPlayers();
    cout << temp[0]->get_all_units_info();
    cout << "\n";
    cout << g1->getPlayers()[1]->get_all_units_info();

    cout << "\nReturning 0, out";
    string buf;
    getline(cin, buf);
    return 0;
}
