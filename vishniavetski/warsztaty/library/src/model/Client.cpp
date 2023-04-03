//
// Created by avish on 3/22/2023.
//

#include "model/Client.h"
#include <string>

Client::Client() {}

Client::Client(string firstName, string lastName, string personalID):
    firstName(firstName),
    lastName(lastName),
    personalID(personalID)
    {}

Client::~Client() {}

// getters
string Client::getClientInfo() const{
    string _prompt = "firstName: " + this->firstName +
            " | lastName: " + this->lastName +
            " | personalID: " + this->personalID;

    return _prompt;
}

string Client::getFirstName() const {
    return this->firstName;
};

string Client::getLastName() const{
    return this->lastName;
};

string Client::getPersonalID() const{
    return this->personalID;
};

// setters

void Client::setFirstName(string firstName){
    if (firstName.empty()){
        return;
    }

    this->firstName = firstName;
}

void Client::setLastName(string lastName){
    if (lastName.empty()){
        return;
    }

    this->lastName = lastName;
}
