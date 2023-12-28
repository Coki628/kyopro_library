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
  _extendedRequiredBy: []
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/graph/bellman_ford.hpp\"\
    \n\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9(\u9802\u70B9\u6570, \u8FBA\
    \u96C6\u5408(0-indexed), \u59CB\u70B9)\nvector<ll> bellman_ford(int N, vector<array<ll,\
    \ 3>> edges, int src) {\n    // \u9802\u70B9[\u3042\u308B\u59CB\u70B9\u304B\u3089\
    \u306E\u6700\u77ED\u8DDD\u96E2] (\u7D4C\u8DEF\u81EA\u4F53\u3092\u77E5\u308A\u305F\
    \u3044\u6642\u306F\u3053\u3053\u306B\u524D\u306E\u9802\u70B9\u3082\u6301\u305F\
    \u305B\u308B)\n    vector<ll> res(N, INF);\n    res[src] = 0;\n    // \u5404\u8FBA\
    \u306B\u3088\u308B\u30B3\u30B9\u30C8\u306E\u7F6E\u304D\u63DB\u3048\u3092\u9802\
    \u70B9\u6570N-1\u56DE\u7E70\u308A\u8FD4\u3059\n    rep(_, N - 1) {\n        for\
    \ (auto [u, v, cost] : edges) {\n            // INF\u304B\u3089\u306F\u66F4\u65B0\
    \u3057\u306A\u3044\n            if (res[u] == INF) {\n                continue;\n\
    \            }\n            chmin(res[v], res[u] + cost);\n        }\n    }\n\
    \    auto tmp = res;\n    // \u8CA0\u306E\u9589\u8DEF(\u3044\u304F\u3089\u3067\
    \u3082\u30B3\u30B9\u30C8\u3092\u6E1B\u3089\u305B\u3066\u3057\u307E\u3046\u5834\
    \u6240)\u304C\u306A\u3044\u304B\u30C1\u30A7\u30C3\u30AF\u3059\u308B\n    rep(_,\
    \ N - 1) {\n        for (auto [u, v, cost] : edges) {\n            if (res[u]\
    \ == INF) {\n                continue;\n            }\n            if (res[v]\
    \ > res[u] + cost) {\n                // \u691C\u51FA\u3057\u305F\u8CA0\u9589\u8DEF\
    \u306F\u3059\u3050\u306B-INF\u306B\u3059\u308B\n                res[v] = -INF;\n\
    \            }\n        }\n    }\n    rep(i, N) {\n        if (tmp[i] != res[i])\
    \ {\n            res[i] = -INF;\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../common/chmin.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9(\u9802\u70B9\u6570, \u8FBA\
    \u96C6\u5408(0-indexed), \u59CB\u70B9)\nvector<ll> bellman_ford(int N, vector<array<ll,\
    \ 3>> edges, int src) {\n    // \u9802\u70B9[\u3042\u308B\u59CB\u70B9\u304B\u3089\
    \u306E\u6700\u77ED\u8DDD\u96E2] (\u7D4C\u8DEF\u81EA\u4F53\u3092\u77E5\u308A\u305F\
    \u3044\u6642\u306F\u3053\u3053\u306B\u524D\u306E\u9802\u70B9\u3082\u6301\u305F\
    \u305B\u308B)\n    vector<ll> res(N, INF);\n    res[src] = 0;\n    // \u5404\u8FBA\
    \u306B\u3088\u308B\u30B3\u30B9\u30C8\u306E\u7F6E\u304D\u63DB\u3048\u3092\u9802\
    \u70B9\u6570N-1\u56DE\u7E70\u308A\u8FD4\u3059\n    rep(_, N - 1) {\n        for\
    \ (auto [u, v, cost] : edges) {\n            // INF\u304B\u3089\u306F\u66F4\u65B0\
    \u3057\u306A\u3044\n            if (res[u] == INF) {\n                continue;\n\
    \            }\n            chmin(res[v], res[u] + cost);\n        }\n    }\n\
    \    auto tmp = res;\n    // \u8CA0\u306E\u9589\u8DEF(\u3044\u304F\u3089\u3067\
    \u3082\u30B3\u30B9\u30C8\u3092\u6E1B\u3089\u305B\u3066\u3057\u307E\u3046\u5834\
    \u6240)\u304C\u306A\u3044\u304B\u30C1\u30A7\u30C3\u30AF\u3059\u308B\n    rep(_,\
    \ N - 1) {\n        for (auto [u, v, cost] : edges) {\n            if (res[u]\
    \ == INF) {\n                continue;\n            }\n            if (res[v]\
    \ > res[u] + cost) {\n                // \u691C\u51FA\u3057\u305F\u8CA0\u9589\u8DEF\
    \u306F\u3059\u3050\u306B-INF\u306B\u3059\u308B\n                res[v] = -INF;\n\
    \            }\n        }\n    }\n    rep(i, N) {\n        if (tmp[i] != res[i])\
    \ {\n            res[i] = -INF;\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/common/chmin.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/src/graph/bellman_ford.hpp
- /library/src/graph/bellman_ford.hpp.html
title: src/graph/bellman_ford.hpp
---
