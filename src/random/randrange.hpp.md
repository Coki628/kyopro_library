---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/random/mt.hpp
    title: src/random/mt.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/random/rand_prime.hpp
    title: src/random/rand_prime.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/random/mt.hpp\"\
    \n\n// \u30B7\u30FC\u30C9\u751F\u6210\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    #line 4 \"src/random/randrange.hpp\"\n\n// [l,r)\u306E\u7BC4\u56F2\u3067\u4E71\
    \u6570\u751F\u6210\nll randrange(ll l, ll r) {\n    uniform_int_distribution<ll>\
    \ rand(l, r - 1);\n    return rand(mt);\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"mt.hpp\"\n\n// [l,r)\u306E\
    \u7BC4\u56F2\u3067\u4E71\u6570\u751F\u6210\nll randrange(ll l, ll r) {\n    uniform_int_distribution<ll>\
    \ rand(l, r - 1);\n    return rand(mt);\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/random/mt.hpp
  isVerificationFile: false
  path: src/random/randrange.hpp
  requiredBy:
  - src/random/rand_prime.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/random/randrange.hpp
layout: document
redirect_from:
- /library/src/random/randrange.hpp
- /library/src/random/randrange.hpp.html
title: src/random/randrange.hpp
---