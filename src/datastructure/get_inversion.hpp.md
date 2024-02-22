---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/Compress.hpp
    title: src/common/Compress.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/bisect.hpp
    title: src/common/bisect.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
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
    \ }\n//     return {zipped, unzipped};\n// }\n#line 4 \"src/datastructure/get_inversion.hpp\"\
    \n\n// \u8EE2\u5012\u6570\u53D6\u5F97\nll get_inversion(vector<ll> A, bool comp\
    \ = true) {\n    int M = A.size();\n    if (comp) {\n        Compress<ll> cp(A);\n\
    \        A = cp.zip(A);\n        M = cp.size();\n    }\n    BIT<ll> bit(M);\n\
    \    ll res = 0;\n    for (auto a : A) {\n        res += bit.query(a + 1, M);\n\
    \        bit.add(a, 1);\n    }\n    return res;\n}\n\n// \u30DE\u30FC\u30B8\u30BD\
    \u30FC\u30C8\u306B\u3088\u308B\u8EE2\u5012\u6570\u53D6\u5F97\n// \u30FB\u5EA7\u5727\
    BIT\u3088\u308A\u901F\u3044\u3051\u3069\u3001\u53C2\u7167\u6E21\u3057\u3084\u3081\
    \u308B\u3068\u30D0\u30B0\u308B\u306E\u3067\u3001\n// \u3000\u5143\u306E\u5217\u3082\
    \u307E\u3060\u4F7F\u3046\u5834\u5408\u306F\u30B3\u30D4\u30FC\u3057\u3066\u304B\
    \u3089\u3084\u308B\u3053\u3068\u3002\n// \u30FB\u5EA7\u5727\u3092\u4E8C\u5206\u63A2\
    \u7D22\u30D9\u30FC\u30B9\u306B\u3057\u3066\u304B\u3089\u307E\u3060\u901F\u5EA6\
    \u6BD4\u8F03\u3057\u3066\u306A\u3044\u306E\u3067\u3001\n// \u3000\u3082\u3057\u304B\
    \u3057\u305F\u3089\u305D\u3063\u3061\u306E\u5EA7\u5727\u7248\u3060\u3063\u305F\
    \u3089\u5927\u5DEE\u306A\u3044\u304B\u3082\u3002\n// ll get_inversion(vector<ll>\
    \ &a) {\n//     int n = a.size();\n//     if (n <= 1) {\n//         return 0;\n\
    //     }\n\n//     ll cnt = 0;\n//     vector<ll> b(a.begin(), a.begin() + n /\
    \ 2);\n//     vector<ll> c(a.begin() + n / 2, a.end());\n\n//     cnt += get_inversion(b);\n\
    //     cnt += get_inversion(c);\n\n//     int ai = 0, bi = 0, ci = 0;\n//    \
    \ // merge\u306E\u51E6\u7406\n//     while (ai < n) {\n//         if (bi < b.size()\
    \ && (ci == c.size() || b[bi] <= c[ci])) {\n//             a[ai++] = b[bi++];\n\
    //         } else {\n//             cnt += n / 2 - bi;\n//             a[ai++]\
    \ = c[ci++];\n//         }\n//     }\n//     return cnt;\n// }\n"
  code: "#pragma once\n#include \"../common/Compress.hpp\"\n#include \"../macros.hpp\"\
    \n\n// \u8EE2\u5012\u6570\u53D6\u5F97\nll get_inversion(vector<ll> A, bool comp\
    \ = true) {\n    int M = A.size();\n    if (comp) {\n        Compress<ll> cp(A);\n\
    \        A = cp.zip(A);\n        M = cp.size();\n    }\n    BIT<ll> bit(M);\n\
    \    ll res = 0;\n    for (auto a : A) {\n        res += bit.query(a + 1, M);\n\
    \        bit.add(a, 1);\n    }\n    return res;\n}\n\n// \u30DE\u30FC\u30B8\u30BD\
    \u30FC\u30C8\u306B\u3088\u308B\u8EE2\u5012\u6570\u53D6\u5F97\n// \u30FB\u5EA7\u5727\
    BIT\u3088\u308A\u901F\u3044\u3051\u3069\u3001\u53C2\u7167\u6E21\u3057\u3084\u3081\
    \u308B\u3068\u30D0\u30B0\u308B\u306E\u3067\u3001\n// \u3000\u5143\u306E\u5217\u3082\
    \u307E\u3060\u4F7F\u3046\u5834\u5408\u306F\u30B3\u30D4\u30FC\u3057\u3066\u304B\
    \u3089\u3084\u308B\u3053\u3068\u3002\n// \u30FB\u5EA7\u5727\u3092\u4E8C\u5206\u63A2\
    \u7D22\u30D9\u30FC\u30B9\u306B\u3057\u3066\u304B\u3089\u307E\u3060\u901F\u5EA6\
    \u6BD4\u8F03\u3057\u3066\u306A\u3044\u306E\u3067\u3001\n// \u3000\u3082\u3057\u304B\
    \u3057\u305F\u3089\u305D\u3063\u3061\u306E\u5EA7\u5727\u7248\u3060\u3063\u305F\
    \u3089\u5927\u5DEE\u306A\u3044\u304B\u3082\u3002\n// ll get_inversion(vector<ll>\
    \ &a) {\n//     int n = a.size();\n//     if (n <= 1) {\n//         return 0;\n\
    //     }\n\n//     ll cnt = 0;\n//     vector<ll> b(a.begin(), a.begin() + n /\
    \ 2);\n//     vector<ll> c(a.begin() + n / 2, a.end());\n\n//     cnt += get_inversion(b);\n\
    //     cnt += get_inversion(c);\n\n//     int ai = 0, bi = 0, ci = 0;\n//    \
    \ // merge\u306E\u51E6\u7406\n//     while (ai < n) {\n//         if (bi < b.size()\
    \ && (ci == c.size() || b[bi] <= c[ci])) {\n//             a[ai++] = b[bi++];\n\
    //         } else {\n//             cnt += n / 2 - bi;\n//             a[ai++]\
    \ = c[ci++];\n//         }\n//     }\n//     return cnt;\n// }\n"
  dependsOn:
  - src/common/Compress.hpp
  - src/common/bisect.hpp
  - src/base.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/datastructure/get_inversion.hpp
  requiredBy: []
  timestamp: '2024-02-22 17:15:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/get_inversion.hpp
layout: document
redirect_from:
- /library/src/datastructure/get_inversion.hpp
- /library/src/datastructure/get_inversion.hpp.html
title: src/datastructure/get_inversion.hpp
---
