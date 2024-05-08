#pragma once
#include "../macros.hpp"

// 区間に辺を張るテク
// 参考：https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656
// ・状況に応じてグラフに対して行いたい操作は様々なので、区間辺グラフの構築のみ行うようにした。
// 　nodesの情報をダイクストラや01BFSなどに突っ込めばOK。
// ・[n,2*n)に元グラフの頂点がある。
struct RangeEdgedGraph {
    int n;
    vv<pil> nodes;

    RangeEdgedGraph(int n) : n(n) {
        nodes.resize(3 * n);
        for (int i = 1; i < n; ++i) {
            int cl = i * 2, cr = i * 2 + 1;
            // 上のセグ木には根→葉方向に重み0の辺を張る
            _add_edge(i, cl, 0);
            _add_edge(i, cr, 0);
            // 下のセグ木には葉→根方向に重み0の辺を張る
            // 下のセグ木を操作したいときは +2*n すればよい
            _add_edge(cl + 2 * n, i + 2 * n, 0);
            _add_edge(cr + 2 * n, i + 2 * n, 0);
        }
    }

    // map [3n, 4n) -> [n, 2n)
    void _add_edge(int u, int v, ll w) {
        if (3 * n <= u) u -= 2 * n;
        nodes[u].pb({v, w});
    }

    // u -> [l,r) の区間辺を張る
    void add_edges(int u, pii seg, ll w) {
        auto [l, r] = seg;
        u += n;
        // 上のセグ木と繋ぐ
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) _add_edge(u, l++, w);
            if (r & 1) _add_edge(u, --r, w);
        }
    }

    // [l,r) -> v の区間辺を張る
    void add_edges(pii seg, int v, ll w) {
        auto [l, r] = seg;
        v += n;
        // 下のセグ木と繋ぐ
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) _add_edge(l + 2 * n, v, w), l++;
            if (r & 1) --r, _add_edge(r + 2 * n, v, w);
        }
    }
    // u -> v の辺を張る
    void add_edge(int u, int v, ll w) {
        _add_edge(u + n, v + n, w);
    }

    vv<pil> get_nodes() {
        return nodes;
    }
};
