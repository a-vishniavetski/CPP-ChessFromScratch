#include <boost/test/unit_test.hpp>
//#include <bits/stdc++.h>
#include <typedefs.h>
#include "Game.h"
#include "Field.h"
#include "Unit.h"
#include "Pawn.h"
#include "Queen.h"


BOOST_AUTO_TEST_SUITE(TestSuiteGame)

    BOOST_AUTO_TEST_CASE(ConstructorTest){

    }


    BOOST_AUTO_TEST_CASE(CopyBoardTest) {
        GamePtr game = make_shared<Game>();
        game->new_game();
        BoardPtr game_board = game->getBoard();
        game->place_unit_at(4, 4, make_shared<Pawn>("Pawn", -1, nullptr, true, WHITE), game_board);
        game->place_unit_at(5, 5, make_shared<Queen>("Queen", -1, nullptr, true, WHITE), game_board);

        BoardPtr new_board = game->copy_board(game_board);

        for (auto field:game_board->getFields()){
            BOOST_TEST_REQUIRE(field->isOccupied() == new_board->get_field(field->getXCoord(), field->getYCoord())->isOccupied());
            if (field->isOccupied()){
                BOOST_TEST(field->getOccupiedByUnit()->get_unit_info() == new_board->get_field(field->getXCoord(), field->getYCoord())->getOccupiedByUnit()->get_unit_info());
            }
        }
    }

BOOST_AUTO_TEST_SUITE_END()
