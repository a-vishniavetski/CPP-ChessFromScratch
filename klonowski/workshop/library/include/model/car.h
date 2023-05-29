//
// Created by Hubert Klonowski on 14/05/2023.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "motorVehicle.h"

class Car : public MotorVehicle{
public:
    Car(std::string plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segmentType);
    ~Car() override;

    double getActualRentalPrice() override;
    std::string getVehicleInfo() override;
private:
    SegmentType segmentType;
};

#endif //CARRENTAL_CAR_H
