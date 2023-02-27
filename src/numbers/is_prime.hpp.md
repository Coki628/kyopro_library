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
    \ = vector<vector<pil>>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\n\
    #define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i\
    \ < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define\
    \ rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c\
    \ < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b);\
    \ i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/numbers/is_prime.hpp\"\
    \n\n// \u7D20\u6570\u5224\u5B9A\uFF1AO(\u221Anum)\nbool is_prime(ll num) {\n \
    \   if (num < 2) {\n        return false;\n    }\n    if (num == 2 or num == 3\
    \ or num == 5) {\n        return true;\n    }\n    if (num%2 == 0 or num%3 ==\
    \ 0 or num%5 == 0) {\n        return false;\n    }\n    // \u7591\u4F3C\u7D20\u6570\
    (2\u3067\u30823\u3067\u3082\u5272\u308A\u5207\u308C\u306A\u3044\u6570\u5B57)\u3067\
    \u6B21\u3005\u306B\u5272\u3063\u3066\u3044\u304F\n    int p = 7;\n    int step\
    \ = 4;\n    int num_sqrt = sqrt(num);\n    while (p <= num_sqrt) {\n        if\
    \ (num%p == 0) {\n            return false;\n        }\n        p += step;\n \
    \       step = 6-step;\n    }\n    return true;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u7D20\u6570\u5224\u5B9A\uFF1AO(\u221Anum)\n\
    bool is_prime(ll num) {\n    if (num < 2) {\n        return false;\n    }\n  \
    \  if (num == 2 or num == 3 or num == 5) {\n        return true;\n    }\n    if\
    \ (num%2 == 0 or num%3 == 0 or num%5 == 0) {\n        return false;\n    }\n \
    \   // \u7591\u4F3C\u7D20\u6570(2\u3067\u30823\u3067\u3082\u5272\u308A\u5207\u308C\
    \u306A\u3044\u6570\u5B57)\u3067\u6B21\u3005\u306B\u5272\u3063\u3066\u3044\u304F\
    \n    int p = 7;\n    int step = 4;\n    int num_sqrt = sqrt(num);\n    while\
    \ (p <= num_sqrt) {\n        if (num%p == 0) {\n            return false;\n  \
    \      }\n        p += step;\n        step = 6-step;\n    }\n    return true;\n\
    }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/is_prime.hpp
  requiredBy: []
  timestamp: '2023-02-28 01:25:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/is_prime.hpp
layout: document
redirect_from:
- /library/src/numbers/is_prime.hpp
- /library/src/numbers/is_prime.hpp.html
title: src/numbers/is_prime.hpp
---
