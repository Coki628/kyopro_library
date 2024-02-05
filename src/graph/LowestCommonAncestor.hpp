#pragma once
#include "../datastructure/SparseTable.hpp"
#include "../macros.hpp"
#include "EulerTour.hpp"

// 線形LCA
// 参考：https://suisen-cp.github.io/cp-library-cpp/library/tree/lowest_common_ancestor.hpp
// ・最短距離取得をlogつけないでやるLCA(構築はちゃんとNlogNかかるけど)。
// ・SparseTableを使うので、あんまり頂点数多い時とかはメモリ厳しいかも。
struct LowestCommonAncestor {
    int N;
    vector<int> dep, in;
    static pii f(const pii &a, const pii &b) {
        return min(a, b);
    }
    // クラス内関数へのdecltype
    // see: https://stackoverflow.com/questions/52520276/is-decltype-of-a-non-static-member-function-ill-formed
    SparseTable<pii, decltype(&f)> st = get_sparse_table(&f, pii{MOD, -1});

    explicit LowestCommonAncestor(const vvi &nodes) : N(nodes.size()) {
        dep.assign(N, 0);
        in.assign(N, 0);
        int t = 0;
        vector<pii> vec;
        auto dfs = [&](auto &&f, int u, int p, int d) -> void {
            dep[u] = d;
            in[u] = t++;
            vec.eb(d, u);
            for (auto v : nodes[u]) {
                if (v == p) continue;
                f(f, v, u, d + 1);
                vec.eb(d, u);
                t++;
            }
        };
        dfs(dfs, 0, -1, 0);
        st.build(vec);
    }

    int lca(int u, int v) {
        if (in[u] > in[v]) swap(u, v);
        return st.query(in[u], in[v] + 1).second;
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
};
