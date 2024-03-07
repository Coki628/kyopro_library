#pragma once
#include "../base.hpp"

// Cartesian Tree
// see: https://nyaannyaan.github.io/library/tree/cartesian-tree.hpp
// return value : pair<graph, root>
// ・渡された数列を元に、根から順に値の昇順で潜っていくような二分木を構築する。
// ・今いる頂点が最小値となる範囲[l,r)が分かる。
// 　(まあこれはlogつければセグ木にぶたんで求まるんだけどね)
// ・戻り値の隣接リストは通常のグラフと同じ隣接リストの形にしたので、
// 　必要に応じてそのままHLDに突っ込んだりできる。
// ・降順で構築したい時はis_minにfalseを渡す。
template<typename T>
pair<vector<vector<int>>, int> cartesian_tree(vector<T> A, bool is_min = true) {
    int N = (int)A.size();
    if (not is_min) {
        for (auto &a : A) {
            a = -a;
        }
    }
    vector<vector<int>> nodes(N);
    vector<int> P(N, -1), st;
    st.reserve(N);
    for (int i = 0; i < N; i++) {
        int prv = -1;
        while (!st.empty() && A[i] < A[st.back()]) {
            prv = st.back();
            st.pop_back();
        }
        if (prv != -1) P[prv] = i;
        if (!st.empty()) P[i] = st.back();
        st.push_back(i);
    }
    int root = -1;
    for (int i = 0; i < N; i++) {
        if (P[i] != -1) {
            nodes[P[i]].push_back(i);
        } else {
            root = i;
        }
    }
    return make_pair(nodes, root);
}

// auto dfs = [&](auto &&f, int l, int u, int r) -> void {
//     for (auto v : nodes[u]) {
//         if (v < u) {
//             f(f, l, v, u);
//         } else if (v > u) {
//             f(f, u + 1, v, r);
//         }
//     }
// };
// dfs(dfs, 0, root, N);
