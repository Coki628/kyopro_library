#pragma once
#include "../macros.hpp"
#include "acl/scc.hpp"

// 区間辺SCC
struct RangeEdgedSCC {
    int N, N2, N3, n;
    vector<pii> edges, edges2, edges3;
    vvi groups;
    vector<int> N2toN, N2toN3, sz;
    bool built = false;
    bool constructed = false;

    RangeEdgedSCC(int N) : N(N) {
        n = 1;
        while (n < N) n <<= 1;
        N2 = 2 * n;
        for (int i = 1; i < n; i++) {
            _add_edge(i, 2 * i + 0);
            _add_edge(i, 2 * i + 1);
        }
        N2toN.assign(N2, -1);
        rep(i, N) {
            N2toN[n + i] = i;
        }
    }

    void _add_edge(int u, int v) {
        edges2.eb(u, v);
    }

    // 有向辺の追加
    void add_edge(int u, int v) {
        _add_edge(n + u, n + v);
    }

    // 区間辺 u -> [l,r) の追加
    void add_edges(int u, int l, int r) {
        l += n, r += n, u += n;
        while (l < r) {
            if (l & 1) _add_edge(u, l++);
            if (r & 1) _add_edge(u, --r);
            l >>= 1, r >>= 1;
        }
    }

    // SCCの実行、普通にACLのSCCをやる
    vvi build() {
        atcoder::scc_graph scc(N2);
        for (auto [u, v] : edges2) {
            scc.add_edge(u, v);
        }
        built = true;
        return groups = scc.scc();
    }

    // 縮約グラフの構築
    void construct() {
        assert(built);
        N3 = groups.size();
        N2toN3.assign(N2, -1);
        sz.assign(N3, 0);
        rep(i, N3) {
            if (groups[i].size()) {
                for (auto u : groups[i]) {
                    N2toN3[u] = i;
                    if (N2toN[u] != -1) {
                        // 元グラフに存在する頂点だけ成分数にカウントしておく
                        sz[i]++;
                    }
                }
            }
        }
        for (auto [u, v] : edges2) {
            int i = N2toN3[u];
            int j = N2toN3[v];
            edges3.eb(i, j);
        }
        UNIQUE(edges3);
        constructed = true;
    }

    // 強連結成分uの元グラフでの頂点数
    int size(int u) {
        assert(constructed);
        return sz[u];
    }

    // 強連結成分の個数
    int size() {
        assert(built);
        return groups.size();
    }

    // 元グラフの辺列挙(そもそもこれは陽にできなくなる)
    vector<pii> get_edges() {
        assert(constructed);
        return edges;
    }

    // 区間辺グラフの辺列挙
    vector<pii> get_edges2() {
        assert(constructed);
        return edges2;
    }

    // 縮約グラフの辺列挙
    vector<pii> get_edges3() {
        assert(constructed);
        return edges3;
    }
};
