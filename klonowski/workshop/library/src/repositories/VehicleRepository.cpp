#include "repositories/VehicleRepository.h"

VehicleRepository::VehicleRepository( std::vector<VehiclePtr> vehicleRepo) : vehicleRepo(vehicleRepo) {}

const VehiclePtr VehicleRepository::get(unsigned int i) const {
    if(vehicleRepo.size() <= i){
        return nullptr;
    } else{
        return vehicleRepo.at(i);
    }
}

void VehicleRepository::add(VehiclePtr vehicle) {
    if(vehicle == nullptr){
        return ;
    } else{
        vehicleRepo.push_back(vehicle);
    }
}

void VehicleRepository::remove(VehiclePtr vehicle) {
    if(vehicle== nullptr){
        return ;
    } else{
        vehicleRepo.erase(std::remove(vehicleRepo.begin(),vehicleRepo.end(),vehicle),vehicleRepo.end());
    }
}

unsigned int VehicleRepository::size() {
    return vehicleRepo.size();
}

std::string VehicleRepository::report() {
    std::string report;
    for (int i = 0; i < vehicleRepo.size(); i++) {
        report+=vehicleRepo.at(i)->getVehicleInfo();
    }
    return report;
}
std::vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) const {
    std::vector<VehiclePtr> clct;
    for (unsigned int i = 0; i < vehicleRepo.size(); i++) {
        VehiclePtr vehicle= get(i);
        if (vehicle!= nullptr && predicate(vehicle)){
            clct.push_back(vehicle);
        }
    }
    return clct;
}

bool predV_true(VehiclePtr ptr) {
    return ptr->getVehicleInfo()==ptr->getVehicleInfo();
}

std::vector<VehiclePtr> VehicleRepository::findAll() const {
    return findBy(predV_true);
}