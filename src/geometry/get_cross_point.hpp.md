---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/geometry/Point.hpp
    title: src/geometry/Point.hpp
  - icon: ':warning:'
    path: src/geometry/Segment.hpp
    title: src/geometry/Segment.hpp
  - icon: ':warning:'
    path: src/geometry/cross.hpp
    title: src/geometry/cross.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qiita.com/zu_rin/items/09876d2c7ec12974bc0f
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
    \  // \u5B9F\u6570\u306E\u540C\u5024\u5224\u5B9A\n    // bool operator==(const\
    \ Point &p) { return std::abs(x-p.x) < EPS and std::abs(y-p.y) < EPS; }\n    //\
    \ bool operator!=(const Point &p) { return std::abs(x-p.x) >= EPS or std::abs(y-p.y)\
    \ >= EPS; }\n    // \u6574\u6570\u306E\u540C\u5024\u5224\u5B9A\n    bool operator==(const\
    \ Point &p) { return x == p.x and y == p.y; }\n    bool operator!=(const Point\
    \ &p) { return x != p.x or y != p.y; }\n    Point operator*(T k) { return {x*k,\
    \ y*k}; }\n    Point operator/(T k) { return {x/k, y/k}; }\n    T norm() { return\
    \ x*x + y*y; }\n    T abs() { return sqrt(norm()); }\n    T abs(const Point &p)\
    \ { return hypot(x-p.x, y-p.y); }\n    T abs2(const Point &p) { return pow(x-p.x,\
    \ 2)+pow(y-p.y, 2); }\n    T manhattan(const Point &p) { return std::abs(x-p.x)\
    \ + std::abs(y-p.y); }\n    void print() { cout << x << ' ' << y << '\\n'; }\n\
    \    operator pair<T, T>() const { return {x, y}; }\n};\n\ntemplate<typename T>\n\
    void print(Point<T> p) {\n    cout << p.x << ' ' << p.y << '\\n';\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const Point<T> &p) {\n    return os <<\
    \ p.x << ' ' << p.y;\n}\n\ntemplate<typename T>\nbool operator<(const Point<T>\
    \ &p1, const Point<T> &p2) {\n    return mkp(p1.x, p1.y) < mkp(p2.x, p2.y);\n\
    }\n\ntemplate<typename T>\nbool operator==(const Point<T> &p1, const Point<T>\
    \ &p2) {\n    return mkp(p1.x, p1.y) == mkp(p2.x, p2.y);\n}\n#line 3 \"src/geometry/Segment.hpp\"\
    \n\ntemplate<typename T> struct Segment { Point<T> p1, p2; };\n#line 3 \"src/geometry/cross.hpp\"\
    \n\n// \u5916\u7A4D\ntemplate<typename T> T cross(const Point<T> a, const Point<T>\
    \ b) {\n    return a.x*b.y - a.y*b.x;\n}\n#line 4 \"src/geometry/get_cross_point.hpp\"\
    \n\n// \u53C2\u8003\uFF1Ahttps://qiita.com/zu_rin/items/09876d2c7ec12974bc0f\n\
    // \u7DDA\u5206seg1\u3068\u7DDA\u5206seg2\u306E\u4EA4\u70B9\ntemplate<typename\
    \ T>\nPoint<T> get_cross_point(Segment<T> seg1, Segment<T> seg2) {\n    T deno\
    \ = cross(seg1.p2 - seg1.p1, seg2.p2 - seg2.p1);\n    if (abs(deno) < EPS) {\n\
    \        // \u7DDA\u5206\u304C\u5E73\u884C\n        throw -1;\n    }\n    T s\
    \ = cross(seg2.p1 - seg1.p1, seg2.p2 - seg2.p1) / deno;\n    T t = cross(seg1.p2\
    \ - seg1.p1, seg1.p1 - seg2.p1) / deno;\n    if (s < -EPS or 1.0 < s-EPS or t\
    \ < -EPS or 1.0 < t-EPS) {\n        // \u7DDA\u5206\u304C\u4EA4\u5DEE\u3057\u3066\
    \u3044\u306A\u3044\n        throw -1;\n    }\n    return { seg1.p1.x + s * (seg1.p2\
    \ - seg1.p1).x, seg1.p1.y + s * (seg1.p2 - seg1.p1).y };\n}\n"
  code: "#include \"Point.hpp\"\n#include \"Segment.hpp\"\n#include \"cross.hpp\"\n\
    \n// \u53C2\u8003\uFF1Ahttps://qiita.com/zu_rin/items/09876d2c7ec12974bc0f\n//\
    \ \u7DDA\u5206seg1\u3068\u7DDA\u5206seg2\u306E\u4EA4\u70B9\ntemplate<typename\
    \ T>\nPoint<T> get_cross_point(Segment<T> seg1, Segment<T> seg2) {\n    T deno\
    \ = cross(seg1.p2 - seg1.p1, seg2.p2 - seg2.p1);\n    if (abs(deno) < EPS) {\n\
    \        // \u7DDA\u5206\u304C\u5E73\u884C\n        throw -1;\n    }\n    T s\
    \ = cross(seg2.p1 - seg1.p1, seg2.p2 - seg2.p1) / deno;\n    T t = cross(seg1.p2\
    \ - seg1.p1, seg1.p1 - seg2.p1) / deno;\n    if (s < -EPS or 1.0 < s-EPS or t\
    \ < -EPS or 1.0 < t-EPS) {\n        // \u7DDA\u5206\u304C\u4EA4\u5DEE\u3057\u3066\
    \u3044\u306A\u3044\n        throw -1;\n    }\n    return { seg1.p1.x + s * (seg1.p2\
    \ - seg1.p1).x, seg1.p1.y + s * (seg1.p2 - seg1.p1).y };\n}\n"
  dependsOn:
  - src/geometry/Point.hpp
  - src/macros.hpp
  - src/base.hpp
  - src/geometry/Segment.hpp
  - src/geometry/cross.hpp
  isVerificationFile: false
  path: src/geometry/get_cross_point.hpp
  requiredBy: []
  timestamp: '2022-10-04 01:47:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/get_cross_point.hpp
layout: document
redirect_from:
- /library/src/geometry/get_cross_point.hpp
- /library/src/geometry/get_cross_point.hpp.html
title: src/geometry/get_cross_point.hpp
---
