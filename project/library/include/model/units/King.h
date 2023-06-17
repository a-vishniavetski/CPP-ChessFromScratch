//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Unit.h"


class King : public Unit {
public:
    King(const string &name, int uuid, const FieldPtr &field, bool alive);
    King(const string &name, int uuid, const FieldPtr &field, bool alive, Color color);
    string getIcon() override;
    vector<FieldPtr> get_moves(BoardPtr board);
    int checkMove(FieldPtr temp_field);

private:
    string icon = "♚";
};


#endif //CHESS_KING_H
