
#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H

#include <vector>
#include "string"
#include "algorithm"
#include "model/rent.h"

class RentRepository{
public:
    RentRepository(std::vector<RentPtr> &rentRepo);
    const RentPtr get(unsigned int i) const;
    void add(RentPtr rent);
    void remove(RentPtr rent);

    std::string report();
    unsigned int size();

    typedef bool (*RentPredicate)(RentPtr);

    std::vector <RentPtr> findBy(RentPredicate predicate) const;
    std::vector<RentPtr> findAll() const;
private:
    std::vector<RentPtr> rentRepo;
};
bool predR_true(RentPtr ptr);

#endif //CARRENTAL_RENTREPOSITORY_H
