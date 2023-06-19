//
// Created by student on 18.06.23.
//

#ifndef CHESS_EXCEPTIONS_H
#define CHESS_EXCEPTIONS_H
#include <stdexcept>

class NoUnitFoundException : public std::logic_error {
public:
    explicit NoUnitFoundException(const std::string &arg);

};

class SaveFailedException : public std::logic_error {
public:
    explicit SaveFailedException(const std::string &arg);

};

class LoadFailedException : public std::logic_error {
public:
    explicit LoadFailedException(const std::string &arg);

};
#endif //CHESS_EXCEPTIONS_H
