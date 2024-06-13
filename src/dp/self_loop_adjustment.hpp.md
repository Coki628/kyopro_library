---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dp/self_loop_adjustment.hpp\"\n\n// \u671F\u5F85\u5024\
    DP(\u78BA\u7387DP)\u306E\u81EA\u5DF1\u30EB\u30FC\u30D7\u88DC\u6B63\n// \u901A\u5E38\
    \u306E\u9077\u79FB\u304C\u5168\u90E8\u7D42\u308F\u3063\u305F\u6240\u3067\u3053\
    \u306E\u95A2\u6570\u306B\u5024\u3092\u6E21\u3059\u3002\n// val: \u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u4EE5\u5916\u306E\u9077\u79FB\u3092\u8A08\u7B97\u6E08\u306Eexp or\
    \ prob\n// cost: \u81EA\u5DF1\u30EB\u30FC\u30D71\u56DE\u5206\u306E\u30B3\u30B9\
    \u30C8(\u78BA\u7387DP\u306E\u6642\u306F0)\n// self_loop_count: \u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u306B\u306A\u308B\u9077\u79FB\u306E\u56DE\u6570\n// total_count:\
    \ \u305D\u306E\u6642\u70B9\u3067\u53D6\u308C\u308B\u9077\u79FB\u306E\u7DCF\u6570\
    \ntemplate<typename T>\nvoid self_loop_adjustment(T &val, T cost, T self_loop_count,\
    \ T total_count) {\n    // \u81EA\u5DF1\u30EB\u30FC\u30D7\u306E\u30B3\u30B9\u30C8\
    \ * \u305D\u3046\u306A\u308B\u78BA\u7387\n    val += cost * self_loop_count /\
    \ total_count;\n    // \u300C\u9077\u79FB\u306E\u7DCF\u6570 / \u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u306B\u306A\u3089\u305A\u306B\u9077\u79FB\u3059\u308B\u6570\u300D\
    \u3092\u639B\u3051\u308B\n    val *= total_count / (total_count - self_loop_count);\n\
    }\n"
  code: "#pragma once\n\n// \u671F\u5F85\u5024DP(\u78BA\u7387DP)\u306E\u81EA\u5DF1\
    \u30EB\u30FC\u30D7\u88DC\u6B63\n// \u901A\u5E38\u306E\u9077\u79FB\u304C\u5168\u90E8\
    \u7D42\u308F\u3063\u305F\u6240\u3067\u3053\u306E\u95A2\u6570\u306B\u5024\u3092\
    \u6E21\u3059\u3002\n// val: \u81EA\u5DF1\u30EB\u30FC\u30D7\u4EE5\u5916\u306E\u9077\
    \u79FB\u3092\u8A08\u7B97\u6E08\u306Eexp or prob\n// cost: \u81EA\u5DF1\u30EB\u30FC\
    \u30D71\u56DE\u5206\u306E\u30B3\u30B9\u30C8(\u78BA\u7387DP\u306E\u6642\u306F0)\n\
    // self_loop_count: \u81EA\u5DF1\u30EB\u30FC\u30D7\u306B\u306A\u308B\u9077\u79FB\
    \u306E\u56DE\u6570\n// total_count: \u305D\u306E\u6642\u70B9\u3067\u53D6\u308C\
    \u308B\u9077\u79FB\u306E\u7DCF\u6570\ntemplate<typename T>\nvoid self_loop_adjustment(T\
    \ &val, T cost, T self_loop_count, T total_count) {\n    // \u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u306E\u30B3\u30B9\u30C8 * \u305D\u3046\u306A\u308B\u78BA\u7387\n\
    \    val += cost * self_loop_count / total_count;\n    // \u300C\u9077\u79FB\u306E\
    \u7DCF\u6570 / \u81EA\u5DF1\u30EB\u30FC\u30D7\u306B\u306A\u3089\u305A\u306B\u9077\
    \u79FB\u3059\u308B\u6570\u300D\u3092\u639B\u3051\u308B\n    val *= total_count\
    \ / (total_count - self_loop_count);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/self_loop_adjustment.hpp
  requiredBy: []
  timestamp: '2024-05-08 12:52:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dp/self_loop_adjustment.hpp
layout: document
redirect_from:
- /library/src/dp/self_loop_adjustment.hpp
- /library/src/dp/self_loop_adjustment.hpp.html
title: src/dp/self_loop_adjustment.hpp
---
