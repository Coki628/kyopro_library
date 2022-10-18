#pragma once
#include "../base.hpp"

// 参考：https://ei1333.github.io/library/structure/others/persistent-array.cpp
// 　　　https://qiita.com/hotman78/items/9c643feae1de087e6fc5#%E3%81%9D%E3%82%82%E3%81%9D%E3%82%82%E9%85%8D%E5%88%97%E3%81%A8%E3%81%AF
// 永続配列
// 特徴
// ・元の要素数がNある配列でもコピーにlog(N)くらいしかかからず済む。
// ・基本的にgetとupdateを使って、普通の配列と同じように操作する。
// ・mutable_getでも値が取れるが、参照も全部これやるとnode増えすぎてMLEしがちっぽい。
// ・何分木にするかだが、hotmanさんによると20分木くらいがいいらしい。
// 　がしかし40万クエリの問題に永続UFで2,4,8,16を試しに使ったところ、
// 　速度は(4,8,16で大差ないものの)8分木が一番速くて、メモリは(4,8で大差ないけど)4分木が一番軽かった。
// 　2分木になると急に色々悪くなった。結局、うしさんが初期設定にしてたLOG=3が一番妥当っぽい？
// ・特定の時点での状態の記録/復元にはポインタを用いる。
// 　なるべく直感的に操作できるようにメソッドを生やしておいた。

template< typename T, int LOG >
struct PersistentArray {
public:
    struct Node {
        T data;
        // 2^LOG分木で構築する
        Node *child[1 << LOG] = {};

        Node() {}

        Node(const T &data) : data(data) {}
    };

private:
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

    T get(Node *t, int k) {
        if (k == 0) return t->data;
        return get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
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

public:
    PersistentArray() : root(nullptr) {}

    Node *root;

    void build(const vector< T > &v) {
        root = nullptr;
        for (int i = 0; i < v.size(); i++) {
            root = build(root, v[i], i);
        }
    }

    T get(const int &k) {
        return get(root, k);
    }

    T operator[](int i) {
        return get(i);
    }

    void update(const int &k, const T &v) {
        *mutable_get(k) = v;
    }

    // 現在の配列の状態を記録する
    Node *save() {
        return root;
    }

    // ポインタp時点の配列の状態を復元する
    void load(Node *p) {
        root = p;
    }
};
