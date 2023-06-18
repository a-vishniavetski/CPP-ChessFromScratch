#include <boost/test/unit_test.hpp>
#include <typedefs.h>
#include "Game.h"
#include "Field.h"
#include "Unit.h"

struct UnitFixture {
    UnitPtr unit;
    FieldPtr field;

    UnitFixture() {
        field = std::make_shared<Field>(0, 0, "white");
        unit = std::make_shared<Unit>("Unit1", 1234, field, true, WHITE);
    }

    ~UnitFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteUnit, UnitFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest){
    BOOST_TEST(unit->getColor() == WHITE);
    BOOST_TEST(unit->getField() == field);
    BOOST_TEST(unit->getUuid() == 1234);
    BOOST_TEST(unit->getName() == "Unit1");
}

    BOOST_AUTO_TEST_CASE(GetMovesTest) {
        GamePtr game = make_shared<Game>();
        game->newGame();
        int x = 1;
        int y = 1;
        vector<FieldPtr> need_moves;
        need_moves.push_back(game->getBoard()->get_field(1, 2));
        need_moves.push_back(game->getBoard()->get_field(1, 3));
        UnitPtr temp_unit =  game->getBoard()->get_field(x, y)->getOccupiedByUnit();
        BoardPtr temp = game->getBoard();
        vector<FieldPtr> returned_moves = temp_unit->getMoves(game->getBoard());
        sort(returned_moves.begin(), returned_moves.end());
        sort(need_moves.begin(), need_moves.end());

        BOOST_TEST(need_moves == returned_moves);
    }

    BOOST_AUTO_TEST_CASE(test_GetName) {
        BOOST_CHECK_EQUAL(unit->getName(), "Unit1");
    }

    BOOST_AUTO_TEST_CASE(test_SetName) {
        unit->setName("NewName");
        BOOST_CHECK_EQUAL(unit->getName(), "NewName");
    }

    BOOST_AUTO_TEST_CASE(test_GetUuid) {
        BOOST_CHECK_EQUAL(unit->getUuid(), 1234);
    }

    BOOST_AUTO_TEST_CASE(test_SetUuid) {
        unit->setUuid(5678);
        BOOST_CHECK_EQUAL(unit->getUuid(), 5678);
    }

    BOOST_AUTO_TEST_CASE(test_GetField) {
        BOOST_CHECK_EQUAL(unit->getField(), field);
    }

    BOOST_AUTO_TEST_CASE(test_SetField) {
        FieldPtr newField = std::make_shared<Field>(1, 1, "black");
        unit->setField(newField);
        BOOST_CHECK_EQUAL(unit->getField(), newField);
    }

    BOOST_AUTO_TEST_CASE(test_IsAlive) {
        BOOST_CHECK_EQUAL(unit->isAlive(), true);
    }

    BOOST_AUTO_TEST_CASE(test_SetAlive) {
        unit->setAlive(false);
        BOOST_CHECK_EQUAL(unit->isAlive(), false);
    }

    BOOST_AUTO_TEST_CASE(test_GetIcon) {
        std::string icon = unit->getIcon();
        BOOST_CHECK(icon.empty());
    }

    BOOST_AUTO_TEST_CASE(test_GetColor) {
        BOOST_CHECK_EQUAL(unit->getColor(), WHITE);
    }

    BOOST_AUTO_TEST_CASE(test_IsEnpassantable) {
        BOOST_CHECK_EQUAL(unit->isEnpassantable(), false);
    }

    BOOST_AUTO_TEST_CASE(test_SetEnpassantable) {
        unit->setEnpassantable(true);
        BOOST_CHECK_EQUAL(unit->isEnpassantable(), true);
    }

    BOOST_AUTO_TEST_CASE(test_GetUnitInfo) {
        std::string expected = "Unit1, 1234, 1, Field(0, 0)white:Not_Occupied, 0";
        std::string info = unit->getUnitInfo();
        BOOST_CHECK_EQUAL(info, expected);
    }

    BOOST_AUTO_TEST_CASE(test_GetMoves) {
        BoardPtr board = std::make_shared<Board>(8, 8, std::vector<FieldPtr>());
        std::vector<FieldPtr> moves = unit->getMoves(board);
        BOOST_CHECK(moves.empty());
    }

BOOST_AUTO_TEST_SUITE_END()
