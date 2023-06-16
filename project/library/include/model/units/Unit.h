#ifndef CHESS_UNIT_H
#define CHESS_UNIT_H

#include <string>
#include <vector>
#include <typedefs.h>

using namespace std;


class Board;
class Field;

/*
 * Unit dzieli się na 6 klas dziedziczących, które na swój sposób wyliczają każdy możliwy ruch
 * i zwracają dostępne pola do posunięcia.
 * JEDNAK, unit-y nie mają odpowiedzialności sprawdzać warunki mata, szacha albo pata.
*/
class Unit {
public:

    Unit(const string &name, int uuid, const FieldPtr field, bool alive, Color color);
    Unit(std::nullptr_t);
    Color getColor() const;
    virtual vector<FieldPtr> get_moves(BoardPtr board);
    string get_unit_info() const;
    const string &getName() const;
    void setName(const string &name);
    int getUuid() const;
    void setUuid(int uuid);
    const FieldPtr getField() const;
    void setField(const FieldPtr &field);
    bool isAlive() const;
    void setAlive(bool alive);
    virtual string getIcon();

private:
    string name;
    string icon = "\n\n";
    Color color;
    int UUID; // unique unit id
    FieldPtr field;
    bool alive;

};


#endif //CHESS_UNIT_H
