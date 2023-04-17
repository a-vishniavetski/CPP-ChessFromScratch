//
// Created by avish on 3/22/2023.
//

#include "model/Client.h"
#include <string>
#include <vector>

Client::Client() {}

Client::Client(const string &firstName, const string &lastName, const string &personalID,
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

const string & Client::getFirstName() const {
    return this->firstName;
};

const string & Client::getLastName() const{
    return this->lastName;
};

const string & Client::getPersonalID() const{
    return this->personalID;
};

const Address* Client::getAddress() const{
    return this->address;
}

// setters

void Client::setFirstName(const string &firstName){
    if (firstName.empty()){
        return;
    }

    this->firstName = firstName;
}

void Client::setLastName(const string &lastName){
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

string Client::getFullClientInfo() const{
    string _prompt = "firstName: " + this->firstName +
                     " | lastName: " + this->lastName +
                     " | personalID: " + this->personalID;

    string _prompt_address = this->address->getAddressInfo();
    string _prompt_rent = "";

    return _prompt +  " | " + _prompt_address + "\n"
    + _prompt_rent;
};
