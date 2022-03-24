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
  bundledCode: "#line 1 \"src/common/modulo.hpp\"\ntemplate<typename T>\nT modulo(T\
    \ a, T b) {\n    return ((a % b) + b) % b;\n}\n"
  code: "template<typename T>\nT modulo(T a, T b) {\n    return ((a % b) + b) % b;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/modulo.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/modulo.hpp
layout: document
redirect_from:
- /library/src/common/modulo.hpp
- /library/src/common/modulo.hpp.html
title: src/common/modulo.hpp
---
