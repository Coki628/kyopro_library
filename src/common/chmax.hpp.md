---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/common/max.hpp
    title: src/common/max.hpp
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
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
  - src/common/max.hpp
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/chmax.hpp
layout: document
redirect_from:
- /library/src/common/chmax.hpp
- /library/src/common/chmax.hpp.html
title: src/common/chmax.hpp
---
