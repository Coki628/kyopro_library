#include "../macros.hpp"
#include "../common/listnd.hpp"

// グリッド01BFS
vvl bfs01(const vvl &grid, const vector<pii> &src, ll invalid=-1) {

    int H = grid.size();
    int W = grid[0].size();
    auto res = list2d(H, W, INF);
    const vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    deque<pii> que;
    for (auto [h, w] : src) {
        que.pb({h, w});
        res[h][w] = 0;
    }
    while (!que.empty()) {
        auto [h, w] = que.front(); que.pop_front();
        for (auto [dh, dw] : directions) {
            int nh = h + dh;
            int nw = w + dw;
            if (nh < 0 or nw < 0 or nh >= H or nw >= W) continue;
            if (grid[nh][nw] == invalid) continue;
            ll cost = grid[nh][nw];
            if (res[nh][nw] == INF) {
                if (cost == 0) {
                    res[nh][nw] = res[h][w];
                    que.push_front({nh, nw});
                } else {
                    res[nh][nw] = res[h][w] + 1;
                    que.pb({nh, nw});
                }
            }
        }
    }
    return res;
}
