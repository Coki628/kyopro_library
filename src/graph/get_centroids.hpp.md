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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/get_centroids.hpp\"\
    \n\n// \u6728nodes\u306E\u91CD\u5FC3\u3092\u53D6\u5F97\nvector<int> get_centroids(const\
    \ vvi &nodes) {\n    int N = nodes.size();\n    vector<int> sz(N), centroids;\n\
    \    auto dfs = [&](auto &&f, int u, int prv) -> void {\n        for (int v :\
    \ nodes[u]) {\n            if (v == prv) continue;\n            f(f, v, u);\n\
    \            sz[u] += sz[v];\n        }\n        sz[u]++;\n        bool is_centroid\
    \ = true;\n        for (int v : nodes[u]) {\n            if (v == prv) continue;\n\
    \            if (sz[v] > N / 2) {\n                is_centroid = false;\n    \
    \            break;\n            }\n        }\n        if (is_centroid && N -\
    \ sz[u] <= N / 2) {\n            centroids.pb(u);\n        }\n    };\n    dfs(dfs,\
    \ 0, -1);\n    return centroids;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u6728nodes\u306E\u91CD\u5FC3\
    \u3092\u53D6\u5F97\nvector<int> get_centroids(const vvi &nodes) {\n    int N =\
    \ nodes.size();\n    vector<int> sz(N), centroids;\n    auto dfs = [&](auto &&f,\
    \ int u, int prv) -> void {\n        for (int v : nodes[u]) {\n            if\
    \ (v == prv) continue;\n            f(f, v, u);\n            sz[u] += sz[v];\n\
    \        }\n        sz[u]++;\n        bool is_centroid = true;\n        for (int\
    \ v : nodes[u]) {\n            if (v == prv) continue;\n            if (sz[v]\
    \ > N / 2) {\n                is_centroid = false;\n                break;\n \
    \           }\n        }\n        if (is_centroid && N - sz[u] <= N / 2) {\n \
    \           centroids.pb(u);\n        }\n    };\n    dfs(dfs, 0, -1);\n    return\
    \ centroids;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/get_centroids.hpp
  requiredBy: []
  timestamp: '2024-01-09 03:13:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/get_centroids.hpp
layout: document
redirect_from:
- /library/src/graph/get_centroids.hpp
- /library/src/graph/get_centroids.hpp.html
title: src/graph/get_centroids.hpp
---
