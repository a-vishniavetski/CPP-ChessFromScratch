#include <boost/test/unit_test.hpp>
#include "model/client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(.03));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {

        std::string name = "Jan";
        std::string lastname = "Kowalski";
        std::string personalId = "12312312312";

        Client client(name, lastname, personalId);

        BOOST_TEST(client.getFirstName() == name);
        BOOST_TEST(client.getLastName() == lastname);
        BOOST_TEST(client.getPersonalID() == personalId);

    }

    BOOST_AUTO_TEST_CASE(SetFirstNameTest)
    {
        Client client("Jan", "Nowak", "12312312312");
        std::string firstName = "Hubert";
        client.setFirstName(firstName);
        BOOST_TEST(client.getFirstName() == firstName);

        client.setFirstName("");
        BOOST_TEST(client.getFirstName() == firstName);

    }

    BOOST_AUTO_TEST_CASE(SetLastNameTest)
    {
        Client client("Jan", "Nowak", "12312312312");
        std::string lastName = "Klonowski";
        client.setLastName(lastName);
        BOOST_TEST(client.getLastName() == lastName);

        client.setLastName("");
        BOOST_TEST(client.getLastName() == lastName);

    }

    BOOST_AUTO_TEST_CASE(SetPersonalIDTest)
    {
        Client client("Jan", "Nowak", "12312312312");
        std::string personalID = "00000000000";
        client.setPersonalID(personalID);
        BOOST_TEST(client.getPersonalID() == personalID);

        client.setPersonalID("");
        BOOST_TEST(client.getPersonalID() == personalID);

    }

BOOST_AUTO_TEST_SUITE_END()