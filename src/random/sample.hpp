#pragma once
#include "../macros.hpp"
#include "mt.hpp"

// 配列vecからランダムにn個の要素を選択して返す
// (stdにあったけど、python風のラッパー作っとく)
template<typename T>
vector<T> sample(vector<T> vec, int n) {
    vector<T> res;
    std::sample(ALL(vec), back_inserter(res), n, mt);
    return res;
}
