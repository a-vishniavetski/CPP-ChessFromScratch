

#include "model/address.h"
#include <iostream>
#include <sstream>
using namespace std;

Address::Address(std::string city, std::string street, std::string number):city(city), street(street), number(number) {}

Address::~Address() {};

string Address::getAddressInfo() const {
    stringstream ss;
    ss << "Address: city = " << this->city << ", street = " << this->street << ", number = " << this->number;
    return ss.str();
}

//getters

string Address::getCity() const {
    return this->city;
}

string Address::getStreet() const {
    return this->street;
}

string Address::getNumber() const {
    return this->number;
}

//setters
//
//void Address::setCity(std::string city) {
//    if(city.empty())
//        return;
//    this->city = city;
//}
//
//void Address::setStreet(std::string street) {
//    if(street.empty())
//        return;
//    this->street = street;
//}
//
//void Address::setNumber(std::string number) {
//    if(number.empty())
//        return;
//    this->number = number;
//}