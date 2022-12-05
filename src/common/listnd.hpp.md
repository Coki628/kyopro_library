---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/combinatorics/nCr.hpp
    title: src/combinatorics/nCr.hpp
  - icon: ':warning:'
    path: src/combinatorics/partition.hpp
    title: src/combinatorics/partition.hpp
  - icon: ':warning:'
    path: src/common/Doubling.hpp
    title: src/common/Doubling.hpp
  - icon: ':warning:'
    path: src/common/_doubling.hpp
    title: src/common/_doubling.hpp
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
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/listnd.hpp\"\n\ntemplate<typename T>\n\
    vector<vector<T>> list2d(int N, int M, T init) {\n    return vector<vector<T>>(N,\
    \ vector<T>(M, init));\n}\n\ntemplate<typename T>\nvector<vector<vector<T>>> list3d(int\
    \ N, int M, int L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M,\
    \ vector<T>(L, init)));\n}\n\ntemplate<typename T> \nvector<vector<vector<vector<T>>>>\
    \ list4d(int N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n\
    \n// \u4EFB\u610F\u6B21\u5143vector\n// \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
    template<typename T>\nvector<T> listnd(size_t a, T b) {\n    return vector<T>(a,\
    \ b);\n}\n\ntemplate<typename... Ts>\nauto listnd(size_t a, Ts... ts) {\n    return\
    \ vector<decltype(listnd(ts...))>(a, listnd(ts...));\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<vector<T>>\
    \ list2d(int N, int M, T init) {\n    return vector<vector<T>>(N, vector<T>(M,\
    \ init));\n}\n\ntemplate<typename T>\nvector<vector<vector<T>>> list3d(int N,\
    \ int M, int L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M,\
    \ vector<T>(L, init)));\n}\n\ntemplate<typename T> \nvector<vector<vector<vector<T>>>>\
    \ list4d(int N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n\
    \n// \u4EFB\u610F\u6B21\u5143vector\n// \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
    template<typename T>\nvector<T> listnd(size_t a, T b) {\n    return vector<T>(a,\
    \ b);\n}\n\ntemplate<typename... Ts>\nauto listnd(size_t a, Ts... ts) {\n    return\
    \ vector<decltype(listnd(ts...))>(a, listnd(ts...));\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/listnd.hpp
  requiredBy:
  - src/grid/bfs01.hpp
  - src/grid/bfs.hpp
  - src/grid/dijkstra.hpp
  - src/grid/bfs_restore.hpp
  - src/grid/transpose.hpp
  - src/string/get_next_indices.hpp
  - src/combinatorics/nCr.hpp
  - src/combinatorics/partition.hpp
  - src/matrix/mat_dot.hpp
  - src/matrix/MatPow.hpp
  - src/common/_doubling.hpp
  - src/common/Doubling.hpp
  - src/template.hpp
  timestamp: '2022-08-29 14:43:01+09:00'
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
