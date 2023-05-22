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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/common/chmin.hpp\"\
    \n\ntemplate<typename T>\nbool chmin(T &x, T y) {\n    return (y < x) ? x = y,\
    \ true : false;\n}\n#line 3 \"src/graph/bfs.hpp\"\n\n// BFS\nvector<ll> bfs(const\
    \ vvi &nodes, const vector<int> &src) {\n\n    int N = nodes.size();\n    vector<ll>\
    \ res(N, INF);\n    queue<int> que;\n    for (int s : src) {\n        res[s] =\
    \ 0;\n        que.push(s);\n    }\n\n    while (!que.empty()) {\n        int u\
    \ = que.front(); que.pop();\n        for (auto v: nodes[u]) {\n            if\
    \ (chmin(res[v], res[u]+1)) {\n                que.push(v);\n            }\n \
    \       }\n    }\n    return res;\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"../common/chmin.hpp\"\n\n// BFS\n\
    vector<ll> bfs(const vvi &nodes, const vector<int> &src) {\n\n    int N = nodes.size();\n\
    \    vector<ll> res(N, INF);\n    queue<int> que;\n    for (int s : src) {\n \
    \       res[s] = 0;\n        que.push(s);\n    }\n\n    while (!que.empty()) {\n\
    \        int u = que.front(); que.pop();\n        for (auto v: nodes[u]) {\n \
    \           if (chmin(res[v], res[u]+1)) {\n                que.push(v);\n   \
    \         }\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/chmin.hpp
  isVerificationFile: false
  path: src/graph/bfs.hpp
  requiredBy: []
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bfs.test.cpp
documentation_of: src/graph/bfs.hpp
layout: document
redirect_from:
- /library/src/graph/bfs.hpp
- /library/src/graph/bfs.hpp.html
title: src/graph/bfs.hpp
---
