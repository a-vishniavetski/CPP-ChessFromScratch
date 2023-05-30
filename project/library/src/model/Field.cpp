//
// Created by avish on 5/29/2023.
//

#include <vector>
#include "Field.h"

using namespace std;


// Konstruktorzy i destruktorzy
Field::~Field() {}

Field::Field(int xCoord, int yCoord, const string &color) : x_coord(xCoord), y_coord(yCoord), color(color) {}

Field::Field(int xCoord, int yCoord, bool isOccupied, const UnitPtr &occupiedByUnit, const vector<UnitPtr> &seenByUnits,
             const string &color) : x_coord(xCoord), y_coord(yCoord), occupied(isOccupied),
                                    occupied_by_unit(occupiedByUnit), seen_by_units(seenByUnits), color(color) {}

int Field::getXCoord() const {
    return x_coord;
}

void Field::setXCoord(int xCoord) {
    x_coord = xCoord;
}

int Field::getYCoord() const {
    return y_coord;
}

void Field::setYCoord(int yCoord) {
    y_coord = yCoord;
}

bool Field::isOccupied() const {
    return occupied;
}

void Field::setOccupied(bool occupied) {
    Field::occupied = occupied;
}

const UnitPtr &Field::getOccupiedByUnit() const {
    return occupied_by_unit;
}

void Field::setOccupiedByUnit(const UnitPtr &occupiedByUnit) {
    occupied_by_unit = occupiedByUnit;
}

const string &Field::getColor() const {
    return color;
}

void Field::setColor(const string &color) {
    Field::color = color;
}

const vector<UnitPtr> &Field::getSeenByUnits() const {
    return seen_by_units;
}

void Field::remove_seeing_unit(const int UUID) {
    //todo
}

void Field::add_seeing_unit(const UnitPtr _unit) {
    //todo
}
