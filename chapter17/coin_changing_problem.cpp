//
// Created by yusuke on 2019-04-30.
//

#include <iostream>
#include <algorithm>
#include "coin_changing_problem.h"

using namespace std;

static const int N_MAX = 50000;
static const int INFTY = (1 << 29);


void coin_main(){
    int n, m;
    int coin[21];
    int T[N_MAX +  1];

    // n : 支払金額、m : コインの種類
    cin >> n >> m;
    // コインの額面を入力
    for (int i = 1; i <= m; i++){
        cin >> coin[i];
    }

    for(int i = 0; i <= N_MAX; i++){
        T[i] = INFTY;
    }
    T[0] = 0;

    // 使用するコインの種類ごとの支払金額までの最小枚数をTに保存していく
    for(int i = 1; i <= m; i++){
        for(int j = 0; j + coin[i] <= n; j++){
            T[j + coin[i]] = min(T[j + coin[i]], T[j] + 1 );
            cout << T[j + coin[i]] << endl;
        }
    }
    cout << T[n] << endl;
}