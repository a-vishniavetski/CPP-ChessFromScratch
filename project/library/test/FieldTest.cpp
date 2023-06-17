#include <boost/test/unit_test.hpp>
//#include <bits/stdc++.h>
#include <typedefs.h>
#include "Game.h"
#include "Field.h"
#include "Unit.h"


BOOST_AUTO_TEST_SUITE(TestSuiteField)

    BOOST_AUTO_TEST_CASE(ConstructorTest){
        FieldPtr field = make_shared<Field>(1, 1, "white");
        UnitPtr unit = make_shared<Unit>("Unit", 1, field, true, WHITE);
        field->occupy(unit);
        BOOST_TEST(field->getColor() == "white");
        BOOST_TEST(field->isOccupied());
        BOOST_TEST(field->getOccupiedByUnit() == unit);
    }


BOOST_AUTO_TEST_SUITE_END()