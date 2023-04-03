#include "model/Address.h"

Address::Address(string arg_city, string arg_street, string arg_number):
    city(arg_city),
    street(arg_street),
    number(arg_number)
    {};

Address::~Address() {}
// getters
string Address::getCity() const{
    return this->city;
};
string Address::getStreet() const{
    return this->street;
};
string Address::getNumber() const{
    return this->number;
};
string Address::getAddressInfo() const{
    string _prompt = this->city + ", " + this-> street + ", " + this->number;
    return _prompt;
};

// setters
void Address::setCity(string city){
    if (city.empty()){
        return;
    }

    this->city = city;
};

void Address::setStreet(string street){
    if (street.empty()){
        return;
    }

    this->street = street;
};;
void Address::setNumber(string number){
    if (number.empty()){
        return;
    }

    this->number = number;
};;