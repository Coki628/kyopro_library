---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/BM.hpp
    title: src/math/BM.hpp
  - icon: ':warning:'
    path: src/math/kth_term_of_linearly_recurrent_sequence.hpp
    title: Kth Term of Linearly Recurrent Sequence
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/coeff-of-rational-function.md
    document_title: Coeff of Rational Function
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/math/coeff_of_rational_function.hpp\"\n\n\
    /**\n * @brief Coeff of Rational Function\n * @docs docs/coeff-of-rational-function.md\n\
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
    \  Q = sub(Q * Q2, 0);\n        k >>= 1;\n    }\n    return ret + P[0];\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Coeff of Rational\
    \ Function\n * @docs docs/coeff-of-rational-function.md\n */\ntemplate< template<\
    \ typename > class FPS, typename Mint >\nMint coeff_of_rational_function(FPS<\
    \ Mint > P, FPS< Mint > Q, int64_t k) {\n    // compute the coefficient [x^k]\
    \ P/Q of rational power series\n    Mint ret = 0;\n    if(P.size() >= Q.size())\
    \ {\n        auto R = P / Q;\n        P -= R * Q;\n        P.shrink();\n     \
    \   if(k < (int) R.size()) ret += R[k];\n    }\n    if(P.empty()) return ret;\n\
    \    P.resize((int) Q.size() - 1);\n    auto sub = [&](const FPS< Mint > &as,\
    \ bool odd) {\n        FPS< Mint > bs((as.size() + !odd) / 2);\n        for(int\
    \ i = odd; i < (int) as.size(); i += 2) bs[i >> 1] = as[i];\n        return bs;\n\
    \    };\n    while(k > 0) {\n        auto Q2(Q);\n        for(int i = 1; i < (int)\
    \ Q2.size(); i += 2) Q2[i] = -Q2[i];\n        P = sub(P * Q2, k & 1);\n      \
    \  Q = sub(Q * Q2, 0);\n        k >>= 1;\n    }\n    return ret + P[0];\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/math/coeff_of_rational_function.hpp
  requiredBy:
  - src/math/BM.hpp
  - src/math/kth_term_of_linearly_recurrent_sequence.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/coeff_of_rational_function.hpp
layout: document
redirect_from:
- /library/src/math/coeff_of_rational_function.hpp
- /library/src/math/coeff_of_rational_function.hpp.html
title: Coeff of Rational Function
---
