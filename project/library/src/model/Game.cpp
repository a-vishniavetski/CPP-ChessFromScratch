#include <iostream>
#include <Game.h>
#include <Field.h>
#include <Board.h>
#include <Unit.h>
#include <Player.h>
#include <Pawn.h>
#include <Rook.h>

using namespace std;


// Konstruktor
Game::Game(){}

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

BoardPtr Game::create_empty_board() const {
    // tworzymy wszystkie pola deski
    vector<FieldPtr> _fields;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            // pole z obojgu X i Y parzystymi albo obojgu nie parzystymi zawsze jest czarne
            if ((i + 1) % 2 != (j + 1) % 2){
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

void Game::fill_classic_unit_sets(vector<UnitPtr>& unit_set_one, vector<UnitPtr>& unit_set_two){
    // todo wszystkie pozostałe jednostki
    int uuids = 31;
    FieldPtr temp_field = make_shared<Field>(nullptr);
    UnitPtr temp_unit;

    // piony
    for (int i = 0; i < 8; i++){
        // białe (drugi rząd na desce)
        temp_unit.reset(new Pawn("Pawn", uuids, temp_field, true));
        place_unit_at(i, 1, temp_unit);
        unit_set_one.push_back(temp_unit);
        uuids = uuids - 1;

        // czarne (siódmy rząd na desce)
        temp_unit.reset(new Pawn("Pawn", uuids, temp_field, true));
        place_unit_at(i, 6, temp_unit);
        unit_set_two.push_back(temp_unit);
        uuids = uuids - 1;
    }

    // wieży
    temp_field = board->get_field(1, 1);
    temp_unit.reset(new Rook("Rook", uuids, temp_field, true));
    temp_field->occupy(temp_unit);
    unit_set_one.push_back(temp_unit);
    uuids = uuids - 1;

}

/*Tworzy nową grę z nowymi graczami i deską według standardowych reguł szachów*/
void Game::new_game(){
    // towrzymy deskę
    board = create_empty_board();

    // tworzymy jednostki i ustawiamy ich na desce
    vector<UnitPtr> unit_set_one;
    vector<UnitPtr> unit_set_two;
    fill_classic_unit_sets(unit_set_one, unit_set_two);

    // tworzymy graczy
    PlayerPtr player_one = make_shared<Player>(Player("Player 1", 0, unit_set_one));
    PlayerPtr player_two = make_shared<Player>(Player("Player 2", 2, unit_set_two));

    setPlayers(vector<PlayerPtr> {player_one, player_two});
}

void Game::place_unit_at(int x_coord, int y_coord, UnitPtr unit) {
    FieldPtr previous_field = unit->getField();

    if (previous_field != nullptr){
        previous_field->deoccupy();
    }

    FieldPtr new_field = board->get_field(x_coord, y_coord);
    // todo field not found exception
    new_field->occupy(unit);
    unit->setField(new_field);
}

const vector<PlayerPtr> &Game::getPlayers() const {
    return players;
}

void Game::setPlayers(const vector<PlayerPtr> &players) {
    Game::players = players;
}

BoardPtr Game::getBoard()  {
    return board;
}

void Game::setBoard(const BoardPtr &board) {
    Game::board = board;
}

int Game::getTotalTurns() const {
    return total_turns;
}

void Game::setTotalTurns(int totalTurns) {
    total_turns = totalTurns;
}

