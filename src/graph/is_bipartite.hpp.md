---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/is_bipartite.hpp\"\
    \n\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\nbool is_bipartite(vvi nodes)\
    \ {\n    int N = nodes.size();\n    vector<int> C(N, -1);\n    auto dfs = [&](auto\
    \ &&f, int u, int c) -> bool {\n        if (C[u] != -1) {\n            return\
    \ C[u] == c;\n        }\n        C[u] = c;\n        for (auto v : nodes[u]) {\n\
    \            if (!f(f, v, 1 - c)) {\n                return false;\n         \
    \   }\n        }\n        return true;\n    };\n    rep(i, N) {\n        if (C[i]\
    \ == -1) {\n            if (!dfs(dfs, i, 0)) {\n                return false;\n\
    \            }\n        }\n    }\n    return true;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\
    \u5224\u5B9A\nbool is_bipartite(vvi nodes) {\n    int N = nodes.size();\n    vector<int>\
    \ C(N, -1);\n    auto dfs = [&](auto &&f, int u, int c) -> bool {\n        if\
    \ (C[u] != -1) {\n            return C[u] == c;\n        }\n        C[u] = c;\n\
    \        for (auto v : nodes[u]) {\n            if (!f(f, v, 1 - c)) {\n     \
    \           return false;\n            }\n        }\n        return true;\n  \
    \  };\n    rep(i, N) {\n        if (C[i] == -1) {\n            if (!dfs(dfs, i,\
    \ 0)) {\n                return false;\n            }\n        }\n    }\n    return\
    \ true;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/is_bipartite.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/is_bipartite.hpp
layout: document
redirect_from:
- /library/src/graph/is_bipartite.hpp
- /library/src/graph/is_bipartite.hpp.html
title: src/graph/is_bipartite.hpp
---
