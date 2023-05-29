#include "model/bicycle.h"

Bicycle::Bicycle(std::string &plateNumber, unsigned int basePrice) : Vehicle(plateNumber, basePrice) {}

double Bicycle::getActualRentalPrice() {
    return Vehicle::getActualRentalPrice();
}

std::string Bicycle::getVehicleInfo() {
    return "Bicycle:\n " + Vehicle::getVehicleInfo();
}

Bicycle::~Bicycle() {}