#include<iostream>
#include<cmath>

using namespace std;
typedef unsigned long long ullong;

ullong power(ullong m, ullong n, ullong M) {
  // res: 結果
  ullong res = 1;
  if ( n > 0 ){
    res = power(m, n / 2, M);
    if ( n % 2 == 0 ) {
      // nが偶数の時
      res = (res * res) % M;
    } else {
      // nが奇数の時
      res = (((res * res) % M) * m) % M;
    }
  }
  // m^0だった時にreturn 1
  return res;
}

int main(){
  int m, n;
  // 変数受け取り
  cin >> m >> n;

  cout << power(m, n, 1000000007) << endl;

  return 0;
}
