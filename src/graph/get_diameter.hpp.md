---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/bfs.hpp
    title: src/graph/bfs.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/common/chmin.hpp\"\
    \n\ntemplate<typename T>\nbool chmin(T &x, T y) {\n    return (y < x) ? x = y,\
    \ true : false;\n}\n#line 4 \"src/graph/bfs.hpp\"\n\n// BFS\n// \u30FB\u30E1\u30A4\
    \u30F3\u306E\u51E6\u7406\u5185\u306B\u30D9\u30BF\u8CBC\u308A\u3057\u3066\u4E2D\
    \u8EAB\u3061\u3087\u3063\u3068\u3044\u3058\u308B\u304C\u3059\u3050\u3067\u304D\
    \u308B\u3088\u3046\u306B\u30E9\u30E0\u30C0\u306B\u3057\u305F\u3002\n// \u3000\
    (\u672C\u5F53\u306F[&]\u3067\u96D1\u306B\u30AD\u30E3\u30D7\u30C1\u30E3\u3057\u305F\
    \u3044\u3051\u3069\u3001\u3053\u308C\u3084\u308B\u3068\u30B0\u30ED\u30FC\u30D0\
    \u30EB\u306B\u7F6E\u3051\u306A\u3044\u307F\u305F\u3044\u306A\u306E\u3067\u3002\
    )\nauto bfs = [](const vvi &nodes, const vector<int> &src) {\n    int N = nodes.size();\n\
    \    vector<ll> res(N, INF);\n    queue<int> que;\n    for (int s : src) {\n \
    \       res[s] = 0;\n        que.push(s);\n    }\n    while (que.size()) {\n \
    \       int u = que.front();\n        que.pop();\n        for (auto v : nodes[u])\
    \ {\n            if (chmin(res[v], res[u] + 1)) {\n                que.push(v);\n\
    \            }\n        }\n    }\n    return res;\n};\n#line 4 \"src/graph/get_diameter.hpp\"\
    \n\nvector<ll> _bfs(const vvpil &nodes, int s) {\n    int N = nodes.size();\n\
    \    vector<ll> res(N, INF);\n    queue<int> que;\n    res[s] = 0;\n    que.push(s);\n\
    \    while (!que.empty()) {\n        int u = que.front();\n        que.pop();\n\
    \        for (auto [v, c] : nodes[u]) {\n            if (chmin(res[v], res[u]\
    \ + c)) {\n                que.push(v);\n            }\n        }\n    }\n   \
    \ return res;\n}\n\n// \u6728\u306E\u76F4\u5F84\ntuple<int, int, int> get_diameter(const\
    \ vvi &nodes) {\n    auto res1 = bfs(nodes, {0});\n    int u = max_element(ALL(res1))\
    \ - res1.begin();\n    auto res2 = bfs(nodes, {u});\n    int v = max_element(ALL(res2))\
    \ - res2.begin();\n    return {res2[v], u, v};\n}\n\n// \u91CD\u307F\u4ED8\u304D\
    \ntuple<ll, int, int> get_diameter(const vvpil &nodes) {\n    auto res1 = _bfs(nodes,\
    \ {0});\n    int u = max_element(ALL(res1)) - res1.begin();\n    auto res2 = _bfs(nodes,\
    \ {u});\n    int v = max_element(ALL(res2)) - res2.begin();\n    return {res2[v],\
    \ u, v};\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"bfs.hpp\"\n\nvector<ll>\
    \ _bfs(const vvpil &nodes, int s) {\n    int N = nodes.size();\n    vector<ll>\
    \ res(N, INF);\n    queue<int> que;\n    res[s] = 0;\n    que.push(s);\n    while\
    \ (!que.empty()) {\n        int u = que.front();\n        que.pop();\n       \
    \ for (auto [v, c] : nodes[u]) {\n            if (chmin(res[v], res[u] + c)) {\n\
    \                que.push(v);\n            }\n        }\n    }\n    return res;\n\
    }\n\n// \u6728\u306E\u76F4\u5F84\ntuple<int, int, int> get_diameter(const vvi\
    \ &nodes) {\n    auto res1 = bfs(nodes, {0});\n    int u = max_element(ALL(res1))\
    \ - res1.begin();\n    auto res2 = bfs(nodes, {u});\n    int v = max_element(ALL(res2))\
    \ - res2.begin();\n    return {res2[v], u, v};\n}\n\n// \u91CD\u307F\u4ED8\u304D\
    \ntuple<ll, int, int> get_diameter(const vvpil &nodes) {\n    auto res1 = _bfs(nodes,\
    \ {0});\n    int u = max_element(ALL(res1)) - res1.begin();\n    auto res2 = _bfs(nodes,\
    \ {u});\n    int v = max_element(ALL(res2)) - res2.begin();\n    return {res2[v],\
    \ u, v};\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/graph/bfs.hpp
  - src/common/chmin.hpp
  isVerificationFile: false
  path: src/graph/get_diameter.hpp
  requiredBy: []
  timestamp: '2024-08-12 17:44:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/get_diameter.hpp
layout: document
redirect_from:
- /library/src/graph/get_diameter.hpp
- /library/src/graph/get_diameter.hpp.html
title: src/graph/get_diameter.hpp
---
