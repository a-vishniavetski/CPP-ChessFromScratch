//
// Created by student on 03.04.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(ConstructorTest){
    // zmienne
    const string t_city = "City";
    const string t_street = "Street";
    const string t_number = "00";

    // instancja klasy
    Address adr = Address(t_city, t_street, t_number);

    string check_city = adr.getCity();
    string check_street = adr.getStreet();
    string check_number = adr.getNumber();

    // testy

    BOOST_TEST(t_city == check_city);
    BOOST_TEST(t_street == check_street);
    BOOST_TEST(t_number == check_number);
}


BOOST_AUTO_TEST_SUITE_END();