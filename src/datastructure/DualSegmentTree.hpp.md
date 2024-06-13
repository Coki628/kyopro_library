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
    links:
    - https://atcoder.jp/contests/abc332/submissions/48389709
    - https://atcoder.jp/contests/abc332/submissions/48392267
    - https://atcoder.jp/contests/abc342/submissions/50480272
    - https://atcoder.jp/contests/abc342/submissions/50580301
    - https://hackmd.io/@tatyam-prime/DualSegmentTree
    - https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/DualSegmentTree.hpp\"\
    \n\n// \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n// \u53C2\u8003\uFF1A\
    https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree\n//\
    \ \u3000\u3000\u3000https://hackmd.io/@tatyam-prime/DualSegmentTree\n// \u3000\
    \u3000\u3000https://atcoder.jp/contests/abc342/submissions/50580301\n// \u3000\
    \u3000\u3000https://atcoder.jp/contests/abc342/submissions/50480272\n// \u3000\
    \u3000\u3000https://atcoder.jp/contests/abc332/submissions/48389709\n// \u3000\
    \u3000\u3000https://atcoder.jp/contests/abc332/submissions/48392267\n// \u4ECA\
    \u307E\u3067\u9045\u5EF6\u30BB\u30B0\u6728\u3067\u56F0\u3089\u306A\u304B\u3063\
    \u305F\u304B\u3089\u4F5C\u3089\u306A\u304B\u3063\u305F\u3051\u3069\u3001\n// \u3044\
    \u3088\u3044\u3088\u5FC5\u8981\u306A\u5834\u9762\u306B\u906D\u9047\u3057\u305F\
    \u306E\u3067\u4F5C\u3063\u305F\u3002(abc342_g)\n// \u57FA\u672C\u7684\u306B\u306F\
    \u805E\u3044\u3066\u305F\u901A\u308A\u3001\u9045\u5EF6\u30BB\u30B0\u6728\u306E\
    \u4F5C\u7528\u7D20\u5074\u3060\u3051\u7248\u306A\u3093\u3060\u3051\u3069\u3001\
    \n// \u3088\u308A\u5177\u4F53\u7684\u306B\u8A00\u3048\u3070\u3001\u4F5C\u7528\u7D20\
    \u3092\u4F55\u3082\u4F1D\u642C\u3055\u305B\u305A\u306B\u305D\u306E\u307E\u307E\
    \u6301\u3063\u3066\u3044\u3066\u3001\n// 1\u70B9\u53D6\u5F97\u306E\u6642\u306B\
    \u90FD\u5EA6\u3001\u8449\u304B\u3089\u89AA\u5074\u306B\u53D6\u308A\u306B\u884C\
    \u304F\u3001\u307F\u305F\u3044\u306A\u611F\u3058\u3060\u3063\u305F\u3002\n// \u3067\
    \u3001\u305D\u308C\u306F\u53EF\u63DB\u306E\u3082\u306E\u3092\u4E57\u305B\u308B\
    \u6642\u306E\u8A71\u3067\u3001\u975E\u53EF\u63DB\u306E\u3082\u306E\u3092\u4E57\
    \u305B\u308B\u6642\u306F\u5B9F\u88C5\u304C\u304B\u306A\u308A\u5909\u308F\u308B\
    \u3002\n// \u4E0B\u304B\u3089\u4E0A\u306B\u53D6\u308A\u306B\u884C\u304F\u65B9\u6CD5\
    \u3060\u3068\u3001\u6F14\u7B97\u3092\u5F53\u3066\u308B\u9806\u5E8F\u304C\u5909\
    \u308F\u3063\u3066\u3057\u307E\u3046\u3002\n// \u306A\u306E\u3067\u975E\u53EF\u63DB\
    \u306E\u5834\u5408\u306F\u3001\u9045\u5EF6\u30BB\u30B0\u6728\u307F\u305F\u3044\
    \u306B\u5148\u306B\u4E0B\u306B\u4F1D\u642C\u3055\u305B\u3066\u304A\u304F\u3002\
    \n// \u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u5B9F\u88C5\u3068\u3057\u3066\u306F\u3001\
    \u53EF\u63DB\u304B\u3069\u3046\u304B\u306E\u30D5\u30E9\u30B0commute\u3092\u7528\
    \u610F\u3057\u3066\u3001\n// \u521D\u671F\u5316\u306E\u6642\u70B9\u3067\u3069\u3063\
    \u3061\u306E\u632F\u308B\u821E\u3044\u306B\u3059\u308B\u304B\u6C7A\u3081\u3089\
    \u308C\u308B\u3088\u3046\u306B\u3057\u305F\u3002\n// \u4F7F\u3044\u65B9\n// \u30FB\
    \u57FA\u672C\u306F\u533A\u9593\u66F4\u65B0\u30681\u70B9\u53D6\u5F97\u3060\u3051\
    \u3067\u304D\u308B\u9045\u5EF6\u30BB\u30B0\u6728\u3068\u601D\u3063\u3066\u3044\
    \u3044\u3002\n// \u30FB\u306A\u3093\u3068\u306A\u304F\u30A4\u30E1\u30FC\u30B8\u3067\
    1\u70B9\u53D6\u5F97\u306FO(1)\u3067\u3067\u304D\u308B\u6C17\u304C\u3057\u3066\u305F\
    \u3093\u3060\u3051\u3069\u3001O(logN)\u304B\u304B\u308B\u3002\n// \u30FB\u9006\
    \u306B1\u70B9\u66F4\u65B0\u306FO(1)\u3067OK\u3002\u306A\u306E\u3067\u57FA\u672C\
    \u7684\u306B\u306F\u521D\u671F\u5316\u304C\u8981\u3089\u306A\u304F\u3066\u3001\
    \n// \u3000\u521D\u671F\u72B6\u614B\u306F\u76F4\u63A5update\u3067\u5168\u7B87\u6240\
    1\u70B9\u66F4\u65B0\u3059\u308B\u3067\u3082\u3044\u3044\u3002\n// \u3000\u4E00\
    \u5FDC\u3001\u914D\u5217\u6E21\u3059\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u6B8B\u3057\u3066\u3042\u308B\u3051\u3069\u306D\u3002\u3060\u3044\u305F\u3044\
    \u305D\u306E\u65B9\u304C\u697D\u3060\u3057\u3002\n// \u30FB\u975E\u53EF\u63DB\u306E\
    \u3082\u306E\u3092\u4E57\u305B\u308B\u6642\u306B\u306F\u521D\u671F\u5316\u6642\
    \u306Bcommute=false\u3092\u6E21\u3059\u3002\ntemplate<typename G, typename H,\
    \ typename Monoid, typename OperatorMonoid>\nstruct DualSegmentTree {\n    int\
    \ sz, height, n;\n    vector<Monoid> data;\n    vector<OperatorMonoid> lazy;\n\
    \    const G g;\n    const H h;\n    const Monoid M1;\n    const OperatorMonoid\
    \ OM0;\n    // \u53EF\u63DB\u304B\u3069\u3046\u304B\n    bool commute;\n\n   \
    \ DualSegmentTree(\n        int n, const G g, const H h, const Monoid &M1,\n \
    \       const OperatorMonoid &OM0, bool commute = true\n    )\n        : n(n),\n\
    \          g(g),\n          h(h),\n          M1(M1),\n          OM0(OM0),\n  \
    \        commute(commute) {\n        sz = 1;\n        height = 0;\n        while\
    \ (sz < n) sz <<= 1, height++;\n        data.assign(n, M1);\n        lazy.assign(2\
    \ * sz, OM0);\n    }\n\n    DualSegmentTree(\n        const vector<Monoid> &A,\
    \ const G g, const H h,\n        const Monoid &M1, const OperatorMonoid &OM0,\
    \ bool commute = true\n    )\n        : g(g),\n          h(h),\n          M1(M1),\n\
    \          OM0(OM0),\n          commute(commute) {\n        build(A);\n    }\n\
    \n    // \u53D6\u5F97\u5074\u306E\u5024\u3001\u7279\u306Bbuild\u306F\u4E0D\u8981\
    \n    void set(int k, const Monoid &x) {\n        data[k] = x;\n    }\n\n    void\
    \ build(const vector<Monoid> &A) {\n        n = A.size();\n        sz = 1;\n \
    \       height = 0;\n        while (sz < n) sz <<= 1, height++;\n        data\
    \ = A;\n        lazy.assign(2 * sz, OM0);\n    }\n\n    inline void propagate(int\
    \ k) {\n        if (lazy[k] == OM0) return;\n        lazy[2 * k + 0] = h(lazy[2\
    \ * k + 0], lazy[k]);\n        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n\
    \        lazy[k] = OM0;\n    }\n\n    inline void thrust(int k) {\n        for\
    \ (int i = height; i > 0; i--) propagate(k >> i);\n    }\n\n    // \u533A\u9593\
    \u66F4\u65B0\uFF1AO(logN)\n    void update(int a, int b, const OperatorMonoid\
    \ &x) {\n        if (a >= b) return;\n        a += sz;\n        b += sz - 1;\n\
    \        // \u975E\u53EF\u63DB\u306A\u3089\u66F4\u65B0\u3092\u4E0B\u306B\u4F1D\
    \u642C\u3055\u305B\u308B\n        if (not commute) {\n            thrust(a);\n\
    \            thrust(b);\n        }\n        for (int l = a, r = b + 1; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) {\n                lazy[l] = h(lazy[l],\
    \ x);\n                ++l;\n            }\n            if (r & 1) {\n       \
    \         --r;\n                lazy[r] = h(lazy[r], x);\n            }\n    \
    \    }\n    }\n\n    Monoid operator[](const int &k) {\n        return this->get(k);\n\
    \    }\n\n    // 1\u70B9\u53D6\u5F97\uFF1AO(logN)\n    Monoid get(int k) {\n \
    \       assert(0 <= k and k < n);\n        Monoid res = data[k];\n        k +=\
    \ sz;\n        if (commute) {\n            // \u53EF\u63DB\u306A\u3089\u4E0B\u304B\
    \u3089\u4E0A\u306B\u66F4\u65B0\u60C5\u5831\u3092\u53D6\u308A\u306B\u884C\u304F\
    \n            for (int i = k; i > 0; i >>= 1) {\n                res = g(res,\
    \ lazy[i]);\n            }\n        } else {\n            // \u975E\u53EF\u63DB\
    \u306A\u3089\u4E0A\u304B\u3089\u4E0B\u306B\u4F1D\u642C\u3055\u305B\u3066\u304A\
    \u304F\n            thrust(k);\n            res = g(res, lazy[k]);\n        }\n\
    \        return res;\n    }\n\n    int size() {\n        return n;\n    }\n\n\
    \    // 1\u70B9\u66F4\u65B0\uFF1AO(1)\n    void update(int i, const OperatorMonoid\
    \ &x) {\n        // update(i, i + 1, x);\n        lazy[i + sz] = h(lazy[i + sz],\
    \ x);\n    }\n};\n\ntemplate<typename G, typename H, typename T, typename E>\n\
    DualSegmentTree<G, H, T, E> get_dual_segment_tree(\n    int N, const G &g, const\
    \ H &h, const T &ti, const E &ei, bool commute = true\n) {\n    return {N, g,\
    \ h, ti, ei, commute};\n}\n\ntemplate<typename G, typename H, typename T, typename\
    \ E>\nDualSegmentTree<G, H, T, E> get_dual_segment_tree(\n    const vector<T>\
    \ &A, const G &g, const H &h, const T &ti,\n    const E &ei, bool commute = true\n\
    ) {\n    return {A, g, h, ti, ei, commute};\n}\n\ntemplate<typename G, typename\
    \ H, typename T, typename E>\nostream &operator<<(ostream &os, DualSegmentTree<G,\
    \ H, T, E> &seg) {\n    for (int i = 0; i < seg.size(); i++) {\n        os <<\
    \ seg[i];\n        if (i != seg.size() - 1) {\n            os << ' ';\n      \
    \  }\n    }\n    return os;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u53CC\u5BFE\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n// \u53C2\u8003\uFF1Ahttps://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree\n\
    // \u3000\u3000\u3000https://hackmd.io/@tatyam-prime/DualSegmentTree\n// \u3000\
    \u3000\u3000https://atcoder.jp/contests/abc342/submissions/50580301\n// \u3000\
    \u3000\u3000https://atcoder.jp/contests/abc342/submissions/50480272\n// \u3000\
    \u3000\u3000https://atcoder.jp/contests/abc332/submissions/48389709\n// \u3000\
    \u3000\u3000https://atcoder.jp/contests/abc332/submissions/48392267\n// \u4ECA\
    \u307E\u3067\u9045\u5EF6\u30BB\u30B0\u6728\u3067\u56F0\u3089\u306A\u304B\u3063\
    \u305F\u304B\u3089\u4F5C\u3089\u306A\u304B\u3063\u305F\u3051\u3069\u3001\n// \u3044\
    \u3088\u3044\u3088\u5FC5\u8981\u306A\u5834\u9762\u306B\u906D\u9047\u3057\u305F\
    \u306E\u3067\u4F5C\u3063\u305F\u3002(abc342_g)\n// \u57FA\u672C\u7684\u306B\u306F\
    \u805E\u3044\u3066\u305F\u901A\u308A\u3001\u9045\u5EF6\u30BB\u30B0\u6728\u306E\
    \u4F5C\u7528\u7D20\u5074\u3060\u3051\u7248\u306A\u3093\u3060\u3051\u3069\u3001\
    \n// \u3088\u308A\u5177\u4F53\u7684\u306B\u8A00\u3048\u3070\u3001\u4F5C\u7528\u7D20\
    \u3092\u4F55\u3082\u4F1D\u642C\u3055\u305B\u305A\u306B\u305D\u306E\u307E\u307E\
    \u6301\u3063\u3066\u3044\u3066\u3001\n// 1\u70B9\u53D6\u5F97\u306E\u6642\u306B\
    \u90FD\u5EA6\u3001\u8449\u304B\u3089\u89AA\u5074\u306B\u53D6\u308A\u306B\u884C\
    \u304F\u3001\u307F\u305F\u3044\u306A\u611F\u3058\u3060\u3063\u305F\u3002\n// \u3067\
    \u3001\u305D\u308C\u306F\u53EF\u63DB\u306E\u3082\u306E\u3092\u4E57\u305B\u308B\
    \u6642\u306E\u8A71\u3067\u3001\u975E\u53EF\u63DB\u306E\u3082\u306E\u3092\u4E57\
    \u305B\u308B\u6642\u306F\u5B9F\u88C5\u304C\u304B\u306A\u308A\u5909\u308F\u308B\
    \u3002\n// \u4E0B\u304B\u3089\u4E0A\u306B\u53D6\u308A\u306B\u884C\u304F\u65B9\u6CD5\
    \u3060\u3068\u3001\u6F14\u7B97\u3092\u5F53\u3066\u308B\u9806\u5E8F\u304C\u5909\
    \u308F\u3063\u3066\u3057\u307E\u3046\u3002\n// \u306A\u306E\u3067\u975E\u53EF\u63DB\
    \u306E\u5834\u5408\u306F\u3001\u9045\u5EF6\u30BB\u30B0\u6728\u307F\u305F\u3044\
    \u306B\u5148\u306B\u4E0B\u306B\u4F1D\u642C\u3055\u305B\u3066\u304A\u304F\u3002\
    \n// \u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u5B9F\u88C5\u3068\u3057\u3066\u306F\u3001\
    \u53EF\u63DB\u304B\u3069\u3046\u304B\u306E\u30D5\u30E9\u30B0commute\u3092\u7528\
    \u610F\u3057\u3066\u3001\n// \u521D\u671F\u5316\u306E\u6642\u70B9\u3067\u3069\u3063\
    \u3061\u306E\u632F\u308B\u821E\u3044\u306B\u3059\u308B\u304B\u6C7A\u3081\u3089\
    \u308C\u308B\u3088\u3046\u306B\u3057\u305F\u3002\n// \u4F7F\u3044\u65B9\n// \u30FB\
    \u57FA\u672C\u306F\u533A\u9593\u66F4\u65B0\u30681\u70B9\u53D6\u5F97\u3060\u3051\
    \u3067\u304D\u308B\u9045\u5EF6\u30BB\u30B0\u6728\u3068\u601D\u3063\u3066\u3044\
    \u3044\u3002\n// \u30FB\u306A\u3093\u3068\u306A\u304F\u30A4\u30E1\u30FC\u30B8\u3067\
    1\u70B9\u53D6\u5F97\u306FO(1)\u3067\u3067\u304D\u308B\u6C17\u304C\u3057\u3066\u305F\
    \u3093\u3060\u3051\u3069\u3001O(logN)\u304B\u304B\u308B\u3002\n// \u30FB\u9006\
    \u306B1\u70B9\u66F4\u65B0\u306FO(1)\u3067OK\u3002\u306A\u306E\u3067\u57FA\u672C\
    \u7684\u306B\u306F\u521D\u671F\u5316\u304C\u8981\u3089\u306A\u304F\u3066\u3001\
    \n// \u3000\u521D\u671F\u72B6\u614B\u306F\u76F4\u63A5update\u3067\u5168\u7B87\u6240\
    1\u70B9\u66F4\u65B0\u3059\u308B\u3067\u3082\u3044\u3044\u3002\n// \u3000\u4E00\
    \u5FDC\u3001\u914D\u5217\u6E21\u3059\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u6B8B\u3057\u3066\u3042\u308B\u3051\u3069\u306D\u3002\u3060\u3044\u305F\u3044\
    \u305D\u306E\u65B9\u304C\u697D\u3060\u3057\u3002\n// \u30FB\u975E\u53EF\u63DB\u306E\
    \u3082\u306E\u3092\u4E57\u305B\u308B\u6642\u306B\u306F\u521D\u671F\u5316\u6642\
    \u306Bcommute=false\u3092\u6E21\u3059\u3002\ntemplate<typename G, typename H,\
    \ typename Monoid, typename OperatorMonoid>\nstruct DualSegmentTree {\n    int\
    \ sz, height, n;\n    vector<Monoid> data;\n    vector<OperatorMonoid> lazy;\n\
    \    const G g;\n    const H h;\n    const Monoid M1;\n    const OperatorMonoid\
    \ OM0;\n    // \u53EF\u63DB\u304B\u3069\u3046\u304B\n    bool commute;\n\n   \
    \ DualSegmentTree(\n        int n, const G g, const H h, const Monoid &M1,\n \
    \       const OperatorMonoid &OM0, bool commute = true\n    )\n        : n(n),\n\
    \          g(g),\n          h(h),\n          M1(M1),\n          OM0(OM0),\n  \
    \        commute(commute) {\n        sz = 1;\n        height = 0;\n        while\
    \ (sz < n) sz <<= 1, height++;\n        data.assign(n, M1);\n        lazy.assign(2\
    \ * sz, OM0);\n    }\n\n    DualSegmentTree(\n        const vector<Monoid> &A,\
    \ const G g, const H h,\n        const Monoid &M1, const OperatorMonoid &OM0,\
    \ bool commute = true\n    )\n        : g(g),\n          h(h),\n          M1(M1),\n\
    \          OM0(OM0),\n          commute(commute) {\n        build(A);\n    }\n\
    \n    // \u53D6\u5F97\u5074\u306E\u5024\u3001\u7279\u306Bbuild\u306F\u4E0D\u8981\
    \n    void set(int k, const Monoid &x) {\n        data[k] = x;\n    }\n\n    void\
    \ build(const vector<Monoid> &A) {\n        n = A.size();\n        sz = 1;\n \
    \       height = 0;\n        while (sz < n) sz <<= 1, height++;\n        data\
    \ = A;\n        lazy.assign(2 * sz, OM0);\n    }\n\n    inline void propagate(int\
    \ k) {\n        if (lazy[k] == OM0) return;\n        lazy[2 * k + 0] = h(lazy[2\
    \ * k + 0], lazy[k]);\n        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);\n\
    \        lazy[k] = OM0;\n    }\n\n    inline void thrust(int k) {\n        for\
    \ (int i = height; i > 0; i--) propagate(k >> i);\n    }\n\n    // \u533A\u9593\
    \u66F4\u65B0\uFF1AO(logN)\n    void update(int a, int b, const OperatorMonoid\
    \ &x) {\n        if (a >= b) return;\n        a += sz;\n        b += sz - 1;\n\
    \        // \u975E\u53EF\u63DB\u306A\u3089\u66F4\u65B0\u3092\u4E0B\u306B\u4F1D\
    \u642C\u3055\u305B\u308B\n        if (not commute) {\n            thrust(a);\n\
    \            thrust(b);\n        }\n        for (int l = a, r = b + 1; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) {\n                lazy[l] = h(lazy[l],\
    \ x);\n                ++l;\n            }\n            if (r & 1) {\n       \
    \         --r;\n                lazy[r] = h(lazy[r], x);\n            }\n    \
    \    }\n    }\n\n    Monoid operator[](const int &k) {\n        return this->get(k);\n\
    \    }\n\n    // 1\u70B9\u53D6\u5F97\uFF1AO(logN)\n    Monoid get(int k) {\n \
    \       assert(0 <= k and k < n);\n        Monoid res = data[k];\n        k +=\
    \ sz;\n        if (commute) {\n            // \u53EF\u63DB\u306A\u3089\u4E0B\u304B\
    \u3089\u4E0A\u306B\u66F4\u65B0\u60C5\u5831\u3092\u53D6\u308A\u306B\u884C\u304F\
    \n            for (int i = k; i > 0; i >>= 1) {\n                res = g(res,\
    \ lazy[i]);\n            }\n        } else {\n            // \u975E\u53EF\u63DB\
    \u306A\u3089\u4E0A\u304B\u3089\u4E0B\u306B\u4F1D\u642C\u3055\u305B\u3066\u304A\
    \u304F\n            thrust(k);\n            res = g(res, lazy[k]);\n        }\n\
    \        return res;\n    }\n\n    int size() {\n        return n;\n    }\n\n\
    \    // 1\u70B9\u66F4\u65B0\uFF1AO(1)\n    void update(int i, const OperatorMonoid\
    \ &x) {\n        // update(i, i + 1, x);\n        lazy[i + sz] = h(lazy[i + sz],\
    \ x);\n    }\n};\n\ntemplate<typename G, typename H, typename T, typename E>\n\
    DualSegmentTree<G, H, T, E> get_dual_segment_tree(\n    int N, const G &g, const\
    \ H &h, const T &ti, const E &ei, bool commute = true\n) {\n    return {N, g,\
    \ h, ti, ei, commute};\n}\n\ntemplate<typename G, typename H, typename T, typename\
    \ E>\nDualSegmentTree<G, H, T, E> get_dual_segment_tree(\n    const vector<T>\
    \ &A, const G &g, const H &h, const T &ti,\n    const E &ei, bool commute = true\n\
    ) {\n    return {A, g, h, ti, ei, commute};\n}\n\ntemplate<typename G, typename\
    \ H, typename T, typename E>\nostream &operator<<(ostream &os, DualSegmentTree<G,\
    \ H, T, E> &seg) {\n    for (int i = 0; i < seg.size(); i++) {\n        os <<\
    \ seg[i];\n        if (i != seg.size() - 1) {\n            os << ' ';\n      \
    \  }\n    }\n    return os;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/DualSegmentTree.hpp
layout: document
redirect_from:
- /library/src/datastructure/DualSegmentTree.hpp
- /library/src/datastructure/DualSegmentTree.hpp.html
title: src/datastructure/DualSegmentTree.hpp
---
