#pragma once
#include "../macros.hpp"

// 有向グラフの閉路検出(未verify)
bool cycle_detection(const vvi &nodes) {
    int N = nodes.size();
    vector<int> memo(N, -1);
    auto dfs = [&](auto dfs, int u) -> bool {
        if (memo[u] == 1) {
            return false;
        } else if (memo[u] == 0) {
            return true;
        }
        memo[u] = 0;

        for (int v : nodes[u]) {
            if (dfs(dfs, v)) {
                return true;
            }
        }
        memo[u] = 1;
        return false;
    };
    rep(i, N) {
        if (dfs(dfs, i)) {
            return true;
        }
    }
    return false;
}
