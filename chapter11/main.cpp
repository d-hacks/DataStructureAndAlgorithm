//
//  main.cpp
//  AlgorithmAndDataStructures
//
//  Created by John Lime on 2019/04/29.
//  Copyright © 2019 Mioto Takahashi. All rights reserved.
//

#include <iostream>
#include <algorithm>

/* MatrixChainMultiplication Dynamic Programming */
int main(int argc, const char * argv[]) {
    int N = 100;
    int n;
    int p[N+1];
    int m[N+1][N+1];
    std::cin >> n;
    for(int i=1; i<=n; i++){
        std::cin >> p[i-1] >> p[i];
    }
    for (int i=1; i<=n; i++){
        m[i][i]=0;
    }
    for (int l=2; l <=n; l++){
        for(int i=1; i<=n-l+1; i++){
            int j=i+l-1;
            m[i][j] = (1 << 21);
            for (int k=i; k<=j-1; k++){
                m[i][j] = std::min(m[i][j], m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }
    std::cout << m[1][n] << std::endl;
    return 0;
}

/* Fibonacci Dynamic Programming */
//int main(int argc, const char * argv[]) {
//    int n;
//    std::cin >> n;
//    int fibonacci [n+1];
//    fibonacci [0] = 1;
//    fibonacci [1] = 1;
//    for (int i=2; i<=n; i++){
//        fibonacci [i] = fibonacci [i-1] + fibonacci [i-2];
//    }
//    std::cout << fibonacci [n] << std::endl;
//
//    return 0;
//}
