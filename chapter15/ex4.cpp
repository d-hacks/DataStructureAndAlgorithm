#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 100000
#define INFTY (1 << 30) // 1を30bit左にシフトする // 未探索の頂点を探すために使用

class Edge {
  public:
  int t, w;
  Edge(){}
  Edge(int t, int w): t(t), w(w) {}
};

vector<Edge> G[MAX];
int n, d[MAX];

bool vis[MAX];
int cnt;

// 幅優先探索
void bfs(int s) {
  for ( int i = 0; i < n; i++ ) d[i] = INFTY; // d = [1073741824,1073741824,1073741824,1073741824]
  queue<int> Q;
  Q.push(s);  // Q = [0]
  d[s] = 0;
  int u;
  while ( !Q.empty() ) {
    u = Q.front(); Q.pop(); // u は各節点 ex) 0
    for ( int i = 0; i < G[u].size(); i++ ) { // 各節点から繋がる辺の数だけ繰り返し
      Edge e = G[u][i];
      if ( d[e.t] == INFTY ) {  // 訪問した頂点から隣接してかつ未訪問の頂点を探索
        d[e.t] = d[u] + e.w; // 距離を計算し
        Q.push(e.t);  // キューに追加
      }
    }
  }
}

void solve() {
  // 適当な始点 s から最も遠い節点 tgt　を求める
  bfs(0);
  int maxv = 0;
  int tgt = 0;
  for ( int i = 0; i < n; i++ ) {
    if ( d[i] == INFTY ) continue;
    if ( maxv < d[i] ) {
    maxv = d[i];
    tgt = i;
    }
  }

  // tgt から最も遠い節点の距離 maxv を求める
  bfs(tgt);
  maxv = 0;
  for ( int i = 0; i < n; i++ ) {
    if ( d[i] == INFTY ) continue;
    maxv = max(maxv, d[i]);
  }

  cout << maxv << endl;
}

int main() {
  int s, t, w;
  cin >> n;

  for ( int i = 0; i < n-1; i++ ) {
    cin >> s >> t >> w;

    G[s].push_back(Edge(t, w)); // ベクタの最後に要素を追加
    G[t].push_back(Edge(s, w));
  }
  solve();
}
