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
    path: src/graph/Dijkstra.hpp
    title: src/graph/Dijkstra.hpp
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
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"\
    src/common/chmin.hpp\"\n\ntemplate<typename T>\nbool chmin(T &x, T y) {\n    return\
    \ (y < x) ? x = y, true : false;\n}\n#line 4 \"src/graph/_dijkstra.hpp\"\n\n//\
    \ \u203B\u7D50\u5C40\u3053\u3063\u3061\u306E\u304C\u4F7F\u3044\u52DD\u624B\u3044\
    \u3044\u304B\u3089\u6B8B\u3057\u3066\u304A\u304F\u3002\n\n// \u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9\ntemplate<typename T>\nvector<T> dijkstra(const vector<vector<pair<int,\
    \ T>>> &nodes, int src, int goal=-1) {\n\n    int N = nodes.size();\n    vector<T>\
    \ res(N, INF);\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> que;\n    res[src] = 0;\n    que.push({0, src});\n\n    while (!que.empty())\
    \ {\n        auto [dist, u] = que.top(); que.pop();\n        if (u == goal) return\
    \ res;\n        if (res[u] < dist) continue;\n        for (auto [v, cost] : nodes[u])\
    \ {\n            if (chmin(res[v], dist+cost)) {\n                que.push({dist+cost,\
    \ v});\n            }\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"../common/chmin.hpp\"\
    \n\n// \u203B\u7D50\u5C40\u3053\u3063\u3061\u306E\u304C\u4F7F\u3044\u52DD\u624B\
    \u3044\u3044\u304B\u3089\u6B8B\u3057\u3066\u304A\u304F\u3002\n\n// \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\ntemplate<typename T>\nvector<T> dijkstra(const vector<vector<pair<int,\
    \ T>>> &nodes, int src, int goal=-1) {\n\n    int N = nodes.size();\n    vector<T>\
    \ res(N, INF);\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> que;\n    res[src] = 0;\n    que.push({0, src});\n\n    while (!que.empty())\
    \ {\n        auto [dist, u] = que.top(); que.pop();\n        if (u == goal) return\
    \ res;\n        if (res[u] < dist) continue;\n        for (auto [v, cost] : nodes[u])\
    \ {\n            if (chmin(res[v], dist+cost)) {\n                que.push({dist+cost,\
    \ v});\n            }\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/chmin.hpp
  isVerificationFile: false
  path: src/graph/_dijkstra.hpp
  requiredBy:
  - src/graph/Dijkstra.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/_dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/_dijkstra.hpp
- /library/src/graph/_dijkstra.hpp.html
title: src/graph/_dijkstra.hpp
---
