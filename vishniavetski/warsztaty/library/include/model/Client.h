//
// Created by avish on 3/22/2023.
//

#ifndef WARSZTAT1_CLIENT_H
#define WARSZTAT1_CLIENT_H
#include <string>
#include <vector>
#include "model/Address.h"

using namespace std;

class Rent;

class Client {
public:
    // constructor
    Client(const string &firstName, const string &lastName, const string &personalID,
           Address* address);

    // destructor
    ~Client();

    // getters
    string getClientInfo() const;
    const string & getFirstName() const;
    const string & getLastName() const;
    const string & getPersonalID() const;
    const Address* getAddress() const;
    string getFullClientInfo() const;

    // setters
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setAddress(Address* address);

    // Rents
    vector<Rent*> currentRents;

private:
    Client();

    string firstName;
    string lastName;
    const string personalID;
    Address* address;

};


#endif //WARSZTAT1_CLIENT_H
