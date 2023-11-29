#pragma once
#include "../macros.hpp"

// 生配列用のINF埋め初期化
// ・動的確保した(初期化の添字が固定値じゃない)生配列には使えない。
// 　マルチテストケースの場合は、グローバルで大きく取って、サイズ指定で小さく埋めるように使う。

// 全埋め
// see: https://qiita.com/oyas/items/70b7e29d0388392ef2ce
template<typename A, size_t N, typename T>
void fill(A (&arr)[N], const T &val) {
    fill((T*)arr, (T*)(arr + N), val);
}
// サイズ指定(必要な所まで埋めたい時使う)
template<typename A, typename T>
void fill(A &arr, int n, const T &val) {
    rep(i, n) arr[i] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, const T &val) {
    rep(i1, n1) rep(i2, n2) arr[i1][i2] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, int n3, const T &val) {
    rep(i1, n1) rep(i2, n2) rep(i3, n3) arr[i1][i2][i3] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, int n3, int n4, const T &val) {
    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) arr[i1][i2][i3][i4] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, int n3, int n4, int n5, const T &val) {
    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) arr[i1][i2][i3][i4][i5] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, int n3, int n4, int n5, int n6, const T &val) {
    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) arr[i1][i2][i3][i4][i5][i6] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, int n3, int n4, int n5, int n6, int n7, const T &val) {
    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) arr[i1][i2][i3][i4][i5][i6][i7] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, const T &val) {
    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) rep(i8, n8) arr[i1][i2][i3][i4][i5][i6][i7][i8] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, const T &val) {
    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) rep(i8, n8) rep(i9, n9) arr[i1][i2][i3][i4][i5][i6][i7][i8][i9] = val;
}
template<typename A, typename T>
void fill(A &arr, int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, const T &val) {
    rep(i1, n1) rep(i2, n2) rep(i3, n3) rep(i4, n4) rep(i5, n5) rep(i6, n6) rep(i7, n7) rep(i8, n8) rep(i9, n9) rep(i10, n10) arr[i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] = val;
}
