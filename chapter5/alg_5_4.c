#include<stdio.h>
#include<string.h>

#define M 1046527
#define NIL (-1)
#define L 14

char H[M][L];

int getChar(char ch) {
  if ( ch=='A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
  else return 0;
}

long long getKey(char str[]) {
  long long sum = 0, p = 1, i;
  // strlen ... 文字列の長さを返す関数
  for ( i=0; i<strlen(str); i++ ) {
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key) {
  return key % M;
}
int h2(int key) {
  return 1 + (key % (M - 1));
}

int find (char str[]) {
  long long key, i, h;
  key = getKey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    // strcmp...文字列の比較
    if (strcmp(H[h], str) == 0) return 1;
    else if (strlen(H[h]) == 0) return 0;
  }
  return 0;
}

int insert(char str[]){
  long long key, i, h;
  key = getKey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) return 1;
    else if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}

int main(){
  int i, n, h;
  char str[L], com[9];
  for (i=0; i<M; i++) H[i][0] = '\0';
  // input line 1
  scanf("%d", &n);
  // input line 2 ~ n
  for (i=0; i<n; i++) {
    // com: 命令, str: 文字列
    scanf("%s %s", com, str);
    // 1文字目だけで評価
    if (com[0] == 'i') {
      insert(str);
    } else {
      if ( find(str) ) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
  return 0;
}

// QUESTION:
// 命令の数 n
// 命令の種類 辞書に追加する: insert, 辞書内検索: find
//
// INPUT:
// 1 6
// 2 insert AAA
// 3 insert AAC
// 4 find AAA
// 5 find CCC
// 6 insert CCC
// 7 find CCC
//
// OUTPUT:
// 1 yes
// 2 no
// 3 yes
