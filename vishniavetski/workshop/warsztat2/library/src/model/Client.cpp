//
// Created by avish on 3/22/2023.
//

#include "model/Client.h"
#include <iostream>
#include <string>

using namespace std;

Client::Client() {}

Client::Client(string firstName, string lastName, string personalID):
    firstName(firstName),
    lastName(lastName),
    personalID(personalID)
    {}

Client::~Client() {}

// getters
string Client::getClientInfo() {
    string _prompt = "firstName: " + this->firstName +
            " | lastName: " + this->lastName +
            " | personalID: " + this->personalID;

    return _prompt;
}

string Client::getFirstName(){
    return this->firstName;
};

string Client::getLastName(){
    return this->lastName;
};

string Client::getPersonalID(){
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

    this->firstName = lastName;
}

void Client::setPersonalID(string personalID) {
    if (personalID.empty()){
        return;
    }

    this->firstName = firstName;
}