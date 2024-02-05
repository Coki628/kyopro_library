#pragma once
#include "../macros.hpp"

// 重心分解
// ・隣接リストnodesを渡せば重心分解の木を構築する。
// ・構築中に何かしたい場合は、ラムダなのでメインのコード内に適当に貼って、
// 　rec関数内を適当にちょっといじって必要な処理を書き足せばOK。
// ・構築した木の辺情報で後からそれ使って色々やる時は普通に戻り値のpar使えばOK。
auto centroid_decomposition = [](const vvi &nodes) -> vector<int> {
    int N = nodes.size();
    vector<int> subsz(N), centroids, par(N);
    vector<bool> used(N);
    // 部分木サイズの再計算
    auto dfs_sz = [&](auto &&f, int u, int prv) -> void {
        subsz[u] = 1;
        for (int v : nodes[u]) {
            if (v == prv or used[v]) continue;
            f(f, v, u);
            subsz[u] += subsz[v];
        }
    };
    // uを根とした部分木の重心を求めるDFS
    auto get_centroids = [&](auto &&f, int u, int prv, int sz) -> void {
        subsz[u] = 1;
        for (int v : nodes[u]) {
            if (v == prv or used[v]) continue;
            f(f, v, u, sz);
            subsz[u] += subsz[v];
        }
        bool iscent = true;
        for (int v : nodes[u]) {
            if (v == prv or used[v]) continue;
            if (subsz[v] > sz / 2) {
                iscent = false;
                break;
            }
        }
        if (iscent and sz - subsz[u] <= sz / 2) {
            centroids.pb(u);
        }
    };
    // 重心分解メイン処理(この中に必要な処理を足す)
    auto rec = [&](auto&& f, int u, int prv, int sz) -> void {
        centroids.clear();
        get_centroids(get_centroids, u, prv, sz);
        int v = centroids[0];
        used[v] = true;
        dfs_sz(dfs_sz, v, -1);
        par[v] = prv;
        for (int w : nodes[v]) {
            if (used[w]) continue;
            f(f, w, v, subsz[w]);
        }
    };
    rec(rec, 0, -1, N);
    return par;
};
