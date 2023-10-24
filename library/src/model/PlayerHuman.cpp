#include "PlayerHuman.h"
#include "Field.h"
#include "Unit.h"

PlayerHuman::PlayerHuman(const string &name, int upid, Color color) : Player(name, upid, color) {}

PlayerHuman::~PlayerHuman() {

}

// nie muszę być wywoływane w ogóle
FieldPtr PlayerHuman::chooseMove(const vector<FieldPtr> &fields) {
    return FieldPtr();
}

UnitPtr PlayerHuman::chooseUnit(BoardPtr board) {
    return UnitPtr();
}

void PlayerHuman::chooseUnitField(FieldPtr field) {
    this->selected_field = field;
    try{
        this->selected_unit = field->getOccupiedByUnit();
    }
    catch (logic_error)
    {
        cout << "Could not find unit";
    }
}

void PlayerHuman::unsetUnit() {
    selected_field = nullptr;
    selected_unit = nullptr;
}

FieldPtr PlayerHuman::getSelectedField() {
    return selected_field;
}

