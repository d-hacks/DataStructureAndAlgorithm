#include<stdio.h>

int linearSearch(int S[], int n, int key) {
  int i = 0;
  S[n] = key;
  while (S[i] != key ) {
    i++;
  }
  return i != n;
}

int main() {
  int i, n, S[10000+1], q, key, c = 0;

  scanf("%d", &n);
  for ( i=0; i<n; i++ ) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for ( i=0; i<q; i++ ) {
    scanf("%d", &key);
    if ( linearSearch(S, n, key) ) {
      c++;
    }
  }
  printf("%d\n", c);

  return 0;
}

// QUESTION:
// n個の整数を含む数列Sと
// q個の整数を含む数列Tがあるとき
// 共通するものの個数Cを出力する
//
// INPUT:
// 1 n
// 2 s1, s2, s3, ..., sn
// 3 q
// 4 t1, t2, t3, ..., tn
//
// OUTPUT:
// 1 c
