//
// Created by Hubert Klonowski on 21/03/2023.
//

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "typedefs.h"
#include "rent.h"
#include "address.h"

class Address;
class Rent;

class Client
{
public:
    Client(std::string firstName, std::string lastName, std::string personalID, AddressPtr address, std::vector<RentPtr> &currentRents);

    ~Client();
    //getters
    std::string getClientInfo() const;
    std::string getFullClientInfo() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPersonalID() const;
    AddressPtr getAddress() const;
    std::vector<RentPtr> getCurrentRents() const;

    //setters
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setPersonalID(std::string personalID);
    void setAddress(AddressPtr address);
    void addToCurrentRents(RentPtr rent);

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    std::vector<RentPtr> currentRents;
    Client();
};

#endif //CLIENT_H
