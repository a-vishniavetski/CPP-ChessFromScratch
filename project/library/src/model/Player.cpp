//
// Created by avish on 5/29/2023.
//

#include "Player.h"
#include <Unit.h>

// Konstruktor i destruktor
Player::Player(const string &name, int upid, const vector<UnitPtr> &units) : name(name), UPID(upid), units(units) {}

Player::~Player() {}

const string &Player::getName() const {
    return name;
}

void Player::setName(const string &name) {
    Player::name = name;
}

int Player::getUpid() const {
    return UPID;
}

void Player::setUpid(int upid) {
    UPID = upid;
}

const vector<UnitPtr> &Player::getUnits() const {
    return units;
}

void Player::setUnits(const vector<UnitPtr> &units) {
    Player::units = units;
}

string Player::get_all_units_info() const {

    string _prompt;

    for (int i = 0; i < units.size(); i++){
        _prompt.append(units[i]->get_unit_info()).append("\n");
    }

    return _prompt;
}

Color Player::getColor() const {
    return color;
}

void Player::addUnit(UnitPtr unit) {
    units.push_back(unit);
}

UnitPtr Player::choose_unit() {
    // todo
    return UnitPtr();
}

Player::Player(const string &name, int upid, Color color) : name(name), UPID(upid), color(color) {}
