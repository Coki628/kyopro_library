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
  - icon: ':heavy_check_mark:'
    path: src/matrix/mat_dot.hpp
    title: src/matrix/mat_dot.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix/MatPow.test.cpp
    title: test/matrix/MatPow.test.cpp
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
    \ { return listnd(N, M, L, O, init); }\n#line 4 \"src/matrix/mat_dot.hpp\"\n\n\
    // \u884C\u5217\u306E\u7A4D\ntemplate<typename T>\nvv<T> mat_dot(const vv<T> &A,\
    \ const vv<T> &B) {\n    int n1 = A.size();\n    int n2 = A[0].size();\n    int\
    \ m2 = B[0].size();\n    auto res = listnd(n1, m2, (T)0);\n    rep(i, n1) {\n\
    \        rep(k, n2) {\n            if (A[i][k] == 0) continue;\n            rep(j,\
    \ m2) {\n                res[i][j] += A[i][k] * B[k][j];\n            }\n    \
    \    }\n    }\n    return res;\n}\n\ntemplate<typename T, size_t SZ1, size_t SZ2,\
    \ size_t SZ3>\narray<array<T, SZ3>, SZ1> mat_dot(\n    const array<array<T, SZ2>,\
    \ SZ1> &A, const array<array<T, SZ3>, SZ2> &B\n) {\n    // \u30B0\u30ED\u30FC\u30D0\
    \u30EB\u3067\u306A\u3044array\u306F\u521D\u671F\u5316\u3055\u308C\u306A\u3044\u306E\
    \u3067{}\u3067\u521D\u671F\u5316(0\u57CB\u3081)\u3059\u308B\n    array<array<T,\
    \ SZ3>, SZ1> res{};\n    rep(i, SZ1) {\n        rep(k, SZ2) {\n            if\
    \ (A[i][k] == 0) continue;\n            rep(j, SZ3) {\n                res[i][j]\
    \ += A[i][k] * B[k][j];\n            }\n        }\n    }\n    return res;\n}\n\
    #line 4 \"src/matrix/MatPow.hpp\"\n\n// \u884C\u5217\u7D2F\u4E57\n// \u30FBDP\u9077\
    \u79FB\u3068\u306E\u5BFE\u5FDC\u306FABC129f\u3042\u305F\u308A\u304C\u898B\u3084\
    \u3059\u305D\u3046\u3002\ntemplate<typename T>\nstruct MatPow {\n    MatPow()\
    \ {}\n\n    vv<T> mat_pow(vv<T> mat, ll k) {\n        int n = mat.size();\n  \
    \      auto res = list2d(n, n, (T)0);\n        rep(i, n) {\n            res[i][i]\
    \ = 1;\n        }\n        while (k > 0) {\n            if (k & 1) {\n       \
    \         res = mat_dot(res, mat);\n            }\n            mat = mat_dot(mat,\
    \ mat);\n            k >>= 1;\n        }\n        return res;\n    }\n\n    template<size_t\
    \ SZ>\n    array<array<T, SZ>, SZ> mat_pow(array<array<T, SZ>, SZ> mat, ll k)\
    \ {\n        int n = mat.size();\n        array<array<T, SZ>, SZ> res = {};\n\
    \        rep(i, n) {\n            res[i][i] = 1;\n        }\n        while (k\
    \ > 0) {\n            if (k & 1) {\n                res = mat_dot(res, mat);\n\
    \            }\n            mat = mat_dot(mat, mat);\n            k >>= 1;\n \
    \       }\n        return res;\n    }\n\n    vector<T> solve(vv<T> mat, const\
    \ vector<T> &init, ll K) {\n        int n = mat.size();\n        auto base = list2d(n,\
    \ 1, (T)0);\n        rep(i, n) base[i][0] = init[i];\n        auto res = mat_pow(mat,\
    \ K);\n        base = mat_dot(res, base);\n        vector<T> ret(n, 0);\n    \
    \    rep(i, n) ret[i] = base[i][0];\n        return ret;\n    }\n\n    template<size_t\
    \ SZ>\n    array<T, SZ> solve(array<array<T, SZ>, SZ> mat, const array<T, SZ>\
    \ &init, ll K) {\n        int n = mat.size();\n        array<array<T, 1>, SZ>\
    \ base = {};\n        rep(i, n) base[i][0] = init[i];\n        auto res = mat_pow(mat,\
    \ K);\n        base = mat_dot(res, base);\n        array<T, SZ> ret = {};\n  \
    \      rep(i, n) ret[i] = base[i][0];\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"mat_dot.hpp\"\n\n//\
    \ \u884C\u5217\u7D2F\u4E57\n// \u30FBDP\u9077\u79FB\u3068\u306E\u5BFE\u5FDC\u306F\
    ABC129f\u3042\u305F\u308A\u304C\u898B\u3084\u3059\u305D\u3046\u3002\ntemplate<typename\
    \ T>\nstruct MatPow {\n    MatPow() {}\n\n    vv<T> mat_pow(vv<T> mat, ll k) {\n\
    \        int n = mat.size();\n        auto res = list2d(n, n, (T)0);\n       \
    \ rep(i, n) {\n            res[i][i] = 1;\n        }\n        while (k > 0) {\n\
    \            if (k & 1) {\n                res = mat_dot(res, mat);\n        \
    \    }\n            mat = mat_dot(mat, mat);\n            k >>= 1;\n        }\n\
    \        return res;\n    }\n\n    template<size_t SZ>\n    array<array<T, SZ>,\
    \ SZ> mat_pow(array<array<T, SZ>, SZ> mat, ll k) {\n        int n = mat.size();\n\
    \        array<array<T, SZ>, SZ> res = {};\n        rep(i, n) {\n            res[i][i]\
    \ = 1;\n        }\n        while (k > 0) {\n            if (k & 1) {\n       \
    \         res = mat_dot(res, mat);\n            }\n            mat = mat_dot(mat,\
    \ mat);\n            k >>= 1;\n        }\n        return res;\n    }\n\n    vector<T>\
    \ solve(vv<T> mat, const vector<T> &init, ll K) {\n        int n = mat.size();\n\
    \        auto base = list2d(n, 1, (T)0);\n        rep(i, n) base[i][0] = init[i];\n\
    \        auto res = mat_pow(mat, K);\n        base = mat_dot(res, base);\n   \
    \     vector<T> ret(n, 0);\n        rep(i, n) ret[i] = base[i][0];\n        return\
    \ ret;\n    }\n\n    template<size_t SZ>\n    array<T, SZ> solve(array<array<T,\
    \ SZ>, SZ> mat, const array<T, SZ> &init, ll K) {\n        int n = mat.size();\n\
    \        array<array<T, 1>, SZ> base = {};\n        rep(i, n) base[i][0] = init[i];\n\
    \        auto res = mat_pow(mat, K);\n        base = mat_dot(res, base);\n   \
    \     array<T, SZ> ret = {};\n        rep(i, n) ret[i] = base[i][0];\n       \
    \ return ret;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/matrix/mat_dot.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/matrix/MatPow.hpp
  requiredBy: []
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/MatPow.test.cpp
documentation_of: src/matrix/MatPow.hpp
layout: document
redirect_from:
- /library/src/matrix/MatPow.hpp
- /library/src/matrix/MatPow.hpp.html
title: src/matrix/MatPow.hpp
---
