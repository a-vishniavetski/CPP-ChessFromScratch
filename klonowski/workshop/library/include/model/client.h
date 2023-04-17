//
// Created by Hubert Klonowski on 21/03/2023.
//

#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
public:
    Client(std::string firstName, std::string lastName, std::string personalID);

    ~Client();
    //getters
    std::string getClientInfo() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPersonalID() const;

    //setters
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setPersonalID(std::string personalID);

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Client();
};

#endif //INTRODUCTIONPROJECT_CLIENT_HEADER_H
