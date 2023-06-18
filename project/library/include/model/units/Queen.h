//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include <typedefs.h>
#include "Unit.h"

using namespace std;



class Queen : public Unit {
public:


    Queen(const string &name, int uuid, const FieldPtr &field, bool alive);
    Queen(const string &name, int uuid, const FieldPtr &field, bool alive, Color color);
    string getIcon() override;
    vector<FieldPtr> getMoves(BoardPtr board) override;
private:
    string icon = "♛";
};


#endif //CHESS_QUEEN_H
