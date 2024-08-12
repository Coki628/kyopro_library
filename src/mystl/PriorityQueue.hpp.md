---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
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
    \ namespace std;\n#line 3 \"src/mystl/PriorityQueue.hpp\"\n\ntemplate<typename\
    \ _Tp, typename _Sequence = vector<_Tp>, typename _Compare = less<typename _Sequence::value_type>>\n\
    struct PriorityQueue : priority_queue<_Tp, _Sequence, _Compare> {\n    using priority_queue<_Tp,\
    \ _Sequence, _Compare>::priority_queue;\n    _Tp pop() {\n        _Tp res = this->top();\n\
    \        priority_queue<_Tp, _Sequence, _Compare>::pop();\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename _Tp, typename\
    \ _Sequence = vector<_Tp>, typename _Compare = less<typename _Sequence::value_type>>\n\
    struct PriorityQueue : priority_queue<_Tp, _Sequence, _Compare> {\n    using priority_queue<_Tp,\
    \ _Sequence, _Compare>::priority_queue;\n    _Tp pop() {\n        _Tp res = this->top();\n\
    \        priority_queue<_Tp, _Sequence, _Compare>::pop();\n        return res;\n\
    \    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/mystl/PriorityQueue.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/mystl/PriorityQueue.hpp
layout: document
redirect_from:
- /library/src/mystl/PriorityQueue.hpp
- /library/src/mystl/PriorityQueue.hpp.html
title: src/mystl/PriorityQueue.hpp
---