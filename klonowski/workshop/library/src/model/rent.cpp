
#include <boost/date_time.hpp>
#include "model/rent.h"
#include <iostream>
#include <sstream>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;

Rent::Rent(unsigned int id, Vehicle *vehicle, Client *client, bool rented, pt::ptime endTime, pt::ptime beginTime): id(id), vehicle(vehicle), client(client), beginTime(beginTime), endTime(endTime) {
    if(this->beginTime == pt::not_a_date_time)
        this->beginTime = pt::second_clock::local_time();
    this->endTime = pt::not_a_date_time;
    this->vehicle->setRented(rented);
}

Rent::~Rent() {}

string Rent::getRentInfo() const {
    stringstream ss;
    ss << "ID: " << this->id << ", Client:  " << this->client->getClientInfo() << ", Vehicle: " << this->vehicle->getVehicleInfo() << ", BeginTime: " << this->beginTime << ", EndTime: " << this->endTime;
    return ss.str();
}

unsigned int Rent::getId() const {
    return this->id;
}

Vehicle* Rent::getVehicle() const {
    return this->getVehicle();
}

Client* Rent::getClient() const {
    return this->client;
}

pt::ptime Rent::getBeginTime() const {
    return this->beginTime;
}

pt::ptime Rent::getEndTime() const {
    return this->endTime;
}

unsigned int Rent::getRentDays() const {
    if(this->endTime == pt::not_a_date_time)
        return 0;
    pt::time_period period(this->beginTime, this->endTime);
    if(period.length().minutes() <= 0)
        return 0;
    return (period.length().hours() / 24) + 1;
}

unsigned int Rent::getRentCost() const {
    return this->rentCost;
}

//setters

void Rent::assignRentToClient() const {
    this->getClient()->addToCurrentRents(this);
}

void Rent::endRent(pt::ptime endTime) {
    if(this->endTime != pt::not_a_date_time)
        return;

    pt::ptime now = pt::second_clock::local_time();
    if(endTime == pt::not_a_date_time)
    {
        this->endTime = now;
        return;
    }
    if(endTime > now)
        return;
    this->endTime = endTime;
    this->getVehicle()->rented = false;
    auto it = std::find(this->getClient()->getCurrentRents().begin(), this->getClient()->getCurrentRents().end(), this);

    if(it != this->getClient()->getCurrentRents().end())
    {
        int index = std::distance(this->getClient()->getCurrentRents().begin(), it);
        this->getClient()->getCurrentRents().erase(index);
    }
    this->rentCost = this->getRentDays() * this->getVehicle()->getBasePrice();
}