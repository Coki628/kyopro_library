#pragma once
#include "../acl/maxflow.hpp"
#include "../macros.hpp"

// 燃やす埋める
// ・直感的に分かりづらい諸々を少しでも使いやすくする。
// 仕様説明
// ・便宜上、選択肢のどちら側なのかを、始点s側を左、終点t側を右と表す。
// ・依存関係の親側になる選択肢は基本的に右に置く。(まあメソッド名で基本的にどっちなのかは示してある)
// ・選択肢のコスト設定addはかなり直感的にやりやすくしたつもり。
struct PSP {
    int N, s = -2, t = -1;
    // だいたい利得が多いのでデフォルトtrue,コストの時はfalseに
    bool is_max;
    ll offset;
    vector<tuple<int, int, ll>> edges;
    atcoder::mf_graph<ll> mf;

    // 選択肢N個の燃やす埋めるを作成
    PSP(int N, bool is_max = true) : N(N), is_max(is_max), offset(0) {}

    // i個目の選択肢の利得(コスト)に(lval,rval)を設定する
    void add(int i, ll lval, ll rval) {
        if (is_max) {
            ll mx = max(lval, rval);
            offset += mx;
            edges.eb(s, i, mx - lval);
            edges.eb(i, t, mx - rval);
        } else {
            ll mn = min(lval, rval);
            edges.eb(s, i, lval - mn);
            edges.eb(i, t, rval - mn);
        }
    }

    // 選択肢aが右ならば選択肢bも右を強制する
    void a_right_then_b_right(int a, int b) {
        edges.eb(a, b, INF);
    }

    // 選択肢aが右で選択肢bが左ならば損失valを負う(ここはis_maxがどちらでも損失)
    void a_right_and_b_left_then(int a, int b, ll val) {
        assert(val >= 0);
        edges.eb(a, b, val);
    }

    // 複数選択肢vsが全て右ならば利得valを得る(多分利得にのみ有効でコストには適用できない)
    // see: https://ikatakos.com/pot/programming_algorithm/graph_theory/maximum_flow/burn_bury_problem
    void all_right_then(const vector<int> &vs, ll val) {
        assert(is_max ? val >= 0 : val <= 0);
        int k = N;
        N++;
        add(k, 0, 1);
        for (auto v : vs) {
            a_right_then_b_right(k, v);
        }
    }

    // 複数選択肢vsが全て左ならば利得valを得る(多分利得にのみ有効でコストには適用できない)
    void all_left_then(const vector<int> &vs, ll val) {
        int k = N;
        N++;
        add(k, 1, 0);
        for (auto v : vs) {
            a_right_then_b_right(v, k);
        }
    }

    ll solve() {
        mf = atcoder::mf_graph<ll>(N + 2);
        s = N;
        t = N + 1;
        for (auto &[u, v, c] : edges) {
            // 始点・終点の確定
            if (u < 0) u += N + 2;
            if (v < 0) v += N + 2;
            mf.add_edge(u, v, c);
        }
        if (is_max) {
            return offset - mf.flow(s, t);
        } else {
            return mf.flow(s, t) - offset;
        }
    }
};
