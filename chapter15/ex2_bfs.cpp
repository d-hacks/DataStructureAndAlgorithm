#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;
static const int MAX = 100000;
static const int INFTY = (1<<29);

vector<int> G[MAX];
list<int> out;
bool V[MAX];  // ここでは色ではなく真偽値で探索を記録
int N;
int indeg[MAX]; // 入字数

// 幅優先探索
void bfs(int s) {
  queue<int> q;
  q.push(s);
  V[s] = true;
  while ( !q.empty() ) {
    int u = q.front(); q.pop();
    out.push_back(u); // 次数が0の頂点を連結リストに追加
    for ( int i = 0; i < G[u].size(); i++ ) {
      int v = G[u][i];  // uに隣接するノード
      indeg[v]--;
      if ( indeg[v] == 0 && !V[v] ) {
        V[v] = true;
        q.push(v);
      }
    }
  }
}

void tsort() {
  for ( int i = 0; i < N; i++ ) {
    indeg[i] = 0;
  }

  for ( int u = 0; u < N; u++ ) {
    for ( int i = 0; i < G[u].size(); i++ ) {
      int v = G[u][i];
      indeg[v]++; // 全てのノードについて，uの入字数indeg[u]を設定する
    }
  }

  for ( int u = 0; u < N; u++ )
    if ( indeg[u] == 0 && !V[u] ) bfs(u);

  for ( list<int>::iterator it = out.begin(); it != out.end(); it++ ) {
    cout << *it << endl;
  }
}

int main() {
  int s, t, M;

  cin >> N >> M;

  for ( int i = 0; i < N; i++ ) V[i] = false;

  for ( int i = 0; i < M; i++ ) {
    cin >> s >> t;
    G[s].push_back(t);
  }

  tsort();

  return 0;
}

