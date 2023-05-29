//
// Created by Hubert Klonowski on 14/05/2023.
//
#include <boost/test/unit_test.hpp>
#include "model/car.h"
#include "string"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteCar)
    std::string plateNumber = "ABCD1";
    unsigned int price = 500;
    VehiclePtr ptr;
    BOOST_AUTO_TEST_CASE(Car_getActualRentalPrice_1000_A_Test){
        unsigned int engine = 1000;
        Car *car = new Car(plateNumber,price,engine,A);
        ptr = car;
        BOOST_TEST(ptr->getActualRentalPrice() == 500);
    }
    BOOST_AUTO_TEST_CASE(Car_getActualRentalPrice_1200_B_Test){
        unsigned int engine = 1200;
        Car *car = new Car(plateNumber,price,engine,B);
        ptr = car;
        BOOST_TEST(ptr->getActualRentalPrice() == 605);
    }
    BOOST_AUTO_TEST_CASE(Car_getActualRentalPrice_1500_C_Test){
        unsigned int engine = 1500;
        Car *car =new Car(plateNumber,price,engine,C);
        ptr = car;
        BOOST_TEST(ptr->getActualRentalPrice() == 750);
    }
    BOOST_AUTO_TEST_CASE(Car_getActualRentalPrice_1800_D_Test){
        unsigned int engine=1800;
        Car *car =new Car(plateNumber,price,engine,D);
        ptr = car;
        BOOST_TEST(ptr->getActualRentalPrice() == 910);
    }
    BOOST_AUTO_TEST_CASE(Car_getActualRentalPrice_2000_E_Test){
        unsigned int engine = 2000;
        Car *car = new Car(plateNumber,price,engine,E);
        ptr = car;
        BOOST_TEST(ptr->getActualRentalPrice() == 1125);
    }

BOOST_AUTO_TEST_SUITE_END();
