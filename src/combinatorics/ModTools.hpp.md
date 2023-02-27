---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/fps/pow_term2.hpp
    title: src/math/fps/pow_term2.hpp
  - icon: ':warning:'
    path: src/math/lagrange_polynomial.hpp
    title: src/math/lagrange_polynomial.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ja.wikipedia.org/wiki/%E4%BA%8C%E9%87%8D%E9%9A%8E%E4%B9%97
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\n\
    #define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i\
    \ < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define\
    \ rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c\
    \ < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b);\
    \ i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/combinatorics/ModTools.hpp\"\
    \n\n// Mod\u6570\u3048\u4E0A\u3052\u6F14\u7B97\u30C4\u30FC\u30EB\ntemplate<typename\
    \ Mint>\nstruct ModTools {\n\n    int MAX;\n    vector<Mint> _fact, _factinv,\
    \ inv;\n\n    // nCr\u306A\u3089n\u3001nHr\u306A\u3089n+r\u307E\u3067\u4F5C\u308B\
    \n    ModTools(int mx) : MAX(++mx) {\n        _fact.resize(MAX);\n        _factinv.resize(MAX);\n\
    \        inv.resize(MAX);\n        _fact[0] = _fact[1] = 1;\n        rep(i, 2,\
    \ MAX) {\n            _fact[i] = _fact[i-1]*(Mint)i;\n        }\n        _factinv[MAX-1]\
    \ = (Mint)1/_fact[MAX-1];\n        rep(i, MAX-2, -1, -1) {\n            _factinv[i]\
    \ = _factinv[i+1]*(Mint)(i+1);\n        }\n        rep(i, MAX-1, 0, -1) {\n  \
    \          inv[i] = _factinv[i]*_fact[i-1];\n        }\n    }\n\n    // \u6E96\
    \u5099O(N)\u3001\u64CD\u4F5CO(1)\u3067log\u304C\u4E57\u3089\u306A\u3044mod\u9664\
    \u7B97\n    Mint div(Mint a, int b) {\n        return a*inv[b];\n    }\n\n   \
    \ Mint fact(int x) {\n        assert(x < MAX);\n        return _fact[x];\n   \
    \ }\n\n    Mint factinv(int x) {\n        assert(x < MAX);\n        return _factinv[x];\n\
    \    }\n\n    Mint nCr(int n, int r) {\n        if (n < r or r < 0) return 0;\n\
    \        r = min(r, n-r);\n        Mint num = _fact[n];\n        Mint den = _factinv[r]\
    \ * _factinv[n-r];\n        return num * den;\n    }\n\n    Mint nHr(int n, int\
    \ r) {\n        assert(r+n-1 < MAX);\n        return nCr(r+n-1, r);\n    }\n\n\
    \    Mint nPr(int n, int r) {\n        if (n < r or r < 0) return 0;\n       \
    \ return _fact[n] * _factinv[n-r];\n    }\n\n    // \u4E8C\u91CD\u968E\u4E57\n\
    \    // \u53C2\u8003\uFF1Ahttps://ja.wikipedia.org/wiki/%E4%BA%8C%E9%87%8D%E9%9A%8E%E4%B9%97\n\
    \    Mint double_factorial(int n) {\n        if (n%2 == 0) {\n            int\
    \ k = n/2;\n            return Mint(2).pow(k)*fact(k);\n        } else {\n   \
    \         int k = (n+1)/2;\n            return fact(2*k)/Mint(2).pow(k)/fact(k);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// Mod\u6570\u3048\u4E0A\u3052\
    \u6F14\u7B97\u30C4\u30FC\u30EB\ntemplate<typename Mint>\nstruct ModTools {\n\n\
    \    int MAX;\n    vector<Mint> _fact, _factinv, inv;\n\n    // nCr\u306A\u3089\
    n\u3001nHr\u306A\u3089n+r\u307E\u3067\u4F5C\u308B\n    ModTools(int mx) : MAX(++mx)\
    \ {\n        _fact.resize(MAX);\n        _factinv.resize(MAX);\n        inv.resize(MAX);\n\
    \        _fact[0] = _fact[1] = 1;\n        rep(i, 2, MAX) {\n            _fact[i]\
    \ = _fact[i-1]*(Mint)i;\n        }\n        _factinv[MAX-1] = (Mint)1/_fact[MAX-1];\n\
    \        rep(i, MAX-2, -1, -1) {\n            _factinv[i] = _factinv[i+1]*(Mint)(i+1);\n\
    \        }\n        rep(i, MAX-1, 0, -1) {\n            inv[i] = _factinv[i]*_fact[i-1];\n\
    \        }\n    }\n\n    // \u6E96\u5099O(N)\u3001\u64CD\u4F5CO(1)\u3067log\u304C\
    \u4E57\u3089\u306A\u3044mod\u9664\u7B97\n    Mint div(Mint a, int b) {\n     \
    \   return a*inv[b];\n    }\n\n    Mint fact(int x) {\n        assert(x < MAX);\n\
    \        return _fact[x];\n    }\n\n    Mint factinv(int x) {\n        assert(x\
    \ < MAX);\n        return _factinv[x];\n    }\n\n    Mint nCr(int n, int r) {\n\
    \        if (n < r or r < 0) return 0;\n        r = min(r, n-r);\n        Mint\
    \ num = _fact[n];\n        Mint den = _factinv[r] * _factinv[n-r];\n        return\
    \ num * den;\n    }\n\n    Mint nHr(int n, int r) {\n        assert(r+n-1 < MAX);\n\
    \        return nCr(r+n-1, r);\n    }\n\n    Mint nPr(int n, int r) {\n      \
    \  if (n < r or r < 0) return 0;\n        return _fact[n] * _factinv[n-r];\n \
    \   }\n\n    // \u4E8C\u91CD\u968E\u4E57\n    // \u53C2\u8003\uFF1Ahttps://ja.wikipedia.org/wiki/%E4%BA%8C%E9%87%8D%E9%9A%8E%E4%B9%97\n\
    \    Mint double_factorial(int n) {\n        if (n%2 == 0) {\n            int\
    \ k = n/2;\n            return Mint(2).pow(k)*fact(k);\n        } else {\n   \
    \         int k = (n+1)/2;\n            return fact(2*k)/Mint(2).pow(k)/fact(k);\n\
    \        }\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/ModTools.hpp
  requiredBy:
  - src/math/lagrange_polynomial.hpp
  - src/math/fps/pow_term2.hpp
  - src/template.hpp
  timestamp: '2023-02-28 01:25:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/ModTools.hpp
layout: document
redirect_from:
- /library/src/combinatorics/ModTools.hpp
- /library/src/combinatorics/ModTools.hpp.html
title: src/combinatorics/ModTools.hpp
---
