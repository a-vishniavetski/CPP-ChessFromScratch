#include <Unit.h>
#include <Field.h>
#include <Board.h>
#include <iostream>

Unit::Unit(const string &name, int uuid, const FieldPtr field, bool alive, Color color)
        : name(name), UUID(uuid), field(field),
          alive(alive), color(color) {

}

const string &Unit::getName() const {
    return name;
}

void Unit::setName(const string &name) {
    Unit::name = name;
}

int Unit::getUuid() const {
    return UUID;
}

void Unit::setUuid(int uuid) {
    UUID = uuid;
}

const FieldPtr Unit::getField() const {
    return field;
}

void Unit::setField(const FieldPtr &field) {
    Unit::field = field;
}

bool Unit::isAlive() const {
    return alive;
}

void Unit::setAlive(bool alive) {
    Unit::alive = alive;
}

vector<FieldPtr> Unit::get_moves(BoardPtr board) {
    vector<FieldPtr> possible_moves;
    int unit_x = getField()->getXCoord();
    int unit_y = getField()->getYCoord();
    FieldPtr temp_field;
    if (getColor() == WHITE){
        temp_field = board->get_field(unit_x, unit_y + 1);
        possible_moves.push_back(temp_field);
        temp_field = board->get_field(unit_x, unit_y + 2);
        possible_moves.push_back(temp_field);
    }
    else{
        board->get_field(unit_x, unit_y - 1);
        possible_moves.push_back(temp_field);
        temp_field = board->get_field(unit_x, unit_y - 2);
        possible_moves.push_back(temp_field);
    }
    //std::cout << "Inside the get_moves";
    return possible_moves;
}

Unit::Unit(std::nullptr_t) {
    FieldPtr null_field = make_shared<Field>(nullptr);
    field = null_field;
}

string Unit::get_unit_info() const {
    if (this == nullptr){
        return "NULL";
    }
    string _prompt;
    _prompt.append(this->getName());
    _prompt.append(", ").append(to_string(this->getUuid()));
    _prompt.append(", ").append(to_string(this->isAlive()));
    _prompt.append(", ").append(this->getField()->get_field_info());
    _prompt.append(", ").append(to_string(this->getColor()));
    return _prompt;
}

string Unit::getIcon() {
    return std::string();
}

Color Unit::getColor() const{
    return color;
}


