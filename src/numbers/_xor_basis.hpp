#pragma once
#include "../common/chmin.hpp"
#include "../macros.hpp"

// XOR基底(クラス版作ったけど、何回か使うまで一応こっちも取っておく)
template<typename T>
vector<T> get_xor_basis(const vector<T> &A) {
    vector<T> basis;
    for (auto a : A) {
        for (auto b : basis) {
            chmin(a, a ^ b);
        }
        if (a > 0) basis.eb(a);
    }
    return basis;
}
