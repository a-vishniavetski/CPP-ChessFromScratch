//
// Created by Hubert Klonowski on 17/04/2023.
//

#ifndef ADDRESS_H
#define ADDRESS_H


#include <string>

class Address {

public:
    Address(std::string city, std::string street, std::string number);

    ~Address();

    //getters
    std::string getAddressInfo() const;

    std::string getCity() const;
    std::string getStreet() const;
    std::string getNumber() const;

    //setters
    void setCity(std::string city);
    void setStreet(std::string street);
    void setNumber(std::string number);

private:
    std::string city;
    std::string street;
    std::string number;
    Address();
};


#endif //ADDRESS_H
