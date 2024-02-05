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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/centroid_decomposition.hpp\"\
    \n\n// \u91CD\u5FC3\u5206\u89E3\n// \u30FB\u96A3\u63A5\u30EA\u30B9\u30C8nodes\u3092\
    \u6E21\u305B\u3070\u91CD\u5FC3\u5206\u89E3\u306E\u6728\u3092\u69CB\u7BC9\u3059\
    \u308B\u3002\n// \u30FB\u69CB\u7BC9\u4E2D\u306B\u4F55\u304B\u3057\u305F\u3044\u5834\
    \u5408\u306F\u3001\u30E9\u30E0\u30C0\u306A\u306E\u3067\u30E1\u30A4\u30F3\u306E\
    \u30B3\u30FC\u30C9\u5185\u306B\u9069\u5F53\u306B\u8CBC\u3063\u3066\u3001\n// \u3000\
    rec\u95A2\u6570\u5185\u3092\u9069\u5F53\u306B\u3061\u3087\u3063\u3068\u3044\u3058\
    \u3063\u3066\u5FC5\u8981\u306A\u51E6\u7406\u3092\u66F8\u304D\u8DB3\u305B\u3070\
    OK\u3002\n// \u30FB\u69CB\u7BC9\u3057\u305F\u6728\u306E\u8FBA\u60C5\u5831\u3067\
    \u5F8C\u304B\u3089\u305D\u308C\u4F7F\u3063\u3066\u8272\u3005\u3084\u308B\u6642\
    \u306F\u666E\u901A\u306B\u623B\u308A\u5024\u306Epar\u4F7F\u3048\u3070OK\u3002\n\
    auto centroid_decomposition = [](const vvi &nodes) -> vector<int> {\n    int N\
    \ = nodes.size();\n    vector<int> subsz(N), centroids, par(N);\n    vector<bool>\
    \ used(N);\n    // \u90E8\u5206\u6728\u30B5\u30A4\u30BA\u306E\u518D\u8A08\u7B97\
    \n    auto dfs_sz = [&](auto &&f, int u, int prv) -> void {\n        subsz[u]\
    \ = 1;\n        for (int v : nodes[u]) {\n            if (v == prv or used[v])\
    \ continue;\n            f(f, v, u);\n            subsz[u] += subsz[v];\n    \
    \    }\n    };\n    // u\u3092\u6839\u3068\u3057\u305F\u90E8\u5206\u6728\u306E\
    \u91CD\u5FC3\u3092\u6C42\u3081\u308BDFS\n    auto get_centroids = [&](auto &&f,\
    \ int u, int prv, int sz) -> void {\n        subsz[u] = 1;\n        for (int v\
    \ : nodes[u]) {\n            if (v == prv or used[v]) continue;\n            f(f,\
    \ v, u, sz);\n            subsz[u] += subsz[v];\n        }\n        bool iscent\
    \ = true;\n        for (int v : nodes[u]) {\n            if (v == prv or used[v])\
    \ continue;\n            if (subsz[v] > sz / 2) {\n                iscent = false;\n\
    \                break;\n            }\n        }\n        if (iscent and sz -\
    \ subsz[u] <= sz / 2) {\n            centroids.pb(u);\n        }\n    };\n   \
    \ // \u91CD\u5FC3\u5206\u89E3\u30E1\u30A4\u30F3\u51E6\u7406(\u3053\u306E\u4E2D\
    \u306B\u5FC5\u8981\u306A\u51E6\u7406\u3092\u8DB3\u3059)\n    auto rec = [&](auto&&\
    \ f, int u, int prv, int sz) -> void {\n        centroids.clear();\n        get_centroids(get_centroids,\
    \ u, prv, sz);\n        int v = centroids[0];\n        used[v] = true;\n     \
    \   dfs_sz(dfs_sz, v, -1);\n        par[v] = prv;\n        for (int w : nodes[v])\
    \ {\n            if (used[w]) continue;\n            f(f, w, v, subsz[w]);\n \
    \       }\n    };\n    rec(rec, 0, -1, N);\n    return par;\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u91CD\u5FC3\u5206\u89E3\n\
    // \u30FB\u96A3\u63A5\u30EA\u30B9\u30C8nodes\u3092\u6E21\u305B\u3070\u91CD\u5FC3\
    \u5206\u89E3\u306E\u6728\u3092\u69CB\u7BC9\u3059\u308B\u3002\n// \u30FB\u69CB\u7BC9\
    \u4E2D\u306B\u4F55\u304B\u3057\u305F\u3044\u5834\u5408\u306F\u3001\u30E9\u30E0\
    \u30C0\u306A\u306E\u3067\u30E1\u30A4\u30F3\u306E\u30B3\u30FC\u30C9\u5185\u306B\
    \u9069\u5F53\u306B\u8CBC\u3063\u3066\u3001\n// \u3000rec\u95A2\u6570\u5185\u3092\
    \u9069\u5F53\u306B\u3061\u3087\u3063\u3068\u3044\u3058\u3063\u3066\u5FC5\u8981\
    \u306A\u51E6\u7406\u3092\u66F8\u304D\u8DB3\u305B\u3070OK\u3002\n// \u30FB\u69CB\
    \u7BC9\u3057\u305F\u6728\u306E\u8FBA\u60C5\u5831\u3067\u5F8C\u304B\u3089\u305D\
    \u308C\u4F7F\u3063\u3066\u8272\u3005\u3084\u308B\u6642\u306F\u666E\u901A\u306B\
    \u623B\u308A\u5024\u306Epar\u4F7F\u3048\u3070OK\u3002\nauto centroid_decomposition\
    \ = [](const vvi &nodes) -> vector<int> {\n    int N = nodes.size();\n    vector<int>\
    \ subsz(N), centroids, par(N);\n    vector<bool> used(N);\n    // \u90E8\u5206\
    \u6728\u30B5\u30A4\u30BA\u306E\u518D\u8A08\u7B97\n    auto dfs_sz = [&](auto &&f,\
    \ int u, int prv) -> void {\n        subsz[u] = 1;\n        for (int v : nodes[u])\
    \ {\n            if (v == prv or used[v]) continue;\n            f(f, v, u);\n\
    \            subsz[u] += subsz[v];\n        }\n    };\n    // u\u3092\u6839\u3068\
    \u3057\u305F\u90E8\u5206\u6728\u306E\u91CD\u5FC3\u3092\u6C42\u3081\u308BDFS\n\
    \    auto get_centroids = [&](auto &&f, int u, int prv, int sz) -> void {\n  \
    \      subsz[u] = 1;\n        for (int v : nodes[u]) {\n            if (v == prv\
    \ or used[v]) continue;\n            f(f, v, u, sz);\n            subsz[u] +=\
    \ subsz[v];\n        }\n        bool iscent = true;\n        for (int v : nodes[u])\
    \ {\n            if (v == prv or used[v]) continue;\n            if (subsz[v]\
    \ > sz / 2) {\n                iscent = false;\n                break;\n     \
    \       }\n        }\n        if (iscent and sz - subsz[u] <= sz / 2) {\n    \
    \        centroids.pb(u);\n        }\n    };\n    // \u91CD\u5FC3\u5206\u89E3\u30E1\
    \u30A4\u30F3\u51E6\u7406(\u3053\u306E\u4E2D\u306B\u5FC5\u8981\u306A\u51E6\u7406\
    \u3092\u8DB3\u3059)\n    auto rec = [&](auto&& f, int u, int prv, int sz) -> void\
    \ {\n        centroids.clear();\n        get_centroids(get_centroids, u, prv,\
    \ sz);\n        int v = centroids[0];\n        used[v] = true;\n        dfs_sz(dfs_sz,\
    \ v, -1);\n        par[v] = prv;\n        for (int w : nodes[v]) {\n         \
    \   if (used[w]) continue;\n            f(f, w, v, subsz[w]);\n        }\n   \
    \ };\n    rec(rec, 0, -1, N);\n    return par;\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-02-06 01:26:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/src/graph/centroid_decomposition.hpp
- /library/src/graph/centroid_decomposition.hpp.html
title: src/graph/centroid_decomposition.hpp
---
