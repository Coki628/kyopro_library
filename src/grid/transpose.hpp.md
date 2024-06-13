---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/string/RollingHash2D.hpp
    title: src/string/RollingHash2D.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/listnd.hpp\"\
    \n\n// \u4EFB\u610F\u6B21\u5143vector\n// \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
    template<typename... Ts>\nauto listnd(size_t N, Ts... ts) {\n    if constexpr\
    \ (sizeof...(ts) == 1) {\n        return vector<Ts...>(N, ts...);\n    } else\
    \ {\n        auto res = listnd(ts...);\n        return vector<decltype(res)>(N,\
    \ res);\n    }\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\ntemplate<typename T>[[deprecated(\"\
    list2d will be merged with listnd\")]] vv<T> list2d(int N, int M, T init) { return\
    \ listnd(N, M, init); }\ntemplate<typename T>[[deprecated(\"list3d will be merged\
    \ with listnd\")]] vv<vector<T>> list3d(int N, int M, int L, T init) { return\
    \ listnd(N, M, L, init); }\ntemplate<typename T>[[deprecated(\"list4d will be\
    \ merged with listnd\")]] vv<vv<T>> list4d(int N, int M, int L, int O, T init)\
    \ { return listnd(N, M, L, O, init); }\n#line 4 \"src/grid/transpose.hpp\"\n\n\
    // \u30B0\u30EA\u30C3\u30C9\u8EE2\u7F6E\ntemplate<typename T>\nvv<T> transpose(const\
    \ vv<T> &grid) {\n    int H = grid.size();\n    int W = grid[0].size();\n    auto\
    \ res = listnd(W, H, (T)0);\n    rep(i, H) {\n        rep(j, W) {\n          \
    \  res[j][i] = grid[i][j];\n        }\n    }\n    return res;\n}\n\n// \u30B0\u30EA\
    \u30C3\u30C9\u8EE2\u7F6E(\u6587\u5B57\u5217)\nvector<string> transpose(const vector<string>\
    \ &grid) {\n    int H = grid.size();\n    int W = grid[0].size();\n    vector<string>\
    \ res(W, string(H, '*'));\n    rep(i, H) {\n        rep(j, W) {\n            res[j][i]\
    \ = grid[i][j];\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../common/listnd.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u30B0\u30EA\u30C3\u30C9\u8EE2\u7F6E\ntemplate<typename T>\nvv<T> transpose(const\
    \ vv<T> &grid) {\n    int H = grid.size();\n    int W = grid[0].size();\n    auto\
    \ res = listnd(W, H, (T)0);\n    rep(i, H) {\n        rep(j, W) {\n          \
    \  res[j][i] = grid[i][j];\n        }\n    }\n    return res;\n}\n\n// \u30B0\u30EA\
    \u30C3\u30C9\u8EE2\u7F6E(\u6587\u5B57\u5217)\nvector<string> transpose(const vector<string>\
    \ &grid) {\n    int H = grid.size();\n    int W = grid[0].size();\n    vector<string>\
    \ res(W, string(H, '*'));\n    rep(i, H) {\n        rep(j, W) {\n            res[j][i]\
    \ = grid[i][j];\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/common/listnd.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/grid/transpose.hpp
  requiredBy:
  - src/string/RollingHash2D.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/transpose.hpp
layout: document
redirect_from:
- /library/src/grid/transpose.hpp
- /library/src/grid/transpose.hpp.html
title: src/grid/transpose.hpp
---
