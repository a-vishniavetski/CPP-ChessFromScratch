//
// Created by Hubert Klonowski on 21/03/2023.
//

#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "address.h"
#include "rent.h"

class Client
{
public:
    Client(std::string firstName, std::string lastName, std::string personalID, Address* address);

    ~Client();
    //getters
    std::string getClientInfo() const;
    std::string getFullClientInfo() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPersonalID() const;
    Address* getAddress() const;
    std::vector<Rent*> getCurrentRents() const;

    //setters
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setPersonalID(std::string personalID);
    void setAddress(Address* address);
    void addToCurrentRents(Rent* rent);

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Address* address;
    std::vector<Rent*> currentRents;
    Client();
};

#endif //CLIENT_H
