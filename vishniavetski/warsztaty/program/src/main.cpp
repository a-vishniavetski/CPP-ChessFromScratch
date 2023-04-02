#include <iostream>
#include <math_helpers.h>
#include <Client.h>

using namespace std;

int main(){
    Client c1 = Client("Aliaksei", "Vishniavetski", "249518");
    Client* c2 = new Client("Ktos", "Inny", "000000");

    cout << c1.getClientInfo() << "\n";
    cout << c2->getClientInfo() << "\n";

    delete c2;

    return 0;
}
