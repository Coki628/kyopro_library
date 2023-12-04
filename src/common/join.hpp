#pragma once
#include "../macros.hpp"
#include "to_string.hpp"

template<typename T>
string join(const vector<T> &A, string separator = "") {
    int N = A.size();
    string res;
    rep(i, N) {
        res += tostr(A[i]);
        if (i != N - 1) res += separator;
    }
    return res;
}
