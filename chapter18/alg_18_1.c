#include<stdio.h>

int isPrime(int x) {
  int i;

  if ( x < 2 ) {  // x = 0またはx = 1の時xは素数ではない
    return 0;
  } else if ( x == 2 ) {
    return 1;     // x = 2 の時xは素数
  } else if ( x % 2 == 0) {
    return 0;     // xが偶数の時xは素数ではない
  }

  // 3 ~ √x の間の奇数の倍数でないか順に確かめる
  for ( i = 3; i*i <= x; i+= 2 ) {
    if ( x % i == 0 ) {
      return 0;
    }
  }
  return 1;
}


int main() {
  int n, x, i;
  int count = 0;

  //標準入力を受け取る
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    scanf("%d", &x);

    if ( isPrime(x) ) {
      count++;
    }
  } 
  printf("%d\n", count);

  return 0;
}
