---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/LIS.hpp
    title: src/common/LIS.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':x:'
    path: test/segment/Accumulate.test.cpp
    title: test/segment/Accumulate.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/bisect.hpp\"\n\ntemplate<typename T>\n\
    int bisect_left(const vector<T> &A, T val, int lo=0) {\n    return lower_bound(A.begin()+lo,\
    \ A.end(), val) - A.begin();\n}\n\ntemplate<typename T>\nint bisect_right(const\
    \ vector<T> &A, T val, int lo=0) {\n    return upper_bound(A.begin()+lo, A.end(),\
    \ val) - A.begin();\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename T>\nint bisect_left(const\
    \ vector<T> &A, T val, int lo=0) {\n    return lower_bound(A.begin()+lo, A.end(),\
    \ val) - A.begin();\n}\n\ntemplate<typename T>\nint bisect_right(const vector<T>\
    \ &A, T val, int lo=0) {\n    return upper_bound(A.begin()+lo, A.end(), val) -\
    \ A.begin();\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/bisect.hpp
  requiredBy:
  - src/common/LIS.hpp
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/segment/Accumulate.test.cpp
  - test/common/bisect.test.cpp
documentation_of: src/common/bisect.hpp
layout: document
redirect_from:
- /library/src/common/bisect.hpp
- /library/src/common/bisect.hpp.html
title: src/common/bisect.hpp
---
