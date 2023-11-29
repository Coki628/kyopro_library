#include "../macros.hpp"
#include "../common/listnd.hpp"
#include "constants/dir4.hpp"

// グリッドBFS
auto bfs = [](const vector<string> &grid, const vector<pii> &src, char invalid='#') {
    int H = grid.size();
    int W = grid[0].size();
    auto res = list2d(H, W, INF);
    queue<pii> que;
    for (auto [h, w] : src) {
        res[h][w] = 0;
        que.push({h, w});
    }
    while (!que.empty()) {
        auto [h, w] = que.front();
        que.pop();
        for (auto [dh, dw] : dir4) {
            int nh = h + dh;
            int nw = w + dw;
            if (nh < 0 or nw < 0 or nh >= H or nw >= W) continue;
            if (grid[nh][nw] == invalid) continue;
            if (res[nh][nw] == INF) {
                res[nh][nw] = res[h][w] + 1;
                que.push({nh, nw});
            }
        }
    }
    return res;
};
