---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/numbers/isqrt.hpp\"\
    \n\n// \u6574\u6570\u3067\u6B63\u78BA\u306Bsqrt\u3092\u8FD4\u3059\nll isqrt(ll\
    \ n, bool ceil=false) {\n    ll ok = 0;\n    ll ng = 3037000500;\n    while (ng\
    \ - ok > 1) {\n        ll m = ok + (ng - ok) / 2;\n        if (m * m <= n) {\n\
    \            ok = m;\n        } else {\n            ng = m;\n        }\n    }\n\
    \    if (ceil and ok*ok != n) ok++;\n    return ok;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u6574\u6570\u3067\u6B63\u78BA\u306Bsqrt\u3092\
    \u8FD4\u3059\nll isqrt(ll n, bool ceil=false) {\n    ll ok = 0;\n    ll ng = 3037000500;\n\
    \    while (ng - ok > 1) {\n        ll m = ok + (ng - ok) / 2;\n        if (m\
    \ * m <= n) {\n            ok = m;\n        } else {\n            ng = m;\n  \
    \      }\n    }\n    if (ceil and ok*ok != n) ok++;\n    return ok;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/isqrt.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/isqrt.hpp
layout: document
redirect_from:
- /library/src/numbers/isqrt.hpp
- /library/src/numbers/isqrt.hpp.html
title: src/numbers/isqrt.hpp
---