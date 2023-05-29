//
// Created by Hubert Klonowski on 14/05/2023.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H


#include <vector>
#include "string"
#include "algorithm"
#include "model/Vehicle.h"

class VehicleRepository {

public:
    VehicleRepository(std::vector<VehiclePtr> vehicleRepo);

    const VehiclePtr get(unsigned int i) const;
    void add(VehiclePtr vehicle);
    void remove(VehiclePtr vehicle);

    std::string report();
    unsigned int size();

    typedef bool (*VehiclePredicate)(VehiclePtr);

    std::vector <VehiclePtr> findBy(VehiclePredicate predicate) const;
    std::vector<VehiclePtr> findAll() const;

private:
    std::vector<VehiclePtr> vehicleRepo;
};
bool predV_true(VehiclePtr ptr);

#endif //CARRENTAL_VEHICLEREPOSITORY_H
