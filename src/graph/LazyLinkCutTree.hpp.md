---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/graph/LinkCutTree.hpp
    title: src/graph/LinkCutTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/lct/lazy-reversible-bbst-base.hpp
    - https://nyaannyaan.github.io/library/lct/link-cut-tree-lazy.hpp
    - https://nyaannyaan.github.io/library/lct/splay-lazy-reversible.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/graph/LinkCutTree.hpp\"\n\n// Link Cut Tree\n\
    // \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/lct/link-cut-tree.hpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FBHLD\u307F\u305F\u3044\u306A\u30D1\u30B9\u30AF\u30A8\
    \u30EA\u306B\u52A0\u3048\u3066\u3001\u8FBA\u306E\u8FFD\u52A0\u30FB\u524A\u9664\
    \u3092\u52D5\u7684\u306B\u884C\u3048\u308B\u3002\u9802\u70B9\u3082\u5F8C\u304B\
    \u3089\u8FFD\u52A0\u3067\u304D\u308B\u3002\n// \u4F7F\u7528\u4F8B1\uFF1Aabc350_g\u3067\
    LCA\u3084k\u500B\u9061\u3063\u305F\u7956\u5148\u306E\u53D6\u5F97\u306A\u3069\u3002\
    \n// \u4F7F\u7528\u4F8B2\uFF1Adynamic_tree_vertex_add_path_sum\u3067\u8FBA\u524A\
    \u9664\u3084\u30D1\u30B9\u30AF\u30A8\u30EA\u306E\u533A\u9593\u548C\u53D6\u5F97\
    \u306A\u3069\u3002\n// \u4F7F\u7528\u4F8B3\uFF1Aabc355_f\u3067\u8FBA\u5C5E\u6027\
    \u3078\u306E\u5BFE\u5FDC\u3002\u8FBA\u3092\u8D85\u9802\u70B9\u3068\u3057\u3066\
    \u305D\u3053\u306B\u5024\u3092\u3064\u3051\u308B\u3002\n// \u4F7F\u7528\u4F8B\
    4\uFF1AAOJ2450\u3067\u95A2\u6570ts\u3092\u4F7F\u3063\u3066\u30DE\u30FC\u30B8\u306E\
    \u5DE6\u53F3\u304C\u3042\u308B\u6642\u306E\u5BFE\u5FDC\u3092\u3057\u3066\u308B\
    \u3002\n// \u30FB\u5358\u4F4D\u5143\u3092INF\u3084-INF\u306B\u3057\u305F\u308A\
    \u3067\u304D\u306A\u3044(\u5E38\u306B0\u521D\u671F\u5316)\u3063\u307D\u3044\u3053\
    \u3068\u304C\u767A\u899A\u3057\u305F\u306E\u3067\u3001\n// \u3000\u8CA0\u6570\u3042\
    \u308A\u306E\u6700\u5927\u6700\u5C0F\u53D6\u5F97\u3068\u304B\u4E57\u305B\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\u6642\u304C\u6765\u305F\u3089\u3001\n// \u3000\u9045\
    \u5EF6LCT\u306E\u5B9F\u88C5\u3092\u53C2\u8003\u306Btid\u3068eid\u3068\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u306B\u7D44\u307F\u8FBC\u3093\u3067\u5BFE\
    \u5FDC\u3059\u308B\u3053\u3068\u3002\n\n// \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\
    \u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n// see: https://nyaannyaan.github.io/library/lct/reversible-bbst-base.hpp\n\
    template<typename Tree, typename Node, typename T, T (*f)(T, T), T (*ts)(T)>\n\
    struct ReversibleBBST : Tree {\n    using Tree::merge;\n    using Tree::split;\n\
    \    using typename Tree::Ptr;\n\n    ReversibleBBST() = default;\n\n    virtual\
    \ void toggle(Ptr t) {\n        if (!t) return;\n        swap(t->l, t->r);\n \
    \       t->sum = ts(t->sum);\n        t->rev ^= true;\n    }\n\n    T fold(Ptr\
    \ &t, int a, int b) {\n        auto x = split(t, a);\n        auto y = split(x.second,\
    \ b - a);\n        auto ret = sum(y.first);\n        t = merge(x.first, merge(y.first,\
    \ y.second));\n        return ret;\n    }\n\n    void reverse(Ptr &t, int a, int\
    \ b) {\n        auto x = split(t, a);\n        auto y = split(x.second, b - a);\n\
    \        toggle(y.first);\n        t = merge(x.first, merge(y.first, y.second));\n\
    \    }\n\n    Ptr update(Ptr t) override {\n        if (!t) return t;\n      \
    \  t->cnt = 1;\n        t->sum = t->key;\n        if (t->l) t->cnt += t->l->cnt,\
    \ t->sum = f(t->l->sum, t->sum);\n        if (t->r) t->cnt += t->r->cnt, t->sum\
    \ = f(t->sum, t->r->sum);\n        return t;\n    }\n\nprotected:\n    inline\
    \ T sum(const Ptr t) {\n        return t ? t->sum : T();\n    }\n\n    void push(Ptr\
    \ t) override {\n        if (!t) return;\n        if (t->rev) {\n            if\
    \ (t->l) toggle(t->l);\n            if (t->r) toggle(t->r);\n            t->rev\
    \ = false;\n        }\n    }\n};\n\n// see: https://nyaannyaan.github.io/library/lct/splay-base.hpp\n\
    template<typename Node> struct SplayTreeBase {\n    using Ptr = Node *;\n    template<typename...\
    \ Args> Ptr my_new(const Args &...args) {\n        return new Node(args...);\n\
    \    }\n    void my_del(Ptr p) {\n        delete p;\n    }\n\n    bool is_root(Ptr\
    \ t) {\n        return !(t->p) || (t->p->l != t && t->p->r != t);\n    }\n\n \
    \   int size(Ptr t) const {\n        return count(t);\n    }\n\n    virtual void\
    \ splay(Ptr t) {\n        if (!t) return;\n        push(t);\n        while (!is_root(t))\
    \ {\n            Ptr q = t->p;\n            if (is_root(q)) {\n              \
    \  push(q), push(t);\n                rot(t);\n            } else {\n        \
    \        Ptr r = q->p;\n                push(r), push(q), push(t);\n         \
    \       if (pos(q) == pos(t)) rot(q), rot(t);\n                else rot(t), rot(t);\n\
    \            }\n        }\n    }\n\n    Ptr get_left(Ptr t) {\n        while (t->l)\
    \ push(t), t = t->l;\n        return t;\n    }\n\n    Ptr get_right(Ptr t) {\n\
    \        while (t->r) push(t), t = t->r;\n        return t;\n    }\n\n    pair<Ptr,\
    \ Ptr> split(Ptr t, int k) {\n        if (!t) return {nullptr, nullptr};\n   \
    \     if (k == 0) return {nullptr, t};\n        if (k == count(t)) return {t,\
    \ nullptr};\n        push(t);\n        if (k <= count(t->l)) {\n            auto\
    \ x = split(t->l, k);\n            t->l = x.second;\n            t->p = nullptr;\n\
    \            if (x.second) x.second->p = t;\n            return {x.first, update(t)};\n\
    \        } else {\n            auto x = split(t->r, k - count(t->l) - 1);\n  \
    \          t->r = x.first;\n            t->p = nullptr;\n            if (x.first)\
    \ x.first->p = t;\n            return {update(t), x.second};\n        }\n    }\n\
    \n    Ptr merge(Ptr l, Ptr r) {\n        if (!l && !r) return nullptr;\n     \
    \   if (!l) return splay(r), r;\n        if (!r) return splay(l), l;\n       \
    \ splay(l), splay(r);\n        l = get_right(l);\n        splay(l);\n        l->r\
    \ = r;\n        r->p = l;\n        update(l);\n        return l;\n    }\n\n  \
    \  using Key = decltype(Node::key);\n    Ptr build(const vector<Key> &v) {\n \
    \       return build(0, v.size(), v);\n    }\n    Ptr build(int l, int r, const\
    \ vector<Key> &v) {\n        if (l == r) return nullptr;\n        if (l + 1 ==\
    \ r) return my_new(v[l]);\n        return merge(build(l, (l + r) >> 1, v), build((l\
    \ + r) >> 1, r, v));\n    }\n\n    template<typename... Args> void insert(Ptr\
    \ &t, int k, const Args &...args) {\n        splay(t);\n        auto x = split(t,\
    \ k);\n        t = merge(merge(x.first, my_new(args...)), x.second);\n    }\n\n\
    \    void erase(Ptr &t, int k) {\n        splay(t);\n        auto x = split(t,\
    \ k);\n        auto y = split(x.second, 1);\n        my_del(y.first);\n      \
    \  t = merge(x.first, y.second);\n    }\n\n    virtual Ptr update(Ptr t) = 0;\n\
    \nprotected:\n    inline int count(Ptr t) const {\n        return t ? t->cnt :\
    \ 0;\n    }\n\n    virtual void push(Ptr t) = 0;\n\n    Ptr build(const vector<Ptr>\
    \ &v) {\n        return build(0, v.size(), v);\n    }\n\n    Ptr build(int l,\
    \ int r, const vector<Ptr> &v) {\n        if (l + 1 >= r) return v[l];\n     \
    \   return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));\n    }\n\
    \n    inline int pos(Ptr t) {\n        if (t->p) {\n            if (t->p->l ==\
    \ t) return -1;\n            if (t->p->r == t) return 1;\n        }\n        return\
    \ 0;\n    }\n\n    virtual void rot(Ptr t) {\n        Ptr x = t->p, y = x->p;\n\
    \        if (pos(t) == -1) {\n            if ((x->l = t->r)) t->r->p = x;\n  \
    \          t->r = x, x->p = t;\n        } else {\n            if ((x->r = t->l))\
    \ t->l->p = x;\n            t->l = x, x->p = t;\n        }\n        update(x),\
    \ update(t);\n        if ((t->p = y)) {\n            if (y->l == x) y->l = t;\n\
    \            if (y->r == x) y->r = t;\n        }\n    }\n};\n\n// \u53CD\u8EE2\
    \u53EF\u80FDSplay Tree\n// see: https://nyaannyaan.github.io/library/lct/splay-reversible.hpp\n\
    template<typename T> struct ReversibleSplayTreeNode {\n    using Ptr = ReversibleSplayTreeNode\
    \ *;\n    Ptr l, r, p;\n    T key, sum;\n    int cnt, id;\n    bool rev;\n\n \
    \   ReversibleSplayTreeNode(const T &t = T())\n        : l(),\n          r(),\n\
    \          p(),\n          key(t),\n          sum(t),\n          cnt(1),\n   \
    \       id(-1),\n          rev(false) {\n    }\n};\n\ntemplate<typename T, T (*f)(T,\
    \ T), T (*ts)(T)>\nstruct ReversibleSplayTree : ReversibleBBST<\n            \
    \                     SplayTreeBase<ReversibleSplayTreeNode<T>>,\n           \
    \                      ReversibleSplayTreeNode<T>, T, f, ts> {\n    using Node\
    \ = ReversibleSplayTreeNode<T>;\n};\n\n// see: https://nyaannyaan.github.io/library/lct/link-cut-base.hpp\n\
    template<typename Splay>\nstruct LinkCutBase : Splay {\n    using Node = typename\
    \ Splay::Node;\n    using Ptr = Node *;\n\n    virtual Ptr expose(Ptr t) {\n \
    \       Ptr rp = nullptr;\n        for (Ptr cur = t; cur; cur = cur->p) {\n  \
    \          this->splay(cur);\n            cur->r = rp;\n            this->update(cur);\n\
    \            rp = cur;\n        }\n        this->splay(t);\n        return rp;\n\
    \    }\n\n    virtual void link(Ptr u, Ptr v) {\n        evert(u);\n        expose(v);\n\
    \        u->p = v;\n    }\n\n    void cut(Ptr u, Ptr v) {\n        evert(u);\n\
    \        expose(v);\n        assert(u->p == v);\n        v->l = u->p = nullptr;\n\
    \        this->update(v);\n    }\n\n    void evert(Ptr t) {\n        expose(t);\n\
    \        this->toggle(t);\n        this->push(t);\n    }\n\n    Ptr lca(Ptr u,\
    \ Ptr v) {\n        if (get_root(u) != get_root(v)) return nullptr;\n        expose(u);\n\
    \        return expose(v);\n    }\n\n    Ptr get_kth(Ptr x, int k) {\n       \
    \ expose(x);\n        while (x) {\n            this->push(x);\n            if\
    \ (x->r && x->r->cnt > k) {\n                x = x->r;\n            } else {\n\
    \                if (x->r) k -= x->r->cnt;\n                if (k == 0) return\
    \ x;\n                k -= 1;\n                x = x->l;\n            }\n    \
    \    }\n        return nullptr;\n    }\n\n    Ptr get_root(Ptr x) {\n        expose(x);\n\
    \        while (x->l) this->push(x), x = x->l;\n        return x;\n    }\n\n \
    \   Ptr get_parent(Ptr x) {\n        expose(x);\n        Ptr p = x->l;\n     \
    \   if (p == nullptr) return nullptr;\n        while (true) {\n            this->push(p);\n\
    \            if (p->r == nullptr) return p;\n            p = p->r;\n        }\n\
    \        exit(1);\n    }\n\n    virtual void set_key(Ptr t, const decltype(Node::key)\
    \ &key) {\n        this->splay(t);\n        t->key = key;\n        this->update(t);\n\
    \    }\n\n    virtual decltype(Node::key) get_key(Ptr t) {\n        return t->key;\n\
    \    }\n\n    decltype(Node::key) fold(Ptr u, Ptr v) {\n        evert(u);\n  \
    \      expose(v);\n        return v->sum;\n    }\n};\n\n// Link Cut Tree\n// see:\
    \ https://nyaannyaan.github.io/library/lct/link-cut-tree.hpp\ntemplate<typename\
    \ T, T (*f)(T, T), T (*ts)(T)>\nstruct LinkCutTree : LinkCutBase<ReversibleSplayTree<T,\
    \ f, ts>> {\n    using LCB = LinkCutBase<ReversibleSplayTree<T, f, ts>>;\n   \
    \ using Ptr = typename LCB::Ptr;\n\n    vector<Ptr> ptr;\n    int N;\n\n    LinkCutTree()\
    \ : N(0) {}\n\n    // \u9802\u70B9\u6570N\u306E\u68EE\u3068\u3057\u3066\u521D\u671F\
    \u5316\n    LinkCutTree(int N) : N(N) {\n        ptr.resize(N);\n        for (int\
    \ i = 0; i < N; i++) {\n            ptr[i] = LCB::my_new(T());\n            ptr[i]->id\
    \ = i;\n        }\n    }\n\n    LinkCutTree(const vector<T> &vec) : N(vec.size())\
    \ {\n        ptr.resize(N);\n        for (int i = 0; i < N; i++) {\n         \
    \   ptr[i] = LCB::my_new(vec[i]);\n            ptr[i]->id = i;\n        }\n  \
    \  }\n\n    // \u9802\u70B9\u8FFD\u52A0\n    void add_vertex(T val = T()) {\n\
    \        ptr.push_back(LCB::my_new(val));\n        ptr.back()->id = N;\n     \
    \   N++;\n    }\n\n    // \u8FBA\u8FFD\u52A0\n    void add_edge(int u, int v)\
    \ {\n        LCB::link(ptr[u], ptr[v]);\n    }\n\n    // \u8FBA\u524A\u9664\n\
    \    void remove_edge(int u, int v) {\n        LCB::cut(ptr[u], ptr[v]);\n   \
    \ }\n\n    // 1\u70B9\u66F4\u65B0\n    void update(int x, T val) {\n        LCB::set_key(ptr[x],\
    \ val);\n    }\n\n    // 1\u70B9\u53D6\u5F97\n    T operator[](int k) {\n    \
    \    return LCB::get_key(ptr[k]);\n    }\n\n    // \u533A\u9593\u53D6\u5F97(\u30D1\
    \u30B9\u30AF\u30A8\u30EA)\n    T query(int s, int t) {\n        return LCB::fold(ptr[s],\
    \ ptr[t]);\n    }\n\n    // \u30DD\u30A4\u30F3\u30BF -> \u9802\u70B9\u756A\u53F7\
    \n    int get_id(Ptr x) {\n        if (x != nullptr) {\n            return x->id;\n\
    \        } else {\n            return -1;\n        }\n    }\n\n    // \u9802\u70B9\
    u,v\u306ELCA\u3092\u8FD4\u3059(\u9023\u7D50\u3067\u306A\u3051\u308C\u3070-1)\n\
    \    int lca(int u, int v) {\n        return get_id(LCB::lca(ptr[u], ptr[v]));\n\
    \    }\n\n    // \u9802\u70B9x\u304B\u3089\u898B\u3066k\u56DE\u9061\u3063\u305F\
    \u7956\u5148\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070-1)\n    int la(int x,\
    \ int k) {\n        return get_id(LCB::get_kth(ptr[x], k));\n    }\n\n    // \u9802\
    \u70B9x\u306E\u89AA\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070-1)\n    int par(int\
    \ x) {\n        return get_id(LCB::get_parent(ptr[x]));\n    }\n\n    // \u9802\
    \u70B9x\u304C\u5C5E\u3059\u308B\u6728\u306E\u6839\u3092\u8FD4\u3059\n    int get_root(int\
    \ x) {\n        return get_id(LCB::get_root(ptr[x]));\n    }\n\n    // \u540C\u3058\
    \u6728\u306B\u5C5E\u3059\u308B\u304B\n    bool same(int u, int v) {\n        return\
    \ get_root(u) == get_root(v);\n    }\n};\n// \u4F8B\n// using T = long long;\n\
    // T f(T a, T b) {\n//     return a + b;\n// }\n// T ts(T a) {\n//     return\
    \ a;\n// }\n#line 4 \"src/graph/LazyLinkCutTree.hpp\"\n\n// \u9045\u5EF6Link Cut\
    \ Tree\n// \u4F7F\u3044\u65B9\n// \u30FB\u307B\u307CLCT\u3068\u540C\u3058\u306B\
    \u3057\u3066\u3042\u308B\u306E\u3067\u305D\u3061\u3089\u3092\u53C2\u7167\u3002\
    \n// \u30FB\u6A5F\u80FD\u3068\u3057\u3066\u306F\u533A\u9593\u66F4\u65B0\u7528\u306E\
    update\u3060\u3051\u8FFD\u52A0\u3057\u3066\u3042\u308B\u3002\n// \u3000\u3042\u3068\
    1\u70B9\u66F4\u65B0\u306Eupdate\u3082\u8981\u7D20\u76F4\u63A5\u3044\u3058\u3063\
    \u305F\u3089\u9045\u5EF6\u306E\u524D\u5F8C\u95A2\u4FC2\u58CA\u308C\u305D\u3046\
    \u3060\u304B\u3089\u3001\n// \u3000\u4F5C\u7528\u7D20\u3092\u66F4\u65B0\u3059\u308B\
    \u611F\u3058\u306B\u5909\u3048\u3066\u3042\u308B\u3002\n// \u30FB\u5358\u4F4D\u5143\
    \u306FACL\u30BB\u30B0\u6728\u3068\u540C\u3058\u3088\u3046\u306A\u611F\u3058\u3067\
    \u95A2\u6570\u306E\u5F62\u3067\u6E21\u3059\u3002\n\n// \u9045\u5EF6\u4F1D\u642C\
    \u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728(\u57FA\u5E95\u30AF\u30E9\
    \u30B9)\n// see: https://nyaannyaan.github.io/library/lct/lazy-reversible-bbst-base.hpp\n\
    template<\n    typename Tree, typename Node, typename T, typename E, T (*f)(T,\
    \ T),\n    T (*g)(T, E), E (*h)(E, E), T (*ts)(T), T (*tid)(), E (*eid)()>\nstruct\
    \ LazyReversibleBBST : Tree {\n    using Tree::merge;\n    using Tree::split;\n\
    \    using typename Tree::Ptr;\n\n    LazyReversibleBBST() = default;\n\n    void\
    \ toggle(Ptr t) {\n        if (!t) return;\n        swap(t->l, t->r);\n      \
    \  t->sum = ts(t->sum);\n        t->rev ^= true;\n    }\n\n    T fold(Ptr &t,\
    \ int a, int b) {\n        auto x = split(t, a);\n        auto y = split(x.second,\
    \ b - a);\n        auto ret = sum(y.first);\n        t = merge(x.first, merge(y.first,\
    \ y.second));\n        return ret;\n    }\n\n    void reverse(Ptr &t, int a, int\
    \ b) {\n        auto x = split(t, a);\n        auto y = split(x.second, b - a);\n\
    \        toggle(y.first);\n        t = merge(x.first, merge(y.first, y.second));\n\
    \    }\n\n    void apply(Ptr &t, int a, int b, const E &e) {\n        auto x =\
    \ split(t, a);\n        auto y = split(x.second, b - a);\n        propagate(y.first,\
    \ e);\n        t = merge(x.first, merge(y.first, y.second));\n    }\n\nprotected:\n\
    \    inline T sum(const Ptr t) {\n        return t ? t->sum : tid();\n    }\n\n\
    \    Ptr update(Ptr t) override {\n        if (!t) return t;\n        t->cnt =\
    \ 1;\n        t->sum = t->key;\n        if (t->l) t->cnt += t->l->cnt, t->sum\
    \ = f(t->l->sum, t->sum);\n        if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum,\
    \ t->r->sum);\n        return t;\n    }\n\n    void push(Ptr t) override {\n \
    \       if (!t) return;\n        if (t->rev) {\n            if (t->l) toggle(t->l);\n\
    \            if (t->r) toggle(t->r);\n            t->rev = false;\n        }\n\
    \        if (t->lazy != eid()) {\n            if (t->l) propagate(t->l, t->lazy);\n\
    \            if (t->r) propagate(t->r, t->lazy);\n            t->lazy = eid();\n\
    \        }\n    }\n\n    void propagate(Ptr t, const E &x) {\n        t->lazy\
    \ = h(t->lazy, x);\n        t->key = g(t->key, x);\n        t->sum = g(t->sum,\
    \ x);\n    }\n};\n\n// \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree\n\
    // see: https://nyaannyaan.github.io/library/lct/splay-lazy-reversible.hpp\ntemplate<typename\
    \ T, typename E, T (*tid)(), E (*eid)()>\nstruct LazyReversibleSplayTreeNode {\n\
    \    using Ptr = LazyReversibleSplayTreeNode *;\n    Ptr l, r, p;\n    T key,\
    \ sum;\n    E lazy;\n    int cnt, id;\n    bool rev;\n\n    LazyReversibleSplayTreeNode(const\
    \ T &t = tid(), const E &e = eid())\n        : l(),\n          r(),\n        \
    \  p(),\n          key(t),\n          sum(t),\n          lazy(e),\n          cnt(1),\n\
    \          id(-1),\n          rev(false) {\n    }\n};\n\ntemplate<\n    typename\
    \ T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n    T (*ts)(T), T\
    \ (*tid)(), E (*eid)()>\nstruct LazyReversibleSplayTree\n    : LazyReversibleBBST<\n\
    \          SplayTreeBase<LazyReversibleSplayTreeNode<T, E, tid, eid>>,\n     \
    \     LazyReversibleSplayTreeNode<T, E, tid, eid>, T, E, f, g, h, ts, tid, eid>\
    \ {\n    using Node = LazyReversibleSplayTreeNode<T, E, tid, eid>;\n};\n\n// \u9045\
    \u5EF6\u4F1D\u642CLink Cut Tree\n// see: https://nyaannyaan.github.io/library/lct/link-cut-tree-lazy.hpp\n\
    template<\n    typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n\
    \    T (*ts)(T), T (*tid)(), E (*eid)()>\nstruct LazyLinkCutTree\n    : LinkCutBase<LazyReversibleSplayTree<T,\
    \ E, f, g, h, ts, tid, eid>> {\n    using LCB = LinkCutBase<LazyReversibleSplayTree<T,\
    \ E, f, g, h, ts, tid, eid>>;\n    using Ptr = typename LCB::Ptr;\n\nprotected:\n\
    \    void set_key(Ptr t, const T &key) override {\n        LCB::evert(t);\n  \
    \      t->key = key;\n        LCB::update(t);\n    }\n\n    T get_key(Ptr t) override\
    \ {\n        LCB::evert(t);\n        return t->key;\n    }\n\n    void apply(Ptr\
    \ u, Ptr v, const E &e) {\n        LCB::evert(u);\n        LCB::expose(v);\n \
    \       LCB::propagate(v, e);\n    }\n\npublic:\n    vector<Ptr> ptr;\n    int\
    \ N;\n\n    LazyLinkCutTree() : N(0) {}\n\n    // \u9802\u70B9\u6570N\u306E\u68EE\
    \u3068\u3057\u3066\u521D\u671F\u5316\n    LazyLinkCutTree(int N) : N(N) {\n  \
    \      ptr.resize(N);\n        for (int i = 0; i < N; i++) {\n            ptr[i]\
    \ = LCB::my_new();\n            ptr[i]->id = i;\n        }\n    }\n\n    LazyLinkCutTree(const\
    \ vector<T> &vec) : N(vec.size()) {\n        ptr.resize(N);\n        for (int\
    \ i = 0; i < N; i++) {\n            ptr[i] = LCB::my_new(vec[i]);\n          \
    \  ptr[i]->id = i;\n        }\n    }\n\n    // \u9802\u70B9\u8FFD\u52A0\n    void\
    \ add_vertex(T val = tid) {\n        ptr.push_back(LCB::my_new(val));\n      \
    \  ptr.back()->id = N;\n        N++;\n    }\n\n    // \u8FBA\u8FFD\u52A0\n   \
    \ void add_edge(int u, int v) {\n        LCB::link(ptr[u], ptr[v]);\n    }\n\n\
    \    // \u8FBA\u524A\u9664\n    void remove_edge(int u, int v) {\n        LCB::cut(ptr[u],\
    \ ptr[v]);\n    }\n\n    // 1\u70B9\u53D6\u5F97\n    T operator[](int k) {\n \
    \       return LCB::get_key(ptr[k]);\n    }\n\n    // \u533A\u9593\u53D6\u5F97\
    (\u30D1\u30B9\u30AF\u30A8\u30EA)\n    T query(int s, int t) {\n        return\
    \ LCB::fold(ptr[s], ptr[t]);\n    }\n\n    // \u30DD\u30A4\u30F3\u30BF -> \u9802\
    \u70B9\u756A\u53F7\n    int get_id(Ptr x) {\n        if (x != nullptr) {\n   \
    \         return x->id;\n        } else {\n            return -1;\n        }\n\
    \    }\n\n    // \u9802\u70B9u,v\u306ELCA\u3092\u8FD4\u3059(\u9023\u7D50\u3067\
    \u306A\u3051\u308C\u3070-1)\n    int lca(int u, int v) {\n        return get_id(LCB::lca(ptr[u],\
    \ ptr[v]));\n    }\n\n    // \u9802\u70B9x\u304B\u3089\u898B\u3066k\u56DE\u9061\
    \u3063\u305F\u7956\u5148\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070-1)\n    int\
    \ la(int x, int k) {\n        return get_id(LCB::get_kth(ptr[x], k));\n    }\n\
    \n    // \u9802\u70B9x\u306E\u89AA\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070\
    -1)\n    int par(int x) {\n        return get_id(LCB::get_parent(ptr[x]));\n \
    \   }\n\n    // \u9802\u70B9x\u304C\u5C5E\u3059\u308B\u6728\u306E\u6839\u3092\u8FD4\
    \u3059\n    int get_root(int x) {\n        return get_id(LCB::get_root(ptr[x]));\n\
    \    }\n\n    // \u540C\u3058\u6728\u306B\u5C5E\u3059\u308B\u304B\n    bool same(int\
    \ u, int v) {\n        return get_root(u) == get_root(v);\n    }\n\n    // 1\u70B9\
    \u66F4\u65B0\n    void update(int x, E val) {\n        apply(ptr[x], ptr[x], val);\n\
    \    }\n\n    // \u533A\u9593\u66F4\u65B0(\u30D1\u30B9\u30AF\u30A8\u30EA)\n  \
    \  void update(int u, int v, const E &e) {\n        apply(ptr[u], ptr[v], e);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"LinkCutTree.hpp\"\n\n\
    // \u9045\u5EF6Link Cut Tree\n// \u4F7F\u3044\u65B9\n// \u30FB\u307B\u307CLCT\u3068\
    \u540C\u3058\u306B\u3057\u3066\u3042\u308B\u306E\u3067\u305D\u3061\u3089\u3092\
    \u53C2\u7167\u3002\n// \u30FB\u6A5F\u80FD\u3068\u3057\u3066\u306F\u533A\u9593\u66F4\
    \u65B0\u7528\u306Eupdate\u3060\u3051\u8FFD\u52A0\u3057\u3066\u3042\u308B\u3002\
    \n// \u3000\u3042\u30681\u70B9\u66F4\u65B0\u306Eupdate\u3082\u8981\u7D20\u76F4\
    \u63A5\u3044\u3058\u3063\u305F\u3089\u9045\u5EF6\u306E\u524D\u5F8C\u95A2\u4FC2\
    \u58CA\u308C\u305D\u3046\u3060\u304B\u3089\u3001\n// \u3000\u4F5C\u7528\u7D20\u3092\
    \u66F4\u65B0\u3059\u308B\u611F\u3058\u306B\u5909\u3048\u3066\u3042\u308B\u3002\
    \n// \u30FB\u5358\u4F4D\u5143\u306FACL\u30BB\u30B0\u6728\u3068\u540C\u3058\u3088\
    \u3046\u306A\u611F\u3058\u3067\u95A2\u6570\u306E\u5F62\u3067\u6E21\u3059\u3002\
    \n\n// \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\
    \u6728(\u57FA\u5E95\u30AF\u30E9\u30B9)\n// see: https://nyaannyaan.github.io/library/lct/lazy-reversible-bbst-base.hpp\n\
    template<\n    typename Tree, typename Node, typename T, typename E, T (*f)(T,\
    \ T),\n    T (*g)(T, E), E (*h)(E, E), T (*ts)(T), T (*tid)(), E (*eid)()>\nstruct\
    \ LazyReversibleBBST : Tree {\n    using Tree::merge;\n    using Tree::split;\n\
    \    using typename Tree::Ptr;\n\n    LazyReversibleBBST() = default;\n\n    void\
    \ toggle(Ptr t) {\n        if (!t) return;\n        swap(t->l, t->r);\n      \
    \  t->sum = ts(t->sum);\n        t->rev ^= true;\n    }\n\n    T fold(Ptr &t,\
    \ int a, int b) {\n        auto x = split(t, a);\n        auto y = split(x.second,\
    \ b - a);\n        auto ret = sum(y.first);\n        t = merge(x.first, merge(y.first,\
    \ y.second));\n        return ret;\n    }\n\n    void reverse(Ptr &t, int a, int\
    \ b) {\n        auto x = split(t, a);\n        auto y = split(x.second, b - a);\n\
    \        toggle(y.first);\n        t = merge(x.first, merge(y.first, y.second));\n\
    \    }\n\n    void apply(Ptr &t, int a, int b, const E &e) {\n        auto x =\
    \ split(t, a);\n        auto y = split(x.second, b - a);\n        propagate(y.first,\
    \ e);\n        t = merge(x.first, merge(y.first, y.second));\n    }\n\nprotected:\n\
    \    inline T sum(const Ptr t) {\n        return t ? t->sum : tid();\n    }\n\n\
    \    Ptr update(Ptr t) override {\n        if (!t) return t;\n        t->cnt =\
    \ 1;\n        t->sum = t->key;\n        if (t->l) t->cnt += t->l->cnt, t->sum\
    \ = f(t->l->sum, t->sum);\n        if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum,\
    \ t->r->sum);\n        return t;\n    }\n\n    void push(Ptr t) override {\n \
    \       if (!t) return;\n        if (t->rev) {\n            if (t->l) toggle(t->l);\n\
    \            if (t->r) toggle(t->r);\n            t->rev = false;\n        }\n\
    \        if (t->lazy != eid()) {\n            if (t->l) propagate(t->l, t->lazy);\n\
    \            if (t->r) propagate(t->r, t->lazy);\n            t->lazy = eid();\n\
    \        }\n    }\n\n    void propagate(Ptr t, const E &x) {\n        t->lazy\
    \ = h(t->lazy, x);\n        t->key = g(t->key, x);\n        t->sum = g(t->sum,\
    \ x);\n    }\n};\n\n// \u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDSplay Tree\n\
    // see: https://nyaannyaan.github.io/library/lct/splay-lazy-reversible.hpp\ntemplate<typename\
    \ T, typename E, T (*tid)(), E (*eid)()>\nstruct LazyReversibleSplayTreeNode {\n\
    \    using Ptr = LazyReversibleSplayTreeNode *;\n    Ptr l, r, p;\n    T key,\
    \ sum;\n    E lazy;\n    int cnt, id;\n    bool rev;\n\n    LazyReversibleSplayTreeNode(const\
    \ T &t = tid(), const E &e = eid())\n        : l(),\n          r(),\n        \
    \  p(),\n          key(t),\n          sum(t),\n          lazy(e),\n          cnt(1),\n\
    \          id(-1),\n          rev(false) {\n    }\n};\n\ntemplate<\n    typename\
    \ T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n    T (*ts)(T), T\
    \ (*tid)(), E (*eid)()>\nstruct LazyReversibleSplayTree\n    : LazyReversibleBBST<\n\
    \          SplayTreeBase<LazyReversibleSplayTreeNode<T, E, tid, eid>>,\n     \
    \     LazyReversibleSplayTreeNode<T, E, tid, eid>, T, E, f, g, h, ts, tid, eid>\
    \ {\n    using Node = LazyReversibleSplayTreeNode<T, E, tid, eid>;\n};\n\n// \u9045\
    \u5EF6\u4F1D\u642CLink Cut Tree\n// see: https://nyaannyaan.github.io/library/lct/link-cut-tree-lazy.hpp\n\
    template<\n    typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),\n\
    \    T (*ts)(T), T (*tid)(), E (*eid)()>\nstruct LazyLinkCutTree\n    : LinkCutBase<LazyReversibleSplayTree<T,\
    \ E, f, g, h, ts, tid, eid>> {\n    using LCB = LinkCutBase<LazyReversibleSplayTree<T,\
    \ E, f, g, h, ts, tid, eid>>;\n    using Ptr = typename LCB::Ptr;\n\nprotected:\n\
    \    void set_key(Ptr t, const T &key) override {\n        LCB::evert(t);\n  \
    \      t->key = key;\n        LCB::update(t);\n    }\n\n    T get_key(Ptr t) override\
    \ {\n        LCB::evert(t);\n        return t->key;\n    }\n\n    void apply(Ptr\
    \ u, Ptr v, const E &e) {\n        LCB::evert(u);\n        LCB::expose(v);\n \
    \       LCB::propagate(v, e);\n    }\n\npublic:\n    vector<Ptr> ptr;\n    int\
    \ N;\n\n    LazyLinkCutTree() : N(0) {}\n\n    // \u9802\u70B9\u6570N\u306E\u68EE\
    \u3068\u3057\u3066\u521D\u671F\u5316\n    LazyLinkCutTree(int N) : N(N) {\n  \
    \      ptr.resize(N);\n        for (int i = 0; i < N; i++) {\n            ptr[i]\
    \ = LCB::my_new();\n            ptr[i]->id = i;\n        }\n    }\n\n    LazyLinkCutTree(const\
    \ vector<T> &vec) : N(vec.size()) {\n        ptr.resize(N);\n        for (int\
    \ i = 0; i < N; i++) {\n            ptr[i] = LCB::my_new(vec[i]);\n          \
    \  ptr[i]->id = i;\n        }\n    }\n\n    // \u9802\u70B9\u8FFD\u52A0\n    void\
    \ add_vertex(T val = tid) {\n        ptr.push_back(LCB::my_new(val));\n      \
    \  ptr.back()->id = N;\n        N++;\n    }\n\n    // \u8FBA\u8FFD\u52A0\n   \
    \ void add_edge(int u, int v) {\n        LCB::link(ptr[u], ptr[v]);\n    }\n\n\
    \    // \u8FBA\u524A\u9664\n    void remove_edge(int u, int v) {\n        LCB::cut(ptr[u],\
    \ ptr[v]);\n    }\n\n    // 1\u70B9\u53D6\u5F97\n    T operator[](int k) {\n \
    \       return LCB::get_key(ptr[k]);\n    }\n\n    // \u533A\u9593\u53D6\u5F97\
    (\u30D1\u30B9\u30AF\u30A8\u30EA)\n    T query(int s, int t) {\n        return\
    \ LCB::fold(ptr[s], ptr[t]);\n    }\n\n    // \u30DD\u30A4\u30F3\u30BF -> \u9802\
    \u70B9\u756A\u53F7\n    int get_id(Ptr x) {\n        if (x != nullptr) {\n   \
    \         return x->id;\n        } else {\n            return -1;\n        }\n\
    \    }\n\n    // \u9802\u70B9u,v\u306ELCA\u3092\u8FD4\u3059(\u9023\u7D50\u3067\
    \u306A\u3051\u308C\u3070-1)\n    int lca(int u, int v) {\n        return get_id(LCB::lca(ptr[u],\
    \ ptr[v]));\n    }\n\n    // \u9802\u70B9x\u304B\u3089\u898B\u3066k\u56DE\u9061\
    \u3063\u305F\u7956\u5148\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070-1)\n    int\
    \ la(int x, int k) {\n        return get_id(LCB::get_kth(ptr[x], k));\n    }\n\
    \n    // \u9802\u70B9x\u306E\u89AA\u3092\u8FD4\u3059(\u306A\u3051\u308C\u3070\
    -1)\n    int par(int x) {\n        return get_id(LCB::get_parent(ptr[x]));\n \
    \   }\n\n    // \u9802\u70B9x\u304C\u5C5E\u3059\u308B\u6728\u306E\u6839\u3092\u8FD4\
    \u3059\n    int get_root(int x) {\n        return get_id(LCB::get_root(ptr[x]));\n\
    \    }\n\n    // \u540C\u3058\u6728\u306B\u5C5E\u3059\u308B\u304B\n    bool same(int\
    \ u, int v) {\n        return get_root(u) == get_root(v);\n    }\n\n    // 1\u70B9\
    \u66F4\u65B0\n    void update(int x, E val) {\n        apply(ptr[x], ptr[x], val);\n\
    \    }\n\n    // \u533A\u9593\u66F4\u65B0(\u30D1\u30B9\u30AF\u30A8\u30EA)\n  \
    \  void update(int u, int v, const E &e) {\n        apply(ptr[u], ptr[v], e);\n\
    \    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/graph/LinkCutTree.hpp
  isVerificationFile: false
  path: src/graph/LazyLinkCutTree.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/LazyLinkCutTree.hpp
layout: document
redirect_from:
- /library/src/graph/LazyLinkCutTree.hpp
- /library/src/graph/LazyLinkCutTree.hpp.html
title: src/graph/LazyLinkCutTree.hpp
---
