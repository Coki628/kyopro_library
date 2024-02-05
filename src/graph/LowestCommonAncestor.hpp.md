---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/datastructure/SparseTable.hpp
    title: src/datastructure/SparseTable.hpp
  - icon: ':warning:'
    path: src/graph/EulerTour.hpp
    title: src/graph/EulerTour.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://stackoverflow.com/questions/52520276/is-decltype-of-a-non-static-member-function-ill-formed
    - https://suisen-cp.github.io/cp-library-cpp/library/tree/lowest_common_ancestor.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/SparseTable.hpp\"\
    \n\n// \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\uFF1A\u69CB\u7BC9\u306B\
    O(NlogN)\u3001\u533A\u9593\u53D6\u5F97\u306BO(1)\ntemplate<typename T, typename\
    \ F>\nstruct SparseTable {\n    const F f;\n    const T e;\n    vv<T> dat;\n \
    \   vector<int> height;\n\n    SparseTable(const F f, const T e) : f(f), e(e)\
    \ {}\n\n    SparseTable(const vector<T> &A, const F f, const T e) : f(f), e(e)\
    \ {\n        build(A);\n    }\n\n    void build(const vector<T> &A) {\n      \
    \  int N = A.size();\n\n        int h = 0;\n        while ((1 << h) <= N) {\n\
    \            h++;\n        }\n        dat.resize(h);\n        rep(i, h) dat[i].resize(1\
    \ << h);\n        height.resize(N + 1);\n\n        rep(i, 2, N + 1) {\n      \
    \      height[i] = height[i >> 1] + 1;\n        }\n        rep(i, N) {\n     \
    \       dat[0][i] = A[i];\n        }\n        rep(i, 1, h) {\n            for\
    \ (int j = 0; j < N; j++) {\n                dat[i][j] =\n                   \
    \ f(dat[i - 1][j],\n                      dat[i - 1][min(j + (1 << (i - 1)), N\
    \ - 1)]);\n            }\n        }\n    }\n\n    // \u533A\u9593[l,r)\u3067\u306E\
    min,max\u3092\u53D6\u5F97\n    T query(int l, int r) {\n        if (l >= r) return\
    \ e;\n        int a = height[r - l];\n        return f(dat[a][l], dat[a][r - (1\
    \ << a)]);\n    }\n\n    // \u533A\u9593[l,r]\u3067\u5DE6\u304B\u3089\u6700\u521D\
    \u306Bx\u306B\u5BFE\u3057\u3066\u6BD4\u8F03\u306E\u6761\u4EF6\u3092\u6E80\u305F\
    \u3059\u3088\u3046\u306A\u5024\u304C\u51FA\u73FE\u3059\u308B\u4F4D\u7F6E\n   \
    \ template<typename G>\n    int bisearch_fore(int l, int r, T x, const G &compare)\
    \ {\n        int ok = r + 1;\n        int ng = l - 1;\n        while (ng + 1 <\
    \ ok) {\n            int mid = (ok + ng) / 2;\n            if (compare(query(l,\
    \ mid + 1), x)) {\n                ok = mid;\n            } else {\n         \
    \       ng = mid;\n            }\n        }\n        if (ok != r + 1) {\n    \
    \        return ok;\n        } else {\n            return -1;\n        }\n   \
    \ }\n\n    // \u533A\u9593[l,r]\u3067\u53F3\u304B\u3089\u6700\u521D\u306Bx\u306B\
    \u5BFE\u3057\u3066\u6BD4\u8F03\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306A\u5024\u304C\u51FA\u73FE\u3059\u308B\u4F4D\u7F6E\n    template<typename\
    \ G>\n    int bisearch_back(int l, int r, T x, const G &compare) {\n        int\
    \ ok = l - 1;\n        int ng = r + 1;\n        while (ok + 1 < ng) {\n      \
    \      int mid = (ok + ng) / 2;\n            if (compare(query(mid, r + 1), x))\
    \ {\n                ok = mid;\n            } else {\n                ng = mid;\n\
    \            }\n        }\n        if (ok != l - 1) {\n            return ok;\n\
    \        } else {\n            return -1;\n        }\n    }\n    // \u4F7F\u7528\
    \u4F8B\n    // stmx.bisearch_back(l, r, x, greater<ll>());\n};\n\ntemplate<typename\
    \ T, typename F>\nSparseTable<T, F> get_sparse_table(vector<T> &A, const F &f,\
    \ const T &e) {\n    return {A, f, e};\n}\n\ntemplate<typename T, typename F>\n\
    SparseTable<T, F> get_sparse_table(const F &f, const T &e) {\n    return {f, e};\n\
    }\n#line 3 \"src/graph/EulerTour.hpp\"\n\n// \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
    \u30FC\n// \u30FBHLD\u304B\u3089\u5207\u308A\u51FA\u3057\u305F\u3002\u90E8\u5206\
    \u6728\u30AF\u30A8\u30EA\u306F\u3053\u308C\u3067\u5341\u5206\u3002\nstruct EulerTour\
    \ {\npublic:\n    int N;\n    vvi nodes;\n    vector<int> sz, in, out, rev, par,\
    \ dep;\n\n    explicit EulerTour(const vvi &nodes) : nodes(nodes), N(nodes.size())\
    \ {\n        sz.assign(N, 0);\n        in.assign(N, 0);\n        out.assign(N,\
    \ 0);\n        rev.assign(N, 0);\n        par.assign(N, 0);\n        dep.assign(N,\
    \ 0);\n        int t = 0;\n        dfs(0, -1, 0, t);\n    }\n\n    int operator[](int\
    \ u) const {\n        assert(0 <= u && u < N);\n        return in[u];\n    }\n\
    \nprivate:\n    void dfs(int idx, int p, int d, int &times) {\n        dep[idx]\
    \ = d;\n        par[idx] = p;\n        sz[idx] = 1;\n        in[idx] = times++;\n\
    \        rev[in[idx]] = idx;\n        for (auto &to : nodes[idx]) {\n        \
    \    if (to == p) continue;\n            dfs(to, idx, d + 1, times);\n       \
    \     sz[idx] += sz[to];\n        }\n        out[idx] = times;\n    }\n};\n#line\
    \ 5 \"src/graph/LowestCommonAncestor.hpp\"\n\n// \u7DDA\u5F62LCA\n// \u53C2\u8003\
    \uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/tree/lowest_common_ancestor.hpp\n\
    // \u30FB\u6700\u77ED\u8DDD\u96E2\u53D6\u5F97\u3092log\u3064\u3051\u306A\u3044\
    \u3067\u3084\u308BLCA(\u69CB\u7BC9\u306F\u3061\u3083\u3093\u3068NlogN\u304B\u304B\
    \u308B\u3051\u3069)\u3002\n// \u30FBSparseTable\u3092\u4F7F\u3046\u306E\u3067\u3001\
    \u3042\u3093\u307E\u308A\u9802\u70B9\u6570\u591A\u3044\u6642\u3068\u304B\u306F\
    \u30E1\u30E2\u30EA\u53B3\u3057\u3044\u304B\u3082\u3002\nstruct LowestCommonAncestor\
    \ {\n    int N;\n    vector<int> dep, in;\n    static pii f(const pii &a, const\
    \ pii &b) {\n        return min(a, b);\n    }\n    // \u30AF\u30E9\u30B9\u5185\
    \u95A2\u6570\u3078\u306Edecltype\n    // see: https://stackoverflow.com/questions/52520276/is-decltype-of-a-non-static-member-function-ill-formed\n\
    \    SparseTable<pii, decltype(&f)> st = get_sparse_table(&f, pii{MOD, -1});\n\
    \n    explicit LowestCommonAncestor(const vvi &nodes) : N(nodes.size()) {\n  \
    \      dep.assign(N, 0);\n        in.assign(N, 0);\n        int t = 0;\n     \
    \   vector<pii> vec;\n        auto dfs = [&](auto &&f, int u, int p, int d) ->\
    \ void {\n            dep[u] = d;\n            in[u] = t++;\n            vec.eb(d,\
    \ u);\n            for (auto v : nodes[u]) {\n                if (v == p) continue;\n\
    \                f(f, v, u, d + 1);\n                vec.eb(d, u);\n         \
    \       t++;\n            }\n        };\n        dfs(dfs, 0, -1, 0);\n       \
    \ st.build(vec);\n    }\n\n    int lca(int u, int v) {\n        if (in[u] > in[v])\
    \ swap(u, v);\n        return st.query(in[u], in[v] + 1).second;\n    }\n\n  \
    \  int dist(int u, int v) {\n        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../datastructure/SparseTable.hpp\"\n#include \"\
    ../macros.hpp\"\n#include \"EulerTour.hpp\"\n\n// \u7DDA\u5F62LCA\n// \u53C2\u8003\
    \uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/tree/lowest_common_ancestor.hpp\n\
    // \u30FB\u6700\u77ED\u8DDD\u96E2\u53D6\u5F97\u3092log\u3064\u3051\u306A\u3044\
    \u3067\u3084\u308BLCA(\u69CB\u7BC9\u306F\u3061\u3083\u3093\u3068NlogN\u304B\u304B\
    \u308B\u3051\u3069)\u3002\n// \u30FBSparseTable\u3092\u4F7F\u3046\u306E\u3067\u3001\
    \u3042\u3093\u307E\u308A\u9802\u70B9\u6570\u591A\u3044\u6642\u3068\u304B\u306F\
    \u30E1\u30E2\u30EA\u53B3\u3057\u3044\u304B\u3082\u3002\nstruct LowestCommonAncestor\
    \ {\n    int N;\n    vector<int> dep, in;\n    static pii f(const pii &a, const\
    \ pii &b) {\n        return min(a, b);\n    }\n    // \u30AF\u30E9\u30B9\u5185\
    \u95A2\u6570\u3078\u306Edecltype\n    // see: https://stackoverflow.com/questions/52520276/is-decltype-of-a-non-static-member-function-ill-formed\n\
    \    SparseTable<pii, decltype(&f)> st = get_sparse_table(&f, pii{MOD, -1});\n\
    \n    explicit LowestCommonAncestor(const vvi &nodes) : N(nodes.size()) {\n  \
    \      dep.assign(N, 0);\n        in.assign(N, 0);\n        int t = 0;\n     \
    \   vector<pii> vec;\n        auto dfs = [&](auto &&f, int u, int p, int d) ->\
    \ void {\n            dep[u] = d;\n            in[u] = t++;\n            vec.eb(d,\
    \ u);\n            for (auto v : nodes[u]) {\n                if (v == p) continue;\n\
    \                f(f, v, u, d + 1);\n                vec.eb(d, u);\n         \
    \       t++;\n            }\n        };\n        dfs(dfs, 0, -1, 0);\n       \
    \ st.build(vec);\n    }\n\n    int lca(int u, int v) {\n        if (in[u] > in[v])\
    \ swap(u, v);\n        return st.query(in[u], in[v] + 1).second;\n    }\n\n  \
    \  int dist(int u, int v) {\n        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n\
    \    }\n};\n"
  dependsOn:
  - src/datastructure/SparseTable.hpp
  - src/macros.hpp
  - src/base.hpp
  - src/graph/EulerTour.hpp
  isVerificationFile: false
  path: src/graph/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2024-02-06 01:26:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/src/graph/LowestCommonAncestor.hpp
- /library/src/graph/LowestCommonAncestor.hpp.html
title: src/graph/LowestCommonAncestor.hpp
---
