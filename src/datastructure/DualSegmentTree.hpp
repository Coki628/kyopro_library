#pragma once
#include "../macros.hpp"

// 双対セグメント木
// 参考：https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree
// 　　　https://hackmd.io/@tatyam-prime/DualSegmentTree
// 　　　https://atcoder.jp/contests/abc342/submissions/50580301
// 　　　https://atcoder.jp/contests/abc342/submissions/50480272
// 　　　https://atcoder.jp/contests/abc332/submissions/48389709
// 　　　https://atcoder.jp/contests/abc332/submissions/48392267
// 今まで遅延セグ木で困らなかったから作らなかったけど、
// いよいよ必要な場面に遭遇したので作った。(abc342_g)
// 基本的には聞いてた通り、遅延セグ木の作用素側だけ版なんだけど、
// より具体的に言えば、作用素を何も伝搬させずにそのまま持っていて、
// 1点取得の時に都度、葉から親側に取りに行く、みたいな感じだった。
// で、それは可換のものを乗せる時の話で、非可換のものを乗せる時は実装がかなり変わる。
// 下から上に取りに行く方法だと、演算を当てる順序が変わってしまう。
// なので非可換の場合は、遅延セグ木みたいに先に下に伝搬させておく。
// ライブラリの実装としては、可換かどうかのフラグcommuteを用意して、
// 初期化の時点でどっちの振る舞いにするか決められるようにした。
// 使い方
// ・基本は区間更新と1点取得だけできる遅延セグ木と思っていい。
// ・なんとなくイメージで1点取得はO(1)でできる気がしてたんだけど、O(logN)かかる。
// ・逆に1点更新はO(1)でOK。なので基本的には初期化が要らなくて、
// 　初期状態は直接updateで全箇所1点更新するでもいい。
// 　一応、配列渡すコンストラクタ残してあるけどね。だいたいその方が楽だし。
// ・非可換のものを乗せる時には初期化時にcommute=falseを渡す。
template<typename G, typename H, typename Monoid, typename OperatorMonoid>
struct DualSegmentTree {
    int sz, height, n;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;
    // 可換かどうか
    bool commute;

    DualSegmentTree(
        int n, const G g, const H h, const Monoid &M1,
        const OperatorMonoid &OM0, bool commute = true
    )
        : n(n),
          g(g),
          h(h),
          M1(M1),
          OM0(OM0),
          commute(commute) {
        sz = 1;
        height = 0;
        while (sz < n) sz <<= 1, height++;
        data.assign(n, M1);
        lazy.assign(2 * sz, OM0);
    }

    DualSegmentTree(
        const vector<Monoid> &A, const G g, const H h,
        const Monoid &M1, const OperatorMonoid &OM0, bool commute = true
    )
        : g(g),
          h(h),
          M1(M1),
          OM0(OM0),
          commute(commute) {
        build(A);
    }

    // 取得側の値、特にbuildは不要
    void set(int k, const Monoid &x) {
        data[k] = x;
    }

    void build(const vector<Monoid> &A) {
        n = A.size();
        sz = 1;
        height = 0;
        while (sz < n) sz <<= 1, height++;
        data = A;
        lazy.assign(2 * sz, OM0);
    }

    inline void propagate(int k) {
        if (lazy[k] == OM0) return;
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
        lazy[k] = OM0;
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }

    // 区間更新：O(logN)
    void update(int a, int b, const OperatorMonoid &x) {
        if (a >= b) return;
        a += sz;
        b += sz - 1;
        // 非可換なら更新を下に伝搬させる
        if (not commute) {
            thrust(a);
            thrust(b);
        }
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                lazy[l] = h(lazy[l], x);
                ++l;
            }
            if (r & 1) {
                --r;
                lazy[r] = h(lazy[r], x);
            }
        }
    }

    Monoid operator[](const int &k) {
        return this->get(k);
    }

    // 1点取得：O(logN)
    Monoid get(int k) {
        assert(0 <= k and k < n);
        Monoid res = data[k];
        k += sz;
        if (commute) {
            // 可換なら下から上に更新情報を取りに行く
            for (int i = k; i > 0; i >>= 1) {
                res = g(res, lazy[i]);
            }
        } else {
            // 非可換なら上から下に伝搬させておく
            thrust(k);
            res = g(res, lazy[k]);
        }
        return res;
    }

    int size() {
        return n;
    }

    // 1点更新：O(1)
    void update(int i, const OperatorMonoid &x) {
        // update(i, i + 1, x);
        lazy[i + sz] = h(lazy[i + sz], x);
    }
};

template<typename G, typename H, typename T, typename E>
DualSegmentTree<G, H, T, E> get_dual_segment_tree(
    int N, const G &g, const H &h, const T &ti, const E &ei, bool commute = true
) {
    return {N, g, h, ti, ei, commute};
}

template<typename G, typename H, typename T, typename E>
DualSegmentTree<G, H, T, E> get_dual_segment_tree(
    const vector<T> &A, const G &g, const H &h, const T &ti,
    const E &ei, bool commute = true
) {
    return {A, g, h, ti, ei, commute};
}

template<typename G, typename H, typename T, typename E>
ostream &operator<<(ostream &os, DualSegmentTree<G, H, T, E> &seg) {
    rep(i, seg.size()) {
        os << seg[i];
        if (i != seg.size() - 1) {
            os << ' ';
        }
    }
    return os;
}
