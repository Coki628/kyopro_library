#pragma once
#include "../macros.hpp"
#include "Accumulate.hpp"

template<typename T>
struct Imos : Accumulate<T> {
    using Accumulate<T>::Accumulate;

    void build() {
        rep(i, this->N - 1) {
            this->dat[i + 1] += this->dat[i];
        }
    }

    // 1点加算
    void add(int i, T a) {
        this->dat[i] += a;
        this->dat[i + 1] -= a;
    }

    // 区間加算[l,r)
    void add(int l, int r, T a) {
        this->dat[l] += a;
        this->dat[r] -= a;
    }

    // 区間取得クエリは不可
    T query(int l, int r) {
        assert(0);
    }

    // 1点取得
    T get(int i) {
        return this->dat[i];
    }

    // 1点取得
    T operator[](int i) {
        return this->dat[i];
    }
};
