#include<stdio.h>
#define MAX 100000

int A[MAX], n;

int partition(int p, int r) {
  int x, i, j, t;
  x = A[r]; /* 基準 */
  i = p - 1;  /* 初期値 */
  for (j = p; j < r; j++ ) {
    if ( A[j] <= x ) {
      i++;
      t = A[i]; A[i] = A[j]; A[j] = t; /* A[i]とA[j]を入れ替える */
    }
  }
  t = A[i + 1]; A[i + 1] = A[r]; A[r] = t;  /* A[i+1]とA[r]を入れ替える */
  return i + 1;
}

int main() {
  int i, q;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  q = partition(0, n - 1);

  for ( i = 0; i < n; i++ ) {
    if ( i ) printf(" ");
    if ( i == q ) printf("["); /* 基準値の部分だけ[]をつける */
    printf("%d", A[i]);
    if ( i == q ) printf("]");
  }
  printf("\n");

  return 0;
}
