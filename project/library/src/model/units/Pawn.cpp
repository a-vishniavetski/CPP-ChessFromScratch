//
// Created by avish on 5/29/2023.
//

#include "model/units/Pawn.h"

Pawn::Pawn(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive, BLACK) {}

vector<FieldPtr> Pawn::get_moves(BoardPtr board) {
    return vector<FieldPtr>();
}

string Pawn::getIcon() {
    return icon;
}

Pawn::Pawn(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                alive, color) {}
