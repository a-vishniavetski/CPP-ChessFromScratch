//
// Created by avish on 3/22/2023.
//

#include <string>
#include "model/Client.h"
#include "model/Rent.h"

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
    string _prompt = "FirstName: " + this->firstName +
            " | LastName: " + this->lastName +
            " | PersonalID: " + this->personalID;

    string _prompt_address = this->address->getAddressInfo();

    return _prompt +  " | Address: " + _prompt_address;
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

