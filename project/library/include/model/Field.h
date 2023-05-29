//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_FIELD_H
#define CHESS_FIELD_H
#include <string>
#import <typedefs.h>


class Unit;


class Field {
private:
    int x_coord;
    int y_coord;
    UnitPtr occupied_by_unit;
    vector<UnitPtr> seen_by_units;
    string color;
};


#endif //CHESS_FIELD_H
