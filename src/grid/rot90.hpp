#pragma once
#include "../macros.hpp"

// グリッドを時計回りに90度回転
vector<string> rot90(const vector<string> &grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<string> res(W, string(H, '*'));
    rep(i, H) {
        rep(j, W) {
            res[j][H - i - 1] = grid[i][j];
        }
    }
    return res;
}

template<typename T>
vv<T> rot90(const vv<T> &grid) {
    int H = grid.size();
    int W = grid[0].size();
    vv<T> res(W, vector<T>(H));
    rep(i, H) {
        rep(j, W) {
            res[j][H - i - 1] = grid[i][j];
        }
    }
    return res;
}
