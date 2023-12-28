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
    links:
    - https://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/datastructure/PersistentSegmentTree.hpp\"\n\
    \n// \u6C38\u7D9A\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.cpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u57FA\u672C\u7684\u306B\u306F\u666E\u901A\u306E\
    \u30BB\u30B0\u6728\u3068\u4E00\u7DD2\u3002\u305F\u3060\u3057\u66F4\u65B0\u30FB\
    \u53D6\u5F97\u3068\u3082\u306B\u6642\u70B9\u3092\u793A\u3059\u30DD\u30A4\u30F3\
    \u30BF\u3092\u5F15\u6570\u306B\u6E21\u3059\u5FC5\u8981\u304C\u3042\u308B\u3002\
    \n// \u30FB\u66F4\u65B0(\u3068\u521D\u671F\u5316)\u306E\u6642\u306B\u305D\u306E\
    \u66F4\u65B0\u5B8C\u4E86\u6642\u70B9\u306E\u30DD\u30A4\u30F3\u30BF\u304C\u8FD4\
    \u308B\u306E\u3067\u3001\n// \u3000\u305D\u308C\u3092\u914D\u5217\u3068\u304B\u306B\
    \u4FDD\u6301\u3057\u3066\u304A\u304F\u3068\u3001\u4EFB\u610F\u306E\u6642\u70B9\
    \u306E\u60C5\u5831\u3092\u53D6\u308A\u51FA\u305B\u308B\u3002(\u5B9F\u88C5\u4F8B\
    \u306Fabc253_f\u3092\u53C2\u7167)\n// \u30FB\u4ED5\u69D8\u5909\u3048\u305F\u3002\
    \u66F4\u65B0\u30FB\u53D6\u5F97\u6642\u306B\u306F\u30DD\u30A4\u30F3\u30BF\u6E21\
    \u3057\u305F\u308A\u3057\u306A\u304F\u3066\u3088\u304F\u3066\u3001\n// \u3000\u72B6\
    \u614B\u3092\u4FDD\u6301\u3057\u305F\u3044\u6642\u306B\u4F7F\u3046save\u3068\u5FA9\
    \u5143\u3057\u305F\u3044\u6642\u306B\u4F7F\u3046load\u3092\u5B9F\u88C5\u3057\u305F\
    \u3002\ntemplate<typename Monoid, typename F>\nstruct PersistentSegmentTree {\n\
    \n    struct Node {\n        Monoid data;\n        Node *l, *r;\n\n        Node(const\
    \ Monoid &data) : data(data), l(nullptr), r(nullptr) {}\n    };\n\n    int sz;\n\
    \    const F f;\n    const Monoid M1;\n    Node *root;\n\n    PersistentSegmentTree(const\
    \ F f, const Monoid &M1) : f(f), M1(M1) {}\n\n    void build(const vector<Monoid>\
    \ &v) {\n        sz = (int)v.size();\n        root = build(0, (int)v.size(), v);\n\
    \    }\n\n    Node *merge(Node *l, Node *r) {\n        auto t = new Node(f(l->data,\
    \ r->data));\n        t->l = l;\n        t->r = r;\n        return t;\n    }\n\
    \n    Node *build(int l, int r, const vector<Monoid> &v) {\n        if (l + 1\
    \ >= r) return new Node(v[l]);\n        return merge(build(l, (l + r) >> 1, v),\
    \ build((l + r) >> 1, r, v));\n    }\n\n    Node *update(int a, const Monoid &x,\
    \ Node *k, int l, int r) {\n        if (r <= a || a + 1 <= l) {\n            return\
    \ k;\n        } else if (a <= l && r <= a + 1) {\n            return new Node(x);\n\
    \        } else {\n            return merge(\n                update(a, x, k->l,\
    \ l, (l + r) >> 1),\n                update(a, x, k->r, (l + r) >> 1, r)\n   \
    \         );\n        }\n    }\n\n    void update(int k, const Monoid &x) {\n\
    \        root = update(k, x, root, 0, sz);\n    }\n\n    Monoid query(int a, int\
    \ b, Node *k, int l, int r) {\n        if (r <= a || b <= l) {\n            return\
    \ M1;\n        } else if (a <= l && r <= b) {\n            return k->data;\n \
    \       } else {\n            return f(\n                query(a, b, k->l, l,\
    \ (l + r) >> 1),\n                query(a, b, k->r, (l + r) >> 1, r)\n       \
    \     );\n        }\n    }\n\n    Monoid query(int a, int b) {\n        return\
    \ query(a, b, root, 0, sz);\n    }\n\n    Monoid all() {\n        return root->data;\n\
    \    }\n\n    Monoid get(int i) {\n        return query(i, i + 1);\n    }\n\n\
    \    void print(int n) {\n        for (int i = 0; i < n; i++) {\n            cout\
    \ << query(root, i, i + 1);\n            if (i == n - 1) cout << endl;\n     \
    \       else cout << ' ';\n        }\n    }\n\n    Node *save() {\n        return\
    \ root;\n    }\n\n    void load(Node *p) {\n        root = p;\n    }\n};\n\ntemplate<typename\
    \ Monoid, typename F>\nPersistentSegmentTree<Monoid, F>\nget_persistent_segment_tree(const\
    \ F &f, const Monoid &M1) {\n    return {f, M1};\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u6C38\u7D9A\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.cpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u57FA\u672C\u7684\u306B\u306F\u666E\u901A\u306E\
    \u30BB\u30B0\u6728\u3068\u4E00\u7DD2\u3002\u305F\u3060\u3057\u66F4\u65B0\u30FB\
    \u53D6\u5F97\u3068\u3082\u306B\u6642\u70B9\u3092\u793A\u3059\u30DD\u30A4\u30F3\
    \u30BF\u3092\u5F15\u6570\u306B\u6E21\u3059\u5FC5\u8981\u304C\u3042\u308B\u3002\
    \n// \u30FB\u66F4\u65B0(\u3068\u521D\u671F\u5316)\u306E\u6642\u306B\u305D\u306E\
    \u66F4\u65B0\u5B8C\u4E86\u6642\u70B9\u306E\u30DD\u30A4\u30F3\u30BF\u304C\u8FD4\
    \u308B\u306E\u3067\u3001\n// \u3000\u305D\u308C\u3092\u914D\u5217\u3068\u304B\u306B\
    \u4FDD\u6301\u3057\u3066\u304A\u304F\u3068\u3001\u4EFB\u610F\u306E\u6642\u70B9\
    \u306E\u60C5\u5831\u3092\u53D6\u308A\u51FA\u305B\u308B\u3002(\u5B9F\u88C5\u4F8B\
    \u306Fabc253_f\u3092\u53C2\u7167)\n// \u30FB\u4ED5\u69D8\u5909\u3048\u305F\u3002\
    \u66F4\u65B0\u30FB\u53D6\u5F97\u6642\u306B\u306F\u30DD\u30A4\u30F3\u30BF\u6E21\
    \u3057\u305F\u308A\u3057\u306A\u304F\u3066\u3088\u304F\u3066\u3001\n// \u3000\u72B6\
    \u614B\u3092\u4FDD\u6301\u3057\u305F\u3044\u6642\u306B\u4F7F\u3046save\u3068\u5FA9\
    \u5143\u3057\u305F\u3044\u6642\u306B\u4F7F\u3046load\u3092\u5B9F\u88C5\u3057\u305F\
    \u3002\ntemplate<typename Monoid, typename F>\nstruct PersistentSegmentTree {\n\
    \n    struct Node {\n        Monoid data;\n        Node *l, *r;\n\n        Node(const\
    \ Monoid &data) : data(data), l(nullptr), r(nullptr) {}\n    };\n\n    int sz;\n\
    \    const F f;\n    const Monoid M1;\n    Node *root;\n\n    PersistentSegmentTree(const\
    \ F f, const Monoid &M1) : f(f), M1(M1) {}\n\n    void build(const vector<Monoid>\
    \ &v) {\n        sz = (int)v.size();\n        root = build(0, (int)v.size(), v);\n\
    \    }\n\n    Node *merge(Node *l, Node *r) {\n        auto t = new Node(f(l->data,\
    \ r->data));\n        t->l = l;\n        t->r = r;\n        return t;\n    }\n\
    \n    Node *build(int l, int r, const vector<Monoid> &v) {\n        if (l + 1\
    \ >= r) return new Node(v[l]);\n        return merge(build(l, (l + r) >> 1, v),\
    \ build((l + r) >> 1, r, v));\n    }\n\n    Node *update(int a, const Monoid &x,\
    \ Node *k, int l, int r) {\n        if (r <= a || a + 1 <= l) {\n            return\
    \ k;\n        } else if (a <= l && r <= a + 1) {\n            return new Node(x);\n\
    \        } else {\n            return merge(\n                update(a, x, k->l,\
    \ l, (l + r) >> 1),\n                update(a, x, k->r, (l + r) >> 1, r)\n   \
    \         );\n        }\n    }\n\n    void update(int k, const Monoid &x) {\n\
    \        root = update(k, x, root, 0, sz);\n    }\n\n    Monoid query(int a, int\
    \ b, Node *k, int l, int r) {\n        if (r <= a || b <= l) {\n            return\
    \ M1;\n        } else if (a <= l && r <= b) {\n            return k->data;\n \
    \       } else {\n            return f(\n                query(a, b, k->l, l,\
    \ (l + r) >> 1),\n                query(a, b, k->r, (l + r) >> 1, r)\n       \
    \     );\n        }\n    }\n\n    Monoid query(int a, int b) {\n        return\
    \ query(a, b, root, 0, sz);\n    }\n\n    Monoid all() {\n        return root->data;\n\
    \    }\n\n    Monoid get(int i) {\n        return query(i, i + 1);\n    }\n\n\
    \    void print(int n) {\n        for (int i = 0; i < n; i++) {\n            cout\
    \ << query(root, i, i + 1);\n            if (i == n - 1) cout << endl;\n     \
    \       else cout << ' ';\n        }\n    }\n\n    Node *save() {\n        return\
    \ root;\n    }\n\n    void load(Node *p) {\n        root = p;\n    }\n};\n\ntemplate<typename\
    \ Monoid, typename F>\nPersistentSegmentTree<Monoid, F>\nget_persistent_segment_tree(const\
    \ F &f, const Monoid &M1) {\n    return {f, M1};\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/PersistentSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/PersistentSegmentTree.hpp
layout: document
redirect_from:
- /library/src/datastructure/PersistentSegmentTree.hpp
- /library/src/datastructure/PersistentSegmentTree.hpp.html
title: src/datastructure/PersistentSegmentTree.hpp
---
