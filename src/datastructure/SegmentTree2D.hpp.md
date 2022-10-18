---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://algoogle.hadrori.jp/algorithm/2d-segment-tree.html
    - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
    - https://qiita.com/tomato1997/items/83ccdfe0ce1f5548a42a
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/datastructure/SegmentTree2D.hpp\"\n\n// \u53C2\
    \u8003\uFF1Ahttp://algoogle.hadrori.jp/algorithm/2d-segment-tree.html\n// \u3000\
    \u3000\u3000https://qiita.com/tomato1997/items/83ccdfe0ce1f5548a42a\n// \u3000\
    \u3000\u3000https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html\n\
    // 2D\u30BB\u30B0\u6728(\u975E\u518D\u5E30\u3001\u66F4\u65B0\u3042\u308A)\ntemplate<typename\
    \ T, typename F>\nstruct SegmentTree2D {\n\n    int H, W;\n    vector<vector<T>>\
    \ dat;\n    const F f;\n    const T M1;\n\n    SegmentTree2D(const F f, const\
    \ T &M1) : f(f), M1(M1) {}\n\n    SegmentTree2D(int _H, int _W, const F f, const\
    \ T &M1) : f(f), M1(M1) {\n        H = W = 1;\n        while(H < _H) H <<= 1;\n\
    \        while(W < _W) W <<= 1;\n        dat.assign(2*H,vector<T>(2*W, M1));\n\
    \    }\n\n    SegmentTree2D(vector<vector<T>> &grid, const F f, const T &M1) :\
    \ f(f), M1(M1) {\n        H = W = 1;\n        while(H < (int)grid.size()) H <<=\
    \ 1;\n        while(W < (int)grid[0].size()) W <<= 1;\n        dat.assign(2*H,vector<T>(2*W,\
    \ M1));\n        for (int i = 0; i < (int)grid.size(); i++)\n            for (int\
    \ j = 0; j < (int)grid[0].size(); j++)\n                dat[H+i][W+j] = grid[i][j];\n\
    \        build();\n    }\n\n    void set(int i, int j, T x) {\n        dat[H+i][W+j]\
    \ = x;\n    }\n\n    T get(int i, int j) {\n        return dat[H+i][W+j];\n  \
    \  }\n\n    void build() {\n        for (int i = 2*H-1; i > H-1; i--)\n      \
    \      for (int j = W-1; j > 0; j--)\n                dat[i][j] = f(dat[i][2*j],\
    \ dat[i][2*j+1]);\n        for (int i = H-1; i > 0; i--)\n            for (int\
    \ j = 1; j < 2*W; j++)\n                dat[i][j] = f(dat[2*i][j], dat[2*i+1][j]);\n\
    \    }\n\n    T query(int Lx, int Ly, int Rx, int Ry) {\n        T vLx = M1, vRx\
    \ = M1;\n        for (Lx += H, Rx += H; Lx < Rx; Lx >>= 1, Rx >>= 1) {\n     \
    \       if (Lx & 1) {\n                T vLy = M1, vRy = M1;\n               \
    \ for (T Ly1 = Ly + W, Ry1 = Ry + W; Ly1 < Ry1; Ly1 >>= 1, Ry1 >>= 1) {\n    \
    \                if (Ly1 & 1) vLy = f(vLy, dat[Lx][Ly1++]);\n                \
    \    if (Ry1 & 1) vRy = f(dat[Lx][--Ry1], vRy);\n                }\n         \
    \       vLx = f(vLx, f(vLy, vRy));\n                Lx++;\n            }\n   \
    \         if (Rx & 1) {\n                Rx--;\n                T vLy = M1, vRy\
    \ = M1;\n                for (T Ly1 = Ly + W, Ry1 = Ry + W; Ly1 < Ry1; Ly1 >>=\
    \ 1, Ry1 >>= 1) {\n                    if (Ly1 & 1) vLy = f(vLy, dat[Rx][Ly1++]);\n\
    \                    if (Ry1 & 1) vRy = f(dat[Rx][--Ry1], vRy);\n            \
    \    }\n                vRx = f(f(vLy, vRy), vRx);\n            }\n        }\n\
    \        return f(vLx, vRx);\n    }\n\n    void update(int x, int y, int val)\
    \ {\n        int i = x + H;\n        int j = y + W;\n        dat[i][j] = val;\n\
    \        while (j >>= 1) {\n            dat[i][j] = f(dat[i][2*j], dat[i][2*j+1]);\n\
    \        }\n        while (i >>= 1) {\n            j = y + W;\n            dat[i][j]\
    \ = f(dat[2*i][j], dat[2*i+1][j]);\n            while (j >>= 1) {\n          \
    \      dat[i][j] = f(dat[i][2*j], dat[i][2*j+1]);\n            }\n        }\n\
    \    }\n};\n\ntemplate<typename T, typename F>\nSegmentTree2D<T, F> get_segment_tree_2d(const\
    \ F& f, const T& M1) {\n    return {f, M1};\n}\n\ntemplate<typename T, typename\
    \ F>\nSegmentTree2D<T, F> get_segment_tree_2d(int H, int W, const F& f, const\
    \ T& M1) {\n    return {H, W, f, M1};\n}\n\ntemplate<typename T, typename F>\n\
    SegmentTree2D<T, F> get_segment_tree_2d(vector<vector<T>> &grid, const F& f, const\
    \ T& M1) {\n    return {grid, f, M1};\n}\n"
  code: "#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttp://algoogle.hadrori.jp/algorithm/2d-segment-tree.html\n\
    // \u3000\u3000\u3000https://qiita.com/tomato1997/items/83ccdfe0ce1f5548a42a\n\
    // \u3000\u3000\u3000https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html\n\
    // 2D\u30BB\u30B0\u6728(\u975E\u518D\u5E30\u3001\u66F4\u65B0\u3042\u308A)\ntemplate<typename\
    \ T, typename F>\nstruct SegmentTree2D {\n\n    int H, W;\n    vector<vector<T>>\
    \ dat;\n    const F f;\n    const T M1;\n\n    SegmentTree2D(const F f, const\
    \ T &M1) : f(f), M1(M1) {}\n\n    SegmentTree2D(int _H, int _W, const F f, const\
    \ T &M1) : f(f), M1(M1) {\n        H = W = 1;\n        while(H < _H) H <<= 1;\n\
    \        while(W < _W) W <<= 1;\n        dat.assign(2*H,vector<T>(2*W, M1));\n\
    \    }\n\n    SegmentTree2D(vector<vector<T>> &grid, const F f, const T &M1) :\
    \ f(f), M1(M1) {\n        H = W = 1;\n        while(H < (int)grid.size()) H <<=\
    \ 1;\n        while(W < (int)grid[0].size()) W <<= 1;\n        dat.assign(2*H,vector<T>(2*W,\
    \ M1));\n        for (int i = 0; i < (int)grid.size(); i++)\n            for (int\
    \ j = 0; j < (int)grid[0].size(); j++)\n                dat[H+i][W+j] = grid[i][j];\n\
    \        build();\n    }\n\n    void set(int i, int j, T x) {\n        dat[H+i][W+j]\
    \ = x;\n    }\n\n    T get(int i, int j) {\n        return dat[H+i][W+j];\n  \
    \  }\n\n    void build() {\n        for (int i = 2*H-1; i > H-1; i--)\n      \
    \      for (int j = W-1; j > 0; j--)\n                dat[i][j] = f(dat[i][2*j],\
    \ dat[i][2*j+1]);\n        for (int i = H-1; i > 0; i--)\n            for (int\
    \ j = 1; j < 2*W; j++)\n                dat[i][j] = f(dat[2*i][j], dat[2*i+1][j]);\n\
    \    }\n\n    T query(int Lx, int Ly, int Rx, int Ry) {\n        T vLx = M1, vRx\
    \ = M1;\n        for (Lx += H, Rx += H; Lx < Rx; Lx >>= 1, Rx >>= 1) {\n     \
    \       if (Lx & 1) {\n                T vLy = M1, vRy = M1;\n               \
    \ for (T Ly1 = Ly + W, Ry1 = Ry + W; Ly1 < Ry1; Ly1 >>= 1, Ry1 >>= 1) {\n    \
    \                if (Ly1 & 1) vLy = f(vLy, dat[Lx][Ly1++]);\n                \
    \    if (Ry1 & 1) vRy = f(dat[Lx][--Ry1], vRy);\n                }\n         \
    \       vLx = f(vLx, f(vLy, vRy));\n                Lx++;\n            }\n   \
    \         if (Rx & 1) {\n                Rx--;\n                T vLy = M1, vRy\
    \ = M1;\n                for (T Ly1 = Ly + W, Ry1 = Ry + W; Ly1 < Ry1; Ly1 >>=\
    \ 1, Ry1 >>= 1) {\n                    if (Ly1 & 1) vLy = f(vLy, dat[Rx][Ly1++]);\n\
    \                    if (Ry1 & 1) vRy = f(dat[Rx][--Ry1], vRy);\n            \
    \    }\n                vRx = f(f(vLy, vRy), vRx);\n            }\n        }\n\
    \        return f(vLx, vRx);\n    }\n\n    void update(int x, int y, int val)\
    \ {\n        int i = x + H;\n        int j = y + W;\n        dat[i][j] = val;\n\
    \        while (j >>= 1) {\n            dat[i][j] = f(dat[i][2*j], dat[i][2*j+1]);\n\
    \        }\n        while (i >>= 1) {\n            j = y + W;\n            dat[i][j]\
    \ = f(dat[2*i][j], dat[2*i+1][j]);\n            while (j >>= 1) {\n          \
    \      dat[i][j] = f(dat[i][2*j], dat[i][2*j+1]);\n            }\n        }\n\
    \    }\n};\n\ntemplate<typename T, typename F>\nSegmentTree2D<T, F> get_segment_tree_2d(const\
    \ F& f, const T& M1) {\n    return {f, M1};\n}\n\ntemplate<typename T, typename\
    \ F>\nSegmentTree2D<T, F> get_segment_tree_2d(int H, int W, const F& f, const\
    \ T& M1) {\n    return {H, W, f, M1};\n}\n\ntemplate<typename T, typename F>\n\
    SegmentTree2D<T, F> get_segment_tree_2d(vector<vector<T>> &grid, const F& f, const\
    \ T& M1) {\n    return {grid, f, M1};\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/SegmentTree2D.hpp
  requiredBy: []
  timestamp: '2022-10-18 16:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/SegmentTree2D.hpp
layout: document
redirect_from:
- /library/src/datastructure/SegmentTree2D.hpp
- /library/src/datastructure/SegmentTree2D.hpp.html
title: src/datastructure/SegmentTree2D.hpp
---
