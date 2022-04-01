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
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/common/zip.hpp\"\n\ntemplate<typename T1,\
    \ typename T2>\npair<vector<T1>, vector<T2>> zip(const vector<pair<T1, T2>> &A)\
    \ {\n    int N = A.size();\n    pair<vector<T1>, vector<T2>> res = {vector<T1>(N),\
    \ vector<T2>(N)};\n    rep(i, N) {\n        res.first[i] = A[i].first;\n     \
    \   res.second[i] = A[i].second;\n    }\n    return res;\n}\n\ntemplate<typename\
    \ T1, typename T2, typename T3>\ntuple<vector<T1>, vector<T2>, vector<T3>> zip(const\
    \ vector<tuple<T1, T2, T3>> &A) {\n    int N = A.size();\n    tuple<vector<T1>,\
    \ vector<T2>, vector<T3>> res = {vector<T1>(N), vector<T2>(N), vector<T3>(N)};\n\
    \    rep(i, N) {\n        get<0>(res)[i] = get<0>(A[i]);\n        get<1>(res)[i]\
    \ = get<1>(A[i]);\n        get<2>(res)[i] = get<2>(A[i]);\n    }\n    return res;\n\
    }\n"
  code: "#include \"../base.hpp\"\n\ntemplate<typename T1, typename T2>\npair<vector<T1>,\
    \ vector<T2>> zip(const vector<pair<T1, T2>> &A) {\n    int N = A.size();\n  \
    \  pair<vector<T1>, vector<T2>> res = {vector<T1>(N), vector<T2>(N)};\n    rep(i,\
    \ N) {\n        res.first[i] = A[i].first;\n        res.second[i] = A[i].second;\n\
    \    }\n    return res;\n}\n\ntemplate<typename T1, typename T2, typename T3>\n\
    tuple<vector<T1>, vector<T2>, vector<T3>> zip(const vector<tuple<T1, T2, T3>>\
    \ &A) {\n    int N = A.size();\n    tuple<vector<T1>, vector<T2>, vector<T3>>\
    \ res = {vector<T1>(N), vector<T2>(N), vector<T3>(N)};\n    rep(i, N) {\n    \
    \    get<0>(res)[i] = get<0>(A[i]);\n        get<1>(res)[i] = get<1>(A[i]);\n\
    \        get<2>(res)[i] = get<2>(A[i]);\n    }\n    return res;\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/common/zip.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/zip.hpp
layout: document
redirect_from:
- /library/src/common/zip.hpp
- /library/src/common/zip.hpp.html
title: src/common/zip.hpp
---
