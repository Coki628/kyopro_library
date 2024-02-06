#pragma once
#include "../macros.hpp"
#include "numbers/FastPrimeFactorization.hpp"
#include "randrange.hpp"

// 範囲[l,r)からランダムに選ばれた素数を返す
ll rand_prime(ll l, ll r) {
    ll p = 1;
    while (not FastPrimeFactorization::is_prime(p)) {
        p = randrange(l, r);
    }
    return p;
}
