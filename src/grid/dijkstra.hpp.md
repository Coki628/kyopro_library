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
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"\
    src/grid/dijkstra.hpp\"\n\n// \u30B0\u30EA\u30C3\u30C9\u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9(H*W\u30B0\u30EA\u30C3\u30C9, \u59CB\u70B9{h, w}) \nusing P = tuple<ll,\
    \ int, int>;\nvvl dijkstra(const vvl &grid, pii src, ll invalid=-1) {\n\n    int\
    \ H = grid.size();\n    int W = grid[0].size();\n    auto res = list2d(H, W, INF);\n\
    \    const vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};\n    priority_queue<P,\
    \ vector<P>, greater<P>> que;\n    auto [sh, sw] = src;\n    que.push({0, sh,\
    \ sw});\n    res[sh][sw] = 0;\n\n    while (!que.empty()) {\n        auto [dist,\
    \ h, w] = que.top(); que.pop();\n        if (res[h][w] < dist) continue;\n   \
    \     for (auto [dh, dw] : directions) {\n            int nh = h+dh;\n       \
    \     int nw = w+dw;\n            if (nh < 0 or nw < 0 or nh >= H or nw >= W)\
    \ continue;\n            if (grid[nh][nw] == invalid) continue;\n            ll\
    \ cost = grid[nh][nw];\n            if (dist+cost < res[nh][nw]) {\n         \
    \       res[nh][nw] = dist+cost;\n                que.push({dist+cost, nh, nw});\n\
    \            }\n        }\n    }\n    return res;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u30B0\u30EA\u30C3\u30C9\u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9(H*W\u30B0\u30EA\u30C3\u30C9, \u59CB\u70B9{h, w}) \nusing P\
    \ = tuple<ll, int, int>;\nvvl dijkstra(const vvl &grid, pii src, ll invalid=-1)\
    \ {\n\n    int H = grid.size();\n    int W = grid[0].size();\n    auto res = list2d(H,\
    \ W, INF);\n    const vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0,\
    \ 1}};\n    priority_queue<P, vector<P>, greater<P>> que;\n    auto [sh, sw] =\
    \ src;\n    que.push({0, sh, sw});\n    res[sh][sw] = 0;\n\n    while (!que.empty())\
    \ {\n        auto [dist, h, w] = que.top(); que.pop();\n        if (res[h][w]\
    \ < dist) continue;\n        for (auto [dh, dw] : directions) {\n            int\
    \ nh = h+dh;\n            int nw = w+dw;\n            if (nh < 0 or nw < 0 or\
    \ nh >= H or nw >= W) continue;\n            if (grid[nh][nw] == invalid) continue;\n\
    \            ll cost = grid[nh][nw];\n            if (dist+cost < res[nh][nw])\
    \ {\n                res[nh][nw] = dist+cost;\n                que.push({dist+cost,\
    \ nh, nw});\n            }\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/grid/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/dijkstra.hpp
layout: document
redirect_from:
- /library/src/grid/dijkstra.hpp
- /library/src/grid/dijkstra.hpp.html
title: src/grid/dijkstra.hpp
---
