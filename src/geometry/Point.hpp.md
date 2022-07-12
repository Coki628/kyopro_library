---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/geometry/Circle.hpp
    title: src/geometry/Circle.hpp
  - icon: ':warning:'
    path: src/geometry/Segment.hpp
    title: src/geometry/Segment.hpp
  - icon: ':warning:'
    path: src/geometry/angle.hpp
    title: src/geometry/angle.hpp
  - icon: ':warning:'
    path: src/geometry/ccw.hpp
    title: src/geometry/ccw.hpp
  - icon: ':warning:'
    path: src/geometry/cross.hpp
    title: src/geometry/cross.hpp
  - icon: ':warning:'
    path: src/geometry/dot.hpp
    title: src/geometry/dot.hpp
  - icon: ':warning:'
    path: src/geometry/get_cross_point.hpp
    title: src/geometry/get_cross_point.hpp
  - icon: ':warning:'
    path: src/geometry/intersect.hpp
    title: src/geometry/intersect.hpp
  - icon: ':warning:'
    path: src/geometry/intersectCC.hpp
    title: src/geometry/intersectCC.hpp
  - icon: ':warning:'
    path: src/geometry/monotone_chain.hpp
    title: src/geometry/monotone_chain.hpp
  - icon: ':warning:'
    path: src/geometry/pick_theorem.hpp
    title: src/geometry/pick_theorem.hpp
  - icon: ':warning:'
    path: src/geometry/project.hpp
    title: src/geometry/project.hpp
  - icon: ':warning:'
    path: src/geometry/reflect.hpp
    title: src/geometry/reflect.hpp
  - icon: ':warning:'
    path: src/geometry/rotate.hpp
    title: src/geometry/rotate.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/geometry/Point.hpp\"\n\ntemplate<typename T>\nstruct Point {\n    T x, y;\n\
    \    Point() : x(0), y(0) {}\n    Point(T x, T y) : x(x), y(y) {}\n    Point operator+(const\
    \ Point &p) { return {x+p.x, y+p.y}; }\n    Point operator-(const Point &p) {\
    \ return {x-p.x, y-p.y}; }\n    Point operator*(const Point &p) { return {x*p.x,\
    \ y*p.y}; }\n    Point operator/(const Point &p) { return {x/p.x, y/p.y}; }\n\
    \    Point &operator+=(const Point &p) { x += p.x, y += p.y; return *this; }\n\
    \    Point &operator-=(const Point &p) { x -= p.x, y -= p.y; return *this; }\n\
    \    Point &operator*=(const Point &p) { x *= p.x, y *= p.y; return *this; }\n\
    \    Point &operator/=(const Point &p) { x /= p.x, y /= p.y; return *this; }\n\
    \    bool operator<(const Point &p) { return mkp(x, y) < mkp(p.x, p.y); }\n  \
    \  bool operator==(const Point &p) { return std::abs(x-p.x) < EPS and std::abs(y-p.y)\
    \ < EPS; }\n    bool operator!=(const Point &p) { return std::abs(x-p.x) >= EPS\
    \ or std::abs(y-p.y) >= EPS; }\n    Point operator*(T k) { return {x*k, y*k};\
    \ }\n    Point operator/(T k) { return {x/k, y/k}; }\n    T norm() { return x*x\
    \ + y*y; }\n    T abs() { return sqrt(norm()); }\n    T abs(const Point &p) {\
    \ return hypot(x-p.x, y-p.y); }\n    T abs2(const Point &p) { return pow(x-p.x,\
    \ 2)+pow(y-p.y, 2); }\n    T manhattan(const Point &p) { return std::abs(x-p.x)\
    \ + std::abs(y-p.y); }\n    void print() { cout << x << ' ' << y << '\\n'; }\n\
    };\n\ntemplate<typename T>\nvoid print(Point<T> p) {\n    cout << p.x << ' ' <<\
    \ p.y << '\\n';\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\ntemplate<typename T>\nstruct\
    \ Point {\n    T x, y;\n    Point() : x(0), y(0) {}\n    Point(T x, T y) : x(x),\
    \ y(y) {}\n    Point operator+(const Point &p) { return {x+p.x, y+p.y}; }\n  \
    \  Point operator-(const Point &p) { return {x-p.x, y-p.y}; }\n    Point operator*(const\
    \ Point &p) { return {x*p.x, y*p.y}; }\n    Point operator/(const Point &p) {\
    \ return {x/p.x, y/p.y}; }\n    Point &operator+=(const Point &p) { x += p.x,\
    \ y += p.y; return *this; }\n    Point &operator-=(const Point &p) { x -= p.x,\
    \ y -= p.y; return *this; }\n    Point &operator*=(const Point &p) { x *= p.x,\
    \ y *= p.y; return *this; }\n    Point &operator/=(const Point &p) { x /= p.x,\
    \ y /= p.y; return *this; }\n    bool operator<(const Point &p) { return mkp(x,\
    \ y) < mkp(p.x, p.y); }\n    bool operator==(const Point &p) { return std::abs(x-p.x)\
    \ < EPS and std::abs(y-p.y) < EPS; }\n    bool operator!=(const Point &p) { return\
    \ std::abs(x-p.x) >= EPS or std::abs(y-p.y) >= EPS; }\n    Point operator*(T k)\
    \ { return {x*k, y*k}; }\n    Point operator/(T k) { return {x/k, y/k}; }\n  \
    \  T norm() { return x*x + y*y; }\n    T abs() { return sqrt(norm()); }\n    T\
    \ abs(const Point &p) { return hypot(x-p.x, y-p.y); }\n    T abs2(const Point\
    \ &p) { return pow(x-p.x, 2)+pow(y-p.y, 2); }\n    T manhattan(const Point &p)\
    \ { return std::abs(x-p.x) + std::abs(y-p.y); }\n    void print() { cout << x\
    \ << ' ' << y << '\\n'; }\n};\n\ntemplate<typename T>\nvoid print(Point<T> p)\
    \ {\n    cout << p.x << ' ' << p.y << '\\n';\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/geometry/Point.hpp
  requiredBy:
  - src/geometry/intersect.hpp
  - src/geometry/reflect.hpp
  - src/geometry/project.hpp
  - src/geometry/ccw.hpp
  - src/geometry/cross.hpp
  - src/geometry/monotone_chain.hpp
  - src/geometry/dot.hpp
  - src/geometry/Segment.hpp
  - src/geometry/pick_theorem.hpp
  - src/geometry/get_cross_point.hpp
  - src/geometry/angle.hpp
  - src/geometry/Circle.hpp
  - src/geometry/intersectCC.hpp
  - src/geometry/rotate.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Point.hpp
layout: document
redirect_from:
- /library/src/geometry/Point.hpp
- /library/src/geometry/Point.hpp.html
title: src/geometry/Point.hpp
---
