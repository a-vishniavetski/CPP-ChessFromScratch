//
// Created by avish on 5/29/2023.
//

#include "Player.h"

// Konstruktor i destruktor
Player::Player(const string &name, int upid, const vector<UnitPtr> &units) : name(name), UPID(upid), units(units) {}

Player::~Player() {}
