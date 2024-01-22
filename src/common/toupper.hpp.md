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
    using namespace std;\n#line 3 \"src/common/toupper.hpp\"\n\nstring toupper(string\
    \ s) {\n    for (auto& c : s) {\n        c = toupper(c);\n    }\n    return s;\n\
    }\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nstring toupper(string s) {\n  \
    \  for (auto& c : s) {\n        c = toupper(c);\n    }\n    return s;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/toupper.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2024-01-22 18:54:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/toupper.hpp
layout: document
redirect_from:
- /library/src/common/toupper.hpp
- /library/src/common/toupper.hpp.html
title: src/common/toupper.hpp
---
