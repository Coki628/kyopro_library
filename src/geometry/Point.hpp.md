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
    path: src/geometry/Line.hpp
    title: src/geometry/Line.hpp
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
    path: src/geometry/get_distance.hpp
    title: src/geometry/get_distance.hpp
  - icon: ':warning:'
    path: src/geometry/get_triangle_by_points.hpp
    title: src/geometry/get_triangle_by_points.hpp
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
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull\
    \ = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\nusing vvl = vv<ll>;\n\
    using vvi = vv<int>;\nusing vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil\
    \ = vv<pil>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa\
    \ = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n\
    #define rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb)\
    \ or (c < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a);\
    \ i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/geometry/Point.hpp\"\
    \n\ntemplate<typename T>\nstruct Point {\n    T x, y;\n    Point() : x(0), y(0)\
    \ {\n    }\n    Point(T x, T y) : x(x), y(y) {\n    }\n    Point operator+(const\
    \ Point &p) {\n        return {x + p.x, y + p.y};\n    }\n    Point operator-(const\
    \ Point &p) {\n        return {x - p.x, y - p.y};\n    }\n    Point operator*(const\
    \ Point &p) {\n        return {x * p.x, y * p.y};\n    }\n    Point operator/(const\
    \ Point &p) {\n        return {x / p.x, y / p.y};\n    }\n    Point &operator+=(const\
    \ Point &p) {\n        x += p.x, y += p.y;\n        return *this;\n    }\n   \
    \ Point &operator-=(const Point &p) {\n        x -= p.x, y -= p.y;\n        return\
    \ *this;\n    }\n    Point &operator*=(const Point &p) {\n        x *= p.x, y\
    \ *= p.y;\n        return *this;\n    }\n    Point &operator/=(const Point &p)\
    \ {\n        x /= p.x, y /= p.y;\n        return *this;\n    }\n    bool operator<(const\
    \ Point &p) {\n        return mkp(x, y) < mkp(p.x, p.y);\n    }\n    // \u5B9F\
    \u6570\u306E\u540C\u5024\u5224\u5B9A\n    // bool operator==(const Point &p) {\n\
    \    //     return std::abs(x - p.x) < EPS and std::abs(y - p.y) < EPS;\n    //\
    \ }\n    // bool operator!=(const Point &p) {\n    //     return std::abs(x -\
    \ p.x) >= EPS or std::abs(y - p.y) >= EPS;\n    // }\n    // \u6574\u6570\u306E\
    \u540C\u5024\u5224\u5B9A\n    bool operator==(const Point &p) {\n        return\
    \ x == p.x and y == p.y;\n    }\n    bool operator!=(const Point &p) {\n     \
    \   return x != p.x or y != p.y;\n    }\n    Point operator*(T k) {\n        return\
    \ {x * k, y * k};\n    }\n    Point operator/(T k) {\n        return {x / k, y\
    \ / k};\n    }\n    T norm() {\n        return x * x + y * y;\n    }\n    T abs()\
    \ {\n        return sqrt(norm());\n    }\n    T abs(const Point &p) {\n      \
    \  return hypot(x - p.x, y - p.y);\n    }\n    // \u6574\u6570\u306E\u307E\u307E\
    \u8DDD\u96E2\u306E\u5927\u5C0F\u3092\u898B\u305F\u3044\u6642\u306F\u3053\u3063\
    \u3061\n    T abs2(const Point &p) {\n        return pow(x - p.x, 2) + pow(y -\
    \ p.y, 2);\n    }\n    T manhattan(const Point &p) {\n        return std::abs(x\
    \ - p.x) + std::abs(y - p.y);\n    }\n    void print() {\n        cout << x <<\
    \ ' ' << y << '\\n';\n    }\n    operator pair<T, T>() const {\n        return\
    \ {x, y};\n    }\n};\n\ntemplate<typename T>\nvoid print(Point<T> p) {\n    cout\
    \ << p.x << ' ' << p.y << '\\n';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const Point<T> &p) {\n    return os << p.x << ' ' << p.y;\n}\n\ntemplate<typename\
    \ T>\nbool operator<(const Point<T> &p1, const Point<T> &p2) {\n    return mkp(p1.x,\
    \ p1.y) < mkp(p2.x, p2.y);\n}\n\ntemplate<typename T>\nbool operator==(const Point<T>\
    \ &p1, const Point<T> &p2) {\n    return mkp(p1.x, p1.y) == mkp(p2.x, p2.y);\n\
    }\n\ntemplate<typename T>\nT norm(Point<T> p) {\n    return p.x * p.x + p.y *\
    \ p.y;\n}\n\ntemplate<typename T>\nT abs(Point<T> p) {\n    return sqrt(norm(p));\n\
    }\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\ntemplate<typename T>\nstruct\
    \ Point {\n    T x, y;\n    Point() : x(0), y(0) {\n    }\n    Point(T x, T y)\
    \ : x(x), y(y) {\n    }\n    Point operator+(const Point &p) {\n        return\
    \ {x + p.x, y + p.y};\n    }\n    Point operator-(const Point &p) {\n        return\
    \ {x - p.x, y - p.y};\n    }\n    Point operator*(const Point &p) {\n        return\
    \ {x * p.x, y * p.y};\n    }\n    Point operator/(const Point &p) {\n        return\
    \ {x / p.x, y / p.y};\n    }\n    Point &operator+=(const Point &p) {\n      \
    \  x += p.x, y += p.y;\n        return *this;\n    }\n    Point &operator-=(const\
    \ Point &p) {\n        x -= p.x, y -= p.y;\n        return *this;\n    }\n   \
    \ Point &operator*=(const Point &p) {\n        x *= p.x, y *= p.y;\n        return\
    \ *this;\n    }\n    Point &operator/=(const Point &p) {\n        x /= p.x, y\
    \ /= p.y;\n        return *this;\n    }\n    bool operator<(const Point &p) {\n\
    \        return mkp(x, y) < mkp(p.x, p.y);\n    }\n    // \u5B9F\u6570\u306E\u540C\
    \u5024\u5224\u5B9A\n    // bool operator==(const Point &p) {\n    //     return\
    \ std::abs(x - p.x) < EPS and std::abs(y - p.y) < EPS;\n    // }\n    // bool\
    \ operator!=(const Point &p) {\n    //     return std::abs(x - p.x) >= EPS or\
    \ std::abs(y - p.y) >= EPS;\n    // }\n    // \u6574\u6570\u306E\u540C\u5024\u5224\
    \u5B9A\n    bool operator==(const Point &p) {\n        return x == p.x and y ==\
    \ p.y;\n    }\n    bool operator!=(const Point &p) {\n        return x != p.x\
    \ or y != p.y;\n    }\n    Point operator*(T k) {\n        return {x * k, y *\
    \ k};\n    }\n    Point operator/(T k) {\n        return {x / k, y / k};\n   \
    \ }\n    T norm() {\n        return x * x + y * y;\n    }\n    T abs() {\n   \
    \     return sqrt(norm());\n    }\n    T abs(const Point &p) {\n        return\
    \ hypot(x - p.x, y - p.y);\n    }\n    // \u6574\u6570\u306E\u307E\u307E\u8DDD\
    \u96E2\u306E\u5927\u5C0F\u3092\u898B\u305F\u3044\u6642\u306F\u3053\u3063\u3061\
    \n    T abs2(const Point &p) {\n        return pow(x - p.x, 2) + pow(y - p.y,\
    \ 2);\n    }\n    T manhattan(const Point &p) {\n        return std::abs(x - p.x)\
    \ + std::abs(y - p.y);\n    }\n    void print() {\n        cout << x << ' ' <<\
    \ y << '\\n';\n    }\n    operator pair<T, T>() const {\n        return {x, y};\n\
    \    }\n};\n\ntemplate<typename T>\nvoid print(Point<T> p) {\n    cout << p.x\
    \ << ' ' << p.y << '\\n';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const Point<T> &p) {\n    return os << p.x << ' ' << p.y;\n}\n\ntemplate<typename\
    \ T>\nbool operator<(const Point<T> &p1, const Point<T> &p2) {\n    return mkp(p1.x,\
    \ p1.y) < mkp(p2.x, p2.y);\n}\n\ntemplate<typename T>\nbool operator==(const Point<T>\
    \ &p1, const Point<T> &p2) {\n    return mkp(p1.x, p1.y) == mkp(p2.x, p2.y);\n\
    }\n\ntemplate<typename T>\nT norm(Point<T> p) {\n    return p.x * p.x + p.y *\
    \ p.y;\n}\n\ntemplate<typename T>\nT abs(Point<T> p) {\n    return sqrt(norm(p));\n\
    }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/geometry/Point.hpp
  requiredBy:
  - src/geometry/dot.hpp
  - src/geometry/monotone_chain.hpp
  - src/geometry/project.hpp
  - src/geometry/intersect.hpp
  - src/geometry/pick_theorem.hpp
  - src/geometry/cross.hpp
  - src/geometry/get_distance.hpp
  - src/geometry/intersectCC.hpp
  - src/geometry/angle.hpp
  - src/geometry/Segment.hpp
  - src/geometry/ccw.hpp
  - src/geometry/Line.hpp
  - src/geometry/Circle.hpp
  - src/geometry/get_cross_point.hpp
  - src/geometry/reflect.hpp
  - src/geometry/rotate.hpp
  - src/geometry/get_triangle_by_points.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Point.hpp
layout: document
redirect_from:
- /library/src/geometry/Point.hpp
- /library/src/geometry/Point.hpp.html
title: src/geometry/Point.hpp
---