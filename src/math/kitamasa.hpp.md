---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://outline.hatenadiary.jp/entry/2020/07/02/205628
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/math/kitamasa.hpp\"\n\n// \u304D\u305F\u307E\
    \u3055\u6CD5\n// \u53C2\u8003\uFF1Ahttps://outline.hatenadiary.jp/entry/2020/07/02/205628\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u884C\u5217\u7D2F\u4E57\u3060\u3068N^3logK\u304B\
    \u304B\u308B\u3082\u306E\u3092N^2logK\u3067\u51E6\u7406\u3067\u304D\u308B\u3002\
    \n// \u30FB\u5236\u9650\u3068\u3057\u3066\u3001\u5F53\u7136\u3069\u3093\u306A\u884C\
    \u5217\u3067\u3082\u51FA\u6765\u308B\u8A33\u3058\u3083\u306A\u304F\u3066\u3001\
    \u6F38\u5316\u5F0FN\u672C\u306E\u884C\u5217\u7D2F\u4E57\u307F\u305F\u3044\u306E\
    \u306F\u7121\u7406\u3067\u3001\n// \u3000N\u9805\u9593\u6F38\u5316\u5F0F1\u672C\
    \u307F\u305F\u3044\u306A\u5F62\u306E\u6642\u3060\u3051\u3067\u304D\u308B\u3002\
    (\u591A\u5206)\n// \u30FB\u5F15\u6570\u306B\u306F\u6700\u521D\u306EN-1\u9805\u3068\
    \u3001\u9077\u79FB\u306E\u6642\u306B\u4F7F\u3046N-1\u9805\u306E\u4FC2\u6570\u3092\
    \u6E21\u3059\u3002\ntemplate<typename T>\nstruct Kitamasa {\n    vector<T> a;\
    \ // \u521D\u671F\u5024\u30D9\u30AF\u30C8\u30EB\n    vector<T> d; // \u4FC2\u6570\
    \u30D9\u30AF\u30C8\u30EB\n    int k;\n\n    Kitamasa(vector<T> &a, vector<T> &d)\
    \ : a(a), d(d), k((int)a.size()) {\n    }\n\n    // a_n \u306E\u4FC2\u6570\u30D9\
    \u30AF\u30C8\u30EB\u3092\u6C42\u3081\u308B\n    vector<T> dfs(int64_t n) {\n \
    \       if (n == k) return d;\n\n        vector<T> res(k);\n        if (n & 1\
    \ || n < k * 2) {\n            vector<T> x = dfs(n - 1);\n            for (int\
    \ i = 0; i < k; ++i) res[i] = d[i] * x[k - 1];\n            for (int i = 0; i\
    \ + 1 < k; ++i) res[i + 1] += x[i];\n        } else {\n            vector<vector<T>>\
    \ x(k, vector<T>(k));\n            x[0] = dfs(n >> 1);\n            for (int i\
    \ = 0; i + 1 < k; ++i) {\n                for (int j = 0; j < k; ++j) x[i + 1][j]\
    \ = d[j] * x[i][k - 1];\n                for (int j = 0; j + 1 < k; ++j) x[i +\
    \ 1][j + 1] += x[i][j];\n            }\n            for (int i = 0; i < k; ++i)\
    \ {\n                for (int j = 0; j < k; ++j) {\n                    res[j]\
    \ += x[0][i] * x[i][j];\n                }\n            }\n        }\n\n     \
    \   return res;\n    }\n\n    // a_n \u3092\u6C42\u3081\u308B\n    T calc(int64_t\
    \ n) {\n        if (n < k) return a[n];\n        vector<T> x = dfs(n);\n     \
    \   T res = 0;\n        for (int i = 0; i < k; ++i) res += x[i] * a[i];\n    \
    \    return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u304D\u305F\u307E\u3055\u6CD5\
    \n// \u53C2\u8003\uFF1Ahttps://outline.hatenadiary.jp/entry/2020/07/02/205628\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u884C\u5217\u7D2F\u4E57\u3060\u3068N^3logK\u304B\
    \u304B\u308B\u3082\u306E\u3092N^2logK\u3067\u51E6\u7406\u3067\u304D\u308B\u3002\
    \n// \u30FB\u5236\u9650\u3068\u3057\u3066\u3001\u5F53\u7136\u3069\u3093\u306A\u884C\
    \u5217\u3067\u3082\u51FA\u6765\u308B\u8A33\u3058\u3083\u306A\u304F\u3066\u3001\
    \u6F38\u5316\u5F0FN\u672C\u306E\u884C\u5217\u7D2F\u4E57\u307F\u305F\u3044\u306E\
    \u306F\u7121\u7406\u3067\u3001\n// \u3000N\u9805\u9593\u6F38\u5316\u5F0F1\u672C\
    \u307F\u305F\u3044\u306A\u5F62\u306E\u6642\u3060\u3051\u3067\u304D\u308B\u3002\
    (\u591A\u5206)\n// \u30FB\u5F15\u6570\u306B\u306F\u6700\u521D\u306EN-1\u9805\u3068\
    \u3001\u9077\u79FB\u306E\u6642\u306B\u4F7F\u3046N-1\u9805\u306E\u4FC2\u6570\u3092\
    \u6E21\u3059\u3002\ntemplate<typename T>\nstruct Kitamasa {\n    vector<T> a;\
    \ // \u521D\u671F\u5024\u30D9\u30AF\u30C8\u30EB\n    vector<T> d; // \u4FC2\u6570\
    \u30D9\u30AF\u30C8\u30EB\n    int k;\n\n    Kitamasa(vector<T> &a, vector<T> &d)\
    \ : a(a), d(d), k((int)a.size()) {\n    }\n\n    // a_n \u306E\u4FC2\u6570\u30D9\
    \u30AF\u30C8\u30EB\u3092\u6C42\u3081\u308B\n    vector<T> dfs(int64_t n) {\n \
    \       if (n == k) return d;\n\n        vector<T> res(k);\n        if (n & 1\
    \ || n < k * 2) {\n            vector<T> x = dfs(n - 1);\n            for (int\
    \ i = 0; i < k; ++i) res[i] = d[i] * x[k - 1];\n            for (int i = 0; i\
    \ + 1 < k; ++i) res[i + 1] += x[i];\n        } else {\n            vector<vector<T>>\
    \ x(k, vector<T>(k));\n            x[0] = dfs(n >> 1);\n            for (int i\
    \ = 0; i + 1 < k; ++i) {\n                for (int j = 0; j < k; ++j) x[i + 1][j]\
    \ = d[j] * x[i][k - 1];\n                for (int j = 0; j + 1 < k; ++j) x[i +\
    \ 1][j + 1] += x[i][j];\n            }\n            for (int i = 0; i < k; ++i)\
    \ {\n                for (int j = 0; j < k; ++j) {\n                    res[j]\
    \ += x[0][i] * x[i][j];\n                }\n            }\n        }\n\n     \
    \   return res;\n    }\n\n    // a_n \u3092\u6C42\u3081\u308B\n    T calc(int64_t\
    \ n) {\n        if (n < k) return a[n];\n        vector<T> x = dfs(n);\n     \
    \   T res = 0;\n        for (int i = 0; i < k; ++i) res += x[i] * a[i];\n    \
    \    return res;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/math/kitamasa.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/kitamasa.hpp
layout: document
redirect_from:
- /library/src/math/kitamasa.hpp
- /library/src/math/kitamasa.hpp.html
title: src/math/kitamasa.hpp
---
