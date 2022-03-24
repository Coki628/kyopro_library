---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    links:
    - https://rsk0315.hatenablog.com/entry/2021/02/23/163040
  bundledCode: "#line 1 \"src/common/mul_overflow.hpp\"\n// \u53C2\u8003\uFF1Ahttps://rsk0315.hatenablog.com/entry/2021/02/23/163040\n\
    // \u4E57\u7B97\u306E\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u691C\u77E5\n\
    template<typename T>\nbool mul_overflow(T x, T y) {\n    T z;\n    return __builtin_mul_overflow(x,\
    \ y, &z);\n}\n"
  code: "// \u53C2\u8003\uFF1Ahttps://rsk0315.hatenablog.com/entry/2021/02/23/163040\n\
    // \u4E57\u7B97\u306E\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u691C\u77E5\n\
    template<typename T>\nbool mul_overflow(T x, T y) {\n    T z;\n    return __builtin_mul_overflow(x,\
    \ y, &z);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/mul_overflow.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/mul_overflow.hpp
layout: document
redirect_from:
- /library/src/common/mul_overflow.hpp
- /library/src/common/mul_overflow.hpp.html
title: src/common/mul_overflow.hpp
---
