---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
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
    \ namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull\
    \ = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\nusing vvl = vv<ll>;\n\
    using vvi = vv<int>;\nusing vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil\
    \ = vv<pil>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa\
    \ = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n\
    #define rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb)\
    \ or (c < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a);\
    \ i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/numbers/Eratosthenes.hpp\"\
    \n\n// \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\nstruct Eratosthenes\
    \ {\n    int n;\n    bool loglog;\n    vector<bool> prime;\n    vector<int> minfactor,\
    \ cntfactor, cntdivisor, sumdivisor;\n    vector<int> mobius;\n\n    Eratosthenes(int\
    \ n, bool loglog = true) : n(n), loglog(loglog) {\n        prime.assign(n + 1,\
    \ true);\n        minfactor.assign(n + 1, 0);\n        cntfactor.assign(n + 1,\
    \ 0);\n        mobius.assign(n + 1, 1);\n        if (not loglog) {\n         \
    \   cntdivisor.assign(n + 1, 1);\n            sumdivisor.assign(n + 1, 1);\n \
    \       }\n        prime[0] = prime[1] = false;\n        minfactor[1] = 1;\n \
    \       rep(i, 2, n + 1) {\n            if (not loglog) {\n                for\
    \ (int j = i; j <= n; j += i) {\n                    cntdivisor[j]++;\n      \
    \              sumdivisor[j] += i;\n                }\n            }\n       \
    \     if (not prime[i]) continue;\n            minfactor[i] = i;\n           \
    \ cntfactor[i]++;\n            mobius[i] = -1;\n            for (int j = i + i;\
    \ j <= n; j += i) {\n                prime[j] = false;\n                minfactor[j]\
    \ = i;\n                cntfactor[i]++;\n                // i\u30672\u56DE\u4EE5\
    \u4E0A\u5272\u308A\u5207\u308C\u308B\u3082\u306E\u30920\u306B\n              \
    \  if (j / i % i == 0) {\n                    mobius[j] = 0;\n               \
    \ } else {\n                    mobius[j] = -mobius[j];\n                }\n \
    \           }\n        }\n    }\n\n    bool is_prime(int x) {\n        assert(x\
    \ <= n);\n        return prime[x];\n    }\n\n    // \u9AD8\u901F\u7D20\u56E0\u6570\
    \u5206\u89E3(osa_k\u6CD5)\n    vector<pii> factorize(int x) {\n        assert(x\
    \ <= n);\n        vector<pii> res;\n        while (x > 1) {\n            int p\
    \ = minfactor[x];\n            int cnt = 0;\n            while (minfactor[x] ==\
    \ p) {\n                x /= p;\n                cnt++;\n            }\n     \
    \       res.pb({p, cnt});\n        }\n        return res;\n    }\n\n    // \u9AD8\
    \u901F\u7D04\u6570\u5217\u6319\n    vector<int> divisors(int n) {\n        vector<int>\
    \ res = {1};\n        auto fact = factorize(n);\n        for (auto [p, cnt] :\
    \ fact) {\n            int m = res.size();\n            rep(i, m) {\n        \
    \        int v = 1;\n                rep(j, cnt) {\n                    v *= p;\n\
    \                    res.pb(res[i] * v);\n                }\n            }\n \
    \       }\n        return res;\n    }\n\n    // \u7D20\u56E0\u6570\u306E\u7A2E\
    \u985E\u6570(\u672Averify)\n    vector<int> get_cntfactor() {\n        return\
    \ cntfactor;\n    }\n\n    // \u7D04\u6570\u306E\u500B\u6570(\u672Averify)\n \
    \   vector<int> get_cntdivisor() {\n        assert(not loglog);\n        return\
    \ cntdivisor;\n    }\n\n    // \u7D04\u6570\u306E\u7DCF\u548C(\u672Averify)\n\
    \    vector<int> get_sumdivisor() {\n        assert(not loglog);\n        return\
    \ sumdivisor;\n    }\n\n    // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\n    vector<int>\
    \ get_mobius() {\n        return mobius;\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u7BE9\nstruct Eratosthenes {\n    int n;\n    bool loglog;\n\
    \    vector<bool> prime;\n    vector<int> minfactor, cntfactor, cntdivisor, sumdivisor;\n\
    \    vector<int> mobius;\n\n    Eratosthenes(int n, bool loglog = true) : n(n),\
    \ loglog(loglog) {\n        prime.assign(n + 1, true);\n        minfactor.assign(n\
    \ + 1, 0);\n        cntfactor.assign(n + 1, 0);\n        mobius.assign(n + 1,\
    \ 1);\n        if (not loglog) {\n            cntdivisor.assign(n + 1, 1);\n \
    \           sumdivisor.assign(n + 1, 1);\n        }\n        prime[0] = prime[1]\
    \ = false;\n        minfactor[1] = 1;\n        rep(i, 2, n + 1) {\n          \
    \  if (not loglog) {\n                for (int j = i; j <= n; j += i) {\n    \
    \                cntdivisor[j]++;\n                    sumdivisor[j] += i;\n \
    \               }\n            }\n            if (not prime[i]) continue;\n  \
    \          minfactor[i] = i;\n            cntfactor[i]++;\n            mobius[i]\
    \ = -1;\n            for (int j = i + i; j <= n; j += i) {\n                prime[j]\
    \ = false;\n                minfactor[j] = i;\n                cntfactor[i]++;\n\
    \                // i\u30672\u56DE\u4EE5\u4E0A\u5272\u308A\u5207\u308C\u308B\u3082\
    \u306E\u30920\u306B\n                if (j / i % i == 0) {\n                 \
    \   mobius[j] = 0;\n                } else {\n                    mobius[j] =\
    \ -mobius[j];\n                }\n            }\n        }\n    }\n\n    bool\
    \ is_prime(int x) {\n        assert(x <= n);\n        return prime[x];\n    }\n\
    \n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(osa_k\u6CD5)\n    vector<pii>\
    \ factorize(int x) {\n        assert(x <= n);\n        vector<pii> res;\n    \
    \    while (x > 1) {\n            int p = minfactor[x];\n            int cnt =\
    \ 0;\n            while (minfactor[x] == p) {\n                x /= p;\n     \
    \           cnt++;\n            }\n            res.pb({p, cnt});\n        }\n\
    \        return res;\n    }\n\n    // \u9AD8\u901F\u7D04\u6570\u5217\u6319\n \
    \   vector<int> divisors(int n) {\n        vector<int> res = {1};\n        auto\
    \ fact = factorize(n);\n        for (auto [p, cnt] : fact) {\n            int\
    \ m = res.size();\n            rep(i, m) {\n                int v = 1;\n     \
    \           rep(j, cnt) {\n                    v *= p;\n                    res.pb(res[i]\
    \ * v);\n                }\n            }\n        }\n        return res;\n  \
    \  }\n\n    // \u7D20\u56E0\u6570\u306E\u7A2E\u985E\u6570(\u672Averify)\n    vector<int>\
    \ get_cntfactor() {\n        return cntfactor;\n    }\n\n    // \u7D04\u6570\u306E\
    \u500B\u6570(\u672Averify)\n    vector<int> get_cntdivisor() {\n        assert(not\
    \ loglog);\n        return cntdivisor;\n    }\n\n    // \u7D04\u6570\u306E\u7DCF\
    \u548C(\u672Averify)\n    vector<int> get_sumdivisor() {\n        assert(not loglog);\n\
    \        return sumdivisor;\n    }\n\n    // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\
    \n    vector<int> get_mobius() {\n        return mobius;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/Eratosthenes.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/Eratosthenes.hpp
layout: document
redirect_from:
- /library/src/numbers/Eratosthenes.hpp
- /library/src/numbers/Eratosthenes.hpp.html
title: src/numbers/Eratosthenes.hpp
---
