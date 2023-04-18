#include <iostream>
#include <math_helpers.h>
#include <Client.h>
#include <Rent.h>

using namespace std;

int main(){
    Address* testaddress = new Address("London", "Accacia Avenue", "22");
    Vehicle* testvehicle = new Vehicle(10, "999");

    Client *c1 = new Client("Aliaksei", "Vishniavetski", "249518", testaddress);

    Rent *rent1 = new Rent(1, c1, testvehicle);


    //cout << c1->getClientInfo() << "\n\n";
    //cout << rent1->getRentInfo() << "\n\n";
    cout << c1->getFullClientInfo() << "\n\n";

    delete testaddress;
    delete testvehicle;
    delete c1;
    delete rent1;

    return 0;
}
