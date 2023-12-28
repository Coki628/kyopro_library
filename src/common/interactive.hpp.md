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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/interactive.hpp\"\
    \n\n// \u30A4\u30F3\u30BF\u30E9\u30AF\u30C6\u30A3\u30D6\u7528\n// (\u3053\u308C\
    \u3089\u3092\u305D\u306E\u307E\u307E\u3068\u8A00\u3046\u3088\u308A\u3001\u53D6\
    \u3063\u3066\u304D\u3066\u4E2D\u8EAB\u3061\u3087\u3063\u3068\u3044\u3058\u3063\
    \u3066\u4F7F\u3046\u3002)\n\nll ask(ll i) {\n    ll res;\n    cout << \"? \" <<\
    \ i + 1 << endl;\n    cin >> res;\n    res--;\n    return res;\n}\n\nvoid answer(ll\
    \ i) {\n    cout << \"! \" << i + 1 << endl;\n}\n\nvoid answer(const vector<ll>\
    \ &A) {\n    int N = A.size();\n    rep(i, N) {\n        cout << A[i];\n     \
    \   if (i == N - 1) {\n            cout << endl;\n        } else {\n         \
    \   cout << ' ';\n        }\n    }\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u30A4\u30F3\u30BF\u30E9\u30AF\
    \u30C6\u30A3\u30D6\u7528\n// (\u3053\u308C\u3089\u3092\u305D\u306E\u307E\u307E\
    \u3068\u8A00\u3046\u3088\u308A\u3001\u53D6\u3063\u3066\u304D\u3066\u4E2D\u8EAB\
    \u3061\u3087\u3063\u3068\u3044\u3058\u3063\u3066\u4F7F\u3046\u3002)\n\nll ask(ll\
    \ i) {\n    ll res;\n    cout << \"? \" << i + 1 << endl;\n    cin >> res;\n \
    \   res--;\n    return res;\n}\n\nvoid answer(ll i) {\n    cout << \"! \" << i\
    \ + 1 << endl;\n}\n\nvoid answer(const vector<ll> &A) {\n    int N = A.size();\n\
    \    rep(i, N) {\n        cout << A[i];\n        if (i == N - 1) {\n         \
    \   cout << endl;\n        } else {\n            cout << ' ';\n        }\n   \
    \ }\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/interactive.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/interactive.hpp
layout: document
redirect_from:
- /library/src/common/interactive.hpp
- /library/src/common/interactive.hpp.html
title: src/common/interactive.hpp
---
