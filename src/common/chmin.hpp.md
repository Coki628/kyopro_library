---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/min.hpp
    title: src/common/min.hpp
  - icon: ':warning:'
    path: src/graph/Dijkstra.hpp
    title: src/graph/Dijkstra.hpp
  - icon: ':warning:'
    path: src/graph/_dijkstra.hpp
    title: src/graph/_dijkstra.hpp
  - icon: ':warning:'
    path: src/graph/bellman_ford.hpp
    title: src/graph/bellman_ford.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/bfs.hpp
    title: src/graph/bfs.hpp
  - icon: ':warning:'
    path: src/graph/bfs01.hpp
    title: src/graph/bfs01.hpp
  - icon: ':warning:'
    path: src/graph/dijkstra.hpp
    title: src/graph/dijkstra.hpp
  - icon: ':warning:'
    path: src/graph/get_diameter.hpp
    title: src/graph/get_diameter.hpp
  - icon: ':warning:'
    path: src/graph/warshall_floyd.hpp
    title: src/graph/warshall_floyd.hpp
  - icon: ':warning:'
    path: src/grid/dijkstra.hpp
    title: src/grid/dijkstra.hpp
  - icon: ':warning:'
    path: src/numbers/XorBasis.hpp
    title: src/numbers/XorBasis.hpp
  - icon: ':warning:'
    path: src/numbers/_xor_basis.hpp
    title: src/numbers/_xor_basis.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/common/chmin.hpp\"\n\ntemplate<typename T>\nbool chmin(T\
    \ &x, T y) {\n    return (y < x) ? x = y, true : false;\n}\n"
  code: "#pragma once\n\ntemplate<typename T>\nbool chmin(T &x, T y) {\n    return\
    \ (y < x) ? x = y, true : false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/chmin.hpp
  requiredBy:
  - src/numbers/XorBasis.hpp
  - src/numbers/_xor_basis.hpp
  - src/template.hpp
  - src/common/min.hpp
  - src/grid/dijkstra.hpp
  - src/graph/dijkstra.hpp
  - src/graph/warshall_floyd.hpp
  - src/graph/bfs01.hpp
  - src/graph/bellman_ford.hpp
  - src/graph/_dijkstra.hpp
  - src/graph/get_diameter.hpp
  - src/graph/Dijkstra.hpp
  - src/graph/bfs.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bfs.test.cpp
documentation_of: src/common/chmin.hpp
layout: document
redirect_from:
- /library/src/common/chmin.hpp
- /library/src/common/chmin.hpp.html
title: src/common/chmin.hpp
---
