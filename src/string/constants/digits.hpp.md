---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
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
  bundledCode: '#line 2 "src/base.hpp"

    #define _USE_MATH_DEFINES

    #include <bits/stdc++.h>

    using namespace std;

    #line 2 "src/string/constants/digits.hpp"


    const string digits = "0123456789";

    '
  code: '#include "../../base.hpp"


    const string digits = "0123456789";

    '
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/constants/digits.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/constants/digits.hpp
layout: document
redirect_from:
- /library/src/string/constants/digits.hpp
- /library/src/string/constants/digits.hpp.html
title: src/string/constants/digits.hpp
---
