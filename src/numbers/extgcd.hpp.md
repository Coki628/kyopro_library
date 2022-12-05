---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/combinatorics/AnyModTools.hpp
    title: src/combinatorics/AnyModTools.hpp
  - icon: ':warning:'
    path: src/numbers/bsgs.hpp
    title: src/numbers/bsgs.hpp
  - icon: ':warning:'
    path: src/numbers/inv_mod.hpp
    title: src/numbers/inv_mod.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/numbers/extgcd.hpp\"\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5(ax+by=gcd(a, b)\u306E\u89E3\u3092\u6C42\
    \u3081\u308B)\ntemplate<typename T>\nT extgcd(T a, T b, T& x, T& y) {\n    T d\
    \ = a;\n    if (b != 0) {\n        d = extgcd(b, a%b, y, x);\n        y -= (a/b)\
    \ * x;\n    } else {\n        x = 1; y = 0;\n    }\n    return d;\n}\n"
  code: "#pragma once\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
    \u4E92\u9664\u6CD5(ax+by=gcd(a, b)\u306E\u89E3\u3092\u6C42\u3081\u308B)\ntemplate<typename\
    \ T>\nT extgcd(T a, T b, T& x, T& y) {\n    T d = a;\n    if (b != 0) {\n    \
    \    d = extgcd(b, a%b, y, x);\n        y -= (a/b) * x;\n    } else {\n      \
    \  x = 1; y = 0;\n    }\n    return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/numbers/extgcd.hpp
  requiredBy:
  - src/numbers/inv_mod.hpp
  - src/numbers/bsgs.hpp
  - src/combinatorics/AnyModTools.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/extgcd.hpp
layout: document
redirect_from:
- /library/src/numbers/extgcd.hpp
- /library/src/numbers/extgcd.hpp.html
title: src/numbers/extgcd.hpp
---
