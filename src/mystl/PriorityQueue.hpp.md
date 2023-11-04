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
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/mystl/PriorityQueue.hpp\"\n\ntemplate<typename\
    \ _Tp, typename _Sequence=vector<_Tp>, typename _Compare=less<typename _Sequence::value_type>>\n\
    struct PriorityQueue : priority_queue<_Tp, _Sequence, _Compare> {\n    using priority_queue<_Tp,\
    \ _Sequence, _Compare>::priority_queue;\n    _Tp pop() {\n        _Tp res = this->top();\n\
    \        priority_queue<_Tp, _Sequence, _Compare>::pop();\n        return res;\n\
    \    }\n};\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename _Tp, typename _Sequence=vector<_Tp>,\
    \ typename _Compare=less<typename _Sequence::value_type>>\nstruct PriorityQueue\
    \ : priority_queue<_Tp, _Sequence, _Compare> {\n    using priority_queue<_Tp,\
    \ _Sequence, _Compare>::priority_queue;\n    _Tp pop() {\n        _Tp res = this->top();\n\
    \        priority_queue<_Tp, _Sequence, _Compare>::pop();\n        return res;\n\
    \    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/mystl/PriorityQueue.hpp
  requiredBy: []
  timestamp: '2023-10-10 14:57:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/mystl/PriorityQueue.hpp
layout: document
redirect_from:
- /library/src/mystl/PriorityQueue.hpp
- /library/src/mystl/PriorityQueue.hpp.html
title: src/mystl/PriorityQueue.hpp
---
