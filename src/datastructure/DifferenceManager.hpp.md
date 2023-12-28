---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
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
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/DifferenceManager.hpp\"\
    \n\n// \u5DEE\u5206\u5217\u7BA1\u7406\n// \u30FB\u3053\u3069\u3075\u3049\u3067\
    \u305F\u307E\u306B\u51FA\u308Bmultiset\u3067\u3053\u306D\u3053\u306D\u3059\u308B\
    \u3060\u308B\u3044\u3084\u3064\u3002\n// \u4ED5\u69D8\u8AAC\u660E\n// \u30FB\u73FE\
    \u5728\u306E\u8981\u7D20\u3092\u8868\u3059\u96C6\u5408\u3068\u3001\u305D\u308C\
    \u3089\u306E(\u30BD\u30FC\u30C8\u6E08\u3060\u3068\u3057\u3066)\u96A3\u63A5\u3068\
    \u306E\u5DEE\u5206\u5217\u306E\u96C6\u5408\u3092\u7BA1\u7406\u3059\u308B\u3002\
    \n// \u30FB\u4E0A\u8A18\u306B\u5BFE\u3059\u308B\u3001\u8981\u7D20\u8FFD\u52A0\u30FB\
    \u8981\u7D20\u524A\u9664\u30FB\u6700\u5927\u5024\u53D6\u5F97\u30FB\u6700\u5C0F\
    \u5024\u53D6\u5F97\u304C\u3067\u304D\u308B\u3002\n// \u30FB\u4E2D\u8EAB\u306F\
    multiset\u306A\u306E\u3067\u3001\u4F5C\u3063\u3066\u306A\u3044\u3051\u3069\u500B\
    \u6570\u3068\u304B\u3082\u53D6\u308C\u308B\u3068\u601D\u3046\u3002\n// \u30FB\u9045\
    \u304F\u306A\u3089\u306A\u304B\u3063\u305F\u306E\u3067\u62BD\u8C61\u5316\u3057\
    \u305F\u3002\u3053\u308C\u3067\u5DEE\u5206XOR\u3068\u304B\u5DEE\u5206GCD\u3068\
    \u304B\u3067\u3082\u3067\u304D\u308B\u3002\ntemplate<typename T, typename F>\n\
    struct DifferenceManager {\n    // se1: \u73FE\u5728\u306E\u8981\u7D20\u3092\u8868\
    \u3059\u96C6\u5408\n    // se2: \u73FE\u5728\u306E\u5DEE\u5206\u5217\u306E\u8981\
    \u7D20\u3092\u8868\u3059\u96C6\u5408\n    multiset<T> se1, se2;\n\n    const F\
    \ f;\n\n    DifferenceManager(const vector<T> &A, const F &f) : se1(ALL(A)), f(f)\
    \ {\n        build();\n    }\n\n    void build() {\n        auto itr = se1.begin();\n\
    \        while (itr != se1.end() and itr != --se1.end()) {\n            se2.insert(f(*next(itr),\
    \ *itr));\n            itr++;\n        }\n    }\n\n    void insert(T x) {\n  \
    \      auto itr = se1.insert(x);\n        if (itr != se1.begin() and itr != --se1.end())\
    \ {\n            se2.erase(se2.find(f(*next(itr), *prev(itr))));\n        }\n\
    \        if (itr != se1.begin()) {\n            se2.insert(f(*itr, *prev(itr)));\n\
    \        }\n        if (itr != --se1.end()) {\n            se2.insert(f(*next(itr),\
    \ *itr));\n        }\n    }\n\n    void erase(T x) {\n        auto itr = se1.find(x);\n\
    \        assert(itr != se1.end());\n        if (itr != se1.begin()) {\n      \
    \      se2.erase(se2.find(f(*itr, *prev(itr))));\n        }\n        if (itr !=\
    \ --se1.end()) {\n            se2.erase(se2.find(f(*next(itr), *itr)));\n    \
    \    }\n        if (itr != se1.begin() and itr != --se1.end()) {\n           \
    \ se2.insert(f(*next(itr), *prev(itr)));\n        }\n        se1.erase(itr);\n\
    \    }\n\n    int size() {\n        return se1.size();\n    }\n\n    T max_val()\
    \ {\n        assert(size() >= 1);\n        return *--se1.end();\n    }\n\n   \
    \ T min_val() {\n        assert(size() >= 1);\n        return *se1.begin();\n\
    \    }\n\n    T max_diff() {\n        assert(size() >= 2);\n        return *--se2.end();\n\
    \    }\n\n    T min_diff() {\n        assert(size() >= 2);\n        return *se2.begin();\n\
    \    }\n};\n\ntemplate<typename T, typename F>\nDifferenceManager<T, F> get_difference_manager(const\
    \ vector<T> &A, const F &f) {\n    return {A, f};\n}\n\ntemplate<typename T>\n\
    auto get_difference_manager(const vector<T> &A) {\n    // \u57FA\u672C\u306F\u3053\
    \u308C\u3092\u6E21\u3059\n    const auto f = [](T a, T b) { return a - b; };\n\
    \    return DifferenceManager<T, decltype(f)>(A, f);\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u5DEE\u5206\u5217\u7BA1\u7406\
    \n// \u30FB\u3053\u3069\u3075\u3049\u3067\u305F\u307E\u306B\u51FA\u308Bmultiset\u3067\
    \u3053\u306D\u3053\u306D\u3059\u308B\u3060\u308B\u3044\u3084\u3064\u3002\n// \u4ED5\
    \u69D8\u8AAC\u660E\n// \u30FB\u73FE\u5728\u306E\u8981\u7D20\u3092\u8868\u3059\u96C6\
    \u5408\u3068\u3001\u305D\u308C\u3089\u306E(\u30BD\u30FC\u30C8\u6E08\u3060\u3068\
    \u3057\u3066)\u96A3\u63A5\u3068\u306E\u5DEE\u5206\u5217\u306E\u96C6\u5408\u3092\
    \u7BA1\u7406\u3059\u308B\u3002\n// \u30FB\u4E0A\u8A18\u306B\u5BFE\u3059\u308B\u3001\
    \u8981\u7D20\u8FFD\u52A0\u30FB\u8981\u7D20\u524A\u9664\u30FB\u6700\u5927\u5024\
    \u53D6\u5F97\u30FB\u6700\u5C0F\u5024\u53D6\u5F97\u304C\u3067\u304D\u308B\u3002\
    \n// \u30FB\u4E2D\u8EAB\u306Fmultiset\u306A\u306E\u3067\u3001\u4F5C\u3063\u3066\
    \u306A\u3044\u3051\u3069\u500B\u6570\u3068\u304B\u3082\u53D6\u308C\u308B\u3068\
    \u601D\u3046\u3002\n// \u30FB\u9045\u304F\u306A\u3089\u306A\u304B\u3063\u305F\u306E\
    \u3067\u62BD\u8C61\u5316\u3057\u305F\u3002\u3053\u308C\u3067\u5DEE\u5206XOR\u3068\
    \u304B\u5DEE\u5206GCD\u3068\u304B\u3067\u3082\u3067\u304D\u308B\u3002\ntemplate<typename\
    \ T, typename F>\nstruct DifferenceManager {\n    // se1: \u73FE\u5728\u306E\u8981\
    \u7D20\u3092\u8868\u3059\u96C6\u5408\n    // se2: \u73FE\u5728\u306E\u5DEE\u5206\
    \u5217\u306E\u8981\u7D20\u3092\u8868\u3059\u96C6\u5408\n    multiset<T> se1, se2;\n\
    \n    const F f;\n\n    DifferenceManager(const vector<T> &A, const F &f) : se1(ALL(A)),\
    \ f(f) {\n        build();\n    }\n\n    void build() {\n        auto itr = se1.begin();\n\
    \        while (itr != se1.end() and itr != --se1.end()) {\n            se2.insert(f(*next(itr),\
    \ *itr));\n            itr++;\n        }\n    }\n\n    void insert(T x) {\n  \
    \      auto itr = se1.insert(x);\n        if (itr != se1.begin() and itr != --se1.end())\
    \ {\n            se2.erase(se2.find(f(*next(itr), *prev(itr))));\n        }\n\
    \        if (itr != se1.begin()) {\n            se2.insert(f(*itr, *prev(itr)));\n\
    \        }\n        if (itr != --se1.end()) {\n            se2.insert(f(*next(itr),\
    \ *itr));\n        }\n    }\n\n    void erase(T x) {\n        auto itr = se1.find(x);\n\
    \        assert(itr != se1.end());\n        if (itr != se1.begin()) {\n      \
    \      se2.erase(se2.find(f(*itr, *prev(itr))));\n        }\n        if (itr !=\
    \ --se1.end()) {\n            se2.erase(se2.find(f(*next(itr), *itr)));\n    \
    \    }\n        if (itr != se1.begin() and itr != --se1.end()) {\n           \
    \ se2.insert(f(*next(itr), *prev(itr)));\n        }\n        se1.erase(itr);\n\
    \    }\n\n    int size() {\n        return se1.size();\n    }\n\n    T max_val()\
    \ {\n        assert(size() >= 1);\n        return *--se1.end();\n    }\n\n   \
    \ T min_val() {\n        assert(size() >= 1);\n        return *se1.begin();\n\
    \    }\n\n    T max_diff() {\n        assert(size() >= 2);\n        return *--se2.end();\n\
    \    }\n\n    T min_diff() {\n        assert(size() >= 2);\n        return *se2.begin();\n\
    \    }\n};\n\ntemplate<typename T, typename F>\nDifferenceManager<T, F> get_difference_manager(const\
    \ vector<T> &A, const F &f) {\n    return {A, f};\n}\n\ntemplate<typename T>\n\
    auto get_difference_manager(const vector<T> &A) {\n    // \u57FA\u672C\u306F\u3053\
    \u308C\u3092\u6E21\u3059\n    const auto f = [](T a, T b) { return a - b; };\n\
    \    return DifferenceManager<T, decltype(f)>(A, f);\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/DifferenceManager.hpp
  requiredBy: []
  timestamp: '2023-12-27 11:17:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/DifferenceManager.hpp
layout: document
redirect_from:
- /library/src/datastructure/DifferenceManager.hpp
- /library/src/datastructure/DifferenceManager.hpp.html
title: src/datastructure/DifferenceManager.hpp
---
