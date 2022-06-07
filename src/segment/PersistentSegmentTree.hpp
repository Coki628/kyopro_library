#include "../base.hpp"

// 参考：https://ei1333.github.io/library/structure/segment-tree/persistent-segment-tree.cpp
// 永続セグメント木
// 使い方
// ・基本的には普通のセグ木と一緒。ただし更新・取得ともに時点を示すポインタを引数に渡す必要がある。
// ・更新(と初期化)の時にその更新完了時点のポインタが返るので、
// 　それを配列とかに保持しておくと、任意の時点の情報を取り出せる。(実装例はabc253_fを参照)

template<typename Monoid, typename F>
struct PersistentSegmentTree {

    struct Node {
        Monoid data;
        Node *l, *r;

        Node(const Monoid &data) : data(data), l(nullptr), r(nullptr) {}
    };

    int sz;
    const F f;
    const Monoid M1;

    PersistentSegmentTree(const F f, const Monoid &M1) : f(f), M1(M1) {}

    Node *build(const vector< Monoid > &v) {
        sz = (int) v.size();
        return build(0, (int) v.size(), v);
    }

    Node *merge(Node *l, Node *r) {
        auto t = new Node(f(l->data, r->data));
        t->l = l;
        t->r = r;
        return t;
    }

    Node *build(int l, int r, const vector< Monoid > &v) {
        if(l + 1 >= r) return new Node(v[l]);
        return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
    }

    Node *update(int a, const Monoid &x, Node *k, int l, int r) {
        if(r <= a || a + 1 <= l) {
            return k;
        } else if(a <= l && r <= a + 1) {
            return new Node(x);
        } else {
            return merge(update(a, x, k->l, l, (l + r) >> 1), update(a, x, k->r, (l + r) >> 1, r));
        }
    }

    Node *update(Node *t, int k, const Monoid &x) {
        return update(k, x, t, 0, sz);
    }

    Monoid query(int a, int b, Node *k, int l, int r) {
        if(r <= a || b <= l) {
            return M1;
        } else if(a <= l && r <= b) {
            return k->data;
        } else {
            return f(query(a, b, k->l, l, (l + r) >> 1),
                     query(a, b, k->r, (l + r) >> 1, r));
        }
    }

    Monoid query(Node* t, int a, int b) {
        return query(a, b, t, 0, sz);
    }

    Monoid all(Node* node) {
        return node ? node->data : M1;
    }

    Monoid get(Node* t, int a) {
        return query(t, a, a+1);
    }

    void print(Node* t, int n) {
        for (int i=0; i<n; i++) {
            cout << query(t, i, i+1);
            if (i == n-1) cout << endl;
            else cout << ' ';
        }
    }
};

template<typename Monoid, typename F>
PersistentSegmentTree<Monoid, F> get_persistent_segment_tree(const F& f, const Monoid& M1) {
    return {f, M1};
}
