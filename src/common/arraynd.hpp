#pragma once
#include "../base.hpp"

// 任意次元array
// 使い方：arraynd<ll, 2, 3>(INF); で ll[2][3] = INF になる。
template<typename T, size_t N, size_t... Ns>
auto arraynd(T a) {
    if constexpr (sizeof...(Ns) == 0) {
        array<T, N> res;
        res.fill(a);
        return res;
    } else {
        static auto cur = arraynd<T, Ns...>(a);
        array<decltype(cur), N> res;
        res.fill(cur);
        return res;
    }
}
