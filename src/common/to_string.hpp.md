---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/common/join.hpp
    title: src/common/join.hpp
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

    #line 3 "src/common/to_string.hpp"


    string to_string(const string &S) { return S; }

    string to_string(char c) { return {c}; }

    '
  code: '#pragma once

    #include "../base.hpp"


    string to_string(const string &S) { return S; }

    string to_string(char c) { return {c}; }

    '
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/to_string.hpp
  requiredBy:
  - src/common/join.hpp
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/to_string.hpp
layout: document
redirect_from:
- /library/src/common/to_string.hpp
- /library/src/common/to_string.hpp.html
title: src/common/to_string.hpp
---
