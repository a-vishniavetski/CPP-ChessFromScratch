//
// Created by student on 17.04.23.
//

#include <vector>
#include <algorithm>
#include "model/Rent.h"
#include "model/Client.h"

using namespace std;

// Constructor
Rent::Rent(int _id, Client* _client, Vehicle* _vehicle, pt::ptime _beginTime) :
        id(_id),
        client(_client),
        vehicle(_vehicle),
        beginTime((_beginTime == pt::not_a_date_time) ? pt::second_clock::local_time() : _beginTime)
{
    vector<Rent*>& clientRents = _client->currentRents;
    clientRents.push_back(this);

    if (!_vehicle->isRented()){
        _vehicle->setRented(true);
    }
    else {
        return;
    }
}
// Destructor
Rent::~Rent() {}
// Getters
int Rent::getId() const {
    return this->id;
}
string Rent::getRentInfo() const {
    string rentInfo = "Rent ID: " + to_string(id) +
            " | BeginTime: " + to_simple_string(this->beginTime) +
            " | EndTime: " + to_simple_string(this->endTime) + "\n" +
            "Client Info: " + this->client->getClientInfo() + "\n" +
            "Vehicle Info : " + this->vehicle->getVehicleInfo();
                                                                                                "Vehicle Info: " + vehicle->getVehicleInfo() + "\n";
    return rentInfo;
}
// Time
const pt::ptime Rent::getBeginTime() const {
    return this->beginTime;
};
const pt::ptime Rent::getEndTime() const {
    return this->endTime;
};
// endRent
void Rent::endRent(pt::ptime _endTime) {

    if (_endTime == pt::not_a_date_time){
        this->endTime = pt::second_clock::local_time();
    }

    else if (_endTime < this->beginTime){
        this->endTime = this->beginTime;
    }
    else {
        this->endTime = _endTime;
    }

    // vehicle not rented anymore
    this->vehicle->setRented(false);
    // zwolnic pojazd
    vector<Rent*> *rents = &this->client->currentRents;
    int id = this->getId();

	rents->erase(remove_if(rents->begin(), rents->end(), [id](Rent *rent) { return (rent->getId() == id);  }), rents->end());

    return;
};
int Rent::getRentDays() const {
    // Rent not over yet
    if (this->getEndTime().is_not_a_date_time()){
        return 0;
    }

    pt::time_period period = pt::time_period(this->getBeginTime(), this->getEndTime());
    pt::time_duration one_minute = {0, 1, 0};
    // Rent period <= 1 min
    if (period.length() <= one_minute){
        return 0;
    }
    // Rent longer than a minute
    int days = 0;
    int hours = period.length().hours();
    int minutes = period.length().minutes();

    days = hours / 25;
    days += 1;

    if (minutes > 1){
        days += 1;
    }

    return days;
};
