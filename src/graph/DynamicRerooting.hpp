#pragma once
#include "../base.hpp"

// ## 動的Rerooting
// ・頂点追加、辺追加、辺削除、1点更新、全方位木DP結果取得、という激ヤバデータ構造。
// ### 使い方・注意点
// ・path clusterやpoint clusterなど理解に必須の概念の詳細はabc351_g公式解説が詳しい。
// 　ロジックを忘れてしまったらそのNyaanさんの丁寧な説明を再読すること。
// 　Static Top Treeに関する解説だが、使い方は基本的に同じのようなので。
// ・使用する5種類の関数の定義が結構難しい。以下、いくつかやってみた個人的な感想。
// 　vertex := 空の頂点。基本的には普通に頂点の情報を入れる。
// 　compress := path clusterのマージ。ここが肝。後述。
// 　rake := point clusterのマージ。全方位のf2に近い。
// 　add_edge := 辺追加。add_edge,add_vertexを合わせると全方位のf1に近い。
// 　add_vertex := 頂点追加。point clusterに新たな頂点の情報を追加する。
// ・compressを書くに当たって、下になる部分木cが持つ値が、
// 　上になる部分木pを経由した時どのように変化するかを考察する必要がある。
// 　point clusterには基本的に木DPするに当たって必要な値を持たせればいいが、
// 　path clusterにはそれに加えて、この操作で必要になる情報を持たせるイメージ。
// 　それが具体的には上下接点(boundary vertex)間の距離だったりする。
// ・辺には情報を持たせない。辺属性を扱いたい時は辺を表す超頂点を作って対応する。
// ・compressで接続する時は親側の下接点=子側の上接点ではない。
// 　間に1本辺が入って接続するイメージだと思う。
// ・Point,Pathはデフォルト初期化されてそうなので、
// 　数値で0じゃなく-INF初期化したいとかあったら、structにして初期値定義した方がよさそう。
// 参考：https://nyaannyaan.github.io/library/verify/verify-aoj-grl/aoj-grl-5-a-dynamic-rerooting.test.cpp
// 　　　https://atcoder.jp/contests/abc351/editorial/9868
// ### 使用例
// ・最遠点：GRL_5_A,GRL_5_B,tkppc2015_j
// ・総和系：abc348_e,abc359_g
// ・乗算：abc351_g

namespace DynamicRerootingImpl {
template<typename Point, Point (*rake)(const Point &, const Point &)>
struct SplayTreeforDashedEdge {
    struct Node {
        Node *l, *r, *p;
        Point key, sum;

        explicit Node(const Point &_key)
            : l(nullptr),
              r(nullptr),
              p(nullptr),
              key(_key),
              sum(_key) {
        }
    };

    SplayTreeforDashedEdge() {
    }

    using NP = Node *;

    void rotr(NP t) {
        NP x = t->p, y = x->p;
        if ((x->l = t->r)) t->r->p = x;
        t->r = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
        }
    }

    void rotl(NP t) {
        NP x = t->p, y = x->p;
        if ((x->r = t->l)) t->l->p = x;
        t->l = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
        }
    }

    void update(NP t) {
        t->sum = t->key;
        if (t->l) t->sum = rake(t->sum, t->l->sum);
        if (t->r) t->sum = rake(t->sum, t->r->sum);
    }

    NP get_right(NP t) {
        while (t->r) t = t->r;
        return t;
    }

    NP alloc(const Point &v) {
        auto t = new Node(v);
        update(t);
        return t;
    }

    void splay(NP t) {
        while (t->p) {
            NP q = t->p;
            if (!q->p) {
                if (q->l == t) rotr(t);
                else rotl(t);
            } else {
                NP r = q->p;
                if (r->l == q) {
                    if (q->l == t) rotr(q), rotr(t);
                    else rotl(t), rotr(t);
                } else {
                    if (q->r == t) rotl(q), rotl(t);
                    else rotr(t), rotl(t);
                }
            }
        }
    }

    NP insert(NP t, const Point &v) {
        if (not t) {
            t = alloc(v);
            return t;
        } else {
            NP cur = get_right(t), z = alloc(v);
            splay(cur);
            z->p = cur;
            cur->r = z;
            update(cur);
            splay(z);
            return z;
        }
    }

    NP erase(NP t) {
        splay(t);
        NP x = t->l, y = t->r;
        delete t;
        if (not x) {
            t = y;
            if (t) t->p = nullptr;
        } else if (not y) {
            t = x;
            t->p = nullptr;
        } else {
            x->p = nullptr;
            t = get_right(x);
            splay(t);
            t->r = y;
            y->p = t;
            update(t);
        }
        return t;
    }
};

template<
    typename Path, typename Point, typename Info, Path (*vertex)(const Info &),
    Path (*compress)(const Path &, const Path &),
    Point (*rake)(const Point &, const Point &),
    Point (*add_edge)(const Path &),
    Path (*add_vertex)(const Point &, const Info &)>
struct TopTree {
private:
    struct Node {
        Node *l, *r, *p;
        Info info;
        Path key, sum, mus;
        typename SplayTreeforDashedEdge<Point, rake>::Node *light, *belong;
        bool rev;

        bool is_root() const {
            return not p or (p->l != this and p->r != this);
        }

        explicit Node(const Info _info)
            : l(nullptr),
              r(nullptr),
              p(nullptr),
              info(_info),
              light(nullptr),
              belong(nullptr),
              rev(false) {
        }
    };

public:
    using NP = Node *;
    SplayTreeforDashedEdge<Point, rake> splay_tree;

private:
    void toggle(NP t) {
        swap(t->l, t->r);
        swap(t->sum, t->mus);
        t->rev ^= true;
    }

