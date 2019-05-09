//
// Created by yusuke on 2019/05/01.
//

#include "longest_increasing_subsequence.h"
#include<iostream>
#include<algorithm>

#define MAX 100000
using namespace std;

int n, A[MAX+1], L[MAX], P[MAX];
int k;

int lis(){
    L[0] = A[0];
    int length = 1;

    for(int i = 1; i < n; i++){
        if(L[length - 1] < A[i]){
            L[length++] = A[i];
        }else{
            // L[length - 1]がA[i]より大きかったらL[length]をA[i]に
            *lower_bound(L, L + length, A[i]) = A[i];
        }
    }
    return length;
}


int lis_test(int num){
    L[0] = 0;
    A[0] = 0;
    P[0] = -1;
    for(int i = 1; i < n; i++){
        k = 0;
        for(int j = 0; j < i - 1; j++){
            if(A[j] < A[i] && L[j] < L[k]){
                k = j;
            }
        }
        L[i] = L[k] + 1;
        P[i] = k;
        cout << L[i] << endl;
    }
    return L[num - 2];
}


void lis_main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << lis() << endl;
    // cout << lis_test(n) << endl;
}

//{5, 1, 3, 2, 4}

// {5}
// {1}
// {1, 3}
// {1, 2}
// {1, 2, 4}

//3

// {5, 1, 3, 1, 4}

// {5}
// {1}
// {1, 3}
// {}