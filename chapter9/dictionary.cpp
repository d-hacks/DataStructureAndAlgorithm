//
// Created by yusuke on 2019-04-29.
//

#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include "dictionary.h"
using namespace std;

void dictionary_main() {
    int n;
    char str[10], com[13];
    map<string, bool> T; // 標準ライブラリからmap を使用

    cin >> n;
    for ( int i = 0; i < n; i++ ) {
     scanf("%s%s", com, str);
     if ( com[0] == 'i' ) T[string(str)] = true;
     else {
         if ( T[string(str)] ) printf("yes\n");
         else printf("no\n");
         }
     }
}