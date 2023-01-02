#include "../macros.hpp"
#include "toint.hpp"

// ※int変換は別途対応する
// vector<ll> split(const string &S, char separator) {
//     int N = S.size();
//     vector<ll> res;
//     string cur;
//     rep(i, N) {
//         if (S[i] == separator) {
//             res.eb(toint(cur));
//             cur = "";
//         } else {
//             cur += S[i];
//         }
//     }
//     if (cur.size()) res.eb(toint(cur));
//     return res;
// }

// 文字列のまま版
vector<string> split(const string &S, char separator) {
    int N = S.size();
    vector<string> res;
    string cur;
    rep(i, N) {
        if (S[i] == separator) {
            res.eb(cur);
            cur = "";
        } else {
            cur += S[i];
        }
    }
    if (cur.size()) res.eb(cur);
    return res;
}
