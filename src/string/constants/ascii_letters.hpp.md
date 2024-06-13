---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/string/constants/ascii_lowercase.hpp
    title: src/string/constants/ascii_lowercase.hpp
  - icon: ':warning:'
    path: src/string/constants/ascii_uppercase.hpp
    title: src/string/constants/ascii_uppercase.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/string/constants/ascii_lowercase.hpp\"\n\nconst\
    \ string ascii_lowercase = \"abcdefghijklmnopqrstuvwxyz\";\n#line 3 \"src/string/constants/ascii_uppercase.hpp\"\
    \n\nconst string ascii_uppercase = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\n#line 5 \"\
    src/string/constants/ascii_letters.hpp\"\n\nconst string ascii_letters = ascii_lowercase\
    \ + ascii_uppercase;\n"
  code: '#pragma once

    #include "../../base.hpp"

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
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/constants/ascii_letters.hpp
layout: document
redirect_from:
- /library/src/string/constants/ascii_letters.hpp
- /library/src/string/constants/ascii_letters.hpp.html
title: src/string/constants/ascii_letters.hpp
---
