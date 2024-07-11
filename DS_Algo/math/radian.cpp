#include <bits/stdc++.h>

const double PI = acos(-1);

template <class T>
struct Point {
    T x, y;
    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {} // 初始化

    Point& operator+=(Point p) & { return x += p.x, y += p.y, *this; }
    Point& operator-=(Point p) & { return x -= p.x, y -= p.y, *this; }
    Point& operator*=(T t) & { return x *= t, y *= t, *this; }
    Point& operator/=(T t) & { return x /= t, y /= t, *this; }

    friend Point operator+(Point a, Point b) { return a += b; }
    friend Point operator-(Point a, Point b) { return a -= b; }
    friend Point operator*(Point a, T b) { return a *= b; }
    friend Point operator*(T a, Point b) { return b *= a; }
    friend Point operator/(Point a, T b) { return a /= b; }
    friend auto& operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }
};

template <class T>
double dis(T x1, T y1, T x2, T y2) { // 距离公式
    double val = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    return sqrt(val);
}

double toArc(double x) { // 角度转弧度
    return PI / 180 * x;
}