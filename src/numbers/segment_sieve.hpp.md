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
    src/numbers/segment_sieve.hpp\"\n\n// \u533A\u9593[l,r)\u5185\u306E\u7D20\u6570\
    \u5217\u6319(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u533A\u9593\u7BE9\
    ) \nvector<bool> segment_sieve(ll l, ll r) {\n\n    int MAX = int(sqrt(r));\n\
    \    vector<bool> is_prime(MAX+1, true);\n    vector<bool> res(r-l, true);\n \
    \   if (l == 1) res[0] = false;\n    if (l == 0) res[1] = false;\n\n    rep(i,\
    \ 2, MAX+1) {\n        ll cnt = 0;\n        if (is_prime[i]) {\n            rep(j,\
    \ i*2, MAX+1, i) {\n                is_prime[j] = false;\n            }\n    \
    \        rep(j, max(2LL, (l+i-1)/i)*i, r, i) {\n                res[j-l] = false;\n\
    \            }\n        }\n    }\n    return res;\n}\n\n// // \u533A\u9593[l,r)\u5185\
    \u306E\u5404\u7D20\u56E0\u6570\u306E\u500B\u6570(\u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u533A\u9593\u7BE9) \n// map<ll, ll> segment_sieve(ll l, ll\
    \ r) {\n\n//     int MAX = int(sqrt(r));\n//     vector<bool> is_prime(MAX+1,\
    \ true);\n//     map<ll, ll> C;\n//     vector<ll> A(r-l);\n//     iota(ALL(A),\
    \ l);\n\n//     rep(i, 2, MAX+1) {\n//         ll cnt = 0;\n//         if (is_prime[i])\
    \ {\n//             rep(j, i*2, MAX+1, i) {\n//                 is_prime[j] =\
    \ false;\n//             }\n//             // \u7D20\u6570\u304C\u898B\u3064\u304B\
    \u3063\u305F\u3089\u3001\u533A\u9593\u5185\u306B\u3042\u308B\u305D\u306E\u500D\
    \u6570\u306B\u3064\u3044\u3066\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3066\u3044\
    \u304F\n//             rep(j, max(2LL, (l+i-1)/i)*i, r, i) {\n//             \
    \    while (A[j-l] % i == 0) {\n//                     A[j-l] /= i;\n//      \
    \               cnt++;\n//                 }\n//             }\n//           \
    \  C[i] += cnt;\n//         }\n//     }\n//     // \u81EA\u8EAB\u304C\u7D20\u6570\
    \u3067\u3042\u308C\u3070\u305D\u306E\u5206\u3092\u8DB3\u3059\n//     rep(i, r-l)\
    \ {\n//         if (A[i] > 1) {\n//             C[A[i]]++;\n//         }\n// \
    \    }\n//     return C;\n// }\n"
  code: "#include \"../macros.hpp\"\n\n// \u533A\u9593[l,r)\u5185\u306E\u7D20\u6570\
    \u5217\u6319(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u533A\u9593\u7BE9\
    ) \nvector<bool> segment_sieve(ll l, ll r) {\n\n    int MAX = int(sqrt(r));\n\
    \    vector<bool> is_prime(MAX+1, true);\n    vector<bool> res(r-l, true);\n \
    \   if (l == 1) res[0] = false;\n    if (l == 0) res[1] = false;\n\n    rep(i,\
    \ 2, MAX+1) {\n        ll cnt = 0;\n        if (is_prime[i]) {\n            rep(j,\
    \ i*2, MAX+1, i) {\n                is_prime[j] = false;\n            }\n    \
    \        rep(j, max(2LL, (l+i-1)/i)*i, r, i) {\n                res[j-l] = false;\n\
    \            }\n        }\n    }\n    return res;\n}\n\n// // \u533A\u9593[l,r)\u5185\
    \u306E\u5404\u7D20\u56E0\u6570\u306E\u500B\u6570(\u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u533A\u9593\u7BE9) \n// map<ll, ll> segment_sieve(ll l, ll\
    \ r) {\n\n//     int MAX = int(sqrt(r));\n//     vector<bool> is_prime(MAX+1,\
    \ true);\n//     map<ll, ll> C;\n//     vector<ll> A(r-l);\n//     iota(ALL(A),\
    \ l);\n\n//     rep(i, 2, MAX+1) {\n//         ll cnt = 0;\n//         if (is_prime[i])\
    \ {\n//             rep(j, i*2, MAX+1, i) {\n//                 is_prime[j] =\
    \ false;\n//             }\n//             // \u7D20\u6570\u304C\u898B\u3064\u304B\
    \u3063\u305F\u3089\u3001\u533A\u9593\u5185\u306B\u3042\u308B\u305D\u306E\u500D\
    \u6570\u306B\u3064\u3044\u3066\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3066\u3044\
    \u304F\n//             rep(j, max(2LL, (l+i-1)/i)*i, r, i) {\n//             \
    \    while (A[j-l] % i == 0) {\n//                     A[j-l] /= i;\n//      \
    \               cnt++;\n//                 }\n//             }\n//           \
    \  C[i] += cnt;\n//         }\n//     }\n//     // \u81EA\u8EAB\u304C\u7D20\u6570\
    \u3067\u3042\u308C\u3070\u305D\u306E\u5206\u3092\u8DB3\u3059\n//     rep(i, r-l)\
    \ {\n//         if (A[i] > 1) {\n//             C[A[i]]++;\n//         }\n// \
    \    }\n//     return C;\n// }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/segment_sieve.hpp
  requiredBy: []
  timestamp: '2022-04-06 17:44:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/segment_sieve.hpp
layout: document
redirect_from:
- /library/src/numbers/segment_sieve.hpp
- /library/src/numbers/segment_sieve.hpp.html
title: src/numbers/segment_sieve.hpp
---
