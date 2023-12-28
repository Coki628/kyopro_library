---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/chmax.hpp
    title: src/common/chmax.hpp
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
    using namespace std;\n#line 2 \"src/common/chmax.hpp\"\n\ntemplate<typename T>\n\
    bool chmax(T &x, T y) {\n    return (y > x) ? x = y, true : false;\n}\n#line 4\
    \ \"src/common/max.hpp\"\n\ntemplate<typename T>\nT max(const vector<T> &A) {\n\
    \    assert(not A.empty());\n    return *max_element(ALL(A));\n}\n\ntemplate<typename\
    \ key, typename val>\nval max(const map<key, val> &mp) {\n    val res = numeric_limits<val>::min();\n\
    \    for (auto &[k, v] : mp) chmax(res, v);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"chmax.hpp\"\n\ntemplate<typename\
    \ T>\nT max(const vector<T> &A) {\n    assert(not A.empty());\n    return *max_element(ALL(A));\n\
    }\n\ntemplate<typename key, typename val>\nval max(const map<key, val> &mp) {\n\
    \    val res = numeric_limits<val>::min();\n    for (auto &[k, v] : mp) chmax(res,\
    \ v);\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/common/chmax.hpp
  isVerificationFile: false
  path: src/common/max.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/max.hpp
layout: document
redirect_from:
- /library/src/common/max.hpp
- /library/src/common/max.hpp.html
title: src/common/max.hpp
---
