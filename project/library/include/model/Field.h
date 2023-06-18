//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_FIELD_H
#define CHESS_FIELD_H
#include <string>
#include <typedefs.h>

using namespace std;

class Unit;


class Field {
public:
    // Konstruktorzy i destruktorzy
    Field(nullptr_t);
    Field(int xCoord, int yCoord, const string &color);
    Field(int xCoord, int yCoord, bool isOccupied, const UnitPtr &occupiedByUnit, const vector<UnitPtr> &seenByUnits,
          const string &color);
    virtual ~Field();

    // x
    int getXCoord() const;
    void setXCoord(int xCoord);
    // y
    int getYCoord() const;
    void setYCoord(int yCoord);
    // occupation
    bool isOccupied() const;
    const UnitPtr &getOccupiedByUnit() const;
    void occupy(const UnitPtr unit);
    void deoccupy();
    void setOccupied(bool _occupied);
    // color
    const string &getColor() const;
    void setColor(const string &color);
    // seen by units
    const vector<UnitPtr> &getSeenByUnits() const;
    void add_seeing_unit(const UnitPtr _unit);
    void remove_seeing_unit(const int UUID);
    // print
    string get_field_info() const;



private:
    int x_coord = -1;
    int y_coord = -1;
    bool occupied = false;
    UnitPtr occupied_by_unit;
    vector<UnitPtr> seen_by_units;
    string color = "none";

};


#endif //CHESS_FIELD_H
