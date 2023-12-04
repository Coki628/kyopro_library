#pragma once
#include "../common/chmin.hpp"
#include "../macros.hpp"

// 01BFS(コストが0or1なら使える)
vector<ll> bfs01(const vvpil &nodes, const vector<int> &src) {
    int N = nodes.size();
    vector<ll> res(N, INF);
    deque<int> que;
    for (int s : src) {
        res[s] = 0;
        que.push_back(s);
    }

    while (!que.empty()) {
        int u = que.front();
        que.pop_front();
        for (auto [v, c] : nodes[u]) {
            if (chmin(res[v], res[u] + c)) {
                if (c == 0) {
                    que.push_front(v);
                } else if (c == 1) {
                    que.push_back(v);
                } else {
                    assert(0);
                }
            }
        }
    }
    return res;
}
