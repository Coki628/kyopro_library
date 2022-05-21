#pragma once
#include "../macros.hpp"

struct UnionFind {

    int n, groupcnt;
    vector<int> par, rank, sz;
    vector<bool> tree;

    UnionFind(int n) : n(n) {
        build();
    }

    UnionFind() {}

    // 既存の連結情報からUFを生成
    UnionFind(const vector<int>& info) : n(info.size()) {
        build();
        vvi adj(n);
        rep(i, n) {
            adj[info[i]].eb(i);
        }
        rep(i, n) {
            if (adj[i].size()) {
                rep(j, adj[i].size()-1) {
                    merge(adj[i][j], adj[i][j+1]);
                }
            }
        }
    }

    void build() {
        par.assign(n, 0);
        rank.assign(n, 0);
        sz.assign(n, 1);
        tree.assign(n, true);
        rep(i, n) par[i] = i;
        groupcnt = n;
    }

    void resize(int _n) {
        n = _n;
        par.assign(n, 0);
        rank.assign(n, 0);
        sz.assign(n, 1);
        tree.assign(n, true);
        rep(i, n) par[i] = i;
        groupcnt = n;
    }

    // 根(グループ番号)の検索
    virtual int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            par[x] = find(par[x]);
            return par[x];
        }
    }

    // 併合：マージ後の集合の根(マージ済なら-1)を返す
    int merge(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) {
            tree[x] = false;
            return -1;
        }
        if (!tree[x] or !tree[y]) {
            tree[x] = tree[y] = false;
        }
        groupcnt--;
        if (rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
            return y;
        } else {
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
            return x;
        }
    }

    // 同じ集合に属するか判定
    bool same(int a, int b) {
        return find(a) == find(b);
    }

    // あるノードの属する集合のノード数
    ll size(int x) {
        return sz[find(x)];
    }

    // 集合の数
    int size() {
        return groupcnt;
    }

    // 木かどうかの判定
    bool is_tree(int x) {
        return tree[find(x)];
    }

    // 全ての根を取得
    set<int> get_roots() {
        set<int> res;
        rep(i, n) {
            res.insert(find(i));
        }
        return res;
    }

    // 全頂点のグループ番号を取得
    vector<int> get_info() {
        vector<int> res(n);
        rep(i, n) {
            res[i] = find(i);
        }
        return res;
    }
};
