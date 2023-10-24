//
// Created by avish on 5/29/2023.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <vector>
#include <typedefs.h>

using namespace std;


class Field;


class Board {
public:
    Board(int _x_dimension, int _y_dimension, const vector<FieldPtr> &_fields);
    Board(const Board& other);
    virtual ~Board();
    int getXDimension();
    void setXDimension(int xDimension);
    int getYDimension();
    void setYDimension(int yDimension);
    FieldPtr getField(int x_dimension, int y_dimension) const;
    vector<FieldPtr> getFieldsOccupiedByColor(Color color);

    vector<UnitPtr> getKnockedOffUnitsByColor(Color color);

private:
    int x_dimension;
    int y_dimension;
    vector<FieldPtr> fields;
public:
    const vector<FieldPtr> &getFields() const;

    void setFields(const vector<FieldPtr> &fields);
};


#endif //CHESS_BOARD_H
