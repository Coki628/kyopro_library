---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/graph/LowLink.hpp
    title: src/graph/LowLink.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/graph/two-edge-connected-components.hpp
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
    \            is_arti[idx] = true;\n        }\n        return k;\n    }\n};\n#line\
    \ 4 \"src/graph/TwoEdgeConnectedComponents.hpp\"\n\n// \u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n// see: https://nyaannyaan.github.io/library/graph/two-edge-connected-components.hpp\n\
    // \u30FB\u5143\u306E\u4E00\u822C\u30B0\u30E9\u30D5\u304B\u3089\u3001\u6A4B\u3092\
    \u8FBA\u3001\u305D\u3046\u3067\u306A\u3044\u90E8\u5206\u3092\u9802\u70B9\u306B\
    \u307E\u3068\u3081\u305F\u7E2E\u7D04\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n// \u30FB\
    \u305D\u306E\u7E2E\u7D04\u30B0\u30E9\u30D5\u306F\u6728\u306B\u306A\u308B\u306E\
    \u3067\u3001\u69D8\u3005\u306A\u64CD\u4F5C\u304C\u53EF\u80FD\u306B\u306A\u308B\
    \u3002\nstruct TwoEdgeConnectedComponents {\n    LowLink low;\n\n    TwoEdgeConnectedComponents(const\
    \ vvi &g_)\n        : g(g_),\n          low(g_),\n          comp(g_.size(), -1),\n\
    \          K(0) {\n        for (int i = 0; i < (int)g.size(); i++) {\n       \
    \     if (comp[i] == -1) dfs(i, -1);\n        }\n        groups.resize(K);\n \
    \       tree.resize(K);\n        for (int i = 0; i < (int)g.size(); i++) {\n \
    \           groups[comp[i]].push_back(i);\n        }\n        for (auto &e : low.get_bridges())\
    \ {\n            int u = comp[e.first], v = comp[e.second];\n            tree[u].push_back(v);\n\
    \            tree[v].push_back(u);\n        }\n    };\n\n    // (\u5143\u30B0\u30E9\
    \u30D5\u3067\u306E)\u9802\u70B9k\u306E\u7E2E\u7D04\u30B0\u30E9\u30D5\u4E0A\u3067\
    \u306E\u9802\u70B9\u756A\u53F7\n    int operator[](const int &k) const {\n   \
    \     return comp[k];\n    }\n\n    // \u9023\u7D50\u6210\u5206\u6570(\u7E2E\u7D04\
    \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570)\n    int size() {\n        return\
    \ K;\n    }\n\n    // (\u5143\u30B0\u30E9\u30D5\u3067\u306E)\u9802\u70B9k\u3092\
    \u542B\u3080\u9023\u7D50\u6210\u5206\u306E\u8981\u7D20\u6570\n    int size(int\
    \ k) {\n        return groups[comp[k]].size();\n    }\n\n    // \u9023\u7D50\u6210\
    \u5206\u6BCE\u306B\u307E\u3068\u3081\u305F\u3082\u306E(ACL\u306ESCC\u304C\u8FD4\
    \u3059\u306E\u3068\u540C\u3058\u611F\u3058\u306E)\n    vvi get_groups() {\n  \
    \      return groups;\n    }\n\n    // \u7E2E\u7D04\u30B0\u30E9\u30D5\u3092\u8868\
    \u3059\u96A3\u63A5\u30EA\u30B9\u30C8\n    vvi get_nodes() {\n        return tree;\n\
    \    }\n\nprivate:\n    const vvi g;\n    vector<int> comp;\n    int K;\n    vector<vector<int>>\
    \ groups, tree;\n\n    void dfs(int i, int p) {\n        if (p >= 0 && low.ord[p]\
    \ >= low.low[i]) {\n            comp[i] = comp[p];\n        } else {\n       \
    \     comp[i] = K++;\n        }\n        for (auto &d : g[i]) {\n            if\
    \ (comp[d] == -1) dfs(d, i);\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"LowLink.hpp\"\n\n//\
    \ \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n// see: https://nyaannyaan.github.io/library/graph/two-edge-connected-components.hpp\n\
    // \u30FB\u5143\u306E\u4E00\u822C\u30B0\u30E9\u30D5\u304B\u3089\u3001\u6A4B\u3092\
    \u8FBA\u3001\u305D\u3046\u3067\u306A\u3044\u90E8\u5206\u3092\u9802\u70B9\u306B\
    \u307E\u3068\u3081\u305F\u7E2E\u7D04\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\n// \u30FB\
    \u305D\u306E\u7E2E\u7D04\u30B0\u30E9\u30D5\u306F\u6728\u306B\u306A\u308B\u306E\
    \u3067\u3001\u69D8\u3005\u306A\u64CD\u4F5C\u304C\u53EF\u80FD\u306B\u306A\u308B\
    \u3002\nstruct TwoEdgeConnectedComponents {\n    LowLink low;\n\n    TwoEdgeConnectedComponents(const\
    \ vvi &g_)\n        : g(g_),\n          low(g_),\n          comp(g_.size(), -1),\n\
    \          K(0) {\n        for (int i = 0; i < (int)g.size(); i++) {\n       \
    \     if (comp[i] == -1) dfs(i, -1);\n        }\n        groups.resize(K);\n \
    \       tree.resize(K);\n        for (int i = 0; i < (int)g.size(); i++) {\n \
    \           groups[comp[i]].push_back(i);\n        }\n        for (auto &e : low.get_bridges())\
    \ {\n            int u = comp[e.first], v = comp[e.second];\n            tree[u].push_back(v);\n\
    \            tree[v].push_back(u);\n        }\n    };\n\n    // (\u5143\u30B0\u30E9\
    \u30D5\u3067\u306E)\u9802\u70B9k\u306E\u7E2E\u7D04\u30B0\u30E9\u30D5\u4E0A\u3067\
    \u306E\u9802\u70B9\u756A\u53F7\n    int operator[](const int &k) const {\n   \
    \     return comp[k];\n    }\n\n    // \u9023\u7D50\u6210\u5206\u6570(\u7E2E\u7D04\
    \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570)\n    int size() {\n        return\
    \ K;\n    }\n\n    // (\u5143\u30B0\u30E9\u30D5\u3067\u306E)\u9802\u70B9k\u3092\
    \u542B\u3080\u9023\u7D50\u6210\u5206\u306E\u8981\u7D20\u6570\n    int size(int\
    \ k) {\n        return groups[comp[k]].size();\n    }\n\n    // \u9023\u7D50\u6210\
    \u5206\u6BCE\u306B\u307E\u3068\u3081\u305F\u3082\u306E(ACL\u306ESCC\u304C\u8FD4\
    \u3059\u306E\u3068\u540C\u3058\u611F\u3058\u306E)\n    vvi get_groups() {\n  \
    \      return groups;\n    }\n\n    // \u7E2E\u7D04\u30B0\u30E9\u30D5\u3092\u8868\
    \u3059\u96A3\u63A5\u30EA\u30B9\u30C8\n    vvi get_nodes() {\n        return tree;\n\
    \    }\n\nprivate:\n    const vvi g;\n    vector<int> comp;\n    int K;\n    vector<vector<int>>\
    \ groups, tree;\n\n    void dfs(int i, int p) {\n        if (p >= 0 && low.ord[p]\
    \ >= low.low[i]) {\n            comp[i] = comp[p];\n        } else {\n       \
    \     comp[i] = K++;\n        }\n        for (auto &d : g[i]) {\n            if\
    \ (comp[d] == -1) dfs(d, i);\n        }\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/graph/LowLink.hpp
  isVerificationFile: false
  path: src/graph/TwoEdgeConnectedComponents.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/TwoEdgeConnectedComponents.hpp
layout: document
redirect_from:
- /library/src/graph/TwoEdgeConnectedComponents.hpp
- /library/src/graph/TwoEdgeConnectedComponents.hpp.html
title: src/graph/TwoEdgeConnectedComponents.hpp
---
