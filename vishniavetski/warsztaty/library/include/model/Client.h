//
// Created by avish on 3/22/2023.
//

#ifndef WARSZTAT1_CLIENT_H
#define WARSZTAT1_CLIENT_H
#include <string>

using namespace std;

class Client {
public:
    // constructor
    Client(string firstName, string lastName, string personalID);

    // destructor
    ~Client();

    // getters
    string getClientInfo();
    string getFirstName();
    string getLastName();
    string getPersonalID();

    // setters
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setPersonalID(string personalID);

private:
    Client();

    string firstName;
    string lastName;
    string personalID;

};


#endif //WARSZTAT1_CLIENT_H
