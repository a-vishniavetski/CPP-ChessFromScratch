//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "Unit.h"

class Queen : public Unit {
public:
    string getIcon() override;
private:
    string icon = "\n♛\n";
};


#endif //CHESS_QUEEN_H
