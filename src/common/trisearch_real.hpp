#pragma once
#include "../macros.hpp"

// 三分探索(実数)
template<typename F>
pair<ld, ld> trisearch_min(ld lo, ld hi, const F &func, ll times) {
    ld m1 = lo;
    ld m2 = hi;
    rep(_, times) {
        m1 = (lo * 2 + hi) / 3;
        m2 = (lo + hi * 2) / 3;
        ld res1 = func(m1);
        ld res2 = func(m2);
        if (res1 <= res2) {
            hi = m2;
        } else {
            lo = m1;
        }
    }
    return {m1, func(m1)};
}

// 三分探索(実数)
template<typename F>
pair<ld, ld> trisearch_max(ld lo, ld hi, const F &func, ll times) {
    ld m1 = lo;
    ld m2 = hi;
    rep(_, times) {
        m1 = (lo * 2 + hi) / 3;
        m2 = (lo + hi * 2) / 3;
        ld res1 = func(m1);
        ld res2 = func(m2);
        if (res1 >= res2) {
            hi = m2;
        } else {
            lo = m1;
        }
    }
    return {m1, func(m1)};
}
