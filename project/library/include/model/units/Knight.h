//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Unit.h"

class Knight : public Unit {
public:
    string getIcon() override;
private:
    string icon = "\n♞\n";

};


#endif //CHESS_KNIGHT_H
