//
// Created by student on 17.04.23.
//

#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Address.h"
#include "model/Client.h"

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

    BOOST_AUTO_TEST_CASE(ConstructorTestDefaultBeginTime){
        Rent *r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);

        // id
        BOOST_TEST(testId == r->getId());
        BOOST_TEST(testClient->currentRents.back()->getId() == r->getId());
        // beginTime
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time()); // time has been set to something
        pt::time_period skew = pt::time_period(r->getBeginTime(), pt::second_clock::local_time());
        BOOST_TEST((skew.length().hours() == 0 && skew.length().minutes() == 0));

        delete r;
    }

    BOOST_AUTO_TEST_CASE(ConstructorTestAnyTime){
        pt::ptime startTime = pt::second_clock::local_time();
        Rent *r = new Rent(testId, testClient, testVehicle, startTime);

        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time());
        BOOST_TEST(r->getBeginTime() == startTime);
}

    BOOST_AUTO_TEST_CASE(EndRentTest){
        Rent *r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);

        // Endtime now and freeing the vehicle
        pt::ptime now = pt::second_clock::local_time();
        r->endRent(pt::not_a_date_time);
        pt::time_period skew = pt::time_period(now, r->getEndTime());
        BOOST_TEST_REQUIRE(!testVehicle->isRented());
        BOOST_TEST((skew.length().hours() == 0 && skew.length().minutes() == 0));
        delete r;

        // Endtime < BeginTime
        r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);
        pt::ptime then = pt::ptime(gr::date(1999,5,13),pt::hours(9)+pt::minutes(25));
        r->endRent(then);
        BOOST_TEST(r->getBeginTime() == r->getEndTime());
        delete r;

        // Endtime okay
        r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);
        now = pt::second_clock::local_time();
        r->endRent(now);
        BOOST_TEST(r->getEndTime() == now);
        delete r;
}

    BOOST_AUTO_TEST_CASE(GetRentDaysTest){
        Rent *r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);

        // rent not over yet
        BOOST_TEST(r->getRentDays() == 0);
        delete r;

        // rent duration <= 1 min
        r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);
        pt::time_duration one_minute = {0, 1, 0};
        pt::ptime _endTime = r->getBeginTime() + one_minute;
        r->endRent(_endTime);
        BOOST_TEST(r->getRentDays() == 0);
        delete r;

        // rent longer than a minute
        // < 24
        r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);
        int hours = 23;
        pt::time_duration _duration = {hours, 0, 0};
        _endTime = r->getBeginTime() + _duration;
        r->endRent(_endTime);
        BOOST_TEST(r->getRentDays() == 1);
        // > 24
        hours = 36;
        _duration = {hours, 0, 0};
        _endTime = r->getBeginTime() + _duration;
        r->endRent(_endTime);
        BOOST_TEST(r->getRentDays() == 2);
        delete r;

        // wartosc graniczna 24h02m
        r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);
        hours = 24;
        _duration = {hours, 2, 0};
        _endTime = r->getBeginTime() + _duration;
        r->endRent(_endTime);
        BOOST_TEST(r->getRentDays() == 2);
        delete r;
}


BOOST_AUTO_TEST_SUITE_END()