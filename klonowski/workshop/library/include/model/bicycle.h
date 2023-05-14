//
// Created by Hubert Klonowski on 14/05/2023.
//

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "vehicle.h"

class Bicycle: public Vehicle{
public:
    Bicycle(std::string &plateNumber, unsigned int basePrice);
    double getActualRentalPrice() override;
    std::string getVehicleInfo() override;
    ~Bicycle() override;
};

#endif //CARRENTAL_BICYCLE_H
