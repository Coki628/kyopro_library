---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/bisect.hpp
    title: src/common/bisect.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/bisect.hpp\"\
    \n\ntemplate<typename T>\nint bisect_left(const vector<T> &A, T val, int lo =\
    \ 0) {\n    return lower_bound(A.begin() + lo, A.end(), val) - A.begin();\n}\n\
    \ntemplate<typename T>\nint bisect_right(const vector<T> &A, T val, int lo = 0)\
    \ {\n    return upper_bound(A.begin() + lo, A.end(), val) - A.begin();\n}\n#line\
    \ 4 \"src/common/LIS.hpp\"\n\n// \u6700\u5C0F\u5897\u52A0\u90E8\u5206\u5217\n\
    template<typename T>\nvector<T> LIS(const vector<T> &A, bool equal = false) {\n\
    \n    auto compare = (not equal) ? [](T a, T b) { return a > b; }\n          \
    \                     : [](T a, T b) { return a >= b; };\n    auto bisect = (not\
    \ equal) ? bisect_left<T> : bisect_right<T>;\n    vector<T> res;\n    if (A.empty())\
    \ {\n        return res;\n    }\n    res.pb(A[0]);\n    int n = A.size();\n  \
    \  rep(i, 1, n) {\n        if (compare(A[i], res.back())) {\n            res.pb(A[i]);\n\
    \        } else {\n            res[bisect(res, A[i], 0)] = A[i];\n        }\n\
    \    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"bisect.hpp\"\n\n// \u6700\
    \u5C0F\u5897\u52A0\u90E8\u5206\u5217\ntemplate<typename T>\nvector<T> LIS(const\
    \ vector<T> &A, bool equal = false) {\n\n    auto compare = (not equal) ? [](T\
    \ a, T b) { return a > b; }\n                               : [](T a, T b) { return\
    \ a >= b; };\n    auto bisect = (not equal) ? bisect_left<T> : bisect_right<T>;\n\
    \    vector<T> res;\n    if (A.empty()) {\n        return res;\n    }\n    res.pb(A[0]);\n\
    \    int n = A.size();\n    rep(i, 1, n) {\n        if (compare(A[i], res.back()))\
    \ {\n            res.pb(A[i]);\n        } else {\n            res[bisect(res,\
    \ A[i], 0)] = A[i];\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/bisect.hpp
  isVerificationFile: false
  path: src/common/LIS.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/LIS.hpp
layout: document
redirect_from:
- /library/src/common/LIS.hpp
- /library/src/common/LIS.hpp.html
title: src/common/LIS.hpp
---
