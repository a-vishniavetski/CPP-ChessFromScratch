#include <iostream>
#include <math_helpers.h>
#include <Client.h>
#include <Rent.h>

using namespace std;

int main(){
    pt::ptime empty = pt::not_a_date_time;
    pt::ptime now = pt::second_clock::local_time();

    Address* testaddress = new Address("London", "Accacia Avenue", "22");
    Vehicle* testvehicle = new Vehicle(10, "999");

    Client *c1 = new Client("Aliaksei", "Vishniavetski", "249518", testaddress);

    Rent *rent1 = new Rent(1, c1, testvehicle, now);


    //cout << c1->getClientInfo() << "\n\n";
    //cout << rent1->getRentInfo() << "\n\n";
    cout << c1->getFullClientInfo() << "\n\n";

    delete testaddress;
    delete testvehicle;
    delete c1;
    delete rent1;

    return 0;
}
