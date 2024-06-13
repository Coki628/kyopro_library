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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/cycle_detection_for_namori.hpp\"\
    \n\n// \u306A\u3082\u308A\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u691C\u51FA\uFF1A\
    O(N)\n// cycle := \u306A\u3082\u308A\u306E\u9589\u8DEF\u306E\u9802\u70B9\u96C6\
    \u5408(\u7D4C\u8DEF\u9806\u306B\u4E26\u3076\u306E\u3067\u3001\u3053\u306E\u6301\
    \u3061\u65B9\u3060\u3068\u8FBA\u3082\u5206\u304B\u308B)\nvector<int> cycle_detection_for_namori(vvi\
    \ nodes) {\n    int N = nodes.size();\n    vector<int> visited(N), cycle;\n  \
    \  bool end = false;\n    auto dfs = [&](auto &&f, int u, int prv) -> bool {\n\
    \        if (visited[u]) {\n            cycle.eb(u);\n            return true;\n\
    \        }\n        visited[u] = true;\n        for (auto v : nodes[u]) {\n  \
    \          if (v == prv) continue;\n            if (f(f, v, u)) {\n          \
    \      if (not end) {\n                    // \u7D42\u7AEF\u306E\u9802\u70B9\u306B\
    \u623B\u3063\u3066\u304F\u308B\u307E\u3067\u306E\u9802\u70B9\u3092\u8FFD\u52A0\
    \u3059\u308B\n                    if (u != cycle[0]) {\n                     \
    \   cycle.eb(u);\n                    } else {\n                        end =\
    \ true;\n                    }\n                }\n                return true;\n\
    \            }\n        }\n        return false;\n    };\n    dfs(dfs, 0, -1);\n\
    \    return cycle;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u306A\u3082\u308A\u30B0\u30E9\
    \u30D5\u306E\u9589\u8DEF\u691C\u51FA\uFF1AO(N)\n// cycle := \u306A\u3082\u308A\
    \u306E\u9589\u8DEF\u306E\u9802\u70B9\u96C6\u5408(\u7D4C\u8DEF\u9806\u306B\u4E26\
    \u3076\u306E\u3067\u3001\u3053\u306E\u6301\u3061\u65B9\u3060\u3068\u8FBA\u3082\
    \u5206\u304B\u308B)\nvector<int> cycle_detection_for_namori(vvi nodes) {\n   \
    \ int N = nodes.size();\n    vector<int> visited(N), cycle;\n    bool end = false;\n\
    \    auto dfs = [&](auto &&f, int u, int prv) -> bool {\n        if (visited[u])\
    \ {\n            cycle.eb(u);\n            return true;\n        }\n        visited[u]\
    \ = true;\n        for (auto v : nodes[u]) {\n            if (v == prv) continue;\n\
    \            if (f(f, v, u)) {\n                if (not end) {\n             \
    \       // \u7D42\u7AEF\u306E\u9802\u70B9\u306B\u623B\u3063\u3066\u304F\u308B\u307E\
    \u3067\u306E\u9802\u70B9\u3092\u8FFD\u52A0\u3059\u308B\n                    if\
    \ (u != cycle[0]) {\n                        cycle.eb(u);\n                  \
    \  } else {\n                        end = true;\n                    }\n    \
    \            }\n                return true;\n            }\n        }\n     \
    \   return false;\n    };\n    dfs(dfs, 0, -1);\n    return cycle;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/cycle_detection_for_namori.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/cycle_detection_for_namori.hpp
layout: document
redirect_from:
- /library/src/graph/cycle_detection_for_namori.hpp
- /library/src/graph/cycle_detection_for_namori.hpp.html
title: src/graph/cycle_detection_for_namori.hpp
---
