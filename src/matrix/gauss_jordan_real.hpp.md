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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/matrix/gauss_jordan_real.hpp\"\
    \n\n// \u6383\u304D\u51FA\u3057\u6CD5\n// \u30FB\u578B\u306F\u9078\u3079\u308B\
    \u3088\u3046\u306B\u3057\u3066\u3042\u308B\u3051\u3069\u3001\u6574\u6570\u578B\
    \u5165\u308C\u308B\u3068\u9664\u7B97\u3068\u304B\u30D0\u30B0\u308B\u3002\u5B9F\
    \u6570\u3067\u306E\u4ED5\u69D8\u304C\u524D\u63D0\u3002\n// \u30FB\u57FA\u672C\u7684\
    \u306B\u5168\u90E8\u6709\u7406\u6570\u306E\u306F\u305A\u306A\u306E\u3067\u3001\
    Fraction\u30AF\u30E9\u30B9\u4F5C\u308C\u3070\u3088\u3055\u305D\u3046\u3060\u304C\
    \u9762\u5012\u3067\u3084\u3063\u3066\u306A\u3044\u3002\ntemplate<typename T>\n\
    vector<T> gauss_jordan(const vv<T> &A, const vector<T> &b) {\n    int N = A.size();\n\
    \    auto B = list2d<T>(N, N + 1, 0);\n    rep(i, N) {\n        rep(j, N) {\n\
    \            B[i][j] = A[i][j];\n        }\n    }\n    // \u884C\u5217A\u306E\u5F8C\
    \u308D\u306Bb\u3092\u4E26\u3079\u540C\u6642\u306B\u51E6\u7406\u3059\u308B\n  \
    \  rep(i, N) {\n        B[i][N] = b[i];\n    }\n\n    rep(i, N) {\n        //\
    \ \u6CE8\u76EE\u3057\u3066\u3044\u308B\u5909\u6570\u306E\u4FC2\u6570\u306E\u7D76\
    \u5BFE\u5024\u304C\u5927\u304D\u3044\u5F0F\u3092i\u756A\u76EE\u306B\u6301\u3063\
    \u3066\u304F\u308B\n        int pivot = i;\n        rep(j, i, N) {\n         \
    \   if (abs(B[j][i]) > abs(B[pivot][i])) {\n                pivot = j;\n     \
    \       }\n        }\n        swap(B[i], B[pivot]);\n\n        // \u89E3\u304C\
    \u306A\u3044\u304B\u3001\u4E00\u610F\u3067\u306A\u3044\n        if (abs(B[i][i])\
    \ < EPS) {\n            return vector<T>();\n        }\n        // \u6CE8\u76EE\
    \u3057\u3066\u3044\u308B\u5909\u6570\u306E\u4FC2\u6570\u30921\u306B\u3059\u308B\
    \n        rep(j, i + 1, N + 1) {\n            B[i][j] /= B[i][i];\n        }\n\
    \        rep(j, N) {\n            if (i != j) {\n                // j\u756A\u76EE\
    \u306E\u5F0F\u304B\u3089i\u756A\u76EE\u306E\u5909\u6570\u3092\u6D88\u53BB\n  \
    \              rep(k, i + 1, N + 1) {\n                    B[j][k] -= B[j][i]\
    \ * B[i][k];\n                }\n            }\n        }\n    }\n\n    vector<T>\
    \ res(N);\n    // \u5F8C\u308D\u306B\u4E26\u3079\u305Fb\u304C\u89E3\u306B\u306A\
    \u308B\n    rep(i, N) {\n        res[i] = B[i][N];\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u6383\u304D\u51FA\u3057\u6CD5\
    \n// \u30FB\u578B\u306F\u9078\u3079\u308B\u3088\u3046\u306B\u3057\u3066\u3042\u308B\
    \u3051\u3069\u3001\u6574\u6570\u578B\u5165\u308C\u308B\u3068\u9664\u7B97\u3068\
    \u304B\u30D0\u30B0\u308B\u3002\u5B9F\u6570\u3067\u306E\u4ED5\u69D8\u304C\u524D\
    \u63D0\u3002\n// \u30FB\u57FA\u672C\u7684\u306B\u5168\u90E8\u6709\u7406\u6570\u306E\
    \u306F\u305A\u306A\u306E\u3067\u3001Fraction\u30AF\u30E9\u30B9\u4F5C\u308C\u3070\
    \u3088\u3055\u305D\u3046\u3060\u304C\u9762\u5012\u3067\u3084\u3063\u3066\u306A\
    \u3044\u3002\ntemplate<typename T>\nvector<T> gauss_jordan(const vv<T> &A, const\
    \ vector<T> &b) {\n    int N = A.size();\n    auto B = list2d<T>(N, N + 1, 0);\n\
    \    rep(i, N) {\n        rep(j, N) {\n            B[i][j] = A[i][j];\n      \
    \  }\n    }\n    // \u884C\u5217A\u306E\u5F8C\u308D\u306Bb\u3092\u4E26\u3079\u540C\
    \u6642\u306B\u51E6\u7406\u3059\u308B\n    rep(i, N) {\n        B[i][N] = b[i];\n\
    \    }\n\n    rep(i, N) {\n        // \u6CE8\u76EE\u3057\u3066\u3044\u308B\u5909\
    \u6570\u306E\u4FC2\u6570\u306E\u7D76\u5BFE\u5024\u304C\u5927\u304D\u3044\u5F0F\
    \u3092i\u756A\u76EE\u306B\u6301\u3063\u3066\u304F\u308B\n        int pivot = i;\n\
    \        rep(j, i, N) {\n            if (abs(B[j][i]) > abs(B[pivot][i])) {\n\
    \                pivot = j;\n            }\n        }\n        swap(B[i], B[pivot]);\n\
    \n        // \u89E3\u304C\u306A\u3044\u304B\u3001\u4E00\u610F\u3067\u306A\u3044\
    \n        if (abs(B[i][i]) < EPS) {\n            return vector<T>();\n       \
    \ }\n        // \u6CE8\u76EE\u3057\u3066\u3044\u308B\u5909\u6570\u306E\u4FC2\u6570\
    \u30921\u306B\u3059\u308B\n        rep(j, i + 1, N + 1) {\n            B[i][j]\
    \ /= B[i][i];\n        }\n        rep(j, N) {\n            if (i != j) {\n   \
    \             // j\u756A\u76EE\u306E\u5F0F\u304B\u3089i\u756A\u76EE\u306E\u5909\
    \u6570\u3092\u6D88\u53BB\n                rep(k, i + 1, N + 1) {\n           \
    \         B[j][k] -= B[j][i] * B[i][k];\n                }\n            }\n  \
    \      }\n    }\n\n    vector<T> res(N);\n    // \u5F8C\u308D\u306B\u4E26\u3079\
    \u305Fb\u304C\u89E3\u306B\u306A\u308B\n    rep(i, N) {\n        res[i] = B[i][N];\n\
    \    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/matrix/gauss_jordan_real.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:50:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/matrix/gauss_jordan_real.hpp
layout: document
redirect_from:
- /library/src/matrix/gauss_jordan_real.hpp
- /library/src/matrix/gauss_jordan_real.hpp.html
title: src/matrix/gauss_jordan_real.hpp
---
