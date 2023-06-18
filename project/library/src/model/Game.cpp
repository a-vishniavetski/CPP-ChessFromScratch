#include <iostream>
#include <algorithm>
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
    place_unit_at(x_coord, y_coord, unit, this->board);
    player->addUnit(unit);
    *uuid_count += 1;
}

int Game::give_player_initial_units(PlayerPtr player, int initial_uuid) {
    int uuids = initial_uuid;
    FieldPtr temp_field = make_shared<Field>(nullptr);

    if (player->getColor() == WHITE){
        // piony
        for (int i = 0; i < 8; i++){
            // białe (drugi rząd na desce)
            create_and_place_unit(i,1,make_shared<Pawn>("Pawn", uuids, temp_field, true, WHITE),player,&uuids);
        }
        // wieży
        create_and_place_unit(0, 0, make_shared<Rook>("Rook", uuids, temp_field, true, WHITE), player, &uuids);
        create_and_place_unit(7, 0, make_shared<Rook>("Rook", uuids, temp_field, true, WHITE), player, &uuids);
        // knights
        create_and_place_unit(1, 0, make_shared<Knight>("Knight", uuids, temp_field, true, WHITE), player, &uuids);
        create_and_place_unit(6, 0, make_shared<Knight>("Knight", uuids, temp_field, true, WHITE), player, &uuids);
        // bishops
        create_and_place_unit(2, 0, make_shared<Bishop>("Bishop", uuids, temp_field, true, WHITE), player, &uuids);
        create_and_place_unit(5, 0, make_shared<Bishop>("Bishop", uuids, temp_field, true, WHITE), player, &uuids);
        // king and queen
        create_and_place_unit(3, 0, make_shared<Queen>("Queen", uuids, temp_field, true, WHITE), player, &uuids);
        create_and_place_unit(4, 0, make_shared<King>("King", uuids, temp_field, true, WHITE), player, &uuids);
    }
    else{
        // piony
        for (int i = 0; i < 8; i++){
            create_and_place_unit(i,6,make_shared<Pawn>("Pawn", uuids, temp_field, true, BLACK),player,&uuids);
        }
        // wieży
        create_and_place_unit(0, 7, make_shared<Rook>("Rook", uuids, temp_field, true, BLACK), player, &uuids);
        create_and_place_unit(7, 7, make_shared<Rook>("Rook", uuids, temp_field, true, BLACK), player, &uuids);
        // knights
        create_and_place_unit(1, 7, make_shared<Knight>("Knight", uuids, temp_field, true, BLACK), player, &uuids);
        create_and_place_unit(6, 7, make_shared<Knight>("Knight", uuids, temp_field, true, BLACK), player, &uuids);
        // bishops
        create_and_place_unit(2, 7, make_shared<Bishop>("Bishop", uuids, temp_field, true, BLACK), player, &uuids);
        create_and_place_unit(5, 7, make_shared<Bishop>("Bishop", uuids, temp_field, true, BLACK), player, &uuids);
        // king and queen
        create_and_place_unit(3, 7, make_shared<Queen>("Queen", uuids, temp_field, true, BLACK), player, &uuids);
        create_and_place_unit(4, 7, make_shared<King>("King", uuids, temp_field, true, BLACK), player, &uuids);
    }
    return uuids;
}

/*Tworzy nową grę z nowymi graczami i deską według standardowych reguł szachów*/
void Game::new_game(){
    // towrzymy deskę
    board = create_empty_board();
    // tworzymy graczy
    PlayerPtr player_white = make_shared<Player>("Player WHITE", 0, WHITE);
    PlayerPtr player_black = make_shared<Player>("Player BLACK", 2, BLACK);
    // tworzymy jednostki i ustawiamy ich na desce
    int next_uuid = give_player_initial_units(player_white, 0);
    give_player_initial_units(player_black, next_uuid);
    setPlayers(vector<PlayerPtr> {player_white, player_black});
}

