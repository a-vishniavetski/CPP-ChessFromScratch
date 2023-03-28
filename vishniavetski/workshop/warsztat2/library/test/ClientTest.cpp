//
// Created by avish on 3/28/2023.
//
#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
		BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.03));
		BOOST_TEST(true);
    }
	
    BOOST_AUTO_TEST_CASE(ConstructorTest) {
		// zmienne testowe
		string name = "Aliaksei";
		string last_name = "Vish";
		string id = "249518";
		
		Client test_client = Client(name, last_name, id);
		
		string getter_name = test_client.getFirstName();
		string getter_last_name = test_client.getLastName();
		string getter_id = test_client.getPersonalID();
		
		
		BOOST_TEST(name == getter_name);
		BOOST_TEST(last_name == getter_last_name);
		BOOST_TEST(id == getter_id);
    }
	
	BOOST_AUTO_TEST_CASE(FirstNameSetterTest){
		// pozytywny test
		string name = "Aliaksei";
		string last_name = "Vish";
		string id = "249518";
		
		Client test_client = Client("InitialName", "Initial last_name", "Initial id");
		test_client.setFirstName(name);
		
		string getter_name = test_client.getFirstName();
		
		BOOST_TEST(name == getter_name);
		
		// negatywny test
		string wrong_name = "";
		
		test_client = Client("InitialName", "Initial last_name", "Initial id");
		test_client.setFirstName(wrong_name);
		
		getter_name = test_client.getFirstName();
		
		BOOST_TEST(name != getter_name);
	}
	
		BOOST_AUTO_TEST_CASE(LastNameSetterTest){
		// pozytywny test
		string name = "Aliaksei";
		string last_name = "Vish";
		string id = "249518";
		
		Client test_client = Client("InitialName", "Initial last_name", "Initial id");
		test_client.setLastName(last_name);
		
		string getter_last_name = test_client.getLastName();
		
		BOOST_TEST(last_name == getter_last_name);
		
		// negatywny test
		string wrong_last_name = "";
		
		test_client = Client("InitialName", "Initial last_name", "Initial id");
		test_client.setLastName(wrong_last_name);
		
		getter_last_name = test_client.getLastName();
		
		BOOST_TEST(wrong_last_name != getter_last_name);
	}
BOOST_AUTO_TEST_SUITE_END()