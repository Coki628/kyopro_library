---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/numbers/FastPrimeFactorization.hpp
    title: src/numbers/FastPrimeFactorization.hpp
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
    using namespace std;\n#line 3 \"src/common/sorted.hpp\"\n\ntemplate<typename T>\n\
    vector<T> sorted(vector<T> A, bool reverse = false) {\n    sort(ALL(A));\n   \
    \ if (reverse) std::reverse(ALL(A));\n    return A;\n}\n\nstring sorted(string\
    \ S, bool reverse = false) {\n    sort(ALL(S));\n    if (reverse) std::reverse(ALL(S));\n\
    \    return S;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<T>\
    \ sorted(vector<T> A, bool reverse = false) {\n    sort(ALL(A));\n    if (reverse)\
    \ std::reverse(ALL(A));\n    return A;\n}\n\nstring sorted(string S, bool reverse\
    \ = false) {\n    sort(ALL(S));\n    if (reverse) std::reverse(ALL(S));\n    return\
    \ S;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/sorted.hpp
  requiredBy:
  - src/template.hpp
  - src/numbers/FastPrimeFactorization.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/sorted.hpp
layout: document
redirect_from:
- /library/src/common/sorted.hpp
- /library/src/common/sorted.hpp.html
title: src/common/sorted.hpp
---
