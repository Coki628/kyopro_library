#pragma once
#include "../base.hpp"
#include "ObjectPool.hpp"

// 永続遅延セグメント木
// 参考：https://suisen-cp.github.io/cp-library-cpp/library/datastructure/segment_tree/persistent_lazy_segment_tree.hpp
// 使い方
// ・基本的には普通の永続セグ木と一緒。(使用例はabc253_fを参照)
// ・メモリを予め確保できる機構が備わってる。(その方が動的確保よりメモリ食わないし、速い。)
// 　初期化後に、init_poolを呼び出して、要素を確保してやる必要がある。
// 　具体的には、コンストラクタ→init_pool→buildの順で準備する。
template<typename F, typename G, typename H, typename Monoid, typename OperatorMonoid>
struct PersistentLazySegmentTree {
    int sz;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    struct Node {
        static inline ObjectPool<Node> _pool;
        static Node *clone(Node *node) {
            return &(*_pool.alloc() = *node);
        }

        Monoid data;
        OperatorMonoid lazy;
        Node *l, *r;

        // このコンストラクタがないとObjectPoolのメモリ確保が動かない
        Node() {}

        Node(const Monoid &data, const OperatorMonoid &lazy)
            : data(data),
              lazy(lazy),
              l(nullptr),
              r(nullptr) {
        }
    };

    PersistentLazySegmentTree(
        const F f, const G g, const H h, const Monoid &M1,
        const OperatorMonoid OM0
    )
        : f(f),
          g(g),
          h(h),
          M1(M1),
          OM0(OM0) {
    }

    Node *build(const vector<Monoid> &v) {
        sz = (int)v.size();
        return build(0, (int)v.size(), v);
    }

    Node *merge(Node *l, Node *r) {
        Node *res = Node::_pool.alloc();
        *res = Node(f(l->data, r->data), OM0);
        res->l = l;
        res->r = r;
        return res;
    }

    Node *build(int l, int r, const vector<Monoid> &v) {
        if (l + 1 == r) {
            Node *res = Node::_pool.alloc();
            return &(*res = Node(v[l], OM0));
        } else {
            return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
        }
    }

    template<bool do_clone = true>
    auto push(Node *node) {
        Node *res = node;
        if constexpr (do_clone) res = Node::clone(res);
        res->l = update_all(res->l, res->lazy);
        res->r = update_all(res->r, res->lazy);
        res->lazy = OM0;
        if constexpr (do_clone) {
            return res;
        } else {
            return;
        }
    }

    Node *update_all(Node *node, const OperatorMonoid &x) {
        if (not node) return nullptr;
        Node *res = Node::clone(node);
        res->data = g(res->data, x);
        res->lazy = h(res->lazy, x);
        return res;
    }

    Node *
    update(int a, int b, const OperatorMonoid &x, Node *node, int l, int r) {
        if (r <= a || b <= l) {
            return node;
        } else if (a <= l && r <= b) {
            return update_all(node, x);
        } else {
            Node *res = push(node);
            res->l = update(a, b, x, res->l, l, (l + r) >> 1);
            res->r = update(a, b, x, res->r, (l + r) >> 1, r);
            res->data = f(res->l->data, res->r->data);
            return res;
        }
    }

    Node *update(Node *node, int a, int b, const OperatorMonoid &x) {
        return update(a, b, x, node, 0, sz);
    }

    Node *update(Node *node, int k, const OperatorMonoid &x) {
        return update(node, k, k + 1, x);
    }

    Monoid
    query(int a, int b, Node *node, int l, int r, const OperatorMonoid &x) {
        if (r <= a || b <= l) {
            return M1;
        } else if (a <= l && r <= b) {
            return g(node->data, x);
        } else {
            OperatorMonoid y = h(x, node->lazy);
            return f(
                query(a, b, node->l, l, (l + r) >> 1, y),
                query(a, b, node->r, (l + r) >> 1, r, y)
            );
        }
    }

    Monoid query(Node *node, int a, int b) {
        return query(a, b, node, 0, sz, OM0);
    }

    Monoid all(Node *node) {
        return node ? node->data : M1;
    }

    Monoid get(Node *node, int a) {
        return query(node, a, a + 1);
    }

    void print(Node *node, int n) {
        for (int i = 0; i < n; i++) {
            cout << query(node, i, i + 1);
            if (i == n - 1) cout << endl;
            else cout << ' ';
        }
    }

    void init_pool(int siz) {
        Node::_pool = ObjectPool<Node>(siz);
    }
    void clear_pool() {
        Node::_pool.clear();
    }
};

template<typename F, typename G, typename H, typename T, typename E>
PersistentLazySegmentTree<F, G, H, T, E> get_persistent_lazy_segment_tree(
    const F &f, const G &g, const H &h, const T &ti, const E &ei
) {
    return {f, g, h, ti, ei};
}
