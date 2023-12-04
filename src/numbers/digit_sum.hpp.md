---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/toint.hpp
    title: src/common/toint.hpp
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
    using namespace std;\n#line 3 \"src/common/toint.hpp\"\n\nll toint(string s) {\n\
    \    assert(s.size() < 20);\n    ll res = 0;\n    for (char &c : s) {\n      \
    \  res *= 10;\n        res += c - '0';\n    }\n    return res;\n}\n\nint toint(char\
    \ num) {\n    return num - '0';\n}\n#line 3 \"src/macros.hpp\"\n\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\nusing ld = long double;\nusing pll =\
    \ pair<ll, ll>;\nusing pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing\
    \ pil = pair<int, ll>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\n\
    using vvl = vv<ll>;\nusing vvi = vv<int>;\nusing vvpll = vv<pll>;\nusing vvpli\
    \ = vv<pli>;\nusing vvpil = vv<pil>;\n#define name4(i, a, b, c, d, e, ...) e\n\
    #define rep(...) name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ rep1(i, a) for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for\
    \ (ll i = a, _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb\
    \ = b; (c > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n\
    #define rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define\
    \ eb emplace_back\n#define mkp make_pair\n#define ALL(A) begin(A), end(A)\n#define\
    \ UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)), A.end())\n#define elif else\
    \ if\n#define tostr to_string\n\n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n\
    \    constexpr int MOD = 1000000007;\n    constexpr ld EPS = 1e-10;\n    constexpr\
    \ ld PI = M_PI;\n#endif\n#line 4 \"src/numbers/digit_sum.hpp\"\n\n// \u6841\u548C\
    \uFF1AO(logN)\nll digit_sum(ll n) {\n    ll res = 0;\n    while (n > 0) {\n  \
    \      res += n % 10;\n        n /= 10;\n    }\n    return res;\n}\n\n// \u6841\
    \u548C\uFF1AO(|S|)(\u672Averify)\nll digit_sum(string S) {\n    ll res = 0;\n\
    \    rep(i, S.size()) {\n        res += toint(S[i]);\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n#include \"../common/toint.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u6841\u548C\uFF1AO(logN)\nll digit_sum(ll n) {\n    ll res = 0;\n    while\
    \ (n > 0) {\n        res += n % 10;\n        n /= 10;\n    }\n    return res;\n\
    }\n\n// \u6841\u548C\uFF1AO(|S|)(\u672Averify)\nll digit_sum(string S) {\n   \
    \ ll res = 0;\n    rep(i, S.size()) {\n        res += toint(S[i]);\n    }\n  \
    \  return res;\n}\n"
  dependsOn:
  - src/common/toint.hpp
  - src/base.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/numbers/digit_sum.hpp
  requiredBy: []
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/digit_sum.hpp
layout: document
redirect_from:
- /library/src/numbers/digit_sum.hpp
- /library/src/numbers/digit_sum.hpp.html
title: src/numbers/digit_sum.hpp
---
