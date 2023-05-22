---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/pow.hpp
    title: src/common/pow.hpp
  - icon: ':warning:'
    path: src/geometry/Circle.hpp
    title: src/geometry/Circle.hpp
  - icon: ':warning:'
    path: src/geometry/Point.hpp
    title: src/geometry/Point.hpp
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
    - https://manabitimes.jp/math/745
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/pow.hpp\"\
    \n\nll pow(ll x, ll n) {\n    ll res = 1;\n    rep(_, n) res *= x;\n    return\
    \ res;\n}\n\nll pow(int x, ll n) { return pow((ll)x, n); }\n\nll pow(ll x, int\
    \ n) { return pow(x, (ll)n); }\n\nll pow(int x, int n) { return pow((ll)x, (ll)n);\
    \ }\n\nll pow(ll x, ll n, int mod) {\n    x %= mod;\n    ll res = 1;\n    while\
    \ (n > 0) {\n        if (n & 1) {\n            res = (res * x) % mod;\n      \
    \  }\n        x = (x * x) % mod;\n        n >>= 1;\n    }\n    return res;\n}\n\
    #line 3 \"src/geometry/Point.hpp\"\n\ntemplate<typename T>\nstruct Point {\n \
    \   T x, y;\n    Point() : x(0), y(0) {}\n    Point(T x, T y) : x(x), y(y) {}\n\
    \    Point operator+(const Point &p) { return {x+p.x, y+p.y}; }\n    Point operator-(const\
    \ Point &p) { return {x-p.x, y-p.y}; }\n    Point operator*(const Point &p) {\
    \ return {x*p.x, y*p.y}; }\n    Point operator/(const Point &p) { return {x/p.x,\
    \ y/p.y}; }\n    Point &operator+=(const Point &p) { x += p.x, y += p.y; return\
    \ *this; }\n    Point &operator-=(const Point &p) { x -= p.x, y -= p.y; return\
    \ *this; }\n    Point &operator*=(const Point &p) { x *= p.x, y *= p.y; return\
    \ *this; }\n    Point &operator/=(const Point &p) { x /= p.x, y /= p.y; return\
    \ *this; }\n    bool operator<(const Point &p) { return mkp(x, y) < mkp(p.x, p.y);\
    \ }\n    // \u5B9F\u6570\u306E\u540C\u5024\u5224\u5B9A\n    // bool operator==(const\
    \ Point &p) { return std::abs(x-p.x) < EPS and std::abs(y-p.y) < EPS; }\n    //\
    \ bool operator!=(const Point &p) { return std::abs(x-p.x) >= EPS or std::abs(y-p.y)\
    \ >= EPS; }\n    // \u6574\u6570\u306E\u540C\u5024\u5224\u5B9A\n    bool operator==(const\
    \ Point &p) { return x == p.x and y == p.y; }\n    bool operator!=(const Point\
    \ &p) { return x != p.x or y != p.y; }\n    Point operator*(T k) { return {x*k,\
    \ y*k}; }\n    Point operator/(T k) { return {x/k, y/k}; }\n    T norm() { return\
    \ x*x + y*y; }\n    T abs() { return sqrt(norm()); }\n    T abs(const Point &p)\
    \ { return hypot(x-p.x, y-p.y); }\n    // \u6574\u6570\u306E\u307E\u307E\u8DDD\
    \u96E2\u306E\u5927\u5C0F\u3092\u898B\u305F\u3044\u6642\u306F\u3053\u3063\u3061\
    \n    T abs2(const Point &p) { return pow(x-p.x, 2)+pow(y-p.y, 2); }\n    T manhattan(const\
    \ Point &p) { return std::abs(x-p.x) + std::abs(y-p.y); }\n    void print() {\
    \ cout << x << ' ' << y << '\\n'; }\n    operator pair<T, T>() const { return\
    \ {x, y}; }\n};\n\ntemplate<typename T>\nvoid print(Point<T> p) {\n    cout <<\
    \ p.x << ' ' << p.y << '\\n';\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const Point<T> &p) {\n    return os << p.x << ' ' << p.y;\n}\n\ntemplate<typename\
    \ T>\nbool operator<(const Point<T> &p1, const Point<T> &p2) {\n    return mkp(p1.x,\
    \ p1.y) < mkp(p2.x, p2.y);\n}\n\ntemplate<typename T>\nbool operator==(const Point<T>\
    \ &p1, const Point<T> &p2) {\n    return mkp(p1.x, p1.y) == mkp(p2.x, p2.y);\n\
    }\n\ntemplate<typename T>\nT norm(Point<T> p) {\n    return p.x * p.x + p.y *\
    \ p.y;\n}\n\ntemplate<typename T>\nT abs(Point<T> p) {\n    return sqrt(norm(p));\n\
    }\n#line 4 \"src/geometry/Circle.hpp\"\n\ntemplate<typename T>\nstruct Circle\
    \ {\n    Point<T> c;\n    T r;\n    Circle(Point<T> c={0, 0}, T r=0) : c(c), r(r)\
    \ {}\n};\n#line 4 \"src/geometry/intersectCC.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://manabitimes.jp/math/745\n\
    // \u5186c1\u3068\u5186c2\u306E\u4EA4\u5DEE\u5224\u5B9A(2\u4E57\u306E\u307E\u307E\
    \u6574\u6570\u3067\u5224\u5B9A\u3067\u304D\u308B\u3088\u3046\u306B\u3057\u3066\
    \u3042\u308B)\ntemplate<typename T>\nint intersectCC(Circle<T> c1, Circle<T> c2)\
    \ {\n    T d2 = pow(c1.c.x-c2.c.x, 2) + pow(c1.c.y-c2.c.y, 2);\n    // \u4E00\u65B9\
    \u304C\u4ED6\u65B9\u3092\u5185\u5305\n    if (d2 < pow(abs(c1.r-c2.r), 2)) {\n\
    \        return 1;\n    }\n    // \u5185\u63A5\u3059\u308B\n    if (d2 == pow(abs(c1.r-c2.r),\
    \ 2)) {\n        return 2;\n    }\n    // 2\u70B9\u3067\u4EA4\u308F\u308B\n  \
    \  if (pow(abs(c1.r-c2.r), 2) < d2 and d2 < pow(c1.r+c2.r, 2)) {\n        return\
    \ 3;\n    }\n    // \u5916\u63A5\u3059\u308B\n    if (d2 == pow(c1.r+c2.r, 2))\
    \ {\n        return 4;\n    }\n    // 2\u5186\u304C\u96E2\u308C\u3066\u308B\n\
    \    if (d2 > pow(c1.r+c2.r, 2)) {\n        return 5;\n    }\n    assert(0);\n\
    }\n"
  code: "#include \"../base.hpp\"\n#include \"../common/pow.hpp\"\n#include \"Circle.hpp\"\
    \n\n// \u53C2\u8003\uFF1Ahttps://manabitimes.jp/math/745\n// \u5186c1\u3068\u5186\
    c2\u306E\u4EA4\u5DEE\u5224\u5B9A(2\u4E57\u306E\u307E\u307E\u6574\u6570\u3067\u5224\
    \u5B9A\u3067\u304D\u308B\u3088\u3046\u306B\u3057\u3066\u3042\u308B)\ntemplate<typename\
    \ T>\nint intersectCC(Circle<T> c1, Circle<T> c2) {\n    T d2 = pow(c1.c.x-c2.c.x,\
    \ 2) + pow(c1.c.y-c2.c.y, 2);\n    // \u4E00\u65B9\u304C\u4ED6\u65B9\u3092\u5185\
    \u5305\n    if (d2 < pow(abs(c1.r-c2.r), 2)) {\n        return 1;\n    }\n   \
    \ // \u5185\u63A5\u3059\u308B\n    if (d2 == pow(abs(c1.r-c2.r), 2)) {\n     \
    \   return 2;\n    }\n    // 2\u70B9\u3067\u4EA4\u308F\u308B\n    if (pow(abs(c1.r-c2.r),\
    \ 2) < d2 and d2 < pow(c1.r+c2.r, 2)) {\n        return 3;\n    }\n    // \u5916\
    \u63A5\u3059\u308B\n    if (d2 == pow(c1.r+c2.r, 2)) {\n        return 4;\n  \
    \  }\n    // 2\u5186\u304C\u96E2\u308C\u3066\u308B\n    if (d2 > pow(c1.r+c2.r,\
    \ 2)) {\n        return 5;\n    }\n    assert(0);\n}\n"
  dependsOn:
  - src/base.hpp
  - src/common/pow.hpp
  - src/macros.hpp
  - src/geometry/Circle.hpp
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/intersectCC.hpp
  requiredBy: []
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/intersectCC.hpp
layout: document
redirect_from:
- /library/src/geometry/intersectCC.hpp
- /library/src/geometry/intersectCC.hpp.html
title: src/geometry/intersectCC.hpp
---
