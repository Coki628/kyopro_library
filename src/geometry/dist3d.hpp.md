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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/geometry/dist3d.hpp\"\
    \n\n// 3\u6B21\u5143\u3067\u306E2\u70B9\u9593\u8DDD\u96E2\u221A((x1-x2)^2+(y1-y2)^2+(z1-z2)^2)\n\
    ld dist3d(tuple<ld, ld, ld> a, tuple<ld, ld, ld> b) {\n    return sqrt(\n    \
    \    (get<0>(a)-get<0>(b))*(get<0>(a)-get<0>(b)) +\n        (get<1>(a)-get<1>(b))*(get<1>(a)-get<1>(b))\
    \ +\n        (get<2>(a)-get<2>(b))*(get<2>(a)-get<2>(b))\n    );\n}\n"
  code: "#include \"../macros.hpp\"\n\n// 3\u6B21\u5143\u3067\u306E2\u70B9\u9593\u8DDD\
    \u96E2\u221A((x1-x2)^2+(y1-y2)^2+(z1-z2)^2)\nld dist3d(tuple<ld, ld, ld> a, tuple<ld,\
    \ ld, ld> b) {\n    return sqrt(\n        (get<0>(a)-get<0>(b))*(get<0>(a)-get<0>(b))\
    \ +\n        (get<1>(a)-get<1>(b))*(get<1>(a)-get<1>(b)) +\n        (get<2>(a)-get<2>(b))*(get<2>(a)-get<2>(b))\n\
    \    );\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/geometry/dist3d.hpp
  requiredBy: []
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/dist3d.hpp
layout: document
redirect_from:
- /library/src/geometry/dist3d.hpp
- /library/src/geometry/dist3d.hpp.html
title: src/geometry/dist3d.hpp
---
