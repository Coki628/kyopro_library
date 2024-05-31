#pragma once
#include "../macros.hpp"
#include "ModTools.hpp"
#include "stirling.hpp"

// ベル数(玉区別あり、箱区別なし、制限なし) ※未Verify
ll bell(int N, int K) {
    ll ans = 0;
    for (int i = 0; i < K + 1; i++) {
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
    for (int i = 0; i < K + 1; i++) {
        prev[i] = (Mint)1 / mt.fact[i];
    }
    // 累積和
    for (int i = 1; i < K + 1; i++) {
        prev[i] += prev[i - 1];
    }

    Mint ans = 0;
    for (int i = 0; i < K + 1; i++) {
        ans += (Mint)pow(i, N, MOD) / mt.fact[i] * prev[K - i];
    }
    return ans;
}
