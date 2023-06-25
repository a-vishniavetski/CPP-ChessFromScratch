#include <boost/test/unit_test.hpp>
#include <Player.h>
#include <typedefs.h>
#include "Game.h"
#include "Field.h"
#include "Unit.h"

BOOST_AUTO_TEST_SUITE(PlayerAiTest)
    BOOST_AUTO_TEST_CASE(test_ChooseUnit){
    // inicjalizacja
        GamePtr game = make_shared<Game>();
        game->newGame(true, WHITE);
        vector<PlayerPtr> players = game->getPlayers();
        PlayerPtr player_ai;

        if (players[0]->getPlayerType() == AI){
            player_ai = players[0];
        }
        else{
            player_ai = players[1];
        }
    // test
        bool unit_found = false;
        UnitPtr chosen_unit = player_ai->chooseUnit(game->getBoard());
        for (auto unit: player_ai->getUnits()){
            if (unit == chosen_unit){
                unit_found = true;
            }
        }
        BOOST_TEST(unit_found, true);
}
    BOOST_AUTO_TEST_CASE(test_ChooseMove){
        // inicjalizacja
        GamePtr game = make_shared<Game>();
        game->newGame(true, WHITE);
        vector<PlayerPtr> players = game->getPlayers();
        PlayerPtr player_ai;

        if (players[0]->getPlayerType() == AI){
            player_ai = players[0];
        }
        else{
            player_ai = players[1];
        }
        // test
        // get unit with legal moves available
        vector<FieldPtr> legal_moves;
        while (1){
            UnitPtr chosen_unit = player_ai->chooseUnit(game->getBoard());
            legal_moves = game->getLegalMoves(chosen_unit);
            if (!legal_moves.empty()){
                break;
            }
        }
        // check the chooseMove
        FieldPtr chosen_field = player_ai->chooseMove(legal_moves);
        bool field_found = false;
        for (auto field: legal_moves){
            if (field == chosen_field){
                field_found = true;
            }
        }
        BOOST_TEST(field_found, true);

}

BOOST_AUTO_TEST_SUITE_END()