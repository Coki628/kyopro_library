#pragma once
#include "../macros.hpp"
#include "mat_dot.hpp"

// 行列累乗
// ・DP遷移との対応はABC129fあたりが見やすそう。
template<typename T>
struct MatPow {
    MatPow() {}

    vv<T> mat_pow(vv<T> mat, ll k) {
        int n = mat.size();
        auto res = list2d(n, n, (T)0);
        rep(i, n) {
            res[i][i] = 1;
        }
        while (k > 0) {
            if (k & 1) {
                res = mat_dot(res, mat);
            }
            mat = mat_dot(mat, mat);
            k >>= 1;
        }
        return res;
    }

    template<size_t SZ>
    array<array<T, SZ>, SZ> mat_pow(array<array<T, SZ>, SZ> mat, ll k) {
        int n = mat.size();
        array<array<T, SZ>, SZ> res = {};
        rep(i, n) {
            res[i][i] = 1;
        }
        while (k > 0) {
            if (k & 1) {
                res = mat_dot(res, mat);
            }
            mat = mat_dot(mat, mat);
            k >>= 1;
        }
        return res;
    }

    vector<T> solve(vv<T> mat, const vector<T> &init, ll K) {
        int n = mat.size();
        auto base = list2d(n, 1, (T)0);
        rep(i, n) base[i][0] = init[i];
        auto res = mat_pow(mat, K);
        base = mat_dot(res, base);
        vector<T> ret(n, 0);
        rep(i, n) ret[i] = base[i][0];
        return ret;
    }

    template<size_t SZ>
    array<T, SZ> solve(array<array<T, SZ>, SZ> mat, const array<T, SZ> &init, ll K) {
        int n = mat.size();
        array<array<T, 1>, SZ> base = {};
        rep(i, n) base[i][0] = init[i];
        auto res = mat_pow(mat, K);
        base = mat_dot(res, base);
        array<T, SZ> ret = {};
        rep(i, n) ret[i] = base[i][0];
        return ret;
    }
};
