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
  bundledCode: "#line 1 \"src/combinatorics/factorial.hpp\"\n// \u968E\u4E57\uFF1A\
    O(N)\ntemplate<typename T>\nT factorial(int x) {\n    T res = 1;\n    for (int\
    \ i=1; i<=x; i++) res *= i;\n    return res;\n}\n"
  code: "// \u968E\u4E57\uFF1AO(N)\ntemplate<typename T>\nT factorial(int x) {\n \
    \   T res = 1;\n    for (int i=1; i<=x; i++) res *= i;\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/combinatorics/factorial.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/combinatorics/factorial.hpp
layout: document
redirect_from:
- /library/src/combinatorics/factorial.hpp
- /library/src/combinatorics/factorial.hpp.html
title: src/combinatorics/factorial.hpp
---
