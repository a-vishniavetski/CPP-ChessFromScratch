#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H

#include "vehicle.h"

class MotorVehicle : public Vehicle{
public:
    MotorVehicle(std::string plateNumber,
                 unsigned int basePrice, unsigned int engineDisplacement);
    unsigned int getEngineDisplacement() const;
    void setEngineDisplacement(unsigned int engineDisplacement);
    double getActualRentalPrice() override;
    std::string getVehicleInfo() override;
    ~MotorVehicle() override = 0;
private:
    unsigned int engineDisplacement;
};

#endif //CARRENTAL_MOTORVEHICLE_H
