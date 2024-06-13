#include "../base.hpp"

// ポテンシャルを用いた負辺除去
// 使い方
// ・前提として負辺は除去できるが、負閉路があると使えない。
// ・グラフの元の辺集合と、負辺を除去できるようなポテンシャルを渡す。負辺のなくなった辺集合を返す。
// 　その辺集合をダイクストラに渡せば最短距離を適切に計算してくれる。
// 　ポテンシャルは(経路を1,2,3,...,nだとして)
// 　(P[1] - P[2]) + (P[2] - P[3]) + ... + (P[n-1] - P[n])
// 　みたいに寄与するので、途中の頂点分は全て相殺される。
// 　なのでダイクストラの結果には始点と終点の分だけ調整するために、(P[終点] - P[始点])を与える。
// ・ポテンシャルはベルマンフォードで最短距離を1つ求めると、それがそのまま使えるらしい。
// 　一見、2乗かけてベルマンフォードで最短距離求めたなら、その後ダイクストラする意味なくない？となる。
// 　だがこの求まったポテンシャルは、他の頂点を始点とするダイクストラにも流用できるらしい。
// 　なので負辺あり全頂点最短距離みたいなやつを求める時にワーシャルフロイドより速くなるようだ。
// ・2乗できない時のポテンシャルを求める方法は、状況に応じて頑張って見つけるしかないようだ。
// 　任意に求まる手段があれば良かったんだけど…。
// 参考：https://niuez.hatenablog.com/entry/2019/03/04/142903
// 　　　https://ikatakos.com/pot/programming_algorithm/graph_theory/minimum_cost_flow
// 使用例：abc237_e
template<typename T>
vector<tuple<int, int, T>> remove_negative_edges(const vector<tuple<int, int, T>> &edges, const vector<T> &P) {
    vector<tuple<int, int, T>> res;
    for (auto [u, v, c] : edges) {
        T nc = c + P[u] - P[v];
        assert(nc >= 0);
        res.emplace_back(u, v, nc);
    }
    return res;
}
