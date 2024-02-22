#pragma once
#include "../macros.hpp"

// Low Link
// see: https://nyaannyaan.github.io/library/graph/lowlink.hpp
// ・グラフの橋と関節点を列挙する。
// ・橋：それを取り除くと連結でなくなるような辺
// ・関節点：それを取り除くと連結でなくなるような頂点
// bridge: 橋(辺(u,v)がu < vとなるように格納)
// articulations point: 関節点
struct LowLink {
    const vvi &g;
    int N;
    vector<int> ord, low, articulations, is_arti;
    vector<pair<int, int>> bridges;

    LowLink(const vvi &_g) : g(_g), N(g.size()), ord(N, -1), low(N, -1), is_arti(N) {
        for (int i = 0, k = 0; i < N; i++) {
            if (ord[i] == -1) {
                k = dfs(i, k, -1);
            }
        }
        sort(ALL(bridges));
    }

    bool is_articulation(int u) {
        return is_arti[u];
    }

    bool is_bridge(int u, int v) {
        if (u > v) swap(u, v);
        auto itr = lower_bound(ALL(bridges), pii{u, v});
        return itr != bridges.end() and (*itr) == pii{u, v};
    }

    bool has_articulation() {
        return articulations.size();
    }

    bool has_bridge() {
        return bridges.size();
    }

    vector<int> get_articulations() {
        return articulations;
    }

    vector<pii> get_bridges() {
        return bridges;
    }

private:
    int dfs(int idx, int k, int par) {
        low[idx] = (ord[idx] = k++);
        int cnt = 0;
        bool arti = false, second = false;
        for (auto &to : g[idx]) {
            if (ord[to] == -1) {
                cnt++;
                k = dfs(to, k, idx);
                low[idx] = min(low[idx], low[to]);
                arti |= (par != -1) && (low[to] >= ord[idx]);
                if (ord[idx] < low[to]) {
                    bridges.emplace_back(minmax(idx, (int)to));
                }
            } else if (to != par || second) {
                low[idx] = min(low[idx], ord[to]);
            } else {
                second = true;
            }
        }
        arti |= par == -1 && cnt > 1;
        if (arti) {
            articulations.push_back(idx);
            is_arti[idx] = true;
        }
        return k;
    }
};