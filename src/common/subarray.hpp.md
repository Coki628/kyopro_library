---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/RangeEdgedTwoSAT.hpp
    title: src/graph/RangeEdgedTwoSAT.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/common/subarray.hpp\"\n\n// \u914D\u5217\u306E\
    \u90E8\u5206\u5217\u53D6\u5F97\n// (\u672C\u5F53\u306F\u300Cslice\u300D\u304C\u4F7F\
    \u3044\u305F\u3044\u3093\u3060\u3051\u3069\u3001std::slice\u3068\u540D\u524D\u885D\
    \u7A81\u3059\u308B\u306E\u3067\u3068\u308A\u3042\u3048\u305Asubarray\u306B\u3057\
    \u3066\u304A\u304F\u3002)\ntemplate<typename T>\nvector<T> subarray(const vector<T>\
    \ &A, int l, int r) {\n    return vector<T>(A.begin() + l, A.begin() + r);\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u914D\u5217\u306E\u90E8\u5206\
    \u5217\u53D6\u5F97\n// (\u672C\u5F53\u306F\u300Cslice\u300D\u304C\u4F7F\u3044\u305F\
    \u3044\u3093\u3060\u3051\u3069\u3001std::slice\u3068\u540D\u524D\u885D\u7A81\u3059\
    \u308B\u306E\u3067\u3068\u308A\u3042\u3048\u305Asubarray\u306B\u3057\u3066\u304A\
    \u304F\u3002)\ntemplate<typename T>\nvector<T> subarray(const vector<T> &A, int\
    \ l, int r) {\n    return vector<T>(A.begin() + l, A.begin() + r);\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/subarray.hpp
  requiredBy:
  - src/template.hpp
  - src/graph/RangeEdgedTwoSAT.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/subarray.hpp
layout: document
redirect_from:
- /library/src/common/subarray.hpp
- /library/src/common/subarray.hpp.html
title: src/common/subarray.hpp
---
