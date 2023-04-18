//
// Created by Hubert Klonowski on 21/03/2023.
//
#include "model/client.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Client::Client(string firstName, string lastName, string personalID, Address* address):firstName(firstName), lastName(lastName), personalID(personalID), address(address)
{}

Client::~Client()
{
    delete address;
}

string Client::getClientInfo() const
{
    stringstream ss;
    ss << "Client: " << firstName << " " << lastName << " " << personalID << " " << address->getAddressInfo();
    return ss.str();
}

string Client::getFullClientInfo() const
{
    stringstream ss;
    ss << "Client: " << firstName << " " << lastName << " " << personalID << " " << address->getAddressInfo() << ", currentRents: ";
    for(int i = 0; i < this->currentRents.size(); i++)
    {
        ss << this->currentRents[i]->getRentInfo() << endl;
    }
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

Address* Client::getAddress() const {
    return address;
}

vector<Rent*> Client::getCurrentRents() const {
    return this->currentRents;
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

void Client::setAddress(Address *address) {
    if(address == nullptr)
        return;
    this->address = address;
}

void Client::addToCurrentRents(Rent *rent) {
    if(rent == nullptr)
        return;
    this->currentRents.push_back(rent);
}

