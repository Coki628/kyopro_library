#pragma once
#include "../common/Compress.hpp"
#include "../macros.hpp"
#include "HeavyLightDecomposition.hpp"

// ## Auxiliary Tree
// ### 説明
// - 指定した頂点集合Sと、それらのLCAのみで構成されるグラフを計算量|S|log|S|程度で構築する。
// ### 使い方
// - 全体のグラフが確定した時点で隣接リストnodesを渡して初期化
// - 各クエリ毎に使う頂点集合の配列Aを渡してbuild
// - このクラス本体への添字アクセスで隣接リストみたいに使える。
// - 頂点番号はそのままなので、距離が必要ならdistで取れるようにした。
// - get_verticesで直近のbuildで使用した頂点を列挙できるようにした。  
//   LCA頂点は複数回使われるので、これを状態戻しに使える。
// - 隣接リストでなく辺集合が使いたい時にはget_edgesが使える。
// - 元頂点番号ではなく、サイズを小さくしたグラフで何かしたい時はget_compressを使えば座圧情報が得られる。
// ### 使用例
// - 色毎に木DPやDFSする：abc340_g,abc359_g,typical90_ai,cf613D,cf1923E
// - 縮約後グラフを使ってbitDP：cf1929E
// - 縮約後グラフで次数チェック：cf1702G1
// - 色毎に全方位木DP：abc359_g
// ### 参考
// https://suisen-cp.github.io/cp-library-cpp/library/tree/auxiliary_tree.hpp
struct AuxiliaryTree {
    int N;
    HeavyLightDecomposition hld;

    AuxiliaryTree() = default;
    AuxiliaryTree(const vvi &nodes) : N(nodes.size()), hld(nodes), _aux(N) {}

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

        // 重複削除
        sort(_upd.begin(), _upd.end()), _upd.erase(unique(_upd.begin(), _upd.end()), _upd.end());

        return st[0];
    }

    // 現在のグラフの座圧情報(元頂点番号⇔座圧後の番号)を返す
    Compress<int> get_compress() {
        Compress<int> cp(get_vertices());
        return cp;
    }

    // 現在のグラフの辺集合(無向辺)を返す
    vector<pair<int, int>> get_edges() {
        vector<pair<int, int>> edges;
        for (auto u : get_vertices()) {
            for (auto v : _aux[u]) {
                if (u > v) continue;
                edges.push_back({u, v});
            }
        }
        return edges;
    }

    // 直近のbuildで使用した頂点を列挙(状態戻しとかに使える)
    vector<int> get_vertices() {
        return _upd;
    }

private:
    vector<vector<int>> _aux;
    vector<int> _upd;
};
