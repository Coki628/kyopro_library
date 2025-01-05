---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/BiConnectedComponents.hpp
    title: src/graph/BiConnectedComponents.hpp
  - icon: ':warning:'
    path: src/graph/BlockCutTree.hpp
    title: src/graph/BlockCutTree.hpp
  - icon: ':warning:'
    path: src/graph/TwoEdgeConnectedComponents.hpp
    title: src/graph/TwoEdgeConnectedComponents.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/graph/lowlink.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/LowLink.hpp\"\
    \n\n// Low Link\n// see: https://nyaannyaan.github.io/library/graph/lowlink.hpp\n\
    // \u30FB\u30B0\u30E9\u30D5\u306E\u6A4B\u3068\u95A2\u7BC0\u70B9\u3092\u5217\u6319\
    \u3059\u308B\u3002\n// \u30FB\u6A4B\uFF1A\u305D\u308C\u3092\u53D6\u308A\u9664\u304F\
    \u3068\u9023\u7D50\u3067\u306A\u304F\u306A\u308B\u3088\u3046\u306A\u8FBA\n// \u30FB\
    \u95A2\u7BC0\u70B9\uFF1A\u305D\u308C\u3092\u53D6\u308A\u9664\u304F\u3068\u9023\
    \u7D50\u3067\u306A\u304F\u306A\u308B\u3088\u3046\u306A\u9802\u70B9\n// bridge:\
    \ \u6A4B(\u8FBA(u,v)\u304Cu < v\u3068\u306A\u308B\u3088\u3046\u306B\u683C\u7D0D\
    )\n// articulations point: \u95A2\u7BC0\u70B9\nstruct LowLink {\n    const vvi\
    \ &g;\n    int N;\n    vector<int> ord, low, articulations, is_arti;\n    vector<pair<int,\
    \ int>> bridges;\n\n    LowLink(const vvi &_g) : g(_g), N(g.size()), ord(N, -1),\
    \ low(N, -1), is_arti(N) {\n        for (int i = 0, k = 0; i < N; i++) {\n   \
    \         if (ord[i] == -1) {\n                k = dfs(i, k, -1);\n          \
    \  }\n        }\n        sort(ALL(bridges));\n    }\n\n    bool is_articulation(int\
    \ u) {\n        return is_arti[u];\n    }\n\n    bool is_bridge(int u, int v)\
    \ {\n        if (u > v) swap(u, v);\n        auto itr = lower_bound(ALL(bridges),\
    \ pii{u, v});\n        return itr != bridges.end() and (*itr) == pii{u, v};\n\
    \    }\n\n    bool has_articulation() {\n        return articulations.size();\n\
    \    }\n\n    bool has_bridge() {\n        return bridges.size();\n    }\n\n \
    \   vector<int> get_articulations() {\n        return articulations;\n    }\n\n\
    \    vector<pii> get_bridges() {\n        return bridges;\n    }\n\nprivate:\n\
    \    int dfs(int idx, int k, int par) {\n        low[idx] = (ord[idx] = k++);\n\
    \        int cnt = 0;\n        bool arti = false, second = false;\n        for\
    \ (auto &to : g[idx]) {\n            if (ord[to] == -1) {\n                cnt++;\n\
    \                k = dfs(to, k, idx);\n                low[idx] = min(low[idx],\
    \ low[to]);\n                arti |= (par != -1) && (low[to] >= ord[idx]);\n \
    \               if (ord[idx] < low[to]) {\n                    bridges.emplace_back(minmax(idx,\
    \ (int)to));\n                }\n            } else if (to != par || second) {\n\
    \                low[idx] = min(low[idx], ord[to]);\n            } else {\n  \
    \              second = true;\n            }\n        }\n        arti |= par ==\
    \ -1 && cnt > 1;\n        if (arti) {\n            articulations.push_back(idx);\n\
    \            is_arti[idx] = true;\n        }\n        return k;\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// Low Link\n// see: https://nyaannyaan.github.io/library/graph/lowlink.hpp\n\
    // \u30FB\u30B0\u30E9\u30D5\u306E\u6A4B\u3068\u95A2\u7BC0\u70B9\u3092\u5217\u6319\
    \u3059\u308B\u3002\n// \u30FB\u6A4B\uFF1A\u305D\u308C\u3092\u53D6\u308A\u9664\u304F\
    \u3068\u9023\u7D50\u3067\u306A\u304F\u306A\u308B\u3088\u3046\u306A\u8FBA\n// \u30FB\
    \u95A2\u7BC0\u70B9\uFF1A\u305D\u308C\u3092\u53D6\u308A\u9664\u304F\u3068\u9023\
    \u7D50\u3067\u306A\u304F\u306A\u308B\u3088\u3046\u306A\u9802\u70B9\n// bridge:\
    \ \u6A4B(\u8FBA(u,v)\u304Cu < v\u3068\u306A\u308B\u3088\u3046\u306B\u683C\u7D0D\
    )\n// articulations point: \u95A2\u7BC0\u70B9\nstruct LowLink {\n    const vvi\
    \ &g;\n    int N;\n    vector<int> ord, low, articulations, is_arti;\n    vector<pair<int,\
    \ int>> bridges;\n\n    LowLink(const vvi &_g) : g(_g), N(g.size()), ord(N, -1),\
    \ low(N, -1), is_arti(N) {\n        for (int i = 0, k = 0; i < N; i++) {\n   \
    \         if (ord[i] == -1) {\n                k = dfs(i, k, -1);\n          \
    \  }\n        }\n        sort(ALL(bridges));\n    }\n\n    bool is_articulation(int\
    \ u) {\n        return is_arti[u];\n    }\n\n    bool is_bridge(int u, int v)\
    \ {\n        if (u > v) swap(u, v);\n        auto itr = lower_bound(ALL(bridges),\
    \ pii{u, v});\n        return itr != bridges.end() and (*itr) == pii{u, v};\n\
    \    }\n\n    bool has_articulation() {\n        return articulations.size();\n\
    \    }\n\n    bool has_bridge() {\n        return bridges.size();\n    }\n\n \
    \   vector<int> get_articulations() {\n        return articulations;\n    }\n\n\
    \    vector<pii> get_bridges() {\n        return bridges;\n    }\n\nprivate:\n\
    \    int dfs(int idx, int k, int par) {\n        low[idx] = (ord[idx] = k++);\n\
    \        int cnt = 0;\n        bool arti = false, second = false;\n        for\
    \ (auto &to : g[idx]) {\n            if (ord[to] == -1) {\n                cnt++;\n\
    \                k = dfs(to, k, idx);\n                low[idx] = min(low[idx],\
    \ low[to]);\n                arti |= (par != -1) && (low[to] >= ord[idx]);\n \
    \               if (ord[idx] < low[to]) {\n                    bridges.emplace_back(minmax(idx,\
    \ (int)to));\n                }\n            } else if (to != par || second) {\n\
    \                low[idx] = min(low[idx], ord[to]);\n            } else {\n  \
    \              second = true;\n            }\n        }\n        arti |= par ==\
    \ -1 && cnt > 1;\n        if (arti) {\n            articulations.push_back(idx);\n\
    \            is_arti[idx] = true;\n        }\n        return k;\n    }\n};"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/LowLink.hpp
  requiredBy:
  - src/graph/BlockCutTree.hpp
  - src/graph/TwoEdgeConnectedComponents.hpp
  - src/graph/BiConnectedComponents.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/LowLink.hpp
layout: document
redirect_from:
- /library/src/graph/LowLink.hpp
- /library/src/graph/LowLink.hpp.html
title: src/graph/LowLink.hpp
---
