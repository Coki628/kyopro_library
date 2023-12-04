---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':x:'
    path: src/common/listnd.hpp
    title: src/common/listnd.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/combinatorics/bell.hpp
    title: src/combinatorics/bell.hpp
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
    \n\n// \u4EFB\u610F\u6B21\u5143vector\n// \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
    template<typename... Ts>\nauto listnd(size_t N, Ts... ts) {\n    if constexpr\
    \ (sizeof...(ts) == 1) {\n        return vector<Ts...>(N, ts...);\n    } else\
    \ {\n        auto res = listnd(ts...);\n        return vector<decltype(res)>(N,\
    \ res);\n    }\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\ntemplate<typename T>[[deprecated(\"\
    list2d will be merged with listnd\")]] vv<T> list2d(int N, int M, T init) { return\
    \ listnd(N, M, init); }\ntemplate<typename T>[[deprecated(\"list3d will be merged\
    \ with listnd\")]] vv<vector<T>> list3d(int N, int M, int L, T init) { return\
    \ listnd(N, M, L, init); }\ntemplate<typename T>[[deprecated(\"list4d will be\
    \ merged with listnd\")]] vv<vv<T>> list4d(int N, int M, int L, int O, T init)\
    \ { return listnd(N, M, L, O, init); }\n#line 4 \"src/combinatorics/stirling.hpp\"\
    \n\n// \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570(\u7389\u533A\u5225\u3042\u308A\
    \u3001\u7BB1\u533A\u5225\u306A\u3057\u30011\u500B\u4EE5\u4E0A)\ntemplate<typename\
    \ T>\nvv<T> stirling(int N, int K) {\n    auto dp = listnd(N + 1, K + 1, (T)0);\n\
    \    dp[0][0] = 1;\n    rep(i, 1, N + 1) {\n        rep(k, 1, K + 1) {\n     \
    \       dp[i][k] = dp[i - 1][k - 1] + dp[i - 1][k] * k;\n        }\n    }\n  \
    \  return dp;\n}\n"
  code: "#pragma once\n#include \"../common/listnd.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570(\u7389\u533A\u5225\u3042\u308A\
    \u3001\u7BB1\u533A\u5225\u306A\u3057\u30011\u500B\u4EE5\u4E0A)\ntemplate<typename\
    \ T>\nvv<T> stirling(int N, int K) {\n    auto dp = listnd(N + 1, K + 1, (T)0);\n\
    \    dp[0][0] = 1;\n    rep(i, 1, N + 1) {\n        rep(k, 1, K + 1) {\n     \
    \       dp[i][k] = dp[i - 1][k - 1] + dp[i - 1][k] * k;\n        }\n    }\n  \
    \  return dp;\n}\n"
  dependsOn:
  - src/common/listnd.hpp
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/stirling.hpp
  requiredBy:
  - src/combinatorics/bell.hpp
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/stirling.hpp
layout: document
redirect_from:
- /library/src/combinatorics/stirling.hpp
- /library/src/combinatorics/stirling.hpp.html
title: src/combinatorics/stirling.hpp
---
