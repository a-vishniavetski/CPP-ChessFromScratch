#include <boost/test/unit_test.hpp>
#include <typedefs.h>
#include <exceptions.h>
#include "Game.h"
#include "Field.h"
#include "Unit.h"

struct BoardFixture {
    BoardPtr board;
    std::vector<FieldPtr> fields;

    BoardFixture() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                fields.push_back(std::make_shared<Field>(i, j, "white"));
            }
        }
        board = std::make_shared<Board>(8, 8, fields);
    }

    ~BoardFixture() {}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBoard, BoardFixture)

    BOOST_AUTO_TEST_CASE(test_GetXDimension) {
        BOOST_CHECK_EQUAL(board->getXDimension(), 8);
    }

    BOOST_AUTO_TEST_CASE(test_SetXDimension) {
        board->setXDimension(10);
        BOOST_CHECK_EQUAL(board->getXDimension(), 10);
    }

    BOOST_AUTO_TEST_CASE(test_GetYDimension) {
        BOOST_CHECK_EQUAL(board->getYDimension(), 8);
    }

    BOOST_AUTO_TEST_CASE(test_SetYDimension) {
        board->setYDimension(10);
        BOOST_CHECK_EQUAL(board->getYDimension(), 10);
    }

    BOOST_AUTO_TEST_CASE(test_GetField) {
        FieldPtr field = board->getField(0, 0);
        BOOST_CHECK_EQUAL(field->getXCoord(), 0);
        BOOST_CHECK_EQUAL(field->getYCoord(), 0);
    }

    BOOST_AUTO_TEST_CASE(test_GetFields) {
        const std::vector<FieldPtr>& boardFields = board->getFields();
        BOOST_CHECK_EQUAL(boardFields.size(), 64);
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                BOOST_CHECK_EQUAL(boardFields[i * 8 + j]->getXCoord(), i);
                BOOST_CHECK_EQUAL(boardFields[i * 8 + j]->getYCoord(), j);
            }
        }
    }

    BOOST_AUTO_TEST_CASE(test_SetFields) {
        std::vector<FieldPtr> newFields;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                newFields.push_back(std::make_shared<Field>(i, j, "black"));
            }
        }
        board->setFields(newFields);

        const std::vector<FieldPtr>& boardFields = board->getFields();
        BOOST_CHECK_EQUAL(boardFields.size(), 64);
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                BOOST_CHECK_EQUAL(boardFields[i * 8 + j]->getXCoord(), i);
                BOOST_CHECK_EQUAL(boardFields[i * 8 + j]->getYCoord(), j);
                BOOST_CHECK_EQUAL(boardFields[i * 8 + j]->getColor(), "black");
            }
        }
    }

BOOST_AUTO_TEST_SUITE_END()