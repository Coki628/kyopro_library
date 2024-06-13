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
    }\n#line 3 \"src/geometry/cross.hpp\"\n\n// \u5916\u7A4D\ntemplate<typename T>\n\
    T cross(const Point<T> a, const Point<T> b) {\n    return a.x * b.y - a.y * b.x;\n\
    }\n#line 5 \"src/geometry/pick_theorem.hpp\"\n\n// \u30D4\u30C3\u30AF\u306E\u5B9A\
    \u7406(\u591A\u89D2\u5F62\u306E\u5EA7\u6A19\u304B\u3089\u3001\u5185\u90E8\u306B\
    \u3042\u308B\u683C\u5B50\u70B9\u306E\u6570\u3092\u51FA\u3059)\ntuple<ll, ll, ll>\
    \ pick_theorem(vector<Point<ll>> P) {\n    ll N = P.size();\n    ll S = 0;\n \
    \   ll b = 0;\n    rep(i, N) {\n        S += cross(P[i], P[(i + 1) % N]);\n  \
    \      auto a = P[i] - P[(i + 1) % N];\n        b += gcd(abs(a.x), abs(a.y));\n\
    \    }\n    ll i = (abs(S) - b + 2) / 2;\n    // \u5185\u90E8\u306B\u3042\u308B\
    \u683C\u5B50\u70B9\u306E\u6570, \u8FBA\u4E0A\u306E\u683C\u5B50\u70B9\u306E\u6570\
    , \u9762\u7A4D\n    return {i, b, abs(S)};\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"Point.hpp\"\n#include\
    \ \"cross.hpp\"\n\n// \u30D4\u30C3\u30AF\u306E\u5B9A\u7406(\u591A\u89D2\u5F62\u306E\
    \u5EA7\u6A19\u304B\u3089\u3001\u5185\u90E8\u306B\u3042\u308B\u683C\u5B50\u70B9\
    \u306E\u6570\u3092\u51FA\u3059)\ntuple<ll, ll, ll> pick_theorem(vector<Point<ll>>\
    \ P) {\n    ll N = P.size();\n    ll S = 0;\n    ll b = 0;\n    rep(i, N) {\n\
    \        S += cross(P[i], P[(i + 1) % N]);\n        auto a = P[i] - P[(i + 1)\
    \ % N];\n        b += gcd(abs(a.x), abs(a.y));\n    }\n    ll i = (abs(S) - b\
    \ + 2) / 2;\n    // \u5185\u90E8\u306B\u3042\u308B\u683C\u5B50\u70B9\u306E\u6570\
    , \u8FBA\u4E0A\u306E\u683C\u5B50\u70B9\u306E\u6570, \u9762\u7A4D\n    return {i,\
    \ b, abs(S)};\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/geometry/Point.hpp
  - src/geometry/cross.hpp
  isVerificationFile: false
  path: src/geometry/pick_theorem.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/pick_theorem.hpp
layout: document
redirect_from:
- /library/src/geometry/pick_theorem.hpp
- /library/src/geometry/pick_theorem.hpp.html
title: src/geometry/pick_theorem.hpp
---
