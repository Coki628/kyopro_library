#pragma once
#include "../macros.hpp"

// 二部グラフ判定
bool is_bipartite(vvi nodes) {
    int N = nodes.size();
    vector<int> C(N, -1);
    auto dfs = [&](auto &&f, int u, int c) -> bool {
        if (C[u] != -1) {
            return C[u] == c;
        }
        C[u] = c;
        for (auto v : nodes[u]) {
            if (!f(f, v, 1 - c)) {
                return false;
            }
        }
        return true;
    };
    rep(i, N) {
        if (C[i] == -1) {
            if (!dfs(dfs, i, 0)) {
                return false;
            }
        }
    }
    return true;
}
