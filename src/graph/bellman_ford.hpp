#pragma once
#include "../common/chmin.hpp"
#include "../macros.hpp"

// ベルマンフォード(頂点数, 辺集合(0-indexed), 始点)
template<typename T>
vector<T> bellman_ford(int N, const vector<tuple<int, int, T>> &edges, int src) {
    // 頂点[ある始点からの最短距離] (経路自体を知りたい時はここに前の頂点も持たせる)
    vector<T> res(N, INF);
    res[src] = 0;
    // 各辺によるコストの置き換えを頂点数N-1回繰り返す
    rep(_, N - 1) {
        for (auto [u, v, cost] : edges) {
            // INFからは更新しない
            if (res[u] == INF) {
                continue;
            }
            chmin(res[v], res[u] + cost);
        }
    }
    auto tmp = res;
    // 負の閉路(いくらでもコストを減らせてしまう場所)がないかチェックする
    rep(_, N - 1) {
        for (auto [u, v, cost] : edges) {
            if (res[u] == INF) {
                continue;
            }
            if (res[v] > res[u] + cost) {
                // 検出した負閉路はすぐに-INFにする
                res[v] = -INF;
            }
        }
    }
    rep(i, N) {
        if (tmp[i] != res[i]) {
            res[i] = -INF;
        }
    }
    return res;
}
