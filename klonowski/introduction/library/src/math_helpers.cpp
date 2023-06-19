//
// Created by Hubert Klonowski on 07/03/2023.
//
#include "math_helpers.h"

unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;

    for(unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}