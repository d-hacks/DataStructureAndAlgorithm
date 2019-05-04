// 点を表す構造体
struct Point {double x, y};

// ベクトルを表す構造体
typedef Point Vector;

// 線分を表す構造体
struct Segment{
  Point p1, p2;
};

// 直線を表す構造体
typedef Segment Line;

// 円を表すグラフ
class Circle {
  public:
    Point c;
    couble r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};

// 多角形の表現
typedef vector<Point> Polygon;

// ベクトルに対する演算子の定義
double x, y;
Point operator + (Point &p) {
  return Point(x + p.x, y + p.y);
}

Point operator - (Point &p) {
  return Point(x - p.x, y - p.y);
}

Point operator * (double k) {
  return Point(x * k, y * k);
}

// ベクトルに対する演算の例
Vector a, b, c, d;
c = a - b;
d = a * 2.0;

