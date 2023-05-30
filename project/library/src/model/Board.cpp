//
// Created by avish on 5/29/2023.
//

#include "Board.h"

Board::Board(int _x_dimension, int _y_dimension, const std::vector<FieldPtr> &_fields) : x_dimension(_x_dimension),
                                                                                         y_dimension(_y_dimension),
                                                                                         fields(_fields) {}

Board::~Board() {

}
