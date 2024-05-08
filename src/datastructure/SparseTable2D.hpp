#pragma once
#include "../macros.hpp"

// 2Dスパーステーブル：構築にO(HWlogHlogW)、区間最小(最大)をO(1)で取得
// see: https://codeforces.com/blog/entry/45485
// ・使い勝手は2Dセグ木とほぼ同じ感じにしてある。
// ・2Dでlog2つ乗る所がO(1)になるので、クエリはさすがに速いと思う。
// ・ただしメモリはHWlogHlogWも食うのでやばい。100万グリッドで900MB超だったので、
// 　AtCならともかくCFでは使い物にならないだろう…。
template<typename T, typename F>
struct SparseTable2D {
    const F f;
    const T e;
    vv<vv<T>> dat;
    vector<int> heighth, heightw;
    vv<T> grid;

    SparseTable2D(const F f, const T e) : f(f), e(e) {
    }

    SparseTable2D(int H, int W, const F f, const T e) : f(f), e(e) {
        grid = listnd(H, W, e);
    }

    SparseTable2D(const vv<T> &grid, const F f, const T e) : f(f), e(e) {
        build(grid);
    }

    void set(int h, int w, T val) {
        grid[h][w] = val;
    }

    void build() {
        build(grid);
    }

    void build(const vv<T> &grid) {
        int H = grid.size();
        int W = grid[0].size();

        int hh = 0, wh = 0;
        while ((1 << hh) <= H) {
            hh++;
        }
        while ((1 << wh) <= W) {
            wh++;
        }
        dat = listnd(hh, wh, 1 << hh, 1 << wh, e);
        heighth.resize(H + 1);
        heightw.resize(W + 1);

        rep(i, 2, H + 1) {
            heighth[i] = heighth[i >> 1] + 1;
        }
        rep(i, 2, W + 1) {
            heightw[i] = heightw[i >> 1] + 1;
        }
        rep(i, H) {
            rep(j, W) {
                dat[0][0][i][j] = grid[i][j];
            }
            rep(kw, 1, wh) {
                rep(j, W) {
                    dat[0][kw][i][j] =
                        f(dat[0][kw - 1][i][j],
                          dat[0][kw - 1][i][min((int)j + (1 << (kw - 1)), W - 1)]);
                }
            }
        }
        rep(kh, 1, hh) {
            rep(kw, wh) {
                rep(i, H) {
                    rep(j, W) {
                        dat[kh][kw][i][j] =
                            f(dat[kh - 1][kw][i][j],
                              dat[kh - 1][kw][min((int)i + (1 << (kh - 1)), H - 1)][j]);
                    }
                }
            }
        }
    }

    T query(int sh, int sw, int th, int tw) {
        if (sh >= th or sw >= tw) return e;
        int a = heighth[th - sh];
        int b = heightw[tw - sw];
        return f(
            f(dat[a][b][sh][sw], dat[a][b][sh][tw - (1 << b)]),
            f(dat[a][b][th - (1 << a)][sw],
              dat[a][b][th - (1 << a)][tw - (1 << b)])
        );
    }
};

template<typename T, typename F>
SparseTable2D<T, F> get_sparse_table_2d(const F &f, const T &M1) {
    return {f, M1};
}

template<typename T, typename F>
SparseTable2D<T, F> get_sparse_table_2d(int H, int W, const F &f, const T &M1) {
    return {H, W, f, M1};
}

template<typename T, typename F>
SparseTable2D<T, F> get_sparse_table_2d(vv<T> &grid, const F &f, const T &M1) {
    return {grid, f, M1};
}
