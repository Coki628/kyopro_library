---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/random/mt.hpp
    title: src/random/mt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.albow.net/entry/random-range/
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/random/mt.hpp\"\n\n// \u30B7\u30FC\u30C9\u751F\
    \u6210\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    #line 4 \"src/random/rand_double.hpp\"\n\n// \u7BC4\u56F2[l,r)\u304B\u3089\u30E9\
    \u30F3\u30C0\u30E0\u3067\u5B9F\u6570\u306E\u5024\u3092\u8FD4\u3059\n// see: https://www.albow.net/entry/random-range/\n\
    double rand_double(double l, double r) {\n    uniform_real_distribution<double>\
    \ dist(l, r);\n    return dist(mt);\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"mt.hpp\"\n\n// \u7BC4\u56F2\
    [l,r)\u304B\u3089\u30E9\u30F3\u30C0\u30E0\u3067\u5B9F\u6570\u306E\u5024\u3092\u8FD4\
    \u3059\n// see: https://www.albow.net/entry/random-range/\ndouble rand_double(double\
    \ l, double r) {\n    uniform_real_distribution<double> dist(l, r);\n    return\
    \ dist(mt);\n}\n"
  dependsOn:
  - src/base.hpp
  - src/random/mt.hpp
  isVerificationFile: false
  path: src/random/rand_double.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/random/rand_double.hpp
layout: document
redirect_from:
- /library/src/random/rand_double.hpp
- /library/src/random/rand_double.hpp.html
title: src/random/rand_double.hpp
---
