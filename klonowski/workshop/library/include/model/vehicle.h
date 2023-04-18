//
// Created by Hubert Klonowski on 17/04/2023.
//

#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

class Vehicle {
public:
    Vehicle(std::string plateNumber, unsigned int basePrice);

    ~Vehicle();

    //getters
    std::string getVehicleInfo() const;
    std::string getPlateNumber() const;
    unsigned int getBasePrice() const;
    bool isRented() const;

    //setters

    void setPlateNumber(std::string plateNumber);
    void setBasePrice(unsigned int basePrice);
    void setRented(bool rented);

    bool rented;

private:
    std::string plateNumber;
    int basePrice;
    Vehicle();

};


#endif //VEHICLE_H
