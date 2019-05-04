#include<iostream>
#include<vector>

using namespace std;
// 1 <= n <= 100000
static const int MAX = 100000;
static const int NIL = -1;

int n;
vector<int> G[MAX];
int color[MAX];

void dfs_visit(int u, int id) {
  color[u] = id;

  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];

    if (color[v] == NIL) {
      dfs_visit(v, id);
    }
  }
}

void assignColors() {
  int id = 1;

  for (int i = 0; i < n; i++) color[i] = NIL;

  for (int u = 0; u < n; u++) {
    if (color[u] == NIL) dfs_visit(u, id++);
  }
}

int main() {
  // origin, destination, num of nodes, num of edges
  int s, t, m, q;

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    // append
    G[s].push_back(t);
    G[t].push_back(s);
  }

  assignColors();

  cin >> q;

  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (color[s] == color[t]) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
