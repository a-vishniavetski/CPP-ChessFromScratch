#include "../../include/repositories/ClientRepository.h"

ClientRepository::ClientRepository(std::vector<ClientPtr> &clientRepo) : clientRepo(clientRepo) {}

ClientPtr ClientRepository::get(unsigned int i) const {
    if(clientRepo.size()<=i){
        return nullptr;
    } else{
        return clientRepo.at(i);
    }
}

void ClientRepository::add(ClientPtr client) {
    if (client == nullptr) {
        return ;
    } else {
        clientRepo.push_back(client);
    }
}

void ClientRepository::remove(ClientPtr client) {
    if(client == nullptr){
        return ;
    } else{
        clientRepo.erase(std::remove(clientRepo.begin(),clientRepo.end(),client),clientRepo.end());
    }
}

unsigned int ClientRepository::size() {
    return clientRepo.size();
}

std::string ClientRepository::report() {
    std::string report;
    for (int i = 0; i < clientRepo.size(); i++) {
        report += clientRepo.at(i)->getClientInfo();
    }
    return report;
}
bool predC_true(ClientPtr ptr) {
    return ptr->getClientInfo() == ptr->getClientInfo();
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    std::vector<ClientPtr> clct;
    for (unsigned int i = 0; i < clientRepo.size(); i++) {
        ClientPtr client= get(i);
        if (client != nullptr && predicate(client)){
            clct.push_back(client);
        }
    }
    return clct;
}

std::vector<ClientPtr> ClientRepository::findAll() const {
    return findBy(predC_true);
}

