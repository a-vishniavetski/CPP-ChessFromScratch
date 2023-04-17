#include "model/Address.h"

Address::Address(string arg_city, string arg_street, string arg_number):
    city(arg_city),
    street(arg_street),
    number(arg_number)
    {};

Address::~Address() {}
// getters
const string & Address::getCity() const{
    return this->city;
};
const string & Address::getStreet() const{
    return this->street;
};
const string & Address::getNumber() const{
    return this->number;
};
string Address::getAddressInfo() const{
    string _prompt = this->city + ", " + this-> street + ", " + this->number;
    return _prompt;
};