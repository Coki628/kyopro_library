#pragma once
#include "../macros.hpp"

// 重複組み合わせ全列挙
template<typename T>
vv<T> combinations_with_replacement(const vector<T> &A, int N) {
    int M = A.size();
    vv<T> res;
    auto rec = [&](auto &&f, vector<T> &cur, ll x, ll n) -> void {
        if (n == N) {
            res.pb(cur);
            return;
        }
        rep(i, x, M) {
            cur.pb(A[i]);
            f(f, cur, i, n + 1);
            cur.pop_back();
        }
    };
    vector<T> cur;
    rec(rec, cur, 0, 0);
    return res;
}
