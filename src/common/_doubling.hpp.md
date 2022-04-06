---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
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
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/common/listnd.hpp\"\n\ntemplate<typename T>\nvector<vector<T>> list2d(int\
    \ N, int M, T init) {\n    return vector<vector<T>>(N, vector<T>(M, init));\n\
    }\n\ntemplate<typename T>\nvector<vector<vector<T>>> list3d(int N, int M, int\
    \ L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L,\
    \ init)));\n}\n\ntemplate<typename T> \nvector<vector<vector<vector<T>>>> list4d(int\
    \ N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n\
    #line 3 \"src/common/_doubling.hpp\"\n\n// \u30C0\u30D6\u30EA\u30F3\u30B0(\u65E7\
    )\nvvl doubling(int MXLOG, const vector<ll> &A) {\n\n    int N = A.size();\n \
    \   auto nxt = list2d(MXLOG, N, -1LL);\n    rep(i, N) {\n        nxt[0][i] = A[i];\n\
    \    }\n    rep(k, 1, MXLOG) {\n        rep(i, N) {\n            if (nxt[k-1][i]\
    \ != -1) {\n                nxt[k][i] = nxt[k-1][nxt[k-1][i]];\n            }\n\
    \        }\n    }\n    return nxt;\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"listnd.hpp\"\n\n// \u30C0\u30D6\u30EA\
    \u30F3\u30B0(\u65E7)\nvvl doubling(int MXLOG, const vector<ll> &A) {\n\n    int\
    \ N = A.size();\n    auto nxt = list2d(MXLOG, N, -1LL);\n    rep(i, N) {\n   \
    \     nxt[0][i] = A[i];\n    }\n    rep(k, 1, MXLOG) {\n        rep(i, N) {\n\
    \            if (nxt[k-1][i] != -1) {\n                nxt[k][i] = nxt[k-1][nxt[k-1][i]];\n\
    \            }\n        }\n    }\n    return nxt;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/common/_doubling.hpp
  requiredBy: []
  timestamp: '2022-04-06 17:44:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/_doubling.hpp
layout: document
redirect_from:
- /library/src/common/_doubling.hpp
- /library/src/common/_doubling.hpp.html
title: src/common/_doubling.hpp
---
