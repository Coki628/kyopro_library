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
    path: src/string/zfill.hpp
    title: src/string/zfill.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/string/zfill.hpp\"\
    \n\nstring zfill(string str, int len) {\n    string zeros;\n    int n = str.size();\n\
    \    rep(i, len - n) zeros += '0';\n    return zeros + str;\n}\n#line 4 \"src/string/compare.hpp\"\
    \n\n// \u6587\u5B57\u5217\u3092\u6570\u5024\u3068\u3057\u3066\u5927\u5C0F\u6BD4\
    \u8F03\u3059\u308B\nbool compare(const string &a, const string &b) {\n    if (a\
    \ == \"*\") return true;\n    int n = max(a.size(), b.size());\n    return zfill(a,\
    \ n) < zfill(b, n);\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"zfill.hpp\"\n\n// \u6587\
    \u5B57\u5217\u3092\u6570\u5024\u3068\u3057\u3066\u5927\u5C0F\u6BD4\u8F03\u3059\
    \u308B\nbool compare(const string &a, const string &b) {\n    if (a == \"*\")\
    \ return true;\n    int n = max(a.size(), b.size());\n    return zfill(a, n) <\
    \ zfill(b, n);\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/string/zfill.hpp
  isVerificationFile: false
  path: src/string/compare.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/compare.hpp
layout: document
redirect_from:
- /library/src/string/compare.hpp
- /library/src/string/compare.hpp.html
title: src/string/compare.hpp
---
