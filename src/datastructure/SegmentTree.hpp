#pragma once
#include "../base.hpp"

template<typename Monoid, typename F>
struct SegmentTree {

    int sz, n;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : n(n), f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    SegmentTree(const F f, const Monoid &M1) : f(f), M1(M1) {
    }

    SegmentTree(const vector<Monoid> &A, const F f, const Monoid &M1)
        : f(f),
          M1(M1) {
        build(A);
    }

    void resize(int n) {
        this->n = n;
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.resize(2 * sz, M1);
    }

    void clear() {
        seg.clear();
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k], seg[2 * k + 1]);
        }
    }

    void build(const vector<Monoid> &A) {
        n = A.size();
        resize(n);
        for (int i = 0; i < n; i++) {
            set(i, A[i]);
        }
        build();
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }

    Monoid all() {
        return seg[1];
    }

    int size() {
        return n;
    }

    template<typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while (a < sz) {
            Monoid nxt =
                type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    // 範囲[a,N)でcheckの条件を満たすような最小位置を返す(なければ-1)
    template<typename C>
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    // 範囲[0,b)でcheckの条件を満たすような最大位置を返す(なければ-1)
    template<typename C>
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

template<typename Monoid, typename F>
SegmentTree<Monoid, F> get_segment_tree(int N, const F &f, const Monoid &M1) {
    return {N, f, M1};
}

template<typename Monoid, typename F>
SegmentTree<Monoid, F> get_segment_tree(const F &f, const Monoid &M1) {
    return {f, M1};
}

template<typename Monoid, typename F>
SegmentTree<Monoid, F> get_segment_tree(
    const vector<Monoid> &A,
    const F &f,
    const Monoid &M1
) {
    return {A, f, M1};
}

template<typename Monoid, typename F>
ostream &operator<<(ostream &os, SegmentTree<Monoid, F> &seg) {
    for (int i = 0; i < seg.size(); i++) {
        os << seg[i];
        if (i != seg.size() - 1) {
            os << ' ';
        }
    }
    return os;
}
