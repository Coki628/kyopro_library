#include "../base.hpp"
#include "../grid/transpose.hpp"
#include "RollingHash.hpp"

struct RollingHash2D {
    RollingHash rh1, rh2;

    explicit RollingHash2D() {}

    // H*Wのグリッドからhlen*wlenサイズのハッシュを全取得する：O(HW)
    vv<uint64_t> get_hashs(const vector<string> &grid, int hlen, int wlen) {
        int H = grid.size();
        int W = grid[0].size();
        assert(hlen <= H and wlen <= W);

        auto rowhashs = listnd(H, W - wlen + 1, (uint64_t)0);
        rep(h, H) {
            auto table = rh1.build(grid[h]);
            rep(w, W - wlen + 1) {
                rowhashs[h][w] = rh1.query(table, w, w + wlen);
            }
        }
        rowhashs = transpose(rowhashs);
        auto colhashs = listnd(W - wlen + 1, H - hlen + 1, (uint64_t)0);
        rep(w, W - wlen + 1) {
            auto table = rh2.build(rowhashs[w]);
            rep(h, H - hlen + 1) {
                colhashs[w][h] = rh2.query(table, h, h + hlen);
            }
        }
        return transpose(colhashs);
    }

    // H*Wのグリッドからhlen*wlenサイズのハッシュを全取得する：O(HW)
    template<typename T>
    vv<uint64_t> get_hashs(const vv<T> &grid, int hlen, int wlen) {
        int H = grid.size();
        int W = grid[0].size();
        assert(hlen <= H and wlen <= W);

        auto rowhashs = listnd(H, W - wlen + 1, (uint64_t)0);
        rep(h, H) {
            auto table = rh1.build(grid[h]);
            rep(w, W - wlen + 1) {
                rowhashs[h][w] = rh1.query(table, w, w + wlen);
            }
        }
        rowhashs = transpose(rowhashs);
        auto colhashs = listnd(W - wlen + 1, H - hlen + 1, (uint64_t)0);
        rep(w, W - wlen + 1) {
            auto table = rh2.build(rowhashs[w]);
            rep(h, H - hlen + 1) {
                colhashs[w][h] = rh2.query(table, h, h + hlen);
            }
        }
        return transpose(colhashs);
    }

    // H*Wのグリッド全体を表すハッシュを取得する：O(HW)
    uint64_t get_hash(const vector<string> &grid) {
        int H = grid.size();
        int W = grid[0].size();
        return get_hashs(grid, H, W)[0][0];
    }

    // H*Wのグリッド全体を表すハッシュを取得する：O(HW)
    template<typename T>
    uint64_t get_hash(const vv<T> &grid) {
        int H = grid.size();
        int W = grid[0].size();
        return get_hashs(grid, H, W)[0][0];
    }
};
