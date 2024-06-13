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
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/common/swap.hpp\"\n\n// \u5024\u914D\u5217\u3068\
    \u4F4D\u7F6E\u914D\u5217\u306E\u540C\u6642\u30B9\u30EF\u30C3\u30D7\n// ids[i]\
    \ := \u4F4D\u7F6Ei\u306B\u3042\u308B\u5024\n// pos[a] := \u5024a\u306E\u3042\u308B\
    \u4F4D\u7F6E\n// \u3068\u3057\u3066\u3001\u4F4D\u7F6Ei,j\u3092\u30B9\u30EF\u30C3\
    \u30D7\u3057\u305F\u6642\u306Eids,pos\u3092\u9069\u5207\u306B\u66F4\u65B0\u3059\
    \u308B\ntemplate<typename T>\nvoid swap(vector<T> &ids, vector<T> &pos, int i,\
    \ int j) {\n    swap(pos[ids[i]], pos[ids[j]]);\n    swap(ids[i], ids[j]);\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u5024\u914D\u5217\u3068\u4F4D\
    \u7F6E\u914D\u5217\u306E\u540C\u6642\u30B9\u30EF\u30C3\u30D7\n// ids[i] := \u4F4D\
    \u7F6Ei\u306B\u3042\u308B\u5024\n// pos[a] := \u5024a\u306E\u3042\u308B\u4F4D\u7F6E\
    \n// \u3068\u3057\u3066\u3001\u4F4D\u7F6Ei,j\u3092\u30B9\u30EF\u30C3\u30D7\u3057\
    \u305F\u6642\u306Eids,pos\u3092\u9069\u5207\u306B\u66F4\u65B0\u3059\u308B\ntemplate<typename\
    \ T>\nvoid swap(vector<T> &ids, vector<T> &pos, int i, int j) {\n    swap(pos[ids[i]],\
    \ pos[ids[j]]);\n    swap(ids[i], ids[j]);\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/swap.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/swap.hpp
layout: document
redirect_from:
- /library/src/common/swap.hpp
- /library/src/common/swap.hpp.html
title: src/common/swap.hpp
---
