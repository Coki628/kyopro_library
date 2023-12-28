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
    path: src/geometry/degrees.hpp
    title: src/geometry/degrees.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
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
    }\n#line 3 \"src/geometry/degrees.hpp\"\n\nld degrees(ld radians) {\n    return\
    \ radians * 180.0 / PI;\n}\n#line 5 \"src/geometry/angle.hpp\"\n\n// \u5EA7\u6A19\
    b\u3092\u8EF8\u306B\u3057\u3066\u53CD\u6642\u8A08\u56DE\u308A\u306B\u5EA7\u6A19\
    a\u304B\u3089\u5EA7\u6A19c\u306B\u5411\u304B\u3046\u89D2\u5EA6\u3092\u53D6\u5F97\
    \ntemplate<typename T>\nld angle(Point<T> a, Point<T> b, Point<T> c, bool degree\
    \ = true) {\n    // b\u304B\u3089\u898B\u305Fa,c\u3078\u5411\u304B\u3046\u30D9\
    \u30AF\u30C8\u30EB\n    Point<T> v1 = a - b;\n    Point<T> v2 = c - b;\n    //\
    \ atan2\u304Cx=0\u304B\u3089\u898B\u305F\u89D2\u5EA6\u3092\u8FD4\u3059\u306E\u3067\
    \u3001\u5DEE\u5206\u3092\u53D6\u308B\n    T res = atan2(v2.y, v2.x) - atan2(v1.y,\
    \ v1.x);\n    // \u8AA4\u5DEE\u5BFE\u7B56\u306EEPS\u3001\u8CA0\u306E\u6570\u306A\
    \u3089\u6642\u8A08\u56DE\u308A\u5074\u306B\u3042\u308B\u306E\u3067\u9006\u5411\
    \u304D\u306B\u3059\u308B\n    if (res < -EPS) res += PI * 2;\n    if (degree)\
    \ res = degrees(res);\n    return res;\n}\n\n// // \u5EA7\u6A19b\u3092\u8EF8\u306B\
    \u3057\u3066\u8FD1\u3044\u5074\u56DE\u308A\u306B\u5EA7\u6A19a\u304B\u3089\u5EA7\
    \u6A19c\u306B\u5411\u304B\u3046\u89D2\u5EA6\u3092\u53D6\u5F97\n// template<typename\
    \ T>\n// ld angle(Point<T> a, Point<T> b, Point<T> c, bool degree=true) {\n//\
    \     // b\u304B\u3089\u898B\u305Fa,c\u3078\u5411\u304B\u3046\u30D9\u30AF\u30C8\
    \u30EB\n//     Point<T> v1 = a-b;\n//     Point<T> v2 = c-b;\n//     // atan2\u304C\
    x=0\u304B\u3089\u898B\u305F\u89D2\u5EA6\u3092\u8FD4\u3059\u306E\u3067\u3001\u5DEE\
    \u5206\u3092\u53D6\u308B\n//     T res = atan2(v2.y, v2.x) - atan2(v1.y, v1.x);\n\
    //     // \u8FD1\u3044\u5074\u306B\u56DE\u8EE2\u3055\u305B\u308B(-180~180\u306B\
    \u53CE\u3081\u308B)\n//     if (res+EPS >= PI) {\n//         res -= PI*2;\n//\
    \     } elif (res <= -PI+EPS) {\n//         res += PI*2;\n//     }\n//     assert(-PI\
    \ < res and res < PI);\n//     if (degree) res = degrees(res);\n//     return\
    \ res;\n// }\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"Point.hpp\"\n#include\
    \ \"degrees.hpp\"\n\n// \u5EA7\u6A19b\u3092\u8EF8\u306B\u3057\u3066\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B\u5EA7\u6A19a\u304B\u3089\u5EA7\u6A19c\u306B\u5411\u304B\
    \u3046\u89D2\u5EA6\u3092\u53D6\u5F97\ntemplate<typename T>\nld angle(Point<T>\
    \ a, Point<T> b, Point<T> c, bool degree = true) {\n    // b\u304B\u3089\u898B\
    \u305Fa,c\u3078\u5411\u304B\u3046\u30D9\u30AF\u30C8\u30EB\n    Point<T> v1 = a\
    \ - b;\n    Point<T> v2 = c - b;\n    // atan2\u304Cx=0\u304B\u3089\u898B\u305F\
    \u89D2\u5EA6\u3092\u8FD4\u3059\u306E\u3067\u3001\u5DEE\u5206\u3092\u53D6\u308B\
    \n    T res = atan2(v2.y, v2.x) - atan2(v1.y, v1.x);\n    // \u8AA4\u5DEE\u5BFE\
    \u7B56\u306EEPS\u3001\u8CA0\u306E\u6570\u306A\u3089\u6642\u8A08\u56DE\u308A\u5074\
    \u306B\u3042\u308B\u306E\u3067\u9006\u5411\u304D\u306B\u3059\u308B\n    if (res\
    \ < -EPS) res += PI * 2;\n    if (degree) res = degrees(res);\n    return res;\n\
    }\n\n// // \u5EA7\u6A19b\u3092\u8EF8\u306B\u3057\u3066\u8FD1\u3044\u5074\u56DE\
    \u308A\u306B\u5EA7\u6A19a\u304B\u3089\u5EA7\u6A19c\u306B\u5411\u304B\u3046\u89D2\
    \u5EA6\u3092\u53D6\u5F97\n// template<typename T>\n// ld angle(Point<T> a, Point<T>\
    \ b, Point<T> c, bool degree=true) {\n//     // b\u304B\u3089\u898B\u305Fa,c\u3078\
    \u5411\u304B\u3046\u30D9\u30AF\u30C8\u30EB\n//     Point<T> v1 = a-b;\n//    \
    \ Point<T> v2 = c-b;\n//     // atan2\u304Cx=0\u304B\u3089\u898B\u305F\u89D2\u5EA6\
    \u3092\u8FD4\u3059\u306E\u3067\u3001\u5DEE\u5206\u3092\u53D6\u308B\n//     T res\
    \ = atan2(v2.y, v2.x) - atan2(v1.y, v1.x);\n//     // \u8FD1\u3044\u5074\u306B\
    \u56DE\u8EE2\u3055\u305B\u308B(-180~180\u306B\u53CE\u3081\u308B)\n//     if (res+EPS\
    \ >= PI) {\n//         res -= PI*2;\n//     } elif (res <= -PI+EPS) {\n//    \
    \     res += PI*2;\n//     }\n//     assert(-PI < res and res < PI);\n//     if\
    \ (degree) res = degrees(res);\n//     return res;\n// }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/geometry/Point.hpp
  - src/geometry/degrees.hpp
  isVerificationFile: false
  path: src/geometry/angle.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/angle.hpp
layout: document
redirect_from:
- /library/src/geometry/angle.hpp
- /library/src/geometry/angle.hpp.html
title: src/geometry/angle.hpp
---
