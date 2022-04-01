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
    - https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/graph/RangeEdgeGraph.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656\n// \u533A\u9593\
    \u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF\ntemplate<typename W>\nstruct RangeEdgeGraph\
    \ {\n    int n;\n    struct edge { int to; W weight; };\n    vector<vector<edge>>\
    \ g;\n    \n    // RangeEdgeGraph(int n) : n(n) {\n    //     g.resize(4*n);\n\
    \    //     for (int i = 1; i < n; ++i) {\n    //         int cl = i<<1|0, cr\
    \ = i<<1|1;\n    //         g[i].push_back({cl, 0});\n    //         g[i].push_back({cr,\
    \ 0});\n    //         g[cl+2*n].push_back({i+2*n, 0});\n    //         g[cr+2*n].push_back({i+2*n,\
    \ 0});\n    //     }\n    //     for (int i = n; i < 2*n; ++i) g[i].push_back({i+2*n,\
    \ 0});\n    // }\n\n    // // from [l1, r1) to [l2, r2)\n    // void add_edge(int\
    \ l1, int r1, int l2, int r2, W w) {\n    //     int idx = g.size();\n    // \
    \    for (l1 += n, r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {\n    //         if\
    \ (l1 & 1) g[l1+2*n].push_back({idx, 0}), l1++;\n    //         if (r1 & 1) --r1,\
    \ g[r1+2*n].push_back({idx, 0});\n    //     }\n    //     vector<edge> node;\n\
    \    //     for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {\n    //    \
    \     if (l2 & 1) node.push_back({l2++, w});\n    //         if (r2 & 1) node.push_back({--r2,\
    \ w});\n    //     }\n    //     g.push_back(node);\n    // }\n\n    RangeEdgeGraph(int\
    \ n) : n(n) {\n        g.resize(3*n);\n        for (int i = 1; i < n; ++i) {\n\
    \            int cl = i<<1|0, cr = i<<1|1;\n            _add_edge(i, cl, 0);\n\
    \            _add_edge(i, cr, 0);\n            _add_edge(cl+2*n, i+2*n, 0);\n\
    \            _add_edge(cr+2*n, i+2*n, 0);\n        }\n    }\n\n    // map [3n,\
    \ 4n) -> [n, 2n)\n    void _add_edge(int u, int v, W w) {\n        if (3*n <=\
    \ u) u -= 2*n;\n        g[u].push_back({v, w});\n    }\n\n    // from [l1, r1)\
    \ to [l2, r2)\n    void add_edge(int l1, int r1, int l2, int r2, W w) {\n    \
    \    int idx = g.size();\n        for (l1 += n, r1 += n; l1 < r1; l1 >>= 1, r1\
    \ >>= 1) {\n            if (l1 & 1) _add_edge(l1+2*n, idx, 0), l1++;\n       \
    \     if (r1 & 1) --r1, _add_edge(r1+2*n, idx, 0);\n        }\n        vector<edge>\
    \ node;\n        for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {\n     \
    \       if (l2 & 1) node.push_back({l2++, w});\n            if (r2 & 1) node.push_back({--r2,\
    \ w});\n        }\n        g.push_back(node);\n    }\n\n    // from u to v\n \
    \   void add_edge(int u, int v, W w) {\n        add_edge(u, u+1, v, v+1, w);\n\
    \    }\n\n    vector<W> dijkstra(int s) {\n        s += n;\n        vector<W>\
    \ dist(g.size(), INF);\n        dist[s] = 0;\n        using P = pair<W, int>;\n\
    \        priority_queue<P, vector<P>, greater<P>> que;\n        que.emplace(0,\
    \ s);\n        while (!que.empty()) {\n            P p = que.top();\n        \
    \    que.pop();\n            int v = p.second;\n            if (dist[v] < p.first)\
    \ continue;\n            for (edge& e : g[v]) {\n                if (dist[e.to]\
    \ > dist[v] + e.weight) {\n                    dist[e.to] = dist[v] + e.weight;\n\
    \                    que.emplace(dist[e.to], e.to);\n                }\n     \
    \       }\n        }\n        vector<W> res(dist.begin() + n, dist.begin() + 2*n);\n\
    \        return res;\n    }\n};\n"
  code: "#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656\n\
    // \u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF\ntemplate<typename W>\n\
    struct RangeEdgeGraph {\n    int n;\n    struct edge { int to; W weight; };\n\
    \    vector<vector<edge>> g;\n    \n    // RangeEdgeGraph(int n) : n(n) {\n  \
    \  //     g.resize(4*n);\n    //     for (int i = 1; i < n; ++i) {\n    //   \
    \      int cl = i<<1|0, cr = i<<1|1;\n    //         g[i].push_back({cl, 0});\n\
    \    //         g[i].push_back({cr, 0});\n    //         g[cl+2*n].push_back({i+2*n,\
    \ 0});\n    //         g[cr+2*n].push_back({i+2*n, 0});\n    //     }\n    //\
    \     for (int i = n; i < 2*n; ++i) g[i].push_back({i+2*n, 0});\n    // }\n\n\
    \    // // from [l1, r1) to [l2, r2)\n    // void add_edge(int l1, int r1, int\
    \ l2, int r2, W w) {\n    //     int idx = g.size();\n    //     for (l1 += n,\
    \ r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {\n    //         if (l1 & 1) g[l1+2*n].push_back({idx,\
    \ 0}), l1++;\n    //         if (r1 & 1) --r1, g[r1+2*n].push_back({idx, 0});\n\
    \    //     }\n    //     vector<edge> node;\n    //     for (l2 += n, r2 += n;\
    \ l2 < r2; l2 >>= 1, r2 >>= 1) {\n    //         if (l2 & 1) node.push_back({l2++,\
    \ w});\n    //         if (r2 & 1) node.push_back({--r2, w});\n    //     }\n\
    \    //     g.push_back(node);\n    // }\n\n    RangeEdgeGraph(int n) : n(n) {\n\
    \        g.resize(3*n);\n        for (int i = 1; i < n; ++i) {\n            int\
    \ cl = i<<1|0, cr = i<<1|1;\n            _add_edge(i, cl, 0);\n            _add_edge(i,\
    \ cr, 0);\n            _add_edge(cl+2*n, i+2*n, 0);\n            _add_edge(cr+2*n,\
    \ i+2*n, 0);\n        }\n    }\n\n    // map [3n, 4n) -> [n, 2n)\n    void _add_edge(int\
    \ u, int v, W w) {\n        if (3*n <= u) u -= 2*n;\n        g[u].push_back({v,\
    \ w});\n    }\n\n    // from [l1, r1) to [l2, r2)\n    void add_edge(int l1, int\
    \ r1, int l2, int r2, W w) {\n        int idx = g.size();\n        for (l1 +=\
    \ n, r1 += n; l1 < r1; l1 >>= 1, r1 >>= 1) {\n            if (l1 & 1) _add_edge(l1+2*n,\
    \ idx, 0), l1++;\n            if (r1 & 1) --r1, _add_edge(r1+2*n, idx, 0);\n \
    \       }\n        vector<edge> node;\n        for (l2 += n, r2 += n; l2 < r2;\
    \ l2 >>= 1, r2 >>= 1) {\n            if (l2 & 1) node.push_back({l2++, w});\n\
    \            if (r2 & 1) node.push_back({--r2, w});\n        }\n        g.push_back(node);\n\
    \    }\n\n    // from u to v\n    void add_edge(int u, int v, W w) {\n       \
    \ add_edge(u, u+1, v, v+1, w);\n    }\n\n    vector<W> dijkstra(int s) {\n   \
    \     s += n;\n        vector<W> dist(g.size(), INF);\n        dist[s] = 0;\n\
    \        using P = pair<W, int>;\n        priority_queue<P, vector<P>, greater<P>>\
    \ que;\n        que.emplace(0, s);\n        while (!que.empty()) {\n         \
    \   P p = que.top();\n            que.pop();\n            int v = p.second;\n\
    \            if (dist[v] < p.first) continue;\n            for (edge& e : g[v])\
    \ {\n                if (dist[e.to] > dist[v] + e.weight) {\n                \
    \    dist[e.to] = dist[v] + e.weight;\n                    que.emplace(dist[e.to],\
    \ e.to);\n                }\n            }\n        }\n        vector<W> res(dist.begin()\
    \ + n, dist.begin() + 2*n);\n        return res;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/RangeEdgeGraph.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/RangeEdgeGraph.hpp
layout: document
redirect_from:
- /library/src/graph/RangeEdgeGraph.hpp
- /library/src/graph/RangeEdgeGraph.hpp.html
title: src/graph/RangeEdgeGraph.hpp
---
