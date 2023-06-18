#include <Unit.h>
#include <Field.h>
#include <Board.h>
#include <iostream>


// ---------------- Konstruktro a destruktor ----------------
Unit::Unit(const string &name, int uuid, const FieldPtr field, bool alive, Color color)
        : name(name), UUID(uuid), field(field),
          alive(alive), color(color) {

}

Unit::Unit(std::nullptr_t) {
    FieldPtr null_field = make_shared<Field>(nullptr);
    field = null_field;
}

Unit::~Unit() {}

// ---------------- GETTERS AND SETTERS ----------------
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

string Unit::getIcon() {
    return std::string();
}

Color Unit::getColor() const{
    return color;
}

bool Unit::isEnpassantable() const {
    return enpassantable;
}

void Unit::setEnpassantable(bool _enpassantable) {
    enpassantable = _enpassantable;
}

// ---------------- LOGIC ----------------
string Unit::getUnitInfo() const {
    if (this == nullptr){
        return "NULL";
    }
    string _prompt;
    _prompt.append(this->getName());
    _prompt.append(", ").append(to_string(this->getUuid()));
    _prompt.append(", ").append(to_string(this->isAlive()));
    _prompt.append(", ").append(this->getField()->getFieldInfo());
    _prompt.append(", ").append(to_string(this->getColor()));
    return _prompt;
}

vector<FieldPtr> Unit::getMoves(BoardPtr board) {
    return vector<FieldPtr>();
}








