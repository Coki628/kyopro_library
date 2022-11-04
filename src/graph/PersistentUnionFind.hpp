#include "../base.hpp"
#include "../datastructure/PersistentArray.hpp"

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
            data.update(x, u+v);
            data.update(y, x);
        } else {
            data.update(y, u+v);
            data.update(x, y);
        }
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    decltype(data)::Node* get_root_node() {
        return data.root;
    }

    void set_root_node(decltype(data)::Node* np) {
        data.root = np;
    }
};
