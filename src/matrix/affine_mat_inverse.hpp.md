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
    - http://sssiii.seesaa.net/upload/detail/image/affine_004.PNG.html
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/matrix/affine_mat_inverse.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttp://sssiii.seesaa.net/upload/detail/image/affine_004.PNG.html\n// \u30A2\
    \u30D5\u30A3\u30F3\u884C\u5217\u306E\u9006\u884C\u5217\ntemplate<typename T>\n\
    vector<vector<T>> affine_mat_inverse(const vector<vector<T>> &a) {\n    auto res\
    \ = a;\n    res[0][0] *= -1;\n    res[1][1] *= -1;\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttp://sssiii.seesaa.net/upload/detail/image/affine_004.PNG.html\n\
    // \u30A2\u30D5\u30A3\u30F3\u884C\u5217\u306E\u9006\u884C\u5217\ntemplate<typename\
    \ T>\nvector<vector<T>> affine_mat_inverse(const vector<vector<T>> &a) {\n   \
    \ auto res = a;\n    res[0][0] *= -1;\n    res[1][1] *= -1;\n    return res;\n\
    }\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/matrix/affine_mat_inverse.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/matrix/affine_mat_inverse.hpp
layout: document
redirect_from:
- /library/src/matrix/affine_mat_inverse.hpp
- /library/src/matrix/affine_mat_inverse.hpp.html
title: src/matrix/affine_mat_inverse.hpp
---
