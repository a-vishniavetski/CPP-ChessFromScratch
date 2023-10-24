//
// Created by avish on 5/29/2023.
//

#include "model/units/Pawn.h"
#include "Field.h"
#include "Board.h"
#include <stdexcept>

string Pawn::getIcon() {
    return icon;
}

Pawn::Pawn(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                alive, color) {}

vector<FieldPtr> Pawn::getMoves(BoardPtr board) {
    vector<FieldPtr> moves;
    int from_x = this->getField()->getXCoord();
    int from_y = this->getField()->getYCoord();
    int to_x = 0;
    int to_y = 0;

    // WHITE
    if (this->getColor() == WHITE){
        // NORMAL MOVE
        to_x = from_x;
        to_y = from_y + 1;
        if (to_y < board->getYDimension()) { // to_y <= 7
            // If not occupied, can move
            if (!board->getField(to_x, to_y)->isOccupied()){
                moves.push_back(board->getField(to_x, to_y));
            }
        }
        // DOUBLE MOVE
        if (from_y == 1){
            to_x = from_x;
            to_y = from_y + 2;
            if (to_y < board->getYDimension()) { // to_y <= 7
                // If path not obstructed, can move
                if (!board->getField(to_x, to_y)->isOccupied() && !board->getField(to_x, to_y - 1)->isOccupied()){
                    moves.push_back(board->getField(to_x, to_y));
                }
            }
        }
        // BICIE
        // LEFT
        to_x = from_x - 1;
        to_y = from_y + 1;
        if(to_y >= 0 && to_y < board->getYDimension() && to_x >= 0 && to_x < board->getXDimension())
        {
            if(board->getField(to_x, to_y)->isOccupied())
            {
                if(board->getField(to_x, to_y)->getOccupiedByUnit()->getColor() != this->getColor())
                    moves.push_back(board->getField(to_x, to_y));
            }
        }
        // RIGHT
        to_x = from_x + 1;
        to_y = from_y + 1;
        if(to_y >= 0 && to_y < board->getYDimension() && to_x >= 0 && to_x < board->getXDimension())
        {
            if(board->getField(to_x, to_y)->isOccupied())
            {
                if(board->getField(to_x, to_y)->getOccupiedByUnit()->getColor() != this->getColor())
                    moves.push_back(board->getField(to_x, to_y));
            }
        }
        // BICIE NA PRZELOCIE (EN PASSANT)
        if(from_y == 4)
        {
            // LEFT
            to_x = from_x - 1;
            to_y = from_y + 1;
            if(to_x > 0 && !board->getField(to_x, to_y)->isOccupied())
            {
                if(board->getField(to_x, from_y)->isOccupied())
                {
                    UnitPtr possible_capture = board->getField(to_x, from_y)->getOccupiedByUnit();
                    if(possible_capture->getName() == "Pawn" && possible_capture->getColor() != this->getColor() && possible_capture->isEnpassantable()){
                        moves.push_back(board->getField(to_x, to_y));
                    }
                }
            }
            // RIGHT
            to_x = from_x + 1;
            to_y = from_y + 1;
            if(to_x < board->getXDimension() && !board->getField(to_x, to_y)->isOccupied())
            {
                if(board->getField(to_x, from_y)->isOccupied())
                {
                    UnitPtr possible_capture = board->getField(to_x, from_y)->getOccupiedByUnit();
                    if(possible_capture->getName() == "Pawn" && (possible_capture->getColor() != this->getColor()) && possible_capture->isEnpassantable()){
                        moves.push_back(board->getField(to_x, to_y));
                    }
                }
            }

        }
    }
    // BLACK
    else if(getColor() == BLACK){
        // NORMAL MOVE
        to_x = from_x;
        to_y = from_y - 1;
        if (to_y >= 0) {
            // If not occupied, can move
            if (!board->getField(to_x, to_y)->isOccupied()){
                moves.push_back(board->getField(to_x, to_y));
            }
        }
        // DOUBLE MOVE
        if (from_y == 6){
            to_x = from_x;
            to_y = from_y - 2;
            if (to_y >= 0) {
                // If not occupied, can move
                if (!board->getField(to_x, to_y)->isOccupied() && !board->getField(to_x, to_y + 1)->isOccupied()){
                    moves.push_back(board->getField(to_x, to_y));
                }
            }
        }
        // BICIE
        // LEFT
        to_x = from_x + 1;
        to_y = from_y - 1;
        if(to_y >= 0 && to_y < board->getYDimension() && to_x >= 0 && to_x < board->getXDimension())
        {
            if(board->getField(to_x, to_y)->isOccupied())
            {
                if(board->getField(to_x, to_y)->getOccupiedByUnit()->getColor() != this->getColor())
                    moves.push_back(board->getField(to_x, to_y));
            }
        }
        // RIGHT
        to_x = from_x - 1;
        to_y = from_y - 1;
        if(to_y >= 0 && to_y < board->getYDimension() && to_x >= 0 && to_x < board->getXDimension())
        {
            if(board->getField(to_x, to_y)->isOccupied())
            {
                if(board->getField(to_x, to_y)->getOccupiedByUnit()->getColor() != this->getColor()) {
                    moves.push_back(board->getField(to_x, to_y));
                }
            }
        }
        // BICE NA PRZELOCIE (EN PASSANT)
        if(from_y == 3)
        {
            // LEFT
            to_x = from_x + 1;
            to_y = from_y - 1;
            if(to_x < board->getXDimension() && !board->getField(to_x, to_y)->isOccupied())
            {
                if(board->getField(to_x, from_y)->isOccupied())
                {
                    UnitPtr possible_capture = board->getField(to_x, from_y)->getOccupiedByUnit();
                    if(possible_capture->getName() == "Pawn" && possible_capture->getColor() != this->getColor() && possible_capture->isEnpassantable()){
                        moves.push_back(board->getField(to_x, to_y));
                    }
                }
            }
            // RIGHT
            to_x = from_x - 1;
            to_y = from_y - 1;
            if(to_x > 0 && !board->getField(to_x, to_y)->isOccupied())
            {
                if(board->getField(to_x, from_y)->isOccupied())
                {
                    UnitPtr possible_capture = board->getField(to_x, from_y)->getOccupiedByUnit();
                    if(possible_capture->getName() == "Pawn" && (possible_capture->getColor() != this->getColor()) && possible_capture->isEnpassantable()){
                        moves.push_back(board->getField(to_x, to_y));
                    }
                }
            }
        }
    }
    else {
        throw std::logic_error("No color");
    }

    return moves;
}
