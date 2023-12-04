#pragma once
#include "../common/listnd.hpp"
#include "../macros.hpp"

// 引数　：数列Aと値の種類数M
// 戻り値：nxt[i][c] := 位置iから見て、値cが次回出現するindex
vvi get_next_indices(const vector<int> &A, int M) {
    int N = A.size();
    auto nxt = listnd(N + 1, M, -1);
    rep(i, N - 1, 0, -1) {
        rep(c, M) {
            if (c == A[i]) {
                nxt[i - 1][c] = i;
            } else {
                nxt[i - 1][c] = nxt[i][c];
            }
        }
    }
    return nxt;
}
