//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "Unit.h"

class Bishop : public Unit {
public:

    Bishop(const string &name, int uuid, const FieldPtr &field, bool alive);

    Bishop(const string &name, int uuid, const FieldPtr &field, bool alive, Color color);

    string getIcon() override;

private:
    string icon = "♝";
};


#endif //CHESS_BISHOP_H
