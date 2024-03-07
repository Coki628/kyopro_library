---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/datastructure/LazySegmentTreeArithmetric.hpp
    title: src/datastructure/LazySegmentTreeArithmetric.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/LazySegmentTree.hpp\"\
    \n\n// \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n// \u53C2\
    \u8003\uFF1Ahttps://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp\n\
    template<typename F, typename G, typename H, typename Monoid, typename OperatorMonoid>\n\
    struct LazySegmentTree {\n    int sz, height, n;\n    vector<Monoid> data;\n \
    \   vector<OperatorMonoid> lazy;\n    const F f;\n    const G g;\n    const H\
    \ h;\n    const Monoid M1;\n    const OperatorMonoid OM0;\n\n    LazySegmentTree(\n\
    \        int n, const F f, const G g, const H h, const Monoid &M1,\n        const\
    \ OperatorMonoid &OM0\n    )\n        : n(n),\n          f(f),\n          g(g),\n\
    \          h(h),\n          M1(M1),\n          OM0(OM0) {\n        sz = 1;\n \
    \       height = 0;\n        while (sz < n) sz <<= 1, height++;\n        data.assign(2\
    \ * sz, M1);\n        lazy.assign(2 * sz, OM0);\n    }\n\n    LazySegmentTree(\n\
    \        const F f, const G g, const H h, const Monoid &M1,\n        const OperatorMonoid\
    \ &OM0\n    )\n        : f(f),\n          g(g),\n          h(h),\n          M1(M1),\n\
    \          OM0(OM0) {\n    }\n\n    LazySegmentTree(\n        const vector<Monoid>\
    \ &A, const F f, const G g, const H h,\n        const Monoid &M1, const OperatorMonoid\
    \ &OM0\n    )\n        : f(f),\n          g(g),\n          h(h),\n          M1(M1),\n\
    \          OM0(OM0) {\n        build(A);\n    }\n\n    void set(int k, const Monoid\
    \ &x) {\n        data[k + sz] = x;\n    }\n\n    void build() {\n        for (int\
    \ k = sz - 1; k > 0; k--) {\n            data[k] = f(data[2 * k + 0], data[2 *\
    \ k + 1]);\n        }\n    }\n\n    void build(const vector<Monoid> &A) {\n  \
    \      n = A.size();\n        sz = 1;\n        height = 0;\n        while (sz\
    \ < n) sz <<= 1, height++;\n        data.assign(2 * sz, M1);\n        lazy.assign(2\
    \ * sz, OM0);\n        for (int i = 0; i < n; i++) set(i, A[i]);\n        build();\n\
    \    }\n\n    inline void propagate(int k) {\n        if (lazy[k] == OM0) return;\n\
    \        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);\n        lazy[2 * k +\
    \ 1] = h(lazy[2 * k + 1], lazy[k]);\n        data[k] = apply(k);\n        lazy[k]\
    \ = OM0;\n    }\n\n    inline Monoid apply(int k) {\n        return lazy[k] ==\
    \ OM0 ? data[k] : g(data[k], lazy[k]);\n    }\n\n    inline void recalc(int k)\
    \ {\n        while (k >>= 1) data[k] = f(apply(2 * k + 0), apply(2 * k + 1));\n\
    \    }\n\n    inline void thrust(int k) {\n        for (int i = height; i > 0;\
    \ i--) propagate(k >> i);\n    }\n\n    void update(int a, int b, const OperatorMonoid\
    \ &x) {\n        if (a >= b) return;\n        thrust(a += sz);\n        thrust(b\
    \ += sz - 1);\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) {\n                lazy[l] = h(lazy[l], x);\n        \
    \        ++l;\n            }\n            if (r & 1) {\n                --r;\n\
    \                lazy[r] = h(lazy[r], x);\n            }\n        }\n        recalc(a);\n\
    \        recalc(b);\n    }\n\n    Monoid query(int a, int b) {\n        if (a\
    \ >= b) return M1;\n        thrust(a += sz);\n        thrust(b += sz - 1);\n \
    \       Monoid L = M1, R = M1;\n        for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) L = f(L, apply(l++));\n            if\
    \ (r & 1) R = f(apply(--r), R);\n        }\n        return f(L, R);\n    }\n\n\
    \    Monoid operator[](const int &k) {\n        return this->get(k);\n    }\n\n\
    \    Monoid get(int k) {\n        assert(0 <= k and k < n);\n        thrust(k\
    \ += sz);\n        return apply(k);\n        // return query(k, k + 1);\n    }\n\
    \n    Monoid all() {\n        return apply(1);\n    }\n\n    int size() {\n  \
    \      return n;\n    }\n\n    void update(int i, const OperatorMonoid &x) {\n\
    \        update(i, i + 1, x);\n    }\n\n    template<typename C>\n    int find_subtree(int\
    \ a, const C &check, Monoid &M, bool type) {\n        while (a < sz) {\n     \
    \       propagate(a);\n            Monoid nxt =\n                type ? f(apply(2\
    \ * a + type), M) : f(M, apply(2 * a + type));\n            if (check(nxt)) a\
    \ = 2 * a + type;\n            else M = nxt, a = 2 * a + 1 - type;\n        }\n\
    \        return a - sz;\n    }\n\n    // \u533A\u9593[a,N)\u3067check\u306E\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u6700\u5C0F\u4F4D\u7F6E\u3092\
    \u8FD4\u3059(\u306A\u3051\u308C\u3070-1)\n    template<typename C>\n    int find_first(int\
    \ a, const C &check) {\n        Monoid L = M1;\n        if (a <= 0) {\n      \
    \      if (check(f(L, apply(1)))) return find_subtree(1, check, L, false);\n \
    \           return -1;\n        }\n        thrust(a + sz);\n        int b = sz;\n\
    \        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a\
    \ & 1) {\n                Monoid nxt = f(L, apply(a));\n                if (check(nxt))\
    \ return find_subtree(a, check, L, false);\n                L = nxt;\n       \
    \         ++a;\n            }\n        }\n        return -1;\n    }\n\n    //\
    \ \u533A\u9593[0,b)\u3067check\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306A\u6700\u5927\u4F4D\u7F6E\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070\
    -1)\n    template<typename C>\n    int find_last(int b, const C &check) {\n  \
    \      Monoid R = M1;\n        if (b >= sz) {\n            if (check(f(apply(1),\
    \ R))) return find_subtree(1, check, R, true);\n            return -1;\n     \
    \   }\n        thrust(b + sz - 1);\n        int a = sz;\n        for (b += sz;\
    \ a < b; a >>= 1, b >>= 1) {\n            if (b & 1) {\n                Monoid\
    \ nxt = f(apply(--b), R);\n                if (check(nxt)) return find_subtree(b,\
    \ check, R, true);\n                R = nxt;\n            }\n        }\n     \
    \   return -1;\n    }\n};\n\ntemplate<typename F, typename G, typename H, typename\
    \ T, typename E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(\n    const\
    \ F &f, const G &g, const H &h, const T &ti, const E &ei\n) {\n    return {f,\
    \ g, h, ti, ei};\n}\n\ntemplate<typename F, typename G, typename H, typename T,\
    \ typename E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(\n    int\
    \ N, const F &f, const G &g, const H &h, const T &ti, const E &ei\n) {\n    return\
    \ {N, f, g, h, ti, ei};\n}\n\ntemplate<typename F, typename G, typename H, typename\
    \ T, typename E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(\n    const\
    \ vector<T> &A, const F &f, const G &g, const H &h, const T &ti,\n    const E\
    \ &ei\n) {\n    return {A, f, g, h, ti, ei};\n}\n\ntemplate<typename F, typename\
    \ G, typename H, typename T, typename E>\nostream &operator<<(ostream &os, LazySegmentTree<F,\
    \ G, H, T, E> &seg) {\n    rep(i, seg.size()) {\n        os << seg[i];\n     \
    \   if (i != seg.size() - 1) {\n            os << ' ';\n        }\n    }\n   \
    \ return os;\n}\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u9045\u5EF6\u8A55\u4FA1\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp\n\
    template<typename F, typename G, typename H, typename Monoid, typename OperatorMonoid>\n\
    struct LazySegmentTree {\n    int sz, height, n;\n    vector<Monoid> data;\n \
    \   vector<OperatorMonoid> lazy;\n    const F f;\n    const G g;\n    const H\
    \ h;\n    const Monoid M1;\n    const OperatorMonoid OM0;\n\n    LazySegmentTree(\n\
    \        int n, const F f, const G g, const H h, const Monoid &M1,\n        const\
    \ OperatorMonoid &OM0\n    )\n        : n(n),\n          f(f),\n          g(g),\n\
    \          h(h),\n          M1(M1),\n          OM0(OM0) {\n        sz = 1;\n \
    \       height = 0;\n        while (sz < n) sz <<= 1, height++;\n        data.assign(2\
    \ * sz, M1);\n        lazy.assign(2 * sz, OM0);\n    }\n\n    LazySegmentTree(\n\
    \        const F f, const G g, const H h, const Monoid &M1,\n        const OperatorMonoid\
    \ &OM0\n    )\n        : f(f),\n          g(g),\n          h(h),\n          M1(M1),\n\
    \          OM0(OM0) {\n    }\n\n    LazySegmentTree(\n        const vector<Monoid>\
    \ &A, const F f, const G g, const H h,\n        const Monoid &M1, const OperatorMonoid\
    \ &OM0\n    )\n        : f(f),\n          g(g),\n          h(h),\n          M1(M1),\n\
    \          OM0(OM0) {\n        build(A);\n    }\n\n    void set(int k, const Monoid\
    \ &x) {\n        data[k + sz] = x;\n    }\n\n    void build() {\n        for (int\
    \ k = sz - 1; k > 0; k--) {\n            data[k] = f(data[2 * k + 0], data[2 *\
    \ k + 1]);\n        }\n    }\n\n    void build(const vector<Monoid> &A) {\n  \
    \      n = A.size();\n        sz = 1;\n        height = 0;\n        while (sz\
    \ < n) sz <<= 1, height++;\n        data.assign(2 * sz, M1);\n        lazy.assign(2\
    \ * sz, OM0);\n        for (int i = 0; i < n; i++) set(i, A[i]);\n        build();\n\
    \    }\n\n    inline void propagate(int k) {\n        if (lazy[k] == OM0) return;\n\
    \        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);\n        lazy[2 * k +\
    \ 1] = h(lazy[2 * k + 1], lazy[k]);\n        data[k] = apply(k);\n        lazy[k]\
    \ = OM0;\n    }\n\n    inline Monoid apply(int k) {\n        return lazy[k] ==\
    \ OM0 ? data[k] : g(data[k], lazy[k]);\n    }\n\n    inline void recalc(int k)\
    \ {\n        while (k >>= 1) data[k] = f(apply(2 * k + 0), apply(2 * k + 1));\n\
    \    }\n\n    inline void thrust(int k) {\n        for (int i = height; i > 0;\
    \ i--) propagate(k >> i);\n    }\n\n    void update(int a, int b, const OperatorMonoid\
    \ &x) {\n        if (a >= b) return;\n        thrust(a += sz);\n        thrust(b\
    \ += sz - 1);\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) {\n                lazy[l] = h(lazy[l], x);\n        \
    \        ++l;\n            }\n            if (r & 1) {\n                --r;\n\
    \                lazy[r] = h(lazy[r], x);\n            }\n        }\n        recalc(a);\n\
    \        recalc(b);\n    }\n\n    Monoid query(int a, int b) {\n        if (a\
    \ >= b) return M1;\n        thrust(a += sz);\n        thrust(b += sz - 1);\n \
    \       Monoid L = M1, R = M1;\n        for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) L = f(L, apply(l++));\n            if\
    \ (r & 1) R = f(apply(--r), R);\n        }\n        return f(L, R);\n    }\n\n\
    \    Monoid operator[](const int &k) {\n        return this->get(k);\n    }\n\n\
    \    Monoid get(int k) {\n        assert(0 <= k and k < n);\n        thrust(k\
    \ += sz);\n        return apply(k);\n        // return query(k, k + 1);\n    }\n\
    \n    Monoid all() {\n        return apply(1);\n    }\n\n    int size() {\n  \
    \      return n;\n    }\n\n    void update(int i, const OperatorMonoid &x) {\n\
    \        update(i, i + 1, x);\n    }\n\n    template<typename C>\n    int find_subtree(int\
    \ a, const C &check, Monoid &M, bool type) {\n        while (a < sz) {\n     \
    \       propagate(a);\n            Monoid nxt =\n                type ? f(apply(2\
    \ * a + type), M) : f(M, apply(2 * a + type));\n            if (check(nxt)) a\
    \ = 2 * a + type;\n            else M = nxt, a = 2 * a + 1 - type;\n        }\n\
    \        return a - sz;\n    }\n\n    // \u533A\u9593[a,N)\u3067check\u306E\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u6700\u5C0F\u4F4D\u7F6E\u3092\
    \u8FD4\u3059(\u306A\u3051\u308C\u3070-1)\n    template<typename C>\n    int find_first(int\
    \ a, const C &check) {\n        Monoid L = M1;\n        if (a <= 0) {\n      \
    \      if (check(f(L, apply(1)))) return find_subtree(1, check, L, false);\n \
    \           return -1;\n        }\n        thrust(a + sz);\n        int b = sz;\n\
    \        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a\
    \ & 1) {\n                Monoid nxt = f(L, apply(a));\n                if (check(nxt))\
    \ return find_subtree(a, check, L, false);\n                L = nxt;\n       \
    \         ++a;\n            }\n        }\n        return -1;\n    }\n\n    //\
    \ \u533A\u9593[0,b)\u3067check\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306A\u6700\u5927\u4F4D\u7F6E\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070\
    -1)\n    template<typename C>\n    int find_last(int b, const C &check) {\n  \
    \      Monoid R = M1;\n        if (b >= sz) {\n            if (check(f(apply(1),\
    \ R))) return find_subtree(1, check, R, true);\n            return -1;\n     \
    \   }\n        thrust(b + sz - 1);\n        int a = sz;\n        for (b += sz;\
    \ a < b; a >>= 1, b >>= 1) {\n            if (b & 1) {\n                Monoid\
    \ nxt = f(apply(--b), R);\n                if (check(nxt)) return find_subtree(b,\
    \ check, R, true);\n                R = nxt;\n            }\n        }\n     \
    \   return -1;\n    }\n};\n\ntemplate<typename F, typename G, typename H, typename\
    \ T, typename E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(\n    const\
    \ F &f, const G &g, const H &h, const T &ti, const E &ei\n) {\n    return {f,\
    \ g, h, ti, ei};\n}\n\ntemplate<typename F, typename G, typename H, typename T,\
    \ typename E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(\n    int\
    \ N, const F &f, const G &g, const H &h, const T &ti, const E &ei\n) {\n    return\
    \ {N, f, g, h, ti, ei};\n}\n\ntemplate<typename F, typename G, typename H, typename\
    \ T, typename E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(\n    const\
    \ vector<T> &A, const F &f, const G &g, const H &h, const T &ti,\n    const E\
    \ &ei\n) {\n    return {A, f, g, h, ti, ei};\n}\n\ntemplate<typename F, typename\
    \ G, typename H, typename T, typename E>\nostream &operator<<(ostream &os, LazySegmentTree<F,\
    \ G, H, T, E> &seg) {\n    rep(i, seg.size()) {\n        os << seg[i];\n     \
    \   if (i != seg.size() - 1) {\n            os << ' ';\n        }\n    }\n   \
    \ return os;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/LazySegmentTree.hpp
  requiredBy:
  - src/datastructure/LazySegmentTreeArithmetric.hpp
  timestamp: '2024-03-07 15:03:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/src/datastructure/LazySegmentTree.hpp
- /library/src/datastructure/LazySegmentTree.hpp.html
title: src/datastructure/LazySegmentTree.hpp
---
