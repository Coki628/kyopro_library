---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/random/rand_double.hpp
    title: src/random/rand_double.hpp
  - icon: ':warning:'
    path: src/random/rand_prime.hpp
    title: src/random/rand_prime.hpp
  - icon: ':warning:'
    path: src/random/randint.hpp
    title: src/random/randint.hpp
  - icon: ':warning:'
    path: src/random/randrange.hpp
    title: src/random/randrange.hpp
  - icon: ':warning:'
    path: src/random/sample.hpp
    title: src/random/sample.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/random/mt.hpp\"\n\n// \u30B7\u30FC\u30C9\u751F\
    \u6210\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u30B7\u30FC\u30C9\u751F\u6210\
    \nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/random/mt.hpp
  requiredBy:
  - src/random/rand_double.hpp
  - src/random/sample.hpp
  - src/random/rand_prime.hpp
  - src/random/randrange.hpp
  - src/random/randint.hpp
  timestamp: '2024-02-06 11:56:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/random/mt.hpp
layout: document
redirect_from:
- /library/src/random/mt.hpp
- /library/src/random/mt.hpp.html
title: src/random/mt.hpp
---
