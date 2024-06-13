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
    \n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\u3057\u3066\u308B\u6240\u306E\u5F15\
    \u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\u308B\u306E\u3092\u9ED9\u3089\u305B\
    \u308B\n#pragma GCC diagnostic ignored \"-Wunused-parameter\"\n#define _USE_MATH_DEFINES\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#line 3 \"src/macros.hpp\"\n\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using pll = pair<ll, ll>;\nusing pii = pair<int, int>;\nusing pli = pair<ll, int>;\n\
    using pil = pair<int, ll>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\n\
    using vvl = vv<ll>;\nusing vvi = vv<int>;\nusing vvpll = vv<pll>;\nusing vvpli\
    \ = vv<pli>;\nusing vvpil = vv<pil>;\n#define name4(i, a, b, c, d, e, ...) e\n\
    #define rep(...) name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ rep1(i, a) for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for\
    \ (ll i = a, _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb\
    \ = b; (c > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n\
    #define rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define\
    \ eb emplace_back\n#define mkp make_pair\n#define ALL(A) begin(A), end(A)\n#define\
    \ UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)), A.end())\n#define elif else\
    \ if\n#define tostr to_string\n\n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n\
    \    constexpr int MOD = 1000000007;\n    constexpr ld EPS = 1e-10;\n    constexpr\
    \ ld PI = M_PI;\n#endif\n#line 4 \"src/graph/bfs01.hpp\"\n\n// 01BFS(\u30B3\u30B9\
    \u30C8\u304C0or1\u306A\u3089\u4F7F\u3048\u308B)\nauto bfs01 = [](const vvpil &nodes,\
    \ const vector<int> &src) {\n    int N = nodes.size();\n    vector<ll> res(N,\
    \ INF);\n    deque<int> que;\n    for (int s : src) {\n        res[s] = 0;\n \
    \       que.push_back(s);\n    }\n    while (que.size()) {\n        int u = que.front();\n\
    \        que.pop_front();\n        for (auto [v, c] : nodes[u]) {\n          \
    \  assert(c == 0 or c == 1);\n            if (chmin(res[v], res[u] + c)) {\n \
    \               if (c == 0) {\n                    que.push_front(v);\n      \
    \          } else if (c == 1) {\n                    que.push_back(v);\n     \
    \           }\n            }\n        }\n    }\n    return res;\n};\n"
  code: "#pragma once\n#include \"../common/chmin.hpp\"\n#include \"../macros.hpp\"\
    \n\n// 01BFS(\u30B3\u30B9\u30C8\u304C0or1\u306A\u3089\u4F7F\u3048\u308B)\nauto\
    \ bfs01 = [](const vvpil &nodes, const vector<int> &src) {\n    int N = nodes.size();\n\
    \    vector<ll> res(N, INF);\n    deque<int> que;\n    for (int s : src) {\n \
    \       res[s] = 0;\n        que.push_back(s);\n    }\n    while (que.size())\
    \ {\n        int u = que.front();\n        que.pop_front();\n        for (auto\
    \ [v, c] : nodes[u]) {\n            assert(c == 0 or c == 1);\n            if\
    \ (chmin(res[v], res[u] + c)) {\n                if (c == 0) {\n             \
    \       que.push_front(v);\n                } else if (c == 1) {\n           \
    \         que.push_back(v);\n                }\n            }\n        }\n   \
    \ }\n    return res;\n};\n"
  dependsOn:
  - src/common/chmin.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/bfs01.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/bfs01.hpp
layout: document
redirect_from:
- /library/src/graph/bfs01.hpp
- /library/src/graph/bfs01.hpp.html
title: src/graph/bfs01.hpp
---
