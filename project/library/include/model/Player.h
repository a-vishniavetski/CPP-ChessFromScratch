//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H
#include <string>
#include <vector>
#include <typedefs.h>


using namespace std;

class Unit;

class Player {
public:
    // Konstruktor i destruktor
    Player(const string &name, int upid, const vector<UnitPtr> &units);

    virtual ~Player();

private:
    string name;
    int UPID;  // unique player ID
    vector<UnitPtr> units;

};


#endif //CHESS_PLAYER_H
