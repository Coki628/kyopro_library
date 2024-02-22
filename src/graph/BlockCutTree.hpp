#pragma once
#include "../base.hpp"
#include "BiConnectedComponents.hpp"

// Block Cut Tree
// see: https://nyaannyaan.github.io/library/tree/block-cut-tree.hpp
//      https://kntychance.hatenablog.jp/entry/2022/09/16/161858
// ・二重辺連結成分分解で橋をベースにして木を構築したのと同じように、
// 　二重頂点連結成分分解で関節点をベースに木(元が非連結なら森)を構築したのがこれ。
// ・なお、孤立点・葉は関節点ではない。(まあそれはそうか…。)
struct BlockCutTree {
    const vector<vector<int>> g;
    BiConnectedComponents bcc;
    vector<vector<int>> aux, groups;
    vector<int> idar, idcc, sz, is_arti;

    BlockCutTree(const vector<vector<int>> &_g) : g(_g), bcc(g) {
        build();
    }

    void build() {
        auto ar = bcc.get_articulations();
        idar.resize(g.size(), -1);
        idcc.resize(g.size(), -1);
        for (int i = 0; i < (int)ar.size(); i++) idar[ar[i]] = i;

        aux.resize(ar.size() + bcc.bc.size());
        vector<int> last(g.size(), -1);
        for (int i = 0; i < (int)bcc.bc.size(); i++) {
            vector<int> st;
            for (auto &[u, v] : bcc.bc[i]) st.push_back(u), st.push_back(v);
            for (auto &u : st) {
                if (idar[u] == -1) idcc[u] = i + ar.size();
                else if (last[u] != i) {
                    add(i + ar.size(), idar[u]);
                    last[u] = i;
                }
            }
        }

        sz.resize(aux.size());
        is_arti.resize(aux.size());
        groups.resize(aux.size());
        for (int u = 0; u < g.size(); u++) {
            int k = this->id(u);
            // 元グラフの孤立点を一応縮約グラフに組み込んでおく
            if (k == -1) {
                k = aux.size();
                idcc[u] = k;
                sz.push_back(0);
                is_arti.push_back(false);
                groups.push_back(vector<int>());
                aux.push_back(vector<int>());
            }
            groups[k].push_back(u);
            sz[k]++;
            if (idar[u] != -1) {
                is_arti[k] = true;
            }
        }
    }

    // 縮約後グラフの隣接リスト
    vector<int> &operator[](int i) {
        return aux[i];
    }

    // 連結成分数(縮約後グラフの頂点数)
    int size() const {
        return aux.size();
    }

    // (縮約後グラフの)頂点kの連結成分要素数
    int size(int k) {
        return sz[k];
    }

    // 元グラフの頂点i -> 縮約後グラフの頂点番号
    int id(int i) {
        return idar[i] == -1 ? idcc[i] : idar[i];
    }

    // (縮約後グラフの)頂点kが元グラフで関節点かどうか
    bool is_articulation(int k) {
        return is_arti[k];
    }

    // 縮約後グラフの隣接リスト
    vector<vector<int>> get_nodes() {
        return aux;
    }

    // ACLのSCCが返すみたいな各連結成分を表す隣接リスト
    vector<vector<int>> get_groups() {
        return groups;
    }

    // bool is_arti(int i) {
    //     return idar[i] != -1;
    // }

    // int arti() {
    //     return bcc.get_articulations().size();
    // }

private:
    void add(int i, int j) {
        if (i == -1 or j == -1) return;
        aux[i].push_back(j);
        aux[j].push_back(i);
    };
};
