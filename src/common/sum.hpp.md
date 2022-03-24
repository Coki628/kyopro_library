---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/sum.hpp
layout: document
redirect_from:
- /library/src/common/sum.hpp
- /library/src/common/sum.hpp.html
title: src/common/sum.hpp
---
