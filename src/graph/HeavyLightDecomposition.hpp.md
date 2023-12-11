---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/AuxiliaryTree.hpp
    title: src/graph/AuxiliaryTree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\nusing vvl = vv<ll>;\n\
    using vvi = vv<int>;\nusing vvpll = vv<pll>;\nusing vvpli = vv<pli>;\nusing vvpil\
    \ = vv<pil>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa\
    \ = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n\
    #define rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb)\
    \ or (c < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a);\
    \ i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) begin(A), end(A)\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/HeavyLightDecomposition.hpp\"\
    \n\n// HL\u5206\u89E3\n// see: https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.hpp\n\
    // \u30FB\u4E3B\u306A\u4F7F\u7528\u65B9\u6CD5\u306A\u3069\n// \u3000\u30FB\u521D\
    \u671F\u5316\u5F8C\u3001\u5FD8\u308C\u305A\u306Bbuild\u3092\u547C\u3076\u3053\u3068\
    \u3002\u2192build\u306F\u521D\u671F\u5316\u306B\u542B\u3081\u305F\u3002\n// \u3000\
    \u30FB\u30D1\u30B9\u30AF\u30A8\u30EA\u306Fadd,query\u3067\u51E6\u7406\n// \u3000\
    \u30FB1\u70B9\u53D6\u5F97/\u66F4\u65B0\u306Fhld.in[x]\u3067\u53EF\u80FD\u3002\
    add,query\u306F\u547C\u3070\u306A\u304F\u3066\u3044\u3044\u3002\n// \u3000\u30FB\
    \u8FBA\u5C5E\u6027\u306B\u3059\u308B\u3068\u3001\u6DFB\u5B570\u304C\u6B20\u756A\
    \u306B\u306A\u308B\u3002(\u89AA\u306B\u5411\u304B\u3046\u8FBA\u3068\u5BFE\u5FDC\
    \u3059\u308B\u306F\u305A\u306A\u306E\u3067\u305D\u308C\u306F\u305D\u3046\u304B\
    )\n// \u3000\u3000\u306A\u304A\u8FBA\u5C5E\u6027\u306B\u5024\u3092\u5272\u308A\
    \u5F53\u3066\u308B\u6642\u306F\u3001dep\u3067\u6DF1\u3044\u65B9\u306E\u9802\u70B9\
    \u306B\u3063\u3066\u3084\u308B\u3068\u3044\u3044\u3002(ABC133f\u3068\u304B\u53C2\
    \u7167)\n// \u3000\u30FB\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u306F[hld.in[x],hld.out[x])\u3067\
    \u51E6\u7406\u3002\n// \u3000\u3000\u306A\u304A\u90E8\u5206\u6728\u30AF\u30A8\u30EA\
    \u3082\u8FBA\u5C5E\u6027\u306E\u6642\u306Fedge=true\u306E\u3088\u3046\u306B\u5DE6\
    \u7AEF\u3092+1\u3059\u308B\u3002\n// \u3000\u3000\u3042\u3068\u300C\u90E8\u5206\
    \u6728\u3058\u3083\u306A\u3044\u90E8\u5206\u300D\u3082\u53D6\u308C\u308B\u3002\
    [0,hld.in[x])\u3068[hld.out[x],N) \u306E2\u533A\u9593\u3067OK\u3002\n// \u3000\
    \u3000\u3053\u308C\u3068\u6DF1\u3055\u3067\u6BD4\u8F03\u3057\u3066\u5834\u5408\
    \u5206\u3051\u3059\u308C\u3070\u3001\u3042\u308B\u30D1\u30B9\u306E\u624B\u524D\
    \u3068\u5411\u3053\u3046\u5074\u304C\u4EFB\u610F\u306B\u53D6\u308C\u308B\u3088\
    \u3046\u306B\u306A\u308B\u3002\n// \u3000\u30FB\u6839\u4ED8\u304D\u6728\u306F\u9802\
    \u70B90\u304C\u6839\u3067\u3042\u308B\u524D\u63D0\u3002\u4ED6\u306E\u9802\u70B9\
    \u3092\u6839\u306B\u3057\u305F\u3044\u5834\u5408\u3001\n// \u3000\u3000HLD\u69CB\
    \u7BC9\u524D\u306B\u6839\u3068\u9802\u70B90\u306E\u95A2\u4FC2\u3092\u5168\u3066\
    \u30B9\u30EF\u30C3\u30D7\u3057\u3066\u304A\u304F\u3002\n// \u3000\u3000\u2192\u4EFB\
    \u610F\u306E\u9802\u70B9\u3092\u6839\u306B\u3067\u304D\u308B\u3088\u3046\u6539\
    \u4FEE\u3057\u3066\u307F\u305F\u3002\u524D\u3084\u308D\u3046\u3068\u3057\u3066\
    \u5931\u6557\u3057\u305F\u3093\u3060\u3051\u3069\u3001\n// \u3000\u3000head\u306E\
    \u521D\u671F\u5024\u3092root\u306B\u3057\u305F\u3089\u3046\u307E\u304F\u3044\u3063\
    \u305F\u3002\n// \u3000\u30FB\u30D1\u30B9\u30AF\u30A8\u30EA[u,v]\u306B\u3066\u3001\
    u->lca\u3068lca->v\u3067HLD\u4E0A\u306E\u5217\u306E\u5411\u304D\u304C\u9006\u306B\
    \u306A\u308B\u306E\u3067\u3001\n// \u3000\u3000\u4E57\u305B\u305F\u30BB\u30B0\u6728\
    \u306E\u6F14\u7B97\u306B\u30DE\u30FC\u30B8\u65B9\u5411\u304C\u3042\u308B\u5834\
    \u5408\u306A\u3069\u306F\u6CE8\u610F\u3057\u3066\u51E6\u7406\u3059\u308B\u3002\
    \n// \u3000\u30FB\u5DE6\u53F3\u306E\u533A\u5225\u304C\u3042\u308B\u30E2\u30CE\u30A4\
    \u30C9\u3092\u4E57\u305B\u305F\u3044\u6642\u306F\u30AF\u30A8\u30EA\u3067\u95A2\
    \u6570S\u3092\u4F7F\u3046\u3068\u3046\u307E\u304F\u3044\u3063\u305F\u3002(cf1843F2\u53C2\
    \u7167)\n\n// HL\u5206\u89E3\nstruct HeavyLightDecomposition {\npublic:\n    vvi\
    \ g;\n    vector<int> sz, in, out, head, rev, par, dep;\n\n    // \u9802\u70B9\
    v\u304B\u3089k\u56DE\u9061\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\n    int\
    \ la(int v, int k) {\n        while (1) {\n            int u = head[v];\n    \
    \        if (in[v] - k >= in[u]) return rev[in[v] - k];\n            k -= in[v]\
    \ - in[u] + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u,\
    \ int v) const {\n        for (;; v = par[head[v]]) {\n            if (in[u] >\
    \ in[v]) swap(u, v);\n            if (head[u] == head[v]) return u;\n        }\n\
    \    }\n\n    // \u9802\u70B9u\u304B\u3089v\u306B\u5411\u304B\u3063\u30661\u3064\
    \u9032\u3093\u3060\u9802\u70B9\u3092\u8FD4\u3059\n    int next(int u, int v) {\n\
    \        // assert(lca(u, v) == u);\n        int d = dist(u, v);\n        return\
    \ la(v, d - 1);\n    }\n\n    int dist(int u, int v) const {\n        return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    template<typename E, typename Q,\
    \ typename F, typename S>\n    E query(\n        int u, int v, const E &ti, const\
    \ Q &q, const F &f, const S &s,\n        bool edge = false\n    ) {\n        E\
    \ l = ti, r = ti;\n        for (;; v = par[head[v]]) {\n            if (in[u]\
    \ > in[v]) swap(u, v), swap(l, r);\n            if (head[u] == head[v]) break;\n\
    \            l = f(q(in[head[v]], in[v] + 1), l);\n        }\n        return s(f(q(in[u]\
    \ + edge, in[v] + 1), l), r);\n    }\n\n    template<typename E, typename Q, typename\
    \ F>\n    E query(\n        int u, int v, const E &ti, const Q &q, const F &f,\
    \ bool edge = false\n    ) {\n        return query(u, v, ti, q, f, f, edge);\n\
    \    }\n\n    template<typename Q>\n    void update(int u, int v, const Q &q,\
    \ bool edge = false) {\n        for (;; v = par[head[v]]) {\n            if (in[u]\
    \ > in[v]) swap(u, v);\n            if (head[u] == head[v]) break;\n         \
    \   q(in[head[v]], in[v] + 1);\n        }\n        q(in[u] + edge, in[v] + 1);\n\
    \    }\n\n    /* {parent, child} */\n    vector<pair<int, int>> compress(vector<int>\
    \ &remark) {\n        auto cmp = [&](int a, int b) { return in[a] < in[b]; };\n\
    \        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        int K = (int)remark.size();\n        for\
    \ (int k = 1; k < K; k++)\n            remark.emplace_back(lca(remark[k - 1],\
    \ remark[k]));\n        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        vector<pair<int, int>> es;\n        stack<int>\
    \ st;\n        for (auto &k : remark) {\n            while (!st.empty() && out[st.top()]\
    \ <= in[k]) st.pop();\n            if (!st.empty()) es.emplace_back(st.top(),\
    \ k);\n            st.emplace(k);\n        }\n        return es;\n    }\n\n  \
    \  explicit HeavyLightDecomposition(const vvi &g, int root = 0) : g(g) {\n   \
    \     build(root);\n    }\n\n    int operator[](int u) const {\n        assert(0\
    \ <= u && u < (int)g.size());\n        return in[u];\n    }\n\nprivate:\n    void\
    \ build(int root = 0) {\n        sz.assign(g.size(), 0);\n        in.assign(g.size(),\
    \ 0);\n        out.assign(g.size(), 0);\n        head.assign(g.size(), root);\n\
    \        rev.assign(g.size(), 0);\n        par.assign(g.size(), 0);\n        dep.assign(g.size(),\
    \ 0);\n        dfs_sz(root, -1, 0);\n        int t = 0;\n        dfs_hld(root,\
    \ -1, t);\n    }\n\n    void dfs_sz(int idx, int p, int d) {\n        dep[idx]\
    \ = d;\n        par[idx] = p;\n        sz[idx] = 1;\n        if (g[idx].size()\
    \ && g[idx][0] == p) swap(g[idx][0], g[idx].back());\n        for (auto &to :\
    \ g[idx]) {\n            if (to == p) continue;\n            dfs_sz(to, idx, d\
    \ + 1);\n            sz[idx] += sz[to];\n            if (sz[g[idx][0]] < sz[to])\
    \ swap(g[idx][0], to);\n        }\n    }\n\n    void dfs_hld(int idx, int p, int\
    \ &times) {\n        in[idx] = times++;\n        rev[in[idx]] = idx;\n       \
    \ for (auto &to : g[idx]) {\n            if (to == p) continue;\n            head[to]\
    \ = (g[idx][0] == to ? head[idx] : to);\n            dfs_hld(to, idx, times);\n\
    \        }\n        out[idx] = times;\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// HL\u5206\u89E3\n// see: https://ei1333.github.io/library/graph/tree/heavy-light-decomposition.hpp\n\
    // \u30FB\u4E3B\u306A\u4F7F\u7528\u65B9\u6CD5\u306A\u3069\n// \u3000\u30FB\u521D\
    \u671F\u5316\u5F8C\u3001\u5FD8\u308C\u305A\u306Bbuild\u3092\u547C\u3076\u3053\u3068\
    \u3002\u2192build\u306F\u521D\u671F\u5316\u306B\u542B\u3081\u305F\u3002\n// \u3000\
    \u30FB\u30D1\u30B9\u30AF\u30A8\u30EA\u306Fadd,query\u3067\u51E6\u7406\n// \u3000\
    \u30FB1\u70B9\u53D6\u5F97/\u66F4\u65B0\u306Fhld.in[x]\u3067\u53EF\u80FD\u3002\
    add,query\u306F\u547C\u3070\u306A\u304F\u3066\u3044\u3044\u3002\n// \u3000\u30FB\
    \u8FBA\u5C5E\u6027\u306B\u3059\u308B\u3068\u3001\u6DFB\u5B570\u304C\u6B20\u756A\
    \u306B\u306A\u308B\u3002(\u89AA\u306B\u5411\u304B\u3046\u8FBA\u3068\u5BFE\u5FDC\
    \u3059\u308B\u306F\u305A\u306A\u306E\u3067\u305D\u308C\u306F\u305D\u3046\u304B\
    )\n// \u3000\u3000\u306A\u304A\u8FBA\u5C5E\u6027\u306B\u5024\u3092\u5272\u308A\
    \u5F53\u3066\u308B\u6642\u306F\u3001dep\u3067\u6DF1\u3044\u65B9\u306E\u9802\u70B9\
    \u306B\u3063\u3066\u3084\u308B\u3068\u3044\u3044\u3002(ABC133f\u3068\u304B\u53C2\
    \u7167)\n// \u3000\u30FB\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u306F[hld.in[x],hld.out[x])\u3067\
    \u51E6\u7406\u3002\n// \u3000\u3000\u306A\u304A\u90E8\u5206\u6728\u30AF\u30A8\u30EA\
    \u3082\u8FBA\u5C5E\u6027\u306E\u6642\u306Fedge=true\u306E\u3088\u3046\u306B\u5DE6\
    \u7AEF\u3092+1\u3059\u308B\u3002\n// \u3000\u3000\u3042\u3068\u300C\u90E8\u5206\
    \u6728\u3058\u3083\u306A\u3044\u90E8\u5206\u300D\u3082\u53D6\u308C\u308B\u3002\
    [0,hld.in[x])\u3068[hld.out[x],N) \u306E2\u533A\u9593\u3067OK\u3002\n// \u3000\
    \u3000\u3053\u308C\u3068\u6DF1\u3055\u3067\u6BD4\u8F03\u3057\u3066\u5834\u5408\
    \u5206\u3051\u3059\u308C\u3070\u3001\u3042\u308B\u30D1\u30B9\u306E\u624B\u524D\
    \u3068\u5411\u3053\u3046\u5074\u304C\u4EFB\u610F\u306B\u53D6\u308C\u308B\u3088\
    \u3046\u306B\u306A\u308B\u3002\n// \u3000\u30FB\u6839\u4ED8\u304D\u6728\u306F\u9802\
    \u70B90\u304C\u6839\u3067\u3042\u308B\u524D\u63D0\u3002\u4ED6\u306E\u9802\u70B9\
    \u3092\u6839\u306B\u3057\u305F\u3044\u5834\u5408\u3001\n// \u3000\u3000HLD\u69CB\
    \u7BC9\u524D\u306B\u6839\u3068\u9802\u70B90\u306E\u95A2\u4FC2\u3092\u5168\u3066\
    \u30B9\u30EF\u30C3\u30D7\u3057\u3066\u304A\u304F\u3002\n// \u3000\u3000\u2192\u4EFB\
    \u610F\u306E\u9802\u70B9\u3092\u6839\u306B\u3067\u304D\u308B\u3088\u3046\u6539\
    \u4FEE\u3057\u3066\u307F\u305F\u3002\u524D\u3084\u308D\u3046\u3068\u3057\u3066\
    \u5931\u6557\u3057\u305F\u3093\u3060\u3051\u3069\u3001\n// \u3000\u3000head\u306E\
    \u521D\u671F\u5024\u3092root\u306B\u3057\u305F\u3089\u3046\u307E\u304F\u3044\u3063\
    \u305F\u3002\n// \u3000\u30FB\u30D1\u30B9\u30AF\u30A8\u30EA[u,v]\u306B\u3066\u3001\
    u->lca\u3068lca->v\u3067HLD\u4E0A\u306E\u5217\u306E\u5411\u304D\u304C\u9006\u306B\
    \u306A\u308B\u306E\u3067\u3001\n// \u3000\u3000\u4E57\u305B\u305F\u30BB\u30B0\u6728\
    \u306E\u6F14\u7B97\u306B\u30DE\u30FC\u30B8\u65B9\u5411\u304C\u3042\u308B\u5834\
    \u5408\u306A\u3069\u306F\u6CE8\u610F\u3057\u3066\u51E6\u7406\u3059\u308B\u3002\
    \n// \u3000\u30FB\u5DE6\u53F3\u306E\u533A\u5225\u304C\u3042\u308B\u30E2\u30CE\u30A4\
    \u30C9\u3092\u4E57\u305B\u305F\u3044\u6642\u306F\u30AF\u30A8\u30EA\u3067\u95A2\
    \u6570S\u3092\u4F7F\u3046\u3068\u3046\u307E\u304F\u3044\u3063\u305F\u3002(cf1843F2\u53C2\
    \u7167)\n\n// HL\u5206\u89E3\nstruct HeavyLightDecomposition {\npublic:\n    vvi\
    \ g;\n    vector<int> sz, in, out, head, rev, par, dep;\n\n    // \u9802\u70B9\
    v\u304B\u3089k\u56DE\u9061\u3063\u305F\u9802\u70B9\u3092\u8FD4\u3059\n    int\
    \ la(int v, int k) {\n        while (1) {\n            int u = head[v];\n    \
    \        if (in[v] - k >= in[u]) return rev[in[v] - k];\n            k -= in[v]\
    \ - in[u] + 1;\n            v = par[u];\n        }\n    }\n\n    int lca(int u,\
    \ int v) const {\n        for (;; v = par[head[v]]) {\n            if (in[u] >\
    \ in[v]) swap(u, v);\n            if (head[u] == head[v]) return u;\n        }\n\
    \    }\n\n    // \u9802\u70B9u\u304B\u3089v\u306B\u5411\u304B\u3063\u30661\u3064\
    \u9032\u3093\u3060\u9802\u70B9\u3092\u8FD4\u3059\n    int next(int u, int v) {\n\
    \        // assert(lca(u, v) == u);\n        int d = dist(u, v);\n        return\
    \ la(v, d - 1);\n    }\n\n    int dist(int u, int v) const {\n        return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    template<typename E, typename Q,\
    \ typename F, typename S>\n    E query(\n        int u, int v, const E &ti, const\
    \ Q &q, const F &f, const S &s,\n        bool edge = false\n    ) {\n        E\
    \ l = ti, r = ti;\n        for (;; v = par[head[v]]) {\n            if (in[u]\
    \ > in[v]) swap(u, v), swap(l, r);\n            if (head[u] == head[v]) break;\n\
    \            l = f(q(in[head[v]], in[v] + 1), l);\n        }\n        return s(f(q(in[u]\
    \ + edge, in[v] + 1), l), r);\n    }\n\n    template<typename E, typename Q, typename\
    \ F>\n    E query(\n        int u, int v, const E &ti, const Q &q, const F &f,\
    \ bool edge = false\n    ) {\n        return query(u, v, ti, q, f, f, edge);\n\
    \    }\n\n    template<typename Q>\n    void update(int u, int v, const Q &q,\
    \ bool edge = false) {\n        for (;; v = par[head[v]]) {\n            if (in[u]\
    \ > in[v]) swap(u, v);\n            if (head[u] == head[v]) break;\n         \
    \   q(in[head[v]], in[v] + 1);\n        }\n        q(in[u] + edge, in[v] + 1);\n\
    \    }\n\n    /* {parent, child} */\n    vector<pair<int, int>> compress(vector<int>\
    \ &remark) {\n        auto cmp = [&](int a, int b) { return in[a] < in[b]; };\n\
    \        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        int K = (int)remark.size();\n        for\
    \ (int k = 1; k < K; k++)\n            remark.emplace_back(lca(remark[k - 1],\
    \ remark[k]));\n        sort(begin(remark), end(remark), cmp);\n        remark.erase(unique(begin(remark),\
    \ end(remark)), end(remark));\n        vector<pair<int, int>> es;\n        stack<int>\
    \ st;\n        for (auto &k : remark) {\n            while (!st.empty() && out[st.top()]\
    \ <= in[k]) st.pop();\n            if (!st.empty()) es.emplace_back(st.top(),\
    \ k);\n            st.emplace(k);\n        }\n        return es;\n    }\n\n  \
    \  explicit HeavyLightDecomposition(const vvi &g, int root = 0) : g(g) {\n   \
    \     build(root);\n    }\n\n    int operator[](int u) const {\n        assert(0\
    \ <= u && u < (int)g.size());\n        return in[u];\n    }\n\nprivate:\n    void\
    \ build(int root = 0) {\n        sz.assign(g.size(), 0);\n        in.assign(g.size(),\
    \ 0);\n        out.assign(g.size(), 0);\n        head.assign(g.size(), root);\n\
    \        rev.assign(g.size(), 0);\n        par.assign(g.size(), 0);\n        dep.assign(g.size(),\
    \ 0);\n        dfs_sz(root, -1, 0);\n        int t = 0;\n        dfs_hld(root,\
    \ -1, t);\n    }\n\n    void dfs_sz(int idx, int p, int d) {\n        dep[idx]\
    \ = d;\n        par[idx] = p;\n        sz[idx] = 1;\n        if (g[idx].size()\
    \ && g[idx][0] == p) swap(g[idx][0], g[idx].back());\n        for (auto &to :\
    \ g[idx]) {\n            if (to == p) continue;\n            dfs_sz(to, idx, d\
    \ + 1);\n            sz[idx] += sz[to];\n            if (sz[g[idx][0]] < sz[to])\
    \ swap(g[idx][0], to);\n        }\n    }\n\n    void dfs_hld(int idx, int p, int\
    \ &times) {\n        in[idx] = times++;\n        rev[in[idx]] = idx;\n       \
    \ for (auto &to : g[idx]) {\n            if (to == p) continue;\n            head[to]\
    \ = (g[idx][0] == to ? head[idx] : to);\n            dfs_hld(to, idx, times);\n\
    \        }\n        out[idx] = times;\n    }\n};"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/HeavyLightDecomposition.hpp
  requiredBy:
  - src/graph/AuxiliaryTree.hpp
  timestamp: '2023-12-11 16:15:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/src/graph/HeavyLightDecomposition.hpp
- /library/src/graph/HeavyLightDecomposition.hpp.html
title: src/graph/HeavyLightDecomposition.hpp
---
