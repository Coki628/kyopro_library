---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
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
    \ namespace std;\n#line 3 \"src/math/Function.hpp\"\n\n// \u5408\u6210\u95A2\u6570\
    \n// \u30FB\u3044\u3064\u3082\u3069\u3063\u3061\u304C\u3069\u3063\u3061\u304B\u3053\
    \u3093\u304C\u3089\u304C\u308B\u306E\u3067\u3082\u3046\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u5316\u3059\u308B\u3002\n// \u30FB\u9069\u7528\u9806\u5E8F\u304C\u5927\u4E8B\
    \uFF01f1 -> f2 \u306E\u9806\u3067\u9069\u7528\u3059\u308B\u3068\u3059\u308B\u3002\
    \n\n// ax + b \u306E\u5408\u6210\u95A2\u6570\n// h2(h1(x))\n// c * h1(x) + d\n\
    // c * (ax + b) + d\n// c * ax + c * b + d\n// {c * a, c * b + d}\n\n// \u5408\
    \u6210\u95A2\u6570(pair\u7248)(\u672Averify)\n// f1 -> f2 \u306E\u9806\u3067\u9069\
    \u7528\u3059\u308B\u3068\u3059\u308B\ntemplate<typename T>\npair<T, T> composite_function(pair<T,\
    \ T> f1, pair<T, T> f2) {\n    return {f2.first * f1.first, f2.first * f1.second\
    \ + f2.second};\n}\n\n// \u5408\u6210\u306F\u524D\u304B\u3089\u9806\u306B\u884C\
    \u308F\u308C\u308B\u3068\u3059\u308B\ntemplate<typename T>\nstruct Function {\n\
    \    T a = 1, b = 0;\n\n    Function &operator*=(const Function &f) {\n      \
    \  a = f.a * a;\n        b = f.a * b + f.b;\n        return *this;\n    }\n\n\
    \    Function operator*(const Function &f) const {\n        return Function(*this)\
    \ *= f;\n    }\n\n    T f(T x) const {\n        return a * x + b;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u5408\u6210\u95A2\u6570\n//\
    \ \u30FB\u3044\u3064\u3082\u3069\u3063\u3061\u304C\u3069\u3063\u3061\u304B\u3053\
    \u3093\u304C\u3089\u304C\u308B\u306E\u3067\u3082\u3046\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u5316\u3059\u308B\u3002\n// \u30FB\u9069\u7528\u9806\u5E8F\u304C\u5927\u4E8B\
    \uFF01f1 -> f2 \u306E\u9806\u3067\u9069\u7528\u3059\u308B\u3068\u3059\u308B\u3002\
    \n\n// ax + b \u306E\u5408\u6210\u95A2\u6570\n// h2(h1(x))\n// c * h1(x) + d\n\
    // c * (ax + b) + d\n// c * ax + c * b + d\n// {c * a, c * b + d}\n\n// \u5408\
    \u6210\u95A2\u6570(pair\u7248)(\u672Averify)\n// f1 -> f2 \u306E\u9806\u3067\u9069\
    \u7528\u3059\u308B\u3068\u3059\u308B\ntemplate<typename T>\npair<T, T> composite_function(pair<T,\
    \ T> f1, pair<T, T> f2) {\n    return {f2.first * f1.first, f2.first * f1.second\
    \ + f2.second};\n}\n\n// \u5408\u6210\u306F\u524D\u304B\u3089\u9806\u306B\u884C\
    \u308F\u308C\u308B\u3068\u3059\u308B\ntemplate<typename T>\nstruct Function {\n\
    \    T a = 1, b = 0;\n\n    Function &operator*=(const Function &f) {\n      \
    \  a = f.a * a;\n        b = f.a * b + f.b;\n        return *this;\n    }\n\n\
    \    Function operator*(const Function &f) const {\n        return Function(*this)\
    \ *= f;\n    }\n\n    T f(T x) const {\n        return a * x + b;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/math/Function.hpp
  requiredBy: []
  timestamp: '2024-08-12 17:44:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/Function.hpp
layout: document
redirect_from:
- /library/src/math/Function.hpp
- /library/src/math/Function.hpp.html
title: src/math/Function.hpp
---
