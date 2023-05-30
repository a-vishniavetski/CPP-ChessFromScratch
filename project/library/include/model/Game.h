#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <vector>
#include <typedefs.h>

using namespace std;


class Player;
class Board;


class Game {
public:
    // Konstruktor
    Game(const vector<PlayerPtr> &_players, BoardPtr const _board, int _totalTurns);


    void gameloop();
    void new_game();
    void place_unit_at(int x_coord, int y_coord, UnitPtr unit);

    virtual ~Game();

private:
    vector<PlayerPtr> players;
    BoardPtr board;
    int total_turns;
};


#endif //CHESS_GAME_H
