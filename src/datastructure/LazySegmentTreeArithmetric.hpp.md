---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/datastructure/LazySegmentTree.hpp
    title: src/datastructure/LazySegmentTree.hpp
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
    - https://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp
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
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/datastructure/LazySegmentTree.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp\n\
    // \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\ntemplate<typename\
    \ F, typename G, typename H, typename Monoid, typename OperatorMonoid>\nstruct\
    \ LazySegmentTree {\n    int sz, height;\n    vector<Monoid> data;\n    vector<OperatorMonoid>\
    \ lazy;\n    const F f;\n    const G g;\n    const H h;\n    const Monoid M1;\n\
    \    const OperatorMonoid OM0;\n\n    LazySegmentTree(int n, const F f, const\
    \ G g, const H h,\n                    const Monoid &M1, const OperatorMonoid\
    \ OM0)\n            : f(f), g(g), h(h), M1(M1), OM0(OM0) {\n        sz = 1;\n\
    \        height = 0;\n        while(sz < n) sz <<= 1, height++;\n        data.assign(2\
    \ * sz, M1);\n        lazy.assign(2 * sz, OM0);\n    }\n\n    LazySegmentTree(const\
    \ F f, const G g, const H h,\n                    const Monoid &M1, const OperatorMonoid\
    \ OM0)\n            : f(f), g(g), h(h), M1(M1), OM0(OM0) {}\n\n    LazySegmentTree(const\
    \ vector<Monoid> &A, const F f, const G g, const H h,\n                    const\
    \ Monoid &M1, const OperatorMonoid OM0)\n            : f(f), g(g), h(h), M1(M1),\
    \ OM0(OM0) {\n        build(A);\n    }\n\n    void set(int k, const Monoid &x)\
    \ {\n        data[k + sz] = x;\n    }\n\n    void build() {\n        for(int k\
    \ = sz - 1; k > 0; k--) {\n            data[k] = f(data[2 * k + 0], data[2 * k\
    \ + 1]);\n        }\n    }\n\n    void build(const vector<Monoid> &A) {\n    \
    \    int n = A.size();\n        sz = 1;\n        height = 0;\n        while(sz\
    \ < n) sz <<= 1, height++;\n        data.assign(2 * sz, M1);\n        lazy.assign(2\
    \ * sz, OM0);\n        for (int i=0; i<n; i++) set(i, A[i]);\n        build();\n\
    \    }\n\n    inline void propagate(int k) {\n        if(lazy[k] == OM0) return;\n\
    \        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);\n        lazy[2 * k +\
    \ 1] = h(lazy[2 * k + 1], lazy[k]);\n        data[k] = apply(k);\n        lazy[k]\
    \ = OM0;\n    }\n\n    inline Monoid apply(int k) {\n        return lazy[k] ==\
    \ OM0 ? data[k] : g(data[k], lazy[k]);\n    }\n\n    inline void recalc(int k)\
    \ {\n        while(k >>= 1) data[k] = f(apply(2 * k + 0), apply(2 * k + 1));\n\
    \    }\n\n    inline void thrust(int k) {\n        for(int i = height; i > 0;\
    \ i--) propagate(k >> i);\n    }\n\n    void update(int a, int b, const OperatorMonoid\
    \ &x) {\n        if(a >= b) return;\n        thrust(a += sz);\n        thrust(b\
    \ += sz - 1);\n        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n\
    \            if(l & 1) lazy[l] = h(lazy[l], x), ++l;\n            if(r & 1) --r,\
    \ lazy[r] = h(lazy[r], x);\n        }\n        recalc(a);\n        recalc(b);\n\
    \    }\n\n    Monoid query(int a, int b) {\n        if(a >= b) return M1;\n  \
    \      thrust(a += sz);\n        thrust(b += sz - 1);\n        Monoid L = M1,\
    \ R = M1;\n        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n    \
    \        if(l & 1) L = f(L, apply(l++));\n            if(r & 1) R = f(apply(--r),\
    \ R);\n        }\n        return f(L, R);\n    }\n\n    Monoid operator[](const\
    \ int &k) {\n        return query(k, k + 1);\n    }\n\n    Monoid get(const int\
    \ &k) {\n        return query(k, k + 1);\n    }\n\n    void update(int i, const\
    \ OperatorMonoid &x) {\n        update(i, i+1, x);\n    }\n\n    template<typename\
    \ P=ll>\n    void print(int n) {\n        for (int i=0; i<n; i++) {\n        \
    \    cout << (P)query(i, i+1);\n            if (i == n-1) cout << endl;\n    \
    \        else cout << ' ';\n        }\n    }\n\n    template<typename C>\n   \
    \ int find_subtree(int a, const C &check, Monoid &M, bool type) {\n        while(a\
    \ < sz) {\n            propagate(a);\n            Monoid nxt = type ? f(apply(2\
    \ * a + type), M) : f(M, apply(2 * a + type));\n            if(check(nxt)) a =\
    \ 2 * a + type;\n            else M = nxt, a = 2 * a + 1 - type;\n        }\n\
    \        return a - sz;\n    }\n\n    // \u533A\u9593[a,N)\u3067check\u306E\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u6700\u5C0F\u4F4D\u7F6E\u3092\
    \u8FD4\u3059(\u306A\u3051\u308C\u3070-1)\n    template<typename C>\n    int find_first(int\
    \ a, const C &check) {\n        Monoid L = M1;\n        if(a <= 0) {\n       \
    \     if(check(f(L, apply(1)))) return find_subtree(1, check, L, false);\n   \
    \         return -1;\n        }\n        thrust(a + sz);\n        int b = sz;\n\
    \        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {\n            if(a &\
    \ 1) {\n                Monoid nxt = f(L, apply(a));\n                if(check(nxt))\
    \ return find_subtree(a, check, L, false);\n                L = nxt;\n       \
    \         ++a;\n            }\n        }\n        return -1;\n    }\n\n    //\
    \ \u533A\u9593[0,b)\u3067check\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306A\u6700\u5927\u4F4D\u7F6E\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070\
    -1)\n    template<typename C>\n    int find_last(int b, const C &check) {\n  \
    \      Monoid R = M1;\n        if(b >= sz) {\n            if(check(f(apply(1),\
    \ R))) return find_subtree(1, check, R, true);\n            return -1;\n     \
    \   }\n        thrust(b + sz - 1);\n        int a = sz;\n        for(b += sz;\
    \ a < b; a >>= 1, b >>= 1) {\n            if(b & 1) {\n                Monoid\
    \ nxt = f(apply(--b), R);\n                if(check(nxt)) return find_subtree(b,\
    \ check, R, true);\n                R = nxt;\n            }\n        }\n     \
    \   return -1;\n    }\n};\n\ntemplate<typename F, typename G, typename H, typename\
    \ T, typename E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(const F&\
    \ f, const G& g, const H& h, const T& ti, const E& ei) {\n    return {f, g, h,\
    \ ti, ei};\n}\n\ntemplate<typename F, typename G, typename H, typename T, typename\
    \ E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(int N, const F& f,\
    \ const G& g, const H& h, const T& ti, const E& ei) {\n    return {N, f, g, h,\
    \ ti, ei};\n}\n\ntemplate<typename F, typename G, typename H, typename T, typename\
    \ E>\nLazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(const vector<T> &A,\
    \ const F& f, const G& g, const H& h, const T& ti, const E& ei) {\n    return\
    \ {A, f, g, h, ti, ei};\n}\n#line 3 \"src/datastructure/LazySegmentTreeArithmetric.hpp\"\
    \n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp\n\
    // \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728(\u7B49\u5DEE\u6570\
    \u5217\u7528)\ntemplate<typename F, typename G, typename H, typename Monoid, typename\
    \ OperatorMonoid>\nstruct LazySegmentTreeArithmetric : LazySegmentTree<F, G, H,\
    \ Monoid, OperatorMonoid> {\n    using LazySegmentTreeType = LazySegmentTree<F,\
    \ G, H, Monoid, OperatorMonoid>;\n    using LazySegmentTreeType::LazySegmentTree;\n\
    \n    void update(int l, int r, const OperatorMonoid& func) {\n        LazySegmentTreeType::update(\n\
    \            l, r, { func.a, func.b - func.a * LazySegmentTreeType::get(l).left\
    \ }\n        );\n    }\n\n    void update(int i, const OperatorMonoid& func) {\n\
    \        LazySegmentTreeType::update(\n            i, { func.a, func.b - func.a\
    \ * LazySegmentTreeType::get(i).left }\n        );\n    }\n};\n\ntemplate<typename\
    \ F, typename G, typename H, typename T, typename E>\nLazySegmentTreeArithmetric<F,\
    \ G, H, T, E> get_lazy_segment_tree_arithmetric(\n    const F& f,\n    const G&\
    \ g,\n    const H& h,\n    const T& ti,\n    const E& ei\n) {\n    return {f,\
    \ g, h, ti, ei};\n}\n\ntemplate<typename F, typename G, typename H, typename T,\
    \ typename E>\nLazySegmentTreeArithmetric<F, G, H, T, E> get_lazy_segment_tree_arithmetric(\n\
    \    int N,\n    const F& f,\n    const G& g,\n    const H& h,\n    const T& ti,\n\
    \    const E& ei\n) {\n    return {N, f, g, h, ti, ei};\n}\n"
  code: "#include \"../macros.hpp\"\n#include \"LazySegmentTree.hpp\"\n\n// \u53C2\
    \u8003\uFF1Ahttps://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp\n\
    // \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728(\u7B49\u5DEE\u6570\
    \u5217\u7528)\ntemplate<typename F, typename G, typename H, typename Monoid, typename\
    \ OperatorMonoid>\nstruct LazySegmentTreeArithmetric : LazySegmentTree<F, G, H,\
    \ Monoid, OperatorMonoid> {\n    using LazySegmentTreeType = LazySegmentTree<F,\
    \ G, H, Monoid, OperatorMonoid>;\n    using LazySegmentTreeType::LazySegmentTree;\n\
    \n    void update(int l, int r, const OperatorMonoid& func) {\n        LazySegmentTreeType::update(\n\
    \            l, r, { func.a, func.b - func.a * LazySegmentTreeType::get(l).left\
    \ }\n        );\n    }\n\n    void update(int i, const OperatorMonoid& func) {\n\
    \        LazySegmentTreeType::update(\n            i, { func.a, func.b - func.a\
    \ * LazySegmentTreeType::get(i).left }\n        );\n    }\n};\n\ntemplate<typename\
    \ F, typename G, typename H, typename T, typename E>\nLazySegmentTreeArithmetric<F,\
    \ G, H, T, E> get_lazy_segment_tree_arithmetric(\n    const F& f,\n    const G&\
    \ g,\n    const H& h,\n    const T& ti,\n    const E& ei\n) {\n    return {f,\
    \ g, h, ti, ei};\n}\n\ntemplate<typename F, typename G, typename H, typename T,\
    \ typename E>\nLazySegmentTreeArithmetric<F, G, H, T, E> get_lazy_segment_tree_arithmetric(\n\
    \    int N,\n    const F& f,\n    const G& g,\n    const H& h,\n    const T& ti,\n\
    \    const E& ei\n) {\n    return {N, f, g, h, ti, ei};\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/datastructure/LazySegmentTree.hpp
  isVerificationFile: false
  path: src/datastructure/LazySegmentTreeArithmetric.hpp
  requiredBy: []
  timestamp: '2022-10-18 16:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/LazySegmentTreeArithmetric.hpp
layout: document
redirect_from:
- /library/src/datastructure/LazySegmentTreeArithmetric.hpp
- /library/src/datastructure/LazySegmentTreeArithmetric.hpp.html
title: src/datastructure/LazySegmentTreeArithmetric.hpp
---