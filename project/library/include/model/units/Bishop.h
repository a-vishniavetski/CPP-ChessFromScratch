//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "Unit.h"

class Bishop : public Unit {
public:

    string getIcon() override;

private:
    string icon = "\n♝\n";
};


#endif //CHESS_BISHOP_H
