#pragma once
#include "../macros.hpp"
#include "stirling.hpp"
#include "ModTools.hpp"

// ベル数(玉区別あり、箱区別なし、制限なし) ※未Verify
ll bell(int N, int K) {
    ll ans = 0;
    rep(i, K + 1) {
        ans += stirling<ll>(N, i)[N][i];
    }
    return ans;
}

// ベル数(玉区別あり、箱区別なし、制限なし) ※未Verify
template<typename Mint>
Mint bell(int N, int K) {
    ModTools<Mint> mt(max(N, K));

    // 前計算しておく
    vector<Mint> prev(K + 1);
    rep(i, K + 1) {
        prev[i] = (Mint)1 / mt.fact[i];
    }
    // 累積和
    rep(i, 1, K + 1) {
        prev[i] += prev[i - 1];
    }

    mint ans = 0;
    rep(i, K + 1) {
        ans += (Mint)pow(i, N, MOD) / mt.fact[i] * prev[K - i];
    }
    return ans;
}
