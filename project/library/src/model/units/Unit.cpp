#include <Unit.h>


Unit::Unit(const string &name, int uuid, const FieldPtr &field, bool alive) : name(name), UUID(uuid), field(field),
                                                                              alive(alive) {}

