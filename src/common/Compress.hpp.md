---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/bisect.hpp
    title: src/common/bisect.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/datastructure/get_inversion.hpp
    title: src/datastructure/get_inversion.hpp
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
    using namespace std;\n#line 3 \"src/common/bisect.hpp\"\n\ntemplate<typename T>\n\
    int bisect_left(const vector<T> &A, T val, int lo = 0) {\n    return lower_bound(A.begin()\
    \ + lo, A.end(), val) - A.begin();\n}\n\ntemplate<typename T>\nint bisect_right(const\
    \ vector<T> &A, T val, int lo = 0) {\n    return upper_bound(A.begin() + lo, A.end(),\
    \ val) - A.begin();\n}\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll,\
    \ ll>;\nusing pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\nusing vvl = vv<ll>;\n\
    using vvi = vv<int>;\nusing vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil\
    \ = vv<pil>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa\
    \ = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n\
    #define rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb)\
    \ or (c < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a);\
    \ i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/common/Compress.hpp\"\
    \n\n// \u5EA7\u6A19\u5727\u7E2E(\u4E8C\u5206\u63A2\u7D22\u30D9\u30FC\u30B9)\n\
    template<typename T>\nstruct Compress {\n    int N;\n    vector<T> dat;\n    bool\
    \ built = false;\n\n    Compress() {}\n\n    Compress(const vector<T> &A) : dat(A)\
    \ {\n        build();\n    }\n\n    void build() {\n        sort(dat.begin(),\
    \ dat.end());\n        dat.erase(unique(dat.begin(), dat.end()), dat.end());\n\
    \        N = dat.size();\n        built = true;\n    }\n\n    void add(T x) {\n\
    \        assert(not built);\n        dat.eb(x);\n    }\n\n    // \u53EF\u5909\u9577\
    \u5F15\u6570\u3001cp.add(l, r); \u3068\u304B\u3067\u304D\u308B\n    template<typename...\
    \ Ts>\n    void add(const T val, Ts... ts) {\n        dat.eb(val);\n        if\
    \ constexpr (sizeof...(Ts) > 0) {\n            add(ts...);\n        }\n    }\n\
    \n    void add(const vector<T> &A) {\n        for (auto a : A) {\n           \
    \ add(a);\n        }\n    }\n\n    int zip(T x) {\n        assert(built);\n  \
    \      return bisect_left(dat, x);\n    }\n\n    T unzip(int x) {\n        assert(built);\n\
    \        return dat[x];\n    }\n\n    int operator[](T x) {\n        return zip(x);\n\
    \    }\n\n    int size() {\n        assert(built);\n        return dat.size();\n\
    \    }\n\n    vector<ll> zip(const vector<T> &A) {\n        int M = A.size();\n\
    \        vector<ll> res(M);\n        rep(i, M) res[i] = zip(A[i]);\n        return\
    \ res;\n    }\n};\n\n// \u5EA7\u6A19\u5727\u7E2E(map\u30D9\u30FC\u30B9)(\u65E7\
    )\n// template<typename T>\n// pair<map<T, int>, vector<T>> compress(vector<T>\
    \ unzipped) {\n//     map<T, int> zipped;\n//     sort(unzipped.begin(), unzipped.end());\n\
    //     unzipped.erase(unique(unzipped.begin(), unzipped.end()), unzipped.end());\n\
    //     rep(i, unzipped.size()) {\n//         zipped[unzipped[i]] = i;\n//    \
    \ }\n//     return {zipped, unzipped};\n// }\n"
  code: "#pragma once\n#include \"../common/bisect.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u5EA7\u6A19\u5727\u7E2E(\u4E8C\u5206\u63A2\u7D22\u30D9\u30FC\u30B9)\n\
    template<typename T>\nstruct Compress {\n    int N;\n    vector<T> dat;\n    bool\
    \ built = false;\n\n    Compress() {}\n\n    Compress(const vector<T> &A) : dat(A)\
    \ {\n        build();\n    }\n\n    void build() {\n        sort(dat.begin(),\
    \ dat.end());\n        dat.erase(unique(dat.begin(), dat.end()), dat.end());\n\
    \        N = dat.size();\n        built = true;\n    }\n\n    void add(T x) {\n\
    \        assert(not built);\n        dat.eb(x);\n    }\n\n    // \u53EF\u5909\u9577\
    \u5F15\u6570\u3001cp.add(l, r); \u3068\u304B\u3067\u304D\u308B\n    template<typename...\
    \ Ts>\n    void add(const T val, Ts... ts) {\n        dat.eb(val);\n        if\
    \ constexpr (sizeof...(Ts) > 0) {\n            add(ts...);\n        }\n    }\n\
    \n    void add(const vector<T> &A) {\n        for (auto a : A) {\n           \
    \ add(a);\n        }\n    }\n\n    int zip(T x) {\n        assert(built);\n  \
    \      return bisect_left(dat, x);\n    }\n\n    T unzip(int x) {\n        assert(built);\n\
    \        return dat[x];\n    }\n\n    int operator[](T x) {\n        return zip(x);\n\
    \    }\n\n    int size() {\n        assert(built);\n        return dat.size();\n\
    \    }\n\n    vector<ll> zip(const vector<T> &A) {\n        int M = A.size();\n\
    \        vector<ll> res(M);\n        rep(i, M) res[i] = zip(A[i]);\n        return\
    \ res;\n    }\n};\n\n// \u5EA7\u6A19\u5727\u7E2E(map\u30D9\u30FC\u30B9)(\u65E7\
    )\n// template<typename T>\n// pair<map<T, int>, vector<T>> compress(vector<T>\
    \ unzipped) {\n//     map<T, int> zipped;\n//     sort(unzipped.begin(), unzipped.end());\n\
    //     unzipped.erase(unique(unzipped.begin(), unzipped.end()), unzipped.end());\n\
    //     rep(i, unzipped.size()) {\n//         zipped[unzipped[i]] = i;\n//    \
    \ }\n//     return {zipped, unzipped};\n// }\n"
  dependsOn:
  - src/common/bisect.hpp
  - src/base.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/common/Compress.hpp
  requiredBy:
  - src/datastructure/get_inversion.hpp
  - src/template.hpp
  timestamp: '2024-02-22 17:15:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/common/Compress.hpp
layout: document
redirect_from:
- /library/src/common/Compress.hpp
- /library/src/common/Compress.hpp.html
title: src/common/Compress.hpp
---
