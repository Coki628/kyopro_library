#pragma once
#include "../base.hpp"

// undo可能UF
// 参考：https://ei1333.github.io/library/structure/union-find/union-find-undo.cpp
// ・オフラインダイコネの改修に合わせてこちらも改修した。
// 　と言っても、非再帰化したり内部実装の変更なので操作方法は変わってない。
struct UnionFindUndo {
    vector<int> data;
    vector<pair<pair<int, int>, int>> history;
    int n, groupcnt;

    UnionFindUndo(int sz) : n(sz), groupcnt(sz) {
        data.assign(sz, -1);
    }

    template<typename F>
    int merge(int x, int y, F f) {
        x = find(x);
        y = find(y);
        if (x == y) return -1;
        if (data[x] > data[y]) swap(x, y);
        f(x, y);
        history.push_back({{x, y}, data[y]});
        groupcnt--;
        data[x] += data[y];
        data[y] = x;
        return x;
    }

    int merge(int a, int b) {
        return merge(a, b, [](int r, int ch) {});
    }

    int find(int v) {
        while (data[v] >= 0) v = data[v];
        return v;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int k) {
        return -data[find(k)];
    }

    int size() {
        return groupcnt;
    }

    pair<int, int> undo() {
        int v = history.back().first.first;
        int w = history.back().first.second;
        int ufw = history.back().second;
        history.pop_back();
        data[w] = ufw;
        data[v] -= data[w];
        groupcnt++;
        // undo後の代表点(v,w)を返す
        return {v, w};
    }

    // 直前t回の操作を戻す
    void undo(int t) {
        while (t--) undo();
    }

    void rollback() {
        while (history.size()) undo();
    }
};
