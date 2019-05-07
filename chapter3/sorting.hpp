//
//  sorting.hpp
//  AlgorithmAndDataStructures
//
//  Created by John Lime on 2019/04/29.
//  Copyright © 2019 Mioto Takahashi. All rights reserved.
//

#ifndef sorting_hpp
#define sorting_hpp

#include <stdio.h>
#include <iostream>

struct comb {
    int index;
    char oper;
};

void print_comb (comb value);

class Sorting {
public:
    Sorting();
    void insertionSort(int* A, int N, comb* output);
    void bubbleSort(int *A, int N, comb* output);
};
#endif /* sorting_hpp */
