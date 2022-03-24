---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':x:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/common/sorted.hpp\"\n\ntemplate<typename T>\n\
    vector<T> sorted(vector<T> A, bool reverse=false) {\n    sort(ALL(A));\n    if\
    \ (reverse) std::reverse(ALL(A));\n    return A;\n}\n\nstring sorted(string S,\
    \ bool reverse=false) {\n    sort(ALL(S));\n    if (reverse) std::reverse(ALL(S));\n\
    \    return S;\n}\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename T>\nvector<T> sorted(vector<T>\
    \ A, bool reverse=false) {\n    sort(ALL(A));\n    if (reverse) std::reverse(ALL(A));\n\
    \    return A;\n}\n\nstring sorted(string S, bool reverse=false) {\n    sort(ALL(S));\n\
    \    if (reverse) std::reverse(ALL(S));\n    return S;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/sorted.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/sorted.hpp
layout: document
redirect_from:
- /library/src/common/sorted.hpp
- /library/src/common/sorted.hpp.html
title: src/common/sorted.hpp
---
