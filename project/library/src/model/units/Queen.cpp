//
// Created by avish on 5/29/2023.
//

#include "model/units/Queen.h"

string Queen::getIcon() {
    return icon;
}

Queen::Queen(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive, BLACK) {}

Queen::Queen(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                  alive, color) {}

