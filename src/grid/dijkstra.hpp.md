---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
  - icon: ':x:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
  - icon: ':warning:'
    path: src/grid/constants/dir4.hpp
    title: src/grid/constants/dir4.hpp
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
    \ { return listnd(N, M, L, O, init); }\n#line 3 \"src/grid/constants/dir4.hpp\"\
    \n\n// 4\u65B9\u5411(\u4E0A\u4E0B\u5DE6\u53F3)\nconst vector<pii> dir4 = {{-1,\
    \ 0}, {1, 0}, {0, -1}, {0, 1}};\n#line 6 \"src/grid/dijkstra.hpp\"\n\n// \u30B0\
    \u30EA\u30C3\u30C9\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9(H*W\u30B0\u30EA\u30C3\u30C9\
    , \u59CB\u70B9{h, w})\nusing P = tuple<ll, int, int>;\nvvl dijkstra(const vvl\
    \ &grid, pii src, ll invalid = -1) {\n    int H = grid.size();\n    int W = grid[0].size();\n\
    \    auto res = listnd(H, W, INF);\n    priority_queue<P, vector<P>, greater<P>>\
    \ que;\n    auto [sh, sw] = src;\n    que.push({0, sh, sw});\n    res[sh][sw]\
    \ = 0;\n\n    while (que.size()) {\n        auto [dist, h, w] = que.top();\n \
    \       que.pop();\n        if (res[h][w] < dist) continue;\n        for (auto\
    \ [dh, dw] : dir4) {\n            int nh = h + dh;\n            int nw = w + dw;\n\
    \            if (nh < 0 or nw < 0 or nh >= H or nw >= W) continue;\n         \
    \   if (grid[nh][nw] == invalid) continue;\n            ll cost = grid[nh][nw];\n\
    \            if (chmin(res[nh][nw], dist + cost)) {\n                que.push({dist\
    \ + cost, nh, nw});\n            }\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../common/chmin.hpp\"\n#include \"../common/listnd.hpp\"\
    \n#include \"../macros.hpp\"\n#include \"constants/dir4.hpp\"\n\n// \u30B0\u30EA\
    \u30C3\u30C9\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9(H*W\u30B0\u30EA\u30C3\u30C9,\
    \ \u59CB\u70B9{h, w})\nusing P = tuple<ll, int, int>;\nvvl dijkstra(const vvl\
    \ &grid, pii src, ll invalid = -1) {\n    int H = grid.size();\n    int W = grid[0].size();\n\
    \    auto res = listnd(H, W, INF);\n    priority_queue<P, vector<P>, greater<P>>\
    \ que;\n    auto [sh, sw] = src;\n    que.push({0, sh, sw});\n    res[sh][sw]\
    \ = 0;\n\n    while (que.size()) {\n        auto [dist, h, w] = que.top();\n \
    \       que.pop();\n        if (res[h][w] < dist) continue;\n        for (auto\
    \ [dh, dw] : dir4) {\n            int nh = h + dh;\n            int nw = w + dw;\n\
    \            if (nh < 0 or nw < 0 or nh >= H or nw >= W) continue;\n         \
    \   if (grid[nh][nw] == invalid) continue;\n            ll cost = grid[nh][nw];\n\
    \            if (chmin(res[nh][nw], dist + cost)) {\n                que.push({dist\
    \ + cost, nh, nw});\n            }\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/common/chmin.hpp
  - src/common/listnd.hpp
  - src/macros.hpp
  - src/base.hpp
  - src/grid/constants/dir4.hpp
  isVerificationFile: false
  path: src/grid/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-12-11 16:15:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/grid/dijkstra.hpp
layout: document
redirect_from:
- /library/src/grid/dijkstra.hpp
- /library/src/grid/dijkstra.hpp.html
title: src/grid/dijkstra.hpp
---
