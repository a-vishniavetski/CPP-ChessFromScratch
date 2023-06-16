//
// Created by avish on 5/29/2023.
//

#include "model/units/Knight.h"

string Knight::getIcon() {
    return icon;
}

Knight::Knight(const string &name, int uuid, const FieldPtr &field, bool alive, const string &icon) : Unit(name, uuid,
                                                                                                           field,
                                                                                                           alive),
                                                                                                      icon(icon) {}

Knight::Knight(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive) {}
