#include "exceptions.h"

NoUnitFoundException::NoUnitFoundException(const std::string &arg) : logic_error(arg) {}

SaveFailedException::SaveFailedException(const std::string &arg) : logic_error(arg) {}

LoadFailedException::LoadFailedException(const std::string &arg) : logic_error(arg) {}
