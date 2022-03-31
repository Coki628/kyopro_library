---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
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
    src/common/listnd.hpp\"\n\ntemplate<typename T> vector<vector<T>> list2d(int N,\
    \ int M, T init) {\n    return vector<vector<T>>(N, vector<T>(M, init));\n}\n\n\
    template<typename T> vector<vector<vector<T>>> list3d(int N, int M, int L, T init)\
    \ {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L,\
    \ init)));\n}\n\ntemplate<typename T> vector<vector<vector<vector<T>>>> list4d(int\
    \ N, int M, int L, int O, T init) {\n    return vector<vector<vector<vector<T>>>>(N,\
    \ vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));\n}\n\
    #line 3 \"src/common/Doubling.hpp\"\n\n// \u30C0\u30D6\u30EA\u30F3\u30B0\ntemplate<typename\
    \ T, typename F>\nstruct Doubling {\n\n    int N;\n    vector<vector<T>> dat;\n\
    \    const int MXLOG;\n    const F f;\n\n    // \u901A\u5E38\u306F\u3053\u3063\
    \u3061\n    Doubling(int MXLOG, const vector<T> &A, T init, const F &f) : MXLOG(MXLOG),\
    \ f(f) {\n        N = A.size();\n        dat = list2d(MXLOG, N, init);\n     \
    \   rep(i, N) {\n            dat[0][i] = A[i];\n        }\n        rep(k, 1, MXLOG)\
    \ {\n            rep(i, N) {\n                dat[k][i] = f(dat[k-1][i], dat[k-1][dat[k-1][i]]);\n\
    \            }\n        }\n    }\n\n    // \u30C0\u30D6\u30EA\u30F3\u30B0\u914D\
    \u5217\u3092\u30E9\u30A4\u30D6\u30E9\u30EA\u5916\u3067\u4E8B\u524D\u69CB\u7BC9\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    Doubling(const vector<vector<T>>\
    \ &A, const F &f) : MXLOG(A.size()), dat(A), f(f) {}\n\n    // st\u304B\u3089\u59CB\
    \u3081\u3066K\u500B\u5148\u3092\u8FD4\u3059\n    T get(T st, ll K) {\n       \
    \ T res = st;\n        rep(k, MXLOG-1, -1, -1) {\n            if (K>>k & 1) {\n\
    \                res = f(res, dat[k][res]);\n            }\n        }\n      \
    \  return res;\n    }\n\n    vector<T> get(const vector<T> &st, ll K) {\n    \
    \    vector<T> res = st;\n        rep(k, MXLOG-1, -1, -1) {\n            if (K>>k\
    \ & 1) {\n                res = f(res, dat[k], k);\n            }\n        }\n\
    \        return res;\n    }\n\n    // st\u304B\u3089\u59CB\u3081\u30661\u500B\u5148\
    \u3092\u8FD4\u3059\n    T next(T st) {\n        return f(st, dat[0][st]);\n  \
    \  }\n\n    // st\u304B\u3089\u59CB\u3081\u3066g\u306B\u5230\u9054\u3059\u308B\
    \u307E\u3067\u306E\u56DE\u6570\u3092\u8FD4\u3059\n    ll times(T st, ll g) {\n\
    \        T cur = st;\n        ll res = 0;\n        rep(k, MXLOG-1, -1, -1) {\n\
    \            if (dat[k][cur] < g) {\n                res += 1LL<<k;\n        \
    \        cur = dat[k][cur];\n            }\n        }\n        res++;\n      \
    \  return res;\n    }\n};\n\ntemplate<typename T, typename F>\nDoubling<T, F>\
    \ get_doubling(int MXLOG, const vector<T> &A, T init, const F &f) {\n    return\
    \ {MXLOG, A, init, f};\n}\n\ntemplate<typename T, typename F>\nDoubling<T, F>\
    \ get_doubling(const vector<vector<T>> &A, const F &f) {\n    return {A, f};\n\
    }\n"
  code: "#include \"../macros.hpp\"\n#include \"listnd.hpp\"\n\n// \u30C0\u30D6\u30EA\
    \u30F3\u30B0\ntemplate<typename T, typename F>\nstruct Doubling {\n\n    int N;\n\
    \    vector<vector<T>> dat;\n    const int MXLOG;\n    const F f;\n\n    // \u901A\
    \u5E38\u306F\u3053\u3063\u3061\n    Doubling(int MXLOG, const vector<T> &A, T\
    \ init, const F &f) : MXLOG(MXLOG), f(f) {\n        N = A.size();\n        dat\
    \ = list2d(MXLOG, N, init);\n        rep(i, N) {\n            dat[0][i] = A[i];\n\
    \        }\n        rep(k, 1, MXLOG) {\n            rep(i, N) {\n            \
    \    dat[k][i] = f(dat[k-1][i], dat[k-1][dat[k-1][i]]);\n            }\n     \
    \   }\n    }\n\n    // \u30C0\u30D6\u30EA\u30F3\u30B0\u914D\u5217\u3092\u30E9\u30A4\
    \u30D6\u30E9\u30EA\u5916\u3067\u4E8B\u524D\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n    Doubling(const vector<vector<T>> &A, const\
    \ F &f) : MXLOG(A.size()), dat(A), f(f) {}\n\n    // st\u304B\u3089\u59CB\u3081\
    \u3066K\u500B\u5148\u3092\u8FD4\u3059\n    T get(T st, ll K) {\n        T res\
    \ = st;\n        rep(k, MXLOG-1, -1, -1) {\n            if (K>>k & 1) {\n    \
    \            res = f(res, dat[k][res]);\n            }\n        }\n        return\
    \ res;\n    }\n\n    vector<T> get(const vector<T> &st, ll K) {\n        vector<T>\
    \ res = st;\n        rep(k, MXLOG-1, -1, -1) {\n            if (K>>k & 1) {\n\
    \                res = f(res, dat[k], k);\n            }\n        }\n        return\
    \ res;\n    }\n\n    // st\u304B\u3089\u59CB\u3081\u30661\u500B\u5148\u3092\u8FD4\
    \u3059\n    T next(T st) {\n        return f(st, dat[0][st]);\n    }\n\n    //\
    \ st\u304B\u3089\u59CB\u3081\u3066g\u306B\u5230\u9054\u3059\u308B\u307E\u3067\u306E\
    \u56DE\u6570\u3092\u8FD4\u3059\n    ll times(T st, ll g) {\n        T cur = st;\n\
    \        ll res = 0;\n        rep(k, MXLOG-1, -1, -1) {\n            if (dat[k][cur]\
    \ < g) {\n                res += 1LL<<k;\n                cur = dat[k][cur];\n\
    \            }\n        }\n        res++;\n        return res;\n    }\n};\n\n\
    template<typename T, typename F>\nDoubling<T, F> get_doubling(int MXLOG, const\
    \ vector<T> &A, T init, const F &f) {\n    return {MXLOG, A, init, f};\n}\n\n\
    template<typename T, typename F>\nDoubling<T, F> get_doubling(const vector<vector<T>>\
    \ &A, const F &f) {\n    return {A, f};\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/common/Doubling.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/Doubling.hpp
layout: document
redirect_from:
- /library/src/common/Doubling.hpp
- /library/src/common/Doubling.hpp.html
title: src/common/Doubling.hpp
---
