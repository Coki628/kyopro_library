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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/listnd.hpp\"\
    \n\n// \u4EFB\u610F\u6B21\u5143vector\n// \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
    template<typename... Ts>\nauto listnd(size_t N, Ts... ts) {\n    if constexpr\
    \ (sizeof...(ts) == 1) {\n        return vector<Ts...>(N, ts...);\n    } else\
    \ {\n        auto res = listnd(ts...);\n        return vector<decltype(res)>(N,\
    \ res);\n    }\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\ntemplate<typename T>[[deprecated(\"\
    list2d will be merged with listnd\")]] vv<T> list2d(int N, int M, T init) { return\
    \ listnd(N, M, init); }\ntemplate<typename T>[[deprecated(\"list3d will be merged\
    \ with listnd\")]] vv<vector<T>> list3d(int N, int M, int L, T init) { return\
    \ listnd(N, M, L, init); }\ntemplate<typename T>[[deprecated(\"list4d will be\
    \ merged with listnd\")]] vv<vv<T>> list4d(int N, int M, int L, int O, T init)\
    \ { return listnd(N, M, L, O, init); }\n#line 4 \"src/grid/bfs_restore.hpp\"\n\
    \n// \u30B0\u30EA\u30C3\u30C9BFS(\u7D4C\u8DEF\u5FA9\u5143)\nstring bfs(\n    const\
    \ vector<string> &grid,\n    const pii &src,\n    const pii &goal,\n    char invalid\
    \ = '#'\n) {\n    int H = grid.size();\n    int W = grid[0].size();\n    auto\
    \ dist = list2d(H, W, INF);\n    auto prv = list2d(H, W, -1);\n    const vector<pii>\
    \ directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};\n    queue<pii> que;\n    auto\
    \ [sh, sw] = src;\n    que.push({sh, sw});\n    dist[sh][sw] = 0;\n    while (!que.empty())\
    \ {\n        auto [h, w] = que.front();\n        que.pop();\n        rep(d, 4)\
    \ {\n            auto [dh, dw] = directions[d];\n            int nh = h + dh;\n\
    \            int nw = w + dw;\n            if (nh < 0 or nw < 0 or nh >= H or\
    \ nw >= W) continue;\n            if (grid[nh][nw] == invalid) continue;\n   \
    \         if (dist[nh][nw] == INF) {\n                dist[nh][nw] = dist[h][w]\
    \ + 1;\n                prv[nh][nw] = d % 2 == 0 ? d + 1 : d - 1;\n          \
    \      que.push({nh, nw});\n            }\n        }\n    }\n\n    // \u7D4C\u8DEF\
    \u5FA9\u5143\n    string res;\n    vector<char> itoc = {'U', 'D', 'L', 'R'};\n\
    \    auto [ch, cw] = goal;\n    while (ch != sh or cw != sw) {\n        int d\
    \ = prv[ch][cw];\n        auto [dh, dw] = directions[d];\n        ch += dh;\n\
    \        cw += dw;\n        res += itoc[d % 2 == 0 ? d + 1 : d - 1];\n    }\n\
    \    reverse(ALL(res));\n    return res;\n}\n"
  code: "#pragma once\n#include \"../common/listnd.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u30B0\u30EA\u30C3\u30C9BFS(\u7D4C\u8DEF\u5FA9\u5143)\nstring bfs(\n  \
    \  const vector<string> &grid,\n    const pii &src,\n    const pii &goal,\n  \
    \  char invalid = '#'\n) {\n    int H = grid.size();\n    int W = grid[0].size();\n\
    \    auto dist = list2d(H, W, INF);\n    auto prv = list2d(H, W, -1);\n    const\
    \ vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};\n    queue<pii>\
    \ que;\n    auto [sh, sw] = src;\n    que.push({sh, sw});\n    dist[sh][sw] =\
    \ 0;\n    while (!que.empty()) {\n        auto [h, w] = que.front();\n       \
    \ que.pop();\n        rep(d, 4) {\n            auto [dh, dw] = directions[d];\n\
    \            int nh = h + dh;\n            int nw = w + dw;\n            if (nh\
    \ < 0 or nw < 0 or nh >= H or nw >= W) continue;\n            if (grid[nh][nw]\
    \ == invalid) continue;\n            if (dist[nh][nw] == INF) {\n            \
    \    dist[nh][nw] = dist[h][w] + 1;\n                prv[nh][nw] = d % 2 == 0\
    \ ? d + 1 : d - 1;\n                que.push({nh, nw});\n            }\n     \
    \   }\n    }\n\n    // \u7D4C\u8DEF\u5FA9\u5143\n    string res;\n    vector<char>\
    \ itoc = {'U', 'D', 'L', 'R'};\n    auto [ch, cw] = goal;\n    while (ch != sh\
    \ or cw != sw) {\n        int d = prv[ch][cw];\n        auto [dh, dw] = directions[d];\n\
    \        ch += dh;\n        cw += dw;\n        res += itoc[d % 2 == 0 ? d + 1\
    \ : d - 1];\n    }\n    reverse(ALL(res));\n    return res;\n}\n"
  dependsOn:
  - src/common/listnd.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/grid/bfs_restore.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/bfs_restore.hpp
layout: document
redirect_from:
- /library/src/grid/bfs_restore.hpp
- /library/src/grid/bfs_restore.hpp.html
title: src/grid/bfs_restore.hpp
---
