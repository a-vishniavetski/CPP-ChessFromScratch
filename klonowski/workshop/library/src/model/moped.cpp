#include "model/moped.h"

Moped::Moped(std::string plateNumber, unsigned int basePrice, unsigned int engineDisplacement) : MotorVehicle(
        plateNumber, basePrice, engineDisplacement) {}

Moped::~Moped() {}

double Moped::getActualRentalPrice() {
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getVehicleInfo() {
    return "Moped:\n " + MotorVehicle::getVehicleInfo();
}
