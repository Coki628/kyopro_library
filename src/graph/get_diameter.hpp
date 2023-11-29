#include "../macros.hpp"
#include "bfs.hpp"

vector<ll> _bfs(const vvpil &nodes, int s) {
    int N = nodes.size();
    vector<ll> res(N, INF);
    queue<int> que;
    res[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto [v, c] : nodes[u]) {
            if (chmin(res[v], res[u] + c)) {
                que.push(v);
            }
        }
    }
    return res;
}

// 木の直径
tuple<int, int, int> get_diameter(const vvi &nodes) {
    auto res1 = bfs(nodes, {0});
    int u = max_element(ALL(res1)) - res1.begin();
    auto res2 = bfs(nodes, {u});
    int v = max_element(ALL(res2)) - res2.begin();
    return {res2[v], u, v};
}

// 重み付き(未verify)
tuple<ll, int, int> get_diameter(const vvpil &nodes) {
    auto res1 = _bfs(nodes, {0});
    int u = max_element(ALL(res1)) - res1.begin();
    auto res2 = _bfs(nodes, {u});
    int v = max_element(ALL(res2)) - res2.begin();
    return {res2[v], u, v};
}
