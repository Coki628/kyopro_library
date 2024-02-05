#pragma once
#include "../macros.hpp"

// オイラーツアー
// ・HLDから切り出した。部分木クエリはこれで十分。
struct EulerTour {
public:
    int N;
    vvi nodes;
    vector<int> sz, in, out, rev, par, dep;

    explicit EulerTour(const vvi &nodes) : nodes(nodes), N(nodes.size()) {
        sz.assign(N, 0);
        in.assign(N, 0);
        out.assign(N, 0);
        rev.assign(N, 0);
        par.assign(N, 0);
        dep.assign(N, 0);
        int t = 0;
        dfs(0, -1, 0, t);
    }

    int operator[](int u) const {
        assert(0 <= u && u < N);
        return in[u];
    }

private:
    void dfs(int idx, int p, int d, int &times) {
        dep[idx] = d;
        par[idx] = p;
        sz[idx] = 1;
        in[idx] = times++;
        rev[in[idx]] = idx;
        for (auto &to : nodes[idx]) {
            if (to == p) continue;
            dfs(to, idx, d + 1, times);
            sz[idx] += sz[to];
        }
        out[idx] = times;
    }
};
