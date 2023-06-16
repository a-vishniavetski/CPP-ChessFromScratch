//
// Created by avish on 5/29/2023.
//

#include "model/units/Pawn.h"

string Pawn::getIcon() {
    return icon;
}

Pawn::Pawn(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                alive, color) {}
