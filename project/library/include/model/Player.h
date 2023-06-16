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

    Player(const string &name, int upid, Color color);

    virtual ~Player();

    string get_all_units_info() const;
    const string &getName() const;
    void setName(const string &name);
    int getUpid() const;
    void setUpid(int upid);
    const vector<UnitPtr> &getUnits() const;
    void setUnits(const vector<UnitPtr> &units);
    void addUnit(UnitPtr unit);
    UnitPtr choose_unit();

    Color getColor() const;

private:
    string name;
    int UPID;  // unique player ID
    vector<UnitPtr> units;
    Color color;

};


#endif //CHESS_PLAYER_H
