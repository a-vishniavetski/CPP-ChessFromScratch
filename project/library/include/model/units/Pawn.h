//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "typedefs.h"
#include "Unit.h"

class Pawn : public Unit {
public:
    Pawn(const string &name, int uuid, const FieldPtr &field, bool alive);

    vector<FieldPtr> get_moves(BoardPtr board);
};


#endif //CHESS_PAWN_H
