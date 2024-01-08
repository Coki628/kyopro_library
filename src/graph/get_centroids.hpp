#pragma once
#include "../macros.hpp"

// 木nodesの重心を取得
vector<int> get_centroids(const vvi &nodes) {
    int N = nodes.size();
    vector<int> sz(N), centroids;
    auto dfs = [&](auto &&f, int u, int prv) -> void {
        for (int v : nodes[u]) {
            if (v == prv) continue;
            f(f, v, u);
            sz[u] += sz[v];
        }
        sz[u]++;
        bool is_centroid = true;
        for (int v : nodes[u]) {
            if (v == prv) continue;
            if (sz[v] > N / 2) {
                is_centroid = false;
                break;
            }
        }
        if (is_centroid && N - sz[u] <= N / 2) {
            centroids.pb(u);
        }
    };
    dfs(dfs, 0, -1);
    return centroids;
}
