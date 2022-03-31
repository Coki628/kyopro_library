---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
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
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"\
    src/common/Compress.hpp\"\n\n// \u5EA7\u6A19\u5727\u7E2E(\u4E8C\u5206\u63A2\u7D22\
    \u30D9\u30FC\u30B9)\ntemplate<typename T>\nstruct Compress {\n\n    int N;\n \
    \   vector<T> dat;\n\n    Compress(vector<T> A) {\n        sort(A.begin(), A.end());\n\
    \        A.erase(unique(A.begin(), A.end()), A.end());\n        N = A.size();\n\
    \        dat = A;\n    }\n\n    int zip(T x) {\n        return bisect_left(dat,\
    \ x);\n    }\n\n    T unzip(int x) {\n        return dat[x];\n    }\n\n    int\
    \ operator[](T x) {\n        return zip(x);\n    }\n\n    int size() {\n     \
    \   return dat.size();\n    }\n\n    vector<ll> zip(const vector<T> &A) {\n  \
    \      int M = A.size();\n        vector<ll> res(M);\n        rep(i, M) res[i]\
    \ = zip(A[i]);\n        return res;\n    }\n};\n\n// \u5EA7\u6A19\u5727\u7E2E\
    (map\u30D9\u30FC\u30B9)(\u65E7)\n// template<typename T>\n// pair<map<T, int>,\
    \ vector<T>> compress(vector<T> unzipped) {\n//     map<T, int> zipped;\n//  \
    \   sort(unzipped.begin(), unzipped.end());\n//     unzipped.erase(unique(unzipped.begin(),\
    \ unzipped.end()), unzipped.end());\n//     rep(i, unzipped.size()) {\n//    \
    \     zipped[unzipped[i]] = i;\n//     }\n//     return {zipped, unzipped};\n\
    // }\n"
  code: "#include \"../macros.hpp\"\n\n// \u5EA7\u6A19\u5727\u7E2E(\u4E8C\u5206\u63A2\
    \u7D22\u30D9\u30FC\u30B9)\ntemplate<typename T>\nstruct Compress {\n\n    int\
    \ N;\n    vector<T> dat;\n\n    Compress(vector<T> A) {\n        sort(A.begin(),\
    \ A.end());\n        A.erase(unique(A.begin(), A.end()), A.end());\n        N\
    \ = A.size();\n        dat = A;\n    }\n\n    int zip(T x) {\n        return bisect_left(dat,\
    \ x);\n    }\n\n    T unzip(int x) {\n        return dat[x];\n    }\n\n    int\
    \ operator[](T x) {\n        return zip(x);\n    }\n\n    int size() {\n     \
    \   return dat.size();\n    }\n\n    vector<ll> zip(const vector<T> &A) {\n  \
    \      int M = A.size();\n        vector<ll> res(M);\n        rep(i, M) res[i]\
    \ = zip(A[i]);\n        return res;\n    }\n};\n\n// \u5EA7\u6A19\u5727\u7E2E\
    (map\u30D9\u30FC\u30B9)(\u65E7)\n// template<typename T>\n// pair<map<T, int>,\
    \ vector<T>> compress(vector<T> unzipped) {\n//     map<T, int> zipped;\n//  \
    \   sort(unzipped.begin(), unzipped.end());\n//     unzipped.erase(unique(unzipped.begin(),\
    \ unzipped.end()), unzipped.end());\n//     rep(i, unzipped.size()) {\n//    \
    \     zipped[unzipped[i]] = i;\n//     }\n//     return {zipped, unzipped};\n\
    // }\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/Compress.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/Compress.hpp
layout: document
redirect_from:
- /library/src/common/Compress.hpp
- /library/src/common/Compress.hpp.html
title: src/common/Compress.hpp
---
