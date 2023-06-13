//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Unit.h"


class King : public Unit {
public:
    string getIcon() override;
private:
    string icon = "\n♚\n";
};


#endif //CHESS_KING_H
