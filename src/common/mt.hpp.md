---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/randrange.hpp
    title: src/common/randrange.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/mt.hpp\"\n\n// \u30B7\u30FC\u30C9\u751F\
    \u6210\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u30B7\u30FC\u30C9\u751F\u6210\
    \nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/mt.hpp
  requiredBy:
  - src/common/randrange.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/mt.hpp
layout: document
redirect_from:
- /library/src/common/mt.hpp
- /library/src/common/mt.hpp.html
title: src/common/mt.hpp
---
