#pragma once
#include "../macros.hpp"

// 縦反転
vector<string> flip_h(const vector<string> &grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<string> res(H, string(W, '*'));
    rep(i, H) {
        rep(j, W) {
            res[i][j] = grid[H - i - 1][j];
        }
    }
    return res;
}

// 横反転
vector<string> flip_w(const vector<string> &grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<string> res(H, string(W, '*'));
    rep(i, H) {
        rep(j, W) {
            res[i][j] = grid[i][W - j - 1];
        }
    }
    return res;
}

// 縦反転
template<typename T>
vv<T> flip_h(const vv<T> &grid) {
    int H = grid.size();
    int W = grid[0].size();
    auto res = listnd(H, W, T());
    rep(i, H) {
        rep(j, W) {
            res[i][j] = grid[H - i - 1][j];
        }
    }
    return res;
}

// 横反転
template<typename T>
vv<T> flip_w(const vv<T> &grid) {
    int H = grid.size();
    int W = grid[0].size();
    auto res = listnd(H, W, T());
    rep(i, H) {
        rep(j, W) {
            res[i][j] = grid[i][W - j - 1];
        }
    }
    return res;
}
