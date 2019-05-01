//
// Created by yusuke on 2019-04-27.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <limits.h>
#include "ex2_2.h"

std::vector<int> algorithm1(std::vector<int> array) {
    int num = 0;
    std::vector<int> max_array;
    for(int i = 0; i < 3; i++){
        // 最大値の初期化
        int max_value = INT_MIN;
        for(int j = 0; j < (int)array.size(); j++) {
            if( array[j] > max_value ) {
                max_value = array[j];
                num = j;
            }
        }
        // 各回の最大値を格納
        max_array.push_back(max_value);
        // 各回の最大値を削除
        array.erase(array.begin() + num);
    }
    return max_array;
}


std::vector<int> algorithm2(std::vector<int> array) {
    std::vector<int> max_array;
    // 降順ソート
    std::sort(array.begin(), array.end(), std::greater<>());
    for(int i = 0; i < 3; i++){
        max_array.push_back(array[i]);
    }
    return max_array;
}


std::vector<int> algorithm3(std::vector<int> array) {
    std::vector<int> max_array;
    std::vector<int> point(101);
    int limit = 0;
    // 各得点の人数をpointに格納
    for(int i = 0; i < (int)point.size(); i++) {
        for (int j = 0; j < (int) array.size(); j++) {
            if (i == array[j]) {
                point[i] += 1;
            }
        }
    }
    //point[l]が1以上の場合lを3回まで出力
    for(int l = 101; l >= 0; l--){
        if(point[l] > 0){
            for (int num = point[l]; num >= 1; num--){
                max_array.push_back(l);
                limit++;
            }
        }else if(limit == 3){
            break;
        }
    }
    return max_array;
}