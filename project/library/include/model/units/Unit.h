//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_UNIT_H
#define CHESS_UNIT_H


#include "typedefs.h"


class Board;
class Field;


class Unit {
public:
    virtual vector<FieldPtr> get_moves(BoardPtr board)=0;

private:
    string name;
    int UUID; // unique unit id
    FieldPtr field;
    bool alive;
};


#endif //CHESS_UNIT_H
