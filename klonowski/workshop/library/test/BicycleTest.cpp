//
// Created by Hubert Klonowski on 14/05/2023.
//
#include <boost/test/unit_test.hpp>
#include "model/bicycle.h"
#include "string"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteBicycle)
    BOOST_AUTO_TEST_CASE(BicycleGetActualRentalPriceTest){
        std::string plateNumber="ABCD123";
        VehiclePtr ptr;
        unsigned int price=10;
        Bicycle *b=new Bicycle(plateNumber,price);
        ptr=b;
        BOOST_TEST(ptr->getActualRentalPrice()==price);
    }

BOOST_AUTO_TEST_SUITE_END();
