---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/toint.hpp
    title: src/common/toint.hpp
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
    \ namespace std;\n#line 3 \"src/common/toint.hpp\"\n\nll toint(string s) {\n \
    \   // \u3053\u3093\u306A\u4FBF\u5229\u306A\u306E\u3042\u3063\u305F\u308F\u2026\
    \u3002\n    return stoll(s);\n}\n\nint toint(char num) {\n    return num - '0';\n\
    }\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull = unsigned long\
    \ long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\nusing pii = pair<int,\
    \ int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int, ll>;\ntemplate<typename\
    \ T>\nusing vv = vector<vector<T>>;\nusing vvl = vv<ll>;\nusing vvi = vv<int>;\n\
    using vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil = vv<pil>;\n#define\
    \ name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4, rep3,\
    \ rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i < _aa;\
    \ i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define rep3(i,\
    \ a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c < 0 && a\
    \ >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b); i--)\n\
    #define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n#define\
    \ ALL(A) begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/numbers/ntod.hpp\"\
    \n\n// N\u9032\u6570\u6587\u5B57\u5217S\u309210\u9032\u6570\u306B\nll ntod(string\
    \ S, ll n) {\n    ll res = 0, k = 1;\n    reverse(ALL(S));\n    for (char &c :\
    \ S) {\n        res += k * toint(c);\n        k *= n;\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n#include \"../common/toint.hpp\"\n#include \"../macros.hpp\"\
    \n\n// N\u9032\u6570\u6587\u5B57\u5217S\u309210\u9032\u6570\u306B\nll ntod(string\
    \ S, ll n) {\n    ll res = 0, k = 1;\n    reverse(ALL(S));\n    for (char &c :\
    \ S) {\n        res += k * toint(c);\n        k *= n;\n    }\n    return res;\n\
    }\n"
  dependsOn:
  - src/common/toint.hpp
  - src/base.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/numbers/ntod.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/ntod.hpp
layout: document
redirect_from:
- /library/src/numbers/ntod.hpp
- /library/src/numbers/ntod.hpp.html
title: src/numbers/ntod.hpp
---
