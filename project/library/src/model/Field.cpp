//
// Created by avish on 5/29/2023.
//

#include <vector>
#include "Field.h"
#include <Unit.h>
#include <Pawn.h>

using namespace std;


// Konstruktorzy i destruktorzy
Field::~Field() {}

Field::Field(int xCoord, int yCoord, const string &color) : x_coord(xCoord), y_coord(yCoord), color(color) {
    /* Potrzebujemy żeby pole "occupied_by" mógło być nullptr(niczym) żeby jego zwalniać
     * dlatego trzeba było dać Unitu konstruktor z nullptr-em.
    */
    UnitPtr null_unit = make_shared<Unit>(nullptr);
    occupied_by_unit = nullptr;
}

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

void Field::setOccupied(bool _occupied) {
    occupied = _occupied;
}

const UnitPtr &Field::getOccupiedByUnit() const {
    return occupied_by_unit;
}

void Field::occupy(const UnitPtr unit) {
    occupied_by_unit = unit;
    setOccupied(true);
}

void Field::deoccupy() {
    setOccupied(false);
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

Field::Field(nullptr_t) {

}

string Field::get_field_info() const {
    string occupied_status = "Not_Occupied";
    if (isOccupied()){
        occupied_status = "Occupied";
    }
    string _prompt = "Field(";
    _prompt.append(to_string(this->getXCoord())).append(", ");
    _prompt.append(to_string(this->getYCoord())).append(")");
    _prompt.append(this->getColor());
    _prompt.append(":").append(occupied_status);
    return _prompt;
}


