//
// Created by Hubert Klonowski on 14/05/2023.
//


#include "repositories/RentRepository.h"
RentRepository::RentRepository(std::vector<RentPtr> &rentRepo) : rentRepo(rentRepo) {}

const RentPtr RentRepository::get(unsigned int i) const {
    if(rentRepo.size() <= i){
        return nullptr;
    } else{
        return rentRepo.at(i);
    }
}

void RentRepository::add(RentPtr rent) {
    if(rent == nullptr){
        return ;
    } else{
        rentRepo.push_back(rent);
    }
}

void RentRepository::remove(RentPtr rent) {
    if(rent == nullptr){
        return ;
    } else{
        rentRepo.erase(std::remove(rentRepo.begin(),rentRepo.end(),rent),rentRepo.end());
    }
}

unsigned int RentRepository::size() {
    return rentRepo.size();
}

std::string RentRepository::report() {
    std::string report;
    for (int i = 0; i < rentRepo.size(); i++) {
        report += rentRepo.at(i)->getRentInfo();
    }
    return report;
}
std::vector<RentPtr> RentRepository::findBy(RentPredicate predicate) const {
    std::vector<RentPtr> clct;
    for (unsigned int i = 0; i < rentRepo.size(); i++) {
        RentPtr rent= get(i);
        if (rent!= nullptr && predicate(rent)){
            clct.push_back(rent);
        }
    }
    return clct;
}

bool predR_true(RentPtr ptr) {
    return ptr->getRentInfo() == ptr->getRentInfo();
}

std::vector<RentPtr> RentRepository::findAll() const {
    return findBy(predR_true);
}