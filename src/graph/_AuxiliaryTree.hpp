#pragma once
#include "../common/chmin.hpp"
#include "../common/HashMap.hpp"
#include "../macros.hpp"
#include "../mystl/Vector.hpp"
#include "HeavyLightDecomposition.hpp"

// Auxiliary Tree
// 説明
// ・指定した頂点集合Sと、それらのLCAのみで構成されるグラフを計算量|S|log|S|程度で構築する。
// 使い方
// ・全体のグラフが確定した時点で隣接リストnodesを渡して初期化
// ・各クエリ毎に使う頂点集合の配列Aを渡してbuild
// ・戻り値は圧縮されたグラフの隣接リスト。重み付きにしてコストを元グラフ上での距離としてある。
// 　隣接リストのキーはHashMapで構成しているので、頂点番号は元グラフと同じものを使える(ので添字が分かりやすい)。
// 　(その分多少は速度が犠牲になっているはずだけど、まあNyaanさんのHashMap爆速だから大概大丈夫だと思う。)
struct AuxiliaryTree {
    int N;
    HeavyLightDecomposition hld;

    AuxiliaryTree(const vvi &nodes) : hld(nodes), N(nodes.size()) {}

    pair<HashMap<int, vector<pil>>, int> build(const vector<int> &A) {
        assert(A.size());
        int K = A.size();
        vector<pii> tmp;
        rep(i, K) {
            tmp.eb(hld.in[A[i]], A[i]);
        }
        sort(ALL(tmp));
        Vector<int> st = {tmp[0].second};
        HashMap<int, vector<pil>> res;
        rep(i, 1, K) {
            ll u = st.pop();
            ll v = tmp[i].second;
            ll lca = hld.lca(u, v);
            while (st.size() and hld.dep[st.back()] > hld.dep[lca]) {
                res[st.back()].eb(u, hld.dist(u, st.back()));
                res[u].eb(st.back(), hld.dist(u, st.back()));
                u = st.pop();
            }
            if (st.empty() or st.back() != lca) {
                st.eb(lca);
            }
            if (u != lca) {
                res[lca].eb(u, hld.dist(u, lca));
                res[u].eb(lca, hld.dist(u, lca));
            }
            st.eb(v);
        }
        while (st.size() >= 2) {
            ll u = st.pop();
            res[st.back()].eb(u, hld.dist(u, st.back()));
            res[u].eb(st.back(), hld.dist(u, st.back()));
        }
        int root = A[0], d = hld.dep[A[0]];
        for (auto &[u, li] : res) {
            if (chmin(d, hld.dep[u])) {
                root = u;
            }
        }
        return {res, root};
    }
};
