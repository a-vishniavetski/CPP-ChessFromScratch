//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <vector>
#include <typedefs.h>


class Field;


class Board {
private:
    int x_dimension;
    int y_dimension;
    vector<FieldPtr> fields;
};


#endif //CHESS_BOARD_H
