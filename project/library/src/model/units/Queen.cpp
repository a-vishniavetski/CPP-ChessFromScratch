//
// Created by avish on 5/29/2023.
//

#include "model/units/Queen.h"
#include "typedefs.h"
#include "Field.h"
#include "Board.h"
#include "Rook.h"
#include "Bishop.h"

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

    // ROOK MOVES
    vector<FieldPtr> rook_moves;
    FieldPtr temp_field = make_shared<Field>(from_x, from_y, this->getField()->getColor());
    UnitPtr temp_unit = make_shared<Rook>("Rook", -1, temp_field, true, this->getColor());
    rook_moves = temp_unit->get_moves(board);
    moves.insert(moves.end(), rook_moves.begin(), rook_moves.end());
    // BISHOP MOVES
    vector<FieldPtr> bishop_moves;
    temp_field = make_shared<Field>(from_x, from_y, this->getField()->getColor());
    temp_unit = make_shared<Bishop>("Rook", -1, temp_field, true, this->getColor());
    bishop_moves = temp_unit->get_moves(board);
    moves.insert(moves.end(), bishop_moves.begin(), bishop_moves.end());

    return moves;
}

