---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/listnd.hpp\"\
    \n\ntemplate<typename T>\n[[deprecated(\"list2d will be merged with listnd\")]]\n\
    vector<vector<T>> list2d(int N, int M, T init) {\n    return vector<vector<T>>(N,\
    \ vector<T>(M, init));\n}\n\ntemplate<typename T>\n[[deprecated(\"list3d will\
    \ be merged with listnd\")]]\nvector<vector<vector<T>>> list3d(int N, int M, int\
    \ L, T init) {\n    return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L,\
    \ init)));\n}\n\ntemplate<typename T>\n[[deprecated(\"list4d will be merged with\
    \ listnd\")]]\nvector<vector<vector<vector<T>>>> list4d(int N, int M, int L, int\
    \ O, T init) {\n    return vector<vector<vector<vector<T>>>>(N, vector<vector<vector<T>>>(M,\
    \ vector<vector<T>>(L, vector<T>(O, init))));\n}\n\n// \u4EFB\u610F\u6B21\u5143\
    vector\n// \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
    template<typename T>\nvector<T> listnd(size_t a, T b) {\n    return vector<T>(a,\
    \ b);\n}\n\ntemplate<typename... Ts>\nauto listnd(size_t a, Ts... ts) {\n    return\
    \ vector<decltype(listnd(ts...))>(a, listnd(ts...));\n}\n#line 3 \"src/combinatorics/nCr.hpp\"\
    \n\n// nCr\u5217\u6319 (\u8A08\u7B97\u91CF\uFF1AO(n*r))\n// template<typename\
    \ T>\n// vector<vector<T>> nCr(int n, int r) {\n//     auto dp = list2d(n+1, r+1,\
    \ (T)0);\n//     dp[0][0] = 1;\n//     rep(i, 1, n+1) {\n//         dp[i][0] =\
    \ 1;\n//         rep(j, 1, r+1) {\n//             dp[i][j] = dp[i-1][j-1]+dp[i-1][j];\n\
    //         }\n//     }\n//     return dp;\n// }\n\n// N\u304C\u3067\u304B\u304F\
    \u3066\u3082\u3044\u3051\u308BnCr (\u8A08\u7B97\u91CF\uFF1AO(r))\ntemplate<typename\
    \ T>\nT nCr(int n, int r) {\n    T res = 1;\n    rep(i, r) res = res*(T)(n-i)/(T)(i+1);\n\
    \    return res;\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"../common/listnd.hpp\"\n\n// nCr\u5217\
    \u6319 (\u8A08\u7B97\u91CF\uFF1AO(n*r))\n// template<typename T>\n// vector<vector<T>>\
    \ nCr(int n, int r) {\n//     auto dp = list2d(n+1, r+1, (T)0);\n//     dp[0][0]\
    \ = 1;\n//     rep(i, 1, n+1) {\n//         dp[i][0] = 1;\n//         rep(j, 1,\
    \ r+1) {\n//             dp[i][j] = dp[i-1][j-1]+dp[i-1][j];\n//         }\n//\
    \     }\n//     return dp;\n// }\n\n// N\u304C\u3067\u304B\u304F\u3066\u3082\u3044\
    \u3051\u308BnCr (\u8A08\u7B97\u91CF\uFF1AO(r))\ntemplate<typename T>\nT nCr(int\
    \ n, int r) {\n    T res = 1;\n    rep(i, r) res = res*(T)(n-i)/(T)(i+1);\n  \
    \  return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/combinatorics/nCr.hpp
  requiredBy: []
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/nCr.hpp
layout: document
redirect_from:
- /library/src/combinatorics/nCr.hpp
- /library/src/combinatorics/nCr.hpp.html
title: src/combinatorics/nCr.hpp
---