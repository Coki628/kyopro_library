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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/dijkstra_v2.hpp\"\
    \n\n// \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9(O(V^2)\u7248) \u203B\u672Averify\n\
    template<typename T>\nvector<T> dijkstra(const vv<T> &G, int src) {\n    int N\
    \ = G.size();\n    vector<T> dist(N, INF);\n    vector<bool> used(N);\n\n    dist[src]\
    \ = 0;\n    while (1) {\n        int v = -1;\n        rep(u, N) {\n          \
    \  if (!used[u] and (v == -1 or dist[u] < dist[v])) {\n                v = u;\n\
    \            }\n        }\n        if (v == -1) {\n            break;\n      \
    \  }\n        used[v] = true;\n        rep(u, N) {\n            dist[u] = min(dist[u],\
    \ dist[v] + G[v][u]);\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u30C0\u30A4\u30AF\u30B9\u30C8\
    \u30E9(O(V^2)\u7248) \u203B\u672Averify\ntemplate<typename T>\nvector<T> dijkstra(const\
    \ vv<T> &G, int src) {\n    int N = G.size();\n    vector<T> dist(N, INF);\n \
    \   vector<bool> used(N);\n\n    dist[src] = 0;\n    while (1) {\n        int\
    \ v = -1;\n        rep(u, N) {\n            if (!used[u] and (v == -1 or dist[u]\
    \ < dist[v])) {\n                v = u;\n            }\n        }\n        if\
    \ (v == -1) {\n            break;\n        }\n        used[v] = true;\n      \
    \  rep(u, N) {\n            dist[u] = min(dist[u], dist[v] + G[v][u]);\n     \
    \   }\n    }\n    return dist;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/dijkstra_v2.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:50:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/dijkstra_v2.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra_v2.hpp
- /library/src/graph/dijkstra_v2.hpp.html
title: src/graph/dijkstra_v2.hpp
---
