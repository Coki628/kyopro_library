#pragma once
#include "../base.hpp"
#include "LowLink.hpp"

// 二重頂点連結成分分解
// see: https://nyaannyaan.github.io/library/graph/biconnected-components.hpp
//      https://kntychance.hatenablog.jp/entry/2022/09/16/161858
// ・これ単体でどうと言うよりは、Block Cut Treeの構築のために存在してる感ある。
struct BiConnectedComponents : LowLink {
    vector<int> used;
    vector<vector<pair<int, int>>> bc;
    vector<pair<int, int>> tmp;

    BiConnectedComponents(const vvi &_g) : LowLink(_g) {
        build();
    }

    void build() {
        used.assign(this->g.size(), 0);
        for (int i = 0; i < (int)used.size(); i++) {
            if (!used[i]) dfs(i, -1);
        }
    }

    void dfs(int idx, int par) {
        used[idx] = true;
        for (auto &to : this->g[idx]) {
            if (to == par) continue;
            if (!used[to] || this->ord[to] < this->ord[idx]) {
                tmp.emplace_back(minmax<int>(idx, to));
            }
            if (!used[to]) {
                dfs(to, idx);
                if (this->low[to] >= this->ord[idx]) {
                    bc.emplace_back();
                    while (true) {
                        auto e = tmp.back();
                        bc.back().emplace_back(e);
                        tmp.pop_back();
                        if (e.first == min<int>(idx, to) &&
                            e.second == max<int>(idx, to)) {
                            break;
                        }
                    }
                }
            }
        }
    }
};
