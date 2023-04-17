//
// Created by avish on 3/22/2023.
//

#ifndef WARSZTAT1_CLIENT_H
#define WARSZTAT1_CLIENT_H
#include <string>
#include "model/Address.h"

using namespace std;

class Client {
public:
    // constructor
    Client(string firstName, string lastName, string personalID,
           Address* address);

    // destructor
    ~Client();

    // getters
    string getClientInfo() const;
    string getFirstName() const;
    string getLastName() const;
    string getPersonalID() const;
    const Address* getAddress() const;

    // setters
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setAddress(Address* address);


private:
    Client();

    string firstName;
    string lastName;
    const string personalID;
    Address* address;

};


#endif //WARSZTAT1_CLIENT_H
