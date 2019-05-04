#include <cmath>
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point{
  public:
    double x, y;

  Point(double x = 0, double y = 0): x(x), y(y) {}

  Point operator + (Point p) {return Point(x + p.x, y + p.y);}
  Point operator - (Point p) {return Point(x - p.x, y - p.y);}
  Point operator * (double a) {return Point(a * x, a * y);}
  Point operator / (double a) {return Point(x / a, y / a);}

  double norm() {return x * x + y * y;}
  double abs() {return std::sqrt(norm());}

  bool operator < (const Point &p) const{
    return x != p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const{
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

typedef Point Vector;

double dot(Vector a, Vector b){
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}
