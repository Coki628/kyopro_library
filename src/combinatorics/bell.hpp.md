---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/combinatorics/ModTools.hpp
    title: src/combinatorics/ModTools.hpp
  - icon: ':warning:'
    path: src/combinatorics/stirling.hpp
    title: src/combinatorics/stirling.hpp
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
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull\
    \ = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/combinatorics/ModTools.hpp\"\
    \n\n// Mod\u6570\u3048\u4E0A\u3052\u6F14\u7B97\u30C4\u30FC\u30EB\ntemplate<typename\
    \ Mint>\nstruct ModTools {\nprivate:\n    int MAX;\n    vector<Mint> _fact, _factinv,\
    \ inv;\n\npublic:\n    // nCr\u306A\u3089n\u3001nHr\u306A\u3089n+r\u307E\u3067\
    \u4F5C\u308B\n    ModTools(int mx) : MAX(++mx) {\n        _fact.resize(MAX);\n\
    \        _factinv.resize(MAX);\n        inv.resize(MAX);\n        _fact[0] = _fact[1]\
    \ = 1;\n        for (int i = 2; i < MAX; i++) {\n            _fact[i] = _fact[i\
    \ - 1] * (Mint)i;\n        }\n        _factinv[MAX - 1] = (Mint)1 / _fact[MAX\
    \ - 1];\n        for (int i = MAX - 2; i >= 0; i--) {\n            _factinv[i]\
    \ = _factinv[i + 1] * (Mint)(i + 1);\n        }\n        for (int i = MAX - 1;\
    \ i > 0; i--) {\n            inv[i] = _factinv[i] * _fact[i - 1];\n        }\n\
    \    }\n\n    // \u6E96\u5099O(N)\u3001\u64CD\u4F5CO(1)\u3067log\u304C\u4E57\u3089\
    \u306A\u3044mod\u9664\u7B97\n    Mint div(Mint a, int b) {\n        return a *\
    \ inv[b];\n    }\n\n    Mint fact(int x) {\n        assert(x < MAX);\n       \
    \ return _fact[x];\n    }\n\n    Mint factinv(int x) {\n        assert(x < MAX);\n\
    \        return _factinv[x];\n    }\n\n    Mint nCr(int n, int r) {\n        if\
    \ (n < r or r < 0) return 0;\n        r = min(r, n - r);\n        Mint num = _fact[n];\n\
    \        Mint den = _factinv[r] * _factinv[n - r];\n        return num * den;\n\
    \    }\n\n    Mint nHr(int n, int r) {\n        assert(r + n - 1 < MAX);\n   \
    \     return nCr(r + n - 1, r);\n    }\n\n    Mint nPr(int n, int r) {\n     \
    \   if (n < r or r < 0) return 0;\n        return _fact[n] * _factinv[n - r];\n\
    \    }\n\n    // \u4E8C\u91CD\u968E\u4E57\n    // \u53C2\u8003\uFF1Ahttps://ja.wikipedia.org/wiki/%E4%BA%8C%E9%87%8D%E9%9A%8E%E4%B9%97\n\
    \    Mint double_factorial(int n) {\n        if (n % 2 == 0) {\n            int\
    \ k = n / 2;\n            return Mint(2).pow(k) * fact(k);\n        } else {\n\
    \            int k = (n + 1) / 2;\n            return fact(2 * k) / Mint(2).pow(k)\
    \ / fact(k);\n        }\n    }\n};\n#line 3 \"src/common/listnd.hpp\"\n\n// \u4EFB\
    \u610F\u6B21\u5143vector\n// \u53C2\u8003\uFF1Ahttps://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp\n\
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
    \  return dp;\n}\n#line 5 \"src/combinatorics/bell.hpp\"\n\n// \u30D9\u30EB\u6570\
    (\u7389\u533A\u5225\u3042\u308A\u3001\u7BB1\u533A\u5225\u306A\u3057\u3001\u5236\
    \u9650\u306A\u3057) \u203B\u672AVerify\nll bell(int N, int K) {\n    ll ans =\
    \ 0;\n    for (int i = 0; i < K + 1; i++) {\n        ans += stirling<ll>(N, i)[N][i];\n\
    \    }\n    return ans;\n}\n\n// \u30D9\u30EB\u6570(\u7389\u533A\u5225\u3042\u308A\
    \u3001\u7BB1\u533A\u5225\u306A\u3057\u3001\u5236\u9650\u306A\u3057) \u203B\u672A\
    Verify\ntemplate<typename Mint>\nMint bell(int N, int K) {\n    ModTools<Mint>\
    \ mt(max(N, K));\n\n    // \u524D\u8A08\u7B97\u3057\u3066\u304A\u304F\n    vector<Mint>\
    \ prev(K + 1);\n    for (int i = 0; i < K + 1; i++) {\n        prev[i] = (Mint)1\
    \ / mt.fact[i];\n    }\n    // \u7D2F\u7A4D\u548C\n    for (int i = 1; i < K +\
    \ 1; i++) {\n        prev[i] += prev[i - 1];\n    }\n\n    Mint ans = 0;\n   \
    \ for (int i = 0; i < K + 1; i++) {\n        ans += (Mint)pow(i, N, MOD) / mt.fact[i]\
    \ * prev[K - i];\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"ModTools.hpp\"\n#include\
    \ \"stirling.hpp\"\n\n// \u30D9\u30EB\u6570(\u7389\u533A\u5225\u3042\u308A\u3001\
    \u7BB1\u533A\u5225\u306A\u3057\u3001\u5236\u9650\u306A\u3057) \u203B\u672AVerify\n\
    ll bell(int N, int K) {\n    ll ans = 0;\n    for (int i = 0; i < K + 1; i++)\
    \ {\n        ans += stirling<ll>(N, i)[N][i];\n    }\n    return ans;\n}\n\n//\
    \ \u30D9\u30EB\u6570(\u7389\u533A\u5225\u3042\u308A\u3001\u7BB1\u533A\u5225\u306A\
    \u3057\u3001\u5236\u9650\u306A\u3057) \u203B\u672AVerify\ntemplate<typename Mint>\n\
    Mint bell(int N, int K) {\n    ModTools<Mint> mt(max(N, K));\n\n    // \u524D\u8A08\
    \u7B97\u3057\u3066\u304A\u304F\n    vector<Mint> prev(K + 1);\n    for (int i\
    \ = 0; i < K + 1; i++) {\n        prev[i] = (Mint)1 / mt.fact[i];\n    }\n   \
    \ // \u7D2F\u7A4D\u548C\n    for (int i = 1; i < K + 1; i++) {\n        prev[i]\
    \ += prev[i - 1];\n    }\n\n    Mint ans = 0;\n    for (int i = 0; i < K + 1;\
    \ i++) {\n        ans += (Mint)pow(i, N, MOD) / mt.fact[i] * prev[K - i];\n  \
    \  }\n    return ans;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/combinatorics/ModTools.hpp
  - src/combinatorics/stirling.hpp
  - src/common/listnd.hpp
  isVerificationFile: false
  path: src/combinatorics/bell.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/bell.hpp
layout: document
redirect_from:
- /library/src/combinatorics/bell.hpp
- /library/src/combinatorics/bell.hpp.html
title: src/combinatorics/bell.hpp
---
