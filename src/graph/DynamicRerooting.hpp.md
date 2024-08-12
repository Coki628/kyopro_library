---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc351/editorial/9868
    - https://nyaannyaan.github.io/library/verify/verify-aoj-grl/aoj-grl-5-a-dynamic-rerooting.test.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/graph/DynamicRerooting.hpp\"\n\n// ## \u52D5\u7684\
    Rerooting\n// \u30FB\u9802\u70B9\u8FFD\u52A0\u3001\u8FBA\u8FFD\u52A0\u3001\u8FBA\
    \u524A\u9664\u30011\u70B9\u66F4\u65B0\u3001\u5168\u65B9\u4F4D\u6728DP\u7D50\u679C\
    \u53D6\u5F97\u3001\u3068\u3044\u3046\u6FC0\u30E4\u30D0\u30C7\u30FC\u30BF\u69CB\
    \u9020\u3002\n// ### \u4F7F\u3044\u65B9\u30FB\u6CE8\u610F\u70B9\n// \u30FBpath\
    \ cluster\u3084point cluster\u306A\u3069\u7406\u89E3\u306B\u5FC5\u9808\u306E\u6982\
    \u5FF5\u306E\u8A73\u7D30\u306Fabc351_g\u516C\u5F0F\u89E3\u8AAC\u304C\u8A73\u3057\
    \u3044\u3002\n// \u3000\u30ED\u30B8\u30C3\u30AF\u3092\u5FD8\u308C\u3066\u3057\u307E\
    \u3063\u305F\u3089\u305D\u306ENyaan\u3055\u3093\u306E\u4E01\u5BE7\u306A\u8AAC\u660E\
    \u3092\u518D\u8AAD\u3059\u308B\u3053\u3068\u3002\n// \u3000Static Top Tree\u306B\
    \u95A2\u3059\u308B\u89E3\u8AAC\u3060\u304C\u3001\u4F7F\u3044\u65B9\u306F\u57FA\
    \u672C\u7684\u306B\u540C\u3058\u306E\u3088\u3046\u306A\u306E\u3067\u3002\n// \u30FB\
    \u4F7F\u7528\u3059\u308B5\u7A2E\u985E\u306E\u95A2\u6570\u306E\u5B9A\u7FA9\u304C\
    \u7D50\u69CB\u96E3\u3057\u3044\u3002\u4EE5\u4E0B\u3001\u3044\u304F\u3064\u304B\
    \u3084\u3063\u3066\u307F\u305F\u500B\u4EBA\u7684\u306A\u611F\u60F3\u3002\n// \u3000\
    vertex := \u7A7A\u306E\u9802\u70B9\u3002\u57FA\u672C\u7684\u306B\u306F\u666E\u901A\
    \u306B\u9802\u70B9\u306E\u60C5\u5831\u3092\u5165\u308C\u308B\u3002\n// \u3000\
    compress := path cluster\u306E\u30DE\u30FC\u30B8\u3002\u3053\u3053\u304C\u809D\
    \u3002\u5F8C\u8FF0\u3002\n// \u3000rake := point cluster\u306E\u30DE\u30FC\u30B8\
    \u3002\u5168\u65B9\u4F4D\u306Ef2\u306B\u8FD1\u3044\u3002\n// \u3000add_edge :=\
    \ \u8FBA\u8FFD\u52A0\u3002add_edge,add_vertex\u3092\u5408\u308F\u305B\u308B\u3068\
    \u5168\u65B9\u4F4D\u306Ef1\u306B\u8FD1\u3044\u3002\n// \u3000add_vertex := \u9802\
    \u70B9\u8FFD\u52A0\u3002point cluster\u306B\u65B0\u305F\u306A\u9802\u70B9\u306E\
    \u60C5\u5831\u3092\u8FFD\u52A0\u3059\u308B\u3002\n// \u30FBcompress\u3092\u66F8\
    \u304F\u306B\u5F53\u305F\u3063\u3066\u3001\u4E0B\u306B\u306A\u308B\u90E8\u5206\
    \u6728c\u304C\u6301\u3064\u5024\u304C\u3001\n// \u3000\u4E0A\u306B\u306A\u308B\
    \u90E8\u5206\u6728p\u3092\u7D4C\u7531\u3057\u305F\u6642\u3069\u306E\u3088\u3046\
    \u306B\u5909\u5316\u3059\u308B\u304B\u3092\u8003\u5BDF\u3059\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\u3002\n// \u3000point cluster\u306B\u306F\u57FA\u672C\u7684\
    \u306B\u6728DP\u3059\u308B\u306B\u5F53\u305F\u3063\u3066\u5FC5\u8981\u306A\u5024\
    \u3092\u6301\u305F\u305B\u308C\u3070\u3044\u3044\u304C\u3001\n// \u3000path cluster\u306B\
    \u306F\u305D\u308C\u306B\u52A0\u3048\u3066\u3001\u3053\u306E\u64CD\u4F5C\u3067\
    \u5FC5\u8981\u306B\u306A\u308B\u60C5\u5831\u3092\u6301\u305F\u305B\u308B\u30A4\
    \u30E1\u30FC\u30B8\u3002\n// \u3000\u305D\u308C\u304C\u5177\u4F53\u7684\u306B\u306F\
    \u4E0A\u4E0B\u63A5\u70B9(boundary vertex)\u9593\u306E\u8DDD\u96E2\u3060\u3063\u305F\
    \u308A\u3059\u308B\u3002\n// \u30FB\u8FBA\u306B\u306F\u60C5\u5831\u3092\u6301\u305F\
    \u305B\u306A\u3044\u3002\u8FBA\u5C5E\u6027\u3092\u6271\u3044\u305F\u3044\u6642\
    \u306F\u8FBA\u3092\u8868\u3059\u8D85\u9802\u70B9\u3092\u4F5C\u3063\u3066\u5BFE\
    \u5FDC\u3059\u308B\u3002\n// \u30FBcompress\u3067\u63A5\u7D9A\u3059\u308B\u6642\
    \u306F\u89AA\u5074\u306E\u4E0B\u63A5\u70B9=\u5B50\u5074\u306E\u4E0A\u63A5\u70B9\
    \u3067\u306F\u306A\u3044\u3002\n// \u3000\u9593\u306B1\u672C\u8FBA\u304C\u5165\
    \u3063\u3066\u63A5\u7D9A\u3059\u308B\u30A4\u30E1\u30FC\u30B8\u3060\u3068\u601D\
    \u3046\u3002\n// \u30FBPoint,Path\u306F\u30C7\u30D5\u30A9\u30EB\u30C8\u521D\u671F\
    \u5316\u3055\u308C\u3066\u305D\u3046\u306A\u306E\u3067\u3001\n// \u3000\u6570\u5024\
    \u30670\u3058\u3083\u306A\u304F-INF\u521D\u671F\u5316\u3057\u305F\u3044\u3068\u304B\
    \u3042\u3063\u305F\u3089\u3001struct\u306B\u3057\u3066\u521D\u671F\u5024\u5B9A\
    \u7FA9\u3057\u305F\u65B9\u304C\u3088\u3055\u305D\u3046\u3002\n// \u53C2\u8003\uFF1A\
    https://nyaannyaan.github.io/library/verify/verify-aoj-grl/aoj-grl-5-a-dynamic-rerooting.test.cpp\n\
    // \u3000\u3000\u3000https://atcoder.jp/contests/abc351/editorial/9868\n// ###\
    \ \u4F7F\u7528\u4F8B\n// \u30FB\u6700\u9060\u70B9\uFF1AGRL_5_A,GRL_5_B,tkppc2015_j\n\
    // \u30FB\u7DCF\u548C\u7CFB\uFF1Aabc348_e,abc359_g\n// \u30FB\u4E57\u7B97\uFF1A\
    abc351_g\n\nnamespace DynamicRerootingImpl {\ntemplate<typename Point, Point (*rake)(const\
    \ Point &, const Point &)>\nstruct SplayTreeforDashedEdge {\n    struct Node {\n\
    \        Node *l, *r, *p;\n        Point key, sum;\n\n        explicit Node(const\
    \ Point &_key)\n            : l(nullptr),\n              r(nullptr),\n       \
    \       p(nullptr),\n              key(_key),\n              sum(_key) {\n   \
    \     }\n    };\n\n    SplayTreeforDashedEdge() {\n    }\n\n    using NP = Node\
    \ *;\n\n    void rotr(NP t) {\n        NP x = t->p, y = x->p;\n        if ((x->l\
    \ = t->r)) t->r->p = x;\n        t->r = x, x->p = t;\n        update(x), update(t);\n\
    \        if ((t->p = y)) {\n            if (y->l == x) y->l = t;\n           \
    \ if (y->r == x) y->r = t;\n        }\n    }\n\n    void rotl(NP t) {\n      \
    \  NP x = t->p, y = x->p;\n        if ((x->r = t->l)) t->l->p = x;\n        t->l\
    \ = x, x->p = t;\n        update(x), update(t);\n        if ((t->p = y)) {\n \
    \           if (y->l == x) y->l = t;\n            if (y->r == x) y->r = t;\n \
    \       }\n    }\n\n    void update(NP t) {\n        t->sum = t->key;\n      \
    \  if (t->l) t->sum = rake(t->sum, t->l->sum);\n        if (t->r) t->sum = rake(t->sum,\
    \ t->r->sum);\n    }\n\n    NP get_right(NP t) {\n        while (t->r) t = t->r;\n\
    \        return t;\n    }\n\n    NP alloc(const Point &v) {\n        auto t =\
    \ new Node(v);\n        update(t);\n        return t;\n    }\n\n    void splay(NP\
    \ t) {\n        while (t->p) {\n            NP q = t->p;\n            if (!q->p)\
    \ {\n                if (q->l == t) rotr(t);\n                else rotl(t);\n\
    \            } else {\n                NP r = q->p;\n                if (r->l\
    \ == q) {\n                    if (q->l == t) rotr(q), rotr(t);\n            \
    \        else rotl(t), rotr(t);\n                } else {\n                  \
    \  if (q->r == t) rotl(q), rotl(t);\n                    else rotr(t), rotl(t);\n\
    \                }\n            }\n        }\n    }\n\n    NP insert(NP t, const\
    \ Point &v) {\n        if (not t) {\n            t = alloc(v);\n            return\
    \ t;\n        } else {\n            NP cur = get_right(t), z = alloc(v);\n   \
    \         splay(cur);\n            z->p = cur;\n            cur->r = z;\n    \
    \        update(cur);\n            splay(z);\n            return z;\n        }\n\
    \    }\n\n    NP erase(NP t) {\n        splay(t);\n        NP x = t->l, y = t->r;\n\
    \        delete t;\n        if (not x) {\n            t = y;\n            if (t)\
    \ t->p = nullptr;\n        } else if (not y) {\n            t = x;\n         \
    \   t->p = nullptr;\n        } else {\n            x->p = nullptr;\n         \
    \   t = get_right(x);\n            splay(t);\n            t->r = y;\n        \
    \    y->p = t;\n            update(t);\n        }\n        return t;\n    }\n\
    };\n\ntemplate<\n    typename Path, typename Point, typename Info, Path (*vertex)(const\
    \ Info &),\n    Path (*compress)(const Path &, const Path &),\n    Point (*rake)(const\
    \ Point &, const Point &),\n    Point (*add_edge)(const Path &),\n    Path (*add_vertex)(const\
    \ Point &, const Info &)>\nstruct TopTree {\nprivate:\n    struct Node {\n   \
    \     Node *l, *r, *p;\n        Info info;\n        Path key, sum, mus;\n    \
    \    typename SplayTreeforDashedEdge<Point, rake>::Node *light, *belong;\n   \
    \     bool rev;\n\n        bool is_root() const {\n            return not p or\
    \ (p->l != this and p->r != this);\n        }\n\n        explicit Node(const Info\
    \ _info)\n            : l(nullptr),\n              r(nullptr),\n             \
    \ p(nullptr),\n              info(_info),\n              light(nullptr),\n   \
    \           belong(nullptr),\n              rev(false) {\n        }\n    };\n\n\
    public:\n    using NP = Node *;\n    SplayTreeforDashedEdge<Point, rake> splay_tree;\n\
    \nprivate:\n    void toggle(NP t) {\n        swap(t->l, t->r);\n        swap(t->sum,\
    \ t->mus);\n        t->rev ^= true;\n    }\n\n    void rotr(NP t) {\n        NP\
    \ x = t->p, y = x->p;\n        push(x), push(t);\n        if ((x->l = t->r)) t->r->p\
    \ = x;\n        t->r = x, x->p = t;\n        update(x), update(t);\n        if\
    \ ((t->p = y)) {\n            if (y->l == x) y->l = t;\n            if (y->r ==\
    \ x) y->r = t;\n        }\n    }\n\n    void rotl(NP t) {\n        NP x = t->p,\
    \ y = x->p;\n        push(x), push(t);\n        if ((x->r = t->l)) t->l->p = x;\n\
    \        t->l = x, x->p = t;\n        update(x), update(t);\n        if ((t->p\
    \ = y)) {\n            if (y->l == x) y->l = t;\n            if (y->r == x) y->r\
    \ = t;\n        }\n    }\n\npublic:\n    TopTree() : splay_tree{} {\n    }\n\n\
    \    void push(NP t) {\n        if (t->rev) {\n            if (t->l) toggle(t->l);\n\
    \            if (t->r) toggle(t->r);\n            t->rev = false;\n        }\n\
    \    }\n\n    void push_rev(NP t) {\n        if (t->rev) {\n            if (t->l)\
    \ toggle(t->l);\n            if (t->r) toggle(t->r);\n            t->rev = false;\n\
    \        }\n    }\n\n    void update(NP t) {\n        Path key =\n           \
    \ t->light ? add_vertex(t->light->sum, t->info) : vertex(t->info);\n        Path\
    \ sum = key, mus = key;\n        if (t->l)\n            sum = compress(t->l->sum,\
    \ sum), mus = compress(mus, t->l->mus);\n        if (t->r)\n            sum =\
    \ compress(sum, t->r->sum), mus = compress(t->r->mus, mus);\n        t->key =\
    \ key, t->sum = sum, t->mus = mus;\n    }\n\n    void splay(NP t) {\n        push(t);\n\
    \        {\n            NP rot = t;\n            while (not rot->is_root()) rot\
    \ = rot->p;\n            t->belong = rot->belong;\n            if (t != rot) rot->belong\
    \ = nullptr;\n        }\n        while (not t->is_root()) {\n            NP q\
    \ = t->p;\n            if (q->is_root()) {\n                push_rev(q), push_rev(t);\n\
    \                if (q->l == t) rotr(t);\n                else rotl(t);\n    \
    \        } else {\n                NP r = q->p;\n                push_rev(r),\
    \ push_rev(q), push_rev(t);\n                if (r->l == q) {\n              \
    \      if (q->l == t) rotr(q), rotr(t);\n                    else rotl(t), rotr(t);\n\
    \                } else {\n                    if (q->r == t) rotl(q), rotl(t);\n\
    \                    else rotr(t), rotl(t);\n                }\n            }\n\
    \        }\n    }\n\n    NP expose(NP t) {\n        NP rp = nullptr;\n       \
    \ for (NP cur = t; cur; cur = cur->p) {\n            splay(cur);\n           \
    \ if (cur->r) {\n                cur->light =\n                    splay_tree.insert(cur->light,\
    \ add_edge(cur->r->sum));\n                cur->r->belong = cur->light;\n    \
    \        }\n            cur->r = rp;\n            if (cur->r) {\n            \
    \    splay_tree.splay(cur->r->belong);\n                push(cur->r);\n      \
    \          cur->light = splay_tree.erase(cur->r->belong);\n            }\n   \
    \         update(cur);\n            rp = cur;\n        }\n        splay(t);\n\
    \        return rp;\n    }\n\n    void link(NP child, NP parent) {\n        expose(parent);\n\
    \        expose(child);\n        child->p = parent;\n        parent->r = child;\n\
    \        update(parent);\n    }\n\n    void cut(NP child) {\n        expose(child);\n\
    \        NP parent = child->l;\n        child->l = nullptr;\n        parent->p\
    \ = nullptr;\n        update(child);\n    }\n\n    void evert(NP t) {\n      \
    \  expose(t);\n        toggle(t);\n        push(t);\n    }\n\n    NP alloc(const\
    \ Info &info) {\n        NP t = new Node(info);\n        update(t);\n        return\
    \ t;\n    }\n\n    bool is_connected(NP u, NP v) {\n        expose(u), expose(v);\n\
    \        return u == v or u->p;\n    }\n\n    NP lca(NP u, NP v) {\n        if\
    \ (not is_connected(u, v)) return nullptr;\n        expose(u);\n        return\
    \ expose(v);\n    }\n\n    void set_key(NP t, const Info &v) {\n        expose(t);\n\
    \        t->info = v;\n        update(t);\n    }\n\n    // u \u3092\u6839\u3068\
    \u3059\u308B sum\n    Path query(NP u) {\n        evert(u);\n        return u->sum;\n\
    \    }\n\n    // root \u3092\u6839, u \u3092\u90E8\u5206\u6728\u306E\u6839\u3068\
    \u3059\u308B sum\n    Path query_subtree(NP root, NP u) {\n        evert(root);\n\
    \        expose(u);\n        NP l = u->l;\n        u->l = nullptr;\n        update(u);\n\
    \        auto ret = u->sum;\n        u->l = l;\n        update(u);\n        return\
    \ ret;\n    }\n};\n\ntemplate<\n    typename Path, typename Point, typename Info,\
    \ Path (*vertex)(const Info &),\n    Path (*compress)(const Path &, const Path\
    \ &),\n    Point (*rake)(const Point &, const Point &),\n    Point (*Add_edge)(const\
    \ Path &),\n    Path (*_add_vertex)(const Point &, const Info &)>\nstruct DynamicRerooting\
    \ {\n    int n;\n    TopTree<Path, Point, Info, vertex, compress, rake, Add_edge,\
    \ _add_vertex> tt;\n    using NP = typename decltype(tt)::NP;\n    vector<NP>\
    \ vs;\n\n    DynamicRerooting(int _n, const vector<Info> &info) : n(_n), vs(n)\
    \ {\n        for (int i = 0; i < n; i++) vs[i] = tt.alloc(info[i]);\n    }\n \
    \   DynamicRerooting() : n(0) {}\n\n    // \u30B0\u30E9\u30D5\u306B\u9802\u70B9\
    \u3092\u8FFD\u52A0\n    void add_vertex(Info info) {\n        vs.pb(tt.alloc(info));\n\
    \        n++;\n    }\n    // u-v \u9593\u306B\u8FBA\u3092\u8FFD\u52A0\n    void\
    \ add_edge(int u, int v) {\n        tt.evert(vs[u]);\n        tt.link(vs[u], vs[v]);\n\
    \    }\n    // u-v \u9593\u306E\u8FBA\u3092\u524A\u9664\n    void remove_edge(int\
    \ u, int v) {\n        tt.evert(vs[u]);\n        tt.cut(vs[v]);\n    }\n    //\
    \ \u9802\u70B9 u \u306E\u60C5\u5831\u3092\u53D6\u5F97\n    Info get_info(int u)\
    \ {\n        return vs[u]->info;\n    }\n    // \u9802\u70B9 u \u306E\u60C5\u5831\
    \u3092\u8A2D\u5B9A\n    void set_info(int u, const Info &info) {\n        tt.set_key(vs[u],\
    \ info);\n    }\n    // \u9802\u70B9 u \u3092\u6839\u3068\u3059\u308B\u30AF\u30A8\
    \u30EA\n    Path query(int u) {\n        return tt.query(vs[u]);\n    }\n    //\
    \ \u9802\u70B9 root \u3092\u6839, \u9802\u70B9 u \u3092\u90E8\u5206\u6728\u306E\
    \u6839\u3068\u3059\u308B\u30AF\u30A8\u30EA\n    Path query_subtree(int root, int\
    \ u) {\n        return tt.query_subtree(vs[root], vs[u]);\n    }\n};\n\n} // namespace\
    \ DynamicRerootingImpl\n\nusing DynamicRerootingImpl::DynamicRerooting;\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// ## \u52D5\u7684Rerooting\n//\
    \ \u30FB\u9802\u70B9\u8FFD\u52A0\u3001\u8FBA\u8FFD\u52A0\u3001\u8FBA\u524A\u9664\
    \u30011\u70B9\u66F4\u65B0\u3001\u5168\u65B9\u4F4D\u6728DP\u7D50\u679C\u53D6\u5F97\
    \u3001\u3068\u3044\u3046\u6FC0\u30E4\u30D0\u30C7\u30FC\u30BF\u69CB\u9020\u3002\
    \n// ### \u4F7F\u3044\u65B9\u30FB\u6CE8\u610F\u70B9\n// \u30FBpath cluster\u3084\
    point cluster\u306A\u3069\u7406\u89E3\u306B\u5FC5\u9808\u306E\u6982\u5FF5\u306E\
    \u8A73\u7D30\u306Fabc351_g\u516C\u5F0F\u89E3\u8AAC\u304C\u8A73\u3057\u3044\u3002\
    \n// \u3000\u30ED\u30B8\u30C3\u30AF\u3092\u5FD8\u308C\u3066\u3057\u307E\u3063\u305F\
    \u3089\u305D\u306ENyaan\u3055\u3093\u306E\u4E01\u5BE7\u306A\u8AAC\u660E\u3092\u518D\
    \u8AAD\u3059\u308B\u3053\u3068\u3002\n// \u3000Static Top Tree\u306B\u95A2\u3059\
    \u308B\u89E3\u8AAC\u3060\u304C\u3001\u4F7F\u3044\u65B9\u306F\u57FA\u672C\u7684\
    \u306B\u540C\u3058\u306E\u3088\u3046\u306A\u306E\u3067\u3002\n// \u30FB\u4F7F\u7528\
    \u3059\u308B5\u7A2E\u985E\u306E\u95A2\u6570\u306E\u5B9A\u7FA9\u304C\u7D50\u69CB\
    \u96E3\u3057\u3044\u3002\u4EE5\u4E0B\u3001\u3044\u304F\u3064\u304B\u3084\u3063\
    \u3066\u307F\u305F\u500B\u4EBA\u7684\u306A\u611F\u60F3\u3002\n// \u3000vertex\
    \ := \u7A7A\u306E\u9802\u70B9\u3002\u57FA\u672C\u7684\u306B\u306F\u666E\u901A\u306B\
    \u9802\u70B9\u306E\u60C5\u5831\u3092\u5165\u308C\u308B\u3002\n// \u3000compress\
    \ := path cluster\u306E\u30DE\u30FC\u30B8\u3002\u3053\u3053\u304C\u809D\u3002\u5F8C\
    \u8FF0\u3002\n// \u3000rake := point cluster\u306E\u30DE\u30FC\u30B8\u3002\u5168\
    \u65B9\u4F4D\u306Ef2\u306B\u8FD1\u3044\u3002\n// \u3000add_edge := \u8FBA\u8FFD\
    \u52A0\u3002add_edge,add_vertex\u3092\u5408\u308F\u305B\u308B\u3068\u5168\u65B9\
    \u4F4D\u306Ef1\u306B\u8FD1\u3044\u3002\n// \u3000add_vertex := \u9802\u70B9\u8FFD\
    \u52A0\u3002point cluster\u306B\u65B0\u305F\u306A\u9802\u70B9\u306E\u60C5\u5831\
    \u3092\u8FFD\u52A0\u3059\u308B\u3002\n// \u30FBcompress\u3092\u66F8\u304F\u306B\
    \u5F53\u305F\u3063\u3066\u3001\u4E0B\u306B\u306A\u308B\u90E8\u5206\u6728c\u304C\
    \u6301\u3064\u5024\u304C\u3001\n// \u3000\u4E0A\u306B\u306A\u308B\u90E8\u5206\u6728\
    p\u3092\u7D4C\u7531\u3057\u305F\u6642\u3069\u306E\u3088\u3046\u306B\u5909\u5316\
    \u3059\u308B\u304B\u3092\u8003\u5BDF\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \u3002\n// \u3000point cluster\u306B\u306F\u57FA\u672C\u7684\u306B\u6728DP\u3059\
    \u308B\u306B\u5F53\u305F\u3063\u3066\u5FC5\u8981\u306A\u5024\u3092\u6301\u305F\
    \u305B\u308C\u3070\u3044\u3044\u304C\u3001\n// \u3000path cluster\u306B\u306F\u305D\
    \u308C\u306B\u52A0\u3048\u3066\u3001\u3053\u306E\u64CD\u4F5C\u3067\u5FC5\u8981\
    \u306B\u306A\u308B\u60C5\u5831\u3092\u6301\u305F\u305B\u308B\u30A4\u30E1\u30FC\
    \u30B8\u3002\n// \u3000\u305D\u308C\u304C\u5177\u4F53\u7684\u306B\u306F\u4E0A\u4E0B\
    \u63A5\u70B9(boundary vertex)\u9593\u306E\u8DDD\u96E2\u3060\u3063\u305F\u308A\u3059\
    \u308B\u3002\n// \u30FB\u8FBA\u306B\u306F\u60C5\u5831\u3092\u6301\u305F\u305B\u306A\
    \u3044\u3002\u8FBA\u5C5E\u6027\u3092\u6271\u3044\u305F\u3044\u6642\u306F\u8FBA\
    \u3092\u8868\u3059\u8D85\u9802\u70B9\u3092\u4F5C\u3063\u3066\u5BFE\u5FDC\u3059\
    \u308B\u3002\n// \u30FBcompress\u3067\u63A5\u7D9A\u3059\u308B\u6642\u306F\u89AA\
    \u5074\u306E\u4E0B\u63A5\u70B9=\u5B50\u5074\u306E\u4E0A\u63A5\u70B9\u3067\u306F\
    \u306A\u3044\u3002\n// \u3000\u9593\u306B1\u672C\u8FBA\u304C\u5165\u3063\u3066\
    \u63A5\u7D9A\u3059\u308B\u30A4\u30E1\u30FC\u30B8\u3060\u3068\u601D\u3046\u3002\
    \n// \u30FBPoint,Path\u306F\u30C7\u30D5\u30A9\u30EB\u30C8\u521D\u671F\u5316\u3055\
    \u308C\u3066\u305D\u3046\u306A\u306E\u3067\u3001\n// \u3000\u6570\u5024\u3067\
    0\u3058\u3083\u306A\u304F-INF\u521D\u671F\u5316\u3057\u305F\u3044\u3068\u304B\u3042\
    \u3063\u305F\u3089\u3001struct\u306B\u3057\u3066\u521D\u671F\u5024\u5B9A\u7FA9\
    \u3057\u305F\u65B9\u304C\u3088\u3055\u305D\u3046\u3002\n// \u53C2\u8003\uFF1A\
    https://nyaannyaan.github.io/library/verify/verify-aoj-grl/aoj-grl-5-a-dynamic-rerooting.test.cpp\n\
    // \u3000\u3000\u3000https://atcoder.jp/contests/abc351/editorial/9868\n// ###\
    \ \u4F7F\u7528\u4F8B\n// \u30FB\u6700\u9060\u70B9\uFF1AGRL_5_A,GRL_5_B,tkppc2015_j\n\
    // \u30FB\u7DCF\u548C\u7CFB\uFF1Aabc348_e,abc359_g\n// \u30FB\u4E57\u7B97\uFF1A\
    abc351_g\n\nnamespace DynamicRerootingImpl {\ntemplate<typename Point, Point (*rake)(const\
    \ Point &, const Point &)>\nstruct SplayTreeforDashedEdge {\n    struct Node {\n\
    \        Node *l, *r, *p;\n        Point key, sum;\n\n        explicit Node(const\
    \ Point &_key)\n            : l(nullptr),\n              r(nullptr),\n       \
    \       p(nullptr),\n              key(_key),\n              sum(_key) {\n   \
    \     }\n    };\n\n    SplayTreeforDashedEdge() {\n    }\n\n    using NP = Node\
    \ *;\n\n    void rotr(NP t) {\n        NP x = t->p, y = x->p;\n        if ((x->l\
    \ = t->r)) t->r->p = x;\n        t->r = x, x->p = t;\n        update(x), update(t);\n\
    \        if ((t->p = y)) {\n            if (y->l == x) y->l = t;\n           \
    \ if (y->r == x) y->r = t;\n        }\n    }\n\n    void rotl(NP t) {\n      \
    \  NP x = t->p, y = x->p;\n        if ((x->r = t->l)) t->l->p = x;\n        t->l\
    \ = x, x->p = t;\n        update(x), update(t);\n        if ((t->p = y)) {\n \
    \           if (y->l == x) y->l = t;\n            if (y->r == x) y->r = t;\n \
    \       }\n    }\n\n    void update(NP t) {\n        t->sum = t->key;\n      \
    \  if (t->l) t->sum = rake(t->sum, t->l->sum);\n        if (t->r) t->sum = rake(t->sum,\
    \ t->r->sum);\n    }\n\n    NP get_right(NP t) {\n        while (t->r) t = t->r;\n\
    \        return t;\n    }\n\n    NP alloc(const Point &v) {\n        auto t =\
    \ new Node(v);\n        update(t);\n        return t;\n    }\n\n    void splay(NP\
    \ t) {\n        while (t->p) {\n            NP q = t->p;\n            if (!q->p)\
    \ {\n                if (q->l == t) rotr(t);\n                else rotl(t);\n\
    \            } else {\n                NP r = q->p;\n                if (r->l\
    \ == q) {\n                    if (q->l == t) rotr(q), rotr(t);\n            \
    \        else rotl(t), rotr(t);\n                } else {\n                  \
    \  if (q->r == t) rotl(q), rotl(t);\n                    else rotr(t), rotl(t);\n\
    \                }\n            }\n        }\n    }\n\n    NP insert(NP t, const\
    \ Point &v) {\n        if (not t) {\n            t = alloc(v);\n            return\
    \ t;\n        } else {\n            NP cur = get_right(t), z = alloc(v);\n   \
    \         splay(cur);\n            z->p = cur;\n            cur->r = z;\n    \
    \        update(cur);\n            splay(z);\n            return z;\n        }\n\
    \    }\n\n    NP erase(NP t) {\n        splay(t);\n        NP x = t->l, y = t->r;\n\
    \        delete t;\n        if (not x) {\n            t = y;\n            if (t)\
    \ t->p = nullptr;\n        } else if (not y) {\n            t = x;\n         \
    \   t->p = nullptr;\n        } else {\n            x->p = nullptr;\n         \
    \   t = get_right(x);\n            splay(t);\n            t->r = y;\n        \
    \    y->p = t;\n            update(t);\n        }\n        return t;\n    }\n\
    };\n\ntemplate<\n    typename Path, typename Point, typename Info, Path (*vertex)(const\
    \ Info &),\n    Path (*compress)(const Path &, const Path &),\n    Point (*rake)(const\
    \ Point &, const Point &),\n    Point (*add_edge)(const Path &),\n    Path (*add_vertex)(const\
    \ Point &, const Info &)>\nstruct TopTree {\nprivate:\n    struct Node {\n   \
    \     Node *l, *r, *p;\n        Info info;\n        Path key, sum, mus;\n    \
    \    typename SplayTreeforDashedEdge<Point, rake>::Node *light, *belong;\n   \
    \     bool rev;\n\n        bool is_root() const {\n            return not p or\
    \ (p->l != this and p->r != this);\n        }\n\n        explicit Node(const Info\
    \ _info)\n            : l(nullptr),\n              r(nullptr),\n             \
    \ p(nullptr),\n              info(_info),\n              light(nullptr),\n   \
    \           belong(nullptr),\n              rev(false) {\n        }\n    };\n\n\
    public:\n    using NP = Node *;\n    SplayTreeforDashedEdge<Point, rake> splay_tree;\n\
    \nprivate:\n    void toggle(NP t) {\n        swap(t->l, t->r);\n        swap(t->sum,\
    \ t->mus);\n        t->rev ^= true;\n    }\n\n    void rotr(NP t) {\n        NP\
    \ x = t->p, y = x->p;\n        push(x), push(t);\n        if ((x->l = t->r)) t->r->p\
    \ = x;\n        t->r = x, x->p = t;\n        update(x), update(t);\n        if\
    \ ((t->p = y)) {\n            if (y->l == x) y->l = t;\n            if (y->r ==\
    \ x) y->r = t;\n        }\n    }\n\n    void rotl(NP t) {\n        NP x = t->p,\
    \ y = x->p;\n        push(x), push(t);\n        if ((x->r = t->l)) t->l->p = x;\n\
    \        t->l = x, x->p = t;\n        update(x), update(t);\n        if ((t->p\
    \ = y)) {\n            if (y->l == x) y->l = t;\n            if (y->r == x) y->r\
    \ = t;\n        }\n    }\n\npublic:\n    TopTree() : splay_tree{} {\n    }\n\n\
    \    void push(NP t) {\n        if (t->rev) {\n            if (t->l) toggle(t->l);\n\
    \            if (t->r) toggle(t->r);\n            t->rev = false;\n        }\n\
    \    }\n\n    void push_rev(NP t) {\n        if (t->rev) {\n            if (t->l)\
    \ toggle(t->l);\n            if (t->r) toggle(t->r);\n            t->rev = false;\n\
    \        }\n    }\n\n    void update(NP t) {\n        Path key =\n           \
    \ t->light ? add_vertex(t->light->sum, t->info) : vertex(t->info);\n        Path\
    \ sum = key, mus = key;\n        if (t->l)\n            sum = compress(t->l->sum,\
    \ sum), mus = compress(mus, t->l->mus);\n        if (t->r)\n            sum =\
    \ compress(sum, t->r->sum), mus = compress(t->r->mus, mus);\n        t->key =\
    \ key, t->sum = sum, t->mus = mus;\n    }\n\n    void splay(NP t) {\n        push(t);\n\
    \        {\n            NP rot = t;\n            while (not rot->is_root()) rot\
    \ = rot->p;\n            t->belong = rot->belong;\n            if (t != rot) rot->belong\
    \ = nullptr;\n        }\n        while (not t->is_root()) {\n            NP q\
    \ = t->p;\n            if (q->is_root()) {\n                push_rev(q), push_rev(t);\n\
    \                if (q->l == t) rotr(t);\n                else rotl(t);\n    \
    \        } else {\n                NP r = q->p;\n                push_rev(r),\
    \ push_rev(q), push_rev(t);\n                if (r->l == q) {\n              \
    \      if (q->l == t) rotr(q), rotr(t);\n                    else rotl(t), rotr(t);\n\
    \                } else {\n                    if (q->r == t) rotl(q), rotl(t);\n\
    \                    else rotr(t), rotl(t);\n                }\n            }\n\
    \        }\n    }\n\n    NP expose(NP t) {\n        NP rp = nullptr;\n       \
    \ for (NP cur = t; cur; cur = cur->p) {\n            splay(cur);\n           \
    \ if (cur->r) {\n                cur->light =\n                    splay_tree.insert(cur->light,\
    \ add_edge(cur->r->sum));\n                cur->r->belong = cur->light;\n    \
    \        }\n            cur->r = rp;\n            if (cur->r) {\n            \
    \    splay_tree.splay(cur->r->belong);\n                push(cur->r);\n      \
    \          cur->light = splay_tree.erase(cur->r->belong);\n            }\n   \
    \         update(cur);\n            rp = cur;\n        }\n        splay(t);\n\
    \        return rp;\n    }\n\n    void link(NP child, NP parent) {\n        expose(parent);\n\
    \        expose(child);\n        child->p = parent;\n        parent->r = child;\n\
    \        update(parent);\n    }\n\n    void cut(NP child) {\n        expose(child);\n\
    \        NP parent = child->l;\n        child->l = nullptr;\n        parent->p\
    \ = nullptr;\n        update(child);\n    }\n\n    void evert(NP t) {\n      \
    \  expose(t);\n        toggle(t);\n        push(t);\n    }\n\n    NP alloc(const\
    \ Info &info) {\n        NP t = new Node(info);\n        update(t);\n        return\
    \ t;\n    }\n\n    bool is_connected(NP u, NP v) {\n        expose(u), expose(v);\n\
    \        return u == v or u->p;\n    }\n\n    NP lca(NP u, NP v) {\n        if\
    \ (not is_connected(u, v)) return nullptr;\n        expose(u);\n        return\
    \ expose(v);\n    }\n\n    void set_key(NP t, const Info &v) {\n        expose(t);\n\
    \        t->info = v;\n        update(t);\n    }\n\n    // u \u3092\u6839\u3068\
    \u3059\u308B sum\n    Path query(NP u) {\n        evert(u);\n        return u->sum;\n\
    \    }\n\n    // root \u3092\u6839, u \u3092\u90E8\u5206\u6728\u306E\u6839\u3068\
    \u3059\u308B sum\n    Path query_subtree(NP root, NP u) {\n        evert(root);\n\
    \        expose(u);\n        NP l = u->l;\n        u->l = nullptr;\n        update(u);\n\
    \        auto ret = u->sum;\n        u->l = l;\n        update(u);\n        return\
    \ ret;\n    }\n};\n\ntemplate<\n    typename Path, typename Point, typename Info,\
    \ Path (*vertex)(const Info &),\n    Path (*compress)(const Path &, const Path\
    \ &),\n    Point (*rake)(const Point &, const Point &),\n    Point (*Add_edge)(const\
    \ Path &),\n    Path (*_add_vertex)(const Point &, const Info &)>\nstruct DynamicRerooting\
    \ {\n    int n;\n    TopTree<Path, Point, Info, vertex, compress, rake, Add_edge,\
    \ _add_vertex> tt;\n    using NP = typename decltype(tt)::NP;\n    vector<NP>\
    \ vs;\n\n    DynamicRerooting(int _n, const vector<Info> &info) : n(_n), vs(n)\
    \ {\n        for (int i = 0; i < n; i++) vs[i] = tt.alloc(info[i]);\n    }\n \
    \   DynamicRerooting() : n(0) {}\n\n    // \u30B0\u30E9\u30D5\u306B\u9802\u70B9\
    \u3092\u8FFD\u52A0\n    void add_vertex(Info info) {\n        vs.pb(tt.alloc(info));\n\
    \        n++;\n    }\n    // u-v \u9593\u306B\u8FBA\u3092\u8FFD\u52A0\n    void\
    \ add_edge(int u, int v) {\n        tt.evert(vs[u]);\n        tt.link(vs[u], vs[v]);\n\
    \    }\n    // u-v \u9593\u306E\u8FBA\u3092\u524A\u9664\n    void remove_edge(int\
    \ u, int v) {\n        tt.evert(vs[u]);\n        tt.cut(vs[v]);\n    }\n    //\
    \ \u9802\u70B9 u \u306E\u60C5\u5831\u3092\u53D6\u5F97\n    Info get_info(int u)\
    \ {\n        return vs[u]->info;\n    }\n    // \u9802\u70B9 u \u306E\u60C5\u5831\
    \u3092\u8A2D\u5B9A\n    void set_info(int u, const Info &info) {\n        tt.set_key(vs[u],\
    \ info);\n    }\n    // \u9802\u70B9 u \u3092\u6839\u3068\u3059\u308B\u30AF\u30A8\
    \u30EA\n    Path query(int u) {\n        return tt.query(vs[u]);\n    }\n    //\
    \ \u9802\u70B9 root \u3092\u6839, \u9802\u70B9 u \u3092\u90E8\u5206\u6728\u306E\
    \u6839\u3068\u3059\u308B\u30AF\u30A8\u30EA\n    Path query_subtree(int root, int\
    \ u) {\n        return tt.query_subtree(vs[root], vs[u]);\n    }\n};\n\n} // namespace\
    \ DynamicRerootingImpl\n\nusing DynamicRerootingImpl::DynamicRerooting;\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/DynamicRerooting.hpp
  requiredBy: []
  timestamp: '2024-06-28 18:15:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/DynamicRerooting.hpp
layout: document
redirect_from:
- /library/src/graph/DynamicRerooting.hpp
- /library/src/graph/DynamicRerooting.hpp.html
title: src/graph/DynamicRerooting.hpp
---
