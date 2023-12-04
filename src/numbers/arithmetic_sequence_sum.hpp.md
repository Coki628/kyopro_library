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
  bundledCode: "#line 2 \"src/numbers/arithmetic_sequence_sum.hpp\"\n\n// \u7B49\u5DEE\
    \u6570\u5217\u306E\u548C\uFF1A(\u521D\u9805a, \u516C\u5DEEd, \u9805\u6570n)\n\
    template<typename T>\nT arithmetic_sequence_sum(T a, T d, T n) {\n    return (a\
    \ * 2 + (n - 1) * d) * n / 2;\n}\n\n// \u7B49\u5DEE\u6570\u5217\u306E\u548C\uFF1A\
    (\u521D\u9805l, \u672B\u9805r, \u9805\u6570n)\n// template<typename T>\n// T arithmetic_sequence_sum(T\
    \ l, T r, T n) {\n//     return (l+r)*n/2;\n// }\n"
  code: "#pragma once\n\n// \u7B49\u5DEE\u6570\u5217\u306E\u548C\uFF1A(\u521D\u9805\
    a, \u516C\u5DEEd, \u9805\u6570n)\ntemplate<typename T>\nT arithmetic_sequence_sum(T\
    \ a, T d, T n) {\n    return (a * 2 + (n - 1) * d) * n / 2;\n}\n\n// \u7B49\u5DEE\
    \u6570\u5217\u306E\u548C\uFF1A(\u521D\u9805l, \u672B\u9805r, \u9805\u6570n)\n\
    // template<typename T>\n// T arithmetic_sequence_sum(T l, T r, T n) {\n//   \
    \  return (l+r)*n/2;\n// }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/numbers/arithmetic_sequence_sum.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/arithmetic_sequence_sum.hpp
layout: document
redirect_from:
- /library/src/numbers/arithmetic_sequence_sum.hpp
- /library/src/numbers/arithmetic_sequence_sum.hpp.html
title: src/numbers/arithmetic_sequence_sum.hpp
---
