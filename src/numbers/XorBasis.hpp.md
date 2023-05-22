---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/common/chmin.hpp\"\
    \n\ntemplate<typename T>\nbool chmin(T &x, T y) {\n    return (y < x) ? x = y,\
    \ true : false;\n}\n#line 3 \"src/numbers/XorBasis.hpp\"\n\n// XOR\u57FA\u5E95\
    (array\u7248\uFF1A\u3053\u3063\u3061\u306E\u304C\u901F\u3044\u3002\u30E1\u30E2\
    \u30EA\u306F\u98DF\u3046\u3002)\ntemplate<typename T, size_t W>\nstruct XorBasis\
    \ {\n    array<T, W> basis = {};\n    vector<T> saved; // \u7DDA\u5F62\u72EC\u7ACB\
    \u306A\u5024\u3092\u4FDD\u6301(zone2021_f\u53C2\u7167)\n    int rank = 0;\n\n\
    \    XorBasis() {}\n\n    XorBasis(const array<T, W>& A) : basis(A) {}\n\n   \
    \ // \u57FA\u5E95\u306Ba\u3092\u8FFD\u52A0\u3001\u57FA\u5E95\u304C\u66F4\u65B0\
    \u3055\u308C\u305F\u3089true\u3092\u8FD4\u3059\uFF1AO(W)\n    bool add(T a) {\n\
    \        if (a == 0) return false;\n        T tmp = a;\n        rep(i, rank) {\n\
    \            chmin(a, a^basis[i]);\n        }\n        if (a > 0) {\n        \
    \    basis[rank] = a;\n            saved.eb(tmp);\n            rank++;\n     \
    \       return true;\n        } else {\n            return false;\n        }\n\
    \    }\n\n    // \u73FE\u5728\u306E\u57FA\u5E95\u3067a\u304C\u4F5C\u308C\u308B\
    \u304B\uFF1AO(W)\n    bool exists(T a) {\n        rep(i, rank) {\n           \
    \ chmin(a, a^basis[i]);\n        }\n        return !(a > 0);\n    }\n\n    //\
    \ 2\u3064\u306E\u57FA\u5E95\u3092\u30DE\u30FC\u30B8\uFF1AO(W^2)\n    XorBasis<T,\
    \ W> merge(const XorBasis<T, W>& a) {\n        if (rank == W or a.rank == 0) {\n\
    \            return *this;\n        }\n        if (a.rank == W or rank == 0) {\n\
    \            return a;\n        }\n        rep(i, a.rank) {\n            add(a.basis[i]);\n\
    \        }\n        return *this;\n    }\n\n    void clear() {\n        basis\
    \ = {};\n        rank = 0;\n    }\n};\n\n// XOR\u57FA\u5E95(vector\u7248)\n//\
    \ template<typename T>\n// struct XorBasis {\n//     vector<T> basis;\n\n//  \
    \   XorBasis() {}\n\n//     XorBasis(const vector<T>& A) : basis(A) {}\n\n// \
    \    // \u57FA\u5E95\u306Ba\u3092\u8FFD\u52A0\u3001\u57FA\u5E95\u304C\u66F4\u65B0\
    \u3055\u308C\u305F\u3089true\u3092\u8FD4\u3059\n//     bool add(T a) {\n//   \
    \      if (a == 0) return false;\n//         for (auto b : basis) {\n//      \
    \       chmin(a, a^b);\n//         }\n//         if (a > 0) {\n//            \
    \ basis.eb(a);\n//             return true;\n//         } else {\n//         \
    \    return false;\n//         }\n//     }\n\n//     // \u73FE\u5728\u306E\u57FA\
    \u5E95\u3067a\u304C\u4F5C\u308C\u308B\u304B\n//     bool exists(T a) {\n//   \
    \      for (auto b : basis) {\n//             chmin(a, a^b);\n//         }\n//\
    \         return !(a > 0);\n//     }\n\n//     int rank() {\n//         return\
    \ basis.size();\n//     }\n// };\n"
  code: "#include \"../macros.hpp\"\n#include \"../common/chmin.hpp\"\n\n// XOR\u57FA\
    \u5E95(array\u7248\uFF1A\u3053\u3063\u3061\u306E\u304C\u901F\u3044\u3002\u30E1\
    \u30E2\u30EA\u306F\u98DF\u3046\u3002)\ntemplate<typename T, size_t W>\nstruct\
    \ XorBasis {\n    array<T, W> basis = {};\n    vector<T> saved; // \u7DDA\u5F62\
    \u72EC\u7ACB\u306A\u5024\u3092\u4FDD\u6301(zone2021_f\u53C2\u7167)\n    int rank\
    \ = 0;\n\n    XorBasis() {}\n\n    XorBasis(const array<T, W>& A) : basis(A) {}\n\
    \n    // \u57FA\u5E95\u306Ba\u3092\u8FFD\u52A0\u3001\u57FA\u5E95\u304C\u66F4\u65B0\
    \u3055\u308C\u305F\u3089true\u3092\u8FD4\u3059\uFF1AO(W)\n    bool add(T a) {\n\
    \        if (a == 0) return false;\n        T tmp = a;\n        rep(i, rank) {\n\
    \            chmin(a, a^basis[i]);\n        }\n        if (a > 0) {\n        \
    \    basis[rank] = a;\n            saved.eb(tmp);\n            rank++;\n     \
    \       return true;\n        } else {\n            return false;\n        }\n\
    \    }\n\n    // \u73FE\u5728\u306E\u57FA\u5E95\u3067a\u304C\u4F5C\u308C\u308B\
    \u304B\uFF1AO(W)\n    bool exists(T a) {\n        rep(i, rank) {\n           \
    \ chmin(a, a^basis[i]);\n        }\n        return !(a > 0);\n    }\n\n    //\
    \ 2\u3064\u306E\u57FA\u5E95\u3092\u30DE\u30FC\u30B8\uFF1AO(W^2)\n    XorBasis<T,\
    \ W> merge(const XorBasis<T, W>& a) {\n        if (rank == W or a.rank == 0) {\n\
    \            return *this;\n        }\n        if (a.rank == W or rank == 0) {\n\
    \            return a;\n        }\n        rep(i, a.rank) {\n            add(a.basis[i]);\n\
    \        }\n        return *this;\n    }\n\n    void clear() {\n        basis\
    \ = {};\n        rank = 0;\n    }\n};\n\n// XOR\u57FA\u5E95(vector\u7248)\n//\
    \ template<typename T>\n// struct XorBasis {\n//     vector<T> basis;\n\n//  \
    \   XorBasis() {}\n\n//     XorBasis(const vector<T>& A) : basis(A) {}\n\n// \
    \    // \u57FA\u5E95\u306Ba\u3092\u8FFD\u52A0\u3001\u57FA\u5E95\u304C\u66F4\u65B0\
    \u3055\u308C\u305F\u3089true\u3092\u8FD4\u3059\n//     bool add(T a) {\n//   \
    \      if (a == 0) return false;\n//         for (auto b : basis) {\n//      \
    \       chmin(a, a^b);\n//         }\n//         if (a > 0) {\n//            \
    \ basis.eb(a);\n//             return true;\n//         } else {\n//         \
    \    return false;\n//         }\n//     }\n\n//     // \u73FE\u5728\u306E\u57FA\
    \u5E95\u3067a\u304C\u4F5C\u308C\u308B\u304B\n//     bool exists(T a) {\n//   \
    \      for (auto b : basis) {\n//             chmin(a, a^b);\n//         }\n//\
    \         return !(a > 0);\n//     }\n\n//     int rank() {\n//         return\
    \ basis.size();\n//     }\n// };\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/chmin.hpp
  isVerificationFile: false
  path: src/numbers/XorBasis.hpp
  requiredBy: []
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/XorBasis.hpp
layout: document
redirect_from:
- /library/src/numbers/XorBasis.hpp
- /library/src/numbers/XorBasis.hpp.html
title: src/numbers/XorBasis.hpp
---
