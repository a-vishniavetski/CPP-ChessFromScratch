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

enum PlayerType {
    AI,
    HUMAN
};

class Player {
public:
    // Konstruktor i destruktor
    Player(const string &name, int upid, const vector<UnitPtr> &units);
    Player(const string &name, int upid, Color color);
    virtual ~Player();

    PlayerType getPlayerType() const;
    string getAllUnitsInfo() const;
    const string &getName() const;
    void setName(const string &name);
    int getUpid() const;
    void setUpid(int upid);
    const vector<UnitPtr> &getUnits() const;
    void setUnits(const vector<UnitPtr> &units);
    void addUnit(UnitPtr unit);
    virtual UnitPtr chooseUnit(BoardPtr board)=0;
    virtual FieldPtr chooseMove(const vector<FieldPtr> &fields)=0;
    Color getColor() const;

private:
    string name;
    int UPID;  // unique player ID
    vector<UnitPtr> units;
    Color color;
    PlayerType player_type;
};


#endif //CHESS_PLAYER_H
