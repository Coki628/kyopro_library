#pragma once
#include "../macros.hpp"

template<typename T>
struct Point {
    T x, y;
    Point() : x(0), y(0) {
    }
    Point(T x, T y) : x(x), y(y) {
    }
    Point operator+(const Point &p) {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point &p) {
        return {x - p.x, y - p.y};
    }
    Point operator*(const Point &p) {
        return {x * p.x, y * p.y};
    }
    Point operator/(const Point &p) {
        return {x / p.x, y / p.y};
    }
    Point &operator+=(const Point &p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) {
        x -= p.x, y -= p.y;
        return *this;
    }
    Point &operator*=(const Point &p) {
        x *= p.x, y *= p.y;
        return *this;
    }
    Point &operator/=(const Point &p) {
        x /= p.x, y /= p.y;
        return *this;
    }
    bool operator<(const Point &p) {
        return mkp(x, y) < mkp(p.x, p.y);
    }
    // 実数の同値判定
    // bool operator==(const Point &p) {
    //     return std::abs(x - p.x) < EPS and std::abs(y - p.y) < EPS;
    // }
    // bool operator!=(const Point &p) {
    //     return std::abs(x - p.x) >= EPS or std::abs(y - p.y) >= EPS;
    // }
    // 整数の同値判定
    bool operator==(const Point &p) {
        return x == p.x and y == p.y;
    }
    bool operator!=(const Point &p) {
        return x != p.x or y != p.y;
    }
    Point operator*(T k) {
        return {x * k, y * k};
    }
    Point operator/(T k) {
        return {x / k, y / k};
    }
    T norm() {
        return x * x + y * y;
    }
    T abs() {
        return sqrt(norm());
    }
    T abs(const Point &p) {
        return hypot(x - p.x, y - p.y);
    }
    // 整数のまま距離の大小を見たい時はこっち
    T abs2(const Point &p) {
        return pow(x - p.x, 2) + pow(y - p.y, 2);
    }
    T manhattan(const Point &p) {
        return std::abs(x - p.x) + std::abs(y - p.y);
    }
    void print() {
        cout << x << ' ' << y << '\n';
    }
    operator pair<T, T>() const {
        return {x, y};
    }
};

template<typename T>
void print(Point<T> p) {
    cout << p.x << ' ' << p.y << '\n';
}

template<typename T>
ostream &operator<<(ostream &os, const Point<T> &p) {
    return os << p.x << ' ' << p.y;
}

template<typename T>
bool operator<(const Point<T> &p1, const Point<T> &p2) {
    return mkp(p1.x, p1.y) < mkp(p2.x, p2.y);
}

template<typename T>
bool operator==(const Point<T> &p1, const Point<T> &p2) {
    return mkp(p1.x, p1.y) == mkp(p2.x, p2.y);
}

template<typename T>
T norm(Point<T> p) {
    return p.x * p.x + p.y * p.y;
}

template<typename T>
T abs(Point<T> p) {
    return sqrt(norm(p));
}
