#pragma once
#include "../macros.hpp"
#include "../common/chmax.hpp"

// 根付き木のハッシュ
// 参考：https://nyaannyaan.github.io/library/tree/tree-hash.hpp
// 　　　https://snuke.hatenablog.com/entry/2017/02/03/054210
// ・実装はNyaanさん、理屈はすぬけさんの記事を参考に。
// ・ハッシュの実装は既存のロリハからベースとなる部分は流用した。
struct TreeHash {
    static const ull mod = (1ull << 61ull) - 1;
    using uint128_t = __uint128_t;
    int n;
    vector<ull> base;

    static inline ull add(ull a, ull b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline ull mul(ull a, ull b) {
        uint128_t c = (uint128_t)a * b;
        return add(c >> 61, c & mod);
    }

    TreeHash(int n) : n(n) {
        // 2^61-1以下の乱数を返す
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<ull> rand(1, TreeHash::mod - 1);
        base.assign(n, 0);
        rep(d, n) {
            // 深さ毎に乱数baseを決めておく
            base[d] = rand(mt);
        }
    }

    // 頂点rootを根とした木nodesのハッシュを返す
    vector<ull> get_hash(const vvi &nodes, int root = 0) {
        assert(nodes.size() <= this->n);
        int N = nodes.size();
        // 頂点uを根とした部分木を表すハッシュ
        vector<ull> hash(N);
        // 葉から見た深さ
        vector<int> depth(N);
        auto dfs = [&](auto &&f, int u, int prv) -> void {
            for (auto v : nodes[u]) {
                if (v == prv) continue;
                f(f, v, u);
                chmax(depth[u], depth[v] + 1);
            }
            assert(depth[u] < N);
            hash[u] = 1;
            for (auto v : nodes[u]) {
                if (v == prv) continue;
                hash[u] = mul(hash[u], add(base[depth[u]], hash[v]));
            }
        };
        dfs(dfs, root, -1);
        return hash;
    }
};