    void rotr(NP t) {
        NP x = t->p, y = x->p;
        push(x), push(t);
        if ((x->l = t->r)) t->r->p = x;
        t->r = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
        }
    }

    void rotl(NP t) {
        NP x = t->p, y = x->p;
        push(x), push(t);
        if ((x->r = t->l)) t->l->p = x;
        t->l = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
        }
    }

public:
    TopTree() : splay_tree{} {
    }

    void push(NP t) {
        if (t->rev) {
            if (t->l) toggle(t->l);
            if (t->r) toggle(t->r);
            t->rev = false;
        }
    }

    void push_rev(NP t) {
        if (t->rev) {
            if (t->l) toggle(t->l);
            if (t->r) toggle(t->r);
            t->rev = false;
        }
    }

    void update(NP t) {
        Path key =
            t->light ? add_vertex(t->light->sum, t->info) : vertex(t->info);
        Path sum = key, mus = key;
        if (t->l)
            sum = compress(t->l->sum, sum), mus = compress(mus, t->l->mus);
        if (t->r)
            sum = compress(sum, t->r->sum), mus = compress(t->r->mus, mus);
        t->key = key, t->sum = sum, t->mus = mus;
    }

    void splay(NP t) {
        push(t);
        {
            NP rot = t;
            while (not rot->is_root()) rot = rot->p;
            t->belong = rot->belong;
            if (t != rot) rot->belong = nullptr;
        }
        while (not t->is_root()) {
            NP q = t->p;
            if (q->is_root()) {
                push_rev(q), push_rev(t);
                if (q->l == t) rotr(t);
                else rotl(t);
            } else {
                NP r = q->p;
                push_rev(r), push_rev(q), push_rev(t);
                if (r->l == q) {
                    if (q->l == t) rotr(q), rotr(t);
                    else rotl(t), rotr(t);
                } else {
                    if (q->r == t) rotl(q), rotl(t);
                    else rotr(t), rotl(t);
                }
            }
        }
    }

    NP expose(NP t) {
        NP rp = nullptr;
        for (NP cur = t; cur; cur = cur->p) {
            splay(cur);
            if (cur->r) {
                cur->light =
                    splay_tree.insert(cur->light, add_edge(cur->r->sum));
                cur->r->belong = cur->light;
            }
            cur->r = rp;
            if (cur->r) {
                splay_tree.splay(cur->r->belong);
                push(cur->r);
                cur->light = splay_tree.erase(cur->r->belong);
            }
            update(cur);
            rp = cur;
        }
        splay(t);
        return rp;
    }

    void link(NP child, NP parent) {
        expose(parent);
        expose(child);
        child->p = parent;
        parent->r = child;
        update(parent);
    }

    void cut(NP child) {
        expose(child);
        NP parent = child->l;
        child->l = nullptr;
        parent->p = nullptr;
        update(child);
    }

    void evert(NP t) {
        expose(t);
        toggle(t);
        push(t);
    }

    NP alloc(const Info &info) {
        NP t = new Node(info);
        update(t);
        return t;
    }

    bool is_connected(NP u, NP v) {
        expose(u), expose(v);
        return u == v or u->p;
    }

    NP lca(NP u, NP v) {
        if (not is_connected(u, v)) return nullptr;
        expose(u);
        return expose(v);
    }

    void set_key(NP t, const Info &v) {
        expose(t);
        t->info = v;
        update(t);
    }

    // u を根とする sum
    Path query(NP u) {
        evert(u);
        return u->sum;
    }

    // root を根, u を部分木の根とする sum
    Path query_subtree(NP root, NP u) {
        evert(root);
        expose(u);
        NP l = u->l;
        u->l = nullptr;
        update(u);
        auto ret = u->sum;
        u->l = l;
        update(u);
        return ret;
    }
};

template<
    typename Path, typename Point, typename Info, Path (*vertex)(const Info &),
    Path (*compress)(const Path &, const Path &),
    Point (*rake)(const Point &, const Point &),
    Point (*Add_edge)(const Path &),
    Path (*_add_vertex)(const Point &, const Info &)>
struct DynamicRerooting {
    int n;
    TopTree<Path, Point, Info, vertex, compress, rake, Add_edge, _add_vertex> tt;
    using NP = typename decltype(tt)::NP;
    vector<NP> vs;

    DynamicRerooting(int _n, const vector<Info> &info) : n(_n), vs(n) {
        for (int i = 0; i < n; i++) vs[i] = tt.alloc(info[i]);
    }
    DynamicRerooting() : n(0) {}

    // グラフに頂点を追加
    void add_vertex(Info info) {
        vs.pb(tt.alloc(info));
        n++;
    }
    // u-v 間に辺を追加
    void add_edge(int u, int v) {
        tt.evert(vs[u]);
        tt.link(vs[u], vs[v]);
    }
    // u-v 間の辺を削除
    void remove_edge(int u, int v) {
        tt.evert(vs[u]);
        tt.cut(vs[v]);
    }
    // 頂点 u の情報を取得
    Info get_info(int u) {
        return vs[u]->info;
    }
    // 頂点 u の情報を設定
    void set_info(int u, const Info &info) {
        tt.set_key(vs[u], info);
    }
    // 頂点 u を根とするクエリ
    Path query(int u) {
        return tt.query(vs[u]);
    }
    // 頂点 root を根, 頂点 u を部分木の根とするクエリ
    Path query_subtree(int root, int u) {
        return tt.query_subtree(vs[root], vs[u]);
    }
};

} // namespace DynamicRerootingImpl

using DynamicRerootingImpl::DynamicRerooting;
