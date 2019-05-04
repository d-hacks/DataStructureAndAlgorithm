#include <iostream>
#include "16_10_point_vector.h"
using namespace std;

bool isOrthogonal(Vector a,  Vector b) {
  return equals(dot(a, b), 0.0);
}

bool isParallel(Vector a, Vector b) {
  return equals(cross(a, b), 0.0);
}

int main(){
  int n, ans, i, j, l;
  int points[8];
  Vector a, b;

  cin >> n;
  for (i=0; i<n; i++) {
    for (j=0; j<8; j++) {
      cin >> l;
      points[j] = l;
    }

    a.x = points[2] - points[0];
    a.y = points[3] - points[1];
    b.x = points[6] - points[4];
    b.y = points[7] - points[5];

    if (isParallel(a, b)) {
      ans = 2;
    } else if (isOrthogonal(a, b)) {
      ans = 1;
    } else {
      ans = 0;
    }

    cout << ans << endl;
  }

  return 0;
}
