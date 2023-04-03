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
    string getCity() const;
    string getStreet() const;
    string getNumber() const;
    string getAddressInfo() const;

    // setters
    void setCity(string city);
    void setStreet(string street);
    void setNumber(string number);

private:
    string city;
    string street;
    string number;

};

#endif //WARSZTAT1_ADDRESS_H
