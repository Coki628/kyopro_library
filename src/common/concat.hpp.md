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
    using namespace std;\n#line 2 \"src/common/concat.hpp\"\n\ntemplate<typename T>\n\
    vector<T> concat(const vector<T>& A, const vector<T>& B) {\n    vector<T> res\
    \ = A;\n    res.insert(res.end(), B.begin(), B.end());\n    return res;\n}\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<T> concat(const\
    \ vector<T>& A, const vector<T>& B) {\n    vector<T> res = A;\n    res.insert(res.end(),\
    \ B.begin(), B.end());\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/concat.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-12-05 11:44:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/concat.hpp
layout: document
redirect_from:
- /library/src/common/concat.hpp
- /library/src/common/concat.hpp.html
title: src/common/concat.hpp
---
