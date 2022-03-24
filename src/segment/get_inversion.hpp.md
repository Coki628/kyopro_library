---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
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
    src/segment/get_inversion.hpp\"\n\n// \u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u306B\
    \u3088\u308B\u8EE2\u5012\u6570\u53D6\u5F97\n// \u30FB\u5EA7\u5727BIT\u3088\u308A\
    \u901F\u3044\u3051\u3069\u3001\u53C2\u7167\u6E21\u3057\u3084\u3081\u308B\u3068\
    \u30D0\u30B0\u308B\u306E\u3067\u3001\n// \u3000\u5143\u306E\u5217\u3082\u307E\u3060\
    \u4F7F\u3046\u5834\u5408\u306F\u30B3\u30D4\u30FC\u3057\u3066\u304B\u3089\u3084\
    \u308B\u3053\u3068\u3002\n// \u30FB\u5EA7\u5727\u3092\u4E8C\u5206\u63A2\u7D22\u30D9\
    \u30FC\u30B9\u306B\u3057\u3066\u304B\u3089\u307E\u3060\u901F\u5EA6\u6BD4\u8F03\
    \u3057\u3066\u306A\u3044\u306E\u3067\u3001\n// \u3000\u3082\u3057\u304B\u3057\u305F\
    \u3089\u305D\u3063\u3061\u306E\u5EA7\u5727\u7248\u3060\u3063\u305F\u3089\u5927\
    \u5DEE\u306A\u3044\u304B\u3082\u3002\n\n// \u8EE2\u5012\u6570\u53D6\u5F97\nll\
    \ get_inversion(vector<ll> &a) {\n    int n = a.size();\n    if (n <= 1) { return\
    \ 0; }\n\n    ll cnt = 0;\n    vector<ll> b(a.begin(), a.begin()+n/2);\n    vector<ll>\
    \ c(a.begin()+n/2, a.end());\n\n    cnt += get_inversion(b);\n    cnt += get_inversion(c);\n\
    \n    int ai = 0, bi = 0, ci = 0;\n    // merge\u306E\u51E6\u7406\n    while (ai\
    \ < n) {\n        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {\n\
    \            a[ai++] = b[bi++];\n        } else {\n            cnt += n / 2 -\
    \ bi;\n            a[ai++] = c[ci++];\n        }\n    }\n    return cnt;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u306B\
    \u3088\u308B\u8EE2\u5012\u6570\u53D6\u5F97\n// \u30FB\u5EA7\u5727BIT\u3088\u308A\
    \u901F\u3044\u3051\u3069\u3001\u53C2\u7167\u6E21\u3057\u3084\u3081\u308B\u3068\
    \u30D0\u30B0\u308B\u306E\u3067\u3001\n// \u3000\u5143\u306E\u5217\u3082\u307E\u3060\
    \u4F7F\u3046\u5834\u5408\u306F\u30B3\u30D4\u30FC\u3057\u3066\u304B\u3089\u3084\
    \u308B\u3053\u3068\u3002\n// \u30FB\u5EA7\u5727\u3092\u4E8C\u5206\u63A2\u7D22\u30D9\
    \u30FC\u30B9\u306B\u3057\u3066\u304B\u3089\u307E\u3060\u901F\u5EA6\u6BD4\u8F03\
    \u3057\u3066\u306A\u3044\u306E\u3067\u3001\n// \u3000\u3082\u3057\u304B\u3057\u305F\
    \u3089\u305D\u3063\u3061\u306E\u5EA7\u5727\u7248\u3060\u3063\u305F\u3089\u5927\
    \u5DEE\u306A\u3044\u304B\u3082\u3002\n\n// \u8EE2\u5012\u6570\u53D6\u5F97\nll\
    \ get_inversion(vector<ll> &a) {\n    int n = a.size();\n    if (n <= 1) { return\
    \ 0; }\n\n    ll cnt = 0;\n    vector<ll> b(a.begin(), a.begin()+n/2);\n    vector<ll>\
    \ c(a.begin()+n/2, a.end());\n\n    cnt += get_inversion(b);\n    cnt += get_inversion(c);\n\
    \n    int ai = 0, bi = 0, ci = 0;\n    // merge\u306E\u51E6\u7406\n    while (ai\
    \ < n) {\n        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {\n\
    \            a[ai++] = b[bi++];\n        } else {\n            cnt += n / 2 -\
    \ bi;\n            a[ai++] = c[ci++];\n        }\n    }\n    return cnt;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/segment/get_inversion.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/segment/get_inversion.hpp
layout: document
redirect_from:
- /library/src/segment/get_inversion.hpp
- /library/src/segment/get_inversion.hpp.html
title: src/segment/get_inversion.hpp
---
