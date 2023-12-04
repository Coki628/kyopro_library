#pragma once
#include "../common/listnd.hpp"
#include "../macros.hpp"

// 行列の積
template<typename T>
vv<T> mat_dot(const vv<T> &A, const vv<T> &B) {
    int n1 = A.size();
    int n2 = A[0].size();
    int m2 = B[0].size();
    auto res = listnd(n1, m2, (T)0);
    rep(i, n1) {
        rep(k, n2) {
            if (A[i][k] == 0) continue;
            rep(j, m2) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}

template<typename T, size_t SZ1, size_t SZ2, size_t SZ3>
array<array<T, SZ3>, SZ1> mat_dot(
    const array<array<T, SZ2>, SZ1> &A, const array<array<T, SZ3>, SZ2> &B
) {
    // グローバルでないarrayは初期化されないので{}で初期化(0埋め)する
    array<array<T, SZ3>, SZ1> res{};
    rep(i, SZ1) {
        rep(k, SZ2) {
            if (A[i][k] == 0) continue;
            rep(j, SZ3) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}
