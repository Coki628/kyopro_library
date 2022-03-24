---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"src/common/ceil.hpp\"\ntemplate<typename T>\nT ceil(T a,\
    \ T b) {\n    if (a >= 0) return (a+b-1) / b;\n    else return a / b;\n}\n"
  code: "template<typename T>\nT ceil(T a, T b) {\n    if (a >= 0) return (a+b-1)\
    \ / b;\n    else return a / b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/ceil.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/ceil.hpp
layout: document
redirect_from:
- /library/src/common/ceil.hpp
- /library/src/common/ceil.hpp.html
title: src/common/ceil.hpp
---
