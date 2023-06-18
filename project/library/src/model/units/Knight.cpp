//
// Created by avish on 5/29/2023.
//

#include "model/units/Knight.h"
#include "Field.h"
#include "Board.h"


string Knight::getIcon() {
    return icon;
}

Knight::Knight(const string &name, int uuid, const FieldPtr &field, bool alive, const string &icon) : Unit(name, uuid,
                                                                                                           field,
                                                                                                           alive,
                                                                                                           BLACK),
                                                                                                      icon(icon) {}

Knight::Knight(const string &name, int uuid, const FieldPtr &field, bool alive) : Unit(name, uuid, field, alive,
                                                                                       BLACK) {}

Knight::Knight(const string &name, int uuid, const FieldPtr &field, bool alive, Color color) : Unit(name, uuid, field,
                                                                                                    alive, color) {}

int Knight::checkMove(FieldPtr temp_field){
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

vector<FieldPtr> Knight::getMoves(BoardPtr board) {
    vector<FieldPtr> moves;
    int from_x = this->getField()->getXCoord();
    int from_y = this->getField()->getYCoord();
    FieldPtr temp_field;
    // wszystkie move które może zrobić knight
    int knight_moves[8][2] = {
            {2, 1},
            {1, 2},
            {-1, 2},
            {-2, 1},
            {-2, -1},
            {-1, -2},
            {1, -2},
            {2, -1}
    };

    for (int i = 0; i < 8; i++) {
        int to_x = from_x + knight_moves[i][0];
        int to_y = from_y + knight_moves[i][1];

        if (to_x >= 0 && to_x < board->getXDimension() && to_y >= 0 && to_y < board->getYDimension()) {
            temp_field = board->get_field(to_x, to_y);
            // PUSTE POLE
            if (checkMove(temp_field) == 0) {
                moves.push_back(temp_field);
            }
            // NASZ KOLOR
            else if (checkMove(temp_field) == 2) {
                continue;
            }
            // PRZECIWNIK
            else {
                moves.push_back(temp_field);
            }
        }
    }

    return moves;
}

