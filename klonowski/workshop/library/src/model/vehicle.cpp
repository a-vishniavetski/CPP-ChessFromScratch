

#include "model/vehicle.h"
#include <iostream>
#include <sstream>
using namespace std;
Vehicle::Vehicle(std::string plateNumber, unsigned int basePrice):plateNumber(plateNumber), basePrice(basePrice) {}

Vehicle::~Vehicle() {}

string Vehicle::getVehicleInfo() const {
    stringstream ss;
    ss << "Plate Number = " << this->plateNumber << ", base price = " << this->basePrice;
    return ss.str();
}

//getters

unsigned int Vehicle::getBasePrice() const {
    return this->basePrice;
}

string Vehicle::getPlateNumber() const {
    return this->plateNumber;
}

bool Vehicle::isRented() const{
    return this->rented;
}

//setters

void Vehicle::setPlateNumber(std::string plateNumber) {
    if(plateNumber.empty())
        return;
    this->plateNumber = plateNumber;
}

void Vehicle::setBasePrice(unsigned int basePrice) {
    if(basePrice == NULL)
        return;
    this->basePrice = basePrice;
}

void Vehicle::setRented(bool rented) {
    if(rented == NULL)
        return;
    this->rented = rented;
}