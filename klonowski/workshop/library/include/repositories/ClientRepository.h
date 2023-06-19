
#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

#include <vector>
#include <string>
#include <algorithm>
#include "model/client.h"

class ClientRepository{
public:
    ClientRepository(std::vector<ClientPtr> &clientRepo);
    ClientPtr get(unsigned int i) const;

    void add(ClientPtr client);
    void remove(ClientPtr client);

    std::string report();
    unsigned int size();

    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;
    std::vector<ClientPtr> findAll() const;

private:
    std::vector<ClientPtr> clientRepo;
};
bool predC_true(ClientPtr ptr);


#endif //CARRENTAL_CLIENTREPOSITORY_H
