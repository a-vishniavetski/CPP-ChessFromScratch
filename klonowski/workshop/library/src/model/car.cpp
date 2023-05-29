#include "model/car.h"

Car::Car(std::string plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement), segmentType(segmentType) {}

double Car::getActualRentalPrice() {
    return MotorVehicle::getActualRentalPrice() * (segmentType / 10.0);
}

Car::~Car() {
}

std::string Car::getVehicleInfo() {
    return "Car:\n "+ MotorVehicle::getVehicleInfo() + "\n segmentType: " + std::to_string(A / 10.0);
}
