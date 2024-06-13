---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/numbers/bsgs.hpp
    title: src/numbers/bsgs.hpp
  - icon: ':warning:'
    path: src/numbers/inv_mod.hpp
    title: src/numbers/inv_mod.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc340/editorial/9250
  bundledCode: "#line 2 \"src/numbers/extgcd.hpp\"\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5(ax+by=gcd(a, b)\u306E\u89E3\u3092\u6C42\
    \u3081\u308B)\n// \u53C2\u8003\uFF1Ahttps://atcoder.jp/contests/abc340/editorial/9250\n\
    // \u30FB\u9664\u7B97\u3084mod\u306B\u8CA0\u6570\u304C\u304B\u304B\u308B\u3068\
    \u58CA\u308C\u308B\u6C17\u304C\u3059\u308B\u306E\u3060\u304C\u3001\u4F55\u6545\
    \u304B\u5927\u4E08\u592B\u3089\u3057\u3044\u3002\n// \u30FBax+by=gcd(a,b)\u3068\
    \u306A\u308B\u3088\u3046\u306A\u6574\u6570x,y\u3092\u8FD4\u3059\u3002\n// \u3000\
    \u53F3\u8FBA\u304Cgcd\u306E\u500D\u6570\u3092\u53D6\u308A\u305F\u3044\u3088\u3046\
    \u306A\u3089\u3001x,y\u3082\u500D\u3059\u308C\u3070\u3044\u3044\u3002\n// \u3000\
    \u500D\u6570\u3067\u306A\u3044\u3088\u3046\u306A\u5024\u306F\u69CB\u7BC9\u4E0D\
    \u53EF\u3002\u591A\u5206\u3002\n// \u30FBax-by\u306A\u3089-b\u3092\u6E21\u305B\
    \u3070OK\u307F\u305F\u3044\u306A\u4F7F\u3044\u65B9\u3092\u3057\u3066\u3082\u5927\
    \u4E08\u592B\u305D\u3046\u3002\n// \u30FB\u6700\u5F8C\u306E\u623B\u308A\u5024\u306F\
    \n// \u3000auto [x, y] = extgcd(a, b);\n// \u3000\u306E\u5411\u304D\u3067\u53D7\
    \u3051\u308B\u3002\ntemplate<typename T>\npair<T, T> extgcd(T a, T b) {\n  if\
    \ (b == 0) return {1, 0};\n  T x, y;\n  tie(y, x) = extgcd(b, a % b);\n  y -=\
    \ a / b * x;\n  return {x, y};\n}\n"
  code: "#pragma once\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\
    \u4E92\u9664\u6CD5(ax+by=gcd(a, b)\u306E\u89E3\u3092\u6C42\u3081\u308B)\n// \u53C2\
    \u8003\uFF1Ahttps://atcoder.jp/contests/abc340/editorial/9250\n// \u30FB\u9664\
    \u7B97\u3084mod\u306B\u8CA0\u6570\u304C\u304B\u304B\u308B\u3068\u58CA\u308C\u308B\
    \u6C17\u304C\u3059\u308B\u306E\u3060\u304C\u3001\u4F55\u6545\u304B\u5927\u4E08\
    \u592B\u3089\u3057\u3044\u3002\n// \u30FBax+by=gcd(a,b)\u3068\u306A\u308B\u3088\
    \u3046\u306A\u6574\u6570x,y\u3092\u8FD4\u3059\u3002\n// \u3000\u53F3\u8FBA\u304C\
    gcd\u306E\u500D\u6570\u3092\u53D6\u308A\u305F\u3044\u3088\u3046\u306A\u3089\u3001\
    x,y\u3082\u500D\u3059\u308C\u3070\u3044\u3044\u3002\n// \u3000\u500D\u6570\u3067\
    \u306A\u3044\u3088\u3046\u306A\u5024\u306F\u69CB\u7BC9\u4E0D\u53EF\u3002\u591A\
    \u5206\u3002\n// \u30FBax-by\u306A\u3089-b\u3092\u6E21\u305B\u3070OK\u307F\u305F\
    \u3044\u306A\u4F7F\u3044\u65B9\u3092\u3057\u3066\u3082\u5927\u4E08\u592B\u305D\
    \u3046\u3002\n// \u30FB\u6700\u5F8C\u306E\u623B\u308A\u5024\u306F\n// \u3000auto\
    \ [x, y] = extgcd(a, b);\n// \u3000\u306E\u5411\u304D\u3067\u53D7\u3051\u308B\u3002\
    \ntemplate<typename T>\npair<T, T> extgcd(T a, T b) {\n  if (b == 0) return {1,\
    \ 0};\n  T x, y;\n  tie(y, x) = extgcd(b, a % b);\n  y -= a / b * x;\n  return\
    \ {x, y};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/numbers/extgcd.hpp
  requiredBy:
  - src/numbers/inv_mod.hpp
  - src/numbers/bsgs.hpp
  timestamp: '2024-05-08 12:52:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/extgcd.hpp
layout: document
redirect_from:
- /library/src/numbers/extgcd.hpp
- /library/src/numbers/extgcd.hpp.html
title: src/numbers/extgcd.hpp
---
