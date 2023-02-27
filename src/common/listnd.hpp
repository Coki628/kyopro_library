#pragma once
#include "../base.hpp"

template<typename T>
[[deprecated("list2d will be merged with listnd")]]
vector<vector<T>> list2d(int N, int M, T init) {
    return vector<vector<T>>(N, vector<T>(M, init));
}

template<typename T>
[[deprecated("list3d will be merged with listnd")]]
vector<vector<vector<T>>> list3d(int N, int M, int L, T init) {
    return vector<vector<vector<T>>>(N, vector<vector<T>>(M, vector<T>(L, init)));
}

template<typename T>
[[deprecated("list4d will be merged with listnd")]]
vector<vector<vector<vector<T>>>> list4d(int N, int M, int L, int O, T init) {
    return vector<vector<vector<vector<T>>>>(N, vector<vector<vector<T>>>(M, vector<vector<T>>(L, vector<T>(O, init))));
}

// 任意次元vector
// 参考：https://luzhiled1333.github.io/comp-library/src/cpp-template/header/make-vector.hpp
template<typename T>
vector<T> listnd(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto listnd(size_t a, Ts... ts) {
    return vector<decltype(listnd(ts...))>(a, listnd(ts...));
}
