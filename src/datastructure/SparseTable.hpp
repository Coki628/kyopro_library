#pragma once
#include "../macros.hpp"

// スパーステーブル：構築にO(NlogN)、区間取得にO(1)
template<typename T, typename F>
struct SparseTable {
    const F f;
    const T e;
    vv<T> dat;
    vector<int> height;

    SparseTable(const F f, const T e) : f(f), e(e) {}

    SparseTable(const vector<T> &A, const F f, const T e) : f(f), e(e) {
        build(A);
    }

    void build(const vector<T> &A) {
        int N = A.size();

        int h = 0;
        while ((1 << h) <= N) {
            h++;
        }
        dat.resize(h);
        rep(i, h) dat[i].resize(1 << h);
        height.resize(N + 1);

        rep(i, 2, N + 1) {
            height[i] = height[i >> 1] + 1;
        }
        rep(i, N) {
            dat[0][i] = A[i];
        }
        rep(i, 1, h) {
            for (int j = 0; j < N; j++) {
                dat[i][j] =
                    f(dat[i - 1][j],
                      dat[i - 1][min(j + (1 << (i - 1)), N - 1)]);
            }
        }
    }

    // 区間[l,r)でのmin,maxを取得
    T query(int l, int r) {
        if (l >= r) return e;
        int a = height[r - l];
        return f(dat[a][l], dat[a][r - (1 << a)]);
    }

    // 区間[l,r]で左から最初にxに対して比較の条件を満たすような値が出現する位置
    template<typename G>
    int bisearch_fore(int l, int r, T x, const G &compare) {
        int ok = r + 1;
        int ng = l - 1;
        while (ng + 1 < ok) {
            int mid = (ok + ng) / 2;
            if (compare(query(l, mid + 1), x)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (ok != r + 1) {
            return ok;
        } else {
            return -1;
        }
    }

    // 区間[l,r]で右から最初にxに対して比較の条件を満たすような値が出現する位置
    template<typename G>
    int bisearch_back(int l, int r, T x, const G &compare) {
        int ok = l - 1;
        int ng = r + 1;
        while (ok + 1 < ng) {
            int mid = (ok + ng) / 2;
            if (compare(query(mid, r + 1), x)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (ok != l - 1) {
            return ok;
        } else {
            return -1;
        }
    }
    // 使用例
    // stmx.bisearch_back(l, r, x, greater<ll>());
};

template<typename T, typename F>
SparseTable<T, F> get_sparse_table(vector<T> &A, const F &f, const T &e) {
    return {A, f, e};
}

template<typename T, typename F>
SparseTable<T, F> get_sparse_table(const F &f, const T &e) {
    return {f, e};
}
