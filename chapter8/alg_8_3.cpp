#include<cstdio>
#define MAX 10000
#define NIL -1

struct Node { int parent, left, right; };

Node T[MAX];
int n, D[MAX], H[MAX];

// 深さを求める
void setDepth(int u, int d) {
  if (u==NIL) return;
  D[u] = d;
  setDepth(T[u].left, d+1);
  setDepth(T[u].right, d+1);
}

// 高さを求める
int setHeight(int u) {
  int h1 = 0, h2 = 0;
  if (T[u].left != NIL)
    h1 = setHeight(T[u].left) + 1;
  if (T[u].right != NIL)
    h2 = setHeight(T[u].right) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}

//接点uの兄弟を返す
int getSibling(int u) {
  //
  if (T[u].parent == NIL) return NIL;
  if (T[T[u].parent].left != u && T[T[u].parent].left != NIL)
    return T[T[u].parent].left;
  if (T[T[u].parent].right != u && T[T[u].parent].right != NIL)
    return T[T[u].parent].right;
  return NIL;
}

// 得られた値をノードごとに出力
void print(int u) {
  printf("node %d: ", u);
  printf("parent = %d, ", T[u].parent);
  printf("sibling = %d, ", getSibling(u));
  int deg = 0;
  if ( T[u].left != NIL ) deg++;
  if ( T[u].right != NIL ) deg++;
  printf("degree = %d, ", deg);
  printf("depth = %d, ", D[u]);
  printf("height = %d, ", H[u]);

  if ( T[u].parent == NIL ) {
    printf("root\n");
  } else if (T[u].left == NIL && T[u].right == NIL ) {
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}

int main() {
  int v, l, r, root = 0;
  scanf("%d", &n);

  // 親を空にしてノードを定義
  for ( int i = 0; i < n; i++ ) T[i].parent = NIL;

  for ( int i = 0; i < n; i++ ) {
    // 標準入力を受け取る+右の子、左の子のノード番号を構造体に格納
    // vはノード番号
    scanf("%d %d %d", &v, &l, &r);
    T[v].left = l;
    T[v].right = r;
    // それぞれの子の親を自分(ノード番号vのノード)として定義
    if ( l != NIL ) T[l].parent = v;
    if ( r != NIL ) T[r].parent = v;
  }

  // rootを探す
  for ( int i = 0; i < n; i++ ) if ( T[i].parent == NIL ) root = i;
  // 深さ・高さ探索
  setDepth(root, 0);
  setHeight(root);

  for ( int i = 0; i < n; i++ ) print(i);

  return 0;
}
