//
// Created by student on 03.04.23.
//

#ifndef WARSZTAT1_ADDRESS_H
#define WARSZTAT1_ADDRESS_H
#include <string>

using namespace std;


class Address {
public:

    Address(string arg_city, string arg_street, string arg_number);
    ~Address();

    // getters
    const string & getCity() const;
    const string & getStreet() const;
    const string & getNumber() const;
    string getAddressInfo() const;

private:
    string city;
    string street;
    string number;

};

#endif //WARSZTAT1_ADDRESS_H
