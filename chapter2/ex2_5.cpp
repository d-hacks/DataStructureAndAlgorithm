//
// Created by yusuke on 2019-04-28.
//

#include<iostream>
#include<algorithm>
#include "ex2_5.h"


void maximum_profit(){
    using namespace std;
    static const int max_num = 200000;
    int R[max_num], n;

    // 入力数の指定
    cin >> n;
    //入力された価格を配列に格納
    for(int i = 0; i < n; i++){
        cin >> R[i];
    }

    int max_value = INT_MIN;
    int min_value = R[0];
    for(int i = 1; i < n; i++){
        //差額の最大値の更新
        if(max_value < R[i] - min_value){
            max_value = R[i] - min_value;
        }
        //価格の最小値を保持
        if(min_value > R[i]){
            min_value = R[i];
        }
    }
    printf("%d", max_value);
}