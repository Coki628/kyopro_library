---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
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
    src/common/listnd.hpp\"\n\ntemplate<typename T>\nvector<vector<T>> list2d(int\
    \ N, int M, T init) {\n    return vector<vector<T>>(N, vector<T>(M, init));\n\
    }\n\ntemplate<typename T>\nvector<vector<vector<T>>> list3d(int N, int M, int\
    \ L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L,\
    \ init)));\n}\n\ntemplate<typename T> \nvector<vector<vector<vector<T>>>> list4d(int\
    \ N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n\
    #line 3 \"src/grid/bfs_restore.hpp\"\n\n// \u30B0\u30EA\u30C3\u30C9BFS(\u7D4C\u8DEF\
    \u5FA9\u5143)\nstring bfs(const vector<string> &grid, const pii &src, const pii\
    \ &goal, char invalid='#') {\n\n    int H = grid.size();\n    int W = grid[0].size();\n\
    \    auto dist = list2d(H, W, INF);\n    auto prv = list2d(H, W, -1);\n    const\
    \ vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};\n    queue<pii>\
    \ que;\n    auto [sh, sw] = src;\n    que.push({sh, sw});\n    dist[sh][sw] =\
    \ 0;\n    while (!que.empty()) {\n        auto [h, w] = que.front(); que.pop();\n\
    \        rep(d, 4) {\n            auto [dh, dw] = directions[d];\n           \
    \ int nh = h + dh;\n            int nw = w + dw;\n            if (nh < 0 or nw\
    \ < 0 or nh >= H or nw >= W) continue;\n            if (grid[nh][nw] == invalid)\
    \ continue;\n            if (dist[nh][nw] == INF) {\n                dist[nh][nw]\
    \ = dist[h][w] + 1;\n                prv[nh][nw] = d%2 == 0 ? d+1 : d-1;\n   \
    \             que.push({nh, nw});\n            }\n        }\n    }\n\n    // \u7D4C\
    \u8DEF\u5FA9\u5143\n    string res;\n    vector<char> itoc = {'U', 'D', 'L', 'R'};\n\
    \    auto [ch, cw] = goal;\n    while (ch != sh or cw != sw) {\n        int d\
    \ = prv[ch][cw];\n        auto [dh, dw] = directions[d];\n        ch += dh;\n\
    \        cw += dw;\n        res += itoc[d%2 == 0 ? d+1 : d-1];\n    }\n    reverse(ALL(res));\n\
    \    return res;\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"../common/listnd.hpp\"\n\n// \u30B0\
    \u30EA\u30C3\u30C9BFS(\u7D4C\u8DEF\u5FA9\u5143)\nstring bfs(const vector<string>\
    \ &grid, const pii &src, const pii &goal, char invalid='#') {\n\n    int H = grid.size();\n\
    \    int W = grid[0].size();\n    auto dist = list2d(H, W, INF);\n    auto prv\
    \ = list2d(H, W, -1);\n    const vector<pii> directions = {{-1, 0}, {1, 0}, {0,\
    \ -1}, {0, 1}};\n    queue<pii> que;\n    auto [sh, sw] = src;\n    que.push({sh,\
    \ sw});\n    dist[sh][sw] = 0;\n    while (!que.empty()) {\n        auto [h, w]\
    \ = que.front(); que.pop();\n        rep(d, 4) {\n            auto [dh, dw] =\
    \ directions[d];\n            int nh = h + dh;\n            int nw = w + dw;\n\
    \            if (nh < 0 or nw < 0 or nh >= H or nw >= W) continue;\n         \
    \   if (grid[nh][nw] == invalid) continue;\n            if (dist[nh][nw] == INF)\
    \ {\n                dist[nh][nw] = dist[h][w] + 1;\n                prv[nh][nw]\
    \ = d%2 == 0 ? d+1 : d-1;\n                que.push({nh, nw});\n            }\n\
    \        }\n    }\n\n    // \u7D4C\u8DEF\u5FA9\u5143\n    string res;\n    vector<char>\
    \ itoc = {'U', 'D', 'L', 'R'};\n    auto [ch, cw] = goal;\n    while (ch != sh\
    \ or cw != sw) {\n        int d = prv[ch][cw];\n        auto [dh, dw] = directions[d];\n\
    \        ch += dh;\n        cw += dw;\n        res += itoc[d%2 == 0 ? d+1 : d-1];\n\
    \    }\n    reverse(ALL(res));\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/grid/bfs_restore.hpp
  requiredBy: []
  timestamp: '2022-04-06 17:44:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/bfs_restore.hpp
layout: document
redirect_from:
- /library/src/grid/bfs_restore.hpp
- /library/src/grid/bfs_restore.hpp.html
title: src/grid/bfs_restore.hpp
---
