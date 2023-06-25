#ifndef CHESS_PLAYERHUMAN_H
#define CHESS_PLAYERHUMAN_H
#include <Player.h>
#include <typedefs.h>

class PlayerHuman : public Player{
public:
    PlayerHuman(const string &name, int upid, Color color);
    ~PlayerHuman() override;
    FieldPtr chooseMove(const vector<FieldPtr> &fields) override;
    virtual UnitPtr chooseUnit(BoardPtr board) override;
private:
    PlayerType player_type = HUMAN;
};


#endif //CHESS_PLAYERHUMAN_H
