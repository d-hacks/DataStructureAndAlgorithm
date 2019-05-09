#include<iostream>
#include<stack>
using namespace std;

int main() {
  stack<int> S;

  S.push(3);  // スタックに3をつむ
  S.push(7);  // スタックに7をつむ
  S.push(1);  // スタックに1をつむ
  cout << S.size() << " ";  // スタックのサイズ = 3

  cout << S.top() << " "; // 1
  S.pop();  // スタックの両店からの要素を削除

  cout << S.top() << " "; // 7
  S.pop();

  cout << S.top() << " "; // 3

  S.push(5);

  cout << S.top() << " "; // 5
  S.pop();

  cout << S.top() << endl; // 3

  return 0;
}
