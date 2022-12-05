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
    path: src/numbers/FastPrimeFactorization.hpp
    title: src/numbers/FastPrimeFactorization.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
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
    src/common/RLE.hpp\"\n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\n\
    template<typename T>\nvector<pair<T, int>> RLE(const vector<T> &A) {\n    if (A.empty())\
    \ return {};\n    int N = A.size();\n    vector<pair<T, int>> res;\n    T cur\
    \ = A[0];\n    int cnt = 1;\n    rep(i, 1, N) {\n        if (A[i] == A[i-1]) {\n\
    \            cnt++;\n        } else {\n            res.pb({cur, cnt});\n     \
    \       cnt = 1;\n            cur = A[i];\n        }\n    }\n    res.pb({cur,\
    \ cnt});\n    return res;\n}\n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\
    (\u6587\u5B57\u5217)\nvector<pair<char, int>> RLE(const string &S) {\n    if (S.empty())\
    \ return {};\n    int N = S.size();\n    vector<pair<char, int>> res;\n    char\
    \ cur = S[0];\n    int cnt = 1;\n    rep(i, 1, N) {\n        if (S[i] == S[i-1])\
    \ {\n            cnt++;\n        } else {\n            res.pb({cur, cnt});\n \
    \           cnt = 1;\n            cur = S[i];\n        }\n    }\n    res.pb({cur,\
    \ cnt});\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\
    \u30B9\u5727\u7E2E\ntemplate<typename T>\nvector<pair<T, int>> RLE(const vector<T>\
    \ &A) {\n    if (A.empty()) return {};\n    int N = A.size();\n    vector<pair<T,\
    \ int>> res;\n    T cur = A[0];\n    int cnt = 1;\n    rep(i, 1, N) {\n      \
    \  if (A[i] == A[i-1]) {\n            cnt++;\n        } else {\n            res.pb({cur,\
    \ cnt});\n            cnt = 1;\n            cur = A[i];\n        }\n    }\n  \
    \  res.pb({cur, cnt});\n    return res;\n}\n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\
    \u30B9\u5727\u7E2E(\u6587\u5B57\u5217)\nvector<pair<char, int>> RLE(const string\
    \ &S) {\n    if (S.empty()) return {};\n    int N = S.size();\n    vector<pair<char,\
    \ int>> res;\n    char cur = S[0];\n    int cnt = 1;\n    rep(i, 1, N) {\n   \
    \     if (S[i] == S[i-1]) {\n            cnt++;\n        } else {\n          \
    \  res.pb({cur, cnt});\n            cnt = 1;\n            cur = S[i];\n      \
    \  }\n    }\n    res.pb({cur, cnt});\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/RLE.hpp
  requiredBy:
  - src/numbers/FastPrimeFactorization.hpp
  - src/template.hpp
  timestamp: '2022-10-18 16:40:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/RLE.hpp
layout: document
redirect_from:
- /library/src/common/RLE.hpp
- /library/src/common/RLE.hpp.html
title: src/common/RLE.hpp
---