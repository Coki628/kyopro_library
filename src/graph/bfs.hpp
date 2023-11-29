#pragma once
#include "../macros.hpp"
#include "../common/chmin.hpp"

// BFS
// ・メインの処理内にベタ貼りして中身ちょっといじるがすぐできるようにラムダにした。
// 　(本当は[&]で雑にキャプチャしたいけど、これやるとグローバルに置けないみたいなので。)
auto bfs = [](const vvi &nodes, const vector<int> &src) {
    int N = nodes.size();
    vector<ll> res(N, INF);
    queue<int> que;
    for (int s : src) {
        res[s] = 0;
        que.push(s);
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto v : nodes[u]) {
            if (chmin(res[v], res[u] + 1)) {
                que.push(v);
            }
        }
    }
    return res;
};
