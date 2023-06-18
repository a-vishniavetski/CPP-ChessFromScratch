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
    vector<FieldPtr> getMoves(BoardPtr board);
    string getIcon() override;

private:
    string icon = "♜";
    int checkMove(FieldPtr temp_field);
};


#endif //CHESS_ROOK_H
