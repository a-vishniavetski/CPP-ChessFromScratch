#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <vector>
#include <typedefs.h>
#include "Board.h"

using namespace std;


class Player;
class Board;


class Game {
public:
    // Konstruktor
    Game();
    Game(const vector<PlayerPtr> &_players, BoardPtr const _board, int _totalTurns);


    void gameloop();
    void new_game();
    void place_unit_at(int x_coord, int y_coord, UnitPtr unit, BoardPtr board);
    BoardPtr create_empty_board() const;
    virtual ~Game();
    const vector<PlayerPtr> &getPlayers() const;
    void setPlayers(const vector<PlayerPtr> &players);
    BoardPtr getBoard() ;
    void setBoard(const BoardPtr &board);
    int getTotalTurns() const;
    void setTotalTurns(int totalTurns);
    bool isWhiteTurn() const;
    void setWhiteTurn(bool whiteTurn);
    void makeMove(UnitPtr unit, FieldPtr destination_field, BoardPtr board, GamePtr game);
    vector<FieldPtr> get_legal_moves(UnitPtr unit);
    void add_unit_to_taken(UnitPtr unit, Color color);
    BoardPtr copy_board(BoardPtr board);
    bool isCheckState(GamePtr game, BoardPtr board, Color color);
    bool isCheckWhite() const;
    void setIsCheckWhite(bool isCheckWhite);
    bool isCheckBlack() const;
    void setIsCheckBlack(bool isCheckBlack);
    void setCheckFor(Color color, bool is_check);
    bool isMate() const;
    void setIsMate(bool isMate);
    Color getVictoryColor() const;
    void setVictoryColor(Color victoryColor);

    FieldPtr findKingByColor(Color color);

    vector<UnitPtr> getTakenUnitsByColor(Color color);

private:
    vector<PlayerPtr> players;
    BoardPtr board;
    int total_turns;
    bool white_turn = true;
    bool is_check_white = false;
    bool is_check_black = false;
    bool is_mate = false;
    Color victory_color;
    PlayerPtr victory_player = nullptr;
    vector<UnitPtr> taken_white_units;
    vector<UnitPtr> taken_black_units;

    int give_player_initial_units(PlayerPtr player, int initial_uuid);
    void create_and_place_unit(int x_coord, int y_coord, UnitPtr unit, PlayerPtr player, int *uuid_count);
};


#endif //CHESS_GAME_H
