#ifndef CHESS_PLAYERAI_H
#define CHESS_PLAYERAI_H
#include <Player.h>
#include <typedefs.h>

class PlayerAi : public Player{
public:
    PlayerAi(const string &name, int upid, Color color);
    ~PlayerAi() override;
    void chooseUnitField(FieldPtr field) override;
    void unsetUnit() override;
    FieldPtr getSelectedField() override;
    UnitPtr chooseUnit(BoardPtr board) override;
    FieldPtr chooseMove(const vector<FieldPtr> &fields) override;

private:
    PlayerType player_type = AI;
    FieldPtr selected_field = nullptr;
};


#endif //CHESS_PLAYERAI_H
