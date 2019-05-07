//
//  sorting.cpp
//  AlgorithmAndDataStructures
//
//  Created by John Lime on 2019/04/29.
//  Copyright © 2019 Mioto Takahashi. All rights reserved.
//

#include "sorting.hpp"

void print_comb (comb value){
    std::cout << value.index;
    if (value.oper=='s'){
        std::cout << " ";
    }
    else if (value.oper=='/'){
        std::cout << std::endl;
    }
}

Sorting::Sorting(){}

void Sorting::insertionSort(int* A, int N, comb* output){
    int output_index = 0;
    for (int i=0; i<N; i++){
        output[output_index].index = A[i];
        if (i!=N-1){
            output[output_index].oper = 's';
        }
        else{
            output[output_index].oper = '/';
        }
        output_index ++;
    }
        
    for (int i=1; i<N; i++){
        int v = A[i];
        int j = i-1;
        while (j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int k=0; k<N; k++){
            output[output_index].index = A[k];
            if (k!=N-1){
                output[output_index].oper = 's';
            }
            else{
                output[output_index].oper = '/';
            }
            output_index ++;
        }
    }
}

void Sorting::bubbleSort(int *A, int N, comb* output){
    int flag = 1;
    int i = 0;
    int count = 0;
    while (flag == 1){
        flag = 0;
        for (int j = N-1; j > i; j--){
            if (A[j] < A[j-1]){
                int tmp_a = A[j];
                int tmp_b = A[j-1];
                A[j] = tmp_b;
                A[j-1] = tmp_a;
                flag = 1;
                count++;
            }
        }
        i++;
    }
    for (int i = 0; i < N; i++){
        output[i].index = A[i];
        if (i != N-1){
            output[i].oper = 's';
        }
        else if (i == N-1){
            output[i].oper = '/';
        }
    }
    output[N].index = count;
    output[N].oper = '/';
}
