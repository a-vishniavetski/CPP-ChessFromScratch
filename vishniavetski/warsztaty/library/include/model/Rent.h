//
// Created by student on 17.04.23.
//

#ifndef WARSZTAT3_RENT_H
#define WARSZTAT3_RENT_H

#include <string>
#include "model/Vehicle.h"
#include "model/Client.h"

using namespace std;

class Client;

class Rent {
public:
    Rent(int _id, Client* _client, Vehicle* _vehicle);
    ~Rent();

    // getters
    int getId() const;
    string getRentInfo() const;

private:
    int id;
    const Client *client;
    const Vehicle *vehicle;
};


#endif //WARSZTAT3_RENT_H
