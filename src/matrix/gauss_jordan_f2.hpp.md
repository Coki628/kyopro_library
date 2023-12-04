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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/matrix/gauss_jordan_f2.hpp\"\
    \n\n// \u6383\u304D\u51FA\u3057\u6CD5(2\u5024\u7528)\n// \u30FB\u8A08\u7B97\u91CF\
    \uFF1AO(RC^2) \u3053\u308C\u306F\u884C\u304C10\u4E07\u3042\u3063\u3066\u3082\u5217\
    \u304C\u30D3\u30C3\u30C8\u3068\u304B\u5C11\u306A\u3044\u6642\u306F\u901A\u7528\
    \u3059\u308B\u3063\u3066\u3053\u3068\u3002\n// \u30FB\u9023\u7ACB\u65B9\u7A0B\u5F0F\
    \u306E\u89E3\u3067\u306F\u306A\u3044\u4F7F\u3044\u65B9\u3082\u3042\u308B\u3002\
    (zone2021_f) \u305D\u3046\u3044\u3046\u6642\u306Fextended\u304Cfalse\u306B\u306A\
    \u308B\u3002\ntemplate<int BITLEN>\npair<int, vector<bitset<BITLEN>>> gauss_jordan(\n\
    \    int N, int M, const vector<bitset<BITLEN>> &A, bool extended = true\n) {\n\
    \    assert(N == A.size());\n    auto res = A;\n    int rank = 0;\n    rep(col,\
    \ M) {\n        if (extended and col == M - 1) break;\n        int pivot = -1;\n\
    \        rep(row, rank, N) {\n            if (res[row][col]) {\n             \
    \   pivot = row;\n                break;\n            }\n        }\n        if\
    \ (pivot == -1) continue;\n        swap(res[rank], res[pivot]);\n        rep(row,\
    \ N) {\n            if (row != rank and res[row][col]) {\n                res[row]\
    \ ^= res[rank];\n            }\n        }\n        rank++;\n    }\n    // \u89E3\
    \u304C\u3042\u308B\u304B\u78BA\u8A8D\n    rep(row, rank, N) {\n        if (res[row][M\
    \ - 1]) {\n            return {-1, vector<bitset<BITLEN>>()};\n        }\n   \
    \ }\n    return {rank, res};\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u6383\u304D\u51FA\u3057\u6CD5\
    (2\u5024\u7528)\n// \u30FB\u8A08\u7B97\u91CF\uFF1AO(RC^2) \u3053\u308C\u306F\u884C\
    \u304C10\u4E07\u3042\u3063\u3066\u3082\u5217\u304C\u30D3\u30C3\u30C8\u3068\u304B\
    \u5C11\u306A\u3044\u6642\u306F\u901A\u7528\u3059\u308B\u3063\u3066\u3053\u3068\
    \u3002\n// \u30FB\u9023\u7ACB\u65B9\u7A0B\u5F0F\u306E\u89E3\u3067\u306F\u306A\u3044\
    \u4F7F\u3044\u65B9\u3082\u3042\u308B\u3002(zone2021_f) \u305D\u3046\u3044\u3046\
    \u6642\u306Fextended\u304Cfalse\u306B\u306A\u308B\u3002\ntemplate<int BITLEN>\n\
    pair<int, vector<bitset<BITLEN>>> gauss_jordan(\n    int N, int M, const vector<bitset<BITLEN>>\
    \ &A, bool extended = true\n) {\n    assert(N == A.size());\n    auto res = A;\n\
    \    int rank = 0;\n    rep(col, M) {\n        if (extended and col == M - 1)\
    \ break;\n        int pivot = -1;\n        rep(row, rank, N) {\n            if\
    \ (res[row][col]) {\n                pivot = row;\n                break;\n  \
    \          }\n        }\n        if (pivot == -1) continue;\n        swap(res[rank],\
    \ res[pivot]);\n        rep(row, N) {\n            if (row != rank and res[row][col])\
    \ {\n                res[row] ^= res[rank];\n            }\n        }\n      \
    \  rank++;\n    }\n    // \u89E3\u304C\u3042\u308B\u304B\u78BA\u8A8D\n    rep(row,\
    \ rank, N) {\n        if (res[row][M - 1]) {\n            return {-1, vector<bitset<BITLEN>>()};\n\
    \        }\n    }\n    return {rank, res};\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/matrix/gauss_jordan_f2.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/matrix/gauss_jordan_f2.hpp
layout: document
redirect_from:
- /library/src/matrix/gauss_jordan_f2.hpp
- /library/src/matrix/gauss_jordan_f2.hpp.html
title: src/matrix/gauss_jordan_f2.hpp
---
