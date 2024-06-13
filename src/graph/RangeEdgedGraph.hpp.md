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
    links:
    - https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/RangeEdgedGraph.hpp\"\
    \n\n// \u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF\n// \u53C2\u8003\
    \uFF1Ahttps://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656\n// \u30FB\u72B6\
    \u6CC1\u306B\u5FDC\u3058\u3066\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u884C\
    \u3044\u305F\u3044\u64CD\u4F5C\u306F\u69D8\u3005\u306A\u306E\u3067\u3001\u533A\
    \u9593\u8FBA\u30B0\u30E9\u30D5\u306E\u69CB\u7BC9\u306E\u307F\u884C\u3046\u3088\
    \u3046\u306B\u3057\u305F\u3002\n// \u3000nodes\u306E\u60C5\u5831\u3092\u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u308401BFS\u306A\u3069\u306B\u7A81\u3063\u8FBC\u3081\u3070\
    OK\u3002\n// \u30FB[n,2*n)\u306B\u5143\u30B0\u30E9\u30D5\u306E\u9802\u70B9\u304C\
    \u3042\u308B\u3002\nstruct RangeEdgedGraph {\n    int n;\n    vv<pil> nodes;\n\
    \n    RangeEdgedGraph(int n) : n(n) {\n        nodes.resize(3 * n);\n        for\
    \ (int i = 1; i < n; ++i) {\n            int cl = i * 2, cr = i * 2 + 1;\n   \
    \         // \u4E0A\u306E\u30BB\u30B0\u6728\u306B\u306F\u6839\u2192\u8449\u65B9\
    \u5411\u306B\u91CD\u307F0\u306E\u8FBA\u3092\u5F35\u308B\n            _add_edge(i,\
    \ cl, 0);\n            _add_edge(i, cr, 0);\n            // \u4E0B\u306E\u30BB\
    \u30B0\u6728\u306B\u306F\u8449\u2192\u6839\u65B9\u5411\u306B\u91CD\u307F0\u306E\
    \u8FBA\u3092\u5F35\u308B\n            // \u4E0B\u306E\u30BB\u30B0\u6728\u3092\u64CD\
    \u4F5C\u3057\u305F\u3044\u3068\u304D\u306F +2*n \u3059\u308C\u3070\u3088\u3044\
    \n            _add_edge(cl + 2 * n, i + 2 * n, 0);\n            _add_edge(cr +\
    \ 2 * n, i + 2 * n, 0);\n        }\n    }\n\n    // map [3n, 4n) -> [n, 2n)\n\
    \    void _add_edge(int u, int v, ll w) {\n        if (3 * n <= u) u -= 2 * n;\n\
    \        nodes[u].push_back({v, w});\n    }\n\n    // u -> [l,r) \u306E\u533A\u9593\
    \u8FBA\u3092\u5F35\u308B\n    void add_edges(int u, pii seg, ll w) {\n       \
    \ auto [l, r] = seg;\n        u += n;\n        // \u4E0A\u306E\u30BB\u30B0\u6728\
    \u3068\u7E4B\u3050\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) _add_edge(u, l++, w);\n            if (r & 1) _add_edge(u,\
    \ --r, w);\n        }\n    }\n\n    // [l,r) -> v \u306E\u533A\u9593\u8FBA\u3092\
    \u5F35\u308B\n    void add_edges(pii seg, int v, ll w) {\n        auto [l, r]\
    \ = seg;\n        v += n;\n        // \u4E0B\u306E\u30BB\u30B0\u6728\u3068\u7E4B\
    \u3050\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) _add_edge(l + 2 * n, v, w), l++;\n            if (r & 1) --r, _add_edge(r\
    \ + 2 * n, v, w);\n        }\n    }\n    // u -> v \u306E\u8FBA\u3092\u5F35\u308B\
    \n    void add_edge(int u, int v, ll w) {\n        _add_edge(u + n, v + n, w);\n\
    \    }\n\n    vv<pil> get_nodes() {\n        return nodes;\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u533A\u9593\u306B\u8FBA\u3092\
    \u5F35\u308B\u30C6\u30AF\n// \u53C2\u8003\uFF1Ahttps://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656\n\
    // \u30FB\u72B6\u6CC1\u306B\u5FDC\u3058\u3066\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\
    \u3066\u884C\u3044\u305F\u3044\u64CD\u4F5C\u306F\u69D8\u3005\u306A\u306E\u3067\
    \u3001\u533A\u9593\u8FBA\u30B0\u30E9\u30D5\u306E\u69CB\u7BC9\u306E\u307F\u884C\
    \u3046\u3088\u3046\u306B\u3057\u305F\u3002\n// \u3000nodes\u306E\u60C5\u5831\u3092\
    \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u308401BFS\u306A\u3069\u306B\u7A81\u3063\u8FBC\
    \u3081\u3070OK\u3002\n// \u30FB[n,2*n)\u306B\u5143\u30B0\u30E9\u30D5\u306E\u9802\
    \u70B9\u304C\u3042\u308B\u3002\nstruct RangeEdgedGraph {\n    int n;\n    vv<pil>\
    \ nodes;\n\n    RangeEdgedGraph(int n) : n(n) {\n        nodes.resize(3 * n);\n\
    \        for (int i = 1; i < n; ++i) {\n            int cl = i * 2, cr = i * 2\
    \ + 1;\n            // \u4E0A\u306E\u30BB\u30B0\u6728\u306B\u306F\u6839\u2192\u8449\
    \u65B9\u5411\u306B\u91CD\u307F0\u306E\u8FBA\u3092\u5F35\u308B\n            _add_edge(i,\
    \ cl, 0);\n            _add_edge(i, cr, 0);\n            // \u4E0B\u306E\u30BB\
    \u30B0\u6728\u306B\u306F\u8449\u2192\u6839\u65B9\u5411\u306B\u91CD\u307F0\u306E\
    \u8FBA\u3092\u5F35\u308B\n            // \u4E0B\u306E\u30BB\u30B0\u6728\u3092\u64CD\
    \u4F5C\u3057\u305F\u3044\u3068\u304D\u306F +2*n \u3059\u308C\u3070\u3088\u3044\
    \n            _add_edge(cl + 2 * n, i + 2 * n, 0);\n            _add_edge(cr +\
    \ 2 * n, i + 2 * n, 0);\n        }\n    }\n\n    // map [3n, 4n) -> [n, 2n)\n\
    \    void _add_edge(int u, int v, ll w) {\n        if (3 * n <= u) u -= 2 * n;\n\
    \        nodes[u].push_back({v, w});\n    }\n\n    // u -> [l,r) \u306E\u533A\u9593\
    \u8FBA\u3092\u5F35\u308B\n    void add_edges(int u, pii seg, ll w) {\n       \
    \ auto [l, r] = seg;\n        u += n;\n        // \u4E0A\u306E\u30BB\u30B0\u6728\
    \u3068\u7E4B\u3050\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) _add_edge(u, l++, w);\n            if (r & 1) _add_edge(u,\
    \ --r, w);\n        }\n    }\n\n    // [l,r) -> v \u306E\u533A\u9593\u8FBA\u3092\
    \u5F35\u308B\n    void add_edges(pii seg, int v, ll w) {\n        auto [l, r]\
    \ = seg;\n        v += n;\n        // \u4E0B\u306E\u30BB\u30B0\u6728\u3068\u7E4B\
    \u3050\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) _add_edge(l + 2 * n, v, w), l++;\n            if (r & 1) --r, _add_edge(r\
    \ + 2 * n, v, w);\n        }\n    }\n    // u -> v \u306E\u8FBA\u3092\u5F35\u308B\
    \n    void add_edge(int u, int v, ll w) {\n        _add_edge(u + n, v + n, w);\n\
    \    }\n\n    vv<pil> get_nodes() {\n        return nodes;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/RangeEdgedGraph.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/RangeEdgedGraph.hpp
layout: document
redirect_from:
- /library/src/graph/RangeEdgedGraph.hpp
- /library/src/graph/RangeEdgedGraph.hpp.html
title: src/graph/RangeEdgedGraph.hpp
---
