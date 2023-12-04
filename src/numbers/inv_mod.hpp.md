---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/numbers/extgcd.hpp
    title: src/numbers/extgcd.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/numbers/bsgs.hpp
    title: src/numbers/bsgs.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/numbers/extgcd.hpp\"\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5(ax+by=gcd(a, b)\u306E\u89E3\u3092\u6C42\
    \u3081\u308B)\ntemplate<typename T>\nT extgcd(T a, T b, T &x, T &y) {\n    T d\
    \ = a;\n    if (b != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a\
    \ / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n    return d;\n\
    }\n#line 3 \"src/numbers/inv_mod.hpp\"\n\n// MOD\u9006\u5143(mod\u304C\u7D20\u6570\
    \u3067\u306A\u304F\u3066\u3082\u3001a\u3068mod\u304C\u4E92\u3044\u306B\u7D20\u306A\
    \u3089\u53EF)\ntemplate<typename T>\nT inv_mod(T a, T mod) {\n    T x, y;\n  \
    \  extgcd(a, mod, x, y);\n    return (mod + x % mod) % mod;\n}\n"
  code: "#pragma once\n#include \"extgcd.hpp\"\n\n// MOD\u9006\u5143(mod\u304C\u7D20\
    \u6570\u3067\u306A\u304F\u3066\u3082\u3001a\u3068mod\u304C\u4E92\u3044\u306B\u7D20\
    \u306A\u3089\u53EF)\ntemplate<typename T>\nT inv_mod(T a, T mod) {\n    T x, y;\n\
    \    extgcd(a, mod, x, y);\n    return (mod + x % mod) % mod;\n}\n"
  dependsOn:
  - src/numbers/extgcd.hpp
  isVerificationFile: false
  path: src/numbers/inv_mod.hpp
  requiredBy:
  - src/numbers/bsgs.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/inv_mod.hpp
layout: document
redirect_from:
- /library/src/numbers/inv_mod.hpp
- /library/src/numbers/inv_mod.hpp.html
title: src/numbers/inv_mod.hpp
---
