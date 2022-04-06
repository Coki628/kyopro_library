---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/split.hpp
    title: src/common/split.hpp
  - icon: ':warning:'
    path: src/numbers/digit_sum.hpp
    title: src/numbers/digit_sum.hpp
  - icon: ':warning:'
    path: src/numbers/ntod.hpp
    title: src/numbers/ntod.hpp
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
    using namespace std;\n#line 3 \"src/common/toint.hpp\"\n\nll toint(string s) {\n\
    \    assert(s.size() < 20);\n    ll res = 0;\n    for (char &c : s) {\n      \
    \  res *= 10;\n        res += c - '0';\n    }\n    return res;\n}\n\nint toint(char\
    \ num) {\n    return num - '0';\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nll toint(string s) {\n    assert(s.size()\
    \ < 20);\n    ll res = 0;\n    for (char &c : s) {\n        res *= 10;\n     \
    \   res += c - '0';\n    }\n    return res;\n}\n\nint toint(char num) {\n    return\
    \ num - '0';\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/toint.hpp
  requiredBy:
  - src/common/split.hpp
  - src/numbers/digit_sum.hpp
  - src/numbers/ntod.hpp
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/toint.hpp
layout: document
redirect_from:
- /library/src/common/toint.hpp
- /library/src/common/toint.hpp.html
title: src/common/toint.hpp
---
