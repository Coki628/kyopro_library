

// 遅延伝搬反転可能乱択平衡二分木
// 使い方
// ・まずbuildの引数にvector渡すか、make_treeで木を作る。
// ・基本的に第一引数に対象の木のポインタ、第二引数以降に添字とか渡す。
// ・生成する木がそれぞれ別の配列のように扱えて独立に、
// 　任意位置挿入や削除、セグ木的な区間操作、区間リバースなどができる。
// ・各木はマージしたり、任意位置で切ったりもできるらしい。(これはまだ試してない)

// see: https://nyaannyaan.github.io/library/rbst/rbst-base.hpp
template<typename Node>
struct RBSTBase {
    using Ptr = Node *;
    template<typename... Args> inline Ptr my_new(Args... args) {
        return new Node(args...);
    }
    inline void my_del(Ptr t) {
        delete t;
    }

    // 空の木を作成 O(1)
    inline Ptr make_tree() const {
        return nullptr;
    }

    // for avoiding memory leak, activate below
    /*
    using Ptr = shared_ptr<Node>;
    template <typename... Args>
    inline Ptr my_new(Args... args) {
        return make_shared<Node>(args...);
    }
    inline void my_del(Ptr t) {}
    Ptr make_tree() {return Ptr();}
    */

    // 木tの要素数を取得 O(1)
    int size(Ptr t) const {
        return count(t);
    }

    Ptr merge(Ptr l, Ptr r) {
        if (!l || !r) return l ? l : r;
        if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
            push(l);
            l->r = merge(l->r, r);
            return update(l);
        } else {
            push(r);
            r->l = merge(l, r->l);
            return update(r);
        }
    }

    pair<Ptr, Ptr> split(Ptr t, int k) {
        if (!t) return {nullptr, nullptr};
        push(t);
        if (k <= count(t->l)) {
            auto s = split(t->l, k);
            t->l = s.second;
            return {s.first, update(t)};
        } else {
            auto s = split(t->r, k - count(t->l) - 1);
            t->r = s.first;
            return {update(t), s.second};
        }
    }

    Ptr build(int l, int r, const vector<decltype(Node::key)> &v) {
        if (l + 1 == r) return my_new(v[l]);
        int m = (l + r) >> 1;
        Ptr pm = my_new(v[m]);
        if (l < m) pm->l = build(l, m, v);
        if (m + 1 < r) pm->r = build(m + 1, r, v);
        return update(pm);
    }

    // 配列vを初期値とした新たな木を作る O(N)
    Ptr build(const vector<decltype(Node::key)> &v) {
        return build(0, (int)v.size(), v);
    }

    // 木tのk番目(0-indexed)に要素args(複数可)を挿入する O(logN)
    template<typename... Args>
    void insert(Ptr &t, int k, const Args &...args) {
        auto x = split(t, k);
        t = merge(merge(x.first, my_new(args...)), x.second);
    }

    // 木tのk番目(0-indexed)の要素を削除する O(logN)
    void erase(Ptr &t, int k) {
        auto x = split(t, k);
        auto y = split(x.second, 1);
        my_del(y.first);
        t = merge(x.first, y.second);
    }

protected:
    static uint64_t rng() {
        static uint64_t x_ = 88172645463325252ULL;
        return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;
    }

    inline int count(const Ptr t) const {
        return t ? t->cnt : 0;
    }

    virtual void push(Ptr) = 0;

    virtual Ptr update(Ptr) = 0;
};

template<typename T, typename E>
struct LazyReversibleRBSTNode {
    typename RBSTBase<LazyReversibleRBSTNode>::Ptr l, r;
    T key, sum;
    E lazy;
    int cnt;
    bool rev;

    LazyReversibleRBSTNode(const T &t = T(), const E &e = E())
        : l(),
          r(),
          key(t),
          sum(t),
          lazy(e),
          cnt(1),
          rev(false) {
    }
};

// see: https://nyaannyaan.github.io/library/rbst/lazy-reversible-rbst.hpp
template<
    typename T, typename E, T (*f)(T, T), T (*g)(T, E), E (*h)(E, E),
    T (*ts)(T)>
struct LazyReversibleRBST : RBSTBase<LazyReversibleRBSTNode<T, E>> {
    using Node = LazyReversibleRBSTNode<T, E>;
    using base = RBSTBase<LazyReversibleRBSTNode<T, E>>;
    using base::merge;
    using base::split;
    using typename base::Ptr;

    LazyReversibleRBST() = default;

    void toggle(Ptr t) {
        if (!t) return;
        swap(t->l, t->r);
        t->sum = ts(t->sum);
        t->rev ^= true;
    }

    // [a,b)を区間取得する O(logN)
    T fold(Ptr &t, int a, int b) {
        assert(a < b);
        auto x = split(t, a);
        auto y = split(x.second, b - a);
        auto ret = sum(y.first);
        t = merge(x.first, merge(y.first, y.second));
        return ret;
    }

    // [a,b)を区間リバースする O(logN)
    void reverse(Ptr &t, int a, int b) {
        assert(a < b);
        auto x = split(t, a);
        auto y = split(x.second, b - a);
        toggle(y.first);
        t = merge(x.first, merge(y.first, y.second));
    }

    // [a,b)を作用素eで区間更新する O(logN)
    void apply(Ptr &t, int a, int b, const E &e) {
        assert(a < b);
        auto x = split(t, a);
        auto y = split(x.second, b - a);
        propagate(y.first, e);
        t = merge(x.first, merge(y.first, y.second));
    }

    // 1点取得 O(logN)
    T get(Ptr &t, int i) {
        return this->fold(t, i, i + 1);
    }

protected:
    inline T sum(const Ptr t) const {
        return t ? t->sum : T();
    }

    Ptr update(Ptr t) override {
        push(t);
        t->cnt = 1;
        t->sum = t->key;
        if (t->l) t->cnt += t->l->cnt, t->sum = f(t->l->sum, t->sum);
        if (t->r) t->cnt += t->r->cnt, t->sum = f(t->sum, t->r->sum);
        return t;
    }

    void push(Ptr t) override {
        if (t->rev) {
            if (t->l) toggle(t->l);
            if (t->r) toggle(t->r);
            t->rev = false;
        }
        if (t->lazy != E()) {
            if (t->l) propagate(t->l, t->lazy);
            if (t->r) propagate(t->r, t->lazy);
            t->lazy = E();
        }
    }

    void propagate(Ptr t, const E &x) {
        t->lazy = h(t->lazy, x);
        t->key = g(t->key, x);
        t->sum = g(t->sum, x);
    }
};
