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
    \ namespace std;\n#line 3 \"src/datastructure/SuccinctIndexableDictionary.hpp\"\
    \n\n// \u5B8C\u5099\u8F9E\u66F8(Wavelet Matrix\u3068\u30BB\u30C3\u30C8\u3067\u4F7F\
    \u3046)\nstruct SuccinctIndexableDictionary {\n    size_t length;\n    size_t\
    \ blocks;\n    vector<unsigned> bit, sum;\n\n    SuccinctIndexableDictionary()\
    \ = default;\n\n    SuccinctIndexableDictionary(size_t length)\n        : length(length),\n\
    \          blocks((length + 31) >> 5) {\n        bit.assign(blocks, 0U);\n   \
    \     sum.assign(blocks, 0U);\n    }\n\n    void set(int k) {\n        bit[k >>\
    \ 5] |= 1U << (k & 31);\n    }\n\n    void build() {\n        sum[0] = 0U;\n \
    \       for (int i = 1; i < blocks; i++) {\n            sum[i] = sum[i - 1] +\
    \ __builtin_popcount(bit[i - 1]);\n        }\n    }\n\n    bool operator[](int\
    \ k) {\n        return (bool((bit[k >> 5] >> (k & 31)) & 1));\n    }\n\n    int\
    \ rank(int k) {\n        return (\n            sum[k >> 5] +\n            __builtin_popcount(bit[k\
    \ >> 5] & ((1U << (k & 31)) - 1))\n        );\n    }\n\n    int rank(bool val,\
    \ int k) {\n        return (val ? rank(k) : k - rank(k));\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u5B8C\u5099\u8F9E\u66F8(Wavelet\
    \ Matrix\u3068\u30BB\u30C3\u30C8\u3067\u4F7F\u3046)\nstruct SuccinctIndexableDictionary\
    \ {\n    size_t length;\n    size_t blocks;\n    vector<unsigned> bit, sum;\n\n\
    \    SuccinctIndexableDictionary() = default;\n\n    SuccinctIndexableDictionary(size_t\
    \ length)\n        : length(length),\n          blocks((length + 31) >> 5) {\n\
    \        bit.assign(blocks, 0U);\n        sum.assign(blocks, 0U);\n    }\n\n \
    \   void set(int k) {\n        bit[k >> 5] |= 1U << (k & 31);\n    }\n\n    void\
    \ build() {\n        sum[0] = 0U;\n        for (int i = 1; i < blocks; i++) {\n\
    \            sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n        }\n\
    \    }\n\n    bool operator[](int k) {\n        return (bool((bit[k >> 5] >> (k\
    \ & 31)) & 1));\n    }\n\n    int rank(int k) {\n        return (\n          \
    \  sum[k >> 5] +\n            __builtin_popcount(bit[k >> 5] & ((1U << (k & 31))\
    \ - 1))\n        );\n    }\n\n    int rank(bool val, int k) {\n        return\
    \ (val ? rank(k) : k - rank(k));\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/SuccinctIndexableDictionary.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/SuccinctIndexableDictionary.hpp
layout: document
redirect_from:
- /library/src/datastructure/SuccinctIndexableDictionary.hpp
- /library/src/datastructure/SuccinctIndexableDictionary.hpp.html
title: src/datastructure/SuccinctIndexableDictionary.hpp
---