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
    UnionFind(const vector<int> &info) : n(info.size()) {
        build();
        vvi adj(n);
        for (int i = 0; i < n; i++) {
            adj[info[i]].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (adj[i].size()) {
                for (int j = 0; j < (int)adj[i].size() - 1; j++) {
                    merge(adj[i][j], adj[i][j + 1]);
                }
            }
        }
    }

    void build() {
        par.assign(n, 0);
        rank.assign(n, 0);
        sz.assign(n, 1);
        tree.assign(n, true);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        groupcnt = n;
    }

    void resize(int _n) {
        n = _n;
        par.assign(n, 0);
        rank.assign(n, 0);
        sz.assign(n, 1);
        tree.assign(n, true);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
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

    // 頂点aの連結成分とbの連結成分の併合
    // 戻り値としてマージ後の集合の代表点(マージ済なら-1)を返す。
    // 関数fを渡す場合、マージ直前にfが実行される。
    // 引数として
    // r := マージ後に親となる代表点
    // ch := マージ後に子となる代表点(マージ済なら-1)
    // を渡す。
    template<typename F>
    int merge(int a, int b, F f) {
        int x = find(a);
        int y = find(b);
        if (x == y) {
            f(x, -1);
            tree[x] = false;
            return -1;
        }
        if (!tree[x] or !tree[y]) {
            tree[x] = tree[y] = false;
        }
        groupcnt--;
        if (rank[x] < rank[y]) {
            f(y, x);
            par[x] = y;
            sz[y] += sz[x];
            return y;
        } else {
            f(x, y);
            par[y] = x;
            sz[x] += sz[y];
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
            return x;
        }
    }

    int merge(int a, int b) {
        return merge(a, b, [](int r, int ch) {});
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
        for (int i = 0; i < n; i++) {
            res.insert(find(i));
        }
        return res;
    }

    // 全頂点のグループ番号を取得
    vector<int> get_info() {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = find(i);
        }
        return res;
    }
};
