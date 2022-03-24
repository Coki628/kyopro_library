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
  bundledCode: "#line 1 \"src/common/modulo.hpp\"\ntemplate<typename T>\nT modulo(T\
    \ a, T b) {\n    return ((a % b) + b) % b;\n}\n"
  code: "template<typename T>\nT modulo(T a, T b) {\n    return ((a % b) + b) % b;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/modulo.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/modulo.hpp
layout: document
redirect_from:
- /library/src/common/modulo.hpp
- /library/src/common/modulo.hpp.html
title: src/common/modulo.hpp
---
