---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"\
    src/numbers/osa_k.hpp\"\n\n// \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(osa_k\u6CD5\
    )\u3001\u524D\u8A08\u7B97\nvector<ll> eratosthenes_sieve(ll n) {\n    vector<ll>\
    \ table(n+1);\n    table[1] = 1;\n    rep(i, 2, n+1) {\n        if (table[i] ==\
    \ 0) {\n            for (ll j=i; j<=n; j+=i) {\n                table[j] = i;\n\
    \            }\n        }\n    }\n    return table;\n}\n\n// \u9AD8\u901F\u7D20\
    \u56E0\u6570\u5206\u89E3(osa_k\u6CD5)(vector\u30D9\u30FC\u30B9)\nvector<pair<ll,\
    \ int>> factorize(const vector<ll> &minfactor, ll x) {\n    vector<pair<ll, int>>\
    \ res;\n    while (x > 1) {\n        int p = minfactor[x];\n        int cnt =\
    \ 0;\n        while (minfactor[x] == p) {\n            x /= p;\n            cnt++;\n\
    \        }\n        res.pb({p, cnt});\n    }\n    return res;\n}\n\n// \u9AD8\u901F\
    \u7D20\u56E0\u6570\u5206\u89E3(osa_k\u6CD5)(map\u30D9\u30FC\u30B9)\n// map<ll,\
    \ ll> factorize(const vector<ll> &table, ll x) {\n//     map<ll, ll> res;\n//\
    \     while (x != table[x]) {\n//         res[table[x]]++;\n//         x /= table[x];\n\
    //     }\n//     if (x != 1) {\n//         res[x]++;\n//     }\n//     return\
    \ res;\n// }\n"
  code: "#include \"../macros.hpp\"\n\n// \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\
    (osa_k\u6CD5)\u3001\u524D\u8A08\u7B97\nvector<ll> eratosthenes_sieve(ll n) {\n\
    \    vector<ll> table(n+1);\n    table[1] = 1;\n    rep(i, 2, n+1) {\n       \
    \ if (table[i] == 0) {\n            for (ll j=i; j<=n; j+=i) {\n             \
    \   table[j] = i;\n            }\n        }\n    }\n    return table;\n}\n\n//\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(osa_k\u6CD5)(vector\u30D9\u30FC\u30B9\
    )\nvector<pair<ll, int>> factorize(const vector<ll> &minfactor, ll x) {\n    vector<pair<ll,\
    \ int>> res;\n    while (x > 1) {\n        int p = minfactor[x];\n        int\
    \ cnt = 0;\n        while (minfactor[x] == p) {\n            x /= p;\n       \
    \     cnt++;\n        }\n        res.pb({p, cnt});\n    }\n    return res;\n}\n\
    \n// \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(osa_k\u6CD5)(map\u30D9\u30FC\u30B9\
    )\n// map<ll, ll> factorize(const vector<ll> &table, ll x) {\n//     map<ll, ll>\
    \ res;\n//     while (x != table[x]) {\n//         res[table[x]]++;\n//      \
    \   x /= table[x];\n//     }\n//     if (x != 1) {\n//         res[x]++;\n// \
    \    }\n//     return res;\n// }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/osa_k.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/osa_k.hpp
layout: document
redirect_from:
- /library/src/numbers/osa_k.hpp
- /library/src/numbers/osa_k.hpp.html
title: src/numbers/osa_k.hpp
---
