#pragma once
#include "../macros.hpp"

using int128 = __int128_t;

istream &operator>>(istream &is, int128 &x) {
    long long in;
    is >> in;
    x = in;
    return is;
}

void print(int128 x) {
    long long out = x;
    cout << out << '\n';
}

string to_string(int128 x) {
    string res;
    while (x) {
        res += '0' + x % 10;
        x /= 10;
    }
    reverse(ALL(res));
    return res;
}

// 禁呪法
// #define ll int128
