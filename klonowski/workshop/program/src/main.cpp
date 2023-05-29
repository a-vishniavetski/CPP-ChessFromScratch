//
// Created by Hubert Klonowski on 07/03/2023.
//
#include <iostream>
#include "model/client.h"
#include "model/Vehicle.h"
#include "model/car.h"
#include "repositories/StorageContainer.h"
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"

using namespace std;

int main()
{
    StorageContainer sc;

    ClientRepository clientRepo(sc.getClientRepo());
    VehicleRepository vehicleRepo(sc.getVehicleRepo());
    RentRepository rentRepo(sc.getRentRepo());

    cout << clientRepo.report() << endl;
    cout << vehicleRepo.report() << endl;
    cout << rentRepo.report() << endl;

    VehiclePtr car = new Car("ABCD123",1,99,D);
    AddressPtr address = new Address("Zgorzelec","Fiolkowa","1");
    std::vector<RentPtr> rents;

    pt::ptime date = pt::ptime(boost::gregorian::date(2022,4,18) );

    ClientPtr client = new Client("Gregorij","Nieswiatow","1231231231231",address,rents);

    RentPtr rent = new Rent(1, car, client, true, date);

    rents.push_back(rent);

    clientRepo.add(client);
    vehicleRepo.add(car);
    rentRepo.add(rent);

    std::cout <<  "-----***-----" << endl;

    std::cout << clientRepo.report() << endl;
    std::cout << vehicleRepo.report() << endl;
    std::cout << rentRepo.report() << endl;
    return 0;
}