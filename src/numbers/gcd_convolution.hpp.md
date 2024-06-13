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
    \ namespace std;\n#line 3 \"src/numbers/gcd_convolution.hpp\"\n\n// \u6DFB\u5B57\
    GCD\u7573\u307F\u8FBC\u307F(\u8A08\u7B97\u91CF\uFF1AO(NloglogN))\ntemplate<typename\
    \ T>\nvector<T> gcd_convolution(vector<T> F, vector<T> G) {\n    int N = max(F.size(),\
    \ G.size());\n\n    // \u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB\n    auto fast_zeta\
    \ = [&](vector<T> &a) {\n        int n = a.size();\n        vector<bool> sieve(n,\
    \ false);\n        for (int p = 2; p < n; ++p) {\n            if (sieve[p]) continue;\n\
    \            for (int k = (n - 1) / p; k >= 0; k--)\n                sieve[k *\
    \ p] = true, a[k] += a[k * p];\n        }\n    };\n    // \u9AD8\u901F\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB\n    auto fast_mobius = [&](vector<T> &a) {\n       \
    \ int n = a.size();\n        vector<bool> sieve(n, false);\n        for (int p\
    \ = 2; p < n; ++p) {\n            if (sieve[p]) continue;\n            else {\n\
    \                for (int k = 0; k * p < n; k++)\n                    sieve[k\
    \ * p] = true, a[k] -= a[k * p];\n            }\n        }\n    };\n\n    fast_zeta(F);\n\
    \    fast_zeta(G);\n\n    vector<T> H(N);\n    rep(i, min(F.size(), G.size()))\
    \ {\n        H[i] = F[i] * G[i];\n    }\n\n    fast_mobius(H);\n\n    return H;\n\
    }\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u6DFB\u5B57GCD\u7573\u307F\u8FBC\
    \u307F(\u8A08\u7B97\u91CF\uFF1AO(NloglogN))\ntemplate<typename T>\nvector<T> gcd_convolution(vector<T>\
    \ F, vector<T> G) {\n    int N = max(F.size(), G.size());\n\n    // \u9AD8\u901F\
    \u30BC\u30FC\u30BF\u5909\u63DB\n    auto fast_zeta = [&](vector<T> &a) {\n   \
    \     int n = a.size();\n        vector<bool> sieve(n, false);\n        for (int\
    \ p = 2; p < n; ++p) {\n            if (sieve[p]) continue;\n            for (int\
    \ k = (n - 1) / p; k >= 0; k--)\n                sieve[k * p] = true, a[k] +=\
    \ a[k * p];\n        }\n    };\n    // \u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\
    \u63DB\n    auto fast_mobius = [&](vector<T> &a) {\n        int n = a.size();\n\
    \        vector<bool> sieve(n, false);\n        for (int p = 2; p < n; ++p) {\n\
    \            if (sieve[p]) continue;\n            else {\n                for\
    \ (int k = 0; k * p < n; k++)\n                    sieve[k * p] = true, a[k] -=\
    \ a[k * p];\n            }\n        }\n    };\n\n    fast_zeta(F);\n    fast_zeta(G);\n\
    \n    vector<T> H(N);\n    rep(i, min(F.size(), G.size())) {\n        H[i] = F[i]\
    \ * G[i];\n    }\n\n    fast_mobius(H);\n\n    return H;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/gcd_convolution.hpp
layout: document
redirect_from:
- /library/src/numbers/gcd_convolution.hpp
- /library/src/numbers/gcd_convolution.hpp.html
title: src/numbers/gcd_convolution.hpp
---
