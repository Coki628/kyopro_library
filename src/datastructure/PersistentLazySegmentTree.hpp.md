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
    - https://suisen-cp.github.io/cp-library-cpp/library/datastructure/segment_tree/persistent_lazy_segment_tree.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/datastructure/PersistentLazySegmentTree.hpp\"\
    \n\n// \u6C38\u7D9A\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n// \u53C2\
    \u8003\uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/datastructure/segment_tree/persistent_lazy_segment_tree.hpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u57FA\u672C\u7684\u306B\u306F\u666E\u901A\u306E\
    \u6C38\u7D9A\u30BB\u30B0\u6728\u3068\u4E00\u7DD2\u3002(\u4F7F\u7528\u4F8B\u306F\
    abc253_f\u3092\u53C2\u7167)\n// \u30FB\u30E1\u30E2\u30EA\u3092\u4E88\u3081\u78BA\
    \u4FDD\u3067\u304D\u308B\u6A5F\u69CB\u304C\u5099\u308F\u3063\u3066\u308B\u3002\
    (\u305D\u306E\u65B9\u304C\u52D5\u7684\u78BA\u4FDD\u3088\u308A\u30E1\u30E2\u30EA\
    \u98DF\u308F\u306A\u3044\u3057\u3001\u901F\u3044\u3002)\n// \u3000\u521D\u671F\
    \u5316\u5F8C\u306B\u3001init_pool\u3092\u547C\u3073\u51FA\u3057\u3066\u3001\u8981\
    \u7D20\u3092\u78BA\u4FDD\u3057\u3066\u3084\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \u3002\n// \u3000\u5177\u4F53\u7684\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\u2192init_pool\u2192build\u306E\u9806\u3067\u6E96\u5099\u3059\u308B\
    \u3002\ntemplate<typename F, typename G, typename H, typename Monoid, typename\
    \ OperatorMonoid>\nstruct PersistentLazySegmentTree {\n    int sz;\n    const\
    \ F f;\n    const G g;\n    const H h;\n    const Monoid M1;\n    const OperatorMonoid\
    \ OM0;\n\n    struct Node {\n        static inline ObjectPool<Node> _pool;\n \
    \       static Node *clone(Node *node) {\n            return &(*_pool.alloc()\
    \ = *node);\n        }\n\n        Monoid data;\n        OperatorMonoid lazy;\n\
    \        Node *l, *r;\n\n        // \u3053\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\u304C\u306A\u3044\u3068ObjectPool\u306E\u30E1\u30E2\u30EA\u78BA\u4FDD\
    \u304C\u52D5\u304B\u306A\u3044\n        Node() {}\n\n        Node(const Monoid\
    \ &data, const OperatorMonoid &lazy)\n            : data(data),\n            \
    \  lazy(lazy),\n              l(nullptr),\n              r(nullptr) {\n      \
    \  }\n    };\n\n    PersistentLazySegmentTree(\n        const F f, const G g,\
    \ const H h, const Monoid &M1,\n        const OperatorMonoid OM0\n    )\n    \
    \    : f(f),\n          g(g),\n          h(h),\n          M1(M1),\n          OM0(OM0)\
    \ {\n    }\n\n    Node *build(const vector<Monoid> &v) {\n        sz = (int)v.size();\n\
    \        return build(0, (int)v.size(), v);\n    }\n\n    Node *merge(Node *l,\
    \ Node *r) {\n        Node *res = Node::_pool.alloc();\n        *res = Node(f(l->data,\
    \ r->data), OM0);\n        res->l = l;\n        res->r = r;\n        return res;\n\
    \    }\n\n    Node *build(int l, int r, const vector<Monoid> &v) {\n        if\
    \ (l + 1 == r) {\n            Node *res = Node::_pool.alloc();\n            return\
    \ &(*res = Node(v[l], OM0));\n        } else {\n            return merge(build(l,\
    \ (l + r) >> 1, v), build((l + r) >> 1, r, v));\n        }\n    }\n\n    template<bool\
    \ do_clone = true>\n    auto push(Node *node) {\n        Node *res = node;\n \
    \       if constexpr (do_clone) res = Node::clone(res);\n        res->l = update_all(res->l,\
    \ res->lazy);\n        res->r = update_all(res->r, res->lazy);\n        res->lazy\
    \ = OM0;\n        if constexpr (do_clone) {\n            return res;\n       \
    \ } else {\n            return;\n        }\n    }\n\n    Node *update_all(Node\
    \ *node, const OperatorMonoid &x) {\n        if (not node) return nullptr;\n \
    \       Node *res = Node::clone(node);\n        res->data = g(res->data, x);\n\
    \        res->lazy = h(res->lazy, x);\n        return res;\n    }\n\n    Node\
    \ *\n    update(int a, int b, const OperatorMonoid &x, Node *node, int l, int\
    \ r) {\n        if (r <= a || b <= l) {\n            return node;\n        } else\
    \ if (a <= l && r <= b) {\n            return update_all(node, x);\n        }\
    \ else {\n            Node *res = push(node);\n            res->l = update(a,\
    \ b, x, res->l, l, (l + r) >> 1);\n            res->r = update(a, b, x, res->r,\
    \ (l + r) >> 1, r);\n            res->data = f(res->l->data, res->r->data);\n\
    \            return res;\n        }\n    }\n\n    Node *update(Node *node, int\
    \ a, int b, const OperatorMonoid &x) {\n        return update(a, b, x, node, 0,\
    \ sz);\n    }\n\n    Node *update(Node *node, int k, const OperatorMonoid &x)\
    \ {\n        return update(node, k, k + 1, x);\n    }\n\n    Monoid\n    query(int\
    \ a, int b, Node *node, int l, int r, const OperatorMonoid &x) {\n        if (r\
    \ <= a || b <= l) {\n            return M1;\n        } else if (a <= l && r <=\
    \ b) {\n            return g(node->data, x);\n        } else {\n            OperatorMonoid\
    \ y = h(x, node->lazy);\n            return f(\n                query(a, b, node->l,\
    \ l, (l + r) >> 1, y),\n                query(a, b, node->r, (l + r) >> 1, r,\
    \ y)\n            );\n        }\n    }\n\n    Monoid query(Node *node, int a,\
    \ int b) {\n        return query(a, b, node, 0, sz, OM0);\n    }\n\n    Monoid\
    \ all(Node *node) {\n        return node ? node->data : M1;\n    }\n\n    Monoid\
    \ get(Node *node, int a) {\n        return query(node, a, a + 1);\n    }\n\n \
    \   void print(Node *node, int n) {\n        for (int i = 0; i < n; i++) {\n \
    \           cout << query(node, i, i + 1);\n            if (i == n - 1) cout <<\
    \ endl;\n            else cout << ' ';\n        }\n    }\n\n    void init_pool(int\
    \ siz) {\n        Node::_pool = ObjectPool<Node>(siz);\n    }\n    void clear_pool()\
    \ {\n        Node::_pool.clear();\n    }\n};\n\ntemplate<typename F, typename\
    \ G, typename H, typename T, typename E>\nPersistentLazySegmentTree<F, G, H, T,\
    \ E> get_persistent_lazy_segment_tree(\n    const F &f, const G &g, const H &h,\
    \ const T &ti, const E &ei\n) {\n    return {f, g, h, ti, ei};\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u6C38\u7D9A\u9045\u5EF6\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n// \u53C2\u8003\uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/datastructure/segment_tree/persistent_lazy_segment_tree.hpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u57FA\u672C\u7684\u306B\u306F\u666E\u901A\u306E\
    \u6C38\u7D9A\u30BB\u30B0\u6728\u3068\u4E00\u7DD2\u3002(\u4F7F\u7528\u4F8B\u306F\
    abc253_f\u3092\u53C2\u7167)\n// \u30FB\u30E1\u30E2\u30EA\u3092\u4E88\u3081\u78BA\
    \u4FDD\u3067\u304D\u308B\u6A5F\u69CB\u304C\u5099\u308F\u3063\u3066\u308B\u3002\
    (\u305D\u306E\u65B9\u304C\u52D5\u7684\u78BA\u4FDD\u3088\u308A\u30E1\u30E2\u30EA\
    \u98DF\u308F\u306A\u3044\u3057\u3001\u901F\u3044\u3002)\n// \u3000\u521D\u671F\
    \u5316\u5F8C\u306B\u3001init_pool\u3092\u547C\u3073\u51FA\u3057\u3066\u3001\u8981\
    \u7D20\u3092\u78BA\u4FDD\u3057\u3066\u3084\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \u3002\n// \u3000\u5177\u4F53\u7684\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\u2192init_pool\u2192build\u306E\u9806\u3067\u6E96\u5099\u3059\u308B\
    \u3002\ntemplate<typename F, typename G, typename H, typename Monoid, typename\
    \ OperatorMonoid>\nstruct PersistentLazySegmentTree {\n    int sz;\n    const\
    \ F f;\n    const G g;\n    const H h;\n    const Monoid M1;\n    const OperatorMonoid\
    \ OM0;\n\n    struct Node {\n        static inline ObjectPool<Node> _pool;\n \
    \       static Node *clone(Node *node) {\n            return &(*_pool.alloc()\
    \ = *node);\n        }\n\n        Monoid data;\n        OperatorMonoid lazy;\n\
    \        Node *l, *r;\n\n        // \u3053\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\u304C\u306A\u3044\u3068ObjectPool\u306E\u30E1\u30E2\u30EA\u78BA\u4FDD\
    \u304C\u52D5\u304B\u306A\u3044\n        Node() {}\n\n        Node(const Monoid\
    \ &data, const OperatorMonoid &lazy)\n            : data(data),\n            \
    \  lazy(lazy),\n              l(nullptr),\n              r(nullptr) {\n      \
    \  }\n    };\n\n    PersistentLazySegmentTree(\n        const F f, const G g,\
    \ const H h, const Monoid &M1,\n        const OperatorMonoid OM0\n    )\n    \
    \    : f(f),\n          g(g),\n          h(h),\n          M1(M1),\n          OM0(OM0)\
    \ {\n    }\n\n    Node *build(const vector<Monoid> &v) {\n        sz = (int)v.size();\n\
    \        return build(0, (int)v.size(), v);\n    }\n\n    Node *merge(Node *l,\
    \ Node *r) {\n        Node *res = Node::_pool.alloc();\n        *res = Node(f(l->data,\
    \ r->data), OM0);\n        res->l = l;\n        res->r = r;\n        return res;\n\
    \    }\n\n    Node *build(int l, int r, const vector<Monoid> &v) {\n        if\
    \ (l + 1 == r) {\n            Node *res = Node::_pool.alloc();\n            return\
    \ &(*res = Node(v[l], OM0));\n        } else {\n            return merge(build(l,\
    \ (l + r) >> 1, v), build((l + r) >> 1, r, v));\n        }\n    }\n\n    template<bool\
    \ do_clone = true>\n    auto push(Node *node) {\n        Node *res = node;\n \
    \       if constexpr (do_clone) res = Node::clone(res);\n        res->l = update_all(res->l,\
    \ res->lazy);\n        res->r = update_all(res->r, res->lazy);\n        res->lazy\
    \ = OM0;\n        if constexpr (do_clone) {\n            return res;\n       \
    \ } else {\n            return;\n        }\n    }\n\n    Node *update_all(Node\
    \ *node, const OperatorMonoid &x) {\n        if (not node) return nullptr;\n \
    \       Node *res = Node::clone(node);\n        res->data = g(res->data, x);\n\
    \        res->lazy = h(res->lazy, x);\n        return res;\n    }\n\n    Node\
    \ *\n    update(int a, int b, const OperatorMonoid &x, Node *node, int l, int\
    \ r) {\n        if (r <= a || b <= l) {\n            return node;\n        } else\
    \ if (a <= l && r <= b) {\n            return update_all(node, x);\n        }\
    \ else {\n            Node *res = push(node);\n            res->l = update(a,\
    \ b, x, res->l, l, (l + r) >> 1);\n            res->r = update(a, b, x, res->r,\
    \ (l + r) >> 1, r);\n            res->data = f(res->l->data, res->r->data);\n\
    \            return res;\n        }\n    }\n\n    Node *update(Node *node, int\
    \ a, int b, const OperatorMonoid &x) {\n        return update(a, b, x, node, 0,\
    \ sz);\n    }\n\n    Node *update(Node *node, int k, const OperatorMonoid &x)\
    \ {\n        return update(node, k, k + 1, x);\n    }\n\n    Monoid\n    query(int\
    \ a, int b, Node *node, int l, int r, const OperatorMonoid &x) {\n        if (r\
    \ <= a || b <= l) {\n            return M1;\n        } else if (a <= l && r <=\
    \ b) {\n            return g(node->data, x);\n        } else {\n            OperatorMonoid\
    \ y = h(x, node->lazy);\n            return f(\n                query(a, b, node->l,\
    \ l, (l + r) >> 1, y),\n                query(a, b, node->r, (l + r) >> 1, r,\
    \ y)\n            );\n        }\n    }\n\n    Monoid query(Node *node, int a,\
    \ int b) {\n        return query(a, b, node, 0, sz, OM0);\n    }\n\n    Monoid\
    \ all(Node *node) {\n        return node ? node->data : M1;\n    }\n\n    Monoid\
    \ get(Node *node, int a) {\n        return query(node, a, a + 1);\n    }\n\n \
    \   void print(Node *node, int n) {\n        for (int i = 0; i < n; i++) {\n \
    \           cout << query(node, i, i + 1);\n            if (i == n - 1) cout <<\
    \ endl;\n            else cout << ' ';\n        }\n    }\n\n    void init_pool(int\
    \ siz) {\n        Node::_pool = ObjectPool<Node>(siz);\n    }\n    void clear_pool()\
    \ {\n        Node::_pool.clear();\n    }\n};\n\ntemplate<typename F, typename\
    \ G, typename H, typename T, typename E>\nPersistentLazySegmentTree<F, G, H, T,\
    \ E> get_persistent_lazy_segment_tree(\n    const F &f, const G &g, const H &h,\
    \ const T &ti, const E &ei\n) {\n    return {f, g, h, ti, ei};\n}\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/PersistentLazySegmentTree.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/PersistentLazySegmentTree.hpp
layout: document
redirect_from:
- /library/src/datastructure/PersistentLazySegmentTree.hpp
- /library/src/datastructure/PersistentLazySegmentTree.hpp.html
title: src/datastructure/PersistentLazySegmentTree.hpp
---
