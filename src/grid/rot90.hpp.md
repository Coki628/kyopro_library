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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/grid/rot90.hpp\"\
    \n\n// \u30B0\u30EA\u30C3\u30C9\u3092\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\
    \u8EE2\nvector<string> rot90(const vector<string> &grid) {\n    int H = grid.size();\n\
    \    int W = grid[0].size();\n    vector<string> res(W, string(H, '*'));\n   \
    \ rep(i, H) {\n        rep(j, W) {\n            res[j][H - i - 1] = grid[i][j];\n\
    \        }\n    }\n    return res;\n}\n\ntemplate<typename T>\nvv<T> rot90(const\
    \ vv<T> &grid) {\n    int H = grid.size();\n    int W = grid[0].size();\n    vv<T>\
    \ res(W, vector<T>(H));\n    rep(i, H) {\n        rep(j, W) {\n            res[j][H\
    \ - i - 1] = grid[i][j];\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u30B0\u30EA\u30C3\u30C9\u3092\
    \u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\nvector<string> rot90(const\
    \ vector<string> &grid) {\n    int H = grid.size();\n    int W = grid[0].size();\n\
    \    vector<string> res(W, string(H, '*'));\n    rep(i, H) {\n        rep(j, W)\
    \ {\n            res[j][H - i - 1] = grid[i][j];\n        }\n    }\n    return\
    \ res;\n}\n\ntemplate<typename T>\nvv<T> rot90(const vv<T> &grid) {\n    int H\
    \ = grid.size();\n    int W = grid[0].size();\n    vv<T> res(W, vector<T>(H));\n\
    \    rep(i, H) {\n        rep(j, W) {\n            res[j][H - i - 1] = grid[i][j];\n\
    \        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/grid/rot90.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:50:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/rot90.hpp
layout: document
redirect_from:
- /library/src/grid/rot90.hpp
- /library/src/grid/rot90.hpp.html
title: src/grid/rot90.hpp
---
