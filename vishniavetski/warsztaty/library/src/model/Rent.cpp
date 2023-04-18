//
// Created by student on 17.04.23.
//

#include <vector>
#include "model/Rent.h"

using namespace std;

// Constructor
Rent::Rent(int _id, Client* _client, Vehicle* _vehicle) :
        id(_id),
        client(_client),
        vehicle(_vehicle)
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
    string rentInfo = "Rent ID: " + to_string(id) + "\n" +
            "Client Info: " + this->client->getClientInfo() + "\n" +
            "Vehicle Info : " + this->vehicle->getVehicleInfo();
                                                                                                "Vehicle Info: " + vehicle->getVehicleInfo() + "\n";
    return rentInfo;
}

string Client::getFullClientInfo() const{
    // Client + Address
    string _prompt = this->getClientInfo();
    // Rents
    string _prompt_rent = "\nCurrents rents:\n";
    for (int i = 0; i < this->currentRents.size(); i++){
        _prompt_rent = _prompt_rent + currentRents[i]->getRentInfo() +
                        "\n";
    }

    return _prompt + _prompt_rent;
}