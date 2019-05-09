//
// Created by yusuke on 2019-05-03.
//

#include "largest_square.h"
#include <cstdio>
#include <algorithm>
#include <iostream>
#define NMAX 1400

using namespace std;


int dp[NMAX][NMAX];
int G[NMAX][NMAX];


int getLargestSquare( int H, int W ) {
    int maxWidth = 0;
    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            dp[i][j] = (G[i][j] + 1) % 2;
            maxWidth |= dp[i][j];
        }
    }

    for ( int i = 1; i < H; i++ ) {
        for ( int j = 1; j < W; j++ ) {
            if ( G[i][j] ) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxWidth = max(maxWidth, dp[i][j]);
            }
        }
    }
    return maxWidth * maxWidth;
}


int main() {
    int H, W;
    cin >> H >> W;

    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            cin >> G[i][j];
        }
    }
    printf("%d\n", getLargestSquare(H, W));
}