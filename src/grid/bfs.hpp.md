---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
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
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/common/listnd.hpp\"\n\ntemplate<typename T> vector<vector<T>> list2d(int N,\
    \ int M, T init) {\n    return vector<vector<T>>(N, vector<T>(M, init));\n}\n\n\
    template<typename T> vector<vector<vector<T>>> list3d(int N, int M, int L, T init)\
    \ {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L,\
    \ init)));\n}\n\ntemplate<typename T> vector<vector<vector<vector<T>>>> list4d(int\
    \ N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n\
    #line 3 \"src/grid/bfs.hpp\"\n\n// \u30B0\u30EA\u30C3\u30C9BFS\nvvl bfs(const\
    \ vector<string> &grid, const vector<pii> &src, char invalid='#') {\n\n    int\
    \ H = grid.size();\n    int W = grid[0].size();\n    auto res = list2d(H, W, INF);\n\
    \    const vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};\n    queue<pii>\
    \ que;\n    for (auto [h, w] : src) {\n        que.push({h, w});\n        res[h][w]\
    \ = 0;\n    }\n    while (!que.empty()) {\n        auto [h, w] = que.front();\
    \ que.pop();\n        for (auto [dh, dw] : directions) {\n            int nh =\
    \ h + dh;\n            int nw = w + dw;\n            if (nh < 0 or nw < 0 or nh\
    \ >= H or nw >= W) continue;\n            if (grid[nh][nw] == invalid) continue;\n\
    \            if (res[nh][nw] == INF) {\n                res[nh][nw] = res[h][w]\
    \ + 1;\n                que.push({nh, nw});\n            }\n        }\n    }\n\
    \    return res;\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"../common/listnd.hpp\"\n\n// \u30B0\
    \u30EA\u30C3\u30C9BFS\nvvl bfs(const vector<string> &grid, const vector<pii> &src,\
    \ char invalid='#') {\n\n    int H = grid.size();\n    int W = grid[0].size();\n\
    \    auto res = list2d(H, W, INF);\n    const vector<pii> directions = {{-1, 0},\
    \ {1, 0}, {0, -1}, {0, 1}};\n    queue<pii> que;\n    for (auto [h, w] : src)\
    \ {\n        que.push({h, w});\n        res[h][w] = 0;\n    }\n    while (!que.empty())\
    \ {\n        auto [h, w] = que.front(); que.pop();\n        for (auto [dh, dw]\
    \ : directions) {\n            int nh = h + dh;\n            int nw = w + dw;\n\
    \            if (nh < 0 or nw < 0 or nh >= H or nw >= W) continue;\n         \
    \   if (grid[nh][nw] == invalid) continue;\n            if (res[nh][nw] == INF)\
    \ {\n                res[nh][nw] = res[h][w] + 1;\n                que.push({nh,\
    \ nw});\n            }\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/grid/bfs.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/bfs.hpp
layout: document
redirect_from:
- /library/src/grid/bfs.hpp
- /library/src/grid/bfs.hpp.html
title: src/grid/bfs.hpp
---
