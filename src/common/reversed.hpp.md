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
    using namespace std;\n#line 2 \"src/common/reversed.hpp\"\n\ntemplate<typename\
    \ T>\nvector<T> reversed(vector<T> A) {\n    reverse(ALL(A));\n    return A;\n\
    }\n\nstring reversed(string S) {\n    reverse(ALL(S));\n    return S;\n}\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<T> reversed(vector<T>\
    \ A) {\n    reverse(ALL(A));\n    return A;\n}\n\nstring reversed(string S) {\n\
    \    reverse(ALL(S));\n    return S;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/reversed.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/reversed.hpp
layout: document
redirect_from:
- /library/src/common/reversed.hpp
- /library/src/common/reversed.hpp.html
title: src/common/reversed.hpp
---