#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
  queue<string> Q;

  Q.push("red");
  Q.push("yellow");
  Q.push("yellow");
  Q.push("blue");

  cout << Q.front() << " "; // red
  Q.pop();

  cout << Q.front() << " "; // yellow
  Q.pop();

  cout << Q.front() << " "; // yellow
  Q.pop();

  Q.push("greem");

  cout << Q.front() << " "; // blue
  Q.pop();

  cout << Q.front() << " "; // green
  return 0;
}
