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
    \ namespace std;\n#line 3 \"src/common/Timer.hpp\"\n\n// \u74B0\u5883\u306B\u4F9D\
    \u5B58\u305B\u305A\u30DF\u30EA\u79D2\u5358\u4F4D\u3067\u6642\u9593\u53D6\u5F97\
    \u3059\u308B\u30AF\u30E9\u30B9\nstruct Timer {\n    chrono::_V2::system_clock::time_point\
    \ start_time;\n\n    // \u521D\u671F\u5316\u6642\u306B\u6642\u9593\u8A08\u6E2C\
    \u3092\u958B\u59CB\n    Timer() {\n        start_time = this->now();\n    }\n\n\
    \    // \u7D4C\u904E\u6642\u9593\n    int64_t get_elapse() {\n        return chrono::duration_cast<chrono::milliseconds>(this->now()\
    \ - start_time).count();\n    }\n\nprivate:\n    chrono::_V2::system_clock::time_point\
    \ now() {\n        return chrono::high_resolution_clock::now();\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u74B0\u5883\u306B\u4F9D\u5B58\
    \u305B\u305A\u30DF\u30EA\u79D2\u5358\u4F4D\u3067\u6642\u9593\u53D6\u5F97\u3059\
    \u308B\u30AF\u30E9\u30B9\nstruct Timer {\n    chrono::_V2::system_clock::time_point\
    \ start_time;\n\n    // \u521D\u671F\u5316\u6642\u306B\u6642\u9593\u8A08\u6E2C\
    \u3092\u958B\u59CB\n    Timer() {\n        start_time = this->now();\n    }\n\n\
    \    // \u7D4C\u904E\u6642\u9593\n    int64_t get_elapse() {\n        return chrono::duration_cast<chrono::milliseconds>(this->now()\
    \ - start_time).count();\n    }\n\nprivate:\n    chrono::_V2::system_clock::time_point\
    \ now() {\n        return chrono::high_resolution_clock::now();\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/Timer.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/Timer.hpp
layout: document
redirect_from:
- /library/src/common/Timer.hpp
- /library/src/common/Timer.hpp.html
title: src/common/Timer.hpp
---
