#pragma once
#include "../macros.hpp"
#include "tree.hpp"

// 差分列管理
// ・内部実装をmultisetから平衡二分探索木treeにしてK番目取得を可能にした。
// 　treeは(multiじゃない)setなので、多重集合を扱えるように内部でidとペアにしてある。
// ・さすがに若干multisetのより遅い。
template<typename T, typename F>
struct DifferenceManagerTree {
    using Tree = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;
    // se1: 現在の要素を表す集合
    // se2: 現在の差分列の要素を表す集合
    Tree se1, se2;
    int id = 0;

    // 基本はこれを渡す
    // [](T a, T b) { return a - b; };
    const F f;

    DifferenceManagerTree(const vector<T> &A, const F &f) : f(f) {
        for (auto &a : A) {
            se1.insert({a, id});
            id++;
        }
        build();
    }

    void build() {
        auto itr = se1.begin();
        while (itr != se1.end() and itr != --se1.end()) {
            se2.insert({f(next(itr)->first, itr->first), id});
            id++;
            itr++;
        }
    }

    void insert(T x) {
        // この戻り値が微妙にmultisetと違う
        auto [itr, _] = se1.insert({x, id});
        id++;
        if (itr != se1.begin() and itr != --se1.end()) {
            se2.erase(se2.lower_bound({f(next(itr)->first, prev(itr)->first), 0}));
        }
        if (itr != se1.begin()) {
            se2.insert({f(itr->first, prev(itr)->first), id});
            id++;
        }
        if (itr != --se1.end()) {
            se2.insert({f(next(itr)->first, itr->first), id});
            id++;
        }
    }

    void erase(T x) {
        auto itr = se1.lower_bound({x, 0});
        assert(itr != se1.end());
        if (itr != se1.begin()) {
            se2.erase(se2.lower_bound({f(itr->first, prev(itr)->first), 0}));
        }
        if (itr != --se1.end()) {
            se2.erase(se2.lower_bound({f(next(itr)->first, itr->first), 0}));
        }
        if (itr != se1.begin() and itr != --se1.end()) {
            se2.insert({f(next(itr)->first, prev(itr)->first), id});
            id++;
        }
        se1.erase(itr);
    }

    int size() {
        return se1.size();
    }

    T max_val() {
        assert(size() >= 1);
        return (--se1.end())->first;
    }

    T min_val() {
        assert(size() >= 1);
        return se1.begin()->first;
    }

    T max_diff() {
        assert(size() >= 2);
        return (--se2.end())->first;
    }

    T min_diff() {
        assert(size() >= 2);
        return se2.begin()->first;
    }

    T kth_val(int k) {
        auto itr = se1.find_by_order(k);
        assert(itr != se1.end());
        return itr->first;
    }

    T kth_diff(int k) {
        auto itr = se2.find_by_order(k);
        assert(itr != se2.end());
        return itr->first;
    }
};

template<typename T, typename F>
DifferenceManagerTree<T, F> get_difference_manager_tree(const vector<T> &A, const F &f) {
    return {A, f};
}
