#pragma once
#include "../macros.hpp"
#include "BIT.hpp"

// 抽象化BIT
// ・xorくらいしか使い道が思いつかず長らく着手せず放置だったけど、
// 　ロリハ用のでかMOD整数を乗せれるかもということで作った。
template<typename T, typename F, typename G>
class AbstractBIT : public BIT<T> {
private:
    const F f;
    const G g;

    // テンプレート引数があると、親のメンバ変数が明示しないと見えないのだそう
    // see: https://teratail.com/questions/179231
    int n = BIT<T>::n;
    vector<T> dat = BIT<T>::dat;

public:
    AbstractBIT() = default;

    explicit AbstractBIT(int n, F f, G g) : BIT<T>(n), f(f), g(g) {}

    explicit AbstractBIT(const vector<T> &v, F f, G g)
        : AbstractBIT((int)v.size(), f, g) {
        build(v);
    }

    void build(const vector<T> &v) override {
        assert(n == (int)v.size());
        for (int i = 1; i <= n; i++) {
            dat[i] = v[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) dat[j] = f(dat[j], dat[i]);
        }
    }

    // [0, r)を合計する
    T sum(int r) override {
        T s = T();
        for (; r > 0; r -= r & -r) {
            s = f(s, dat[r]);
        }
        return s;
    }

    void add(int k, const T &x) override {
        for (++k; k <= n; k += k & -k) {
            dat[k] = f(dat[k], x);
        }
    }

    // 区間和の取得 [l, r)
    T query(int l, int r) {
        if (l >= r) return T();
        return g(sum(r), sum(l));
    }

    void update(int i, T x) {
        add(i, g(x, this->get(i)));
    }

    T get(int i) override {
        // return query(i, i + 1);
        // BITの高速な1点取得
        // see: https://twitter.com/KakurenboUni/status/1643832177690550273
        T s = dat[i + 1];
        if (i & 1) {
            int j = i;
            i++;
            i -= i & -i;
            for (; j > i; j -= j & -j) {
                s = g(s, dat[j]);
            }
        }
        return s;
    }
};
