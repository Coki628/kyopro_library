#pragma once
#include "../base.hpp"
#include "../common/print.hpp"

template<typename _Tp>
struct my_vector : vector<_Tp> {
    // コンストラクタの継承
    using vector<_Tp>::vector;
    _Tp pop() {
        _Tp res = this->back();
        this->pop_back();
        return res;
    }

    template<typename F>
    auto map(F f) {
        vector<decltype(f(_Tp()))> res;
        for (auto& val : *this) {
            res.eb(f(val));
        }
        return res;
    }
};

template<typename T>
void print(const my_vector<T> &A) {
    vector<T> V(A.begin(), A.end());
    print(V);
}
