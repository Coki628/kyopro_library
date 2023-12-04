#pragma once
#include "../common/listnd.hpp"
#include "../macros.hpp"

// グリッド転置
template<typename T>
vv<T> transpose(const vv<T> &grid) {
    int H = grid.size();
    int W = grid[0].size();
    auto res = listnd(W, H, (T)0);
    rep(i, H) {
        rep(j, W) {
            res[j][i] = grid[i][j];
        }
    }
    return res;
}

// グリッド転置(文字列)
vector<string> transpose(const vector<string> &grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<string> res(W, string(H, '*'));
    rep(i, H) {
        rep(j, W) {
            res[j][i] = grid[i][j];
        }
    }
    return res;
}
