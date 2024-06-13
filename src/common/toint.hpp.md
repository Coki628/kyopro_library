---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/split.hpp
    title: src/common/split.hpp
  - icon: ':warning:'
    path: src/numbers/digit_sum.hpp
    title: src/numbers/digit_sum.hpp
  - icon: ':warning:'
    path: src/numbers/ntod.hpp
    title: src/numbers/ntod.hpp
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
    \ namespace std;\n#line 3 \"src/common/toint.hpp\"\n\nll toint(string s) {\n \
    \   // \u3053\u3093\u306A\u4FBF\u5229\u306A\u306E\u3042\u3063\u305F\u308F\u2026\
    \u3002\n    return stoll(s);\n}\n\nint toint(char num) {\n    return num - '0';\n\
    }\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nll toint(string s) {\n    // \u3053\
    \u3093\u306A\u4FBF\u5229\u306A\u306E\u3042\u3063\u305F\u308F\u2026\u3002\n   \
    \ return stoll(s);\n}\n\nint toint(char num) {\n    return num - '0';\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/toint.hpp
  requiredBy:
  - src/common/split.hpp
  - src/numbers/ntod.hpp
  - src/numbers/digit_sum.hpp
  - src/template.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/toint.hpp
layout: document
redirect_from:
- /library/src/common/toint.hpp
- /library/src/common/toint.hpp.html
title: src/common/toint.hpp
---
