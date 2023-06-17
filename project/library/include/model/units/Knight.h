//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Unit.h"

class Knight : public Unit {
public:
    Knight(const string &name, int uuid, const FieldPtr &field, bool alive, const string &icon);
    Knight(const string &name, int uuid, const FieldPtr &field, bool alive);
    Knight(const string &name, int uuid, const FieldPtr &field, bool alive, Color color);
    string getIcon() override;
    vector<FieldPtr> get_moves(BoardPtr board);

private:
    string icon = "♞";
    int checkMove(FieldPtr temp_field);
};


#endif //CHESS_KNIGHT_H
