#include<iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000 // 番兵

int L[MAX/2+2], R[MAX/2+2]; //　マージの際の配列を一時的に格納するために使用する
int cnt; // マージにおける比較回数をカウント

void merge(int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for ( int i = 0; i < n1; i++ ) L[i] = A[left + i]; // 部分配列の前半部分を一時的に格納
  for ( int i = 0; i < n2; i++ ) R[i] = A[mid + i]; // 部分配列の後半部分を一時的に格納
  L[n1] = R[n2] = SENTINEL; //　各配列の最後に番兵を追加
  int i = 0, j = 0;
  // 整列した配列をAに戻す
  for ( int k = left; k < right; k++ ) {
    cnt++;
    if ( L[i] <= R[j] ) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[], int n, int left, int right) {
  if ( left + 1 < right ) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int main() {
  int A[MAX], n, i;
  cnt = 0;

  cin >> n;
  for ( i = 0; i < n; i++ ) cin >> A[i];
  mergeSort(A, n, 0, n);

  for ( i = 0; i < n; i++ ) {
    if ( i ) cout << " ";
    cout << A[i];
  }
  cout << endl;

  cout << cnt << endl;

  return 0;
}

