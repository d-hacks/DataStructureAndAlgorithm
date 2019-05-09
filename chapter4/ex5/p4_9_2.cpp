#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
  int n, q, t;
  string name;
  // 標準ライブラリから queue を使用
  queue<pair<string, int > > Q; // プロセスのキュー

  cin >> n >> q;

  // 全てのプロセスをキューに順番に追加する
  for ( int i = 0; i < n; i++ ) {
    cin >> name >> t;
    Q.push(make_pair(name, t));
  }

  pair<string, int> u;
  int elaps = 0, a;

  // シミュレーション
  while ( !Q.empty() ) {
    u = Q.front(); Q.pop();
    a = min(u.second, q); // q または必要な時間 u.t だけ処理を行う
    u.second -= a;  // 残りの必要時間を計算
    elaps += a; // 経過時間を加算
    if ( u.second > 0 ) {
      Q.push(u);  // 処理が完了していなければキューに追加
    } else {
      cout << u.first << " " << elaps << endl;
    }
  }

  return 0;
}
