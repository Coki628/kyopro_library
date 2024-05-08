#pragma once
#include "../base.hpp"

// Link Cut Tree
// 参考：https://nyaannyaan.github.io/library/lct/link-cut-tree.hpp
// 使い方
// ・HLDみたいなパスクエリに加えて、辺追加・削除を動的に行える。
// 使用例1：abc250_gでLCAやk個遡った祖先の取得など。
// 使用例2：dynamic_tree_vertex_add_path_sumで辺削除やパスクエリの区間和取得など。

// 反転可能平衡二分木(基底クラス)
// see: https://nyaannyaan.github.io/library/lct/reversible-bbst-base.hpp
template<typename Tree, typename Node, typename T, T (*f)(T, T), T (*ts)(T)>
struct ReversibleBBST : Tree {
    using Tree::merge;
    using Tree::split;
    using typename Tree::Ptr;

    ReversibleBBST() = default;

    virtual void toggle(Ptr t) {
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

    Ptr update(Ptr t) override {
        if (!t) return t;
        t->cnt = 1;
        t->sum = t->key;
        if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
        if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
        return t;
    }

protected:
    inline T sum(const Ptr t) {
        return t ? t->sum : T();
    }

    void push(Ptr t) override {
        if (!t) return;
        if (t->rev) {
            if (t->l) toggle(t->l);
            if (t->r) toggle(t->r);
            t->rev = false;
        }
    }
};

// see: https://nyaannyaan.github.io/library/lct/splay-base.hpp
template<typename Node> struct SplayTreeBase {
    using Ptr = Node *;
    template<typename... Args> Ptr my_new(const Args &...args) {
        return new Node(args...);
    }
    void my_del(Ptr p) {
        delete p;
    }

    bool is_root(Ptr t) {
        return !(t->p) || (t->p->l != t && t->p->r != t);
    }

    int size(Ptr t) const {
        return count(t);
    }

    virtual void splay(Ptr t) {
        if (!t) return;
        push(t);
        while (!is_root(t)) {
            Ptr q = t->p;
            if (is_root(q)) {
                push(q), push(t);
                rot(t);
            } else {
                Ptr r = q->p;
                push(r), push(q), push(t);
                if (pos(q) == pos(t)) rot(q), rot(t);
                else rot(t), rot(t);
            }
        }
    }

    Ptr get_left(Ptr t) {
        while (t->l) push(t), t = t->l;
        return t;
    }

    Ptr get_right(Ptr t) {
        while (t->r) push(t), t = t->r;
        return t;
    }

    pair<Ptr, Ptr> split(Ptr t, int k) {
        if (!t) return {nullptr, nullptr};
        if (k == 0) return {nullptr, t};
        if (k == count(t)) return {t, nullptr};
        push(t);
        if (k <= count(t->l)) {
            auto x = split(t->l, k);
            t->l = x.second;
            t->p = nullptr;
            if (x.second) x.second->p = t;
            return {x.first, update(t)};
        } else {
            auto x = split(t->r, k - count(t->l) - 1);
            t->r = x.first;
            t->p = nullptr;
            if (x.first) x.first->p = t;
            return {update(t), x.second};
        }
    }

    Ptr merge(Ptr l, Ptr r) {
        if (!l && !r) return nullptr;
        if (!l) return splay(r), r;
        if (!r) return splay(l), l;
        splay(l), splay(r);
        l = get_right(l);
        splay(l);
        l->r = r;
        r->p = l;
        update(l);
        return l;
    }

    using Key = decltype(Node::key);
    Ptr build(const vector<Key> &v) {
        return build(0, v.size(), v);
    }
    Ptr build(int l, int r, const vector<Key> &v) {
        if (l == r) return nullptr;
        if (l + 1 == r) return my_new(v[l]);
        return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
    }

    template<typename... Args> void insert(Ptr &t, int k, const Args &...args) {
        splay(t);
        auto x = split(t, k);
        t = merge(merge(x.first, my_new(args...)), x.second);
    }

    void erase(Ptr &t, int k) {
        splay(t);
        auto x = split(t, k);
        auto y = split(x.second, 1);
        my_del(y.first);
        t = merge(x.first, y.second);
    }

    virtual Ptr update(Ptr t) = 0;

protected:
    inline int count(Ptr t) const {
        return t ? t->cnt : 0;
    }

    virtual void push(Ptr t) = 0;

    Ptr build(const vector<Ptr> &v) {
        return build(0, v.size(), v);
    }

    Ptr build(int l, int r, const vector<Ptr> &v) {
        if (l + 1 >= r) return v[l];
        return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
    }

    inline int pos(Ptr t) {
        if (t->p) {
            if (t->p->l == t) return -1;
            if (t->p->r == t) return 1;
        }
        return 0;
    }

    virtual void rot(Ptr t) {
        Ptr x = t->p, y = x->p;
        if (pos(t) == -1) {
            if ((x->l = t->r)) t->r->p = x;
            t->r = x, x->p = t;
        } else {
            if ((x->r = t->l)) t->l->p = x;
            t->l = x, x->p = t;
        }
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
        }
    }
};

