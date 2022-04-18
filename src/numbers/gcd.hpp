#pragma once
#include "../macros.hpp"

template<typename T>
T gcd(T a, T b) { return __gcd(a, b); }

template<typename T>
T gcd(const vector<T> &A) {
    T res = 0;
    for (auto a : A) res = gcd(res, a);
    return res;
}
