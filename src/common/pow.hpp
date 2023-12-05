#pragma once
#include "../macros.hpp"

ll pow(ll x, ll n) {
    ll res = 1;
    rep(_, n) res *= x;
    return res;
}

ll pow(int x, ll n) {
    return pow((ll)x, n);
}

ll pow(ll x, int n) {
    return pow(x, (ll)n);
}

ll pow(int x, int n) {
    return pow((ll)x, (ll)n);
}

template<typename T1, typename T2, typename M>
T1 pow(T1 x, T2 n, M mod) {
    x %= mod;
    T1 res = 1;
    while (n > 0) {
        if (n & 1) {
            assert(not mul_overflow(res, x));
            res = (res * x) % mod;
        }
        assert(not mul_overflow(x, x));
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}
