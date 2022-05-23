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
    using namespace std;\n#line 2 \"src/common/subarray.hpp\"\n\ntemplate<typename\
    \ T>\nvector<T> subarray(const vector<T>& A, int l, int r) {\n    return vector<T>(A.begin()+l,\
    \ A.begin()+r);\n}\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<T> subarray(const\
    \ vector<T>& A, int l, int r) {\n    return vector<T>(A.begin()+l, A.begin()+r);\n\
    }\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/subarray.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-04-14 14:32:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/subarray.hpp
layout: document
redirect_from:
- /library/src/common/subarray.hpp
- /library/src/common/subarray.hpp.html
title: src/common/subarray.hpp
---
