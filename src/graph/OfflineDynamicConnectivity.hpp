#pragma once
#include "../base.hpp"
#include "UnionFindUndo.hpp"

// オフラインダイコネ
// see: https://atcoder.jp/contests/abc334/submissions/48778004
// 使い方及び旧ライブラリとの相違点
// ・初期化時にクエリ数は渡さなくていい。
// ・一連の辺の付け外しをadd_edge,remove_edgeで記録する。
// ・あとで状態確認したいタイミングでqueryを実行しておく。
// 　この時、経過時間を返すので、必要なら取っておく。
// ・全ての操作が終わったらsolveを実行。
// 　前もってqueryを実行したタイミングで、この時渡した関数fを実行してくれる。
// 　この関数fの引数には経過時間が渡されるので、必要に応じて適宜クエリ番号などと紐付ける。
// ・なお、経過時間はadd_edge,remove_edge,queryを使う度に1ずつ増える。
// ・solveに、pre_add,post_removeという関数をオプションで渡せるようにして、
// 　マージ前とundo後に何か見たい時に対応できるようにした。
// 　これらの関数の引数にはマージとundoに関わった2つの代表点が渡される。
class OfflineDynamicConnectivity {
private:
    struct Query {
        int type, v, w, otherTime;
    };

    int V, curTime;
    vector<Query> queries;
    vector<map<int, int>> presentEdges;

    template<typename F>
    void solve(F f, int l, int r, const auto &pre_add, const auto &post_remove) {
        if (l >= r) {
            if (l == r && queries[r].type == 0) {
                f(r);
            }
            return;
        }
        int m = l + (r - l) / 2;
        int curSize = uf.history.size();
        for (int i = m + 1; i <= r; i++) {
            if (queries[i].otherTime < l) {
                pre_add(queries[i].v, queries[i].w);
                uf.merge(queries[i].v, queries[i].w);
            }
        }
        solve(f, l, m, pre_add, post_remove);
        while ((int)uf.history.size() > curSize) {
            auto [v, w] = uf.undo();
            post_remove(v, w);
        }
        for (int i = l; i <= m; i++) {
            if (queries[i].otherTime > r) {
                pre_add(queries[i].v, queries[i].w);
                uf.merge(queries[i].v, queries[i].w);
            }
        }
        solve(f, m + 1, r, pre_add, post_remove);
        while ((int)uf.history.size() > curSize) {
            auto [v, w] = uf.undo();
            post_remove(v, w);
        }
    }

public:
    UnionFindUndo uf;

    OfflineDynamicConnectivity(int V)
        : V(V),
          curTime(0),
          uf(V),
          presentEdges(V) {
    }

    void add_edge(int v, int w) {
        if (v > w) swap(v, w);
        presentEdges[v][w] = curTime++;
        queries.push_back({1, v, w, INT_MAX});
    }

    void remove_edge(int v, int w) {
        if (v > w) swap(v, w);
        int insTime = presentEdges[v][w];
        queries.push_back({-1, v, w, insTime});
        queries[insTime].otherTime = curTime++;
        presentEdges[v].erase(w);
    }

    int query() {
        queries.push_back({0, -1, -1, curTime++});
        return curTime - 1;
    }

    template<typename F>
    void solve(F f) {
        solve(f, 0, curTime - 1, [](int v, int w) {}, [](int v, int w) {});
    }

    template<typename F>
    void solve(F f, const auto &pre_add, const auto &post_remove) {
        solve(f, 0, curTime - 1, pre_add, post_remove);
    }
};
