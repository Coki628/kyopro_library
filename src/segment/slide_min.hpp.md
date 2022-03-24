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
    src/segment/slide_min.hpp\"\n\n// \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024(\u6BD4\
    \u8F03\u95A2\u6570\u3001\u5143\u306E\u6570\u5217\u3001\u9077\u79FB\u56DE\u6570\
    \u3001\u9077\u79FB\u5E45\u3001\u9077\u79FB\u306E\u91CD\u307F)\ntemplate<typename\
    \ T, typename F>\nvector<T> slide_min(const F &func, vector<T> &A, ll k, ll w=1,\
    \ ll v=0) {\n\n    ll N = A.size();\n    auto res = A;\n    rep(a, w) {\n    \
    \    deque<pair<int, T>> que;\n        int i = 0;\n        while (i*w+a < N) {\n\
    \            ll val = A[i*w+a] - i*v;\n            while (!que.empty() and func(que.back().second,\
    \ val) == val) {\n                que.pop_back();\n            }\n           \
    \ que.pb({i, val});\n            res[i*w+a] = que.front().second + i*v;\n    \
    \        if (que.front().first == i-k+1) {\n                que.pop_front();\n\
    \            }\n            i++;\n        }\n    }\n    return res;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\
    (\u6BD4\u8F03\u95A2\u6570\u3001\u5143\u306E\u6570\u5217\u3001\u9077\u79FB\u56DE\
    \u6570\u3001\u9077\u79FB\u5E45\u3001\u9077\u79FB\u306E\u91CD\u307F)\ntemplate<typename\
    \ T, typename F>\nvector<T> slide_min(const F &func, vector<T> &A, ll k, ll w=1,\
    \ ll v=0) {\n\n    ll N = A.size();\n    auto res = A;\n    rep(a, w) {\n    \
    \    deque<pair<int, T>> que;\n        int i = 0;\n        while (i*w+a < N) {\n\
    \            ll val = A[i*w+a] - i*v;\n            while (!que.empty() and func(que.back().second,\
    \ val) == val) {\n                que.pop_back();\n            }\n           \
    \ que.pb({i, val});\n            res[i*w+a] = que.front().second + i*v;\n    \
    \        if (que.front().first == i-k+1) {\n                que.pop_front();\n\
    \            }\n            i++;\n        }\n    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/segment/slide_min.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/segment/slide_min.hpp
layout: document
redirect_from:
- /library/src/segment/slide_min.hpp
- /library/src/segment/slide_min.hpp.html
title: src/segment/slide_min.hpp
---
