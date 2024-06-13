---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/datastructure/tree.hpp
    title: src/datastructure/tree.hpp
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
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull\
    \ = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/datastructure/tree.hpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\n\n// \u521D\
    \u671F\u5316\n// tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>\
    \ tr;\n\n// k\u756A\u76EE(0-indexed)\u306E\u8981\u7D20\u3092\u53D6\u5F97\n// ll\
    \ val = *tr.find_by_order(k);\n// \u9006\u5F15\u304D\u3082\u3067\u304D\u308B\n\
    // int k = order_of_key(val);\n\n// \u305D\u308C\u610F\u5916\u306F\u307B\u307C\
    set\u3068\u540C\u3058\u611F\u3058\u3067\u4F7F\u3048\u308B\u3002\n#line 4 \"src/datastructure/DifferenceManagerTree.hpp\"\
    \n\n// \u5DEE\u5206\u5217\u7BA1\u7406\n// \u30FB\u5185\u90E8\u5B9F\u88C5\u3092\
    multiset\u304B\u3089\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728tree\u306B\u3057\
    \u3066K\u756A\u76EE\u53D6\u5F97\u3092\u53EF\u80FD\u306B\u3057\u305F\u3002\n//\
    \ \u3000tree\u306F(multi\u3058\u3083\u306A\u3044)set\u306A\u306E\u3067\u3001\u591A\
    \u91CD\u96C6\u5408\u3092\u6271\u3048\u308B\u3088\u3046\u306B\u5185\u90E8\u3067\
    id\u3068\u30DA\u30A2\u306B\u3057\u3066\u3042\u308B\u3002\n// \u30FB\u3055\u3059\
    \u304C\u306B\u82E5\u5E72multiset\u306E\u3088\u308A\u9045\u3044\u3002\ntemplate<typename\
    \ T, typename F>\nstruct DifferenceManagerTree {\n    using Tree = tree<pair<T,\
    \ int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \    // se1: \u73FE\u5728\u306E\u8981\u7D20\u3092\u8868\u3059\u96C6\u5408\n  \
    \  // se2: \u73FE\u5728\u306E\u5DEE\u5206\u5217\u306E\u8981\u7D20\u3092\u8868\u3059\
    \u96C6\u5408\n    Tree se1, se2;\n    int id = 0;\n\n    const F f;\n\n    DifferenceManagerTree(const\
    \ vector<T> &A, const F &f) : f(f) {\n        for (auto &a : A) {\n          \
    \  se1.insert({a, id});\n            id++;\n        }\n        build();\n    }\n\
    \n    void build() {\n        auto itr = se1.begin();\n        while (itr != se1.end()\
    \ and itr != --se1.end()) {\n            se2.insert({f(next(itr)->first, itr->first),\
    \ id});\n            id++;\n            itr++;\n        }\n    }\n\n    void insert(T\
    \ x) {\n        // \u3053\u306E\u623B\u308A\u5024\u304C\u5FAE\u5999\u306Bmultiset\u3068\
    \u9055\u3046\n        auto [itr, _] = se1.insert({x, id});\n        id++;\n  \
    \      if (itr != se1.begin() and itr != --se1.end()) {\n            se2.erase(se2.lower_bound({f(next(itr)->first,\
    \ prev(itr)->first), 0}));\n        }\n        if (itr != se1.begin()) {\n   \
    \         se2.insert({f(itr->first, prev(itr)->first), id});\n            id++;\n\
    \        }\n        if (itr != --se1.end()) {\n            se2.insert({f(next(itr)->first,\
    \ itr->first), id});\n            id++;\n        }\n    }\n\n    void erase(T\
    \ x) {\n        auto itr = se1.lower_bound({x, 0});\n        assert(itr != se1.end());\n\
    \        if (itr != se1.begin()) {\n            se2.erase(se2.lower_bound({f(itr->first,\
    \ prev(itr)->first), 0}));\n        }\n        if (itr != --se1.end()) {\n   \
    \         se2.erase(se2.lower_bound({f(next(itr)->first, itr->first), 0}));\n\
    \        }\n        if (itr != se1.begin() and itr != --se1.end()) {\n       \
    \     se2.insert({f(next(itr)->first, prev(itr)->first), id});\n            id++;\n\
    \        }\n        se1.erase(itr);\n    }\n\n    int size() {\n        return\
    \ se1.size();\n    }\n\n    T max_val() {\n        assert(size() >= 1);\n    \
    \    return (--se1.end())->first;\n    }\n\n    T min_val() {\n        assert(size()\
    \ >= 1);\n        return se1.begin()->first;\n    }\n\n    T max_diff() {\n  \
    \      assert(size() >= 2);\n        return (--se2.end())->first;\n    }\n\n \
    \   T min_diff() {\n        assert(size() >= 2);\n        return se2.begin()->first;\n\
    \    }\n\n    T kth_val(int k) {\n        auto itr = se1.find_by_order(k);\n \
    \       assert(itr != se1.end());\n        return itr->first;\n    }\n\n    T\
    \ kth_diff(int k) {\n        auto itr = se2.find_by_order(k);\n        assert(itr\
    \ != se2.end());\n        return itr->first;\n    }\n};\n\ntemplate<typename T,\
    \ typename F>\nDifferenceManagerTree<T, F> get_difference_manager_tree(const vector<T>\
    \ &A, const F &f) {\n    return {A, f};\n}\n\ntemplate<typename T>\nauto get_difference_manager_tree(const\
    \ vector<T> &A) {\n    // \u57FA\u672C\u306F\u3053\u308C\u3092\u6E21\u3059\n \
    \   const auto f = [](T a, T b) { return a - b; };\n    return DifferenceManagerTree<T,\
    \ decltype(f)>(A, f);\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"tree.hpp\"\n\n// \u5DEE\
    \u5206\u5217\u7BA1\u7406\n// \u30FB\u5185\u90E8\u5B9F\u88C5\u3092multiset\u304B\
    \u3089\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728tree\u306B\u3057\u3066K\u756A\u76EE\
    \u53D6\u5F97\u3092\u53EF\u80FD\u306B\u3057\u305F\u3002\n// \u3000tree\u306F(multi\u3058\
    \u3083\u306A\u3044)set\u306A\u306E\u3067\u3001\u591A\u91CD\u96C6\u5408\u3092\u6271\
    \u3048\u308B\u3088\u3046\u306B\u5185\u90E8\u3067id\u3068\u30DA\u30A2\u306B\u3057\
    \u3066\u3042\u308B\u3002\n// \u30FB\u3055\u3059\u304C\u306B\u82E5\u5E72multiset\u306E\
    \u3088\u308A\u9045\u3044\u3002\ntemplate<typename T, typename F>\nstruct DifferenceManagerTree\
    \ {\n    using Tree = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n    // se1: \u73FE\u5728\u306E\u8981\u7D20\
    \u3092\u8868\u3059\u96C6\u5408\n    // se2: \u73FE\u5728\u306E\u5DEE\u5206\u5217\
    \u306E\u8981\u7D20\u3092\u8868\u3059\u96C6\u5408\n    Tree se1, se2;\n    int\
    \ id = 0;\n\n    const F f;\n\n    DifferenceManagerTree(const vector<T> &A, const\
    \ F &f) : f(f) {\n        for (auto &a : A) {\n            se1.insert({a, id});\n\
    \            id++;\n        }\n        build();\n    }\n\n    void build() {\n\
    \        auto itr = se1.begin();\n        while (itr != se1.end() and itr != --se1.end())\
    \ {\n            se2.insert({f(next(itr)->first, itr->first), id});\n        \
    \    id++;\n            itr++;\n        }\n    }\n\n    void insert(T x) {\n \
    \       // \u3053\u306E\u623B\u308A\u5024\u304C\u5FAE\u5999\u306Bmultiset\u3068\
    \u9055\u3046\n        auto [itr, _] = se1.insert({x, id});\n        id++;\n  \
    \      if (itr != se1.begin() and itr != --se1.end()) {\n            se2.erase(se2.lower_bound({f(next(itr)->first,\
    \ prev(itr)->first), 0}));\n        }\n        if (itr != se1.begin()) {\n   \
    \         se2.insert({f(itr->first, prev(itr)->first), id});\n            id++;\n\
    \        }\n        if (itr != --se1.end()) {\n            se2.insert({f(next(itr)->first,\
    \ itr->first), id});\n            id++;\n        }\n    }\n\n    void erase(T\
    \ x) {\n        auto itr = se1.lower_bound({x, 0});\n        assert(itr != se1.end());\n\
    \        if (itr != se1.begin()) {\n            se2.erase(se2.lower_bound({f(itr->first,\
    \ prev(itr)->first), 0}));\n        }\n        if (itr != --se1.end()) {\n   \
    \         se2.erase(se2.lower_bound({f(next(itr)->first, itr->first), 0}));\n\
    \        }\n        if (itr != se1.begin() and itr != --se1.end()) {\n       \
    \     se2.insert({f(next(itr)->first, prev(itr)->first), id});\n            id++;\n\
    \        }\n        se1.erase(itr);\n    }\n\n    int size() {\n        return\
    \ se1.size();\n    }\n\n    T max_val() {\n        assert(size() >= 1);\n    \
    \    return (--se1.end())->first;\n    }\n\n    T min_val() {\n        assert(size()\
    \ >= 1);\n        return se1.begin()->first;\n    }\n\n    T max_diff() {\n  \
    \      assert(size() >= 2);\n        return (--se2.end())->first;\n    }\n\n \
    \   T min_diff() {\n        assert(size() >= 2);\n        return se2.begin()->first;\n\
    \    }\n\n    T kth_val(int k) {\n        auto itr = se1.find_by_order(k);\n \
    \       assert(itr != se1.end());\n        return itr->first;\n    }\n\n    T\
    \ kth_diff(int k) {\n        auto itr = se2.find_by_order(k);\n        assert(itr\
    \ != se2.end());\n        return itr->first;\n    }\n};\n\ntemplate<typename T,\
    \ typename F>\nDifferenceManagerTree<T, F> get_difference_manager_tree(const vector<T>\
    \ &A, const F &f) {\n    return {A, f};\n}\n\ntemplate<typename T>\nauto get_difference_manager_tree(const\
    \ vector<T> &A) {\n    // \u57FA\u672C\u306F\u3053\u308C\u3092\u6E21\u3059\n \
    \   const auto f = [](T a, T b) { return a - b; };\n    return DifferenceManagerTree<T,\
    \ decltype(f)>(A, f);\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/datastructure/tree.hpp
  isVerificationFile: false
  path: src/datastructure/DifferenceManagerTree.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/DifferenceManagerTree.hpp
layout: document
redirect_from:
- /library/src/datastructure/DifferenceManagerTree.hpp
- /library/src/datastructure/DifferenceManagerTree.hpp.html
title: src/datastructure/DifferenceManagerTree.hpp
---
