#pragma once
#include "../macros.hpp"
#include "LowLink.hpp"

// 二重辺連結成分分解
// see: https://nyaannyaan.github.io/library/graph/two-edge-connected-components.hpp
// ・元の一般グラフから、橋を辺、そうでない部分を頂点にまとめた縮約グラフを構築
// ・その縮約グラフは木になるので、様々な操作が可能になる。
struct TwoEdgeConnectedComponents {
    LowLink low;

    TwoEdgeConnectedComponents(const vvi &g_)
        : g(g_),
          low(g_),
          comp(g_.size(), -1),
          K(0) {
        for (int i = 0; i < (int)g.size(); i++) {
            if (comp[i] == -1) dfs(i, -1);
        }
        groups.resize(K);
        tree.resize(K);
        for (int i = 0; i < (int)g.size(); i++) {
            groups[comp[i]].push_back(i);
        }
        for (auto &e : low.get_bridges()) {
            int u = comp[e.first], v = comp[e.second];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    };

    // (元グラフでの)頂点kの縮約グラフ上での頂点番号
    int operator[](const int &k) const {
        return comp[k];
    }

    // 連結成分数(縮約グラフの頂点数)
    int size() {
        return K;
    }

    // (元グラフでの)頂点kを含む連結成分の要素数
    int size(int k) {
        return groups[comp[k]].size();
    }

    // 連結成分毎にまとめたもの(ACLのSCCが返すのと同じ感じの)
    vvi get_groups() {
        return groups;
    }

    // 縮約グラフを表す隣接リスト
    vvi get_nodes() {
        return tree;
    }

private:
    const vvi g;
    vector<int> comp;
    int K;
    vector<vector<int>> groups, tree;

    void dfs(int i, int p) {
        if (p >= 0 && low.ord[p] >= low.low[i]) {
            comp[i] = comp[p];
        } else {
            comp[i] = K++;
        }
        for (auto &d : g[i]) {
            if (comp[d] == -1) dfs(d, i);
        }
    }
};
