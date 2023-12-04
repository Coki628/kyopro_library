#pragma once
#include "../base.hpp"
#include "chmax.hpp"

template<typename T>
T max(const vector<T> &A) {
    assert(not A.empty());
    return *max_element(ALL(A));
}

template<typename key, typename val>
val max(const map<key, val> &mp) {
    val res = numeric_limits<val>::min();
    for (auto &[k, v] : mp) chmax(res, v);
    return res;
}
