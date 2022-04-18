---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/numbers/gcd.hpp
    title: src/numbers/gcd.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/numbers/Fraction.hpp
    title: src/numbers/Fraction.hpp
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
    src/numbers/gcd.hpp\"\n\ntemplate<typename T>\nT gcd(T a, T b) { return __gcd(a,\
    \ b); }\n\ntemplate<typename T>\nT gcd(const vector<T> &A) {\n    T res = 0;\n\
    \    for (auto a : A) res = gcd(res, a);\n    return res;\n}\n#line 4 \"src/numbers/lcm.hpp\"\
    \n\n// \u9664\u7B97\u3092\u524D\u306B\u51FA\u3057\u3066\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3092\u9632\u3050\ntemplate<typename T>\nT lcm(T x, T y) {\
    \ return x/gcd(x, y)*y; }\n\ntemplate<typename T>\nT lcm(const vector<T> &A) {\n\
    \    T res = 1;\n    for (auto a : A) res = lcm(res, a);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"gcd.hpp\"\n\n// \u9664\
    \u7B97\u3092\u524D\u306B\u51FA\u3057\u3066\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3092\u9632\u3050\ntemplate<typename T>\nT lcm(T x, T y) { return x/gcd(x,\
    \ y)*y; }\n\ntemplate<typename T>\nT lcm(const vector<T> &A) {\n    T res = 1;\n\
    \    for (auto a : A) res = lcm(res, a);\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/numbers/gcd.hpp
  isVerificationFile: false
  path: src/numbers/lcm.hpp
  requiredBy:
  - src/template.hpp
  - src/numbers/Fraction.hpp
  timestamp: '2022-04-19 01:28:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/lcm.hpp
layout: document
redirect_from:
- /library/src/numbers/lcm.hpp
- /library/src/numbers/lcm.hpp.html
title: src/numbers/lcm.hpp
---
