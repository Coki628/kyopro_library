#pragma once
#include "../macros.hpp"
#include "HeavyLightDecomposition.hpp"

// Auxiliary Tree
// 説明
// ・指定した頂点集合Sと、それらのLCAのみで構成されるグラフを計算量|S|log|S|程度で構築する。
// 使い方
// ・全体のグラフが確定した時点で隣接リストnodesを渡して初期化
// ・各クエリ毎に使う頂点集合の配列Aを渡してbuild
// ・このクラス本体への添字アクセスで隣接リストみたいに使える。
// ・頂点番号はそのままなので、距離が必要ならdistで取れるようにした。
// ・get_verticesで直近のbuildで使用した頂点を列挙できるようにした。
// 　LCA頂点は複数回使われるので、これを状態戻しに使える。
// see: https://suisen-cp.github.io/cp-library-cpp/library/tree/auxiliary_tree.hpp
struct AuxiliaryTree {
    int N;
    HeavyLightDecomposition hld;

    AuxiliaryTree() = default;
    AuxiliaryTree(const vvi &nodes) : hld(nodes), N(nodes.size()), _aux(N) {}

    const vector<int> &operator[](int u) const {
        return _aux[u];
    }

    int dist(int u, int v) {
        return hld.dist(u, v);
    }

    int build(vector<int> vs) {
        const int k = vs.size();
        for (int v : _upd) _aux[v].clear();
        _upd.clear();

        sort(vs.begin(), vs.end(), [this](int i, int j) {
            return hld.in[i] < hld.in[j];
        });

        copy(vs.begin(), vs.end(), back_inserter(_upd));

        vector<int> st{vs[0]};
        for (int i = 0; i < k - 1; ++i) {
            const int w = hld.lca(vs[i], vs[i + 1]);

            if (w != vs[i]) {
                _upd.push_back(w);
                int last = st.back();
                st.pop_back();
                while (st.size() and hld.dep[w] < hld.dep[st.back()]) {
                    int u = st.back();
                    _aux[u].push_back(last);
                    _aux[last].push_back(u);
                    last = st.back();
                    st.pop_back();
                }

                if (st.empty() or st.back() != w) {
                    st.push_back(w);
                    vs.push_back(w);
                    _aux[w].push_back(last);
                    _aux[last].push_back(w);
                } else {
                    _aux[w].push_back(last);
                    _aux[last].push_back(w);
                }
            }

            st.push_back(vs[i + 1]);
        }
        const int siz = st.size();
        for (int i = 0; i < siz - 1; ++i) {
            _aux[st[i]].push_back(st[i + 1]);
            _aux[st[i + 1]].push_back(st[i]);
        }
        return st[0];
    }

    // 直近のbuildで使用した頂点を列挙(状態戻しとかに使える)
    vector<int> get_vertices() {
        return _upd;
    }

private:
    vector<vector<int>> _aux;
    vector<int> _upd;
};
