#include <Unit.h>


Unit::Unit(const string &name, int uuid, const FieldPtr field, bool alive) : name(name), UUID(uuid), field(field),
                                                                             alive(alive) {}

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

const FieldPtr &Unit::getField() const {
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

