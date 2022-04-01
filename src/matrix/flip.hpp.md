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
    using namespace std;\n#line 2 \"src/matrix/flip.hpp\"\n\n// x = p \u3067\u53CD\
    \u8EE2\ntemplate<typename T>\nvector<vector<T>> flip_x(T p) {\n    const vector<vector<T>>\
    \ res = {\n        {-1, 0, 2*p},\n        {0, 1, 0},\n        {0, 0, 1},\n   \
    \ };\n    return res;\n}\n// y = p \u3067\u53CD\u8EE2\ntemplate<typename T>\n\
    vector<vector<T>> flip_y(T p) {\n    const vector<vector<T>> res = {\n       \
    \ {1, 0, 0},\n        {0, -1, 2*p},\n        {0, 0, 1},\n    };\n    return res;\n\
    }\n"
  code: "#include \"../base.hpp\"\n\n// x = p \u3067\u53CD\u8EE2\ntemplate<typename\
    \ T>\nvector<vector<T>> flip_x(T p) {\n    const vector<vector<T>> res = {\n \
    \       {-1, 0, 2*p},\n        {0, 1, 0},\n        {0, 0, 1},\n    };\n    return\
    \ res;\n}\n// y = p \u3067\u53CD\u8EE2\ntemplate<typename T>\nvector<vector<T>>\
    \ flip_y(T p) {\n    const vector<vector<T>> res = {\n        {1, 0, 0},\n   \
    \     {0, -1, 2*p},\n        {0, 0, 1},\n    };\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/matrix/flip.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/matrix/flip.hpp
layout: document
redirect_from:
- /library/src/matrix/flip.hpp
- /library/src/matrix/flip.hpp.html
title: src/matrix/flip.hpp
---
