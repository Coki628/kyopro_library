---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/rbst/lazy-reversible-rbst.hpp
    - https://nyaannyaan.github.io/library/rbst/rbst-base.hpp
  bundledCode: "#line 1 \"src/datastructure/LazyReversibleRBST.hpp\"\n\n\n// \u9045\
    \u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\u8861\u4E8C\u5206\
    \u6728\n// \u4F7F\u3044\u65B9\n// \u30FB\u307E\u305Abuild\u306E\u5F15\u6570\u306B\
    vector\u6E21\u3059\u304B\u3001make_tree\u3067\u6728\u3092\u4F5C\u308B\u3002\n\
    // \u30FB\u57FA\u672C\u7684\u306B\u7B2C\u4E00\u5F15\u6570\u306B\u5BFE\u8C61\u306E\
    \u6728\u306E\u30DD\u30A4\u30F3\u30BF\u3001\u7B2C\u4E8C\u5F15\u6570\u4EE5\u964D\
    \u306B\u6DFB\u5B57\u3068\u304B\u6E21\u3059\u3002\n// \u30FB\u751F\u6210\u3059\u308B\
    \u6728\u304C\u305D\u308C\u305E\u308C\u5225\u306E\u914D\u5217\u306E\u3088\u3046\
    \u306B\u6271\u3048\u3066\u72EC\u7ACB\u306B\u3001\n// \u3000\u4EFB\u610F\u4F4D\u7F6E\
    \u633F\u5165\u3084\u524A\u9664\u3001\u30BB\u30B0\u6728\u7684\u306A\u533A\u9593\
    \u64CD\u4F5C\u3001\u533A\u9593\u30EA\u30D0\u30FC\u30B9\u306A\u3069\u304C\u3067\
    \u304D\u308B\u3002\n// \u30FB\u5404\u6728\u306F\u30DE\u30FC\u30B8\u3057\u305F\u308A\
    \u3001\u4EFB\u610F\u4F4D\u7F6E\u3067\u5207\u3063\u305F\u308A\u3082\u3067\u304D\
    \u308B\u3089\u3057\u3044\u3002(\u3053\u308C\u306F\u307E\u3060\u8A66\u3057\u3066\
    \u306A\u3044)\n\n// see: https://nyaannyaan.github.io/library/rbst/rbst-base.hpp\n\
    template<typename Node>\nstruct RBSTBase {\n    using Ptr = Node *;\n    template<typename...\
    \ Args> inline Ptr my_new(Args... args) {\n        return new Node(args...);\n\
    \    }\n    inline void my_del(Ptr t) {\n        delete t;\n    }\n\n    // \u7A7A\
    \u306E\u6728\u3092\u4F5C\u6210 O(1)\n    inline Ptr make_tree() const {\n    \
    \    return nullptr;\n    }\n\n    // for avoiding memory leak, activate below\n\
    \    /*\n    using Ptr = shared_ptr<Node>;\n    template <typename... Args>\n\
    \    inline Ptr my_new(Args... args) {\n        return make_shared<Node>(args...);\n\
    \    }\n    inline void my_del(Ptr t) {}\n    Ptr make_tree() {return Ptr();}\n\
    \    */\n\n    // \u6728t\u306E\u8981\u7D20\u6570\u3092\u53D6\u5F97 O(1)\n   \
    \ int size(Ptr t) const {\n        return count(t);\n    }\n\n    Ptr merge(Ptr\
    \ l, Ptr r) {\n        if (!l || !r) return l ? l : r;\n        if (int((rng()\
    \ * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n            push(l);\n            l->r\
    \ = merge(l->r, r);\n            return update(l);\n        } else {\n       \
    \     push(r);\n            r->l = merge(l, r->l);\n            return update(r);\n\
    \        }\n    }\n\n    pair<Ptr, Ptr> split(Ptr t, int k) {\n        if (!t)\
    \ return {nullptr, nullptr};\n        push(t);\n        if (k <= count(t->l))\
    \ {\n            auto s = split(t->l, k);\n            t->l = s.second;\n    \
    \        return {s.first, update(t)};\n        } else {\n            auto s =\
    \ split(t->r, k - count(t->l) - 1);\n            t->r = s.first;\n           \
    \ return {update(t), s.second};\n        }\n    }\n\n    Ptr build(int l, int\
    \ r, const vector<decltype(Node::key)> &v) {\n        if (l + 1 == r) return my_new(v[l]);\n\
    \        int m = (l + r) >> 1;\n        Ptr pm = my_new(v[m]);\n        if (l\
    \ < m) pm->l = build(l, m, v);\n        if (m + 1 < r) pm->r = build(m + 1, r,\
    \ v);\n        return update(pm);\n    }\n\n    // \u914D\u5217v\u3092\u521D\u671F\
    \u5024\u3068\u3057\u305F\u65B0\u305F\u306A\u6728\u3092\u4F5C\u308B O(N)\n    Ptr\
    \ build(const vector<decltype(Node::key)> &v) {\n        return build(0, (int)v.size(),\
    \ v);\n    }\n\n    // \u6728t\u306Ek\u756A\u76EE(0-indexed)\u306B\u8981\u7D20\
    args(\u8907\u6570\u53EF)\u3092\u633F\u5165\u3059\u308B O(logN)\n    template<typename...\
    \ Args>\n    void insert(Ptr &t, int k, const Args &...args) {\n        auto x\
    \ = split(t, k);\n        t = merge(merge(x.first, my_new(args...)), x.second);\n\
    \    }\n\n    // \u6728t\u306Ek\u756A\u76EE(0-indexed)\u306E\u8981\u7D20\u3092\
    \u524A\u9664\u3059\u308B O(logN)\n    void erase(Ptr &t, int k) {\n        auto\
    \ x = split(t, k);\n        auto y = split(x.second, 1);\n        my_del(y.first);\n\
    \        t = merge(x.first, y.second);\n    }\n\nprotected:\n    static uint64_t\
    \ rng() {\n        static uint64_t x_ = 88172645463325252ULL;\n        return\
    \ x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n    }\n\n    inline int count(const\
    \ Ptr t) const {\n        return t ? t->cnt : 0;\n    }\n\n    virtual void push(Ptr)\
    \ = 0;\n\n    virtual Ptr update(Ptr) = 0;\n};\n\ntemplate<typename T, typename\
    \ E>\nstruct LazyReversibleRBSTNode {\n    typename RBSTBase<LazyReversibleRBSTNode>::Ptr\
    \ l, r;\n    T key, sum;\n    E lazy;\n    int cnt;\n    bool rev;\n\n    LazyReversibleRBSTNode(const\
    \ T &t = T(), const E &e = E())\n        : l(),\n          r(),\n          key(t),\n\
    \          sum(t),\n          lazy(e),\n          cnt(1),\n          rev(false)\
    \ {\n    }\n};\n\n// see: https://nyaannyaan.github.io/library/rbst/lazy-reversible-rbst.hpp\n\
    template<\n    typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n\
    \    T (*ts)(T)>\nstruct LazyReversibleRBST : RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>> {\n    using Node = LazyReversibleRBSTNode<T, E>;\n    using base = RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>>;\n    using base::merge;\n    using base::split;\n    using typename base::Ptr;\n\
    \n    LazyReversibleRBST() = default;\n\n    void toggle(Ptr t) {\n        if\
    \ (!t) return;\n        swap(t->l, t->r);\n        t->sum = ts(t->sum);\n    \
    \    t->rev ^= true;\n    }\n\n    // [a,b)\u3092\u533A\u9593\u53D6\u5F97\u3059\
    \u308B O(logN)\n    T fold(Ptr &t, int a, int b) {\n        assert(a < b);\n \
    \       auto x = split(t, a);\n        auto y = split(x.second, b - a);\n    \
    \    auto ret = sum(y.first);\n        t = merge(x.first, merge(y.first, y.second));\n\
    \        return ret;\n    }\n\n    // [a,b)\u3092\u533A\u9593\u30EA\u30D0\u30FC\
    \u30B9\u3059\u308B O(logN)\n    void reverse(Ptr &t, int a, int b) {\n       \
    \ assert(a < b);\n        auto x = split(t, a);\n        auto y = split(x.second,\
    \ b - a);\n        toggle(y.first);\n        t = merge(x.first, merge(y.first,\
    \ y.second));\n    }\n\n    // [a,b)\u3092\u4F5C\u7528\u7D20e\u3067\u533A\u9593\
    \u66F4\u65B0\u3059\u308B O(logN)\n    void apply(Ptr &t, int a, int b, const E\
    \ &e) {\n        assert(a < b);\n        auto x = split(t, a);\n        auto y\
    \ = split(x.second, b - a);\n        propagate(y.first, e);\n        t = merge(x.first,\
    \ merge(y.first, y.second));\n    }\n\n    // 1\u70B9\u53D6\u5F97 O(logN)\n  \
    \  T get(Ptr &t, int i) {\n        return this->fold(t, i, i + 1);\n    }\n\n\
    protected:\n    inline T sum(const Ptr t) const {\n        return t ? t->sum :\
    \ T();\n    }\n\n    Ptr update(Ptr t) override {\n        push(t);\n        t->cnt\
    \ = 1;\n        t->sum = t->key;\n        if (t->l) t->cnt += t->l->cnt, t->sum\
    \ = f(t->l->sum, t->sum);\n        if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum,\
    \ t->r->sum);\n        return t;\n    }\n\n    void push(Ptr t) override {\n \
    \       if (t->rev) {\n            if (t->l) toggle(t->l);\n            if (t->r)\
    \ toggle(t->r);\n            t->rev = false;\n        }\n        if (t->lazy !=\
    \ E()) {\n            if (t->l) propagate(t->l, t->lazy);\n            if (t->r)\
    \ propagate(t->r, t->lazy);\n            t->lazy = E();\n        }\n    }\n\n\
    \    void propagate(Ptr t, const E &x) {\n        t->lazy = h(t->lazy, x);\n \
    \       t->key = g(t->key, x);\n        t->sum = g(t->sum, x);\n    }\n};\n"
  code: "\n\n// \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u4E71\u629E\u5E73\
    \u8861\u4E8C\u5206\u6728\n// \u4F7F\u3044\u65B9\n// \u30FB\u307E\u305Abuild\u306E\
    \u5F15\u6570\u306Bvector\u6E21\u3059\u304B\u3001make_tree\u3067\u6728\u3092\u4F5C\
    \u308B\u3002\n// \u30FB\u57FA\u672C\u7684\u306B\u7B2C\u4E00\u5F15\u6570\u306B\u5BFE\
    \u8C61\u306E\u6728\u306E\u30DD\u30A4\u30F3\u30BF\u3001\u7B2C\u4E8C\u5F15\u6570\
    \u4EE5\u964D\u306B\u6DFB\u5B57\u3068\u304B\u6E21\u3059\u3002\n// \u30FB\u751F\u6210\
    \u3059\u308B\u6728\u304C\u305D\u308C\u305E\u308C\u5225\u306E\u914D\u5217\u306E\
    \u3088\u3046\u306B\u6271\u3048\u3066\u72EC\u7ACB\u306B\u3001\n// \u3000\u4EFB\u610F\
    \u4F4D\u7F6E\u633F\u5165\u3084\u524A\u9664\u3001\u30BB\u30B0\u6728\u7684\u306A\
    \u533A\u9593\u64CD\u4F5C\u3001\u533A\u9593\u30EA\u30D0\u30FC\u30B9\u306A\u3069\
    \u304C\u3067\u304D\u308B\u3002\n// \u30FB\u5404\u6728\u306F\u30DE\u30FC\u30B8\u3057\
    \u305F\u308A\u3001\u4EFB\u610F\u4F4D\u7F6E\u3067\u5207\u3063\u305F\u308A\u3082\
    \u3067\u304D\u308B\u3089\u3057\u3044\u3002(\u3053\u308C\u306F\u307E\u3060\u8A66\
    \u3057\u3066\u306A\u3044)\n\n// see: https://nyaannyaan.github.io/library/rbst/rbst-base.hpp\n\
    template<typename Node>\nstruct RBSTBase {\n    using Ptr = Node *;\n    template<typename...\
    \ Args> inline Ptr my_new(Args... args) {\n        return new Node(args...);\n\
    \    }\n    inline void my_del(Ptr t) {\n        delete t;\n    }\n\n    // \u7A7A\
    \u306E\u6728\u3092\u4F5C\u6210 O(1)\n    inline Ptr make_tree() const {\n    \
    \    return nullptr;\n    }\n\n    // for avoiding memory leak, activate below\n\
    \    /*\n    using Ptr = shared_ptr<Node>;\n    template <typename... Args>\n\
    \    inline Ptr my_new(Args... args) {\n        return make_shared<Node>(args...);\n\
    \    }\n    inline void my_del(Ptr t) {}\n    Ptr make_tree() {return Ptr();}\n\
    \    */\n\n    // \u6728t\u306E\u8981\u7D20\u6570\u3092\u53D6\u5F97 O(1)\n   \
    \ int size(Ptr t) const {\n        return count(t);\n    }\n\n    Ptr merge(Ptr\
    \ l, Ptr r) {\n        if (!l || !r) return l ? l : r;\n        if (int((rng()\
    \ * (l->cnt + r->cnt)) >> 32) < l->cnt) {\n            push(l);\n            l->r\
    \ = merge(l->r, r);\n            return update(l);\n        } else {\n       \
    \     push(r);\n            r->l = merge(l, r->l);\n            return update(r);\n\
    \        }\n    }\n\n    pair<Ptr, Ptr> split(Ptr t, int k) {\n        if (!t)\
    \ return {nullptr, nullptr};\n        push(t);\n        if (k <= count(t->l))\
    \ {\n            auto s = split(t->l, k);\n            t->l = s.second;\n    \
    \        return {s.first, update(t)};\n        } else {\n            auto s =\
    \ split(t->r, k - count(t->l) - 1);\n            t->r = s.first;\n           \
    \ return {update(t), s.second};\n        }\n    }\n\n    Ptr build(int l, int\
    \ r, const vector<decltype(Node::key)> &v) {\n        if (l + 1 == r) return my_new(v[l]);\n\
    \        int m = (l + r) >> 1;\n        Ptr pm = my_new(v[m]);\n        if (l\
    \ < m) pm->l = build(l, m, v);\n        if (m + 1 < r) pm->r = build(m + 1, r,\
    \ v);\n        return update(pm);\n    }\n\n    // \u914D\u5217v\u3092\u521D\u671F\
    \u5024\u3068\u3057\u305F\u65B0\u305F\u306A\u6728\u3092\u4F5C\u308B O(N)\n    Ptr\
    \ build(const vector<decltype(Node::key)> &v) {\n        return build(0, (int)v.size(),\
    \ v);\n    }\n\n    // \u6728t\u306Ek\u756A\u76EE(0-indexed)\u306B\u8981\u7D20\
    args(\u8907\u6570\u53EF)\u3092\u633F\u5165\u3059\u308B O(logN)\n    template<typename...\
    \ Args>\n    void insert(Ptr &t, int k, const Args &...args) {\n        auto x\
    \ = split(t, k);\n        t = merge(merge(x.first, my_new(args...)), x.second);\n\
    \    }\n\n    // \u6728t\u306Ek\u756A\u76EE(0-indexed)\u306E\u8981\u7D20\u3092\
    \u524A\u9664\u3059\u308B O(logN)\n    void erase(Ptr &t, int k) {\n        auto\
    \ x = split(t, k);\n        auto y = split(x.second, 1);\n        my_del(y.first);\n\
    \        t = merge(x.first, y.second);\n    }\n\nprotected:\n    static uint64_t\
    \ rng() {\n        static uint64_t x_ = 88172645463325252ULL;\n        return\
    \ x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;\n    }\n\n    inline int count(const\
    \ Ptr t) const {\n        return t ? t->cnt : 0;\n    }\n\n    virtual void push(Ptr)\
    \ = 0;\n\n    virtual Ptr update(Ptr) = 0;\n};\n\ntemplate<typename T, typename\
    \ E>\nstruct LazyReversibleRBSTNode {\n    typename RBSTBase<LazyReversibleRBSTNode>::Ptr\
    \ l, r;\n    T key, sum;\n    E lazy;\n    int cnt;\n    bool rev;\n\n    LazyReversibleRBSTNode(const\
    \ T &t = T(), const E &e = E())\n        : l(),\n          r(),\n          key(t),\n\
    \          sum(t),\n          lazy(e),\n          cnt(1),\n          rev(false)\
    \ {\n    }\n};\n\n// see: https://nyaannyaan.github.io/library/rbst/lazy-reversible-rbst.hpp\n\
    template<\n    typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n\
    \    T (*ts)(T)>\nstruct LazyReversibleRBST : RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>> {\n    using Node = LazyReversibleRBSTNode<T, E>;\n    using base = RBSTBase<LazyReversibleRBSTNode<T,\
    \ E>>;\n    using base::merge;\n    using base::split;\n    using typename base::Ptr;\n\
    \n    LazyReversibleRBST() = default;\n\n    void toggle(Ptr t) {\n        if\
    \ (!t) return;\n        swap(t->l, t->r);\n        t->sum = ts(t->sum);\n    \
    \    t->rev ^= true;\n    }\n\n    // [a,b)\u3092\u533A\u9593\u53D6\u5F97\u3059\
    \u308B O(logN)\n    T fold(Ptr &t, int a, int b) {\n        assert(a < b);\n \
    \       auto x = split(t, a);\n        auto y = split(x.second, b - a);\n    \
    \    auto ret = sum(y.first);\n        t = merge(x.first, merge(y.first, y.second));\n\
    \        return ret;\n    }\n\n    // [a,b)\u3092\u533A\u9593\u30EA\u30D0\u30FC\
    \u30B9\u3059\u308B O(logN)\n    void reverse(Ptr &t, int a, int b) {\n       \
    \ assert(a < b);\n        auto x = split(t, a);\n        auto y = split(x.second,\
    \ b - a);\n        toggle(y.first);\n        t = merge(x.first, merge(y.first,\
    \ y.second));\n    }\n\n    // [a,b)\u3092\u4F5C\u7528\u7D20e\u3067\u533A\u9593\
    \u66F4\u65B0\u3059\u308B O(logN)\n    void apply(Ptr &t, int a, int b, const E\
    \ &e) {\n        assert(a < b);\n        auto x = split(t, a);\n        auto y\
    \ = split(x.second, b - a);\n        propagate(y.first, e);\n        t = merge(x.first,\
    \ merge(y.first, y.second));\n    }\n\n    // 1\u70B9\u53D6\u5F97 O(logN)\n  \
    \  T get(Ptr &t, int i) {\n        return this->fold(t, i, i + 1);\n    }\n\n\
    protected:\n    inline T sum(const Ptr t) const {\n        return t ? t->sum :\
    \ T();\n    }\n\n    Ptr update(Ptr t) override {\n        push(t);\n        t->cnt\
    \ = 1;\n        t->sum = t->key;\n        if (t->l) t->cnt += t->l->cnt, t->sum\
    \ = f(t->l->sum, t->sum);\n        if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum,\
    \ t->r->sum);\n        return t;\n    }\n\n    void push(Ptr t) override {\n \
    \       if (t->rev) {\n            if (t->l) toggle(t->l);\n            if (t->r)\
    \ toggle(t->r);\n            t->rev = false;\n        }\n        if (t->lazy !=\
    \ E()) {\n            if (t->l) propagate(t->l, t->lazy);\n            if (t->r)\
    \ propagate(t->r, t->lazy);\n            t->lazy = E();\n        }\n    }\n\n\
    \    void propagate(Ptr t, const E &x) {\n        t->lazy = h(t->lazy, x);\n \
    \       t->key = g(t->key, x);\n        t->sum = g(t->sum, x);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/LazyReversibleRBST.hpp
  requiredBy: []
  timestamp: '2024-05-08 12:52:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/LazyReversibleRBST.hpp
layout: document
redirect_from:
- /library/src/datastructure/LazyReversibleRBST.hpp
- /library/src/datastructure/LazyReversibleRBST.hpp.html
title: src/datastructure/LazyReversibleRBST.hpp
---
