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
    #line 4 \"src/matrix/mat_dot.hpp\"\n\n// \u884C\u5217\u306E\u7A4D\ntemplate<typename\
    \ T>\nvector<vector<T>> mat_dot(const vector<vector<T>> &A, const vector<vector<T>>\
    \ &B) {\n    int n1 = A.size();\n    int n2 = A[0].size();\n    int m2 = B[0].size();\n\
    \    auto res = list2d(n1, m2, (T)0);\n    rep(i, n1) {\n        rep(k, n2) {\n\
    \            if (A[i][k] == 0) continue;\n            rep(j, m2) {\n         \
    \       res[i][j] += A[i][k]*B[k][j];\n            }\n        }\n    }\n    return\
    \ res;\n}\n#line 3 \"src/matrix/MatPow.hpp\"\n\n// \u884C\u5217\u7D2F\u4E57\n\
    template<typename T>\nstruct MatPow {\n\n    MatPow() {}\n\n    vector<vector<T>>\
    \ mat_pow(vector<vector<T>> mat, ll k) {\n        int n = mat.size();\n      \
    \  auto res = list2d(n, n, (T)0);\n        rep(i, n) {\n            res[i][i]\
    \ = 1;\n        }\n        while (k > 0) {\n            if (k & 1) {\n       \
    \         res = mat_dot(res, mat);\n            }\n            mat = mat_dot(mat,\
    \ mat);\n            k >>= 1;\n        }\n        return res;\n    }\n\n    vector<T>\
    \ solve(vector<vector<T>> mat, const vector<T> &_init, ll K) {\n        int n\
    \ = mat.size();\n        auto init = list2d(n, 1, (T)0);\n        rep(i, n) init[i][0]\
    \ = _init[i];\n        auto res = mat_pow(mat, K);\n        res = mat_dot(res,\
    \ init);\n        vector<T> ret(n, 0);\n        rep(i, n) ret[i] = res[i][0];\n\
    \        return ret;\n    }\n};\n"
  code: "#include \"../macros.hpp\"\n#include \"mat_dot.hpp\"\n\n// \u884C\u5217\u7D2F\
    \u4E57\ntemplate<typename T>\nstruct MatPow {\n\n    MatPow() {}\n\n    vector<vector<T>>\
    \ mat_pow(vector<vector<T>> mat, ll k) {\n        int n = mat.size();\n      \
    \  auto res = list2d(n, n, (T)0);\n        rep(i, n) {\n            res[i][i]\
    \ = 1;\n        }\n        while (k > 0) {\n            if (k & 1) {\n       \
    \         res = mat_dot(res, mat);\n            }\n            mat = mat_dot(mat,\
    \ mat);\n            k >>= 1;\n        }\n        return res;\n    }\n\n    vector<T>\
    \ solve(vector<vector<T>> mat, const vector<T> &_init, ll K) {\n        int n\
    \ = mat.size();\n        auto init = list2d(n, 1, (T)0);\n        rep(i, n) init[i][0]\
    \ = _init[i];\n        auto res = mat_pow(mat, K);\n        res = mat_dot(res,\
    \ init);\n        vector<T> ret(n, 0);\n        rep(i, n) ret[i] = res[i][0];\n\
    \        return ret;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/matrix/mat_dot.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/matrix/MatPow.hpp
  requiredBy: []
  timestamp: '2022-04-06 17:44:14+09:00'
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
