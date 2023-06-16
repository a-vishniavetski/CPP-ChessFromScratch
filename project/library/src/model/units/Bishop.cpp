//
// Created by avish on 5/29/2023.
//

#include "model/units/Bishop.h"

string Bishop::getIcon() {
    return icon;
}

Bishop::Bishop(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive,
                                                                                       BLACK) {}

Bishop::Bishop(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                    alive, color) {}
