#pragma once
#include "../common/listnd.hpp"
#include "../macros.hpp"

// グリッドBFS(経路復元)
string bfs(
    const vector<string> &grid,
    const pii &src,
    const pii &goal,
    char invalid = '#'
) {
    int H = grid.size();
    int W = grid[0].size();
    auto dist = list2d(H, W, INF);
    auto prv = list2d(H, W, -1);
    const vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pii> que;
    auto [sh, sw] = src;
    que.push({sh, sw});
    dist[sh][sw] = 0;
    while (!que.empty()) {
        auto [h, w] = que.front();
        que.pop();
        rep(d, 4) {
            auto [dh, dw] = directions[d];
            int nh = h + dh;
            int nw = w + dw;
            if (nh < 0 or nw < 0 or nh >= H or nw >= W) continue;
            if (grid[nh][nw] == invalid) continue;
            if (dist[nh][nw] == INF) {
                dist[nh][nw] = dist[h][w] + 1;
                prv[nh][nw] = d % 2 == 0 ? d + 1 : d - 1;
                que.push({nh, nw});
            }
        }
    }

    // 経路復元
    string res;
    vector<char> itoc = {'U', 'D', 'L', 'R'};
    auto [ch, cw] = goal;
    while (ch != sh or cw != sw) {
        int d = prv[ch][cw];
        auto [dh, dw] = directions[d];
        ch += dh;
        cw += dw;
        res += itoc[d % 2 == 0 ? d + 1 : d - 1];
    }
    reverse(ALL(res));
    return res;
}
