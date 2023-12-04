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
    using namespace std;\n#line 3 \"src/common/arraynd.hpp\"\n\n// \u4EFB\u610F\u6B21\
    \u5143array\n// \u4F7F\u3044\u65B9\uFF1Aarraynd<ll, 2, 3>(INF); \u3067 ll[2][3]\
    \ = INF \u306B\u306A\u308B\u3002\ntemplate<typename T, size_t N, size_t... Ns>\n\
    auto arraynd(T a) {\n    if constexpr (sizeof...(Ns) == 0) {\n        array<T,\
    \ N> res;\n        res.fill(a);\n        return res;\n    } else {\n        static\
    \ auto cur = arraynd<T, Ns...>(a);\n        array<decltype(cur), N> res;\n   \
    \     res.fill(cur);\n        return res;\n    }\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u4EFB\u610F\u6B21\u5143array\n\
    // \u4F7F\u3044\u65B9\uFF1Aarraynd<ll, 2, 3>(INF); \u3067 ll[2][3] = INF \u306B\
    \u306A\u308B\u3002\ntemplate<typename T, size_t N, size_t... Ns>\nauto arraynd(T\
    \ a) {\n    if constexpr (sizeof...(Ns) == 0) {\n        array<T, N> res;\n  \
    \      res.fill(a);\n        return res;\n    } else {\n        static auto cur\
    \ = arraynd<T, Ns...>(a);\n        array<decltype(cur), N> res;\n        res.fill(cur);\n\
    \        return res;\n    }\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/arraynd.hpp
  requiredBy: []
  timestamp: '2023-11-30 18:05:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/arraynd.hpp
layout: document
redirect_from:
- /library/src/common/arraynd.hpp
- /library/src/common/arraynd.hpp.html
title: src/common/arraynd.hpp
---
