#pragma once
#include "../macros.hpp"
#include "acl/scc.hpp"

// SCC
// ・ACLをラップしてる。
// ・縮約グラフの構築ができるようにしてある。
struct SCC {
    int N, N2;
    vector<pii> edges, edges2;
    vvi groups;
    vector<int> NtoN2, sz;
    bool built = false;
    bool constructed = false;

    SCC(int N) : N(N) {}

    // 有向辺の追加
    void add_edge(int u, int v) {
        edges.eb(u, v);
    }

    // SCCの実行、普通にACLのSCCをやる
    vvi build() {
        atcoder::scc_graph scc(N);
        for (auto [u, v] : edges) {
            scc.add_edge(u, v);
        }
        built = true;
        return groups = scc.scc();
    }

    // 縮約グラフの構築
    void construct() {
        assert(built);
        N2 = groups.size();
        NtoN2.assign(N, -1);
        sz.assign(N2, 0);
        rep(i, N2) {
            sz[i] = groups[i].size();
            for (auto u : groups[i]) {
                NtoN2[u] = i;
            }
        }
        for (auto [u, v] : edges) {
            int i = NtoN2[u];
            int j = NtoN2[v];
            edges2.eb(i, j);
        }
        UNIQUE(edges2);
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

    // 元グラフの辺列挙
    vector<pii> get_edges() {
        assert(constructed);
        return edges;
    }

    // 縮約グラフの辺列挙
    vector<pii> get_edges2() {
        assert(constructed);
        return edges2;
    }
};
