#ifndef CHESS_PLAYERHUMAN_H
#define CHESS_PLAYERHUMAN_H
#include <Player.h>
#include <typedefs.h>

class PlayerHuman : public Player{
public:
    PlayerHuman(const string &name, int upid, Color color);
    ~PlayerHuman() override;
    void chooseUnitField(FieldPtr field) override;
    void unsetUnit() override;

    FieldPtr getSelectedField() override;

    UnitPtr chooseUnit(BoardPtr board) override;
    FieldPtr chooseMove(const vector<FieldPtr> &fields) override;
private:
    PlayerType player_type = HUMAN;
    FieldPtr selected_field = nullptr;
    UnitPtr selected_unit = nullptr;
};


#endif //CHESS_PLAYERHUMAN_H
