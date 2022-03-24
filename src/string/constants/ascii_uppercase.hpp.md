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
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':x:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/string/constants/ascii_uppercase.hpp
layout: document
redirect_from:
- /library/src/string/constants/ascii_uppercase.hpp
- /library/src/string/constants/ascii_uppercase.hpp.html
title: src/string/constants/ascii_uppercase.hpp
---
