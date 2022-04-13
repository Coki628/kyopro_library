---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    path: src/grid/bfs_restore.hpp
    title: src/grid/bfs_restore.hpp
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
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/listnd.hpp\"\n\ntemplate<typename T>\n\
    vector<vector<T>> list2d(int N, int M, T init) {\n    return vector<vector<T>>(N,\
    \ vector<T>(M, init));\n}\n\ntemplate<typename T>\nvector<vector<vector<T>>> list3d(int\
    \ N, int M, int L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M,\
    \ vector<T>(L, init)));\n}\n\ntemplate<typename T> \nvector<vector<vector<vector<T>>>>\
    \ list4d(int N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<vector<T>>\
    \ list2d(int N, int M, T init) {\n    return vector<vector<T>>(N, vector<T>(M,\
    \ init));\n}\n\ntemplate<typename T>\nvector<vector<vector<T>>> list3d(int N,\
    \ int M, int L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M,\
    \ vector<T>(L, init)));\n}\n\ntemplate<typename T> \nvector<vector<vector<vector<T>>>>\
    \ list4d(int N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/listnd.hpp
  requiredBy:
  - src/common/_doubling.hpp
  - src/common/Doubling.hpp
  - src/matrix/MatPow.hpp
  - src/matrix/mat_dot.hpp
  - src/template.hpp
  - src/string/get_next_indices.hpp
  - src/combinatorics/partition.hpp
  - src/combinatorics/nCr.hpp
  - src/grid/bfs.hpp
  - src/grid/transpose.hpp
  - src/grid/bfs_restore.hpp
  timestamp: '2022-04-06 17:44:14+09:00'
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
