---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/constants/ascii_lowercase.hpp
    title: src/string/constants/ascii_lowercase.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/constants/ascii_uppercase.hpp
    title: src/string/constants/ascii_uppercase.hpp
  _extendedRequiredBy: []
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

    #line 3 "src/string/constants/ascii_lowercase.hpp"


    const string ascii_lowercase = "abcdefghijklmnopqrstuvwxyz";

    #line 3 "src/string/constants/ascii_uppercase.hpp"


    const string ascii_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    #line 4 "src/string/constants/ascii_letters.hpp"


    const string ascii_letters = ascii_lowercase + ascii_uppercase;

    '
  code: '#include "../../base.hpp"

    #include "ascii_lowercase.hpp"

    #include "ascii_uppercase.hpp"


    const string ascii_letters = ascii_lowercase + ascii_uppercase;

    '
  dependsOn:
  - src/base.hpp
  - src/string/constants/ascii_lowercase.hpp
  - src/string/constants/ascii_uppercase.hpp
  isVerificationFile: false
  path: src/string/constants/ascii_letters.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/constants/ascii_letters.hpp
layout: document
redirect_from:
- /library/src/string/constants/ascii_letters.hpp
- /library/src/string/constants/ascii_letters.hpp.html
title: src/string/constants/ascii_letters.hpp
---
