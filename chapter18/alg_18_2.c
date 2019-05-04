#include<stdio.h>

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  } else {
    return x;
  }
}

int main() {
  int a, b;
  // 標準入力を受け取る
  scanf("%d %d", &a, &b);

  printf("%d\n", gcd(a, b));

  return 0;
}
