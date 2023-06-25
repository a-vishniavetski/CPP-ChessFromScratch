#include "PlayerHuman.h"

PlayerHuman::PlayerHuman(const string &name, int upid, Color color) : Player(name, upid, color) {}

PlayerHuman::~PlayerHuman() {

}

// nie muszę być wywoływane w ogóle
FieldPtr PlayerHuman::chooseMove(const vector<FieldPtr> &fields) {
    return FieldPtr();
}

UnitPtr PlayerHuman::chooseUnit(BoardPtr board) {
    return UnitPtr();
}
