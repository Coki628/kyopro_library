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
    src/combinatorics/stirling.hpp\"\n\n// \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\
    (\u7389\u533A\u5225\u3042\u308A\u3001\u7BB1\u533A\u5225\u306A\u3057\u30011\u500B\
    \u4EE5\u4E0A)\ntemplate<typename T>\nvector<vector<T>> stirling(int N, int K)\
    \ {\n    auto dp = list2d<T>(N+1, K+1, 0);\n    dp[0][0] = 1;\n    rep(i, 1, N+1)\
    \ {\n        rep(k, 1, K+1) {\n            dp[i][k] = dp[i-1][k-1] + dp[i-1][k]*k;\n\
    \        }\n    }\n    return dp;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\
    (\u7389\u533A\u5225\u3042\u308A\u3001\u7BB1\u533A\u5225\u306A\u3057\u30011\u500B\
    \u4EE5\u4E0A)\ntemplate<typename T>\nvector<vector<T>> stirling(int N, int K)\
    \ {\n    auto dp = list2d<T>(N+1, K+1, 0);\n    dp[0][0] = 1;\n    rep(i, 1, N+1)\
    \ {\n        rep(k, 1, K+1) {\n            dp[i][k] = dp[i-1][k-1] + dp[i-1][k]*k;\n\
    \        }\n    }\n    return dp;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/stirling.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/stirling.hpp
layout: document
redirect_from:
- /library/src/combinatorics/stirling.hpp
- /library/src/combinatorics/stirling.hpp.html
title: src/combinatorics/stirling.hpp
---
