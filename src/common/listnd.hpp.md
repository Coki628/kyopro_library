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
    path: src/combinatorics/bell.hpp
    title: src/combinatorics/bell.hpp
  - icon: ':warning:'
    path: src/combinatorics/nCr.hpp
    title: src/combinatorics/nCr.hpp
  - icon: ':warning:'
    path: src/combinatorics/partition.hpp
    title: src/combinatorics/partition.hpp
  - icon: ':warning:'
    path: src/combinatorics/stirling.hpp
    title: src/combinatorics/stirling.hpp
  - icon: ':warning:'
    path: src/datastructure/Doubling.hpp
    title: src/datastructure/Doubling.hpp
  - icon: ':warning:'
    path: src/datastructure/_doubling.hpp
    title: src/datastructure/_doubling.hpp
  - icon: ':warning:'
    path: src/grid/bfs.hpp
    title: src/grid/bfs.hpp
  - icon: ':warning:'
    path: src/grid/bfs01.hpp
    title: src/grid/bfs01.hpp
  - icon: ':warning:'
    path: src/grid/bfs_restore.hpp
    title: src/grid/bfs_restore.hpp
  - icon: ':warning:'
    path: src/grid/dijkstra.hpp
    title: src/grid/dijkstra.hpp
  - icon: ':warning:'
    path: src/grid/transpose.hpp
    title: src/grid/transpose.hpp
  - icon: ':heavy_check_mark:'
    path: src/matrix/MatPow.hpp
    title: src/matrix/MatPow.hpp
  - icon: ':heavy_check_mark:'
    path: src/matrix/mat_dot.hpp
    title: src/matrix/mat_dot.hpp
  - icon: ':warning:'
    path: src/string/RollingHash2D.hpp
    title: src/string/RollingHash2D.hpp
  - icon: ':warning:'
    path: src/string/get_next_indices.hpp
    title: src/string/get_next_indices.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix/MatPow.test.cpp
    title: test/matrix/MatPow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp
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
    \ { return listnd(N, M, L, O, init); }\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u4EFB\u610F\u6B21\u5143vector\n\
    // \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
    template<typename... Ts>\nauto listnd(size_t N, Ts... ts) {\n    if constexpr\
    \ (sizeof...(ts) == 1) {\n        return vector<Ts...>(N, ts...);\n    } else\
    \ {\n        auto res = listnd(ts...);\n        return vector<decltype(res)>(N,\
    \ res);\n    }\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\ntemplate<typename T>[[deprecated(\"\
    list2d will be merged with listnd\")]] vv<T> list2d(int N, int M, T init) { return\
    \ listnd(N, M, init); }\ntemplate<typename T>[[deprecated(\"list3d will be merged\
    \ with listnd\")]] vv<vector<T>> list3d(int N, int M, int L, T init) { return\
    \ listnd(N, M, L, init); }\ntemplate<typename T>[[deprecated(\"list4d will be\
    \ merged with listnd\")]] vv<vv<T>> list4d(int N, int M, int L, int O, T init)\
    \ { return listnd(N, M, L, O, init); }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/listnd.hpp
  requiredBy:
  - src/string/get_next_indices.hpp
  - src/string/RollingHash2D.hpp
  - src/template.hpp
  - src/datastructure/Doubling.hpp
  - src/datastructure/_doubling.hpp
  - src/matrix/mat_dot.hpp
  - src/matrix/MatPow.hpp
  - src/combinatorics/nCr.hpp
  - src/combinatorics/stirling.hpp
  - src/combinatorics/partition.hpp
  - src/combinatorics/bell.hpp
  - src/grid/bfs01.hpp
  - src/grid/bfs_restore.hpp
  - src/grid/bfs.hpp
  - src/grid/dijkstra.hpp
  - src/grid/transpose.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/MatPow.test.cpp
documentation_of: src/common/listnd.hpp
layout: document
redirect_from:
- /library/src/common/listnd.hpp
- /library/src/common/listnd.hpp.html
title: src/common/listnd.hpp
---
