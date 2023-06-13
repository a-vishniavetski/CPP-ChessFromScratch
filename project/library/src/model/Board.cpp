#include <iostream>
#include <Board.h>
#include <Field.h>

using namespace std;


Board::Board(int _x_dimension, int _y_dimension, const std::vector<FieldPtr> &_fields) : x_dimension(_x_dimension),
                                                                                         y_dimension(_y_dimension),
                                                                                         fields(_fields) {}

Board::~Board() {

}

int Board::getXDimension() {
    return x_dimension;
}

void Board::setXDimension(int xDimension) {
    x_dimension = xDimension;
}

int Board::getYDimension() {
    return y_dimension;
}

void Board::setYDimension(int yDimension) {
    y_dimension = yDimension;
}

FieldPtr Board::get_field(int x_dimension, int y_dimension) const{
    //std::cout << "In get_filed";
    FieldPtr retval = make_shared<Field>(nullptr);

    for (int i = 0; i < fields.size(); i++){
        retval = fields[i];
        if (retval->getXCoord() == x_dimension && retval->getYCoord() == y_dimension){
            //std::cout << "Field found";
            break;
        }
        else{
            //std::cout << "Field not found";
        }
    }
    // todo field_not_found exception czy coś takiego
    //std::cout << "Almost out of get_filed";
    return retval;
}
