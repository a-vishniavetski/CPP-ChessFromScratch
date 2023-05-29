//
// Created by Hubert Klonowski on 17/04/2023.
//

#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <ostream>
#include "typedefs.h"

enum SegmentType{ A = 10, B = 11, C = 12, D = 13, E = 15};

class Vehicle {
public:
    Vehicle(std::string plateNumber, unsigned int basePrice);

    virtual ~Vehicle() = 0;

    //getters
    virtual std::string getVehicleInfo();
    const std::string &getPlateNumber() const;
    unsigned int getBasePrice() const;
    bool isRented() const;

    virtual double getActualRentalPrice();

    //setters

    void setPlateNumber(std::string plateNumber);
    void setBasePrice(unsigned int basePrice);
    void setRented(bool rented);

    bool rented;

private:
    std::string plateNumber;
    int basePrice;
};


#endif //VEHICLE_H
