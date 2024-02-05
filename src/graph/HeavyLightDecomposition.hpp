#pragma once
#include "../macros.hpp"

// HL分解
// see: https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.hpp
// ・主な使用方法など
// 　・初期化後、忘れずにbuildを呼ぶこと。→buildは初期化に含めた。
// 　・パスクエリはadd,queryで処理
// 　・1点取得/更新はhld.in[x]で可能。add,queryは呼ばなくていい。
// 　・辺属性にすると、添字0が欠番になる。(親に向かう辺と対応するはずなのでそれはそうか)
// 　　なお辺属性に値を割り当てる時は、depで深い方の頂点にってやるといい。(ABC133fとか参照)
// 　・部分木クエリは[hld.in[x],hld.out[x])で処理。
// 　　なお部分木クエリも辺属性の時はedge=trueのように左端を+1する。
// 　　あと「部分木じゃない部分」も取れる。[0,hld.in[x])と[hld.out[x],N) の2区間でOK。
// 　　これと深さで比較して場合分けすれば、あるパスの手前と向こう側が任意に取れるようになる。
// 　・根付き木は頂点0が根である前提。他の頂点を根にしたい場合、
// 　　HLD構築前に根と頂点0の関係を全てスワップしておく。
// 　　→任意の頂点を根にできるよう改修してみた。前やろうとして失敗したんだけど、
// 　　headの初期値をrootにしたらうまくいった。
// 　・パスクエリ[u,v]にて、u->lcaとlca->vでHLD上の列の向きが逆になるので、
// 　　乗せたセグ木の演算にマージ方向がある場合などは注意して処理する。
// 　・左右の区別があるモノイドを乗せたい時はクエリで関数Sを使うとうまくいった。(cf1843F2参照)
struct HeavyLightDecomposition {
public:
    int N;
    vvi nodes;
    vector<int> sz, in, out, head, rev, par, dep;

    // 頂点vからk回遡った頂点を返す
    int la(int v, int k) {
        while (1) {
            int u = head[v];
            if (in[v] - k >= in[u]) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }

    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }

    // 頂点uからvに向かってk個進んだ頂点を返す(uはvの祖先であること)
    int next(int u, int v, int k) {
        // assert(lca(u, v) == u);
        int d = dist(u, v);
        assert(d >= k);
        return la(v, d - k);
    }

    int dist(int u, int v) const {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    template<typename E, typename Q, typename F, typename S>
    E query(
        int u, int v, const E &ti, const Q &q, const F &f, const S &s,
        bool edge = false
    ) {
        E l = ti, r = ti;
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v), swap(l, r);
            if (head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return s(f(q(in[u] + edge, in[v] + 1), l), r);
    }

    template<typename E, typename Q, typename F>
    E query(
        int u, int v, const E &ti, const Q &q, const F &f, bool edge = false
    ) {
        return query(u, v, ti, q, f, f, edge);
    }

    template<typename Q>
    void update(int u, int v, const Q &q, bool edge = false) {
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) break;
            q(in[head[v]], in[v] + 1);
        }
        q(in[u] + edge, in[v] + 1);
    }

    /* {parent, child} */
    vector<pair<int, int>> compress(vector<int> &remark) {
        auto cmp = [&](int a, int b) { return in[a] < in[b]; };
        sort(begin(remark), end(remark), cmp);
        remark.erase(unique(begin(remark), end(remark)), end(remark));
        int K = (int)remark.size();
        for (int k = 1; k < K; k++)
            remark.emplace_back(lca(remark[k - 1], remark[k]));
        sort(begin(remark), end(remark), cmp);
        remark.erase(unique(begin(remark), end(remark)), end(remark));
        vector<pair<int, int>> es;
        stack<int> st;
        for (auto &k : remark) {
            while (!st.empty() && out[st.top()] <= in[k]) st.pop();
            if (!st.empty()) es.emplace_back(st.top(), k);
            st.emplace(k);
        }
        return es;
    }

    explicit HeavyLightDecomposition(const vvi &nodes, int root = 0) : nodes(nodes), N(nodes.size()) {
        sz.assign(N, 0);
        in.assign(N, 0);
        out.assign(N, 0);
        head.assign(N, root);
        rev.assign(N, 0);
        par.assign(N, 0);
        dep.assign(N, 0);
        dfs_sz(root, -1, 0);
        int t = 0;
        dfs_hld(root, -1, t);
    }

    int operator[](int u) const {
        assert(0 <= u && u < N);
        return in[u];
    }

private:
    void dfs_sz(int idx, int p, int d) {
        dep[idx] = d;
        par[idx] = p;
        sz[idx] = 1;
        if (nodes[idx].size() && nodes[idx][0] == p) swap(nodes[idx][0], nodes[idx].back());
        for (auto &to : nodes[idx]) {
            if (to == p) continue;
            dfs_sz(to, idx, d + 1);
            sz[idx] += sz[to];
            if (sz[nodes[idx][0]] < sz[to]) swap(nodes[idx][0], to);
        }
    }

    void dfs_hld(int idx, int p, int &times) {
        in[idx] = times++;
        rev[in[idx]] = idx;
        for (auto &to : nodes[idx]) {
            if (to == p) continue;
            head[to] = (nodes[idx][0] == to ? head[idx] : to);
            dfs_hld(to, idx, times);
        }
        out[idx] = times;
    }
};
