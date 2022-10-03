#pragma once
#include "../macros.hpp"

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << p.first << ' ' << p.second;
}

template<typename T1, typename T2, typename T3>
ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &tp) {
    return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);
}

template<typename T1, typename T2, typename T3, typename T4>
ostream &operator<<(ostream &os, const tuple<T1, T2, T3, T4> &tp) {
    return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp);
}

template<typename T, size_t SZ>
ostream &operator<<(ostream &os, const array<T, SZ> &arr) {
    rep(i, arr.size()) {
        os << arr[i];
        if (i != (ll)arr.size()-1) {
            os << ' ';
        }
    }
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    rep(i, vec.size()) {
        os << vec[i];
        if (i != (ll)vec.size()-1) {
            os << ' ';
        }
    }
    return os;
}

void print() {
    cout << '\n';
}

template<typename T>
void print(T out) {
    cout << out << '\n';
}

template<typename T1, typename T2, typename T3>
void print(const tuple<T1, T2, T3> &tp) {
    cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\n';
}

template<typename T1, typename T2, typename T3, typename T4>
void print(const tuple<T1, T2, T3, T4> &tp) { 
    cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\n';
}

template<typename T>
void print(const vector<T> &V, char sep=' ') {
    rep(i, V.size()) {
        cout << V[i];
        if (i != (ll)V.size()-1) cout << sep;
    }
    cout << '\n';
}

template<typename T, size_t SZ>
void print(const array<T, SZ> &arr, char sep=' ') {
    rep(i, arr.size()) {
        cout << arr[i];
        if (i != (ll)arr.size()-1) cout << sep;
    }
    cout << '\n';
}

// template<typename T, size_t SZ>
// void print(const vector<array<T, SZ>> &V) {
//     for (auto& arr : V) print(arr);
// }

template<typename T>
void print(const deque<T> &que) {
    vector<T> V(ALL(que));
    print(V);
}

template<typename T>
void print(const set<T> &se) {
    vector<T> V(ALL(se));
    print(V);
}

#define debug(x) (cout << #x << ": ", print(x));
