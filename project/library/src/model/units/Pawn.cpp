//
// Created by avish on 5/29/2023.
//

#include "model/units/Pawn.h"

Pawn::Pawn(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive) {}

vector<FieldPtr> Pawn::get_moves(BoardPtr board) {
    return vector<FieldPtr>();
}
