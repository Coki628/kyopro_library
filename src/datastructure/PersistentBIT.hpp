#include "../base.hpp"
#include "BIT.hpp"

// 参考：https://suisen-cp.github.io/cp-library-cpp/library/datastructure/fenwick_tree/persistent_fenwick_tree.hpp
// 永続BIT
// ・BITの歯抜けの2分木でセグ木と同じようにやるのは難しいんじゃないかと思ったけど、
// 　suisenさんがしっかり作っていた。in-orderに並べるとうまくいくとか。
// 　コアの部分を手持ちのものに適用させて、一応verifyはできた。(abc253_f)
// 　なんだけど、セグ木と比べてあんま速くなってはいなくて、
// 　なんか余計なnode生成とかやっちゃってるかもしれない。

template<typename T>
class PersistentBIT : public BIT<T> {
public:
    struct Node {
        T data;
        Node *l, *r;

        Node(const T &data) : data(data), l(nullptr), r(nullptr) {}
        Node(Node* node) : data(node->data), l(node->l), r(node->r) {}
    };
private:
    int n, sz;
    Node* root;
    vector<Node*> nodes;
public:
    PersistentBIT() =  default;

    explicit PersistentBIT(int n) : n(n) {
        sz = 1;
        while (sz < n) {
            sz <<= 1;
        }
        if (n == 0) sz = 0;
        nodes.resize(n+1);
        auto rec = [&](auto rec, int p, int id) -> Node* {
            if (p == 0) return nullptr;
            const int np = p >> 1;
            Node* res = new Node((T)0);
            res->l = rec(rec, np, id - np);
            if (id + 1 <= n) res->r = rec(rec, np, id + np);
            if (id <= n) {
                nodes[id] = res;
            }
            return res;
        };
        root = rec(rec, sz, sz);
    }

    explicit PersistentBIT(const vector<T> &v) : PersistentBIT((int)v.size()) {
        build(v);
    }

    void build(const vector<T> &v) override {
        assert(n == (int)v.size());
        for (int i = 1; i <= n; i++) {
            nodes[i]->data = v[i-1];
        }
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) {
                nodes[j]->data += nodes[i]->data;
            }
        }
    }

    T sum(int r) {
        T s = T();
        int p = sz;
        Node* cur = root;
        while (r > 0) {
            if (r & p) {
                r ^= p;
                s += cur->data;
                cur = cur->r;
            } else {
                cur = cur->l;
            }
            p >>= 1;
        }
        return s;
    }

    void add(int k, const T &x) override {
        k++;
        root = new Node(root);
        Node* cur = root;
        int p = sz;
        while (1) {
            if (k & p) {
                if (k ^= p) {
                    cur = cur->r = new Node(cur->r);
                } else {
                    cur->data += x;
                    break;
                }
            } else {
                cur->data += x;
                cur = cur->l = new Node(cur->l);
            }
            p >>= 1;
        }
    }

    Node* save() {
        return root;
    }

    void load(Node* p) {
        root = p;
    }
};
