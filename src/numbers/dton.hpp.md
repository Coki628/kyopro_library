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
    src/numbers/dton.hpp\"\n\n// 10\u9032\u6570\u3092N\u9032\u6570\u6587\u5B57\u5217\
    \u306B(\u8CA0\u6570\u5BFE\u5FDC\u7248)\nstring dton(ll num, ll n, char base='0')\
    \ {\n    string res;\n    while (abs(num) > 0) {\n        ll m = num % abs(n);\n\
    \        num -= m;\n        res += base+m;\n        num /= n;\n    }\n    reverse(ALL(res));\n\
    \    if (res != \"\") {\n        return res;\n    } else {\n        return res+base;\n\
    \    }\n}\n\n// \u65E7\u7248\n// string dton(ll num, ll n) {\n//     string res;\n\
    //     ll m;\n//     while (num > 0) {\n//         tie(num, m) = divmod(num, n);\n\
    //         res += tochar(m);\n//     }\n//     reverse(ALL(res));\n//     if (res\
    \ != \"\") {\n//         return res;\n//     } else {\n//         return \"0\"\
    ;\n//     }\n// }\n"
  code: "#include \"../macros.hpp\"\n\n// 10\u9032\u6570\u3092N\u9032\u6570\u6587\u5B57\
    \u5217\u306B(\u8CA0\u6570\u5BFE\u5FDC\u7248)\nstring dton(ll num, ll n, char base='0')\
    \ {\n    string res;\n    while (abs(num) > 0) {\n        ll m = num % abs(n);\n\
    \        num -= m;\n        res += base+m;\n        num /= n;\n    }\n    reverse(ALL(res));\n\
    \    if (res != \"\") {\n        return res;\n    } else {\n        return res+base;\n\
    \    }\n}\n\n// \u65E7\u7248\n// string dton(ll num, ll n) {\n//     string res;\n\
    //     ll m;\n//     while (num > 0) {\n//         tie(num, m) = divmod(num, n);\n\
    //         res += tochar(m);\n//     }\n//     reverse(ALL(res));\n//     if (res\
    \ != \"\") {\n//         return res;\n//     } else {\n//         return \"0\"\
    ;\n//     }\n// }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/dton.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/dton.hpp
layout: document
redirect_from:
- /library/src/numbers/dton.hpp
- /library/src/numbers/dton.hpp.html
title: src/numbers/dton.hpp
---