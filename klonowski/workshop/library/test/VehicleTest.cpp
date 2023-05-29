#include <boost/test/unit_test.hpp>
#include "model/vehicle.h"
#include <model/bicycle.h>

BOOST_AUTO_TEST_SUITE(TestSuiteVehicle)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(.03));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {

        std::string plateNumber = "ABCD1";
        unsigned int basePrice = 1;

        Bicycle vehicle(plateNumber, basePrice);

        BOOST_TEST(vehicle.getPlateNumber() == plateNumber);
        BOOST_TEST(vehicle.getBasePrice() == basePrice);

    }

    BOOST_AUTO_TEST_CASE(SetPlateNumber)
    {
        std::string plateNumber = "ABCD1";
        Bicycle vehicle(plateNumber, 1);
        std::string plateNumber1 = "XDXD2";
        vehicle.setPlateNumber(plateNumber1);
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber1);

        vehicle.setPlateNumber("");
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber1);
    }

    BOOST_AUTO_TEST_CASE(SetBasePrice)
    {
        std::string plateNumber = "ABCD1";

        Bicycle vehicle(plateNumber, 1);
        unsigned int basePrice = 4;
        vehicle.setBasePrice(basePrice);
        BOOST_TEST(vehicle.getBasePrice() == basePrice);

        vehicle.setBasePrice(NULL);
        BOOST_TEST(vehicle.getBasePrice() == basePrice);
    }

    //ROBIC 2.2

BOOST_AUTO_TEST_SUITE_END()