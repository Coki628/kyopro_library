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
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/common/chmin.hpp\"\n\ntemplate<typename T>\n\
    bool chmin(T &x, T y) {\n    return (y < x) ? x = y, true : false;\n}\n#line 3\
    \ \"src/common/min.hpp\"\n\ntemplate<typename T> T min(const vector<T> &A) {\n\
    \    return *min_element(ALL(A));\n}\n\ntemplate<typename key, typename val> val\
    \ min(const map<key, val> &mp) {\n    val res = numeric_limits<val>::max();\n\
    \    for (auto& [k, v] : mp) chmin(res, v);\n    return res;\n}\n"
  code: "#include \"../base.hpp\"\n#include \"chmin.hpp\"\n\ntemplate<typename T>\
    \ T min(const vector<T> &A) {\n    return *min_element(ALL(A));\n}\n\ntemplate<typename\
    \ key, typename val> val min(const map<key, val> &mp) {\n    val res = numeric_limits<val>::max();\n\
    \    for (auto& [k, v] : mp) chmin(res, v);\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/common/chmin.hpp
  isVerificationFile: false
  path: src/common/min.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/min.hpp
layout: document
redirect_from:
- /library/src/common/min.hpp
- /library/src/common/min.hpp.html
title: src/common/min.hpp
---
