#pragma once
#include "../macros.hpp"

// pair入力一括受け取り
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

// vector入力一括受け取り
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}

// ※最近はもうずっとvectorの受け取りはoperator>>なので、これはもう要らないかも。
// template<typename T = ll>
// vector<T> LIST(ll N) {
//     vector<T> A(N);
//     rep(i, N) {
//         cin >> A[i];
//     }
//     return A;
// }
