---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://rsk0315.hatenablog.com/entry/2021/02/23/163040
  bundledCode: "#line 2 \"src/common/overflow.hpp\"\n\n// \u4E57\u7B97\u306E\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u691C\u77E5\n// \u53C2\u8003\uFF1Ahttps://rsk0315.hatenablog.com/entry/2021/02/23/163040\n\
    template<typename T>\nbool mul_overflow(T x, T y) {\n    T z;\n    return __builtin_mul_overflow(x,\
    \ y, &z);\n}\n\n// \u52A0\u7B97\u306E\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u691C\u77E5\ntemplate<typename T>\nbool add_overflow(T x, T y) {\n    T z;\n\
    \    return __builtin_add_overflow(x, y, &z);\n}\n"
  code: "#pragma once\n\n// \u4E57\u7B97\u306E\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u691C\u77E5\n// \u53C2\u8003\uFF1Ahttps://rsk0315.hatenablog.com/entry/2021/02/23/163040\n\
    template<typename T>\nbool mul_overflow(T x, T y) {\n    T z;\n    return __builtin_mul_overflow(x,\
    \ y, &z);\n}\n\n// \u52A0\u7B97\u306E\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u691C\u77E5\ntemplate<typename T>\nbool add_overflow(T x, T y) {\n    T z;\n\
    \    return __builtin_add_overflow(x, y, &z);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/common/overflow.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/overflow.hpp
layout: document
redirect_from:
- /library/src/common/overflow.hpp
- /library/src/common/overflow.hpp.html
title: src/common/overflow.hpp
---
