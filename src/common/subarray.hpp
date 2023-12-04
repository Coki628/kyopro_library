#pragma once
#include "../base.hpp"

// 配列の部分列取得
// (本当は「slice」が使いたいんだけど、std::sliceと名前衝突するのでとりあえずsubarrayにしておく。)
template<typename T>
vector<T> subarray(const vector<T> &A, int l, int r) {
    return vector<T>(A.begin() + l, A.begin() + r);
}
