---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/input.hpp\"\
    \n\n// pair\u5165\u529B\u4E00\u62EC\u53D7\u3051\u53D6\u308A\ntemplate<typename\
    \ T1, typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p) {\n    is\
    \ >> p.first >> p.second;\n    return is;\n}\n\n// vector\u5165\u529B\u4E00\u62EC\
    \u53D7\u3051\u53D6\u308A\ntemplate<typename T>\nistream &operator>>(istream &is,\
    \ vector<T> &v) {\n    for (T &in : v) is >> in;\n    return is;\n}\n\n// \u5F8C\
    \u65B9\u4E92\u63DB\u3002\u6700\u8FD1\u4F7F\u3063\u3066\u306A\u3044\u3051\u3069\
    \u4F7F\u7528\u7B87\u6240\u304C\u3042\u307E\u308A\u306B\u591A\u3044\u306E\u3067\
    \u6B8B\u3057\u3066\u304A\u304F\u3002\ntemplate<typename T = ll>\nvector<T> LIST(int\
    \ N) {\n    vector<T> A(N);\n    rep(i, N) {\n        cin >> A[i];\n    }\n  \
    \  return A;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// pair\u5165\u529B\u4E00\u62EC\
    \u53D7\u3051\u53D6\u308A\ntemplate<typename T1, typename T2>\nistream &operator>>(istream\
    \ &is, pair<T1, T2> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\
    \n// vector\u5165\u529B\u4E00\u62EC\u53D7\u3051\u53D6\u308A\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v) {\n    for (T &in : v) is\
    \ >> in;\n    return is;\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\u3002\u6700\u8FD1\u4F7F\
    \u3063\u3066\u306A\u3044\u3051\u3069\u4F7F\u7528\u7B87\u6240\u304C\u3042\u307E\
    \u308A\u306B\u591A\u3044\u306E\u3067\u6B8B\u3057\u3066\u304A\u304F\u3002\ntemplate<typename\
    \ T = ll>\nvector<T> LIST(int N) {\n    vector<T> A(N);\n    rep(i, N) {\n   \
    \     cin >> A[i];\n    }\n    return A;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/input.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2023-12-12 16:05:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
