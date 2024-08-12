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
    links:
    - https://atcoder.jp/contests/abc362/submissions/55563043
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 2 \"src/datastructure/hash_table.hpp\"\n\n#include <ext/pb_ds/assoc_container.hpp>\n\
    using namespace __gnu_pbds;\n\n// \u9AD8\u901F\u306A\u30CF\u30C3\u30B7\u30E5\u30C6\
    \u30FC\u30D6\u30EB\n// see: https://atcoder.jp/contests/abc362/submissions/55563043\n\
    template<typename Key, typename Val>\nusing hash_table = gp_hash_table<Key, Val>;\n\
    \n// \u5BA3\u8A00\n// hash_table<ll, ll> ht;\n// \u5B58\u5728\u30C1\u30A7\u30C3\
    \u30AF\n// ht.find(val) != ht.end()\n"
  code: "#include \"../base.hpp\"\n\n#include <ext/pb_ds/assoc_container.hpp>\nusing\
    \ namespace __gnu_pbds;\n\n// \u9AD8\u901F\u306A\u30CF\u30C3\u30B7\u30E5\u30C6\
    \u30FC\u30D6\u30EB\n// see: https://atcoder.jp/contests/abc362/submissions/55563043\n\
    template<typename Key, typename Val>\nusing hash_table = gp_hash_table<Key, Val>;\n\
    \n// \u5BA3\u8A00\n// hash_table<ll, ll> ht;\n// \u5B58\u5728\u30C1\u30A7\u30C3\
    \u30AF\n// ht.find(val) != ht.end()\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/hash_table.hpp
  requiredBy: []
  timestamp: '2024-08-12 17:44:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/hash_table.hpp
layout: document
redirect_from:
- /library/src/datastructure/hash_table.hpp
- /library/src/datastructure/hash_table.hpp.html
title: src/datastructure/hash_table.hpp
---
