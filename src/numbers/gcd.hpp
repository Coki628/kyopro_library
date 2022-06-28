#pragma once
#include "../macros.hpp"

// 非再帰版作ってみたけど、速度あんま変わらなそう…。
template<typename T>
T gcd(T a, T b) {
    while (b) {
        T t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// template<typename T>
// T gcd(T a, T b) { return __gcd(a, b); }

template<typename T>
T gcd(const vector<T> &A) {
    T res = 0;
    for (auto a : A) res = gcd(res, a);
    return res;
}
