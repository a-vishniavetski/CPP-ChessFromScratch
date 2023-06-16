#include <boost/test/unit_test.hpp>
//#include <bits/stdc++.h>
#include <typedefs.h>
#include "Game.h"
#include "Field.h"
#include "Unit.h"


BOOST_AUTO_TEST_SUITE(TestSuiteUnit)

    BOOST_AUTO_TEST_CASE(ConstructorTest){
    FieldPtr field = make_shared<Field>(1, 1, "white");
    UnitPtr unit = make_shared<Unit>("Unit", 1, field, true, WHITE);
    BOOST_TEST(unit->getColor() == WHITE);
    BOOST_TEST(unit->getField() == field);
    BOOST_TEST(unit->getUuid() == 1);
    BOOST_TEST(unit->getName() == "Unit");
}
    BOOST_AUTO_TEST_CASE(GetMovesTest) {
        GamePtr game = make_shared<Game>();
        game->new_game();
        int x = 1;
        int y = 1;
        vector<FieldPtr> need_moves;
        need_moves.push_back(game->getBoard()->get_field(1, 2));
        need_moves.push_back(game->getBoard()->get_field(1, 3));
        UnitPtr temp_unit =  game->getBoard()->get_field(x, y)->getOccupiedByUnit();
        BoardPtr temp = game->getBoard();
        vector<FieldPtr> returned_moves = temp_unit->get_moves(game->getBoard());
        sort(returned_moves.begin(), returned_moves.end());
        sort(need_moves.begin(), need_moves.end());


        BOOST_TEST(need_moves == returned_moves);
    }

BOOST_AUTO_TEST_SUITE_END()
