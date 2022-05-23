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
    using namespace std;\n#line 2 \"src/mystl/my_queue.hpp\"\n\ntemplate<typename\
    \ _Tp>\nstruct my_queue : queue<_Tp> {\n    using queue<_Tp>::queue;\n    _Tp\
    \ pop() {\n        _Tp res = this->front();\n        queue<_Tp>::pop();\n    \
    \    return res;\n    }\n};\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename _Tp>\nstruct my_queue : queue<_Tp>\
    \ {\n    using queue<_Tp>::queue;\n    _Tp pop() {\n        _Tp res = this->front();\n\
    \        queue<_Tp>::pop();\n        return res;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/mystl/my_queue.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/mystl/my_queue.hpp
layout: document
redirect_from:
- /library/src/mystl/my_queue.hpp
- /library/src/mystl/my_queue.hpp.html
title: src/mystl/my_queue.hpp
---
