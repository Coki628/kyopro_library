---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/string/constants/ascii_letters.hpp
    title: src/string/constants/ascii_letters.hpp
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "src/base.hpp"

    #define _USE_MATH_DEFINES

    #include <bits/stdc++.h>

    using namespace std;

    #line 3 "src/string/constants/ascii_lowercase.hpp"


    const string ascii_lowercase = "abcdefghijklmnopqrstuvwxyz";

    '
  code: '#pragma once

    #include "../../base.hpp"


    const string ascii_lowercase = "abcdefghijklmnopqrstuvwxyz";

    '
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/constants/ascii_lowercase.hpp
  requiredBy:
  - src/string/constants/ascii_letters.hpp
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/string/constants/ascii_lowercase.hpp
layout: document
redirect_from:
- /library/src/string/constants/ascii_lowercase.hpp
- /library/src/string/constants/ascii_lowercase.hpp.html
title: src/string/constants/ascii_lowercase.hpp
---
