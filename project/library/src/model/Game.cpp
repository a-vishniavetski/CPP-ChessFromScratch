#include <Game.h>
#include <Field.h>
#include <Board.h>


using namespace std;


// Konstruktor
Game::Game(const vector<PlayerPtr> &_players, BoardPtr const _board, int _totalTurns) : players(_players), board(_board),
                                                                                        total_turns(_totalTurns) {}

/*
 * Podstawa całej gry, pętla która będzie się powtarzała przez cały czas grania, w niej pytami graczy o ruchi,
 * aktualizujemy parametry itp.
 */
void Game::gameloop() {
    // załadować grę z pamięci masowej albo stworzyć nową
    // todo zapisywanie/załądowanie gry z pamięci masowej
    bool game_running = true;

    while (game_running){

    }

    // sekcja dla zapisywania gry
}

Game::~Game() {

}

BoardPtr create_empty_board(){
    // tworzymy wszystkie pola deski
    vector<FieldPtr> _fields;
    _fields.resize(64);
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            // pole z obojgu X i Y parzystymi albo obojgu nie parzystymi zawsze jest czarne
            if (i % 2 != j % 2){
                _fields.push_back(make_shared<Field>(Field(i, j, "white")));
            }
            else{
                _fields.push_back(make_shared<Field>(Field(i, j, "black")));
            }
        }
    }

    // towrzymy deskę
    int x_dimension = 8;
    int y_dimension = 8;
    BoardPtr board = make_shared<Board>(x_dimension, y_dimension, _fields);

    return board;
}


/*Tworzy nową grę z nowymi graczami i deską według standardowych reguł szachów*/
void new_game(){
    // towrzymy deskę
    BoardPtr board = create_empty_board();

    // tworzymy jednostki i ustawiamy ich na desce
    // piony
    int uuids = 31;
    vector<UnitPtr> unit_set_one;
    unit_set_one.resize(16);
    for (int i = 0; i < 8; i++){
        //unit_set_one.push_back(make_shared<UnitPtr>(Unit()))
    }

    // tworzymy graczy
    //PlayerPtr player_one = make_shared<PlayerPtr>(Player())
}

