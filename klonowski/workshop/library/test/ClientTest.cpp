#include <boost/test/unit_test.hpp>
#include "model/client.h"
#include "model/address.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    Address *testaddress1;
    Address *testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = new Address("London", "Accacia Avenue", "22");
        testaddress2 = new Address("London", "Rue Morgue", "13");
    }

    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(.03));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {
        std::vector<RentPtr> rents;

        Client client(testFirstName, testLastName, testPersonalID, testaddress1, rents);

        BOOST_TEST(client.getFirstName() == testFirstName);
        BOOST_TEST(client.getLastName() == testLastName);
        BOOST_TEST(client.getPersonalID() == testPersonalID);
        BOOST_TEST(client.getAddress() == testaddress1);

    }

    BOOST_AUTO_TEST_CASE(SetFirstNameTest)
    {
        std::vector<RentPtr> rents;

        Client client(testFirstName, testLastName, testPersonalID, testaddress1, rents);
        std::string firstName = "Hubert";
        client.setFirstName(firstName);
        BOOST_TEST(client.getFirstName() == firstName);

        client.setFirstName("");
        BOOST_TEST(client.getFirstName() == firstName);

    }

    BOOST_AUTO_TEST_CASE(SetLastNameTest)
    {
        std::vector<RentPtr> rents;

        Client client(testFirstName, testLastName, testPersonalID, testaddress1, rents);
        std::string lastName = "Klonowski";
        client.setLastName(lastName);
        BOOST_TEST(client.getLastName() == lastName);

        client.setLastName("");
        BOOST_TEST(client.getLastName() == lastName);

    }

    BOOST_AUTO_TEST_CASE(SetPersonalIDTest)
    {
        std::vector<RentPtr> rents;

        Client client(testFirstName, testLastName, testPersonalID, testaddress1, rents);
        std::string personalID = "00000000000";
        client.setPersonalID(personalID);
        BOOST_TEST(client.getPersonalID() == personalID);

        client.setPersonalID("");
        BOOST_TEST(client.getPersonalID() == personalID);

    }

    BOOST_AUTO_TEST_CASE(SetAddressTest)
    {
        std::vector<RentPtr> rents;

        Client client(testFirstName, testLastName, testPersonalID, testaddress1, rents);

        client.setAddress(testaddress2);
        BOOST_TEST(client.getAddress() == testaddress2);

        client.setAddress(nullptr);
        BOOST_TEST(client.getAddress() == testaddress2);

    }

BOOST_AUTO_TEST_SUITE_END()