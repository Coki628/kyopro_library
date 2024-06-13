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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/numbers/pythagorean_triple.hpp\"\
    \n\n// \u30D4\u30BF\u30B4\u30E9\u30B9\u6570(\u672A\u6574\u5099\u3002\u91CD\u8907\
    \u524A\u9664\u3068\u304Bgcd\u3067\u4E92\u3044\u306B\u7D20\u3068\u304B\u8003\u3048\
    \u3066\u306A\u3044\u3002)\nvector<ll> pythagorean_triple(ll m, ll n) {\n    ll\
    \ a = abs(pow(m, 2) - pow(n, 2));\n    ll b = 2 * m * n;\n    ll c = pow(m, 2)\
    \ + pow(n, 2);\n    vector<ll> res = {a, b, c};\n    sort(ALL(res));\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u30D4\u30BF\u30B4\u30E9\u30B9\
    \u6570(\u672A\u6574\u5099\u3002\u91CD\u8907\u524A\u9664\u3068\u304Bgcd\u3067\u4E92\
    \u3044\u306B\u7D20\u3068\u304B\u8003\u3048\u3066\u306A\u3044\u3002)\nvector<ll>\
    \ pythagorean_triple(ll m, ll n) {\n    ll a = abs(pow(m, 2) - pow(n, 2));\n \
    \   ll b = 2 * m * n;\n    ll c = pow(m, 2) + pow(n, 2);\n    vector<ll> res =\
    \ {a, b, c};\n    sort(ALL(res));\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/pythagorean_triple.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/pythagorean_triple.hpp
layout: document
redirect_from:
- /library/src/numbers/pythagorean_triple.hpp
- /library/src/numbers/pythagorean_triple.hpp.html
title: src/numbers/pythagorean_triple.hpp
---
