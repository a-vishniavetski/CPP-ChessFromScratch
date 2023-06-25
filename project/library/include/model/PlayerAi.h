#ifndef CHESS_PLAYERAI_H
#define CHESS_PLAYERAI_H
#include <Player.h>
#include <typedefs.h>

class PlayerAi : public Player{
public:
    PlayerAi(const string &name, int upid, Color color);
    ~PlayerAi() override;
    UnitPtr chooseUnit(BoardPtr board) override;
    FieldPtr chooseMove(const vector<FieldPtr> &fields) override;

private:
    PlayerType player_type = AI;
};


#endif //CHESS_PLAYERAI_H
