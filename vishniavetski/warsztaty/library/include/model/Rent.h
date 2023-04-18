//
// Created by student on 17.04.23.
//

#ifndef WARSZTAT3_RENT_H
#define WARSZTAT3_RENT_H

#include <string>
#include <boost/date_time.hpp>
#include "model/Vehicle.h"
using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;



class Client;

class Rent {
public:
    Rent(int _id, Client* _client, Vehicle* _vehicle, pt::ptime _beginTime);
    ~Rent();

    // getters
    int getId() const;
    string getRentInfo() const;
    const pt::ptime getBeginTime() const;
    const pt::ptime getEndTime() const;
    // Rent
    void endRent(pt::ptime _endTime);
    int getRentDays() const;


private:
    int id;
    const Client *client;
    Vehicle *vehicle;
    pt::ptime beginTime;
    pt::ptime endTime = pt::not_a_date_time;
};


#endif //WARSZTAT3_RENT_H
