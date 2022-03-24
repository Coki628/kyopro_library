---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/common/min.hpp
    title: src/common/min.hpp
  - icon: ':warning:'
    path: src/graph/Dijkstra.hpp
    title: src/graph/Dijkstra.hpp
  - icon: ':warning:'
    path: src/graph/_dijkstra.hpp
    title: src/graph/_dijkstra.hpp
  - icon: ':x:'
    path: src/graph/bfs.hpp
    title: src/graph/bfs.hpp
  - icon: ':warning:'
    path: src/graph/bfs01.hpp
    title: src/graph/bfs01.hpp
  - icon: ':warning:'
    path: src/graph/warshall_floyd.hpp
    title: src/graph/warshall_floyd.hpp
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':x:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - src/common/min.hpp
  - src/graph/Dijkstra.hpp
  - src/graph/bfs.hpp
  - src/graph/warshall_floyd.hpp
  - src/graph/_dijkstra.hpp
  - src/graph/bfs01.hpp
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/chmin.hpp
layout: document
redirect_from:
- /library/src/common/chmin.hpp
- /library/src/common/chmin.hpp.html
title: src/common/chmin.hpp
---
