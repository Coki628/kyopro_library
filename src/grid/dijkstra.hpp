#pragma once
#include "../macros.hpp"
#include "../common/listnd.hpp"
#include "../common/chmin.hpp"
#include "constants/dir4.hpp"

// グリッドダイクストラ(H*Wグリッド, 始点{h, w})
using P = tuple<ll, int, int>;
vvl dijkstra(const vvl &grid, pii src, ll invalid = -1) {
    int H = grid.size();
    int W = grid[0].size();
    auto res = listnd(H, W, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    auto [sh, sw] = src;
    que.push({0, sh, sw});
    res[sh][sw] = 0;

    while (que.size()) {
        auto [dist, h, w] = que.top();
        que.pop();
        if (res[h][w] < dist) continue;
        for (auto [dh, dw] : dir4) {
            int nh = h + dh;
            int nw = w + dw;
            if (nh < 0 or nw < 0 or nh >= H or nw >= W) continue;
            if (grid[nh][nw] == invalid) continue;
            ll cost = grid[nh][nw];
            if (chmin(res[nh][nw], dist + cost)) {
                que.push({dist + cost, nh, nw});
            }
        }
    }
    return res;
}
