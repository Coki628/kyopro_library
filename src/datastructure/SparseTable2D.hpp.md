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
    links:
    - https://codeforces.com/blog/entry/45485
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/SparseTable2D.hpp\"\
    \n\n// 2D\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\uFF1A\u69CB\u7BC9\u306B\
    O(HWlogHlogW)\u3001\u533A\u9593\u6700\u5C0F(\u6700\u5927)\u3092O(1)\u3067\u53D6\
    \u5F97\n// see: https://codeforces.com/blog/entry/45485\n// \u30FB\u4F7F\u3044\
    \u52DD\u624B\u306F2D\u30BB\u30B0\u6728\u3068\u307B\u307C\u540C\u3058\u611F\u3058\
    \u306B\u3057\u3066\u3042\u308B\u3002\n// \u30FB2D\u3067log2\u3064\u4E57\u308B\u6240\
    \u304CO(1)\u306B\u306A\u308B\u306E\u3067\u3001\u30AF\u30A8\u30EA\u306F\u3055\u3059\
    \u304C\u306B\u901F\u3044\u3068\u601D\u3046\u3002\n// \u30FB\u305F\u3060\u3057\u30E1\
    \u30E2\u30EA\u306FHWlogHlogW\u3082\u98DF\u3046\u306E\u3067\u3084\u3070\u3044\u3002\
    100\u4E07\u30B0\u30EA\u30C3\u30C9\u3067900MB\u8D85\u3060\u3063\u305F\u306E\u3067\
    \u3001\n// \u3000AtC\u306A\u3089\u3068\u3082\u304B\u304FCF\u3067\u306F\u4F7F\u3044\
    \u7269\u306B\u306A\u3089\u306A\u3044\u3060\u308D\u3046\u2026\u3002\ntemplate<typename\
    \ T, typename F>\nstruct SparseTable2D {\n    const F f;\n    const T e;\n   \
    \ vv<vv<T>> dat;\n    vector<int> heighth, heightw;\n    vv<T> grid;\n\n    SparseTable2D(const\
    \ F f, const T e) : f(f), e(e) {\n    }\n\n    SparseTable2D(int H, int W, const\
    \ F f, const T e) : f(f), e(e) {\n        grid = listnd(H, W, e);\n    }\n\n \
    \   SparseTable2D(const vv<T> &grid, const F f, const T e) : f(f), e(e) {\n  \
    \      build(grid);\n    }\n\n    void set(int h, int w, T val) {\n        grid[h][w]\
    \ = val;\n    }\n\n    void build() {\n        build(grid);\n    }\n\n    void\
    \ build(const vv<T> &grid) {\n        int H = grid.size();\n        int W = grid[0].size();\n\
    \n        int hh = 0, wh = 0;\n        while ((1 << hh) <= H) {\n            hh++;\n\
    \        }\n        while ((1 << wh) <= W) {\n            wh++;\n        }\n \
    \       dat = listnd(hh, wh, 1 << hh, 1 << wh, e);\n        heighth.resize(H +\
    \ 1);\n        heightw.resize(W + 1);\n\n        for (int i = 2; i < H + 1; i++)\
    \ {\n            heighth[i] = heighth[i >> 1] + 1;\n        }\n        for (int\
    \ i = 2; i < W + 1; i++) {\n            heightw[i] = heightw[i >> 1] + 1;\n  \
    \      }\n        for (int i = 0; i < H; i++) {\n            for (int j = 0; j\
    \ < W; j++) {\n                dat[0][0][i][j] = grid[i][j];\n            }\n\
    \            for (int kw = 1; kw < wh; kw++) {\n                for (int j = 0;\
    \ j < W; j++) {\n                    dat[0][kw][i][j] =\n                    \
    \    f(dat[0][kw - 1][i][j],\n                          dat[0][kw - 1][i][min((int)j\
    \ + (1 << (kw - 1)), W - 1)]);\n                }\n            }\n        }\n\
    \        for (int kh = 1; kh < hh; kh++) {\n            for (int kw = 0; kw <\
    \ wh; kw++) {\n                for (int i = 0; i < H; i++) {\n               \
    \     for (int j = 0; j < W; j++) {\n                        dat[kh][kw][i][j]\
    \ =\n                            f(dat[kh - 1][kw][i][j],\n                  \
    \            dat[kh - 1][kw][min((int)i + (1 << (kh - 1)), H - 1)][j]);\n    \
    \                }\n                }\n            }\n        }\n    }\n\n   \
    \ T query(int sh, int sw, int th, int tw) {\n        if (sh >= th or sw >= tw)\
    \ return e;\n        int a = heighth[th - sh];\n        int b = heightw[tw - sw];\n\
    \        return f(\n            f(dat[a][b][sh][sw], dat[a][b][sh][tw - (1 <<\
    \ b)]),\n            f(dat[a][b][th - (1 << a)][sw],\n              dat[a][b][th\
    \ - (1 << a)][tw - (1 << b)])\n        );\n    }\n};\n\ntemplate<typename T, typename\
    \ F>\nSparseTable2D<T, F> get_sparse_table_2d(const F &f, const T &M1) {\n   \
    \ return {f, M1};\n}\n\ntemplate<typename T, typename F>\nSparseTable2D<T, F>\
    \ get_sparse_table_2d(int H, int W, const F &f, const T &M1) {\n    return {H,\
    \ W, f, M1};\n}\n\ntemplate<typename T, typename F>\nSparseTable2D<T, F> get_sparse_table_2d(vv<T>\
    \ &grid, const F &f, const T &M1) {\n    return {grid, f, M1};\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// 2D\u30B9\u30D1\u30FC\u30B9\
    \u30C6\u30FC\u30D6\u30EB\uFF1A\u69CB\u7BC9\u306BO(HWlogHlogW)\u3001\u533A\u9593\
    \u6700\u5C0F(\u6700\u5927)\u3092O(1)\u3067\u53D6\u5F97\n// see: https://codeforces.com/blog/entry/45485\n\
    // \u30FB\u4F7F\u3044\u52DD\u624B\u306F2D\u30BB\u30B0\u6728\u3068\u307B\u307C\u540C\
    \u3058\u611F\u3058\u306B\u3057\u3066\u3042\u308B\u3002\n// \u30FB2D\u3067log2\u3064\
    \u4E57\u308B\u6240\u304CO(1)\u306B\u306A\u308B\u306E\u3067\u3001\u30AF\u30A8\u30EA\
    \u306F\u3055\u3059\u304C\u306B\u901F\u3044\u3068\u601D\u3046\u3002\n// \u30FB\u305F\
    \u3060\u3057\u30E1\u30E2\u30EA\u306FHWlogHlogW\u3082\u98DF\u3046\u306E\u3067\u3084\
    \u3070\u3044\u3002100\u4E07\u30B0\u30EA\u30C3\u30C9\u3067900MB\u8D85\u3060\u3063\
    \u305F\u306E\u3067\u3001\n// \u3000AtC\u306A\u3089\u3068\u3082\u304B\u304FCF\u3067\
    \u306F\u4F7F\u3044\u7269\u306B\u306A\u3089\u306A\u3044\u3060\u308D\u3046\u2026\
    \u3002\ntemplate<typename T, typename F>\nstruct SparseTable2D {\n    const F\
    \ f;\n    const T e;\n    vv<vv<T>> dat;\n    vector<int> heighth, heightw;\n\
    \    vv<T> grid;\n\n    SparseTable2D(const F f, const T e) : f(f), e(e) {\n \
    \   }\n\n    SparseTable2D(int H, int W, const F f, const T e) : f(f), e(e) {\n\
    \        grid = listnd(H, W, e);\n    }\n\n    SparseTable2D(const vv<T> &grid,\
    \ const F f, const T e) : f(f), e(e) {\n        build(grid);\n    }\n\n    void\
    \ set(int h, int w, T val) {\n        grid[h][w] = val;\n    }\n\n    void build()\
    \ {\n        build(grid);\n    }\n\n    void build(const vv<T> &grid) {\n    \
    \    int H = grid.size();\n        int W = grid[0].size();\n\n        int hh =\
    \ 0, wh = 0;\n        while ((1 << hh) <= H) {\n            hh++;\n        }\n\
    \        while ((1 << wh) <= W) {\n            wh++;\n        }\n        dat =\
    \ listnd(hh, wh, 1 << hh, 1 << wh, e);\n        heighth.resize(H + 1);\n     \
    \   heightw.resize(W + 1);\n\n        for (int i = 2; i < H + 1; i++) {\n    \
    \        heighth[i] = heighth[i >> 1] + 1;\n        }\n        for (int i = 2;\
    \ i < W + 1; i++) {\n            heightw[i] = heightw[i >> 1] + 1;\n        }\n\
    \        for (int i = 0; i < H; i++) {\n            for (int j = 0; j < W; j++)\
    \ {\n                dat[0][0][i][j] = grid[i][j];\n            }\n          \
    \  for (int kw = 1; kw < wh; kw++) {\n                for (int j = 0; j < W; j++)\
    \ {\n                    dat[0][kw][i][j] =\n                        f(dat[0][kw\
    \ - 1][i][j],\n                          dat[0][kw - 1][i][min((int)j + (1 <<\
    \ (kw - 1)), W - 1)]);\n                }\n            }\n        }\n        for\
    \ (int kh = 1; kh < hh; kh++) {\n            for (int kw = 0; kw < wh; kw++) {\n\
    \                for (int i = 0; i < H; i++) {\n                    for (int j\
    \ = 0; j < W; j++) {\n                        dat[kh][kw][i][j] =\n          \
    \                  f(dat[kh - 1][kw][i][j],\n                              dat[kh\
    \ - 1][kw][min((int)i + (1 << (kh - 1)), H - 1)][j]);\n                    }\n\
    \                }\n            }\n        }\n    }\n\n    T query(int sh, int\
    \ sw, int th, int tw) {\n        if (sh >= th or sw >= tw) return e;\n       \
    \ int a = heighth[th - sh];\n        int b = heightw[tw - sw];\n        return\
    \ f(\n            f(dat[a][b][sh][sw], dat[a][b][sh][tw - (1 << b)]),\n      \
    \      f(dat[a][b][th - (1 << a)][sw],\n              dat[a][b][th - (1 << a)][tw\
    \ - (1 << b)])\n        );\n    }\n};\n\ntemplate<typename T, typename F>\nSparseTable2D<T,\
    \ F> get_sparse_table_2d(const F &f, const T &M1) {\n    return {f, M1};\n}\n\n\
    template<typename T, typename F>\nSparseTable2D<T, F> get_sparse_table_2d(int\
    \ H, int W, const F &f, const T &M1) {\n    return {H, W, f, M1};\n}\n\ntemplate<typename\
    \ T, typename F>\nSparseTable2D<T, F> get_sparse_table_2d(vv<T> &grid, const F\
    \ &f, const T &M1) {\n    return {grid, f, M1};\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/SparseTable2D.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/SparseTable2D.hpp
layout: document
redirect_from:
- /library/src/datastructure/SparseTable2D.hpp
- /library/src/datastructure/SparseTable2D.hpp.html
title: src/datastructure/SparseTable2D.hpp
---
