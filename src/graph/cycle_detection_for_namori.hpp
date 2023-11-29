#include "../macros.hpp"

// なもりグラフの閉路検出
// cycle[u] := 頂点uがなもりの閉路に含まれるかどうか
vector<int> cycle_detection_for_namori(vvi nodes) {
    int N = nodes.size();
    vector<int> visited(N), cycle(N);
    bool end = false;
    auto dfs = [&](auto&& f, int u, int prv) -> bool {
        if (visited[u]) {
            cycle[u] = true;
            return true;
        }
        visited[u] = true;
        for (auto v : nodes[u]) {
            if (v == prv) continue;
            if (f(f, v, u)) {
                if (not end) {
                    // 終端の頂点に戻ってくるまでの頂点を追加する
                    if (not cycle[u]) {
                        cycle[u] = true;
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
