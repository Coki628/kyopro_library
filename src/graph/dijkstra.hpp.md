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
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/_Dijkstra.hpp
    title: src/graph/_Dijkstra.hpp
  - icon: ':warning:'
    path: src/graph/_dijkstra.hpp
    title: src/graph/_dijkstra.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/graph/dijkstra.hpp\"\
    \n\n// \u203B\u7D50\u5C40\u3053\u3063\u3061\u306E\u304C\u4F7F\u3044\u52DD\u624B\
    \u3044\u3044\u304B\u3089\u6B8B\u3057\u3066\u304A\u304F\u3002\n\n// \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\n// \u30FB\u30E1\u30A4\u30F3\u306E\u51E6\u7406\u5185\u306B\
    \u30D9\u30BF\u8CBC\u308A\u3057\u3066\u4E2D\u8EAB\u3061\u3087\u3063\u3068\u3044\
    \u3058\u308B\u304C\u3059\u3050\u3067\u304D\u308B\u3088\u3046\u306B\u30E9\u30E0\
    \u30C0\u306B\u3057\u305F\u3002\nauto dijkstra = [](const vvpil &nodes, const vector<int>\
    \ &src, int goal = -1) {\n    int N = nodes.size();\n    vector<ll> res(N, numeric_limits<ll>::max()\
    \ / 2);\n    priority_queue<pli, vector<pli>, greater<pli>> que;\n    for (auto\
    \ s : src) {\n        res[s] = 0;\n        que.push({0, s});\n    }\n    while\
    \ (que.size()) {\n        auto [dist, u] = que.top();\n        que.pop();\n  \
    \      if (u == goal) return res;\n        if (res[u] < dist) continue;\n    \
    \    for (auto [v, cost] : nodes[u]) {\n            if (chmin(res[v], dist + cost))\
    \ {\n                que.push({dist + cost, v});\n            }\n        }\n \
    \   }\n    return res;\n};\n"
  code: "#pragma once\n#include \"../common/chmin.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u203B\u7D50\u5C40\u3053\u3063\u3061\u306E\u304C\u4F7F\u3044\u52DD\u624B\
    \u3044\u3044\u304B\u3089\u6B8B\u3057\u3066\u304A\u304F\u3002\n\n// \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\n// \u30FB\u30E1\u30A4\u30F3\u306E\u51E6\u7406\u5185\u306B\
    \u30D9\u30BF\u8CBC\u308A\u3057\u3066\u4E2D\u8EAB\u3061\u3087\u3063\u3068\u3044\
    \u3058\u308B\u304C\u3059\u3050\u3067\u304D\u308B\u3088\u3046\u306B\u30E9\u30E0\
    \u30C0\u306B\u3057\u305F\u3002\nauto dijkstra = [](const vvpil &nodes, const vector<int>\
    \ &src, int goal = -1) {\n    int N = nodes.size();\n    vector<ll> res(N, numeric_limits<ll>::max()\
    \ / 2);\n    priority_queue<pli, vector<pli>, greater<pli>> que;\n    for (auto\
    \ s : src) {\n        res[s] = 0;\n        que.push({0, s});\n    }\n    while\
    \ (que.size()) {\n        auto [dist, u] = que.top();\n        que.pop();\n  \
    \      if (u == goal) return res;\n        if (res[u] < dist) continue;\n    \
    \    for (auto [v, cost] : nodes[u]) {\n            if (chmin(res[v], dist + cost))\
    \ {\n                que.push({dist + cost, v});\n            }\n        }\n \
    \   }\n    return res;\n};\n"
  dependsOn:
  - src/common/chmin.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy:
  - src/graph/_dijkstra.hpp
  - src/graph/_Dijkstra.hpp
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: src/graph/dijkstra.hpp
---
