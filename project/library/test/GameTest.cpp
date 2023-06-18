#include <boost/test/unit_test.hpp>
//#include <bits/stdc++.h>
#include <typedefs.h>
#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Pawn.h"
#include "Queen.h"

struct GameFixture {
    GamePtr game;
    BoardPtr board;
    std::vector<PlayerPtr> players;

    GameFixture() {
        board = std::make_shared<Board>(8, 8, std::vector<FieldPtr>());
        players.push_back(std::make_shared<Player>("Player 1", 0, WHITE));
        players.push_back(std::make_shared<Player>("Player 2", 1, BLACK));
        game = std::make_shared<Game>(players, board, 0);
    }

    ~GameFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteGame, GameFixture)

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

    BOOST_AUTO_TEST_CASE(test_IsCheckWhite) {
        game->setIsCheckWhite(true);
        BOOST_CHECK(game->isCheckWhite());

        game->setIsCheckWhite(false);
        BOOST_CHECK(!game->isCheckWhite());
    }

    BOOST_AUTO_TEST_CASE(test_IsCheckBlack) {
        game->setIsCheckBlack(true);
        BOOST_CHECK(game->isCheckBlack());

        game->setIsCheckBlack(false);
        BOOST_CHECK(!game->isCheckBlack());
    }

    BOOST_AUTO_TEST_CASE(test_IsMate) {
        game->setIsMate(true);
        BOOST_CHECK(game->isMate());

        game->setIsMate(false);
        BOOST_CHECK(!game->isMate());
    }

    BOOST_AUTO_TEST_CASE(test_GetVictoryColor) {
        game->setVictoryColor(WHITE);
        BOOST_CHECK_EQUAL(game->getVictoryColor(), WHITE);

        game->setVictoryColor(BLACK);
        BOOST_CHECK_EQUAL(game->getVictoryColor(), BLACK);
    }

    BOOST_AUTO_TEST_CASE(test_GetPlayers) {
        const std::vector<PlayerPtr>& gamePlayers = game->getPlayers();
        BOOST_CHECK_EQUAL(gamePlayers.size(), 2);
        BOOST_CHECK_EQUAL(gamePlayers[0]->getName(), "Player 1");
        BOOST_CHECK_EQUAL(gamePlayers[1]->getName(), "Player 2");
    }

    BOOST_AUTO_TEST_CASE(test_SetPlayers) {
        std::vector<PlayerPtr> newPlayers;
        newPlayers.push_back(std::make_shared<Player>("Player 3", 3, WHITE));
        newPlayers.push_back(std::make_shared<Player>("Player 4", 4, BLACK));
        game->setPlayers(newPlayers);

        const std::vector<PlayerPtr>& gamePlayers = game->getPlayers();
        BOOST_CHECK_EQUAL(gamePlayers.size(), 2);
        BOOST_CHECK_EQUAL(gamePlayers[0]->getName(), "Player 3");
        BOOST_CHECK_EQUAL(gamePlayers[1]->getName(), "Player 4");
    }

    BOOST_AUTO_TEST_CASE(test_GetBoard) {
        BoardPtr gameBoard = game->getBoard();
        BOOST_CHECK_EQUAL(gameBoard, board);
    }

    BOOST_AUTO_TEST_CASE(test_SetBoard) {
        BoardPtr newBoard = std::make_shared<Board>(10, 10, std::vector<FieldPtr>());
        game->setBoard(newBoard);
        BoardPtr gameBoard = game->getBoard();
        BOOST_CHECK_EQUAL(gameBoard, newBoard);
    }

    BOOST_AUTO_TEST_CASE(test_GetTotalTurns) {
        BOOST_CHECK_EQUAL(game->getTotalTurns(), 0);
    }

    BOOST_AUTO_TEST_CASE(test_SetTotalTurns) {
        game->setTotalTurns(10);
        BOOST_CHECK_EQUAL(game->getTotalTurns(), 10);
    }

    BOOST_AUTO_TEST_CASE(test_IsWhiteTurn) {
        game->setWhiteTurn(true);
        BOOST_CHECK(game->isWhiteTurn());

        game->setWhiteTurn(false);
        BOOST_CHECK(!game->isWhiteTurn());
    }

    BOOST_AUTO_TEST_CASE(test_GetTakenUnitsByColor) {
        std::vector<UnitPtr> whiteTakenUnits = game->getTakenUnitsByColor(WHITE);
        whiteTakenUnits.push_back(std::make_shared<Pawn>("Pawn", 99, nullptr, true, WHITE));
        whiteTakenUnits.push_back(std::make_shared<Pawn>("Pawn", 88, nullptr, true, WHITE));
        
        std::vector<UnitPtr> blackTakenUnits = game->getTakenUnitsByColor(BLACK);
        blackTakenUnits.push_back(std::make_shared<Pawn>("Pawn", 100, nullptr, true, BLACK));
        
        BOOST_CHECK_EQUAL(whiteTakenUnits.size(), 2);
        BOOST_CHECK_EQUAL(whiteTakenUnits[0]->getColor(), WHITE);
        BOOST_CHECK_EQUAL(whiteTakenUnits[1]->getColor(), WHITE);
        BOOST_CHECK_EQUAL(blackTakenUnits.size(), 1);
        BOOST_CHECK_EQUAL(blackTakenUnits[0]->getColor(), BLACK);
    }

    BOOST_AUTO_TEST_CASE(test_IsStalemate) {
        game->setIsStalemate(true);
        BOOST_CHECK(game->isStalemate());

        game->setIsStalemate(false);
        BOOST_CHECK(!game->isStalemate());
    }

    BOOST_AUTO_TEST_CASE(test_IsTie) {
        game->setIsTie(true);
        BOOST_CHECK(game->isTie());

        game->setIsTie(false);
        BOOST_CHECK(!game->isTie());
    }

BOOST_AUTO_TEST_SUITE_END()
