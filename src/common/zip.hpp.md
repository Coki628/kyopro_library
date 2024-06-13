---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
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
    \ namespace std;\n#line 3 \"src/common/zip.hpp\"\n\ntemplate<typename T1, typename\
    \ T2>\npair<vector<T1>, vector<T2>> zip(const vector<pair<T1, T2>> &A) {\n   \
    \ int N = A.size();\n    pair<vector<T1>, vector<T2>> res = {vector<T1>(N), vector<T2>(N)};\n\
    \    rep(i, N) {\n        res.first[i] = A[i].first;\n        res.second[i] =\
    \ A[i].second;\n    }\n    return res;\n}\n\ntemplate<typename T1, typename T2,\
    \ typename T3>\ntuple<vector<T1>, vector<T2>, vector<T3>> zip(const vector<tuple<T1,\
    \ T2, T3>> &A) {\n    int N = A.size();\n    tuple<vector<T1>, vector<T2>, vector<T3>>\
    \ res = {\n        vector<T1>(N), vector<T2>(N), vector<T3>(N)\n    };\n    rep(i,\
    \ N) {\n        get<0>(res)[i] = get<0>(A[i]);\n        get<1>(res)[i] = get<1>(A[i]);\n\
    \        get<2>(res)[i] = get<2>(A[i]);\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename T1, typename\
    \ T2>\npair<vector<T1>, vector<T2>> zip(const vector<pair<T1, T2>> &A) {\n   \
    \ int N = A.size();\n    pair<vector<T1>, vector<T2>> res = {vector<T1>(N), vector<T2>(N)};\n\
    \    rep(i, N) {\n        res.first[i] = A[i].first;\n        res.second[i] =\
    \ A[i].second;\n    }\n    return res;\n}\n\ntemplate<typename T1, typename T2,\
    \ typename T3>\ntuple<vector<T1>, vector<T2>, vector<T3>> zip(const vector<tuple<T1,\
    \ T2, T3>> &A) {\n    int N = A.size();\n    tuple<vector<T1>, vector<T2>, vector<T3>>\
    \ res = {\n        vector<T1>(N), vector<T2>(N), vector<T3>(N)\n    };\n    rep(i,\
    \ N) {\n        get<0>(res)[i] = get<0>(A[i]);\n        get<1>(res)[i] = get<1>(A[i]);\n\
    \        get<2>(res)[i] = get<2>(A[i]);\n    }\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/zip.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/zip.hpp
layout: document
redirect_from:
- /library/src/common/zip.hpp
- /library/src/common/zip.hpp.html
title: src/common/zip.hpp
---
