#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
static const int MAX = 100000;

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;

// 深さ優先探索
void dfs(int u) {
  V[u] = true;
  for ( int i = 0; i < G[u].size(); i++ ) {
    int v = G[u][i];
    if ( !V[v] ) dfs(v);
  }
  out.push_front(u);
}

int main() {
  int s, t, M;

  cin >> N >> M;

  for ( int i = 0; i < N; i++ ) V[i] = false;

  for ( int i = 0; i < M; i++ ) {
    cin >> s >> t;
    G[s].push_back(t);
  }

  for ( int i = 0; i < N; i++ ) {
    if ( !V[i] ) dfs(i);
  }

  for ( list<int>::iterator it = out.begin(); it != out.end(); it++ )
    cout << *it << endl;

    return 0;
}

