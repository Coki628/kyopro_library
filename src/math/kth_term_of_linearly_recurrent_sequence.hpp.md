---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/math/coeff_of_rational_function.hpp
    title: src/math/coeff_of_rational_function.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/BM.hpp
    title: src/math/BM.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/math/fps/kth-term-of-linearly-recurrent-sequence.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/math/coeff_of_rational_function.hpp\"\n\n\
    // see: https://ei1333.github.io/library/math/fps/coeff-of-rational-function.hpp\n\
    template< template< typename > class FPS, typename Mint >\nMint coeff_of_rational_function(FPS<\
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
    \ 4 \"src/math/kth_term_of_linearly_recurrent_sequence.hpp\"\n\n// see: https://ei1333.github.io/library/math/fps/kth-term-of-linearly-recurrent-sequence.hpp\n\
    template< template< typename > class FPS, typename Mint >\nMint kth_term_of_linearly_recurrent_sequence(const\
    \ FPS< Mint > &a, FPS< Mint > c, int64_t k) {\n    assert(a.size() == c.size());\n\
    \    c = FPS< Mint >{1} - (c << 1);\n    return coeff_of_rational_function((a\
    \ * c).pre(a.size()), c, k);\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"coeff_of_rational_function.hpp\"\
    \n\n// see: https://ei1333.github.io/library/math/fps/kth-term-of-linearly-recurrent-sequence.hpp\n\
    template< template< typename > class FPS, typename Mint >\nMint kth_term_of_linearly_recurrent_sequence(const\
    \ FPS< Mint > &a, FPS< Mint > c, int64_t k) {\n    assert(a.size() == c.size());\n\
    \    c = FPS< Mint >{1} - (c << 1);\n    return coeff_of_rational_function((a\
    \ * c).pre(a.size()), c, k);\n}\n"
  dependsOn:
  - src/base.hpp
  - src/math/coeff_of_rational_function.hpp
  isVerificationFile: false
  path: src/math/kth_term_of_linearly_recurrent_sequence.hpp
  requiredBy:
  - src/math/BM.hpp
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/kth_term_of_linearly_recurrent_sequence.hpp
layout: document
redirect_from:
- /library/src/math/kth_term_of_linearly_recurrent_sequence.hpp
- /library/src/math/kth_term_of_linearly_recurrent_sequence.hpp.html
title: src/math/kth_term_of_linearly_recurrent_sequence.hpp
---
