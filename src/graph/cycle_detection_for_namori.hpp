#pragma once
#include "../macros.hpp"

// なもりグラフの閉路検出：O(N)
// cycle := なもりの閉路の頂点集合(経路順に並ぶので、この持ち方だと辺も分かる)
vector<int> cycle_detection_for_namori(vvi nodes) {
    int N = nodes.size();
    vector<int> visited(N), cycle;
    bool end = false;
    auto dfs = [&](auto &&f, int u, int prv) -> bool {
        if (visited[u]) {
            cycle.eb(u);
            return true;
        }
        visited[u] = true;
        for (auto v : nodes[u]) {
            if (v == prv) continue;
            if (f(f, v, u)) {
                if (not end) {
                    // 終端の頂点に戻ってくるまでの頂点を追加する
                    if (u != cycle[0]) {
                        cycle.eb(u);
                    } else {
                        end = true;
                    }
                }
                return true;
            }
        }
        return false;
    };
    dfs(dfs, 0, -1);
    return cycle;
}
