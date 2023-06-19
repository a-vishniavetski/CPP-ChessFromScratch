#include "model/motorVehicle.h"

MotorVehicle::MotorVehicle(std::string plateNumber, unsigned int basePrice, unsigned int engineDisplacement)
        : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement) {}

MotorVehicle::~MotorVehicle() {
}


unsigned int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

void MotorVehicle::setEngineDisplacement(unsigned int engineDisplacement) {
    MotorVehicle::engineDisplacement = engineDisplacement;
}

double MotorVehicle::getActualRentalPrice() {
    if (engineDisplacement < 1000){
        return Vehicle::getActualRentalPrice();
    }
    else if (engineDisplacement <= 2000){
        return Vehicle::getActualRentalPrice() * ( 1 + ( (engineDisplacement - 1000.0) / 2000.0) );
    }
    return Vehicle::getActualRentalPrice() * 1.5;
}

std::string MotorVehicle::getVehicleInfo() {
    return Vehicle::getVehicleInfo()+"\n engineDisplacement: "+std::to_string(engineDisplacement);
}
