#pragma once
#include "../base.hpp"
#include "LinkCutTree.hpp"

// 遅延Link Cut Tree
// 使い方
// ・ほぼLCTと同じにしてあるのでそちらを参照。
// ・機能としては区間更新用のupdateだけ追加してある。
// 　あと1点更新のupdateも要素直接いじったら遅延の前後関係壊れそうだから、
// 　作用素を更新する感じに変えてある。
// ・単位元はACLセグ木と同じような感じで関数の形で渡す。

// 遅延伝搬反転可能平衡二分木(基底クラス)
// see: https://nyaannyaan.github.io/library/lct/lazy-reversible-bbst-base.hpp
template<
    typename Tree, typename Node, typename T, typename E, T (*f)(T, T),
    T (*g)(T, E), E (*h)(E, E), T (*ts)(T), T (*tid)(), E (*eid)()>
struct LazyReversibleBBST : Tree {
    using Tree::merge;
    using Tree::split;
    using typename Tree::Ptr;

    LazyReversibleBBST() = default;

    void toggle(Ptr t) {
        if (!t) return;
        swap(t->l, t->r);
        t->sum = ts(t->sum);
        t->rev ^= true;
    }

    T fold(Ptr &t, int a, int b) {
        auto x = split(t, a);
        auto y = split(x.second, b - a);
        auto ret = sum(y.first);
        t = merge(x.first, merge(y.first, y.second));
        return ret;
    }

    void reverse(Ptr &t, int a, int b) {
        auto x = split(t, a);
        auto y = split(x.second, b - a);
        toggle(y.first);
        t = merge(x.first, merge(y.first, y.second));
    }

    void apply(Ptr &t, int a, int b, const E &e) {
        auto x = split(t, a);
        auto y = split(x.second, b - a);
        propagate(y.first, e);
        t = merge(x.first, merge(y.first, y.second));
    }

protected:
    inline T sum(const Ptr t) {
        return t ? t->sum : tid();
    }

    Ptr update(Ptr t) override {
        if (!t) return t;
        t->cnt = 1;
        t->sum = t->key;
        if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
        if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
        return t;
    }

    void push(Ptr t) override {
        if (!t) return;
        if (t->rev) {
            if (t->l) toggle(t->l);
            if (t->r) toggle(t->r);
            t->rev = false;
        }
        if (t->lazy != eid()) {
            if (t->l) propagate(t->l, t->lazy);
            if (t->r) propagate(t->r, t->lazy);
            t->lazy = eid();
        }
    }

    void propagate(Ptr t, const E &x) {
        t->lazy = h(t->lazy, x);
        t->key = g(t->key, x);
        t->sum = g(t->sum, x);
    }
};

// 遅延伝搬反転可能Splay Tree
// see: https://nyaannyaan.github.io/library/lct/splay-lazy-reversible.hpp
template<typename T, typename E, T (*tid)(), E (*eid)()>
struct LazyReversibleSplayTreeNode {
    using Ptr = LazyReversibleSplayTreeNode *;
    Ptr l, r, p;
    T key, sum;
    E lazy;
    int cnt, id;
    bool rev;

    LazyReversibleSplayTreeNode(const T &t = tid(), const E &e = eid())
        : l(),
          r(),
          p(),
          key(t),
          sum(t),
          lazy(e),
          cnt(1),
          id(-1),
          rev(false) {
    }
};

template<
    typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
    T (*ts)(T), T (*tid)(), E (*eid)()>
struct LazyReversibleSplayTree
    : LazyReversibleBBST<
          SplayTreeBase<LazyReversibleSplayTreeNode<T, E, tid, eid>>,
          LazyReversibleSplayTreeNode<T, E, tid, eid>, T, E, f, g, h, ts, tid, eid> {
    using Node = LazyReversibleSplayTreeNode<T, E, tid, eid>;
};

// 遅延伝搬Link Cut Tree
// see: https://nyaannyaan.github.io/library/lct/link-cut-tree-lazy.hpp
template<
    typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
    T (*ts)(T), T (*tid)(), E (*eid)()>
struct LazyLinkCutTree
    : LinkCutBase<LazyReversibleSplayTree<T, E, f, g, h, ts, tid, eid>> {
    using LCB = LinkCutBase<LazyReversibleSplayTree<T, E, f, g, h, ts, tid, eid>>;
    using Ptr = typename LCB::Ptr;

protected:
    void set_key(Ptr t, const T &key) override {
        LCB::evert(t);
        t->key = key;
        LCB::update(t);
    }

    T get_key(Ptr t) override {
        LCB::evert(t);
        return t->key;
    }

    void apply(Ptr u, Ptr v, const E &e) {
        LCB::evert(u);
        LCB::expose(v);
        LCB::propagate(v, e);
    }

public:
    vector<Ptr> ptr;
    int N;

    LazyLinkCutTree() : N(0) {}

    // 頂点数Nの森として初期化
    LazyLinkCutTree(int N) : N(N) {
        ptr.resize(N);
        for (int i = 0; i < N; i++) {
            ptr[i] = LCB::my_new();
            ptr[i]->id = i;
        }
    }

    LazyLinkCutTree(const vector<T> &vec) : N(vec.size()) {
        ptr.resize(N);
        for (int i = 0; i < N; i++) {
            ptr[i] = LCB::my_new(vec[i]);
            ptr[i]->id = i;
        }
    }

    // 頂点追加
    void add_vertex(T val = tid) {
        ptr.push_back(LCB::my_new(val));
        ptr.back()->id = N;
        N++;
    }

    // 辺追加
    void add_edge(int u, int v) {
        LCB::link(ptr[u], ptr[v]);
    }

    // 辺削除
    void remove_edge(int u, int v) {
        LCB::cut(ptr[u], ptr[v]);
    }

    // 1点取得
    T operator[](int k) {
        return LCB::get_key(ptr[k]);
    }

    // 区間取得(パスクエリ)
    T query(int s, int t) {
        return LCB::fold(ptr[s], ptr[t]);
    }

    // ポインタ -> 頂点番号
    int get_id(Ptr x) {
        if (x != nullptr) {
            return x->id;
        } else {
            return -1;
        }
    }

    // 頂点u,vのLCAを返す(連結でなければ-1)
    int lca(int u, int v) {
        return get_id(LCB::lca(ptr[u], ptr[v]));
    }

    // 頂点xから見てk回遡った祖先を返す(なければ-1)
    int la(int x, int k) {
        return get_id(LCB::get_kth(ptr[x], k));
    }

    // 頂点xの親を返す(なければ-1)
    int par(int x) {
        return get_id(LCB::get_parent(ptr[x]));
    }

    // 頂点xが属する木の根を返す
    int get_root(int x) {
        return get_id(LCB::get_root(ptr[x]));
    }

    // 同じ木に属するか
    bool same(int u, int v) {
        return get_root(u) == get_root(v);
    }

    // 1点更新
    void update(int x, E val) {
        apply(ptr[x], ptr[x], val);
    }

    // 区間更新(パスクエリ)
    void update(int u, int v, const E &e) {
        apply(ptr[u], ptr[v], e);
    }
};
