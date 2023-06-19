//
// Created by Hubert Klonowski on 18/04/2023.
//

#ifndef RENT_H
#define RENT_H

#include <boost/date_time.hpp>
#include <string>
#include "typedefs.h"

class Client;
class Vehicle;

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Rent{
public:
    Rent(unsigned int id, VehiclePtr vehicle, ClientPtr client, bool rented = true, pt::ptime endTime =  pt::not_a_date_time, pt::ptime beginTime =  pt::second_clock::local_time());

    ~Rent();

    //getters

    unsigned int getId() const;
    VehiclePtr getVehicle() const;
    ClientPtr getClient() const;

    std::string getRentInfo() const;
    pt::ptime getBeginTime() const;
    pt::ptime getEndTime() const;
    unsigned int getRentDays() const;
    unsigned int getRentCost() const;


    //setters

    void assignRentToClient();
    void endRent(pt::ptime endTime);
    unsigned int rentCost = 0;

private:
    unsigned int id;
    VehiclePtr vehicle;
    ClientPtr client;
    pt::ptime beginTime;
    pt::ptime endTime;
};

#endif //RENT_H
