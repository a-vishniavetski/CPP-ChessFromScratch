//
// Created by Hubert Klonowski on 14/05/2023.
//
#include <boost/test/unit_test.hpp>
#include "model/moped.h"
#include "string"
#include "typedefs.h"


BOOST_AUTO_TEST_SUITE(TestSuiteMoped)
    std::string plateNumber = "ABCD1";
    unsigned int price = 500;
    VehiclePtr ptr;
    BOOST_AUTO_TEST_CASE(Moped_getActualRentalPrice_1000_Test){
        unsigned int engine = 1000;
        Moped *moped = new Moped(plateNumber,price,engine);
        ptr = moped;
        BOOST_TEST(ptr->getActualRentalPrice() == 500);
    }
    BOOST_AUTO_TEST_CASE(Moped_getActualRentalPrice_1200_Test){
        unsigned int engine = 1200;
        Moped *moped = new Moped(plateNumber,price,engine);
        ptr = moped;
        BOOST_TEST(ptr->getActualRentalPrice() == 550);
    }
    BOOST_AUTO_TEST_CASE(Moped_getActualRentalPrice_1800_Test){
        unsigned int engine=1800;
        Moped *moped = new Moped(plateNumber,price,engine);
        ptr = moped;
        BOOST_TEST(ptr->getActualRentalPrice() == 700);
    }
    BOOST_AUTO_TEST_CASE(Moped_getActualRentalPrice_2000_Test){
        unsigned int engine = 2000;
        Moped *moped = new Moped(plateNumber,price,engine);
        ptr = moped;
        BOOST_TEST(ptr->getActualRentalPrice() == 750);
    }
    BOOST_AUTO_TEST_CASE(Moped_getActualRentalPrice_2100_Test){
        unsigned int engine = 2100;
        Moped *moped = new Moped(plateNumber,price,engine);
        ptr = moped;
        BOOST_TEST(ptr->getActualRentalPrice() == 750);
    }

BOOST_AUTO_TEST_SUITE_END();
