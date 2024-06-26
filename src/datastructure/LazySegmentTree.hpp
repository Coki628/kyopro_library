#pragma once
#include "../macros.hpp"

// 遅延評価セグメント木
// 参考：https://ei1333.github.io/library/structure/segment-tree/lazy-segment-tree.cpp
template<typename F, typename G, typename H, typename Monoid, typename OperatorMonoid>
struct LazySegmentTree {
    int sz, height, n;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    LazySegmentTree(
        int n, const F f, const G g, const H h, const Monoid &M1,
        const OperatorMonoid &OM0
    )
        : n(n),
          f(f),
          g(g),
          h(h),
          M1(M1),
          OM0(OM0) {
        sz = 1;
        height = 0;
        while (sz < n) sz <<= 1, height++;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    LazySegmentTree(
        const F f, const G g, const H h, const Monoid &M1,
        const OperatorMonoid &OM0
    )
        : f(f),
          g(g),
          h(h),
          M1(M1),
          OM0(OM0) {
    }

    LazySegmentTree(
        const vector<Monoid> &A, const F f, const G g, const H h,
        const Monoid &M1, const OperatorMonoid &OM0
    )
        : f(f),
          g(g),
          h(h),
          M1(M1),
          OM0(OM0) {
        build(A);
    }

    void set(int k, const Monoid &x) {
        data[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }

    void build(const vector<Monoid> &A) {
        n = A.size();
        sz = 1;
        height = 0;
        while (sz < n) sz <<= 1, height++;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
        for (int i = 0; i < n; i++) set(i, A[i]);
        build();
    }

    inline void propagate(int k) {
        if (lazy[k] == OM0) return;
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
        data[k] = apply(k);
        lazy[k] = OM0;
    }

    inline Monoid apply(int k) {
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
    }

    inline void recalc(int k) {
        while (k >>= 1) data[k] = f(apply(2 * k + 0), apply(2 * k + 1));
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid &x) {
        if (a >= b) return;
        thrust(a += sz);
        thrust(b += sz - 1);
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
        recalc(a);
        recalc(b);
    }

    Monoid query(int a, int b) {
        if (a >= b) return M1;
        thrust(a += sz);
        thrust(b += sz - 1);
        Monoid L = M1, R = M1;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, apply(l++));
            if (r & 1) R = f(apply(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) {
        return this->get(k);
    }

    Monoid get(int k) {
        assert(0 <= k and k < n);
        thrust(k += sz);
        return apply(k);
        // return query(k, k + 1);
    }

    Monoid all() {
        return apply(1);
    }

    int size() {
        return n;
    }

    void update(int i, const OperatorMonoid &x) {
        update(i, i + 1, x);
    }

    template<typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while (a < sz) {
            propagate(a);
            Monoid nxt =
                type ? f(apply(2 * a + type), M) : f(M, apply(2 * a + type));
            if (check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    // 区間[a,N)でcheckの条件を満たすような[a,r)の最小でのr-1を返す(なければ-1)
    template<typename C>
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, apply(1)))) return find_subtree(1, check, L, false);
            return -1;
        }
        thrust(a + sz);
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, apply(a));
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    // 区間[0,b)でcheckの条件を満たすような[l,b)の最大でのlを返す(なければ-1)
    template<typename C>
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(apply(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(b + sz - 1);
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(apply(--b), R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

template<typename F, typename G, typename H, typename T, typename E>
LazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(
    const F &f, const G &g, const H &h, const T &ti, const E &ei
) {
    return {f, g, h, ti, ei};
}

template<typename F, typename G, typename H, typename T, typename E>
LazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(
    int N, const F &f, const G &g, const H &h, const T &ti, const E &ei
) {
    return {N, f, g, h, ti, ei};
}

template<typename F, typename G, typename H, typename T, typename E>
LazySegmentTree<F, G, H, T, E> get_lazy_segment_tree(
    const vector<T> &A, const F &f, const G &g, const H &h, const T &ti,
    const E &ei
) {
    return {A, f, g, h, ti, ei};
}

template<typename F, typename G, typename H, typename T, typename E>
ostream &operator<<(ostream &os, LazySegmentTree<F, G, H, T, E> &seg) {
    for (int i = 0; i < seg.size(); i++) {
        os << seg[i];
        if (i != seg.size() - 1) {
            os << ' ';
        }
    }
    return os;
}
