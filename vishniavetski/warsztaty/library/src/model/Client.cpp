//
// Created by avish on 3/22/2023.
//

#include "model/Client.h"
#include <string>

Client::Client() {}

Client::Client(string firstName, string lastName, string personalID,
               Address* address):
    firstName(firstName),
    lastName(lastName),
    personalID(personalID),
    address(address)
    {}

Client::~Client() {}

// getters
string Client::getClientInfo() const{
    string _prompt = "firstName: " + this->firstName +
            " | lastName: " + this->lastName +
            " | personalID: " + this->personalID;

    string _prompt_address = this->address->getAddressInfo();

    return _prompt +  " | " + _prompt_address;
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

const Address* Client::getAddress() const{
    return this->address;
}

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

void Client::setAddress(Address *address) {
    if (address == nullptr){
        return;
    }

    this->address = address;
}