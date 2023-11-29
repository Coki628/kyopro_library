#pragma once
#include "../macros.hpp"
#include "../common/chmin.hpp"

// ※結局こっちのが使い勝手いいから残しておく。

// ダイクストラ
// ・メインの処理内にベタ貼りして中身ちょっといじるがすぐできるようにラムダにした。
auto dijkstra = [](const vvpil &nodes, const vector<int> &src, int goal = -1) {
    int N = nodes.size();
    vector<ll> res(N, numeric_limits<ll>::max() / 2);
    priority_queue<pli, vector<pli>, greater<pli>> que;
    for (auto s : src) {
        res[s] = 0;
        que.push({0, s});
    }
    while (que.size()) {
        auto [dist, u] = que.top();
        que.pop();
        if (u == goal) return res;
        if (res[u] < dist) continue;
        for (auto [v, cost] : nodes[u]) {
            if (chmin(res[v], dist + cost)) {
                que.push({dist + cost, v});
            }
        }
    }
    return res;
};
