#include <iostream>
#include <stdio.h>
#include <vector>
#include "ex2_2.h"
#include "ex2_5.h"


int main() {
    // ex2_2
    std::vector<int> array{25, 36, 4, 55, 71, 18, 0, 71, 89, 65};
    printf("%s", "algorithm1\n");
    for(int i = 0; i < algorithm1(array).size(); i++){
        std::cout << algorithm1(array)[i] << "\n";
    }

    printf("%s", "\nalgorithm2\n");
    for(int i = 0; i < algorithm2(array).size(); i++){
        std::cout << algorithm2(array)[i] << "\n";
    }

    printf("%s", "\nalgorithm3\n");
    for(int i = 0; i < algorithm3(array).size(); i++){
        std::cout << algorithm3(array)[i] << "\n";
    }

    printf("%s", "\n");

    // ex2_5
    maximum_profit();

    return 0;
}