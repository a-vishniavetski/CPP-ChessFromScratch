//
// Created by student on 17.04.23.
//

#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"

using namespace std;

struct TestSuiteVehicleFixture {
    const string testPlateNumber = "12345";
    int testBasePrice = 10;

    TestSuiteVehicleFixture(){};

    ~TestSuiteVehicleFixture(){};
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest){
        Vehicle v = Vehicle(testBasePrice, testPlateNumber);
        BOOST_TEST(v.getBasePrice() == testBasePrice);
        BOOST_TEST(v.getPlateNumber() == testPlateNumber);
    }

    BOOST_AUTO_TEST_CASE(BasePriceSetterTest){
        Vehicle v = Vehicle(0, ".....");
        // pozytywny
        v.setBasePrice(testBasePrice);
        BOOST_TEST(v.getBasePrice() == testBasePrice);
    }

    BOOST_AUTO_TEST_CASE(PlateNumberSetterTest) {
        Vehicle v = Vehicle(0, ".....");
        // pozytywny
        const std::string testPlateNumber = "DEF456";
        v.setPlateNumber(testPlateNumber);
        BOOST_TEST(v.getPlateNumber() == testPlateNumber);
        // negatywny
        const std::string emptyPlateNumber = "";
        v.setPlateNumber(emptyPlateNumber);
        BOOST_TEST(v.getPlateNumber() != emptyPlateNumber);
    }


BOOST_AUTO_TEST_SUITE_END()