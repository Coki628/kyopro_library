#include "../macros.hpp"
#include "UnionFind.hpp"

// 重み付きUF
template<typename T>
struct WeightedUnionFind : UnionFind {

    vector<T> weight;
    
    WeightedUnionFind(int n) : UnionFind(n) {
        // 根への距離を管理
        weight.resize(n);
    }

    // 検索
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int y = find(par[x]);
            // 親への重みを追加しながら根まで走査
            weight[x] += weight[par[x]];
            par[x] = y;
            return y;
        }
    }

    // 併合
    int merge(int a, int b, ll w) {
        int x = find(a);
        int y = find(b);
        int r = UnionFind::merge(a, b);
        if (r == y) {
            weight[x] = w - weight[a] + weight[b];
            return y;
        } else {
            weight[y] = - w - weight[b] + weight[a];
            return x;
        }
    }

    // xからyへのコスト
    T diff(int x, int y) {
        assert(same(x, y));
        return weight[x] - weight[y];
    }
};
