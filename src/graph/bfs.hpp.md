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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/get_diameter.hpp
    title: src/graph/get_diameter.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/graph/bfs.hpp\"\
    \n\n// BFS\n// \u30FB\u30E1\u30A4\u30F3\u306E\u51E6\u7406\u5185\u306B\u30D9\u30BF\
    \u8CBC\u308A\u3057\u3066\u4E2D\u8EAB\u3061\u3087\u3063\u3068\u3044\u3058\u308B\
    \u304C\u3059\u3050\u3067\u304D\u308B\u3088\u3046\u306B\u30E9\u30E0\u30C0\u306B\
    \u3057\u305F\u3002\n// \u3000(\u672C\u5F53\u306F[&]\u3067\u96D1\u306B\u30AD\u30E3\
    \u30D7\u30C1\u30E3\u3057\u305F\u3044\u3051\u3069\u3001\u3053\u308C\u3084\u308B\
    \u3068\u30B0\u30ED\u30FC\u30D0\u30EB\u306B\u7F6E\u3051\u306A\u3044\u307F\u305F\
    \u3044\u306A\u306E\u3067\u3002)\nauto bfs = [](const vvi &nodes, const vector<int>\
    \ &src) {\n    int N = nodes.size();\n    vector<ll> res(N, INF);\n    queue<int>\
    \ que;\n    for (int s : src) {\n        res[s] = 0;\n        que.push(s);\n \
    \   }\n    while (!que.empty()) {\n        int u = que.front();\n        que.pop();\n\
    \        for (auto v : nodes[u]) {\n            if (chmin(res[v], res[u] + 1))\
    \ {\n                que.push(v);\n            }\n        }\n    }\n    return\
    \ res;\n};\n"
  code: "#pragma once\n#include \"../common/chmin.hpp\"\n#include \"../macros.hpp\"\
    \n\n// BFS\n// \u30FB\u30E1\u30A4\u30F3\u306E\u51E6\u7406\u5185\u306B\u30D9\u30BF\
    \u8CBC\u308A\u3057\u3066\u4E2D\u8EAB\u3061\u3087\u3063\u3068\u3044\u3058\u308B\
    \u304C\u3059\u3050\u3067\u304D\u308B\u3088\u3046\u306B\u30E9\u30E0\u30C0\u306B\
    \u3057\u305F\u3002\n// \u3000(\u672C\u5F53\u306F[&]\u3067\u96D1\u306B\u30AD\u30E3\
    \u30D7\u30C1\u30E3\u3057\u305F\u3044\u3051\u3069\u3001\u3053\u308C\u3084\u308B\
    \u3068\u30B0\u30ED\u30FC\u30D0\u30EB\u306B\u7F6E\u3051\u306A\u3044\u307F\u305F\
    \u3044\u306A\u306E\u3067\u3002)\nauto bfs = [](const vvi &nodes, const vector<int>\
    \ &src) {\n    int N = nodes.size();\n    vector<ll> res(N, INF);\n    queue<int>\
    \ que;\n    for (int s : src) {\n        res[s] = 0;\n        que.push(s);\n \
    \   }\n    while (!que.empty()) {\n        int u = que.front();\n        que.pop();\n\
    \        for (auto v : nodes[u]) {\n            if (chmin(res[v], res[u] + 1))\
    \ {\n                que.push(v);\n            }\n        }\n    }\n    return\
    \ res;\n};\n"
  dependsOn:
  - src/common/chmin.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/bfs.hpp
  requiredBy:
  - src/graph/get_diameter.hpp
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bfs.test.cpp
documentation_of: src/graph/bfs.hpp
layout: document
redirect_from:
- /library/src/graph/bfs.hpp
- /library/src/graph/bfs.hpp.html
title: src/graph/bfs.hpp
---