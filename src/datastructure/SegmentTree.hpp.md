---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/string/SuffixArray.hpp
    title: src/string/SuffixArray.hpp
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
    using namespace std;\n#line 3 \"src/datastructure/SegmentTree.hpp\"\n\ntemplate<typename\
    \ Monoid, typename F>\nstruct SegmentTree {\n\n    int sz, n;\n    vector<Monoid>\
    \ seg;\n\n    const F f;\n    const Monoid M1;\n\n    SegmentTree(int n, const\
    \ F f, const Monoid &M1) : n(n), f(f), M1(M1) {\n        sz = 1;\n        while\
    \ (sz < n) sz <<= 1;\n        seg.assign(2 * sz, M1);\n    }\n\n    SegmentTree(const\
    \ F f, const Monoid &M1) : f(f), M1(M1) {\n    }\n\n    SegmentTree(const vector<Monoid>\
    \ &A, const F f, const Monoid &M1)\n        : f(f),\n          M1(M1) {\n    \
    \    build(A);\n    }\n\n    void resize(int n) {\n        this->n = n;\n    \
    \    sz = 1;\n        while (sz < n) sz <<= 1;\n        seg.resize(2 * sz, M1);\n\
    \    }\n\n    void clear() {\n        seg.clear();\n    }\n\n    void set(int\
    \ k, const Monoid &x) {\n        seg[k + sz] = x;\n    }\n\n    void build() {\n\
    \        for (int k = sz - 1; k > 0; k--) {\n            seg[k] = f(seg[2 * k],\
    \ seg[2 * k + 1]);\n        }\n    }\n\n    void build(const vector<Monoid> &A)\
    \ {\n        n = A.size();\n        resize(n);\n        rep(i, n) set(i, A[i]);\n\
    \        build();\n    }\n\n    void update(int k, const Monoid &x) {\n      \
    \  k += sz;\n        seg[k] = x;\n        while (k >>= 1) {\n            seg[k]\
    \ = f(seg[2 * k], seg[2 * k + 1]);\n        }\n    }\n\n    Monoid query(int a,\
    \ int b) {\n        Monoid L = M1, R = M1;\n        for (a += sz, b += sz; a <\
    \ b; a >>= 1, b >>= 1) {\n            if (a & 1) L = f(L, seg[a++]);\n       \
    \     if (b & 1) R = f(seg[--b], R);\n        }\n        return f(L, R);\n   \
    \ }\n\n    Monoid operator[](const int &k) const {\n        return seg[k + sz];\n\
    \    }\n\n    Monoid all() {\n        return seg[1];\n    }\n\n    int size()\
    \ {\n        return n;\n    }\n\n    template<typename C>\n    int find_subtree(int\
    \ a, const C &check, Monoid &M, bool type) {\n        while (a < sz) {\n     \
    \       Monoid nxt =\n                type ? f(seg[2 * a + type], M) : f(M, seg[2\
    \ * a + type]);\n            if (check(nxt)) a = 2 * a + type;\n            else\
    \ M = nxt, a = 2 * a + 1 - type;\n        }\n        return a - sz;\n    }\n\n\
    \    // \u7BC4\u56F2[a,N)\u3067check\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u3088\u3046\u306A\u6700\u5C0F\u4F4D\u7F6E\u3092\u8FD4\u3059(\u306A\u3051\u308C\
    \u3070-1)\n    template<typename C>\n    int find_first(int a, const C &check)\
    \ {\n        Monoid L = M1;\n        if (a <= 0) {\n            if (check(f(L,\
    \ seg[1]))) return find_subtree(1, check, L, false);\n            return -1;\n\
    \        }\n        int b = sz;\n        for (a += sz, b += sz; a < b; a >>= 1,\
    \ b >>= 1) {\n            if (a & 1) {\n                Monoid nxt = f(L, seg[a]);\n\
    \                if (check(nxt)) return find_subtree(a, check, L, false);\n  \
    \              L = nxt;\n                ++a;\n            }\n        }\n    \
    \    return -1;\n    }\n\n    // \u7BC4\u56F2[0,b)\u3067check\u306E\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u6700\u5927\u4F4D\u7F6E\u3092\u8FD4\
    \u3059(\u306A\u3051\u308C\u3070-1)\n    template<typename C>\n    int find_last(int\
    \ b, const C &check) {\n        Monoid R = M1;\n        if (b >= sz) {\n     \
    \       if (check(f(seg[1], R))) return find_subtree(1, check, R, true);\n   \
    \         return -1;\n        }\n        int a = sz;\n        for (b += sz; a\
    \ < b; a >>= 1, b >>= 1) {\n            if (b & 1) {\n                Monoid nxt\
    \ = f(seg[--b], R);\n                if (check(nxt)) return find_subtree(b, check,\
    \ R, true);\n                R = nxt;\n            }\n        }\n        return\
    \ -1;\n    }\n};\n\ntemplate<typename Monoid, typename F>\nSegmentTree<Monoid,\
    \ F> get_segment_tree(int N, const F &f, const Monoid &M1) {\n    return {N, f,\
    \ M1};\n}\n\ntemplate<typename Monoid, typename F>\nSegmentTree<Monoid, F> get_segment_tree(const\
    \ F &f, const Monoid &M1) {\n    return {f, M1};\n}\n\ntemplate<typename Monoid,\
    \ typename F>\nSegmentTree<Monoid, F> get_segment_tree(\n    const vector<Monoid>\
    \ &A,\n    const F &f,\n    const Monoid &M1\n) {\n    return {A, f, M1};\n}\n\
    \ntemplate<typename Monoid, typename F>\nostream &operator<<(ostream &os, SegmentTree<Monoid,\
    \ F> &seg) {\n    rep(i, seg.size()) {\n        os << seg[i];\n        if (i !=\
    \ seg.size() - 1) {\n            os << ' ';\n        }\n    }\n    return os;\n\
    }\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename Monoid, typename\
    \ F>\nstruct SegmentTree {\n\n    int sz, n;\n    vector<Monoid> seg;\n\n    const\
    \ F f;\n    const Monoid M1;\n\n    SegmentTree(int n, const F f, const Monoid\
    \ &M1) : n(n), f(f), M1(M1) {\n        sz = 1;\n        while (sz < n) sz <<=\
    \ 1;\n        seg.assign(2 * sz, M1);\n    }\n\n    SegmentTree(const F f, const\
    \ Monoid &M1) : f(f), M1(M1) {\n    }\n\n    SegmentTree(const vector<Monoid>\
    \ &A, const F f, const Monoid &M1)\n        : f(f),\n          M1(M1) {\n    \
    \    build(A);\n    }\n\n    void resize(int n) {\n        this->n = n;\n    \
    \    sz = 1;\n        while (sz < n) sz <<= 1;\n        seg.resize(2 * sz, M1);\n\
    \    }\n\n    void clear() {\n        seg.clear();\n    }\n\n    void set(int\
    \ k, const Monoid &x) {\n        seg[k + sz] = x;\n    }\n\n    void build() {\n\
    \        for (int k = sz - 1; k > 0; k--) {\n            seg[k] = f(seg[2 * k],\
    \ seg[2 * k + 1]);\n        }\n    }\n\n    void build(const vector<Monoid> &A)\
    \ {\n        n = A.size();\n        resize(n);\n        rep(i, n) set(i, A[i]);\n\
    \        build();\n    }\n\n    void update(int k, const Monoid &x) {\n      \
    \  k += sz;\n        seg[k] = x;\n        while (k >>= 1) {\n            seg[k]\
    \ = f(seg[2 * k], seg[2 * k + 1]);\n        }\n    }\n\n    Monoid query(int a,\
    \ int b) {\n        Monoid L = M1, R = M1;\n        for (a += sz, b += sz; a <\
    \ b; a >>= 1, b >>= 1) {\n            if (a & 1) L = f(L, seg[a++]);\n       \
    \     if (b & 1) R = f(seg[--b], R);\n        }\n        return f(L, R);\n   \
    \ }\n\n    Monoid operator[](const int &k) const {\n        return seg[k + sz];\n\
    \    }\n\n    Monoid all() {\n        return seg[1];\n    }\n\n    int size()\
    \ {\n        return n;\n    }\n\n    template<typename C>\n    int find_subtree(int\
    \ a, const C &check, Monoid &M, bool type) {\n        while (a < sz) {\n     \
    \       Monoid nxt =\n                type ? f(seg[2 * a + type], M) : f(M, seg[2\
    \ * a + type]);\n            if (check(nxt)) a = 2 * a + type;\n            else\
    \ M = nxt, a = 2 * a + 1 - type;\n        }\n        return a - sz;\n    }\n\n\
    \    // \u7BC4\u56F2[a,N)\u3067check\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u3088\u3046\u306A\u6700\u5C0F\u4F4D\u7F6E\u3092\u8FD4\u3059(\u306A\u3051\u308C\
    \u3070-1)\n    template<typename C>\n    int find_first(int a, const C &check)\
    \ {\n        Monoid L = M1;\n        if (a <= 0) {\n            if (check(f(L,\
    \ seg[1]))) return find_subtree(1, check, L, false);\n            return -1;\n\
    \        }\n        int b = sz;\n        for (a += sz, b += sz; a < b; a >>= 1,\
    \ b >>= 1) {\n            if (a & 1) {\n                Monoid nxt = f(L, seg[a]);\n\
    \                if (check(nxt)) return find_subtree(a, check, L, false);\n  \
    \              L = nxt;\n                ++a;\n            }\n        }\n    \
    \    return -1;\n    }\n\n    // \u7BC4\u56F2[0,b)\u3067check\u306E\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u6700\u5927\u4F4D\u7F6E\u3092\u8FD4\
    \u3059(\u306A\u3051\u308C\u3070-1)\n    template<typename C>\n    int find_last(int\
    \ b, const C &check) {\n        Monoid R = M1;\n        if (b >= sz) {\n     \
    \       if (check(f(seg[1], R))) return find_subtree(1, check, R, true);\n   \
    \         return -1;\n        }\n        int a = sz;\n        for (b += sz; a\
    \ < b; a >>= 1, b >>= 1) {\n            if (b & 1) {\n                Monoid nxt\
    \ = f(seg[--b], R);\n                if (check(nxt)) return find_subtree(b, check,\
    \ R, true);\n                R = nxt;\n            }\n        }\n        return\
    \ -1;\n    }\n};\n\ntemplate<typename Monoid, typename F>\nSegmentTree<Monoid,\
    \ F> get_segment_tree(int N, const F &f, const Monoid &M1) {\n    return {N, f,\
    \ M1};\n}\n\ntemplate<typename Monoid, typename F>\nSegmentTree<Monoid, F> get_segment_tree(const\
    \ F &f, const Monoid &M1) {\n    return {f, M1};\n}\n\ntemplate<typename Monoid,\
    \ typename F>\nSegmentTree<Monoid, F> get_segment_tree(\n    const vector<Monoid>\
    \ &A,\n    const F &f,\n    const Monoid &M1\n) {\n    return {A, f, M1};\n}\n\
    \ntemplate<typename Monoid, typename F>\nostream &operator<<(ostream &os, SegmentTree<Monoid,\
    \ F> &seg) {\n    rep(i, seg.size()) {\n        os << seg[i];\n        if (i !=\
    \ seg.size() - 1) {\n            os << ' ';\n        }\n    }\n    return os;\n\
    }\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/SegmentTree.hpp
  requiredBy:
  - src/string/SuffixArray.hpp
  - src/template.hpp
  timestamp: '2023-12-11 16:15:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/src/datastructure/SegmentTree.hpp
- /library/src/datastructure/SegmentTree.hpp.html
title: src/datastructure/SegmentTree.hpp
---
