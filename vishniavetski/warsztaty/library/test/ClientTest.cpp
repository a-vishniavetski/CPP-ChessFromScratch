//
// Created by avish on 3/28/2023.
//
#include <boost/test/unit_test.hpp>
#include "model/Client.h"

struct TestSuiteClientFixture {
    const std::string testFirstName = "Aliaksei";
    const std::string testLastName = "Vishniavetski";
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
		BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.03));
		BOOST_TEST(true);
    }
	
    BOOST_AUTO_TEST_CASE(ConstructorTest) {
		Client test_client = Client(testFirstName, testLastName, testPersonalID, testaddress1);

		BOOST_TEST(testFirstName == test_client.getFirstName());
        BOOST_TEST(testLastName == test_client.getLastName());
        BOOST_TEST(testPersonalID == test_client.getPersonalID());
    }
	
	BOOST_AUTO_TEST_CASE(FirstNameSetterTest){
		// pozytywny test
		
		Client test_client = Client(testFirstName, testLastName, testPersonalID, testaddress1);
		test_client.setFirstName("Jordan");
		
		string getter_name = test_client.getFirstName();
		
		BOOST_TEST("Jordan" == getter_name);

		// negatywny test
		string wrong_name = "";

        Client test_client2 = Client(testFirstName, testLastName, testPersonalID, testaddress1);
		test_client.setFirstName(wrong_name);
		
		getter_name = test_client2.getFirstName();
		
		BOOST_TEST(testFirstName == getter_name);
	}
	
		BOOST_AUTO_TEST_CASE(LastNameSetterTest){
		// pozytywny test
		string name = "Aliaksei";
		string last_name = "Vish";
		string id = "249518";
		
		Client test_client = Client("InitialName", "Initial last_name", "Initial id", testaddress1);
		test_client.setLastName(last_name);
		
		string getter_last_name = test_client.getLastName();
		
		BOOST_TEST(last_name == getter_last_name);
		
		// negatywny test
		string wrong_last_name = "";
		
		Client test_client2 = Client("InitialName", "Initial last_name", "Initial id", testaddress1);
		test_client.setLastName(wrong_last_name);
		
		getter_last_name = test_client2.getLastName();
		
		BOOST_TEST(wrong_last_name != getter_last_name);
	}
BOOST_AUTO_TEST_SUITE_END()