void Game::place_unit_at(int x_coord, int y_coord, UnitPtr unit, BoardPtr board) {
    FieldPtr previous_field = unit->getField();

    if (previous_field != nullptr){
        previous_field->deoccupy();
    }

    FieldPtr new_field = board->get_field(x_coord, y_coord);
    //UnitPtr previous_unit = new_field->getOccupiedByUnit();
    //previous_unit->setField(nullptr);

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

void Game::setWhiteTurn(bool whiteTurn) {
    white_turn = whiteTurn;
}

bool Game::isWhiteTurn() const {
    return white_turn;
}

void Game::makeMove(UnitPtr unit, FieldPtr destination_field, BoardPtr board, GamePtr game) {
    string type = unit->getName();
    int from_x = unit->getField()->getXCoord();
    int from_y = unit->getField()->getYCoord();
    int to_x = destination_field->getXCoord();
    int to_y = destination_field->getYCoord();
    UnitPtr taken_unit = nullptr;
    PlayerPtr current_player;
    PlayerPtr enemy_player;
    for (auto player:getPlayers()){
        if (player->getColor() == unit->getColor()){
            current_player = player;
        }
        else{
            enemy_player = player;
        }
    }
    bool could_enpassant = false;

    if (!destination_field->isOccupied()){
        could_enpassant = true;
        place_unit_at(to_x, to_y, unit, this->board);
    } else{
        taken_unit = destination_field->getOccupiedByUnit();
        if (current_player->getColor() == WHITE) add_unit_to_taken(taken_unit, BLACK);
        else add_unit_to_taken(taken_unit, WHITE);

        place_unit_at(to_x, to_y, unit, this->board);
    }

    // PAWN
    if (unit->getName() == "Pawn"){
        // EN PASSANT
        if (from_x != to_x && could_enpassant){
            int enp_x = destination_field->getXCoord();
            int enp_y = 0;
            if (unit->getColor() == WHITE) enp_y = destination_field->getYCoord() - 1;
            if (unit->getColor() == BLACK) enp_y = destination_field->getYCoord() + 1;

            FieldPtr enp_field = board->get_field(enp_x, enp_y);
            taken_unit = enp_field->getOccupiedByUnit();
            taken_unit->setField(nullptr);
            enp_field->deoccupy();

            if (current_player->getColor() == WHITE) add_unit_to_taken(taken_unit, BLACK);
            else add_unit_to_taken(taken_unit, WHITE);
        }
        // DOUBLE MOVE
        if(abs(from_y - to_y) == 2){
            unit->setEnpassantable(true);
            //cout <<"DOUBLE MOVE";
            //cout << "\n" << to_string(unit->isEnpassantable());
        }
        // PROMOCJA
        if (unit->getColor() == WHITE && to_y == 7){
            int temp_uuid = unit->getUuid();
            FieldPtr temp_field = nullptr;
            UnitPtr temp = make_shared<Queen>("Queen", temp_uuid, temp_field, true, WHITE);
            current_player->addUnit(temp);
            place_unit_at(to_x, to_y, temp, this->board);
        }
        if (unit->getColor() == BLACK && to_y == 0){
            int temp_uuid = unit->getUuid();
            FieldPtr temp_field = nullptr;
            UnitPtr temp = make_shared<Queen>("Queen", temp_uuid, temp_field, true, BLACK);
            current_player->addUnit(temp);
            place_unit_at(to_x, to_y, temp, this->board);
        }
    }


    // Bicie na przelocie jest możliwe tylko w ciągu 1 ruchu
    for (auto unit: enemy_player->getUnits()){
        unit->setEnpassantable(false);
    }

    // IS CHECK?
    if(isCheckState(game, board, WHITE)){
        this->setCheckFor(WHITE, true);
    }
    else{
        this->setCheckFor(WHITE, false);
    }
    if(isCheckState(game, board, BLACK)){
        this->setCheckFor(BLACK, true);
    }
    else{
        this->setCheckFor(BLACK, false);
    }

    // ZMIEN GRACZA
    if (isWhiteTurn()){
        setWhiteTurn(false);
    }
    else{
        setWhiteTurn(true);
    }

}



vector<FieldPtr> Game::get_legal_moves(UnitPtr unit) {
    vector<FieldPtr> unchecked_moves = unit->get_moves(this->getBoard());
    vector<FieldPtr> legal_moves;
    FieldPtr unit_field = unit->getField();
    int x = unit_field->getXCoord();
    int y = unit_field->getYCoord();

    for (auto destination_field: unchecked_moves){
        // Tworzymy nową grę, deskę itp.
        GamePtr fake_game = make_shared<Game>();
        PlayerPtr player_white = make_shared<Player>("Player WHITE", 3, WHITE);
        PlayerPtr player_black = make_shared<Player>("Player BLACK", 4, BLACK);
        fake_game->setPlayers(vector<PlayerPtr> {player_white, player_black});
        BoardPtr fake_board = copy_board(this->board);
        fake_game->setBoard(fake_board);
        FieldPtr fake_destination_field = fake_board->get_field(destination_field->getXCoord(), destination_field->getYCoord());
        UnitPtr fake_unit = fake_board->get_field(x, y)->getOccupiedByUnit();
        // sprawdzamy co będzie jeśli zrobimy ten ruch
        fake_game->makeMove(fake_unit, fake_destination_field, fake_board, fake_game);
        if (!isCheckState(fake_game, fake_board, unit->getColor())){
            //unchecked_moves.erase(std::remove(unchecked_moves.begin(), unchecked_moves.end(), destination_field), unchecked_moves.end());
            legal_moves.push_back(destination_field);
        }
    }

    return legal_moves;
}


void Game::add_unit_to_taken(UnitPtr unit, Color color) {
    if (color == WHITE){
        taken_white_units.push_back(unit);
    }
    else{
        taken_black_units.push_back(unit);
    }
}

BoardPtr Game::copy_board(BoardPtr board) {
    BoardPtr retval = create_empty_board();
    UnitPtr actual_unit;
    UnitPtr temp_unit;
    FieldPtr temp_field;
    for (auto field:board->getFields()){
        int actual_x = field->getXCoord();
        int actual_y = field->getYCoord();
        temp_field = retval->get_field(actual_x, actual_y);

        // UNIT
        if (field->isOccupied()) {
            actual_unit = field->getOccupiedByUnit();
            string name = actual_unit->getName();
            string icon = actual_unit->getIcon();
            Color color = actual_unit->getColor();
            int UUID = actual_unit->getUuid();
            FieldPtr _field = nullptr;
            bool alive = actual_unit->isAlive();
            bool enpassantable = actual_unit->isEnpassantable();

            if (actual_unit->getName() == "Pawn") {
                temp_unit = make_shared<Pawn>(name, UUID, _field, alive, color);
            } else if (actual_unit->getName() == "Rook") {
                temp_unit = make_shared<Rook>(name, UUID, _field, alive, color);
            } else if (actual_unit->getName() == "Knight") {
                temp_unit = make_shared<Knight>(name, UUID, _field, alive, color);
            } else if (actual_unit->getName() == "Bishop") {
                temp_unit = make_shared<Bishop>(name, UUID, _field, alive, color);
            } else if (actual_unit->getName() == "Queen") {
                temp_unit = make_shared<Queen>(name, UUID, _field, alive, color);
            } else if (actual_unit->getName() == "King") {
                temp_unit = make_shared<King>(name, UUID, _field, alive, color);
            }


            place_unit_at(actual_x, actual_y, temp_unit, retval);
        }
    }
    return retval;
}

FieldPtr Game::findKingByColor(Color color) {
    // ZNALEŹĆ KRÓLA
    int king_x = -1;
    int king_y = -1;
    UnitPtr temp_unit;
    for(auto field:board->getFields()) {
        if (!field->isOccupied()) continue;
        temp_unit = field->getOccupiedByUnit();
        if (temp_unit->getName() == "King" && temp_unit->getColor() == color) {
            return field;
            break;
        }
    }
}

bool Game::isCheckState(GamePtr game, BoardPtr board, Color color) {
    // ZNALEŹĆ KRÓLA
    int king_x = -1;
    int king_y = -1;
    UnitPtr temp_unit;
    for(auto field:board->getFields()) {
        if (!field->isOccupied()) continue;
        temp_unit = field->getOccupiedByUnit();
        if (temp_unit->getName() == "King" && temp_unit->getColor() == color) {
            king_x = field->getXCoord();
            king_y = field->getYCoord();
            break;
        }
    }
    // CZY KTOŚ WIDZI KRÓLA
    temp_unit = nullptr;
    for(auto field:board->getFields())
    {
        if(!field->isOccupied()) continue;
        temp_unit = field->getOccupiedByUnit();
        if(temp_unit->getColor() != color)
        {
            // Czy ta jednostka może zrobić ruch na króla?
            vector<FieldPtr> moves = temp_unit->get_moves(board);
            for(auto move:moves)
            {
                if(move->getXCoord() == king_x && move->getYCoord() == king_y) return true; // JEST CHECK
            }
        }
    }
    return false;
}

bool Game::isCheckWhite() const {
    return is_check_white;
}

void Game::setIsCheckWhite(bool isCheckWhite) {
    is_check_white = isCheckWhite;
}

bool Game::isCheckBlack() const {
    return is_check_black;
}

void Game::setIsCheckBlack(bool isCheckBlack) {
    is_check_black = isCheckBlack;
}

bool Game::isMate() const {
    return is_mate;
}

void Game::setIsMate(bool isMate) {
    is_mate = isMate;
}

Color Game::getVictoryColor() const {
    return victory_color;
}

void Game::setVictoryColor(Color victoryColor) {
    victory_color = victoryColor;
}

void Game::setCheckFor(Color color, bool is_check) {
    if (color == WHITE){
        setIsCheckWhite(is_check);
    }
    else{
        setIsCheckBlack(is_check);
    }
}

vector<UnitPtr> Game::getTakenUnitsByColor(Color color) {
    if(color == BLACK)
        return taken_black_units;
    if(color == WHITE)
        return taken_white_units;
}