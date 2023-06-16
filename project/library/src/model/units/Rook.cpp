//
// Created by avish on 5/29/2023.
//

#include "model/units/Rook.h"

Rook::Rook(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive, BLACK) {}

vector<FieldPtr> Rook::get_moves(BoardPtr board) {
    return vector<FieldPtr>();
}

string Rook::getIcon() {
    return icon;
}

Rook::Rook(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                alive, color) {}
