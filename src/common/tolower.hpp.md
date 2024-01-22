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
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/tolower.hpp\"\n\nstring tolower(string\
    \ s) {\n    for (auto& c : s) {\n        c = tolower(c);\n    }\n    return s;\n\
    }\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nstring tolower(string s) {\n  \
    \  for (auto& c : s) {\n        c = tolower(c);\n    }\n    return s;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/tolower.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2024-01-22 18:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/tolower.hpp
layout: document
redirect_from:
- /library/src/common/tolower.hpp
- /library/src/common/tolower.hpp.html
title: src/common/tolower.hpp
---
