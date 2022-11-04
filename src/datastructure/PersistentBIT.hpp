#include "../base.hpp"
#include "BIT.hpp"
#include "PersistentArray.hpp"

// 永続BIT
template<typename T>
class PersistentBIT : public BIT<T> {
private:
    int n;

public:
    PersistentArray<T, 3> dat;

    PersistentBIT() =  default;

    explicit PersistentBIT(int n) : n(n) {
        dat.build(vector<T>(n+1, 0));
    }

    explicit PersistentBIT(const vector<T> &v) : PersistentBIT((int)v.size()) {
        build(v);
    }

    void build(const vector<T> &v) override {
        assert(n == (int)v.size());
        for (int i = 1; i <= n; i++) {
            dat.update(i, v[i-1]);
        }
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) {
                dat.update(j, dat[j]+dat[i]);
            }
        }
    }

    T sum(int r) {
        T s = T();
        for (; r > 0; r -= r & -r) {
            s += dat[r];
        }
        return s;
    }

    void add(int k, const T &x) override {
        for (++k; k <= n; k += k & -k) {
            dat.update(k, dat[k]+x);
        }
    }

    int lower_bound(T x) {
        int i = 0;
        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {
            if (i + k <= n && dat[i+k] < x) {
                x -= dat[i+k];
                i += k;
            }
        }
        return i;
    }

    int upper_bound(T x) {
        int i = 0;
        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {
            if (i + k <= n && dat[i+k] <= x) {
                x -= dat[i+k];
                i += k;
            }
        }
        return i;
    }

    auto save() {
        return dat.save();
    }

    void load(auto p) {
        dat.load(p);
    }
};
