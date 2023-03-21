//
// Created by Hubert Klonowski on 21/03/2023.
//
#include <iostream>
using namespace std;
class Client{
    Client()
    {
        cout << "Konstruktor Client wywołany";
    }

    ~Client()
    {
        cout << "Destruktor Client wywołany";
    }
};