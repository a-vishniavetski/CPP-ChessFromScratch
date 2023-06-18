#include <boost/test/unit_test.hpp>
//#include <bits/stdc++.h>
#include <typedefs.h>
#include <exceptions.h>
#include "Game.h"
#include "Field.h"
#include "Unit.h"


struct FieldFixture {
    FieldPtr field;
    UnitPtr unit;
    
    FieldFixture() {
        field = std::make_shared<Field>(0, 0, "white");
        unit = make_shared<Unit>("Unit", 1, field, true, WHITE);
    }

    ~FieldFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteField, FieldFixture)

    BOOST_AUTO_TEST_CASE(test_Constructor){
        FieldPtr field = make_shared<Field>(1, 1, "white");
        
        field->occupy(unit);
        BOOST_TEST(field->getColor() == "white");
        BOOST_TEST(field->isOccupied());
        BOOST_TEST(field->getOccupiedByUnit() == unit);
    }

    BOOST_AUTO_TEST_CASE(test_GetXCoord) {
        BOOST_CHECK_EQUAL(field->getXCoord(), 0);
    }
    
    BOOST_AUTO_TEST_CASE(test_SetXCoord) {
        field->setXCoord(1);
        BOOST_CHECK_EQUAL(field->getXCoord(), 1);
    }
    
    BOOST_AUTO_TEST_CASE(test_GetYCoord) {
        BOOST_CHECK_EQUAL(field->getYCoord(), 0);
    }
    
    BOOST_AUTO_TEST_CASE(test_SetYCoord) {
        field->setYCoord(1);
        BOOST_CHECK_EQUAL(field->getYCoord(), 1);
    }
    
    BOOST_AUTO_TEST_CASE(test_IsOccupied) {
        BOOST_CHECK_EQUAL(field->isOccupied(), false);
    }
    
    BOOST_AUTO_TEST_CASE(test_SetOccupied) {
        field->setOccupied(true);
        BOOST_CHECK_EQUAL(field->isOccupied(), true);
    }
    
    BOOST_AUTO_TEST_CASE(test_GetOccupiedByUnit) {
        BOOST_CHECK_THROW(field->getOccupiedByUnit(), NoUnitFoundException);
    }
    
    BOOST_AUTO_TEST_CASE(test_Occupy) {
        field->occupy(unit);
        BOOST_CHECK_EQUAL(field->isOccupied(), true);
        BOOST_CHECK_EQUAL(field->getOccupiedByUnit(), unit);
    }
    
    BOOST_AUTO_TEST_CASE(test_Deoccupy) {
        field->occupy(unit);
        field->deoccupy();
        BOOST_CHECK_EQUAL(field->isOccupied(), false);
        BOOST_CHECK_THROW(field->getOccupiedByUnit(), NoUnitFoundException);
    }
    
    BOOST_AUTO_TEST_CASE(test_GetColor) {
        BOOST_CHECK_EQUAL(field->getColor(), "white");
    }
    
    BOOST_AUTO_TEST_CASE(test_SetColor) {
        field->setColor("black");
        BOOST_CHECK_EQUAL(field->getColor(), "black");
    }
    
    BOOST_AUTO_TEST_CASE(test_GetFieldInfo) {
        std::string expected = "Field(0, 0)white:Not_Occupied";
        std::string info = field->getFieldInfo();
        BOOST_CHECK_EQUAL(info, expected);
    }

BOOST_AUTO_TEST_SUITE_END()
