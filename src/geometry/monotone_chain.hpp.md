---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/geometry/Point.hpp
    title: src/geometry/Point.hpp
  - icon: ':question:'
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
    \ p.y << '\\n';\n}\n#line 3 \"src/geometry/monotone_chain.hpp\"\n\n// \u30A2\u30F3\
    \u30C9\u30EA\u30E5\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0(Monotone Chain)\uFF1A\
    \u51F8\u5305\u306B\u4F7F\u3063\u305F\u5EA7\u6A19\u3068\u8DDD\u96E2\u3092\u8FD4\
    \u3059\ntemplate<typename T>\nvector<pair<Point<T>, ld>> monotone_chain(vector<Point<T>>\
    \ li) {\n    int N = li.size();\n    assert(N >= 2);\n\n    sort(ALL(li), [](Point<T>\
    \ a, Point<T> b) {\n        // \u30BD\u30FC\u30C8\u6761\u4EF6\u306By\u3082\u4F7F\
    \u3046\n        if (a.x == b.x) return a.y < b.y;\n        else return a.x < b.x;\
    \ \n    });\n\n    // \u4E0A\u534A\u5206\n    // \u4F7F\u3046\u5EA7\u6A19\u3068\
    \u8DDD\u96E2\u3092\u4FDD\u6301\n    vector<pair<Point<T>, ld>> stack;\n    stack.pb({li[0],\
    \ 0});\n    stack.pb({li[1], li[0].abs(li[1])});\n    rep(i, 2, N) {\n       \
    \ // 1\u3064\u524D->\u6B21 \u3068 1\u3064\u524D->2\u3064\u524D \u306E\u30D9\u30AF\
    \u30C8\u30EB\u3067\u5916\u7A4D\u3092\u30C1\u30A7\u30C3\u30AF\u3057\u3066\u5411\
    \u304D\u3092\u5224\u5B9A\u3059\u308B\n        while (stack.size() >= 2 and ccw(stack[stack.size()-2].first,\
    \ stack[stack.size()-1].first, li[i]) == 1) {\n            // \u6B21\u304C\u53CD\
    \u6642\u8A08\u56DE\u308A\u5074\u306B\u3042\u308B\u6642\u306F1\u3064\u524D\u3092\
    \u5916\u3059\n            stack.pop_back();\n        }\n        // \u6B21\u304C\
    \u6642\u8A08\u56DE\u308A\u5074\u306B\u3042\u308C\u3070OK\u306A\u306E\u3067\u9032\
    \u3081\u308B\n        stack.pb({li[i], stack.back().first.abs(li[i])});\n    }\n\
    \    vector<pair<Point<T>, ld>> res;\n    rep(i, 1, stack.size()) {\n        res.pb(stack[i]);\n\
    \    }\n\n    // \u4E0B\u534A\u5206(\u3084\u308B\u3053\u3068\u306F\u540C\u3058\
    )\n    stack.clear();\n    stack.pb({li[li.size()-1], 0});\n    stack.pb({li[li.size()-2],\
    \ li[li.size()-1].abs(li[li.size()-2])});\n    rrep(i, N-3, -1) {\n        while\
    \ (stack.size() >= 2 and ccw(stack[stack.size()-2].first, stack[stack.size()-1].first,\
    \ li[i]) == 1) {\n            stack.pop_back();\n        }\n        stack.pb({li[i],\
    \ stack.back().first.abs(li[i])});\n    }\n    rep(i, 1, stack.size()) {\n   \
    \     res.pb(stack[i]);\n    }\n    return res;\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"Point.hpp\"\n\n// \u30A2\u30F3\u30C9\
    \u30EA\u30E5\u30FC\u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0(Monotone Chain)\uFF1A\
    \u51F8\u5305\u306B\u4F7F\u3063\u305F\u5EA7\u6A19\u3068\u8DDD\u96E2\u3092\u8FD4\
    \u3059\ntemplate<typename T>\nvector<pair<Point<T>, ld>> monotone_chain(vector<Point<T>>\
    \ li) {\n    int N = li.size();\n    assert(N >= 2);\n\n    sort(ALL(li), [](Point<T>\
    \ a, Point<T> b) {\n        // \u30BD\u30FC\u30C8\u6761\u4EF6\u306By\u3082\u4F7F\
    \u3046\n        if (a.x == b.x) return a.y < b.y;\n        else return a.x < b.x;\
    \ \n    });\n\n    // \u4E0A\u534A\u5206\n    // \u4F7F\u3046\u5EA7\u6A19\u3068\
    \u8DDD\u96E2\u3092\u4FDD\u6301\n    vector<pair<Point<T>, ld>> stack;\n    stack.pb({li[0],\
    \ 0});\n    stack.pb({li[1], li[0].abs(li[1])});\n    rep(i, 2, N) {\n       \
    \ // 1\u3064\u524D->\u6B21 \u3068 1\u3064\u524D->2\u3064\u524D \u306E\u30D9\u30AF\
    \u30C8\u30EB\u3067\u5916\u7A4D\u3092\u30C1\u30A7\u30C3\u30AF\u3057\u3066\u5411\
    \u304D\u3092\u5224\u5B9A\u3059\u308B\n        while (stack.size() >= 2 and ccw(stack[stack.size()-2].first,\
    \ stack[stack.size()-1].first, li[i]) == 1) {\n            // \u6B21\u304C\u53CD\
    \u6642\u8A08\u56DE\u308A\u5074\u306B\u3042\u308B\u6642\u306F1\u3064\u524D\u3092\
    \u5916\u3059\n            stack.pop_back();\n        }\n        // \u6B21\u304C\
    \u6642\u8A08\u56DE\u308A\u5074\u306B\u3042\u308C\u3070OK\u306A\u306E\u3067\u9032\
    \u3081\u308B\n        stack.pb({li[i], stack.back().first.abs(li[i])});\n    }\n\
    \    vector<pair<Point<T>, ld>> res;\n    rep(i, 1, stack.size()) {\n        res.pb(stack[i]);\n\
    \    }\n\n    // \u4E0B\u534A\u5206(\u3084\u308B\u3053\u3068\u306F\u540C\u3058\
    )\n    stack.clear();\n    stack.pb({li[li.size()-1], 0});\n    stack.pb({li[li.size()-2],\
    \ li[li.size()-1].abs(li[li.size()-2])});\n    rrep(i, N-3, -1) {\n        while\
    \ (stack.size() >= 2 and ccw(stack[stack.size()-2].first, stack[stack.size()-1].first,\
    \ li[i]) == 1) {\n            stack.pop_back();\n        }\n        stack.pb({li[i],\
    \ stack.back().first.abs(li[i])});\n    }\n    rep(i, 1, stack.size()) {\n   \
    \     res.pb(stack[i]);\n    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/monotone_chain.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/monotone_chain.hpp
layout: document
redirect_from:
- /library/src/geometry/monotone_chain.hpp
- /library/src/geometry/monotone_chain.hpp.html
title: src/geometry/monotone_chain.hpp
---
