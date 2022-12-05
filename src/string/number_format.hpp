#include "../macros.hpp"

// 数値を3桁コンマ区切り
string number_format(ll num) {
    string s = tostr(num);
    reverse(ALL(s));
    string res;
    rep(i, s.size()) {
        res += s[i];
        if (i%3 == 2) {
            res += ',';
        }
    }
    if (res.back() == ',') {
        res.pop_back();
    }
    reverse(ALL(res));
    return res;
}
