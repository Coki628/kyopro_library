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
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"\
    src/geometry/get_a_and_b.hpp\"\n\n// 2\u70B9\u3092\u901A\u308B\u76F4\u7DDA\u306E\
    \u5F0F\u306E\u4FC2\u6570a,b\ntemplate<typename T>\npair<T, T> get_a_and_b(Point<T>\
    \ p1, Point<T> p2) {\n    // x\u5EA7\u6A19\u304C\u540C\u3058\u3060\u30680\u9664\
    \u7B97\n    assert(p2.x-p1.x != 0);\n    T a = (p2.y-p1.y) / (p2.x-p1.x);\n  \
    \  T b = (p1.x*p2.y-p2.x*p1.y) / (p1.x-p2.x);\n    return {a, b};\n}\n"
  code: "#include \"../macros.hpp\"\n\n// 2\u70B9\u3092\u901A\u308B\u76F4\u7DDA\u306E\
    \u5F0F\u306E\u4FC2\u6570a,b\ntemplate<typename T>\npair<T, T> get_a_and_b(Point<T>\
    \ p1, Point<T> p2) {\n    // x\u5EA7\u6A19\u304C\u540C\u3058\u3060\u30680\u9664\
    \u7B97\n    assert(p2.x-p1.x != 0);\n    T a = (p2.y-p1.y) / (p2.x-p1.x);\n  \
    \  T b = (p1.x*p2.y-p2.x*p1.y) / (p1.x-p2.x);\n    return {a, b};\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/geometry/get_a_and_b.hpp
  requiredBy: []
  timestamp: '2022-04-19 01:28:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/get_a_and_b.hpp
layout: document
redirect_from:
- /library/src/geometry/get_a_and_b.hpp
- /library/src/geometry/get_a_and_b.hpp.html
title: src/geometry/get_a_and_b.hpp
---