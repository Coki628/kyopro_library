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
  - icon: ':heavy_check_mark:'
    path: src/graph/WeightedUnionFind.hpp
    title: src/graph/WeightedUnionFind.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/UnionFind.test.cpp
    title: test/graph/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/WeightedUnionFind.test.cpp
    title: test/graph/WeightedUnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/UnionFind.hpp\"\
    \n\nstruct UnionFind {\n    int n, groupcnt;\n    vector<int> par, rank, sz;\n\
    \    vector<bool> tree;\n\n    UnionFind(int n) : n(n) {\n        build();\n \
    \   }\n\n    UnionFind() {}\n\n    // \u65E2\u5B58\u306E\u9023\u7D50\u60C5\u5831\
    \u304B\u3089UF\u3092\u751F\u6210\n    UnionFind(const vector<int> &info) : n(info.size())\
    \ {\n        build();\n        vvi adj(n);\n        rep(i, n) {\n            adj[info[i]].eb(i);\n\
    \        }\n        rep(i, n) {\n            if (adj[i].size()) {\n          \
    \      rep(j, adj[i].size() - 1) {\n                    merge(adj[i][j], adj[i][j\
    \ + 1]);\n                }\n            }\n        }\n    }\n\n    void build()\
    \ {\n        par.assign(n, 0);\n        rank.assign(n, 0);\n        sz.assign(n,\
    \ 1);\n        tree.assign(n, true);\n        rep(i, n) par[i] = i;\n        groupcnt\
    \ = n;\n    }\n\n    void resize(int _n) {\n        n = _n;\n        par.assign(n,\
    \ 0);\n        rank.assign(n, 0);\n        sz.assign(n, 1);\n        tree.assign(n,\
    \ true);\n        rep(i, n) par[i] = i;\n        groupcnt = n;\n    }\n\n    //\
    \ \u6839(\u30B0\u30EB\u30FC\u30D7\u756A\u53F7)\u306E\u691C\u7D22\n    virtual\
    \ int find(int x) {\n        if (par[x] == x) {\n            return x;\n     \
    \   } else {\n            par[x] = find(par[x]);\n            return par[x];\n\
    \        }\n    }\n\n    // \u4F75\u5408\uFF1A\u30DE\u30FC\u30B8\u5F8C\u306E\u96C6\
    \u5408\u306E\u6839(\u30DE\u30FC\u30B8\u6E08\u306A\u3089-1)\u3092\u8FD4\u3059\n\
    \    template<typename F>\n    int merge(int a, int b, F f) {\n        int x =\
    \ find(a);\n        int y = find(b);\n        if (x == y) {\n            tree[x]\
    \ = false;\n            f(-1, y);\n            return -1;\n        }\n       \
    \ if (!tree[x] or !tree[y]) {\n            tree[x] = tree[y] = false;\n      \
    \  }\n        groupcnt--;\n        if (rank[x] < rank[y]) {\n            par[x]\
    \ = y;\n            sz[y] += sz[x];\n            f(y, x);\n            return\
    \ y;\n        } else {\n            par[y] = x;\n            sz[x] += sz[y];\n\
    \            if (rank[x] == rank[y]) {\n                rank[x]++;\n         \
    \   }\n            f(x, y);\n            return x;\n        }\n    }\n\n    int\
    \ merge(int a, int b) {\n        return merge(a, b, [](int r, int ch) {});\n \
    \   }\n\n    // \u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\
    \n    bool same(int a, int b) {\n        return find(a) == find(b);\n    }\n\n\
    \    // \u3042\u308B\u30CE\u30FC\u30C9\u306E\u5C5E\u3059\u308B\u96C6\u5408\u306E\
    \u30CE\u30FC\u30C9\u6570\n    ll size(int x) {\n        return sz[find(x)];\n\
    \    }\n\n    // \u96C6\u5408\u306E\u6570\n    int size() {\n        return groupcnt;\n\
    \    }\n\n    // \u6728\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A\n    bool is_tree(int\
    \ x) {\n        return tree[find(x)];\n    }\n\n    // \u5168\u3066\u306E\u6839\
    \u3092\u53D6\u5F97\n    set<int> get_roots() {\n        set<int> res;\n      \
    \  rep(i, n) {\n            res.insert(find(i));\n        }\n        return res;\n\
    \    }\n\n    // \u5168\u9802\u70B9\u306E\u30B0\u30EB\u30FC\u30D7\u756A\u53F7\u3092\
    \u53D6\u5F97\n    vector<int> get_info() {\n        vector<int> res(n);\n    \
    \    rep(i, n) {\n            res[i] = find(i);\n        }\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\nstruct UnionFind {\n    int n,\
    \ groupcnt;\n    vector<int> par, rank, sz;\n    vector<bool> tree;\n\n    UnionFind(int\
    \ n) : n(n) {\n        build();\n    }\n\n    UnionFind() {}\n\n    // \u65E2\u5B58\
    \u306E\u9023\u7D50\u60C5\u5831\u304B\u3089UF\u3092\u751F\u6210\n    UnionFind(const\
    \ vector<int> &info) : n(info.size()) {\n        build();\n        vvi adj(n);\n\
    \        rep(i, n) {\n            adj[info[i]].eb(i);\n        }\n        rep(i,\
    \ n) {\n            if (adj[i].size()) {\n                rep(j, adj[i].size()\
    \ - 1) {\n                    merge(adj[i][j], adj[i][j + 1]);\n             \
    \   }\n            }\n        }\n    }\n\n    void build() {\n        par.assign(n,\
    \ 0);\n        rank.assign(n, 0);\n        sz.assign(n, 1);\n        tree.assign(n,\
    \ true);\n        rep(i, n) par[i] = i;\n        groupcnt = n;\n    }\n\n    void\
    \ resize(int _n) {\n        n = _n;\n        par.assign(n, 0);\n        rank.assign(n,\
    \ 0);\n        sz.assign(n, 1);\n        tree.assign(n, true);\n        rep(i,\
    \ n) par[i] = i;\n        groupcnt = n;\n    }\n\n    // \u6839(\u30B0\u30EB\u30FC\
    \u30D7\u756A\u53F7)\u306E\u691C\u7D22\n    virtual int find(int x) {\n       \
    \ if (par[x] == x) {\n            return x;\n        } else {\n            par[x]\
    \ = find(par[x]);\n            return par[x];\n        }\n    }\n\n    // \u4F75\
    \u5408\uFF1A\u30DE\u30FC\u30B8\u5F8C\u306E\u96C6\u5408\u306E\u6839(\u30DE\u30FC\
    \u30B8\u6E08\u306A\u3089-1)\u3092\u8FD4\u3059\n    template<typename F>\n    int\
    \ merge(int a, int b, F f) {\n        int x = find(a);\n        int y = find(b);\n\
    \        if (x == y) {\n            tree[x] = false;\n            f(-1, y);\n\
    \            return -1;\n        }\n        if (!tree[x] or !tree[y]) {\n    \
    \        tree[x] = tree[y] = false;\n        }\n        groupcnt--;\n        if\
    \ (rank[x] < rank[y]) {\n            par[x] = y;\n            sz[y] += sz[x];\n\
    \            f(y, x);\n            return y;\n        } else {\n            par[y]\
    \ = x;\n            sz[x] += sz[y];\n            if (rank[x] == rank[y]) {\n \
    \               rank[x]++;\n            }\n            f(x, y);\n            return\
    \ x;\n        }\n    }\n\n    int merge(int a, int b) {\n        return merge(a,\
    \ b, [](int r, int ch) {});\n    }\n\n    // \u540C\u3058\u96C6\u5408\u306B\u5C5E\
    \u3059\u308B\u304B\u5224\u5B9A\n    bool same(int a, int b) {\n        return\
    \ find(a) == find(b);\n    }\n\n    // \u3042\u308B\u30CE\u30FC\u30C9\u306E\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u30CE\u30FC\u30C9\u6570\n    ll size(int x) {\n\
    \        return sz[find(x)];\n    }\n\n    // \u96C6\u5408\u306E\u6570\n    int\
    \ size() {\n        return groupcnt;\n    }\n\n    // \u6728\u304B\u3069\u3046\
    \u304B\u306E\u5224\u5B9A\n    bool is_tree(int x) {\n        return tree[find(x)];\n\
    \    }\n\n    // \u5168\u3066\u306E\u6839\u3092\u53D6\u5F97\n    set<int> get_roots()\
    \ {\n        set<int> res;\n        rep(i, n) {\n            res.insert(find(i));\n\
    \        }\n        return res;\n    }\n\n    // \u5168\u9802\u70B9\u306E\u30B0\
    \u30EB\u30FC\u30D7\u756A\u53F7\u3092\u53D6\u5F97\n    vector<int> get_info() {\n\
    \        vector<int> res(n);\n        rep(i, n) {\n            res[i] = find(i);\n\
    \        }\n        return res;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/UnionFind.hpp
  requiredBy:
  - src/template.hpp
  - src/graph/WeightedUnionFind.hpp
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/UnionFind.test.cpp
  - test/graph/WeightedUnionFind.test.cpp
documentation_of: src/graph/UnionFind.hpp
layout: document
redirect_from:
- /library/src/graph/UnionFind.hpp
- /library/src/graph/UnionFind.hpp.html
title: src/graph/UnionFind.hpp
---
