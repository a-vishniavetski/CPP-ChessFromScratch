//
// Created by student on 17.04.23.
//

#include <boost/test/unit_test.hpp>
#include "model/Rent.h"

using namespace std;

struct TestSuiteRentFixture {
    int testId = 1;
    Address *testAddress;
    Client *testClient;
    Vehicle *testVehicle;

    TestSuiteRentFixture(){
        testAddress = new Address("City", "Street", "Number" );
        testClient = new Client("Al", "Vi", "12345", testAddress);
        testVehicle = new Vehicle(10, "999");
    };

    ~TestSuiteRentFixture(){
        delete testAddress;
        delete testClient;
    };
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest){
        Rent r = Rent(testId, testClient, testVehicle);
        BOOST_TEST(testId == r.getId());
        BOOST_TEST(testClient->currentRents.back()->getId() == r.getId());
    }


BOOST_AUTO_TEST_SUITE_END()