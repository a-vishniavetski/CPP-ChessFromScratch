#ifndef CHESS_UNIT_H
#define CHESS_UNIT_H


#include "typedefs.h"


class Board;
class Field;

/*
 * Unit dzieli się na 6 klas dziedziczących, które na swój sposób wyliczają każdy możliwy ruch
 * i zwracają dostępne pola do posunięcia.
 * JEDNAK, unit-y nie mają odpowiedzialności sprawdzać warunki mata, szacha albo pata.
*/
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
