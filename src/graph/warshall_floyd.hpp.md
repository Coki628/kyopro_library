---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
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
  bundledCode: "#line 2 \"src/common/chmin.hpp\"\n\ntemplate<typename T>\nbool chmin(T\
    \ &x, T y) {\n    return (y < x) ? x = y, true : false;\n}\n#line 2 \"src/base.hpp\"\
    \n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull = unsigned long\
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/graph/warshall_floyd.hpp\"\
    \n\ntemplate<typename T>\nvv<T> warshall_floyd(vv<T> G) {\n    ll N = G.size();\n\
    \    rep(i, N) G[i][i] = 0;\n    rep(k, N) {\n        rep(i, N) {\n          \
    \  rep(j, N) {\n                chmin(G[i][j], G[i][k] + G[k][j]);\n         \
    \   }\n        }\n    }\n    rep(i, N) {\n        if (G[i][i] < 0) {\n       \
    \     return {};\n        }\n    }\n    return G;\n}\n\n// \u7121\u5411\u8FBA\u306A\
    \u3089\u3053\u308C\u3067\u3082\u5927\u4E08\u592B\u305D\u3046\u3002\n// template<typename\
    \ T>\n// vv<T> warshall_floyd(vv<T>> G) {\n//     ll N = G.size();\n//     rep(i,\
    \ N) G[i][i] = 0;\n//     rep(k, N) {\n//         rep(i, N) {\n//            \
    \ rep(j, i + 1, N) {\n//                 chmin(G[i][j], G[i][k] + G[k][j]);\n\
    //                 chmin(G[j][i], G[j][k] + G[k][i]);\n//             }\n//  \
    \       }\n//     }\n//     rep(i, N) {\n//         if (G[i][i] < 0) {\n//   \
    \          return {};\n//         }\n//     }\n//     return G;\n// }\n"
  code: "#pragma once\n#include \"../common/chmin.hpp\"\n#include \"../macros.hpp\"\
    \n\ntemplate<typename T>\nvv<T> warshall_floyd(vv<T> G) {\n    ll N = G.size();\n\
    \    rep(i, N) G[i][i] = 0;\n    rep(k, N) {\n        rep(i, N) {\n          \
    \  rep(j, N) {\n                chmin(G[i][j], G[i][k] + G[k][j]);\n         \
    \   }\n        }\n    }\n    rep(i, N) {\n        if (G[i][i] < 0) {\n       \
    \     return {};\n        }\n    }\n    return G;\n}\n\n// \u7121\u5411\u8FBA\u306A\
    \u3089\u3053\u308C\u3067\u3082\u5927\u4E08\u592B\u305D\u3046\u3002\n// template<typename\
    \ T>\n// vv<T> warshall_floyd(vv<T>> G) {\n//     ll N = G.size();\n//     rep(i,\
    \ N) G[i][i] = 0;\n//     rep(k, N) {\n//         rep(i, N) {\n//            \
    \ rep(j, i + 1, N) {\n//                 chmin(G[i][j], G[i][k] + G[k][j]);\n\
    //                 chmin(G[j][i], G[j][k] + G[k][i]);\n//             }\n//  \
    \       }\n//     }\n//     rep(i, N) {\n//         if (G[i][i] < 0) {\n//   \
    \          return {};\n//         }\n//     }\n//     return G;\n// }\n"
  dependsOn:
  - src/common/chmin.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/src/graph/warshall_floyd.hpp
- /library/src/graph/warshall_floyd.hpp.html
title: src/graph/warshall_floyd.hpp
---