// 反転可能Splay Tree
// see: https://nyaannyaan.github.io/library/lct/splay-reversible.hpp
template<typename T> struct ReversibleSplayTreeNode {
    using Ptr = ReversibleSplayTreeNode *;
    Ptr l, r, p;
    T key, sum;
    int cnt, id;
    bool rev;

    ReversibleSplayTreeNode(const T &t = T())
        : l(),
          r(),
          p(),
          key(t),
          sum(t),
          cnt(1),
          id(-1),
          rev(false) {
    }
};

template<typename T, T (*f)(T, T), T (*ts)(T)>
struct ReversibleSplayTree : ReversibleBBST<
                                 SplayTreeBase<ReversibleSplayTreeNode<T>>,
                                 ReversibleSplayTreeNode<T>, T, f, ts> {
    using Node = ReversibleSplayTreeNode<T>;
};

// see: https://nyaannyaan.github.io/library/lct/link-cut-base.hpp
template<typename Splay> struct LinkCutBase : Splay {
    using Node = typename Splay::Node;
    using Ptr = Node *;

    virtual Ptr expose(Ptr t) {
        Ptr rp = nullptr;
        for (Ptr cur = t; cur; cur = cur->p) {
            this->splay(cur);
            cur->r = rp;
            this->update(cur);
            rp = cur;
        }
        this->splay(t);
        return rp;
    }

    virtual void link(Ptr u, Ptr v) {
        evert(u);
        expose(v);
        u->p = v;
    }

    void cut(Ptr u, Ptr v) {
        evert(u);
        expose(v);
        assert(u->p == v);
        v->l = u->p = nullptr;
        this->update(v);
    }

    void evert(Ptr t) {
        expose(t);
        this->toggle(t);
        this->push(t);
    }

    Ptr lca(Ptr u, Ptr v) {
        if (get_root(u) != get_root(v)) return nullptr;
        expose(u);
        return expose(v);
    }

    Ptr get_kth(Ptr x, int k) {
        expose(x);
        while (x) {
            this->push(x);
            if (x->r && x->r->cnt > k) {
                x = x->r;
            } else {
                if (x->r) k -= x->r->cnt;
                if (k == 0) return x;
                k -= 1;
                x = x->l;
            }
        }
        return nullptr;
    }

    Ptr get_root(Ptr x) {
        expose(x);
        while (x->l) this->push(x), x = x->l;
        return x;
    }

    Ptr get_parent(Ptr x) {
        expose(x);
        Ptr p = x->l;
        if (p == nullptr) return nullptr;
        while (true) {
            this->push(p);
            if (p->r == nullptr) return p;
            p = p->r;
        }
        exit(1);
    }

    virtual void set_key(Ptr t, const decltype(Node::key) &key) {
        this->splay(t);
        t->key = key;
        this->update(t);
    }

    virtual decltype(Node::key) get_key(Ptr t) {
        return t->key;
    }

    decltype(Node::key) fold(Ptr u, Ptr v) {
        evert(u);
        expose(v);
        return v->sum;
    }
};

// Link Cut Tree
// see: https://nyaannyaan.github.io/library/lct/link-cut-tree.hpp
template<typename T, T (*f)(T, T), T (*ts)(T)>
struct LinkCutTree : LinkCutBase<ReversibleSplayTree<T, f, ts>> {
    using LCB = LinkCutBase<ReversibleSplayTree<T, f, ts>>;
    using Node = typename LCB::Node;
    using Ptr = Node *;

    vector<Ptr> ptr;
    int N;

    LinkCutTree() : N(0) {}

    // 頂点数Nの森として初期化
    LinkCutTree(int N) : N(N) {
        ptr.resize(N);
        for (int i = 0; i < N; i++) {
            ptr[i] = LCB::my_new(T());
            ptr[i]->id = i;
        }
    }

    LinkCutTree(const vector<T> &vec) : N(vec.size()) {
        ptr.resize(N);
        for (int i = 0; i < N; i++) {
            ptr[i] = LCB::my_new(vec[i]);
            ptr[i]->id = i;
        }
    }

    // 頂点追加
    void add_vertex(T val = T()) {
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

    // 1点更新
    void update(int x, T val) {
        LCB::set_key(ptr[x], val);
    }

    // 1点取得
    T operator[](int k) {
        return LCB::get_key(ptr[k]);
    }

    // パスクエリ
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
};
// 例
// using T = long long;
// T f(T a, T b) {
//     return a + b;
// }
// T ts(T a) {
//     return a;
// }
