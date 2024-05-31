#pragma once
#include "../macros.hpp"

// 経路復元
// ・s -> t 間の経路を取得
// ・直前の頂点を持った配列prvさえ渡せば、BFSでもダイクストラでも汎用的に使える(はず)。
vector<pii> get_route(vv<pii> &prv, pii s, pii t) {
    vector<pii> res = {t};
    while (t != s) {
        t = prv[t.first][t.second];
        if (t == pii{-1, -1}) {
            return {};
        }
        res.eb(t);
    }
    reverse(ALL(res));
    return res;
}
