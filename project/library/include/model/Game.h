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
    void place_unit_at(int x_coord, int y_coord, UnitPtr unit);
    BoardPtr create_empty_board() const;
    virtual ~Game();
    const vector<PlayerPtr> &getPlayers() const;
    void setPlayers(const vector<PlayerPtr> &players);
    BoardPtr getBoard() ;
    void setBoard(const BoardPtr &board);
    int getTotalTurns() const;
    void setTotalTurns(int totalTurns);



private:
    vector<PlayerPtr> players;
    BoardPtr board;
    int total_turns;

    int give_player_initial_units(PlayerPtr player, int initial_uuid);

    void create_and_place_unit(int x_coord, int y_coord, UnitPtr unit, PlayerPtr player, int *uuid_count);
};


#endif //CHESS_GAME_H
