#include "../base.hpp"

// 参考：https://ei1333.github.io/library/structure/others/persistent-array.cpp
// 永続配列
template< typename T, int LOG >
struct PersistentArray {
    struct Node {
        T data;
        Node *child[1 << LOG] = {};

        Node() {}

        Node(const T &data) : data(data) {}
    };

    Node *root;

    PersistentArray() : root(nullptr) {}

    T get(Node *t, int k) {
        if (k == 0) return t->data;
        return get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
    }

    T get(const int &k) {
        return get(root, k);
    }

    pair< Node *, T * > mutable_get(Node *t, int k) {
        t = t ? new Node(*t) : new Node();
        if (k == 0) return {t, &t->data};
        auto p = mutable_get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
        t->child[k & ((1 << LOG) - 1)] = p.first;
        return {t, p.second};
    }

    T *mutable_get(const int &k) {
        auto ret = mutable_get(root, k);
        root = ret.first;
        return ret.second;
    }

    Node *build(Node *t, const T &data, int k) {
        if (!t) t = new Node();
        if (k == 0) {
            t->data = data;
            return t;
        }
        auto p = build(t->child[k & ((1 << LOG) - 1)], data, k >> LOG);
        t->child[k & ((1 << LOG) - 1)] = p;
        return t;
    }

    void build(const vector< T > &v) {
        root = nullptr;
        for (int i = 0; i < v.size(); i++) {
            root = build(root, v[i], i);
        }
    }
};

// 参考：https://ei1333.github.io/library/structure/union-find/persistent-union-find.cpp
// 永続UF
struct PersistentUnionFind {
    PersistentArray< int, 3 > data;

    PersistentUnionFind() {}

    PersistentUnionFind(int sz) {
        data.build(vector< int >(sz, -1));
    }

    int find(int k) {
        int p = data.get(k);
        return p >= 0 ? find(p) : k;
    }

    int size(int k) {
        return (-data.get(find(k)));
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        auto u = data.get(x);
        auto v = data.get(y);

        if (u < v) {
            auto a = data.mutable_get(x);
            *a += v;
            auto b = data.mutable_get(y);
            *b = x;
        } else {
            auto a = data.mutable_get(y);
            *a += u;
            auto b = data.mutable_get(x);
            *b = y;
        }
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
