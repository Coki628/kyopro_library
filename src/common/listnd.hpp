#pragma once
#include "../macros.hpp"

// 任意次元vector
// 参考：https://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp
template<typename... Ts>
auto listnd(size_t N, Ts... ts) {
    if constexpr (sizeof...(ts) == 1) {
        return vector<Ts...>(N, ts...);
    } else {
        auto res = listnd(ts...);
        return vector<decltype(res)>(N, res);
    }
}

// 後方互換
template<typename T>[[deprecated("list2d will be merged with listnd")]] vv<T> list2d(int N, int M, T init) { return listnd(N, M, init); }
template<typename T>[[deprecated("list3d will be merged with listnd")]] vv<vector<T>> list3d(int N, int M, int L, T init) { return listnd(N, M, L, init); }
template<typename T>[[deprecated("list4d will be merged with listnd")]] vv<vv<T>> list4d(int N, int M, int L, int O, T init) { return listnd(N, M, L, O, init); }
