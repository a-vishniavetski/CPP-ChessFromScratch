//
// Created by Hubert Klonowski on 21/03/2023.
//
#include "model/client.h"
#include <iostream>
#include <sstream>
using namespace std;

Client::Client(string firstName, string lastName, string personalID):firstName(firstName), lastName(lastName), personalID(personalID)
{}

Client::~Client()
{}

string Client::getClientInfo() const
{
    stringstream ss;
    ss << "Client: " << firstName << " " << lastName << " " << personalID;
    return ss.str();
}

//getters

string Client::getFirstName() const {
    return firstName;
}

string Client::getLastName() const {
    return lastName;
}

string Client::getPersonalID() const {
    return personalID;
}

//setters

void Client::setFirstName(std::string firstName) {
    if(firstName.empty())
        return;
    this->firstName = firstName;
}
void Client::setLastName(std::string lastName) {
    if(lastName.empty())
        return;
    this->lastName = lastName;
}
void Client::setPersonalID(std::string personalID){
    if(personalID.empty())
        return;
    this->personalID = personalID;
}

