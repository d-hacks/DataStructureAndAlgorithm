#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  vector<int> v;

  cin >> n;
  for (int i=0; i<n; i++){
    int x; cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  for (int i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }

  cout << endl;

  return 0;
}
