---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/math/berlekamp_massey.hpp
    title: Berlekamp Massey
  - icon: ':warning:'
    path: src/math/coeff_of_rational_function.hpp
    title: Coeff of Rational Function
  - icon: ':warning:'
    path: src/math/kth_term_of_linearly_recurrent_sequence.hpp
    title: Kth Term of Linearly Recurrent Sequence
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
    \ = vector<vector<pil>>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\n\
    #define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i\
    \ < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define\
    \ rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c\
    \ < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b);\
    \ i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 1 \"src/math/berlekamp_massey.hpp\"\
    \n/**\n * @brief Berlekamp Massey\n */\ntemplate< template< typename > class FPS,\
    \ typename Mint >\nFPS< Mint > berlekamp_massey(const FPS< Mint > &s) {\n    const\
    \ int N = (int) s.size();\n    FPS< Mint > b = {Mint(-1)}, c = {Mint(-1)};\n \
    \   Mint y = Mint(1);\n    for(int ed = 1; ed <= N; ed++) {\n        int l = int(c.size()),\
    \ m = int(b.size());\n        Mint x = 0;\n        for(int i = 0; i < l; i++)\
    \ x += c[i] * s[ed - l + i];\n        b.emplace_back(0);\n        m++;\n     \
    \   if(x == Mint(0)) continue;\n        Mint freq = x / y;\n        if(l < m)\
    \ {\n            auto tmp = c;\n            c.insert(begin(c), m - l, Mint(0));\n\
    \            for(int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];\n\
    \            b = tmp;\n            y = x;\n        } else {\n            for(int\
    \ i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n        }\n    }\n\
    \    return c;\n}\n#line 3 \"src/math/coeff_of_rational_function.hpp\"\n\n/**\n\
    \ * @brief Coeff of Rational Function\n * @docs docs/coeff-of-rational-function.md\n\
    \ */\ntemplate< template< typename > class FPS, typename Mint >\nMint coeff_of_rational_function(FPS<\
    \ Mint > P, FPS< Mint > Q, int64_t k) {\n    // compute the coefficient [x^k]\
    \ P/Q of rational power series\n    Mint ret = 0;\n    if(P.size() >= Q.size())\
    \ {\n        auto R = P / Q;\n        P -= R * Q;\n        P.shrink();\n     \
    \   if(k < (int) R.size()) ret += R[k];\n    }\n    if(P.empty()) return ret;\n\
    \    P.resize((int) Q.size() - 1);\n    auto sub = [&](const FPS< Mint > &as,\
    \ bool odd) {\n        FPS< Mint > bs((as.size() + !odd) / 2);\n        for(int\
    \ i = odd; i < (int) as.size(); i += 2) bs[i >> 1] = as[i];\n        return bs;\n\
    \    };\n    while(k > 0) {\n        auto Q2(Q);\n        for(int i = 1; i < (int)\
    \ Q2.size(); i += 2) Q2[i] = -Q2[i];\n        P = sub(P * Q2, k & 1);\n      \
    \  Q = sub(Q * Q2, 0);\n        k >>= 1;\n    }\n    return ret + P[0];\n}\n#line\
    \ 4 \"src/math/kth_term_of_linearly_recurrent_sequence.hpp\"\n\n/**\n * @brief\
    \ Kth Term of Linearly Recurrent Sequence\n * @docs docs/kth-term-of-linearly-recurrent-sequence.md\n\
    \ */\ntemplate< template< typename > class FPS, typename Mint >\nMint kth_term_of_linearly_recurrent_sequence(const\
    \ FPS< Mint > &a, FPS< Mint > c, int64_t k) {\n    assert(a.size() == c.size());\n\
    \    c = FPS< Mint >{1} - (c << 1);\n    return coeff_of_rational_function((a\
    \ * c).pre(a.size()), c, k);\n}\n#line 4 \"src/math/BM.hpp\"\n\n// BM\uFF1A\u7DDA\
    \u5F62\u6F38\u5316\u5F0F\u306E\u6570\u5217A\u304B\u3089\u3001\u305D\u306E\u7B2C\
    K\u9805\u3092\u6C42\u3081\u308B\ntemplate<template<typename> class FPS, typename\
    \ Mint>\nMint BM(FPS<Mint> A, ll K) {\n    auto bm = berlekamp_massey(A);\n  \
    \  bm.pop_back();\n    reverse(ALL(bm));\n    A.resize(bm.size());\n    return\
    \ kth_term_of_linearly_recurrent_sequence(A, bm, K);\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"berlekamp_massey.hpp\"\n#include \"\
    kth_term_of_linearly_recurrent_sequence.hpp\"\n\n// BM\uFF1A\u7DDA\u5F62\u6F38\
    \u5316\u5F0F\u306E\u6570\u5217A\u304B\u3089\u3001\u305D\u306E\u7B2CK\u9805\u3092\
    \u6C42\u3081\u308B\ntemplate<template<typename> class FPS, typename Mint>\nMint\
    \ BM(FPS<Mint> A, ll K) {\n    auto bm = berlekamp_massey(A);\n    bm.pop_back();\n\
    \    reverse(ALL(bm));\n    A.resize(bm.size());\n    return kth_term_of_linearly_recurrent_sequence(A,\
    \ bm, K);\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/math/berlekamp_massey.hpp
  - src/math/kth_term_of_linearly_recurrent_sequence.hpp
  - src/math/coeff_of_rational_function.hpp
  isVerificationFile: false
  path: src/math/BM.hpp
  requiredBy: []
  timestamp: '2023-02-28 01:25:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/BM.hpp
layout: document
redirect_from:
- /library/src/math/BM.hpp
- /library/src/math/BM.hpp.html
title: src/math/BM.hpp
---
