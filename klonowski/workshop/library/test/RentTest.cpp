#include <boost/test/unit_test.hpp>
#include "model/address.h"
#include "model/rent.h"
#include "model/vehicle.h"
#include "model/client.h"
#include "model/bicycle.h"
#include "typedefs.h"


BOOST_AUTO_TEST_SUITE(TestSuiteRent)
    std::vector<RentPtr> rents;
    std::string plateNumber = "ABCD1";

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(.03));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {

        unsigned int id = 1;
        AddressPtr address = new Address("London", "Alley", "2");

        Bicycle* vehicle = new Bicycle(plateNumber, 2);
        ClientPtr c1 = new Client("Andrzej", "Konieczny", "12312312312", address, rents);

        Rent rent(id, vehicle, c1, true, pt::not_a_date_time);
        pt::ptime now = pt::second_clock::local_time(); //hope this takes no longer than 59 secs...
        BOOST_TEST_REQUIRE(!rent.getBeginTime().is_not_a_date_time()); //if this isn't met, the next check doesn't make sense...
        pt::time_period skew = pt::time_period(rent.getBeginTime(), now);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));
        BOOST_TEST(rent.getId() == id);
        BOOST_TEST(rent.getVehicle() == vehicle);
        BOOST_TEST(rent.getClient() == c1);
        BOOST_TEST(rent.getVehicle()->isRented() == true);

        delete address;
        delete vehicle;
        delete c1;

    }
    BOOST_AUTO_TEST_CASE(EndRentTest)
    {

        unsigned int id = 1;
        AddressPtr address = new Address("London", "Alley", "2");
        Bicycle* vehicle = new Bicycle(plateNumber, 2);

        ClientPtr c1 = new Client("Andrzej", "Konieczny", "12312312312", address, rents);

        Rent rent(id, vehicle, c1, true, pt::not_a_date_time);

        BOOST_TEST(rent.getClient()->getCurrentRents().size() == 0);
        BOOST_TEST(rent.getVehicle()->isRented() == false);
        BOOST_TEST(rent.getEndTime() == pt::ptime(gr::date(2023,5,13),pt::hours(9)+pt::minutes(25)));


        delete address;
        delete c1;
        delete vehicle;

    }

    BOOST_AUTO_TEST_CASE(GetRentDaysTest)
    {

        unsigned int id = 1;
        AddressPtr address = new Address("London", "Alley", "2");
        Bicycle* vehicle = new Bicycle(plateNumber, 2);
        ClientPtr c1 = new Client("Andrzej", "Konieczny", "12312312312", address, rents);

        pt::ptime beg = pt::ptime(gr::date(2023,4,18),pt::hours(0)+pt::minutes(00));

        pt::ptime end = pt::ptime(gr::date(2023,4,18),pt::hours(0)+pt::minutes(1));
        pt::ptime end1 = pt::ptime(gr::date(2023,4,18),pt::hours(23)+pt::minutes(59));
        pt::ptime end2 = pt::ptime(gr::date(2023,4,18),pt::hours(24)+pt::minutes(0));
        Rent rent1(id, vehicle, c1, true, pt::not_a_date_time, beg);
        Rent rent2(id, vehicle, c1, true, pt::not_a_date_time, beg);
        Rent rent3(id, vehicle, c1, true, pt::not_a_date_time, beg);

        rent1.endRent(end);
        rent2.endRent(end1);
        rent3.endRent(end2);

        BOOST_TEST(rent1.getRentDays() == 1);
        BOOST_TEST(rent2.getRentDays() == 1);
        BOOST_TEST(rent3.getRentDays() == 2);


        delete address;
        delete c1;
        delete vehicle;

    }

    BOOST_AUTO_TEST_CASE(RentCostTest)
    {

        unsigned int id = 1;
        AddressPtr address = new Address("London", "Alley", "2");
        Bicycle* vehicle = new Bicycle(plateNumber, 2);
        ClientPtr c1 = new Client("Andrzej", "Konieczny", "12312312312", address, rents);
        pt::ptime beg = pt::ptime(gr::date(2023,4,18),pt::hours(0)+pt::minutes(00));
        Rent rent(id, vehicle, c1, true, pt::not_a_date_time, beg);
        Rent rent1(id, vehicle, c1, true, pt::not_a_date_time, beg);
        pt::ptime end1 = pt::ptime(gr::date(2023,4,18),pt::hours(23)+pt::minutes(59));
        pt::ptime end2 = pt::ptime(gr::date(2023,4,18),pt::hours(0)+pt::minutes(0));

        rent.endRent(end1);
        rent1.endRent(end2);

        BOOST_TEST(rent.getRentCost() == 2);
        BOOST_TEST(rent.getRentCost() == 0);

        delete address;
        delete c1;
        delete vehicle;

    }

    BOOST_AUTO_TEST_CASE(RentCost1Test)
    {

        unsigned int id = 1;
        AddressPtr address = new Address("London", "Alley", "2");
        Bicycle* vehicle = new Bicycle(plateNumber, 2);
        ClientPtr c1 = new Client("Andrzej", "Konieczny", "12312312312", address, rents);
        pt::ptime beg = pt::ptime(gr::date(2023,4,18),pt::hours(0)+pt::minutes(00));
        Rent rent(id, vehicle, c1, true, pt::not_a_date_time, beg);
        pt::ptime end1 = pt::ptime(gr::date(2023,4,18),pt::hours(23)+pt::minutes(59));

        rent.endRent(end1);
        int cost = rent.getRentCost();

        vehicle->setBasePrice(9);

        BOOST_TEST(rent.getRentCost() == cost);

        delete address;
        delete c1;
        delete vehicle;

    }

BOOST_AUTO_TEST_SUITE_END()