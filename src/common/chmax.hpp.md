---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/max.hpp
    title: src/common/max.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':warning:'
    path: src/common/yesno.hpp
    title: src/common/yesno.hpp
  - icon: ':warning:'
    path: src/graph/TreeHash.hpp
    title: src/graph/TreeHash.hpp
  - icon: ':warning:'
    path: src/graph/_AuxiliaryTree.hpp
    title: src/graph/_AuxiliaryTree.hpp
  - icon: ':warning:'
    path: src/math/FormalPowerSeries.hpp
    title: src/math/FormalPowerSeries.hpp
  - icon: ':warning:'
    path: src/math/fps/pow.hpp
    title: src/math/fps/pow.hpp
  - icon: ':warning:'
    path: src/math/fps/pow_term2.hpp
    title: src/math/fps/pow_term2.hpp
  - icon: ':warning:'
    path: src/mystl/Deque.hpp
    title: src/mystl/Deque.hpp
  - icon: ':warning:'
    path: src/mystl/Multiset.hpp
    title: src/mystl/Multiset.hpp
  - icon: ':warning:'
    path: src/mystl/Set.hpp
    title: src/mystl/Set.hpp
  - icon: ':warning:'
    path: src/mystl/Vector.hpp
    title: src/mystl/Vector.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/UnionFind.test.cpp
    title: test/graph/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/WeightedUnionFind.test.cpp
    title: test/graph/WeightedUnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/MatPow.test.cpp
    title: test/matrix/MatPow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/common/chmax.hpp\"\n\ntemplate<typename T>\nbool chmax(T\
    \ &x, T y) {\n    return (y > x) ? x = y, true : false;\n}\n"
  code: "#pragma once\n\ntemplate<typename T>\nbool chmax(T &x, T y) {\n    return\
    \ (y > x) ? x = y, true : false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/chmax.hpp
  requiredBy:
  - src/graph/TreeHash.hpp
  - src/graph/_AuxiliaryTree.hpp
  - src/math/fps/pow_term2.hpp
  - src/math/fps/pow.hpp
  - src/math/FormalPowerSeries.hpp
  - src/template.hpp
  - src/mystl/Set.hpp
  - src/mystl/Multiset.hpp
  - src/mystl/Vector.hpp
  - src/mystl/Deque.hpp
  - src/common/print.hpp
  - src/common/max.hpp
  - src/common/yesno.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bfs.test.cpp
  - test/graph/WeightedUnionFind.test.cpp
  - test/graph/UnionFind.test.cpp
  - test/matrix/MatPow.test.cpp
  - test/common/bisect.test.cpp
documentation_of: src/common/chmax.hpp
layout: document
redirect_from:
- /library/src/common/chmax.hpp
- /library/src/common/chmax.hpp.html
title: src/common/chmax.hpp
---
