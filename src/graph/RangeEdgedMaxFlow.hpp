#pragma once
#include "../macros.hpp"
#include "acl/maxflow.hpp"

// 区間辺最大流(未verify)
template<typename T>
struct RangeEdgedMaxFlow {
    int N, N2, n;
    atcoder::mf_graph<T> mf;

    RangeEdgedMaxFlow(int N) : N(N), N2(N * 2), n(N), mf(N * 2) {
        for (int i = 1; i < n; i++) {
            int cl = i * 2, cr = i * 2 + 1;
            _add_edge(i, cl);
            _add_edge(i, cr);
        }
        N2toN.assign(N2, -1);
        rep(i, N) {
            N2toN[n + i] = i;
        }
    }

    void _add_edge(int u, int v, T cap) {
        mf.add_edge(u, v, cap);
    }

    // 有向辺の追加
    void add_edge(int u, int v, T cap) {
        _add_edge(n + u, n + v, cap);
    }

    // 区間辺 u -> [l,r) の追加
    void add_edges(int u, int l, int r, T cap) {
        u += n;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) _add_edge(u, l++, cap);
            if (r & 1) _add_edge(u, --r, cap);
        }
    }

    T flow(int s, int t) {
        return mf.flow(s, t);
    }
};
