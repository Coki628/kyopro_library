#pragma once

// 乗算のオーバーフロー検知
// 参考：https://rsk0315.hatenablog.com/entry/2021/02/23/163040
template<typename T>
bool mul_overflow(T x, T y) {
    T z;
    return __builtin_mul_overflow(x, y, &z);
}

// 加算のオーバーフロー検知
template<typename T>
bool add_overflow(T x, T y) {
    T z;
    return __builtin_add_overflow(x, y, &z);
}
