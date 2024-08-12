#pragma once
#include "../base.hpp"

// 合成関数
// ・いつもどっちがどっちかこんがらがるのでもうライブラリ化する。
// ・適用順序が大事！f1 -> f2 の順で適用するとする。

// ax + b の合成関数
// h2(h1(x))
// c * h1(x) + d
// c * (ax + b) + d
// c * ax + c * b + d
// {c * a, c * b + d}

// 合成関数(pair版)(未verify)
// f1 -> f2 の順で適用するとする
template<typename T>
pair<T, T> composite_function(pair<T, T> f1, pair<T, T> f2) {
    return {f2.first * f1.first, f2.first * f1.second + f2.second};
}

// 合成は前から順に行われるとする
template<typename T>
struct Function {
    T a = 1, b = 0;

    Function &operator*=(const Function &f) {
        a = f.a * a;
        b = f.a * b + f.b;
        return *this;
    }

    Function operator*(const Function &f) const {
        return Function(*this) *= f;
    }

    T f(T x) const {
        return a * x + b;
    }
};
