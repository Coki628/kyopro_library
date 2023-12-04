---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/string/replace.hpp\"\n\nstring replace(string\
    \ str, const string &replace, const string &with) {\n    if (!replace.empty())\
    \ {\n        size_t pos = 0;\n        while ((pos = str.find(replace, pos)) !=\
    \ string::npos) {\n            str.replace(pos, replace.length(), with);\n   \
    \         pos += with.length();\n        }\n    }\n    return str;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\nstring replace(string str, const\
    \ string &replace, const string &with) {\n    if (!replace.empty()) {\n      \
    \  size_t pos = 0;\n        while ((pos = str.find(replace, pos)) != string::npos)\
    \ {\n            str.replace(pos, replace.length(), with);\n            pos +=\
    \ with.length();\n        }\n    }\n    return str;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/string/replace.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/replace.hpp
layout: document
redirect_from:
- /library/src/string/replace.hpp
- /library/src/string/replace.hpp.html
title: src/string/replace.hpp
---
