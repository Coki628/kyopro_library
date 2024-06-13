---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/Compress.hpp
    title: src/common/Compress.hpp
  - icon: ':warning:'
    path: src/common/LIS.hpp
    title: src/common/LIS.hpp
  - icon: ':warning:'
    path: src/datastructure/get_inversion.hpp
    title: src/datastructure/get_inversion.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/common/bisect.hpp\"\n\ntemplate<typename T>\n\
    int bisect_left(const vector<T> &A, T val, int lo = 0) {\n    return lower_bound(A.begin()\
    \ + lo, A.end(), val) - A.begin();\n}\n\ntemplate<typename T>\nint bisect_right(const\
    \ vector<T> &A, T val, int lo = 0) {\n    return upper_bound(A.begin() + lo, A.end(),\
    \ val) - A.begin();\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename T>\nint bisect_left(const\
    \ vector<T> &A, T val, int lo = 0) {\n    return lower_bound(A.begin() + lo, A.end(),\
    \ val) - A.begin();\n}\n\ntemplate<typename T>\nint bisect_right(const vector<T>\
    \ &A, T val, int lo = 0) {\n    return upper_bound(A.begin() + lo, A.end(), val)\
    \ - A.begin();\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/bisect.hpp
  requiredBy:
  - src/datastructure/get_inversion.hpp
  - src/common/Compress.hpp
  - src/common/LIS.hpp
  - src/template.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/common/bisect.test.cpp
documentation_of: src/common/bisect.hpp
layout: document
redirect_from:
- /library/src/common/bisect.hpp
- /library/src/common/bisect.hpp.html
title: src/common/bisect.hpp
---
