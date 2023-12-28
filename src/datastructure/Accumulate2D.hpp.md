---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/Accumulate2D.hpp\"\
    \n\n// 2\u6B21\u5143\u7D2F\u7A4D\u548C\ntemplate<typename T>\nclass Accumulate2D\
    \ {\n    int H;\n    int W;\n    vv<T> dat;\n\n    void build(const vv<T> &grid)\
    \ {\n        rep(i, H) {\n            rep(j, W) {\n                dat[i + 1][j\
    \ + 1] = grid[i][j];\n            }\n        }\n        rep(i, H + 1) {\n    \
    \        rep(j, W) {\n                dat[i][j + 1] += dat[i][j];\n          \
    \  }\n        }\n        rep(j, W + 1) {\n            rep(i, H) {\n          \
    \      dat[i + 1][j] += dat[i][j];\n            }\n        }\n    }\n\npublic:\n\
    \    Accumulate2D(const vv<T> &grid) : H(grid.size()), W(grid[0].size()) {\n \
    \       dat.resize(H + 1, vector<T>(W + 1, 0));\n        build(grid);\n    }\n\
    \n    Accumulate2D(int H, int W) : H(H), W(W) {\n        dat.resize(H + 1, vector<T>(W\
    \ + 1, 0));\n    }\n\n    void set(int h, int w, T x) {\n        dat[h + 1][w\
    \ + 1] = x;\n    }\n\n    void add(int h, int w, T x) {\n        dat[h + 1][w\
    \ + 1] += x;\n    }\n\n    void build() {\n        rep(i, H + 1) {\n         \
    \   rep(j, W) {\n                dat[i][j + 1] += dat[i][j];\n            }\n\
    \        }\n        rep(j, W + 1) {\n            rep(i, H) {\n               \
    \ dat[i + 1][j] += dat[i][j];\n            }\n        }\n    }\n\n    // [(h1,w1),(h2,w2))\u306E\
    \u533A\u9593\u548C\n    T query(int h1, int w1, int h2, int w2) {\n        if\
    \ (h1 >= h2 or w1 >= w2) return (T)0;\n        return dat[h1][w1] - dat[h1][w2]\
    \ - dat[h2][w1] + dat[h2][w2];\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// 2\u6B21\u5143\u7D2F\u7A4D\u548C\
    \ntemplate<typename T>\nclass Accumulate2D {\n    int H;\n    int W;\n    vv<T>\
    \ dat;\n\n    void build(const vv<T> &grid) {\n        rep(i, H) {\n         \
    \   rep(j, W) {\n                dat[i + 1][j + 1] = grid[i][j];\n           \
    \ }\n        }\n        rep(i, H + 1) {\n            rep(j, W) {\n           \
    \     dat[i][j + 1] += dat[i][j];\n            }\n        }\n        rep(j, W\
    \ + 1) {\n            rep(i, H) {\n                dat[i + 1][j] += dat[i][j];\n\
    \            }\n        }\n    }\n\npublic:\n    Accumulate2D(const vv<T> &grid)\
    \ : H(grid.size()), W(grid[0].size()) {\n        dat.resize(H + 1, vector<T>(W\
    \ + 1, 0));\n        build(grid);\n    }\n\n    Accumulate2D(int H, int W) : H(H),\
    \ W(W) {\n        dat.resize(H + 1, vector<T>(W + 1, 0));\n    }\n\n    void set(int\
    \ h, int w, T x) {\n        dat[h + 1][w + 1] = x;\n    }\n\n    void add(int\
    \ h, int w, T x) {\n        dat[h + 1][w + 1] += x;\n    }\n\n    void build()\
    \ {\n        rep(i, H + 1) {\n            rep(j, W) {\n                dat[i][j\
    \ + 1] += dat[i][j];\n            }\n        }\n        rep(j, W + 1) {\n    \
    \        rep(i, H) {\n                dat[i + 1][j] += dat[i][j];\n          \
    \  }\n        }\n    }\n\n    // [(h1,w1),(h2,w2))\u306E\u533A\u9593\u548C\n \
    \   T query(int h1, int w1, int h2, int w2) {\n        if (h1 >= h2 or w1 >= w2)\
    \ return (T)0;\n        return dat[h1][w1] - dat[h1][w2] - dat[h2][w1] + dat[h2][w2];\n\
    \    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/Accumulate2D.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/Accumulate2D.hpp
layout: document
redirect_from:
- /library/src/datastructure/Accumulate2D.hpp
- /library/src/datastructure/Accumulate2D.hpp.html
title: src/datastructure/Accumulate2D.hpp
---
