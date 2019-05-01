#include<stdio.h>

int S[1000000], n;

int binarySearch(int key) {
  int left  = 0;
  int right = n;
  int mid;

  while (left < right) {
    mid = (left + right)/2;
    if (S[mid] == key) {
      return 1;
    } else if (S[mid] < key ) {
      left = mid + 1;
    } else if (S[mid] > key) {
      right = mid;
    }
  }
  return 0;
}

int main() {
  int i, q, k, c = 0;

  scanf("%d", &n);
  for ( i=0; i<n; i++ ) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for ( i=0; i<q; i++ ) {
    scanf("%d", &k);
    if ( binarySearch(k) ) c++;
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
