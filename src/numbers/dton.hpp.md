---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/modulo.hpp
    title: src/common/modulo.hpp
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
  bundledCode: "#line 2 \"src/common/modulo.hpp\"\n\ntemplate<typename T>\nT modulo(T\
    \ a, T b) {\n    return ((a % b) + b) % b;\n}\n#line 2 \"src/base.hpp\"\n#define\
    \ _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing namespace std;\n#line 3 \"\
    src/macros.hpp\"\n\nusing ll = long long;\nusing ull = unsigned long long;\nusing\
    \ ld = long double;\nusing pll = pair<ll, ll>;\nusing pii = pair<int, int>;\n\
    using pli = pair<ll, int>;\nusing pil = pair<int, ll>;\ntemplate<typename T>\n\
    using vv = vector<vector<T>>;\nusing vvl = vv<ll>;\nusing vvi = vv<int>;\nusing\
    \ vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil = vv<pil>;\n#define name4(i,\
    \ a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4, rep3, rep2,\
    \ rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i < _aa; i++)\n\
    #define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define rep3(i, a,\
    \ b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c < 0 && a >=\
    \ i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define\
    \ pb push_back\n#define eb emplace_back\n#define mkp make_pair\n#define ALL(A)\
    \ begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)), A.end())\n\
    #define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n    constexpr\
    \ ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr ld EPS =\
    \ 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/numbers/dton.hpp\"\
    \n\n// 10\u9032\u6CD5\u3092N\u9032\u6CD5\u6587\u5B57\u5217\u306B(\u8CA0\u6570\
    n\u5BFE\u5FDC\u7248)\nstring dton(ll num, ll n, char base = '0') {\n    string\
    \ res;\n    while (abs(num) > 0) {\n        ll m = modulo(num, abs(n));\n    \
    \    num -= m;\n        ll nxt = base + m;\n        // \u82F1\u6570\u5B57\u3067\
    \u8868\u73FE\u3067\u304D\u306A\u3044\u5024\u306B\u306A\u3063\u305F\u3089\u4E0D\
    \u6B63\u3068\u3059\u308B\n        if (nxt >= UCHAR_MAX or not isalnum(nxt)) {\n\
    \            return \"\";\n        }\n        res += nxt;\n        num /= n;\n\
    \    }\n    reverse(ALL(res));\n    if (res != \"\") {\n        return res;\n\
    \    } else {\n        return {base};\n    }\n}\n\n// \u65E7\u7248\n// string\
    \ dton(ll num, ll n) {\n//     string res;\n//     ll m;\n//     while (num >\
    \ 0) {\n//         tie(num, m) = divmod(num, n);\n//         res += tochar(m);\n\
    //     }\n//     reverse(ALL(res));\n//     if (res != \"\") {\n//         return\
    \ res;\n//     } else {\n//         return \"0\";\n//     }\n// }\n"
  code: "#pragma once\n#include \"../common/modulo.hpp\"\n#include \"../macros.hpp\"\
    \n\n// 10\u9032\u6CD5\u3092N\u9032\u6CD5\u6587\u5B57\u5217\u306B(\u8CA0\u6570\
    n\u5BFE\u5FDC\u7248)\nstring dton(ll num, ll n, char base = '0') {\n    string\
    \ res;\n    while (abs(num) > 0) {\n        ll m = modulo(num, abs(n));\n    \
    \    num -= m;\n        ll nxt = base + m;\n        // \u82F1\u6570\u5B57\u3067\
    \u8868\u73FE\u3067\u304D\u306A\u3044\u5024\u306B\u306A\u3063\u305F\u3089\u4E0D\
    \u6B63\u3068\u3059\u308B\n        if (nxt >= UCHAR_MAX or not isalnum(nxt)) {\n\
    \            return \"\";\n        }\n        res += nxt;\n        num /= n;\n\
    \    }\n    reverse(ALL(res));\n    if (res != \"\") {\n        return res;\n\
    \    } else {\n        return {base};\n    }\n}\n\n// \u65E7\u7248\n// string\
    \ dton(ll num, ll n) {\n//     string res;\n//     ll m;\n//     while (num >\
    \ 0) {\n//         tie(num, m) = divmod(num, n);\n//         res += tochar(m);\n\
    //     }\n//     reverse(ALL(res));\n//     if (res != \"\") {\n//         return\
    \ res;\n//     } else {\n//         return \"0\";\n//     }\n// }\n"
  dependsOn:
  - src/common/modulo.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/dton.hpp
  requiredBy: []
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/dton.hpp
layout: document
redirect_from:
- /library/src/numbers/dton.hpp
- /library/src/numbers/dton.hpp.html
title: src/numbers/dton.hpp
---