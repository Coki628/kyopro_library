---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/numbers/extgcd.hpp
    title: src/numbers/extgcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://betrue12.hateblo.jp/entry/2020/02/23/173513
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/numbers/extgcd.hpp\"\n\n// \u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5(ax+by=gcd(a, b)\u306E\u89E3\
    \u3092\u6C42\u3081\u308B)\ntemplate<typename T>\nT extgcd(T a, T b, T &x, T &y)\
    \ {\n    T d = a;\n    if (b != 0) {\n        d = extgcd(b, a % b, y, x);\n  \
    \      y -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n\
    \    return d;\n}\n#line 4 \"src/combinatorics/AnyModTools.hpp\"\n\n// \u4EFB\u610F\
    Mod\u6570\u3048\u4E0A\u3052\u6F14\u7B97\u30C4\u30FC\u30EB\n// \u53C2\u8003\uFF1A\
    https://betrue12.hateblo.jp/entry/2020/02/23/173513\nstruct AnyModTools {\nprivate:\n\
    \    const int64_t MOD;\n    // \u7D20\u6570\u51AA\u3092(p, c)\u3067\u8868\u73FE\
    \u3057\u305F\u3082\u306E\n    vector<pair<int64_t, int>> primes;\n    // \u7D20\
    \u6570\u51AAp^c\u306E\u5B9F\u969B\u306E\u5024\n    vector<int64_t> ppow;\n   \
    \ // \u968E\u4E57\u3092(x, y)\u5F62\u5F0F\u3067\u8868\u73FE\u3057\u305F\u3082\u306E\
    \n    vector<vector<pair<int64_t, int>>> fact;\n\n    vector<pair<int64_t, int>>\
    \ factorize(int64_t n) {\n        vector<pair<int64_t, int>> ret;\n        for\
    \ (int64_t i = 2; i * i <= n; i++) {\n            int cnt = 0;\n            while\
    \ (n % i == 0) {\n                n /= i;\n                cnt++;\n          \
    \  }\n            if (cnt) ret.emplace_back(i, cnt);\n        }\n        if (n\
    \ > 1) ret.emplace_back(n, 1);\n        return ret;\n    }\n\n    void add(int64_t\
    \ &a, int64_t b, int64_t mod) {\n        a = (a + b) % mod;\n    }\n    void mul(int64_t\
    \ &a, int64_t b, int64_t mod) {\n        a = a * b % mod;\n    }\n    int64_t\
    \ inv_mod(int64_t a, int64_t mod) {\n        int64_t x, y;\n        extgcd(a,\
    \ mod, x, y);\n        return (MOD + x % mod) % mod;\n    }\n\n    // \u7D20\u56E0\
    \u6570\u5206\u89E3\u3092\u3057\u3066\u7D20\u6570\u51AA\u3054\u3068\u306Bfact\u3092\
    \u524D\u8A08\u7B97\uFF1AO(\u221AM+N*(M\u306E\u7D20\u56E0\u6570\u306E\u7A2E\u985E\
    \u6570))\n    void create_composite_mod_table(int N, int64_t MOD) {\n        primes\
    \ = factorize(MOD);\n        int sz = primes.size();\n        ppow.resize(sz,\
    \ 1);\n        fact.resize(sz);\n        for (int pi = 0; pi < sz; pi++) {\n \
    \           int64_t p = primes[pi].first, cnt = primes[pi].second;\n         \
    \   while (cnt--) ppow[pi] *= p;\n\n            auto &f = fact[pi];\n        \
    \    f.resize(N + 1);\n            f[0] = {1, 0};\n            for (int i = 1;\
    \ i <= N; i++) {\n                f[i] = f[i - 1];\n                int n = i;\n\
    \                while (n % p == 0) {\n                    n /= p;\n         \
    \           f[i].second++;\n                }\n                mul(f[i].first,\
    \ n, ppow[pi]);\n            }\n        }\n    }\n\n    // \u7D20\u56E0\u6570\u6BCE\
    \u306E\u4E8C\u9805\u4FC2\u6570\u3092\u8A08\u7B97\n    int64_t comb_mod(int n,\
    \ int k, int pi) {\n        auto &a = fact[pi][n], &b = fact[pi][k], &c = fact[pi][n\
    \ - k];\n        int64_t p = primes[pi].first, cnt = primes[pi].second;\n    \
    \    int64_t pp = ppow[pi];\n        int pw = a.second - b.second - c.second;\n\
    \        if (pw >= cnt) return 0;\n\n        int64_t v = a.first;\n        mul(v,\
    \ inv_mod(b.first, pp), pp);\n        mul(v, inv_mod(c.first, pp), pp);\n    \
    \    while (pw--) mul(v, p, pp);\n        return v;\n    }\n\n    pair<int64_t,\
    \ int64_t> crt(int64_t b1, int64_t m1, int64_t b2, int64_t m2) {\n        int64_t\
    \ p, q;\n        int64_t d = extgcd(m1, m2, p, q);\n        if ((b2 - b1) % d\
    \ != 0) return {-1, -1};\n        int64_t m = m1 * (m2 / d);\n        int64_t\
    \ tmp = (b2 - b1) / d * p % (m2 / d);\n        int64_t r = ((b1 + m1 * tmp) %\
    \ m + m) % m;\n        return make_pair(r, m);\n    }\n\npublic:\n    AnyModTools(int64_t\
    \ MOD, int MX) : MOD(MOD) {\n        create_composite_mod_table(++MX, MOD);\n\
    \    }\n\n    // \u4E8C\u9805\u4FC2\u6570nCr\u306E\u8A08\u7B97\uFF1AO(mod\u306E\
    \u7D20\u56E0\u6570\u306E\u7A2E\u985E\u6570*\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\
    )\n    int64_t nCr(int n, int k) {\n        if (n < k or k < 0) return 0;\n  \
    \      pair<int64_t, int64_t> res = {0, 1};\n        for (int pi = 0; pi < primes.size();\
    \ pi++) {\n            res = crt(res.first, res.second, comb_mod(n, k, pi), ppow[pi]);\n\
    \        }\n        return res.first;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../numbers/extgcd.hpp\"\
    \n\n// \u4EFB\u610FMod\u6570\u3048\u4E0A\u3052\u6F14\u7B97\u30C4\u30FC\u30EB\n\
    // \u53C2\u8003\uFF1Ahttps://betrue12.hateblo.jp/entry/2020/02/23/173513\nstruct\
    \ AnyModTools {\nprivate:\n    const int64_t MOD;\n    // \u7D20\u6570\u51AA\u3092\
    (p, c)\u3067\u8868\u73FE\u3057\u305F\u3082\u306E\n    vector<pair<int64_t, int>>\
    \ primes;\n    // \u7D20\u6570\u51AAp^c\u306E\u5B9F\u969B\u306E\u5024\n    vector<int64_t>\
    \ ppow;\n    // \u968E\u4E57\u3092(x, y)\u5F62\u5F0F\u3067\u8868\u73FE\u3057\u305F\
    \u3082\u306E\n    vector<vector<pair<int64_t, int>>> fact;\n\n    vector<pair<int64_t,\
    \ int>> factorize(int64_t n) {\n        vector<pair<int64_t, int>> ret;\n    \
    \    for (int64_t i = 2; i * i <= n; i++) {\n            int cnt = 0;\n      \
    \      while (n % i == 0) {\n                n /= i;\n                cnt++;\n\
    \            }\n            if (cnt) ret.emplace_back(i, cnt);\n        }\n  \
    \      if (n > 1) ret.emplace_back(n, 1);\n        return ret;\n    }\n\n    void\
    \ add(int64_t &a, int64_t b, int64_t mod) {\n        a = (a + b) % mod;\n    }\n\
    \    void mul(int64_t &a, int64_t b, int64_t mod) {\n        a = a * b % mod;\n\
    \    }\n    int64_t inv_mod(int64_t a, int64_t mod) {\n        int64_t x, y;\n\
    \        extgcd(a, mod, x, y);\n        return (MOD + x % mod) % mod;\n    }\n\
    \n    // \u7D20\u56E0\u6570\u5206\u89E3\u3092\u3057\u3066\u7D20\u6570\u51AA\u3054\
    \u3068\u306Bfact\u3092\u524D\u8A08\u7B97\uFF1AO(\u221AM+N*(M\u306E\u7D20\u56E0\
    \u6570\u306E\u7A2E\u985E\u6570))\n    void create_composite_mod_table(int N, int64_t\
    \ MOD) {\n        primes = factorize(MOD);\n        int sz = primes.size();\n\
    \        ppow.resize(sz, 1);\n        fact.resize(sz);\n        for (int pi =\
    \ 0; pi < sz; pi++) {\n            int64_t p = primes[pi].first, cnt = primes[pi].second;\n\
    \            while (cnt--) ppow[pi] *= p;\n\n            auto &f = fact[pi];\n\
    \            f.resize(N + 1);\n            f[0] = {1, 0};\n            for (int\
    \ i = 1; i <= N; i++) {\n                f[i] = f[i - 1];\n                int\
    \ n = i;\n                while (n % p == 0) {\n                    n /= p;\n\
    \                    f[i].second++;\n                }\n                mul(f[i].first,\
    \ n, ppow[pi]);\n            }\n        }\n    }\n\n    // \u7D20\u56E0\u6570\u6BCE\
    \u306E\u4E8C\u9805\u4FC2\u6570\u3092\u8A08\u7B97\n    int64_t comb_mod(int n,\
    \ int k, int pi) {\n        auto &a = fact[pi][n], &b = fact[pi][k], &c = fact[pi][n\
    \ - k];\n        int64_t p = primes[pi].first, cnt = primes[pi].second;\n    \
    \    int64_t pp = ppow[pi];\n        int pw = a.second - b.second - c.second;\n\
    \        if (pw >= cnt) return 0;\n\n        int64_t v = a.first;\n        mul(v,\
    \ inv_mod(b.first, pp), pp);\n        mul(v, inv_mod(c.first, pp), pp);\n    \
    \    while (pw--) mul(v, p, pp);\n        return v;\n    }\n\n    pair<int64_t,\
    \ int64_t> crt(int64_t b1, int64_t m1, int64_t b2, int64_t m2) {\n        int64_t\
    \ p, q;\n        int64_t d = extgcd(m1, m2, p, q);\n        if ((b2 - b1) % d\
    \ != 0) return {-1, -1};\n        int64_t m = m1 * (m2 / d);\n        int64_t\
    \ tmp = (b2 - b1) / d * p % (m2 / d);\n        int64_t r = ((b1 + m1 * tmp) %\
    \ m + m) % m;\n        return make_pair(r, m);\n    }\n\npublic:\n    AnyModTools(int64_t\
    \ MOD, int MX) : MOD(MOD) {\n        create_composite_mod_table(++MX, MOD);\n\
    \    }\n\n    // \u4E8C\u9805\u4FC2\u6570nCr\u306E\u8A08\u7B97\uFF1AO(mod\u306E\
    \u7D20\u56E0\u6570\u306E\u7A2E\u985E\u6570*\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\
    )\n    int64_t nCr(int n, int k) {\n        if (n < k or k < 0) return 0;\n  \
    \      pair<int64_t, int64_t> res = {0, 1};\n        for (int pi = 0; pi < primes.size();\
    \ pi++) {\n            res = crt(res.first, res.second, comb_mod(n, k, pi), ppow[pi]);\n\
    \        }\n        return res.first;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/numbers/extgcd.hpp
  isVerificationFile: false
  path: src/combinatorics/AnyModTools.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/AnyModTools.hpp
layout: document
redirect_from:
- /library/src/combinatorics/AnyModTools.hpp
- /library/src/combinatorics/AnyModTools.hpp.html
title: src/combinatorics/AnyModTools.hpp
---
