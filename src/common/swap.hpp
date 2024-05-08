#pragma once
#include "../base.hpp"

// 値配列と位置配列の同時スワップ
// ids[i] := 位置iにある値
// pos[a] := 値aのある位置
// として、位置i,jをスワップした時のids,posを適切に更新する
template<typename T>
void swap(vector<T> &ids, vector<T> &pos, int i, int j) {
    swap(pos[ids[i]], pos[ids[j]]);
    swap(ids[i], ids[j]);
}
