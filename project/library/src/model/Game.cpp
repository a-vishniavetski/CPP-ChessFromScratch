#include <Game.h>
#include <Field.h>
#include <Board.h>
#include <Unit.h>
#include <Player.h>
#include <Pawn.h>
#include <Rook.h>

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

void fill_classic_unit_sets(BoardPtr board, vector<UnitPtr>& unit_set_one, vector<UnitPtr>& unit_set_two){
    int uuids = 31;
    FieldPtr temp_field;
    UnitPtr temp_unit;
    unit_set_one.resize(16);
    unit_set_two.resize(16);

    // piony
    for (int i = 0; i < 8; i++){
        // białe (drugi rząd na desce)
        temp_unit.reset(new Pawn("Pawn", uuids, temp_field, true));
        
        unit_set_one.push_back(temp_unit);
        uuids = uuids - 1;

        // czarne (siódmy rząd na desce)
        temp_field = board->get_field(i, 7); // pole o iksie 'i' w siódmym rzędzie (czarne)
        temp_unit.reset(new Pawn("Pawn", uuids, temp_field, true));

        temp_field->occupy(temp_unit);

        unit_set_two.push_back(temp_unit);
        uuids = uuids - 1;
    }

    // wieży
    temp_field = board->get_field(1, 1);
    temp_unit.reset(new Rook("Rook", uuids, temp_field, true));
    temp_field->occupy(temp_unit);

}

/*Tworzy nową grę z nowymi graczami i deską według standardowych reguł szachów*/
void Game::new_game(){
    // towrzymy deskę
    BoardPtr board = create_empty_board();

    // tworzymy jednostki i ustawiamy ich na desce
    vector<UnitPtr> unit_set_one;
    vector<UnitPtr> unit_set_two;
    unit_set_one.resize(16);
    unit_set_two.resize(16);
    fill_classic_unit_sets(board, unit_set_one, unit_set_two);

    // tworzymy graczy
    //PlayerPtr player_one = make_shared<PlayerPtr>(Player())
}

void Game::place_unit_at(int x_coord, int y_coord, UnitPtr unit) {
    unit->getField()->deoccupy();
    FieldPtr temp_field = board->get_field(x_coord, y_coord);
    temp_field->occupy(unit);
}

