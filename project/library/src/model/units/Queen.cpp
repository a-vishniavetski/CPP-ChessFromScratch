//
// Created by avish on 5/29/2023.
//

#include "model/units/Queen.h"
#include "typedefs.h"
#include "Field.h"
#include "Board.h"

string Queen::getIcon() {
    return icon;
}

Queen::Queen(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive, BLACK) {}

Queen::Queen(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                  alive, color) {}

vector<FieldPtr> Queen::get_moves(BoardPtr board) {
    vector<FieldPtr> moves;
    int from_x = this->getField()->getXCoord();
    int from_y = this->getField()->getYCoord();
    int to_x = 0;
    int to_y = 0;

    for (auto field: board->getFields()){
        moves.push_back(field);
    }
    return moves;
}

