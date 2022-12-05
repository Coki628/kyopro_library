#include "../macros.hpp"

// 三分探索(整数) [lo,hi)
template<typename T=ll, typename F>
pair<ll, T> trisearch_min(ll lo, ll hi, const F &func, ll offset=1) {
    ll m1 = lo, l = lo;
    ll m2 = hi, r = hi;
    while (lo+2 < hi) {
        m1 = (lo*2+hi) / 3;
        m2 = (lo+hi*2) / 3;
        T res1 = func(m1);
        T res2 = func(m2);
        if (res1 <= res2) {
            hi = m2;
        } else {
            lo = m1;
        }
    }
    T mn = numeric_limits<T>::max();
    pair<ll, T> res;
    rep(i, max(m1-offset, l), min(m2+offset, r)) {
        T val = func(i);
        if (val < mn) {
            mn = val;
            res = {i, val};
        }
    }
    return res;
}

// 三分探索(整数) [lo,hi)
template<typename T=ll, typename F>
pair<ll, T> trisearch_max(ll lo, ll hi, const F &func, ll offset=1) {
    ll m1 = lo, l = lo;
    ll m2 = hi, r = hi;
    while (lo+2 < hi) {
        m1 = (lo*2+hi) / 3;
        m2 = (lo+hi*2) / 3;
        ll res1 = func(m1);
        ll res2 = func(m2);
        if (res1 >= res2) {
            hi = m2;
        } else {
            lo = m1;
        }
    }
    T mx = numeric_limits<T>::min();
    pair<ll, T> res;
    rep(i, max(m1-offset, l), min(m2+offset, r)) {
        T val = func(i);
        if (val > mx) {
            mx = val;
            res = {i, val};
        }
    }
    return res;
}
