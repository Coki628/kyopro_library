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
    - https://qiita.com/oyas/items/70b7e29d0388392ef2ce
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/fill.hpp\"\
    \n\n// \u751F\u914D\u5217\u7528\u306EINF\u57CB\u3081\u521D\u671F\u5316\n// \u30FB\
    \u52D5\u7684\u78BA\u4FDD\u3057\u305F(\u521D\u671F\u5316\u306E\u6DFB\u5B57\u304C\
    \u56FA\u5B9A\u5024\u3058\u3083\u306A\u3044)\u751F\u914D\u5217\u306B\u306F\u4F7F\
    \u3048\u306A\u3044\u3002\n// \u3000\u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\
    \u30B9\u306E\u5834\u5408\u306F\u3001\u30B0\u30ED\u30FC\u30D0\u30EB\u3067\u5927\
    \u304D\u304F\u53D6\u3063\u3066\u3001\u30B5\u30A4\u30BA\u6307\u5B9A\u3067\u5C0F\
    \u3055\u304F\u57CB\u3081\u308B\u3088\u3046\u306B\u4F7F\u3046\u3002\n\n// \u5168\
    \u57CB\u3081\n// see: https://qiita.com/oyas/items/70b7e29d0388392ef2ce\ntemplate<typename\
    \ A, size_t N, typename T>\nvoid fill(A (&arr)[N], const T &val) {\n    fill((T*)arr,\
    \ (T*)(arr + N), val);\n}\n// \u30B5\u30A4\u30BA\u6307\u5B9A(\u5FC5\u8981\u306A\
    \u6240\u307E\u3067\u57CB\u3081\u305F\u3044\u6642\u4F7F\u3046)\ntemplate<typename\
    \ A, typename T>\nvoid fill(A &arr, int n, const T &val) {\n    rep(i, n) arr[i]\
    \ = val;\n}\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2,\
    \ const T &val) {\n    rep(i1, n1) rep(i2, n2) arr[i1][i2] = val;\n}\ntemplate<typename\
    \ A, typename T>\nvoid fill(A &arr, int n1, int n2, int n3, const T &val) {\n\
    \    rep(i1, n1) rep(i2, n2) rep(i3, n3) arr[i1][i2][i3] = val;\n}\ntemplate<typename\
    \ A, typename T>\nvoid fill(A &arr, int n1, int n2, int n3, int n4, const T &val)\
    \ {\n    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) arr[i1][i2][i3][i4] =\
    \ val;\n}\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2,\
    \ int n3, int n4, int n5, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3,\
    \ n3) rep(i4, n4) rep(i5, n5) arr[i1][i2][i3][i4][i5] = val;\n}\ntemplate<typename\
    \ A, typename T>\nvoid fill(A &arr, int n1, int n2, int n3, int n4, int n5, int\
    \ n6, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5,\
    \ n5) rep(i6, n6) arr[i1][i2][i3][i4][i5][i6] = val;\n}\ntemplate<typename A,\
    \ typename T>\nvoid fill(A &arr, int n1, int n2, int n3, int n4, int n5, int n6,\
    \ int n7, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4)\
    \ rep(i5, n5) rep(i6, n6) rep(i7, n7) arr[i1][i2][i3][i4][i5][i6][i7] = val;\n\
    }\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2, int n3,\
    \ int n4, int n5, int n6, int n7, int n8, const T &val) {\n    rep(i1, n1) rep(i2,\
    \ n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) rep(i8, n8)\
    \ arr[i1][i2][i3][i4][i5][i6][i7][i8] = val;\n}\ntemplate<typename A, typename\
    \ T>\nvoid fill(A &arr, int n1, int n2, int n3, int n4, int n5, int n6, int n7,\
    \ int n8, int n9, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4,\
    \ n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) rep(i8, n8) rep(i9, n9) arr[i1][i2][i3][i4][i5][i6][i7][i8][i9]\
    \ = val;\n}\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2,\
    \ int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, const T &val)\
    \ {\n    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6)\
    \ rep(i7, n7) rep(i8, n8) rep(i9, n9) rep(i10, n10) arr[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10]\
    \ = val;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u751F\u914D\u5217\u7528\u306E\
    INF\u57CB\u3081\u521D\u671F\u5316\n// \u30FB\u52D5\u7684\u78BA\u4FDD\u3057\u305F\
    (\u521D\u671F\u5316\u306E\u6DFB\u5B57\u304C\u56FA\u5B9A\u5024\u3058\u3083\u306A\
    \u3044)\u751F\u914D\u5217\u306B\u306F\u4F7F\u3048\u306A\u3044\u3002\n// \u3000\
    \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u306E\u5834\u5408\u306F\
    \u3001\u30B0\u30ED\u30FC\u30D0\u30EB\u3067\u5927\u304D\u304F\u53D6\u3063\u3066\
    \u3001\u30B5\u30A4\u30BA\u6307\u5B9A\u3067\u5C0F\u3055\u304F\u57CB\u3081\u308B\
    \u3088\u3046\u306B\u4F7F\u3046\u3002\n\n// \u5168\u57CB\u3081\n// see: https://qiita.com/oyas/items/70b7e29d0388392ef2ce\n\
    template<typename A, size_t N, typename T>\nvoid fill(A (&arr)[N], const T &val)\
    \ {\n    fill((T*)arr, (T*)(arr + N), val);\n}\n// \u30B5\u30A4\u30BA\u6307\u5B9A\
    (\u5FC5\u8981\u306A\u6240\u307E\u3067\u57CB\u3081\u305F\u3044\u6642\u4F7F\u3046\
    )\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n, const T &val) {\n\
    \    rep(i, n) arr[i] = val;\n}\ntemplate<typename A, typename T>\nvoid fill(A\
    \ &arr, int n1, int n2, const T &val) {\n    rep(i1, n1) rep(i2, n2) arr[i1][i2]\
    \ = val;\n}\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2,\
    \ int n3, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3, n3) arr[i1][i2][i3]\
    \ = val;\n}\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2,\
    \ int n3, int n4, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4,\
    \ n4) arr[i1][i2][i3][i4] = val;\n}\ntemplate<typename A, typename T>\nvoid fill(A\
    \ &arr, int n1, int n2, int n3, int n4, int n5, const T &val) {\n    rep(i1, n1)\
    \ rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) arr[i1][i2][i3][i4][i5] = val;\n\
    }\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2, int n3,\
    \ int n4, int n5, int n6, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3,\
    \ n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) arr[i1][i2][i3][i4][i5][i6] = val;\n\
    }\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2, int n3,\
    \ int n4, int n5, int n6, int n7, const T &val) {\n    rep(i1, n1) rep(i2, n2)\
    \ rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) arr[i1][i2][i3][i4][i5][i6][i7]\
    \ = val;\n}\ntemplate<typename A, typename T>\nvoid fill(A &arr, int n1, int n2,\
    \ int n3, int n4, int n5, int n6, int n7, int n8, const T &val) {\n    rep(i1,\
    \ n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7)\
    \ rep(i8, n8) arr[i1][i2][i3][i4][i5][i6][i7][i8] = val;\n}\ntemplate<typename\
    \ A, typename T>\nvoid fill(A &arr, int n1, int n2, int n3, int n4, int n5, int\
    \ n6, int n7, int n8, int n9, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3,\
    \ n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) rep(i8, n8) rep(i9, n9)\
    \ arr[i1][i2][i3][i4][i5][i6][i7][i8][i9] = val;\n}\ntemplate<typename A, typename\
    \ T>\nvoid fill(A &arr, int n1, int n2, int n3, int n4, int n5, int n6, int n7,\
    \ int n8, int n9, int n10, const T &val) {\n    rep(i1, n1) rep(i2, n2) rep(i3,\
    \ n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) rep(i8, n8) rep(i9, n9)\
    \ rep(i10, n10) arr[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] = val;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/fill.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/fill.hpp
layout: document
redirect_from:
- /library/src/common/fill.hpp
- /library/src/common/fill.hpp.html
title: src/common/fill.hpp
---
