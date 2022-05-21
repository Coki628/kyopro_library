#pragma once
#include "../macros.hpp"

// 累積和
template<typename T>
struct Accumulate {
    vector<T> dat;
    int N;

    Accumulate(int N) : N(N) {
        dat.resize(N);
    }

    Accumulate(const vector<T> &A) : N(A.size()), dat(A) {
        build();
    }

    void set(int i, T a) {
        dat[i] = a;
    }

    void add(int i, T a) {
        dat[i] += a;
    }

    void build() {
        rep(i, N-1) {
            dat[i+1] += dat[i];
        }
        dat.insert(dat.begin(), 0);
    }

    virtual T query(int l, int r) {
        assert(0 <= l and l <= N and 0 <= r and r <= N);
        return dat[r]-dat[l];
    }

    T get(int i) {
        return query(i, i+1);
    }

    T operator[](int i) {
        return query(i, i+1);
    }

    // 区間[l, r]を左から右に向かってx番目の値がある位置
    ll bisearch_fore(int l, int r, ll x) {
        if (l > r) return -1;
        ll l_sm = query(0, l);
        int ok = r + 1;
        int ng = l - 1;
        while (ng+1 < ok) {
            int mid = (ok+ng) / 2;
            if (query(0, mid+1) - l_sm >= x) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (ok != r+1) {
            return ok;
        } else {
            return -1;
        }
    }

    // 区間[l, r]を右から左に向かってx番目の値がある位置
    ll bisearch_back(int l, int r, ll x) {
        if (l > r) return -1;
        ll r_sm = query(0, r+1);
        int ok = l - 1;
        int ng = r + 1;
        while (ok+1 < ng) {
            int mid = (ok+ng) / 2;
            if (r_sm - query(0, mid) >= x) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (ok != l-1) {
            return ok;
        } else {
            return -1;
        }
    }
};
