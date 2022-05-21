#include "../base.hpp"
#include "UnionFindUndo.hpp"

// 参考：https://ei1333.github.io/library/other/offline-dynamic-connectivity.cpp
// 　　　https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html
// オフラインダイコネ
struct OfflineDynamicConnectivity {
    using edge = pair< int, int >;

    UnionFindUndo uf;
    int V, Q, segsz;
    vector< vector< edge > > seg;
    // 連結成分数
    int comp;

    vector< pair< pair< int, int >, edge > > pend;
    map< edge, int > cnt, appear;

    // 頂点数V、Q個のクエリで初期化
    // (このQ個には、辺の追加・削除・回答クエリ全てが含まれる。クエリ数と言うより経過時間の最大)
    OfflineDynamicConnectivity(int V, int Q) : uf(V), V(V), Q(Q), comp(V) {
        segsz = 1;
        while (segsz < Q) segsz <<= 1;
        seg.resize(2 * segsz - 1);
    }

    // 時刻idxに辺(s,t)を追加
    void insert(int idx, int s, int t) {
        auto e = minmax(s, t);
        if (cnt[e]++ == 0) appear[e] = idx;
    }

    // 時刻idxに辺(s,t)を削除
    void erase(int idx, int s, int t) {
        auto e = minmax(s, t);
        if (--cnt[e] == 0) pend.emplace_back(make_pair(appear[e], idx), e);
    }

    void add(int a, int b, const edge &e, int k, int l, int r) {
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            seg[k].emplace_back(e);
            return;
        }
        add(a, b, e, 2 * k + 1, l, (l + r) >> 1);
        add(a, b, e, 2 * k + 2, (l + r) >> 1, r);
    }

    void add(int a, int b, const edge &e) {
        add(a, b, e, 0, 0, segsz);
    }

    // クエリを全て与えた後に呼び出す
    void build() {
        for (auto &p : cnt) {
            if (p.second > 0) pend.emplace_back(make_pair(appear[p.first], Q), p.first);
        }
        for (auto &s : pend) {
            add(s.first.first, s.first.second, s.second);
        }
    }

    // build()実行後に呼び出す、各i(0<=i<Q)についてf(i)が呼び出される
    template<typename F>
    void run(const F &f, int k = 0) {
        int add = 0;
        for (auto &e : seg[k]) {
            add += uf.merge(e.first, e.second);
        }
        comp -= add;
        if (k < segsz - 1) {
            run(f, 2 * k + 1);
            run(f, 2 * k + 2);
        } else if (k - (segsz - 1) < Q) {
            int query_index = k - (segsz - 1);
            f(query_index);
        }
        for (auto &e : seg[k]) {
            uf.undo();
        }
        comp += add;
    }
};
