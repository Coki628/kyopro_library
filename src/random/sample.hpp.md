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
    path: src/random/mt.hpp
    title: src/random/mt.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/random/mt.hpp\"\
    \n\n// \u30B7\u30FC\u30C9\u751F\u6210\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    #line 4 \"src/random/sample.hpp\"\n\n// \u914D\u5217vec\u304B\u3089\u30E9\u30F3\
    \u30C0\u30E0\u306Bn\u500B\u306E\u8981\u7D20\u3092\u9078\u629E\u3057\u3066\u8FD4\
    \u3059\n// (std\u306B\u3042\u3063\u305F\u3051\u3069\u3001python\u98A8\u306E\u30E9\
    \u30C3\u30D1\u30FC\u4F5C\u3063\u3068\u304F)\ntemplate<typename T>\nvector<T> sample(vector<T>\
    \ vec, int n) {\n    vector<T> res;\n    std::sample(ALL(vec), back_inserter(res),\
    \ n, mt);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"mt.hpp\"\n\n// \u914D\
    \u5217vec\u304B\u3089\u30E9\u30F3\u30C0\u30E0\u306Bn\u500B\u306E\u8981\u7D20\u3092\
    \u9078\u629E\u3057\u3066\u8FD4\u3059\n// (std\u306B\u3042\u3063\u305F\u3051\u3069\
    \u3001python\u98A8\u306E\u30E9\u30C3\u30D1\u30FC\u4F5C\u3063\u3068\u304F)\ntemplate<typename\
    \ T>\nvector<T> sample(vector<T> vec, int n) {\n    vector<T> res;\n    std::sample(ALL(vec),\
    \ back_inserter(res), n, mt);\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/random/mt.hpp
  isVerificationFile: false
  path: src/random/sample.hpp
  requiredBy: []
  timestamp: '2024-02-06 11:56:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/random/sample.hpp
layout: document
redirect_from:
- /library/src/random/sample.hpp
- /library/src/random/sample.hpp.html
title: src/random/sample.hpp
---
