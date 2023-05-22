#include "../base.hpp"
#include "UnionFindUndo.hpp"
#include "common/HashMap.hpp"

// 参考：https://ei1333.github.io/library/other/offline-dynamic-connectivity.cpp
// 　　　https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html
// 　　　https://nyaannyaan.github.io/library/graph/offline-dynamic-connectivity.hpp
// オフラインダイコネ
struct OfflineDynamicConnectivity {
    using edge = pair< int, int >;

private:
    int V, Q, segsz;
    vector< vector< edge > > seg;
    vector< pair< pair< int, int >, edge > > pend;
    HashMap< edge, int > cnt, appear;

    void add(int l, int r, const edge &e) {
        int L = l + segsz;
        int R = r + segsz;
        while (L < R) {
            if (L & 1) seg[L++].push_back(e);
            if (R & 1) seg[--R].push_back(e);
            L >>= 1, R >>= 1;
        }
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

    template<typename F>
    void _run(const F &f, int k, int l, int r) {
        if (Q <= l) return;
        int tmp = 0, tmp2 = 0;
        for (auto &e : seg[k]) {
            if (uf.size(e.first) == 1) {
                tmp2++;
            }
            if (uf.size(e.second) == 1) {
                tmp2++;
            }
            tmp += uf.merge(e.first, e.second);
        }
        comp -= tmp;
        single -= tmp2;
        if (l + 1 == r) {
            f(l);
        } else {
            _run(f, 2 * k + 0, l, (l+r) >> 1);
            _run(f, 2 * k + 1, (l+r) >> 1, r);
        }
        for (auto &e : seg[k]) {
            uf.undo();
        }
        comp += tmp;
        single += tmp2;
    }

public:
    UnionFindUndo uf;
    // 連結成分数
    int comp;
    // 要素数1の連結成分数
    int single;

    // 頂点数V、Q個のクエリで初期化
    // (このQ個には、辺の追加・削除・回答クエリ全てが含まれる。クエリ数と言うより経過時間の最大。
    //  なお、次の回答クエリが来るまでの辺の追加削除は同時刻にまとめてOK。)
    OfflineDynamicConnectivity(int V, int Q) : uf(V), V(V), Q(Q), comp(V), single(V) {
        segsz = 1;
        while (segsz < Q) segsz <<= 1;
        seg.resize(2 * segsz);
    }

    // 一応作ったんだけど、これやっても速くならなかった。
    void reserve(int n) {
        cnt.reserve(n);
        appear.reserve(n);
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

    // build()実行後に動作、各i(0<=i<Q)についてf(i)が呼び出される
    // 時刻iの操作が終わった後の状態でfが実行される
    template<typename F>
    void run(const F &f) {
        build();
        _run(f, 1, 0, segsz);
    }
};
