#include <boost/test/unit_test.hpp>
#include "model/address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(.03));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {

        std::string city = "Lodz";
        std::string street = "Gladka";
        std::string number = "9";

        Address address(city, street, number);

        BOOST_TEST(address.getCity() == city);
        BOOST_TEST(address.getStreet() == street);
        BOOST_TEST(address.getNumber() == number);

    }
//
//    BOOST_AUTO_TEST_CASE(SetCity)
//    {
//        Address address("Lodz", "Gladka", "9");
//        std::string city = "Warszawa";
//        address.setCity(city);
//        BOOST_TEST(address.getCity() == city);
//
//        address.setCity("");
//        BOOST_TEST(address.getCity() == city);
//    }
//
//    BOOST_AUTO_TEST_CASE(SetStreet)
//    {
//        Address address("Lodz", "Gladka", "9");
//        std::string street = "Jana Pawla";
//        address.setStreet(street);
//        BOOST_TEST(address.getStreet() == street);
//
//        address.setStreet("");
//        BOOST_TEST(address.getStreet() == street);
//    }
//
//    BOOST_AUTO_TEST_CASE(SetNumber)
//    {
//        Address address("Lodz", "Gladka", "9");
//        std::string number = "1";
//        address.setNumber(number);
//        BOOST_TEST(address.getNumber() == number);
//
//        address.setNumber("");
//        BOOST_TEST(address.getNumber() == number);
//    }

BOOST_AUTO_TEST_SUITE_END()