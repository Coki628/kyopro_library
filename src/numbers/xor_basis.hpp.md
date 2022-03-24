---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/common/chmin.hpp\"\n\ntemplate<typename T>\n\
    bool chmin(T &x, T y) {\n    return (y < x) ? x = y, true : false;\n}\n#line 3\
    \ \"src/numbers/xor_basis.hpp\"\n\n// XOR\u57FA\u5E95\ntemplate<typename T>\n\
    vector<T> get_xor_basis(const vector<T> &A) {\n    vector<T> basis;\n    for (auto\
    \ a : A) {\n        for (auto b : basis) {\n            chmin(a, a^b);\n     \
    \   }\n        if (a > 0) basis.eb(a);\n    }\n    return basis;\n}\n"
  code: "#include \"../base.hpp\"\n#include \"../common/chmin.hpp\"\n\n// XOR\u57FA\
    \u5E95\ntemplate<typename T>\nvector<T> get_xor_basis(const vector<T> &A) {\n\
    \    vector<T> basis;\n    for (auto a : A) {\n        for (auto b : basis) {\n\
    \            chmin(a, a^b);\n        }\n        if (a > 0) basis.eb(a);\n    }\n\
    \    return basis;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/common/chmin.hpp
  isVerificationFile: false
  path: src/numbers/xor_basis.hpp
  requiredBy: []
  timestamp: '2022-03-24 12:02:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/xor_basis.hpp
layout: document
redirect_from:
- /library/src/numbers/xor_basis.hpp
- /library/src/numbers/xor_basis.hpp.html
title: src/numbers/xor_basis.hpp
---
