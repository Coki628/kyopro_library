#pragma once
#include "../base.hpp"

// 参考：https://ei1333.github.io/library/structure/union-find/union-find-undo.cpp
// undo可能UF
struct UnionFindUndo {
    vector< int > data;
    stack< pair< int, int > > history;

    UnionFindUndo(int sz) {
        data.assign(sz, -1);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        history.emplace(x, data[x]);
        history.emplace(y, data[y]);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int k) {
        if (data[k] < 0) return (k);
        return find(data[k]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int k) {
        return -data[find(k)];
    }

    void undo() {
        data[history.top().first] = history.top().second;
        history.pop();
        data[history.top().first] = history.top().second;
        history.pop();
    }

    // 直前t回の操作を戻す
    void undo(int t) {
        while (t--) undo();
    }

    void snapshot() {
        while (history.size()) history.pop();
    }

    void rollback() {
        while (history.size()) undo();
    }
};
