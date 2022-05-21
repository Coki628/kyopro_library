---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/pow.hpp
    title: src/common/pow.hpp
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
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/common/pow.hpp\"\n\nll pow(ll x, ll n) {\n    ll res = 1;\n    rep(_, n) res\
    \ *= x;\n    return res;\n}\n\nll pow(int x, ll n) { return pow((ll)x, n); }\n\
    \nll pow(ll x, int n) { return pow(x, (ll)n); }\n\nll pow(int x, int n) { return\
    \ pow((ll)x, (ll)n); }\n\nll pow(ll x, ll n, int mod) {\n    x %= mod;\n    ll\
    \ res = 1;\n    while (n > 0) {\n        if (n & 1) {\n            res = (res\
    \ * x) % mod;\n        }\n        x = (x * x) % mod;\n        n >>= 1;\n    }\n\
    \    return res;\n}\n#line 3 \"src/numbers/bsgs.hpp\"\n\n// x^k \u2261 y (mod\
    \ m) \u3068\u306A\u308B\u3088\u3046\u306A k \u3092\u6C42\u3081\u308B\nll bsgs(ll\
    \ x, ll y, ll m) {\n    ll z = 1;\n    map<ll, ll> C = {{z, 0}};\n    ll sq =\
    \ int(sqrt(m)) + 1;\n\n    // Baby-step\n    rep(i, sq) {\n        z = z * x %\
    \ m;\n        C[z] = i + 1;\n    }\n    if (C.count(y)) {\n        return C[y];\n\
    \    }\n\n    // Giant-step\n    ll r = pow(z, m-2, m); // r = x^(-sq);\n    rep(i,\
    \ 1, sq+1) {\n        y = y * r % m;\n        if (C.count(y)) {\n            return\
    \ C[y] + i*sq;\n        }\n    }\n    return -1;\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"../common/pow.hpp\"\n\n// x^k \u2261\
    \ y (mod m) \u3068\u306A\u308B\u3088\u3046\u306A k \u3092\u6C42\u3081\u308B\n\
    ll bsgs(ll x, ll y, ll m) {\n    ll z = 1;\n    map<ll, ll> C = {{z, 0}};\n  \
    \  ll sq = int(sqrt(m)) + 1;\n\n    // Baby-step\n    rep(i, sq) {\n        z\
    \ = z * x % m;\n        C[z] = i + 1;\n    }\n    if (C.count(y)) {\n        return\
    \ C[y];\n    }\n\n    // Giant-step\n    ll r = pow(z, m-2, m); // r = x^(-sq);\n\
    \    rep(i, 1, sq+1) {\n        y = y * r % m;\n        if (C.count(y)) {\n  \
    \          return C[y] + i*sq;\n        }\n    }\n    return -1;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/pow.hpp
  isVerificationFile: false
  path: src/numbers/bsgs.hpp
  requiredBy: []
  timestamp: '2022-05-22 00:24:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/bsgs.hpp
layout: document
redirect_from:
- /library/src/numbers/bsgs.hpp
- /library/src/numbers/bsgs.hpp.html
title: src/numbers/bsgs.hpp
---
