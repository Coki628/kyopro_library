---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':x:'
    path: test/matrix/MatPow.test.cpp
    title: test/matrix/MatPow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/input.hpp\"\
    \n\n// pair\u5165\u529B\u4E00\u62EC\u53D7\u3051\u53D6\u308A\ntemplate<typename\
    \ T1, typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p) {\n    is\
    \ >> p.first >> p.second;\n    return is;\n}\n\n// vector\u5165\u529B\u4E00\u62EC\
    \u53D7\u3051\u53D6\u308A\ntemplate<typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n    for (T &in : v) is >> in;\n    return is;\n}\n\n// \u203B\
    \u6700\u8FD1\u306F\u3082\u3046\u305A\u3063\u3068vector\u306E\u53D7\u3051\u53D6\
    \u308A\u306Foperator>>\u306A\u306E\u3067\u3001\u3053\u308C\u306F\u3082\u3046\u8981\
    \u3089\u306A\u3044\u304B\u3082\u3002\n// template<typename T = ll>\n// vector<T>\
    \ LIST(ll N) {\n//     vector<T> A(N);\n//     rep(i, N) {\n//         cin >>\
    \ A[i];\n//     }\n//     return A;\n// }\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// pair\u5165\u529B\u4E00\u62EC\
    \u53D7\u3051\u53D6\u308A\ntemplate<typename T1, typename T2>\nistream &operator>>(istream\
    \ &is, pair<T1, T2> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\
    \n// vector\u5165\u529B\u4E00\u62EC\u53D7\u3051\u53D6\u308A\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v) {\n    for (T &in : v) is\
    \ >> in;\n    return is;\n}\n\n// \u203B\u6700\u8FD1\u306F\u3082\u3046\u305A\u3063\
    \u3068vector\u306E\u53D7\u3051\u53D6\u308A\u306Foperator>>\u306A\u306E\u3067\u3001\
    \u3053\u308C\u306F\u3082\u3046\u8981\u3089\u306A\u3044\u304B\u3082\u3002\n// template<typename\
    \ T = ll>\n// vector<T> LIST(ll N) {\n//     vector<T> A(N);\n//     rep(i, N)\
    \ {\n//         cin >> A[i];\n//     }\n//     return A;\n// }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/input.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/matrix/MatPow.test.cpp
documentation_of: src/common/input.hpp
layout: document
redirect_from:
- /library/src/common/input.hpp
- /library/src/common/input.hpp.html
title: src/common/input.hpp
---