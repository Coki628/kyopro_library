---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  bundledCode: "#line 1 \"src/common/ceil.hpp\"\ntemplate<typename T>\nT ceil(T a,\
    \ T b) {\n    if (a >= 0) return (a+b-1) / b;\n    else return a / b;\n}\n"
  code: "template<typename T>\nT ceil(T a, T b) {\n    if (a >= 0) return (a+b-1)\
    \ / b;\n    else return a / b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/ceil.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/ceil.hpp
layout: document
redirect_from:
- /library/src/common/ceil.hpp
- /library/src/common/ceil.hpp.html
title: src/common/ceil.hpp
---
