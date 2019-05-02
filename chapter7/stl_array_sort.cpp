#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n, v[5];

  for (int i=0; i<5; i++) cin >> v[i];

  sort(v, v+5);

  for (int i=0; i<5; i++){
    cout << v[i] << " ";
  }

  cout << endl;
  return 0;
}

