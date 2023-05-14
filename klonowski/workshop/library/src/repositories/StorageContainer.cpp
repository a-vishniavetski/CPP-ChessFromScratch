//
// Created by Hubert Klonowski on 14/05/2023.
//
#include "repositories/StorageContainer.h"
#include "model/car.h"

StorageContainer::StorageContainer() {
    unsigned int id1 = 1;
    unsigned int id2 = 11;
    unsigned int id3 = 2;

    pt::ptime date1 = pt::ptime(boost::gregorian::date(2023,1,1) );
    pt::ptime date2 = pt::ptime(boost::gregorian::date(2023,2,2) );
    pt::ptime end=pt::ptime(boost::gregorian::date(2023,3,3), pt::hours(24)) ;

    std::vector<RentPtr> rents1;
    std::vector<RentPtr> rents2;

    AddressPtr address1 = new Address("Brodnica", "Paderewskiego", "1");

    AddressPtr address2 = new Address("Warszawa","Dowcip","3A");

    VehiclePtr renata = new Car("CBR6XD9", 50, 2, A);

    VehiclePtr skoda = new Car("WZ42069",30, 5, B);

    this->vehicleRepo.push_back(renata);
    this->vehicleRepo.push_back(skoda);

    ClientPtr client1 = new Client("Hubert", "Konieczny", "123123123", address1, rents1);
    ClientPtr client2 = new Client("Oliwia", "Brazylia","123321321", address2, rents2);
    client1->setFirstName("Hubert");
    RentPtr rent1 = new Rent(id1, renata, client1, true, date1);
    RentPtr rent2 = new Rent(id2, skoda, client2, true, end);
    RentPtr rent3 = new Rent(id3, skoda, client2, true, date2);
    rent1->endRent(end);

    this->clientRepo.push_back(client1);
    this->clientRepo.push_back(client2);

    this->rentRepo.push_back(rent1);
    this->rentRepo.push_back(rent2);
    this->rentRepo.push_back(rent3);

}

std::vector<ClientPtr> &StorageContainer::getClientRepo()  {
    return clientRepo;
}

std::vector<RentPtr> &StorageContainer::getRentRepo()  {
    return rentRepo;
}

std::vector<VehiclePtr> &StorageContainer::getVehicleRepo() {
    return vehicleRepo;
}
