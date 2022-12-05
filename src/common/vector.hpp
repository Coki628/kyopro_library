#pragma once
#include "../macros.hpp"

// 参考：https://twitter.com/stoq_/status/1484211267510288384
template<typename T>
constexpr void operator--(vector<T> &vec, int) noexcept {
    rep(i, vec.size()) vec[i]--;
}

template<typename T>
constexpr void operator++(vector<T> &vec, int) noexcept {
    rep(i, vec.size()) vec[i]++;
}
