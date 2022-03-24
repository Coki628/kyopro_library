---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
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
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/common/sum.hpp\"\n\ntemplate<typename T>\n\
    T sum(const vector<T> &A) {\n    return accumulate(ALL(A), (T)0);\n}\n\ntemplate<typename\
    \ key, typename val>\nval sum(const map<key, val> &mp) {\n    val res = 0;\n \
    \   for (auto& [k, v] : mp) res += v;\n    return res;\n}\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename T>\nT sum(const vector<T> &A)\
    \ {\n    return accumulate(ALL(A), (T)0);\n}\n\ntemplate<typename key, typename\
    \ val>\nval sum(const map<key, val> &mp) {\n    val res = 0;\n    for (auto& [k,\
    \ v] : mp) res += v;\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/sum.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/sum.hpp
layout: document
redirect_from:
- /library/src/common/sum.hpp
- /library/src/common/sum.hpp.html
title: src/common/sum.hpp
---
