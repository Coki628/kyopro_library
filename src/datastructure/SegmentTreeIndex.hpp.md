---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
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
    \ namespace std;\n#line 3 \"src/datastructure/SegmentTreeIndex.hpp\"\n\ntemplate<typename\
    \ Monoid, typename F>\nstruct SegmentTreeIndex {\n    int sz;\n    vector<pair<Monoid,\
    \ int>> seg;\n\n    const F f;\n    const Monoid M1;\n\n    pair<Monoid, int>\
    \ compare(\n        const pair<Monoid, int> &a, const pair<Monoid, int> &b\n \
    \   ) {\n        if (a.first == b.first) {\n            // \u540C\u5024\u306F\
    index\u304C\u5C0F\u3055\u3044\u65B9\u512A\u5148\n            if (a.second <= b.second)\
    \ {\n                return a;\n            } else {\n                return b;\n\
    \            }\n        } else if (f(a.first, b.first) == a.first) {\n       \
    \     return a;\n        } else {\n            return b;\n        }\n    }\n\n\
    \    SegmentTreeIndex(int n, const F f, const Monoid &M1) : f(f), M1(M1) {\n \
    \       sz = 1;\n        while (sz < n) sz <<= 1;\n        seg.assign(2 * sz,\
    \ {M1, -1});\n    }\n\n    SegmentTreeIndex(const F f, const Monoid &M1) : f(f),\
    \ M1(M1) {}\n\n    void resize(int n) {\n        sz = 1;\n        while (sz <\
    \ n) sz <<= 1;\n        seg.assign(2 * sz, {M1, -1});\n    }\n\n    void set(int\
    \ k, const Monoid &x) {\n        seg[k + sz] = {x, k};\n    }\n\n    void build()\
    \ {\n        for (int k = sz - 1; k > 0; k--) {\n            seg[k] = compare(seg[2\
    \ * k], seg[2 * k + 1]);\n        }\n    }\n\n    void build(const vector<Monoid>\
    \ &A) {\n        int n = A.size();\n        resize(n);\n        for (int i = 0;\
    \ i < n; i++) set(i, A[i]);\n        build();\n    }\n\n    void update(int k,\
    \ const Monoid &x) {\n        k += sz;\n        seg[k] = {x, k - sz};\n      \
    \  while (k >>= 1) {\n            seg[k] = compare(seg[2 * k], seg[2 * k + 1]);\n\
    \        }\n    }\n\n    void add(int k, const Monoid &x) {\n        update(k,\
    \ seg[k + sz].first + x);\n    }\n\n    pair<Monoid, int> query(int a, int b)\
    \ {\n        pair<Monoid, int> L = {M1, -1}, R = {M1, -1};\n        for (a +=\
    \ sz, b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a & 1) L = compare(L,\
    \ seg[a++]);\n            if (b & 1) R = compare(seg[--b], R);\n        }\n  \
    \      return compare(L, R);\n    }\n\n    Monoid operator[](const int &k) const\
    \ {\n        return seg[k + sz].first;\n    }\n\n    pair<Monoid, int> all() {\n\
    \        return seg[1];\n    }\n\n    void print(int n) {\n        for (int i\
    \ = 0; i < n; i++) {\n            cout << query(i, i + 1).first;\n           \
    \ if (i == n - 1) cout << endl;\n            else cout << ' ';\n        }\n  \
    \  }\n};\n\ntemplate<typename Monoid, typename F>\nSegmentTreeIndex<Monoid, F>\
    \ get_segment_tree_index(int N, const F &f, const Monoid &M1) {\n    return {N,\
    \ f, M1};\n}\n\ntemplate<typename Monoid, typename F>\nSegmentTreeIndex<Monoid,\
    \ F> get_segment_tree_index(const F &f, const Monoid &M1) {\n    return {f, M1};\n\
    }\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate<typename Monoid, typename\
    \ F>\nstruct SegmentTreeIndex {\n    int sz;\n    vector<pair<Monoid, int>> seg;\n\
    \n    const F f;\n    const Monoid M1;\n\n    pair<Monoid, int> compare(\n   \
    \     const pair<Monoid, int> &a, const pair<Monoid, int> &b\n    ) {\n      \
    \  if (a.first == b.first) {\n            // \u540C\u5024\u306Findex\u304C\u5C0F\
    \u3055\u3044\u65B9\u512A\u5148\n            if (a.second <= b.second) {\n    \
    \            return a;\n            } else {\n                return b;\n    \
    \        }\n        } else if (f(a.first, b.first) == a.first) {\n           \
    \ return a;\n        } else {\n            return b;\n        }\n    }\n\n   \
    \ SegmentTreeIndex(int n, const F f, const Monoid &M1) : f(f), M1(M1) {\n    \
    \    sz = 1;\n        while (sz < n) sz <<= 1;\n        seg.assign(2 * sz, {M1,\
    \ -1});\n    }\n\n    SegmentTreeIndex(const F f, const Monoid &M1) : f(f), M1(M1)\
    \ {}\n\n    void resize(int n) {\n        sz = 1;\n        while (sz < n) sz <<=\
    \ 1;\n        seg.assign(2 * sz, {M1, -1});\n    }\n\n    void set(int k, const\
    \ Monoid &x) {\n        seg[k + sz] = {x, k};\n    }\n\n    void build() {\n \
    \       for (int k = sz - 1; k > 0; k--) {\n            seg[k] = compare(seg[2\
    \ * k], seg[2 * k + 1]);\n        }\n    }\n\n    void build(const vector<Monoid>\
    \ &A) {\n        int n = A.size();\n        resize(n);\n        for (int i = 0;\
    \ i < n; i++) set(i, A[i]);\n        build();\n    }\n\n    void update(int k,\
    \ const Monoid &x) {\n        k += sz;\n        seg[k] = {x, k - sz};\n      \
    \  while (k >>= 1) {\n            seg[k] = compare(seg[2 * k], seg[2 * k + 1]);\n\
    \        }\n    }\n\n    void add(int k, const Monoid &x) {\n        update(k,\
    \ seg[k + sz].first + x);\n    }\n\n    pair<Monoid, int> query(int a, int b)\
    \ {\n        pair<Monoid, int> L = {M1, -1}, R = {M1, -1};\n        for (a +=\
    \ sz, b += sz; a < b; a >>= 1, b >>= 1) {\n            if (a & 1) L = compare(L,\
    \ seg[a++]);\n            if (b & 1) R = compare(seg[--b], R);\n        }\n  \
    \      return compare(L, R);\n    }\n\n    Monoid operator[](const int &k) const\
    \ {\n        return seg[k + sz].first;\n    }\n\n    pair<Monoid, int> all() {\n\
    \        return seg[1];\n    }\n\n    void print(int n) {\n        for (int i\
    \ = 0; i < n; i++) {\n            cout << query(i, i + 1).first;\n           \
    \ if (i == n - 1) cout << endl;\n            else cout << ' ';\n        }\n  \
    \  }\n};\n\ntemplate<typename Monoid, typename F>\nSegmentTreeIndex<Monoid, F>\
    \ get_segment_tree_index(int N, const F &f, const Monoid &M1) {\n    return {N,\
    \ f, M1};\n}\n\ntemplate<typename Monoid, typename F>\nSegmentTreeIndex<Monoid,\
    \ F> get_segment_tree_index(const F &f, const Monoid &M1) {\n    return {f, M1};\n\
    }\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/SegmentTreeIndex.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/SegmentTreeIndex.hpp
layout: document
redirect_from:
- /library/src/datastructure/SegmentTreeIndex.hpp
- /library/src/datastructure/SegmentTreeIndex.hpp.html
title: src/datastructure/SegmentTreeIndex.hpp
---
