---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/numbers/factorize.hpp\"\n\n// \u7D20\u56E0\
    \u6570\u5206\u89E3(vector\u30D9\u30FC\u30B9)\ntemplate<typename T>\nvector<pair<T,\
    \ int>> factorize(T n) {\n    vector<pair<T, int>> ret;\n    for (T i=2; i*i<=n;\
    \ i++) {\n        int cnt = 0;\n        while (n % i == 0) {\n            n /=\
    \ i;\n            cnt++;\n        }\n        if (cnt) ret.emplace_back(i, cnt);\n\
    \    }\n    if (n > 1) ret.emplace_back(n, 1);\n    return ret;\n}\n"
  code: "#include \"../base.hpp\"\n\n// \u7D20\u56E0\u6570\u5206\u89E3(vector\u30D9\
    \u30FC\u30B9)\ntemplate<typename T>\nvector<pair<T, int>> factorize(T n) {\n \
    \   vector<pair<T, int>> ret;\n    for (T i=2; i*i<=n; i++) {\n        int cnt\
    \ = 0;\n        while (n % i == 0) {\n            n /= i;\n            cnt++;\n\
    \        }\n        if (cnt) ret.emplace_back(i, cnt);\n    }\n    if (n > 1)\
    \ ret.emplace_back(n, 1);\n    return ret;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/numbers/factorize.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/numbers/factorize.hpp
layout: document
redirect_from:
- /library/src/numbers/factorize.hpp
- /library/src/numbers/factorize.hpp.html
title: src/numbers/factorize.hpp
---
