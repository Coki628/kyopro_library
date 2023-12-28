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
    using namespace std;\n#line 3 \"src/mystl/Queue.hpp\"\n\ntemplate<typename _Tp>\n\
    struct Queue : queue<_Tp> {\n    using queue<_Tp>::queue;\n    _Tp pop() {\n \
    \       _Tp res = this->front();\n        queue<_Tp>::pop();\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename _Tp>\nstruct\
    \ Queue : queue<_Tp> {\n    using queue<_Tp>::queue;\n    _Tp pop() {\n      \
    \  _Tp res = this->front();\n        queue<_Tp>::pop();\n        return res;\n\
    \    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/mystl/Queue.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/mystl/Queue.hpp
layout: document
redirect_from:
- /library/src/mystl/Queue.hpp
- /library/src/mystl/Queue.hpp.html
title: src/mystl/Queue.hpp
---
