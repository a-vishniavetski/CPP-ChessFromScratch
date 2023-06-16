#include <iostream>
#include <Game.h>
#include <Field.h>
#include <Board.h>
#include <Unit.h>
#include <Player.h>
#include <Pawn.h>
#include <Rook.h>
#include <Knight.h>
#include <Bishop.h>
#include <Queen.h>
#include <King.h>

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

void Game::create_and_place_unit(int x_coord, int y_coord, UnitPtr unit, PlayerPtr player, int* uuid_count){
    place_unit_at(x_coord, y_coord, unit);
    player->addUnit(unit);
    *uuid_count += 1;
}

int Game::give_player_initial_units(PlayerPtr player, int initial_uuid) {
    int uuids = initial_uuid;
    FieldPtr temp_field = make_shared<Field>(nullptr);
    UnitPtr temp_unit;

    if (player->getColor() == WHITE){
        // piony
        for (int i = 0; i < 8; i++){
            // białe (drugi rząd na desce)
            create_and_place_unit(i,1,make_shared<Pawn>("Pawn", uuids, temp_field, true),player,&uuids);
        }
        // wieży
        create_and_place_unit(0, 0, make_shared<Rook>("Rook", uuids, temp_field, true), player, &uuids);
        create_and_place_unit(7, 0, make_shared<Rook>("Rook", uuids, temp_field, true), player, &uuids);
        // knights
        create_and_place_unit(1, 0, make_shared<Knight>("Knight", uuids, temp_field, true), player, &uuids);
        create_and_place_unit(6, 0, make_shared<Knight>("Knight", uuids, temp_field, true), player, &uuids);
        // bishops
        create_and_place_unit(2, 0, make_shared<Bishop>("Bishop", uuids, temp_field, true), player, &uuids);
        create_and_place_unit(5, 0, make_shared<Bishop>("Bishop", uuids, temp_field, true), player, &uuids);
        // king and queen
        create_and_place_unit(3, 0, make_shared<Queen>("Queen", uuids, temp_field, true), player, &uuids);
        create_and_place_unit(4, 0, make_shared<King>("King", uuids, temp_field, true), player, &uuids);
    }
    else{
        // piony
        for (int i = 0; i < 8; i++){
            create_and_place_unit(i,6,make_shared<Pawn>("Pawn", uuids, temp_field, true),player,&uuids);
        }
        // wieży
        create_and_place_unit(0, 7, make_shared<Rook>("Rook", uuids, temp_field, true), player, &uuids);
        create_and_place_unit(7, 7, make_shared<Rook>("Rook", uuids, temp_field, true), player, &uuids);
        // knights
        create_and_place_unit(1, 7, make_shared<Knight>("Knight", uuids, temp_field, true), player, &uuids);
        create_and_place_unit(6, 7, make_shared<Knight>("Knight", uuids, temp_field, true), player, &uuids);
        // bishops
        create_and_place_unit(2, 7, make_shared<Bishop>("Bishop", uuids, temp_field, true), player, &uuids);
        create_and_place_unit(5, 7, make_shared<Bishop>("Bishop", uuids, temp_field, true), player, &uuids);
        // king and queen
        create_and_place_unit(3, 7, make_shared<Queen>("Queen", uuids, temp_field, true), player, &uuids);
        create_and_place_unit(4, 7, make_shared<King>("King", uuids, temp_field, true), player, &uuids);
    }
    return uuids;
}

/*Tworzy nową grę z nowymi graczami i deską według standardowych reguł szachów*/
void Game::new_game(){
    // towrzymy deskę
    board = create_empty_board();
    // tworzymy graczy
    PlayerPtr player_white = make_shared<Player>("Player 1", 0, WHITE);
    PlayerPtr player_black = make_shared<Player>("Player 2", 2, BLACK);
    // tworzymy jednostki i ustawiamy ich na desce
    int next_uuid = give_player_initial_units(player_white, 0);
    give_player_initial_units(player_black, 0);


    setPlayers(vector<PlayerPtr> {player_white, player_black});
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

