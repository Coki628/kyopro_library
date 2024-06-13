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
    path: src/graph/LowestCommonAncestor.hpp
    title: src/graph/LowestCommonAncestor.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/EulerTour.hpp\"\
    \n\n// \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n// \u30FBHLD\u304B\u3089\u5207\
    \u308A\u51FA\u3057\u305F\u3002\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u306F\u3053\
    \u308C\u3067\u5341\u5206\u3002\nstruct EulerTour {\npublic:\n    int N;\n    vvi\
    \ nodes;\n    vector<int> sz, in, out, rev, par, dep;\n\n    explicit EulerTour(const\
    \ vvi &nodes) : nodes(nodes), N(nodes.size()) {\n        sz.assign(N, 0);\n  \
    \      in.assign(N, 0);\n        out.assign(N, 0);\n        rev.assign(N, 0);\n\
    \        par.assign(N, 0);\n        dep.assign(N, 0);\n        int t = 0;\n  \
    \      dfs(0, -1, 0, t);\n    }\n\n    int operator[](int u) const {\n       \
    \ assert(0 <= u && u < N);\n        return in[u];\n    }\n\nprivate:\n    void\
    \ dfs(int idx, int p, int d, int &times) {\n        dep[idx] = d;\n        par[idx]\
    \ = p;\n        sz[idx] = 1;\n        in[idx] = times++;\n        rev[in[idx]]\
    \ = idx;\n        for (auto &to : nodes[idx]) {\n            if (to == p) continue;\n\
    \            dfs(to, idx, d + 1, times);\n            sz[idx] += sz[to];\n   \
    \     }\n        out[idx] = times;\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u30AA\u30A4\u30E9\u30FC\u30C4\
    \u30A2\u30FC\n// \u30FBHLD\u304B\u3089\u5207\u308A\u51FA\u3057\u305F\u3002\u90E8\
    \u5206\u6728\u30AF\u30A8\u30EA\u306F\u3053\u308C\u3067\u5341\u5206\u3002\nstruct\
    \ EulerTour {\npublic:\n    int N;\n    vvi nodes;\n    vector<int> sz, in, out,\
    \ rev, par, dep;\n\n    explicit EulerTour(const vvi &nodes) : nodes(nodes), N(nodes.size())\
    \ {\n        sz.assign(N, 0);\n        in.assign(N, 0);\n        out.assign(N,\
    \ 0);\n        rev.assign(N, 0);\n        par.assign(N, 0);\n        dep.assign(N,\
    \ 0);\n        int t = 0;\n        dfs(0, -1, 0, t);\n    }\n\n    int operator[](int\
    \ u) const {\n        assert(0 <= u && u < N);\n        return in[u];\n    }\n\
    \nprivate:\n    void dfs(int idx, int p, int d, int &times) {\n        dep[idx]\
    \ = d;\n        par[idx] = p;\n        sz[idx] = 1;\n        in[idx] = times++;\n\
    \        rev[in[idx]] = idx;\n        for (auto &to : nodes[idx]) {\n        \
    \    if (to == p) continue;\n            dfs(to, idx, d + 1, times);\n       \
    \     sz[idx] += sz[to];\n        }\n        out[idx] = times;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/EulerTour.hpp
  requiredBy:
  - src/graph/LowestCommonAncestor.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/EulerTour.hpp
layout: document
redirect_from:
- /library/src/graph/EulerTour.hpp
- /library/src/graph/EulerTour.hpp.html
title: src/graph/EulerTour.hpp
---
