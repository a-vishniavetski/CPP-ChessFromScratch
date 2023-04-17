//
// Created by student on 17.04.23.
//

#ifndef WARSZTAT3_VEHICLE_H
#define WARSZTAT3_VEHICLE_H
#include <string>

using namespace std;

class Vehicle {
private:
    int basePrice;
    string plateNumber;
    bool rented = false;

public:
    // Konstruktor parametrowy
    Vehicle(int _basePrice, const string& _plateNumber);
    ~Vehicle();

    // Gettery
    int getBasePrice() const;
    const string& getPlateNumber() const;
    string getVehicleInfo() const;
    bool isRented() const;

    // Settery
    void setBasePrice(int _basePrice);
    void setPlateNumber(const string& _plateNumber);
    void setRented(bool _val);
};


#endif //WARSZTAT3_VEHICLE_H
