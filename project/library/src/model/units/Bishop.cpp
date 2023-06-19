//
// Created by avish on 5/29/2023.
//

#include "model/units/Bishop.h"
#include "Board.h"
#include "Field.h"

string Bishop::getIcon() {
    return icon;
}

Bishop::Bishop(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive,
                                                                                       BLACK) {}

Bishop::Bishop(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                    alive, color) {}

int Bishop::checkMove(FieldPtr temp_field){
    // Zwróć 0 jeśli pole jest puste, 1 jeśli zajęte przeciwnikiem, 2 jeśli własną jednostką

    // PUSTE POLE
    if(!temp_field->isOccupied())
    {
        return 0;
    }
        // NIE PUSTE POLE
    else {
        // NASZ COLOR
        if (temp_field->getOccupiedByUnit()->getColor() == this->getColor()){
            return 2;
        }
            // NIE NASZ KOLOR
        else{
            return 1;
        }
    }
}

vector<FieldPtr> Bishop::getMoves(BoardPtr board) {
    vector<FieldPtr> moves;
    int from_x = this->getField()->getXCoord();
    int from_y = this->getField()->getYCoord();
    int to_x = 0;
    int to_y = 0;
    FieldPtr temp_field;

    // UP-RIGHT DIAGONAL
    to_x = from_x + 1;
    to_y = from_y + 1;
    while (to_x < board->getXDimension() && to_y < board->getYDimension()) {
        temp_field = board->getField(to_x, to_y);
        // PUSTE POLE
        if (checkMove(temp_field) == 0) {
            moves.push_back(temp_field);
        }
            // NASZ KOLOR
        else if (checkMove(temp_field) == 2) {
            break;
        }
            // PRZECIWNIK
        else {
            moves.push_back(temp_field);
            break;
        }

        to_x += 1;
        to_y += 1;
    }

    // UP-LEFT DIAGONAL
    to_x = from_x - 1;
    to_y = from_y + 1;
    while (to_x >= 0 && to_y < board->getYDimension()) {
        temp_field = board->getField(to_x, to_y);
        // PUSTE POLE
        if (checkMove(temp_field) == 0) {
            moves.push_back(temp_field);
        }
            // NASZ KOLOR
        else if (checkMove(temp_field) == 2) {
            break;
        }
            // PRZECIWNIK
        else {
            moves.push_back(temp_field);
            break;
        }

        to_x -= 1;
        to_y += 1;
    }

    // DOWN-RIGHT DIAGONAL
    to_x = from_x + 1;
    to_y = from_y - 1;
    while (to_x < board->getXDimension() && to_y >= 0) {
        temp_field = board->getField(to_x, to_y);
        // PUSTE POLE
        if (checkMove(temp_field) == 0) {
            moves.push_back(temp_field);
        }
            // NASZ KOLOR
        else if (checkMove(temp_field) == 2) {
            break;
        }
            // PRZECIWNIK
        else {
            moves.push_back(temp_field);
            break;
        }

        to_x += 1;
        to_y -= 1;
    }

    // DOWN-LEFT DIAGONAL
    to_x = from_x - 1;
    to_y = from_y - 1;
    while (to_x >= 0 && to_y >= 0) {
        temp_field = board->getField(to_x, to_y);
        // PUSTE POLE
        if (checkMove(temp_field) == 0) {
            moves.push_back(temp_field);
        }
            // NASZ KOLOR
        else if (checkMove(temp_field) == 2) {
            break;
        }
            // PRZECIWNIK
        else {
            moves.push_back(temp_field);
            break;
        }

        to_x -= 1;
        to_y -= 1;
    }

    return moves;
}
