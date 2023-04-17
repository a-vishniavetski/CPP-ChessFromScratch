#include <iostream>
#include <math_helpers.h>
#include <Client.h>

using namespace std;

int main(){
    Address* testaddress = new Address("London", "Accacia Avenue", "22");

    Client c1 = Client("Aliaksei", "Vishniavetski", "249518", testaddress);
    Client* c2 = new Client("Ktos", "Inny", "000000", testaddress);

    cout << c1.getClientInfo() << "\n";
    cout << c2->getClientInfo() << "\n";

    Address* testaddress2 = new Address("Not London", "Not Accacia Avenue", "Not 22");

    c2->setAddress(testaddress2);

    cout << c1.getClientInfo() << "\n";
    cout << c2->getClientInfo() << "\n";

    delete c2;

    return 0;
}
