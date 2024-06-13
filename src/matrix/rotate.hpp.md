---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://imagingsolution.net/math/rotate-around-point/
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/matrix/rotate.hpp\"\n\n// (x, y)\u3092\u4E2D\u5FC3\
    \u306B\u6642\u8A08\u56DE\u308A90\u5EA6\u56DE\u8EE2\n// \u53C2\u8003\uFF1Ahttps://imagingsolution.net/math/rotate-around-point/\n\
    template<typename T>\nvector<vector<T>> rot90(T x, T y) {\n    const vector<vector<T>>\
    \ res = {\n        {0, 1, x - y},\n        {-1, 0, y + x},\n        {0, 0, 1},\n\
    \    };\n    return res;\n}\n// (x, y)\u3092\u4E2D\u5FC3\u306B\u53CD\u6642\u8A08\
    \u56DE\u308A90\u5EA6\u56DE\u8EE2\ntemplate<typename T>\nvector<vector<T>> rot270(T\
    \ x, T y) {\n    const vector<vector<T>> res = {\n        {0, -1, x + y},\n  \
    \      {1, 0, y - x},\n        {0, 0, 1},\n    };\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// (x, y)\u3092\u4E2D\u5FC3\u306B\
    \u6642\u8A08\u56DE\u308A90\u5EA6\u56DE\u8EE2\n// \u53C2\u8003\uFF1Ahttps://imagingsolution.net/math/rotate-around-point/\n\
    template<typename T>\nvector<vector<T>> rot90(T x, T y) {\n    const vector<vector<T>>\
    \ res = {\n        {0, 1, x - y},\n        {-1, 0, y + x},\n        {0, 0, 1},\n\
    \    };\n    return res;\n}\n// (x, y)\u3092\u4E2D\u5FC3\u306B\u53CD\u6642\u8A08\
    \u56DE\u308A90\u5EA6\u56DE\u8EE2\ntemplate<typename T>\nvector<vector<T>> rot270(T\
    \ x, T y) {\n    const vector<vector<T>> res = {\n        {0, -1, x + y},\n  \
    \      {1, 0, y - x},\n        {0, 0, 1},\n    };\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/matrix/rotate.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/matrix/rotate.hpp
layout: document
redirect_from:
- /library/src/matrix/rotate.hpp
- /library/src/matrix/rotate.hpp.html
title: src/matrix/rotate.hpp
---
