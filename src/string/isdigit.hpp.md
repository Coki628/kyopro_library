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
    using namespace std;\n#line 2 \"src/string/isdigit.hpp\"\n\nbool isdigit(string\
    \ S) {\n    for (auto c : S) {\n        if (not isdigit(c)) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\n"
  code: "#include \"../base.hpp\"\n\nbool isdigit(string S) {\n    for (auto c : S)\
    \ {\n        if (not isdigit(c)) {\n            return false;\n        }\n   \
    \ }\n    return true;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/isdigit.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2023-01-03 02:49:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/isdigit.hpp
layout: document
redirect_from:
- /library/src/string/isdigit.hpp
- /library/src/string/isdigit.hpp.html
title: src/string/isdigit.hpp
---
