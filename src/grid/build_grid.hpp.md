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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/grid/build_grid.hpp\"\
    \n\n// \u4F59\u767D\u4ED8\u304D\u30B0\u30EA\u30C3\u30C9\u3092\u69CB\u7BC9\nvector<string>\
    \ build_grid(int H, int W, char intv, int offset = 1) {\n    vector<string> res(H\
    \ + offset * 2);\n    rep(h, offset) res[h] = string(W + offset * 2, intv);\n\
    \    rep(h, offset, H + offset) {\n        string s;\n        cin >> s;\n    \
    \    res[h] = string(offset, intv) + s + string(offset, intv);\n    }\n    rep(h,\
    \ H + offset, H + offset * 2) res[h] = string(W + offset * 2, intv);\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u4F59\u767D\u4ED8\u304D\u30B0\
    \u30EA\u30C3\u30C9\u3092\u69CB\u7BC9\nvector<string> build_grid(int H, int W,\
    \ char intv, int offset = 1) {\n    vector<string> res(H + offset * 2);\n    rep(h,\
    \ offset) res[h] = string(W + offset * 2, intv);\n    rep(h, offset, H + offset)\
    \ {\n        string s;\n        cin >> s;\n        res[h] = string(offset, intv)\
    \ + s + string(offset, intv);\n    }\n    rep(h, H + offset, H + offset * 2) res[h]\
    \ = string(W + offset * 2, intv);\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/grid/build_grid.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/build_grid.hpp
layout: document
redirect_from:
- /library/src/grid/build_grid.hpp
- /library/src/grid/build_grid.hpp.html
title: src/grid/build_grid.hpp
---