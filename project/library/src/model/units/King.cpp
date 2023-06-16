//
// Created by avish on 5/29/2023.
//

#include "model/units/King.h"

string King::getIcon() {
    return icon;
}

King::King(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive) {}
