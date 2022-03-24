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
  bundledCode: "#line 1 \"src/common/tochar.hpp\"\nchar tochar(int num) {\n    return\
    \ '0' + num;\n}\n"
  code: "char tochar(int num) {\n    return '0' + num;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/tochar.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/tochar.hpp
layout: document
redirect_from:
- /library/src/common/tochar.hpp
- /library/src/common/tochar.hpp.html
title: src/common/tochar.hpp
---
