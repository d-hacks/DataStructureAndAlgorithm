//
// Created by yusuke on 2019-05-03.
//

#include "largest_rectangle.h"
#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 1400

using namespace std;

struct Rectangle {
    int height;
    int pos;
};

int getLargestRectangle(int size, int buffer[]){
    stack<Rectangle> S;
    int maxv = 0;
    buffer[size] = 0;

    for ( int i = 0; i <= size; i++ ){
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if ( S.empty() ) {
            S.push(rect);
        }else{
            if ( S.top().height < rect.height ) {
                S.push(rect);
            }else if( S.top().height > rect.height ) {
                int target = i;
                while ( !S.empty() && S.top().height >= rect.height ) {
                    Rectangle pre = S.top(); S.pop();
                    int area = pre.height * (i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
    }
    return maxv;
}


int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];


int getLargestRectangle() {
    for ( int j = 0; j < W; j++ ) {
        for ( int i = 0; i < H; i++ ) {
            if ( buffer[i][j] ) {
                T[i][j] = 0;
            } else {
                T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
            }
        }
    }

    int maxv = 0;
    for ( int i = 0; i < H; i++ ) {
        maxv = max(maxv, getLargestRectangle(W, T[i]));
    }
    return maxv;
}

void lr_main() {
    scanf("%d %d", &H, &W);
    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            scanf("%d", &buffer[i][j]);
        }
    }
    cout << getLargestRectangle() << endl;
}

