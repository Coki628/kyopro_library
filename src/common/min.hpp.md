---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
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
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 2 \"src/common/chmin.hpp\"\n\ntemplate<typename T>\nbool\
    \ chmin(T &x, T y) {\n    return (y < x) ? x = y, true : false;\n}\n#line 4 \"\
    src/common/min.hpp\"\n\ntemplate<typename T>\nT min(const vector<T> &A) {\n  \
    \  assert(not A.empty());\n    return *min_element(ALL(A));\n}\n\ntemplate<typename\
    \ key, typename val>\nval min(const map<key, val> &mp) {\n    val res = numeric_limits<val>::max();\n\
    \    for (auto &[k, v] : mp) chmin(res, v);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"chmin.hpp\"\n\ntemplate<typename\
    \ T>\nT min(const vector<T> &A) {\n    assert(not A.empty());\n    return *min_element(ALL(A));\n\
    }\n\ntemplate<typename key, typename val>\nval min(const map<key, val> &mp) {\n\
    \    val res = numeric_limits<val>::max();\n    for (auto &[k, v] : mp) chmin(res,\
    \ v);\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/common/chmin.hpp
  isVerificationFile: false
  path: src/common/min.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/min.hpp
layout: document
redirect_from:
- /library/src/common/min.hpp
- /library/src/common/min.hpp.html
title: src/common/min.hpp
---
