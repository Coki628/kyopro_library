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
    - https://ta7uw.hatenablog.com/entry/2019/09/29/162635
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/datastructure/BIT2D.hpp\"\n\n// 2\u6B21\u5143\
    BIT\n// \u53C2\u8003\uFF1Ahttps://ta7uw.hatenablog.com/entry/2019/09/29/162635\n\
    // \u30FB\u4ED6\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u3068\u4F7F\u3044\u52DD\u624B\
    \u3092\u7D71\u4E00\u3057\u305F\u3044\u306E\u3067\u3001\u64CD\u4F5C\u3068\u3057\
    \u3066\u306F0-indexed\u3067\u52D5\u304B\u305B\u308B\u3088\u3046\u306B\u3057\u3066\
    \u3042\u308B\u3002\ntemplate<typename T>\nclass BIT2D {\n    int H;\n    int W;\n\
    \    vv<T> data2d;\n\npublic:\n    BIT2D(int H, int W) : H(H), W(W) {\n      \
    \  data2d.resize(H + 1, vector<T>(W + 1, 0));\n    }\n\n    // [0,h],[0,w]\n \
    \   T sum(int h, int w) {\n        T res = 0;\n        h++, w++;\n        for\
    \ (int i = h; i > 0; i -= i & -i) {\n            for (int j = w; j > 0; j -= j\
    \ & -j) {\n                res += data2d[i - 1][j - 1];\n            }\n     \
    \   }\n        return res;\n    }\n\n    // [h1,h2),[w1,w2)\u306E\u533A\u9593\u548C\
    \n    T query(int h1, int w1, int h2, int w2) {\n        return sum(h2 - 1, w2\
    \ - 1) - sum(h1 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) +\n               sum(h1 -\
    \ 1, w1 - 1);\n    }\n\n    T get(int h, int w) {\n        return query(h, w,\
    \ h + 1, w + 1);\n    }\n\n    void add(int h, int w, T x) {\n        h++, w++;\n\
    \        for (int i = h; i <= H; i += i & -i) {\n            for (int j = w; j\
    \ <= W; j += j & -j) {\n                data2d[i - 1][j - 1] += x;\n         \
    \   }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// 2\u6B21\u5143BIT\n// \u53C2\u8003\
    \uFF1Ahttps://ta7uw.hatenablog.com/entry/2019/09/29/162635\n// \u30FB\u4ED6\u306E\
    \u30E9\u30A4\u30D6\u30E9\u30EA\u3068\u4F7F\u3044\u52DD\u624B\u3092\u7D71\u4E00\
    \u3057\u305F\u3044\u306E\u3067\u3001\u64CD\u4F5C\u3068\u3057\u3066\u306F0-indexed\u3067\
    \u52D5\u304B\u305B\u308B\u3088\u3046\u306B\u3057\u3066\u3042\u308B\u3002\ntemplate<typename\
    \ T>\nclass BIT2D {\n    int H;\n    int W;\n    vv<T> data2d;\n\npublic:\n  \
    \  BIT2D(int H, int W) : H(H), W(W) {\n        data2d.resize(H + 1, vector<T>(W\
    \ + 1, 0));\n    }\n\n    // [0,h],[0,w]\n    T sum(int h, int w) {\n        T\
    \ res = 0;\n        h++, w++;\n        for (int i = h; i > 0; i -= i & -i) {\n\
    \            for (int j = w; j > 0; j -= j & -j) {\n                res += data2d[i\
    \ - 1][j - 1];\n            }\n        }\n        return res;\n    }\n\n    //\
    \ [h1,h2),[w1,w2)\u306E\u533A\u9593\u548C\n    T query(int h1, int w1, int h2,\
    \ int w2) {\n        return sum(h2 - 1, w2 - 1) - sum(h1 - 1, w2 - 1) - sum(h2\
    \ - 1, w1 - 1) +\n               sum(h1 - 1, w1 - 1);\n    }\n\n    T get(int\
    \ h, int w) {\n        return query(h, w, h + 1, w + 1);\n    }\n\n    void add(int\
    \ h, int w, T x) {\n        h++, w++;\n        for (int i = h; i <= H; i += i\
    \ & -i) {\n            for (int j = w; j <= W; j += j & -j) {\n              \
    \  data2d[i - 1][j - 1] += x;\n            }\n        }\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/BIT2D.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/BIT2D.hpp
layout: document
redirect_from:
- /library/src/datastructure/BIT2D.hpp
- /library/src/datastructure/BIT2D.hpp.html
title: src/datastructure/BIT2D.hpp
---
