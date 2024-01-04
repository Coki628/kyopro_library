#pragma once
#include "../base.hpp"
#include "../common/subarray.hpp"
#include "TwoSAT.hpp"

// 区間辺2-SAT
// see: https://codeforces.com/contest/1903/submission/235149307
// ・おてらさんの実装がACLをうまくラップしてる感じですごく参考になった。
// ・使用側としてはなるべく頂点番号の変化とかを意識しないで済むように、
// 　呼び出し時には全て元頂点の番号で操作を呼べるようにした。
struct RangeEdgedTwoSAT : public TwoSAT {
    using base_type = TwoSAT;
    using base_type::base_type;

    int n;
    RangeEdgedTwoSAT(int n) : n(n), base_type(2 * n) {
        for (int i = 1; i < n; i++) {
            int cl = i * 2, cr = i * 2 + 1;
            base_type::add_clause(i, true, cl, false);
            base_type::add_clause(i, true, cr, false);
        }
    }

    void add_clause(int i, bool f, int j, bool g) override {
        base_type::add_clause(i + n, f, j + n, g);
    }

    // u = f, [l,r) = g の区間辺を張る
    void add_clause(int u, bool f, int l, int r, bool g) {
        u += n;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) base_type::add_clause(u, f, l++, g);
            if (r & 1) base_type::add_clause(u, f, --r, g);
        }
    }

    vector<bool> answer() {
        auto res = base_type::answer();
        return subarray(res, n, 2 * n);
    }
};
