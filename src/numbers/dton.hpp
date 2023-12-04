#pragma once
#include "../macros.hpp"
#include "../common/modulo.hpp"

// 10進法をN進法文字列に(負数n対応版)
string dton(ll num, ll n, char base = '0') {
    string res;
    while (abs(num) > 0) {
        ll m = modulo(num, abs(n));
        num -= m;
        ll nxt = base + m;
        // 英数字で表現できない値になったら不正とする
        if (nxt >= UCHAR_MAX or not isalnum(nxt)) {
            return "";
        }
        res += nxt;
        num /= n;
    }
    reverse(ALL(res));
    if (res != "") {
        return res;
    } else {
        return {base};
    }
}

// 旧版
// string dton(ll num, ll n) {
//     string res;
//     ll m;
//     while (num > 0) {
//         tie(num, m) = divmod(num, n);
//         res += tochar(m);
//     }
//     reverse(ALL(res));
//     if (res != "") {
//         return res;
//     } else {
//         return "0";
//     }
// }
