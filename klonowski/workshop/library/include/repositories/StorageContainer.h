//
// Created by Hubert Klonowski on 14/05/2023.
//

#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H

#include "ClientRepository.h"
#include "RentRepository.h"
#include "VehicleRepository.h"

class StorageContainer {
public:
    StorageContainer();
    std::vector<ClientPtr> &getClientRepo();
    std::vector<VehiclePtr> &getVehicleRepo();
    std::vector<RentPtr> &getRentRepo();

private:
    std::vector<ClientPtr> clientRepo;
    std::vector<RentPtr> rentRepo;
    std::vector<VehiclePtr> vehicleRepo;
};


#endif //CARRENTAL_STORAGECONTAINER_H
