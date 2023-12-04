---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/string/constants/ascii_letters.hpp
    title: src/string/constants/ascii_letters.hpp
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

    #line 3 "src/string/constants/ascii_uppercase.hpp"


    const string ascii_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    '
  code: '#pragma once

    #include "../../base.hpp"


    const string ascii_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    '
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/constants/ascii_uppercase.hpp
  requiredBy:
  - src/string/constants/ascii_letters.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/constants/ascii_uppercase.hpp
layout: document
redirect_from:
- /library/src/string/constants/ascii_uppercase.hpp
- /library/src/string/constants/ascii_uppercase.hpp.html
title: src/string/constants/ascii_uppercase.hpp
---
