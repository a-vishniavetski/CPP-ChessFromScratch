#include <boost/test/unit_test.hpp>
//#include <bits/stdc++.h>
#include <typedefs.h>
#include <exceptions.h>
#include "Game.h"
#include "Field.h"
#include "Unit.h"


BOOST_AUTO_TEST_SUITE(TestSuiteExceptions)

    BOOST_AUTO_TEST_CASE(NoUnitFoundExceptionTest){
        FieldPtr field = make_shared<Field>(1, 1, "white");
        BOOST_REQUIRE_THROW(field->getOccupiedByUnit(), NoUnitFoundException);
    }


BOOST_AUTO_TEST_SUITE_END()