---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/common/floor.hpp\"\n\ntemplate<typename T>\nT floor(T\
    \ a, T b) {\n    if (a < 0) return (a - b + 1) / b;\n    else return a / b;\n\
    }\n"
  code: "#pragma once\n\ntemplate<typename T>\nT floor(T a, T b) {\n    if (a < 0)\
    \ return (a - b + 1) / b;\n    else return a / b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/floor.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/floor.hpp
layout: document
redirect_from:
- /library/src/common/floor.hpp
- /library/src/common/floor.hpp.html
title: src/common/floor.hpp
---
