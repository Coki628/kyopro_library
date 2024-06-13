---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
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
    \ namespace std;\n#line 3 \"src/dp/get_smaller_flag.hpp\"\n\n// \u6841DP\u306E\
    smaller flag\u53D6\u5F97\nbool get_smaller_flag(bool current_flag, int current_value,\
    \ int limit_value) {\n    assert(not (current_flag == 0 and current_value > limit_value));\n\
    \    bool next_flag = current_flag | (current_value < limit_value);\n    return\
    \ next_flag;\n}\n\n// \u4E0B\u9650\u304C\u6C7A\u307E\u3063\u3066\u308B\u6642\u7528\
    (\u672Averify)\nbool get_greater_flag(bool current_flag, int current_value, int\
    \ limit_value) {\n    assert(not (current_flag == 0 and current_value < limit_value));\n\
    \    bool next_flag = current_flag | (current_value > limit_value);\n    return\
    \ next_flag;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u6841DP\u306Esmaller flag\u53D6\
    \u5F97\nbool get_smaller_flag(bool current_flag, int current_value, int limit_value)\
    \ {\n    assert(not (current_flag == 0 and current_value > limit_value));\n  \
    \  bool next_flag = current_flag | (current_value < limit_value);\n    return\
    \ next_flag;\n}\n\n// \u4E0B\u9650\u304C\u6C7A\u307E\u3063\u3066\u308B\u6642\u7528\
    (\u672Averify)\nbool get_greater_flag(bool current_flag, int current_value, int\
    \ limit_value) {\n    assert(not (current_flag == 0 and current_value < limit_value));\n\
    \    bool next_flag = current_flag | (current_value > limit_value);\n    return\
    \ next_flag;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/dp/get_smaller_flag.hpp
  requiredBy: []
  timestamp: '2024-06-13 19:19:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/get_smaller_flag.hpp
layout: document
redirect_from:
- /library/src/dp/get_smaller_flag.hpp
- /library/src/dp/get_smaller_flag.hpp.html
title: src/dp/get_smaller_flag.hpp
---
