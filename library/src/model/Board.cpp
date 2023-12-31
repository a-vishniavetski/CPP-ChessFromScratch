#include <iostream>
#include <Board.h>
#include <Field.h>
#include "Unit.h"
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

FieldPtr Board::getField(int x_dimension, int y_dimension) const{
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

const vector<FieldPtr> &Board::getFields() const {
    return fields;
}

void Board::setFields(const vector<FieldPtr> &fields) {
    Board::fields = fields;
}

Board::Board(const Board& other) {
    x_dimension = other.x_dimension;
    y_dimension = other.y_dimension;

    // Deep copy the fields vector
    for (const auto& field : other.fields) {
        FieldPtr newField = make_shared<Field>(*field);
        fields.push_back(newField);
    }
}

vector<FieldPtr> Board::getFieldsOccupiedByColor(Color color) {
    vector<FieldPtr> occupied;
    for(int i = 0; i < fields.size(); i++)
    {
        if(fields[i]->isOccupied())
        {
            if(fields[i]->getOccupiedByUnit()->getColor() == color)
            {
                occupied.push_back(fields[i]);
            }
        }

    }
    return occupied;
}

vector<UnitPtr> Board::getKnockedOffUnitsByColor(Color color) {
    vector<UnitPtr> knockedOff;
    for(int i = 0; i < fields.size(); i++)
    {
        if(fields[i]->isOccupied()){
            if(fields[i]->getOccupiedByUnit()->getColor() == color)
            {
                if(fields[i]->getOccupiedByUnit()->isAlive() == false)
                {
                    knockedOff.push_back(fields[i]->getOccupiedByUnit());
                }
            }
        }
    }
    return knockedOff;
}
