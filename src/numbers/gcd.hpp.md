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
    path: src/numbers/Fraction.hpp
    title: src/numbers/Fraction.hpp
  - icon: ':warning:'
    path: src/numbers/lcm.hpp
    title: src/numbers/lcm.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
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
    src/numbers/gcd.hpp\"\n\n// \u975E\u518D\u5E30\u7248\u4F5C\u3063\u3066\u307F\u305F\
    \u3051\u3069\u3001\u901F\u5EA6\u3042\u3093\u307E\u5909\u308F\u3089\u306A\u305D\
    \u3046\u2026\u3002\ntemplate<typename T>\nT gcd(T a, T b) {\n    while (b) {\n\
    \        T t = a % b;\n        a = b;\n        b = t;\n    }\n    return a;\n\
    }\n\n// template<typename T>\n// T gcd(T a, T b) { return __gcd(a, b); }\n\ntemplate<typename\
    \ T>\nT gcd(const vector<T> &A) {\n    T res = 0;\n    for (auto a : A) res =\
    \ gcd(res, a);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u975E\u518D\u5E30\u7248\u4F5C\
    \u3063\u3066\u307F\u305F\u3051\u3069\u3001\u901F\u5EA6\u3042\u3093\u307E\u5909\
    \u308F\u3089\u306A\u305D\u3046\u2026\u3002\ntemplate<typename T>\nT gcd(T a, T\
    \ b) {\n    while (b) {\n        T t = a % b;\n        a = b;\n        b = t;\n\
    \    }\n    return a;\n}\n\n// template<typename T>\n// T gcd(T a, T b) { return\
    \ __gcd(a, b); }\n\ntemplate<typename T>\nT gcd(const vector<T> &A) {\n    T res\
    \ = 0;\n    for (auto a : A) res = gcd(res, a);\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/gcd.hpp
  requiredBy:
  - src/numbers/lcm.hpp
  - src/numbers/Fraction.hpp
  - src/template.hpp
  timestamp: '2022-06-28 16:28:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/gcd.hpp
layout: document
redirect_from:
- /library/src/numbers/gcd.hpp
- /library/src/numbers/gcd.hpp.html
title: src/numbers/gcd.hpp
---
