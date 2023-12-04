#pragma once
#include "../macros.hpp"
#include "../common/listnd.hpp"

// グリッド転置
template<typename T>
vector<vector<T>> transpose(const vector<vector<T>> &grid) {
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
