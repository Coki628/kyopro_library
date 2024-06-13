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
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/string/isdigit.hpp\"\n\nbool isdigit(string S)\
    \ {\n    for (auto c : S) {\n        if (not isdigit(c)) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nbool isdigit(string S) {\n    for\
    \ (auto c : S) {\n        if (not isdigit(c)) {\n            return false;\n \
    \       }\n    }\n    return true;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/isdigit.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/isdigit.hpp
layout: document
redirect_from:
- /library/src/string/isdigit.hpp
- /library/src/string/isdigit.hpp.html
title: src/string/isdigit.hpp
---
