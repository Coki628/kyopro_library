---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/grid/idtogrid.hpp
    title: src/grid/idtogrid.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/common/divmod.hpp\"\n\ntemplate<typename T>\n\
    pair<T, T> divmod(T a, T b) {\n    T d = a / b;\n    T m = a % b;\n    return\
    \ {d, m};\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename T>\npair<T, T>\
    \ divmod(T a, T b) {\n    T d = a / b;\n    T m = a % b;\n    return {d, m};\n\
    }\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/divmod.hpp
  requiredBy:
  - src/template.hpp
  - src/grid/idtogrid.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/divmod.hpp
layout: document
redirect_from:
- /library/src/common/divmod.hpp
- /library/src/common/divmod.hpp.html
title: src/common/divmod.hpp
---
