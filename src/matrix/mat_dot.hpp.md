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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/matrix/MatPow.hpp
    title: src/matrix/MatPow.hpp
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
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\n\
    #define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i\
    \ < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define\
    \ rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c\
    \ < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b);\
    \ i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/listnd.hpp\"\
    \n\ntemplate<typename T>\n[[deprecated(\"list2d will be merged with listnd\")]]\n\
    vector<vector<T>> list2d(int N, int M, T init) {\n    return vector<vector<T>>(N,\
    \ vector<T>(M, init));\n}\n\ntemplate<typename T>\n[[deprecated(\"list3d will\
    \ be merged with listnd\")]]\nvector<vector<vector<T>>> list3d(int N, int M, int\
    \ L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L,\
    \ init)));\n}\n\ntemplate<typename T>\n[[deprecated(\"list4d will be merged with\
    \ listnd\")]]\nvector<vector<vector<vector<T>>>> list4d(int N, int M, int L, int\
    \ O, T init) {\n    return vector<vector<vector<vector<T>>>>(N, vector<vector<vector<T>>>(M,\
    \ vector<vector<T>>(L, vector<T>(O, init))));\n}\n\n// \u4EFB\u610F\u6B21\u5143\
    vector\n// \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
    template<typename T>\nvector<T> listnd(size_t a, T b) {\n    return vector<T>(a,\
    \ b);\n}\n\ntemplate<typename... Ts>\nauto listnd(size_t a, Ts... ts) {\n    return\
    \ vector<decltype(listnd(ts...))>(a, listnd(ts...));\n}\n#line 4 \"src/matrix/mat_dot.hpp\"\
    \n\n// \u884C\u5217\u306E\u7A4D\ntemplate<typename T>\nvector<vector<T>> mat_dot(const\
    \ vector<vector<T>> &A, const vector<vector<T>> &B) {\n    int n1 = A.size();\n\
    \    int n2 = A[0].size();\n    int m2 = B[0].size();\n    auto res = list2d(n1,\
    \ m2, (T)0);\n    rep(i, n1) {\n        rep(k, n2) {\n            if (A[i][k]\
    \ == 0) continue;\n            rep(j, m2) {\n                res[i][j] += A[i][k]\
    \ * B[k][j];\n            }\n        }\n    }\n    return res;\n}\n\ntemplate<typename\
    \ T, size_t SZ1, size_t SZ2, size_t SZ3>\narray<array<T, SZ3>, SZ1> mat_dot(const\
    \ array<array<T, SZ2>, SZ1> &A, const array<array<T, SZ3>, SZ2> &B) {\n    //\
    \ \u30B0\u30ED\u30FC\u30D0\u30EB\u3067\u306A\u3044array\u306F\u521D\u671F\u5316\
    \u3055\u308C\u306A\u3044\u306E\u3067{}\u3067\u521D\u671F\u5316(0\u57CB\u3081)\u3059\
    \u308B\n    array<array<T, SZ3>, SZ1> res{};\n    rep(i, SZ1) {\n        rep(k,\
    \ SZ2) {\n            if (A[i][k] == 0) continue;\n            rep(j, SZ3) {\n\
    \                res[i][j] += A[i][k] * B[k][j];\n            }\n        }\n \
    \   }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"../common/listnd.hpp\"\
    \n\n// \u884C\u5217\u306E\u7A4D\ntemplate<typename T>\nvector<vector<T>> mat_dot(const\
    \ vector<vector<T>> &A, const vector<vector<T>> &B) {\n    int n1 = A.size();\n\
    \    int n2 = A[0].size();\n    int m2 = B[0].size();\n    auto res = list2d(n1,\
    \ m2, (T)0);\n    rep(i, n1) {\n        rep(k, n2) {\n            if (A[i][k]\
    \ == 0) continue;\n            rep(j, m2) {\n                res[i][j] += A[i][k]\
    \ * B[k][j];\n            }\n        }\n    }\n    return res;\n}\n\ntemplate<typename\
    \ T, size_t SZ1, size_t SZ2, size_t SZ3>\narray<array<T, SZ3>, SZ1> mat_dot(const\
    \ array<array<T, SZ2>, SZ1> &A, const array<array<T, SZ3>, SZ2> &B) {\n    //\
    \ \u30B0\u30ED\u30FC\u30D0\u30EB\u3067\u306A\u3044array\u306F\u521D\u671F\u5316\
    \u3055\u308C\u306A\u3044\u306E\u3067{}\u3067\u521D\u671F\u5316(0\u57CB\u3081)\u3059\
    \u308B\n    array<array<T, SZ3>, SZ1> res{};\n    rep(i, SZ1) {\n        rep(k,\
    \ SZ2) {\n            if (A[i][k] == 0) continue;\n            rep(j, SZ3) {\n\
    \                res[i][j] += A[i][k] * B[k][j];\n            }\n        }\n \
    \   }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/matrix/mat_dot.hpp
  requiredBy:
  - src/matrix/MatPow.hpp
  timestamp: '2023-02-28 01:25:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/MatPow.test.cpp
documentation_of: src/matrix/mat_dot.hpp
layout: document
redirect_from:
- /library/src/matrix/mat_dot.hpp
- /library/src/matrix/mat_dot.hpp.html
title: src/matrix/mat_dot.hpp
---
