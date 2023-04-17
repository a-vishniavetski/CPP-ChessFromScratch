//
// Created by student on 17.04.23.
//

#include "model/Vehicle.h"

// Konstruktor
Vehicle::Vehicle(int basePrice, const string& plateNumber):
        basePrice(basePrice),
        plateNumber(plateNumber)
{}
// Destruktor
Vehicle::~Vehicle(){}


// Getters
int Vehicle::getBasePrice() const {
    return basePrice;
}

const std::string& Vehicle::getPlateNumber() const {
    return plateNumber;
}

string Vehicle::getVehicleInfo() const {
    string _prompt = "PlateNumber: " + this->getPlateNumber() +
    " | BasePrice: " + to_string(this->getBasePrice());

    return _prompt;
}
// Setters
void Vehicle::setBasePrice(int _basePrice) {
    this->basePrice = _basePrice;
}

void Vehicle::setPlateNumber(const std::string& _plateNumber) {
    if (_plateNumber.empty()) {
        return;
    }

    this->plateNumber = _plateNumber;
}
