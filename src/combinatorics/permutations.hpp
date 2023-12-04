#pragma once
#include "../macros.hpp"

// 順列全列挙
template<typename T>
vv<T> permutations(const vector<T> &A, int N = -1) {
    if (N == -1) N = A.size();
    int M = A.size();
    assert(N <= M);
    vv<T> comb;
    rep(bit, 1 << M) {
        if (popcount(bit) != N) continue;
        vector<T> res;
        rep(i, M) {
            if (bit >> i & 1) {
                res.pb(A[i]);
            }
        }
        comb.pb(res);
    }

    vv<T> res;
    for (auto &perm : comb) {
        sort(ALL(perm));
        do {
            res.pb(perm);
        } while (next_permutation(ALL(perm)));
    }
    return res;
}
