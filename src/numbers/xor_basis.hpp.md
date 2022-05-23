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
    src/common/chmin.hpp\"\n\ntemplate<typename T>\nbool chmin(T &x, T y) {\n    return\
    \ (y < x) ? x = y, true : false;\n}\n#line 3 \"src/numbers/xor_basis.hpp\"\n\n\
    // XOR\u57FA\u5E95(\u30AF\u30E9\u30B9\u7248\u4F5C\u3063\u305F\u3051\u3069\u3001\
    \u4F55\u56DE\u304B\u4F7F\u3046\u307E\u3067\u4E00\u5FDC\u3053\u3063\u3061\u3082\
    \u53D6\u3063\u3066\u304A\u304F)\ntemplate<typename T>\nvector<T> get_xor_basis(const\
    \ vector<T> &A) {\n    vector<T> basis;\n    for (auto a : A) {\n        for (auto\
    \ b : basis) {\n            chmin(a, a^b);\n        }\n        if (a > 0) basis.eb(a);\n\
    \    }\n    return basis;\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"../common/chmin.hpp\"\n\n// XOR\u57FA\
    \u5E95(\u30AF\u30E9\u30B9\u7248\u4F5C\u3063\u305F\u3051\u3069\u3001\u4F55\u56DE\
    \u304B\u4F7F\u3046\u307E\u3067\u4E00\u5FDC\u3053\u3063\u3061\u3082\u53D6\u3063\
    \u3066\u304A\u304F)\ntemplate<typename T>\nvector<T> get_xor_basis(const vector<T>\
    \ &A) {\n    vector<T> basis;\n    for (auto a : A) {\n        for (auto b : basis)\
    \ {\n            chmin(a, a^b);\n        }\n        if (a > 0) basis.eb(a);\n\
    \    }\n    return basis;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/chmin.hpp
  isVerificationFile: false
  path: src/numbers/xor_basis.hpp
  requiredBy: []
  timestamp: '2022-04-19 01:28:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/xor_basis.hpp
layout: document
redirect_from:
- /library/src/numbers/xor_basis.hpp
- /library/src/numbers/xor_basis.hpp.html
title: src/numbers/xor_basis.hpp
---
