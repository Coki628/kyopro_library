#include "../macros.hpp"

// 経路復元
// ・s -> t 間の経路を取得
// ・直前の頂点を持った配列prvさえ渡せば、BFSでもダイクストラでも汎用的に使える(はず)。
vector<int> get_route(vector<int> &prv, int s, int t) {
    vector<int> res = {t};
    while (t != s) {
        t = prv[t];
        if (t == -1) {
            return {};
        }
        res.eb(t);
    }
    reverse(ALL(res));
    return res;
}
