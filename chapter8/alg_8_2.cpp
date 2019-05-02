#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node { int p, l, r; };

Node T[MAX];
int n, D[MAX];

// 出力する関数
// void: 戻り値のいらない関数
void print(int u) {
  int i, c;
  cont
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p << ", ";
  cout << "depth = " << D[u] << ", ";

  if (T[u].p == NIL) cout << "root, ";
  else if (T[u].l == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";

  for (i=0, c=T[u].l; c!= NIL; i++, c=T[c].r) {
    if (i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

// depthを再帰的に求める
void rec(int u, int p) {
  D[u] = p;
  if (T[u].r != NIL) rec(T[u].r, p);
  if (T[u].l != NIL) rec(T[u].l, p+1);
}

// 各nodeの定義
int main() {
  int i, j, d, v, c, l, r;

  // 標準入力を受け取る
  cin >> n;
  // 空？ノードを作る
  for (i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;

  // 子と兄弟のノード情報を埋める
  for (i=0; i<n; i++) {
    cin >> v >> d;
    for (j=0; j<d; j++) {
      cin >> c;
      // d: 子の数
      // c: 子のノード

      if (j==0) T[v].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = v;
    }
  }

  // 親ノードを探す
  for (i=0; i<n; i++) {
    if (T[i].p == NIL) r = i;
  }
  //深さ情報を再帰的に得る
  rec(r, 0);

  //ノードごとに結果をプリント
  for (i=0; i<n; i++) print(i);

  return 0;
}

// QUESTION:
// 与えられた木の各接点uについて、以下の情報を出力せよ
  // ▶ u の節点番号
  // ▶ u の節点の種類（根、内部ノードまたは葉）
  // ▶ u の親の節点番号
  // ▶ u の子のリスト
  // ▶ u の深さ
  // ex) node 0: parent = -1, depth = 0, root, [1, 4, 10]
//
// INPUT:
// 1 n (接点の個数)
// 2 id k c1 c2 ... ck (id: 接点の番号, k: 次数, c1~ck: 子の接点番号)
// ...
//
// OUTPUT:
// 1 node id: parent = p, depth = d, type, [c1, ..., ck]
