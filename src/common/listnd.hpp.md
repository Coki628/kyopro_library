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
    path: src/grid/transpose.hpp
    title: src/grid/transpose.hpp
  - icon: ':warning:'
    path: src/matrix/MatPow.hpp
    title: src/matrix/MatPow.hpp
  - icon: ':warning:'
    path: src/matrix/mat_dot.hpp
    title: src/matrix/mat_dot.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/segment/Accumulate.test.cpp
    title: test/segment/Accumulate.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/listnd.hpp\"\n\ntemplate<typename T>\
    \ vector<vector<T>> list2d(int N, int M, T init) {\n    return vector<vector<T>>(N,\
    \ vector<T>(M, init));\n}\n\ntemplate<typename T> vector<vector<vector<T>>> list3d(int\
    \ N, int M, int L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M,\
    \ vector<T>(L, init)));\n}\n\ntemplate<typename T> vector<vector<vector<vector<T>>>>\
    \ list4d(int N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename T> vector<vector<T>>\
    \ list2d(int N, int M, T init) {\n    return vector<vector<T>>(N, vector<T>(M,\
    \ init));\n}\n\ntemplate<typename T> vector<vector<vector<T>>> list3d(int N, int\
    \ M, int L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M,\
    \ vector<T>(L, init)));\n}\n\ntemplate<typename T> vector<vector<vector<vector<T>>>>\
    \ list4d(int N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/listnd.hpp
  requiredBy:
  - src/matrix/mat_dot.hpp
  - src/matrix/MatPow.hpp
  - src/combinatorics/partition.hpp
  - src/combinatorics/nCr.hpp
  - src/common/Doubling.hpp
  - src/common/_doubling.hpp
  - src/grid/transpose.hpp
  - src/grid/bfs.hpp
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/segment/Accumulate.test.cpp
documentation_of: src/common/listnd.hpp
layout: document
redirect_from:
- /library/src/common/listnd.hpp
- /library/src/common/listnd.hpp.html
title: src/common/listnd.hpp
---
