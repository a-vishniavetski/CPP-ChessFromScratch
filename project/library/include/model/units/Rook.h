//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H


#include "Unit.h"


class Rook : public Unit {
public:
    Rook(const string &name, int uuid, const FieldPtr &field, bool alive);

    Rook(const string &name, int uuid, const FieldPtr &field, bool alive, Color color);

    vector<FieldPtr> get_moves(BoardPtr board);

    string getIcon() override;
private:
    string icon = "\n♜\n";
};


#endif //CHESS_ROOK_H
