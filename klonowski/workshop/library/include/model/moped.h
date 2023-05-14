
#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H

#include "model/motorVehicle.h"

class Moped : public MotorVehicle{
public:
    Moped(std::string plateNumber, unsigned int basePrice, unsigned int engineDisplacement);
    ~Moped() override;

    double getActualRentalPrice() override;
    std::string getVehicleInfo() override;
};

#endif //CARRENTAL_MOPED_H
