//
// Created by Hubert Klonowski on 07/03/2023.
//
#include <iostream>
#include <math_helpers.h>
#include <model/client.h>

using namespace std;

int main()
{
    Client client1("Marek", "Kowalski", "12312312300");
    cout << client1.getClientInfo() << endl;

    Client* client2 = new Client("Jan", "Brzechwa", "23423424300");
    cout << client2->getClientInfo() << endl;

    client2->setLastName("Tuwim");
//    delete &client1;
    delete client2;
    return 0;
}