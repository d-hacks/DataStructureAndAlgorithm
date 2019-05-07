//
//  main.cpp
//  AlgorithmAndDataStructures
//
//  Created by John Lime on 2019/04/29.
//  Copyright © 2019 Mioto Takahashi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "sorting.hpp"

/* Sorting Algorithms */

int main(int argc, const char * argv[]) {
    Sorting sort = Sorting();
    int N;
    std::cin >> N;
    int A [N];
    int insertA [N];
    int bubbleA [N];
    for (int i=0; i<N; i++){
        std::cin >> A[i];
        insertA[i] = A[i];
        bubbleA[i] = A[i];
    }

    comb insert_out [N*N];
    sort.insertionSort(insertA, N, insert_out);

    comb bubble_out [N+1];
    sort.bubbleSort(bubbleA, N, bubble_out);

    std::cout << "Insert Sort" << std::endl;
    for (int i=0; i<N*N; i++){
        print_comb(insert_out[i]);
    }

    std::cout << "Bubble Sort" << std::endl;
    for (int i=0; i<N+1; i++){
        print_comb(bubble_out[i]);
    }
    return 0;
}
