#include "../macros.hpp"

// Binary Indexed Tree
template<typename T>
class BIT {
private:
    int n;
    vector<T> dat;

public:
    BIT() =  default;

    explicit BIT(int n) : n(n) {
        dat.assign(n+1, 0);
    }

    explicit BIT(const vector<T> &v) : BIT((int)v.size()) {
        build(v);
    }

    void build(const vector<T> &v) {
        assert(n == (int)v.size());
        for (int i = 1; i <= n; i++) {
            dat[i] = v[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) dat[j] += dat[i];
        }
    }

    // [0, r)を合計する
    T sum(int r) {
        T s = T();
        for (; r > 0; r -= r & -r) {
            s += dat[r];
        }
        return s;
    }

    void add(int k, const T &x) {
        for (++k; k <= n; k += k & -k) {
            dat[k] += x;
        }
    }

    // 区間和の取得 [l, r)
    T query(int l, int r) {
        return sum(r) - sum(l);
    }

    T get(int i) {
        return query(i, i+1);
    }

    void update(int i, T x) {
        add(i, x-get(i));
    }

    T operator[](int i) {
        return query(i, i+1);
    }

    void print() {
        rep(i, n) {
            cout << query(i, i+1);
            if (i == n-1) cout << endl;
            else cout << ' ';
        }
    }

    // 区間[l, r]を左から右に向かってx番目の値がある位置
    ll bisearch_fore(int l, int r, ll x) {
        if (l > r) return -1;
        ll l_sm = sum(l);
        int ok = r + 1;
        int ng = l - 1;
        while (ng+1 < ok) {
            int mid = (ok+ng) / 2;
            if (sum(mid+1) - l_sm >= x) {
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
        ll r_sm = sum(r+1);
        int ok = l - 1;
        int ng = r + 1;
        while (ok+1 < ng) {
            int mid = (ok+ng) / 2;
            if (r_sm - sum(mid) >= x) {
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

    // 参考：https://ei1333.github.io/library/structure/others/binary-indexed-tree.cpp
    // 区間[0,k]の総和がx以上となる最小のkを返す。数列が単調増加であることを要求する。
    // (logが1つなので、TL厳しい時はこちらを使う。)
    int lower_bound(T x) const {
        int i = 0;
        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {
            if (i + k <= n && dat[i+k] < x) {
                x -= dat[i+k];
                i += k;
            }
        }
        return i;
    }

    // 区間[0,k]の総和がxを上回る最小のkを返す。数列が単調増加であることを要求する。(未verify)
    int upper_bound(T x) const {
        int i = 0;
        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {
            if (i + k <= n && dat[i+k] <= x) {
                x -= dat[i+k];
                i += k;
            }
        }
        return i;
    }
};
