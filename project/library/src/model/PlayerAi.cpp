#include "PlayerAi.h"
#include <Unit.h>
#include <cstdlib>



PlayerAi::PlayerAi(const string &name, int upid, Color color) : Player(name, upid, color) {}
PlayerAi::~PlayerAi() {}

void PlayerAi::chooseUnitField(FieldPtr field) {
    return;
}

FieldPtr PlayerAi::getSelectedField() {
    return nullptr;
}

void PlayerAi::unsetUnit() {
    return;
}

UnitPtr PlayerAi::chooseUnit(BoardPtr board) {
    try {
        srand(time(0));
        int units_size = getUnits().size();
        int index = 0;
        int count = 0;
        UnitPtr temp_unit;
        while (count <= 40){
            index = rand() % units_size;
            temp_unit = getUnits()[index];
            if (temp_unit->isAlive()){
                return temp_unit;
            }
            count++;
        }
        // count > 40
        throw std::logic_error("PlayerAI: Choosing random for too long");
    }
    catch (...){
        cout << "PlayerAI::chooseUnit: too many attempts to choose a random unit have failed";
        exit(1);
    }
}

FieldPtr PlayerAi::chooseMove(const vector<FieldPtr> &fields) {
    srand(time(0));
    int fields_size = fields.size();
    int index = 0;
    FieldPtr random_field;
    index = rand() % fields_size;
    random_field = fields[index];
    return random_field;
}

