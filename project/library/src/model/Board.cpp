#include <Board.h>
#include <Field.h>

using namespace std;


Board::Board(int _x_dimension, int _y_dimension, const std::vector<FieldPtr> &_fields) : x_dimension(_x_dimension),
                                                                                         y_dimension(_y_dimension),
                                                                                         fields(_fields) {}

Board::~Board() {

}

int Board::getXDimension() const {
    return x_dimension;
}

void Board::setXDimension(int xDimension) {
    x_dimension = xDimension;
}

int Board::getYDimension() const {
    return y_dimension;
}

void Board::setYDimension(int yDimension) {
    y_dimension = yDimension;
}

FieldPtr Board::get_field(int x_dimension, int y_dimension) const{
    FieldPtr retval;

    for (int i = 0; i < fields.size(); i++){
        retval = fields[i];
        if (retval->getXCoord() == x_dimension && retval->getYCoord() == y_dimension){
            break;
        }
    }
    // todo field_not_found exception czy coś takiego

    return retval;
}
