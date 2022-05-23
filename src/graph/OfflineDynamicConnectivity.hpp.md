---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/graph/UnionFindUndo.hpp
    title: src/graph/UnionFindUndo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/other/offline-dynamic-connectivity.cpp
    - https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/graph/UnionFindUndo.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/structure/union-find/union-find-undo.cpp\n\
    // undo\u53EF\u80FDUF\nstruct UnionFindUndo {\n    vector< int > data;\n    stack<\
    \ pair< int, int > > history;\n\n    UnionFindUndo(int sz) {\n        data.assign(sz,\
    \ -1);\n    }\n\n    bool merge(int x, int y) {\n        x = find(x), y = find(y);\n\
    \        history.emplace(x, data[x]);\n        history.emplace(y, data[y]);\n\
    \        if (x == y) return false;\n        if (data[x] > data[y]) swap(x, y);\n\
    \        data[x] += data[y];\n        data[y] = x;\n        return true;\n   \
    \ }\n\n    int find(int k) {\n        if (data[k] < 0) return (k);\n        return\
    \ find(data[k]);\n    }\n\n    bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n\n    int size(int k) {\n        return -data[find(k)];\n\
    \    }\n\n    void undo() {\n        data[history.top().first] = history.top().second;\n\
    \        history.pop();\n        data[history.top().first] = history.top().second;\n\
    \        history.pop();\n    }\n\n    // \u76F4\u524Dt\u56DE\u306E\u64CD\u4F5C\
    \u3092\u623B\u3059\n    void undo(int t) {\n        while (t--) undo();\n    }\n\
    \n    void snapshot() {\n        while (history.size()) history.pop();\n    }\n\
    \n    void rollback() {\n        while (history.size()) undo();\n    }\n};\n#line\
    \ 3 \"src/graph/OfflineDynamicConnectivity.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/other/offline-dynamic-connectivity.cpp\n\
    // \u3000\u3000\u3000https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html\n\
    // \u30AA\u30D5\u30E9\u30A4\u30F3\u30C0\u30A4\u30B3\u30CD\nstruct OfflineDynamicConnectivity\
    \ {\n    using edge = pair< int, int >;\n\n    UnionFindUndo uf;\n    int V, Q,\
    \ segsz;\n    vector< vector< edge > > seg;\n    // \u9023\u7D50\u6210\u5206\u6570\
    \n    int comp;\n\n    vector< pair< pair< int, int >, edge > > pend;\n    map<\
    \ edge, int > cnt, appear;\n\n    // \u9802\u70B9\u6570V\u3001Q\u500B\u306E\u30AF\
    \u30A8\u30EA\u3067\u521D\u671F\u5316\n    // (\u3053\u306EQ\u500B\u306B\u306F\u3001\
    \u8FBA\u306E\u8FFD\u52A0\u30FB\u524A\u9664\u30FB\u56DE\u7B54\u30AF\u30A8\u30EA\
    \u5168\u3066\u304C\u542B\u307E\u308C\u308B\u3002\u30AF\u30A8\u30EA\u6570\u3068\
    \u8A00\u3046\u3088\u308A\u7D4C\u904E\u6642\u9593\u306E\u6700\u5927)\n    OfflineDynamicConnectivity(int\
    \ V, int Q) : uf(V), V(V), Q(Q), comp(V) {\n        segsz = 1;\n        while\
    \ (segsz < Q) segsz <<= 1;\n        seg.resize(2 * segsz - 1);\n    }\n\n    //\
    \ \u6642\u523Bidx\u306B\u8FBA(s,t)\u3092\u8FFD\u52A0\n    void insert(int idx,\
    \ int s, int t) {\n        auto e = minmax(s, t);\n        if (cnt[e]++ == 0)\
    \ appear[e] = idx;\n    }\n\n    // \u6642\u523Bidx\u306B\u8FBA(s,t)\u3092\u524A\
    \u9664\n    void erase(int idx, int s, int t) {\n        auto e = minmax(s, t);\n\
    \        if (--cnt[e] == 0) pend.emplace_back(make_pair(appear[e], idx), e);\n\
    \    }\n\n    void add(int a, int b, const edge &e, int k, int l, int r) {\n \
    \       if (r <= a || b <= l) return;\n        if (a <= l && r <= b) {\n     \
    \       seg[k].emplace_back(e);\n            return;\n        }\n        add(a,\
    \ b, e, 2 * k + 1, l, (l + r) >> 1);\n        add(a, b, e, 2 * k + 2, (l + r)\
    \ >> 1, r);\n    }\n\n    void add(int a, int b, const edge &e) {\n        add(a,\
    \ b, e, 0, 0, segsz);\n    }\n\n    // \u30AF\u30A8\u30EA\u3092\u5168\u3066\u4E0E\
    \u3048\u305F\u5F8C\u306B\u547C\u3073\u51FA\u3059\n    void build() {\n       \
    \ for (auto &p : cnt) {\n            if (p.second > 0) pend.emplace_back(make_pair(appear[p.first],\
    \ Q), p.first);\n        }\n        for (auto &s : pend) {\n            add(s.first.first,\
    \ s.first.second, s.second);\n        }\n    }\n\n    // build()\u5B9F\u884C\u5F8C\
    \u306B\u547C\u3073\u51FA\u3059\u3001\u5404i(0<=i<Q)\u306B\u3064\u3044\u3066f(i)\u304C\
    \u547C\u3073\u51FA\u3055\u308C\u308B\n    template<typename F>\n    void run(const\
    \ F &f, int k = 0) {\n        int add = 0;\n        for (auto &e : seg[k]) {\n\
    \            add += uf.merge(e.first, e.second);\n        }\n        comp -= add;\n\
    \        if (k < segsz - 1) {\n            run(f, 2 * k + 1);\n            run(f,\
    \ 2 * k + 2);\n        } else if (k - (segsz - 1) < Q) {\n            int query_index\
    \ = k - (segsz - 1);\n            f(query_index);\n        }\n        for (auto\
    \ &e : seg[k]) {\n            uf.undo();\n        }\n        comp += add;\n  \
    \  }\n};\n"
  code: "#include \"../base.hpp\"\n#include \"UnionFindUndo.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/other/offline-dynamic-connectivity.cpp\n\
    // \u3000\u3000\u3000https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html\n\
    // \u30AA\u30D5\u30E9\u30A4\u30F3\u30C0\u30A4\u30B3\u30CD\nstruct OfflineDynamicConnectivity\
    \ {\n    using edge = pair< int, int >;\n\n    UnionFindUndo uf;\n    int V, Q,\
    \ segsz;\n    vector< vector< edge > > seg;\n    // \u9023\u7D50\u6210\u5206\u6570\
    \n    int comp;\n\n    vector< pair< pair< int, int >, edge > > pend;\n    map<\
    \ edge, int > cnt, appear;\n\n    // \u9802\u70B9\u6570V\u3001Q\u500B\u306E\u30AF\
    \u30A8\u30EA\u3067\u521D\u671F\u5316\n    // (\u3053\u306EQ\u500B\u306B\u306F\u3001\
    \u8FBA\u306E\u8FFD\u52A0\u30FB\u524A\u9664\u30FB\u56DE\u7B54\u30AF\u30A8\u30EA\
    \u5168\u3066\u304C\u542B\u307E\u308C\u308B\u3002\u30AF\u30A8\u30EA\u6570\u3068\
    \u8A00\u3046\u3088\u308A\u7D4C\u904E\u6642\u9593\u306E\u6700\u5927)\n    OfflineDynamicConnectivity(int\
    \ V, int Q) : uf(V), V(V), Q(Q), comp(V) {\n        segsz = 1;\n        while\
    \ (segsz < Q) segsz <<= 1;\n        seg.resize(2 * segsz - 1);\n    }\n\n    //\
    \ \u6642\u523Bidx\u306B\u8FBA(s,t)\u3092\u8FFD\u52A0\n    void insert(int idx,\
    \ int s, int t) {\n        auto e = minmax(s, t);\n        if (cnt[e]++ == 0)\
    \ appear[e] = idx;\n    }\n\n    // \u6642\u523Bidx\u306B\u8FBA(s,t)\u3092\u524A\
    \u9664\n    void erase(int idx, int s, int t) {\n        auto e = minmax(s, t);\n\
    \        if (--cnt[e] == 0) pend.emplace_back(make_pair(appear[e], idx), e);\n\
    \    }\n\n    void add(int a, int b, const edge &e, int k, int l, int r) {\n \
    \       if (r <= a || b <= l) return;\n        if (a <= l && r <= b) {\n     \
    \       seg[k].emplace_back(e);\n            return;\n        }\n        add(a,\
    \ b, e, 2 * k + 1, l, (l + r) >> 1);\n        add(a, b, e, 2 * k + 2, (l + r)\
    \ >> 1, r);\n    }\n\n    void add(int a, int b, const edge &e) {\n        add(a,\
    \ b, e, 0, 0, segsz);\n    }\n\n    // \u30AF\u30A8\u30EA\u3092\u5168\u3066\u4E0E\
    \u3048\u305F\u5F8C\u306B\u547C\u3073\u51FA\u3059\n    void build() {\n       \
    \ for (auto &p : cnt) {\n            if (p.second > 0) pend.emplace_back(make_pair(appear[p.first],\
    \ Q), p.first);\n        }\n        for (auto &s : pend) {\n            add(s.first.first,\
    \ s.first.second, s.second);\n        }\n    }\n\n    // build()\u5B9F\u884C\u5F8C\
    \u306B\u547C\u3073\u51FA\u3059\u3001\u5404i(0<=i<Q)\u306B\u3064\u3044\u3066f(i)\u304C\
    \u547C\u3073\u51FA\u3055\u308C\u308B\n    template<typename F>\n    void run(const\
    \ F &f, int k = 0) {\n        int add = 0;\n        for (auto &e : seg[k]) {\n\
    \            add += uf.merge(e.first, e.second);\n        }\n        comp -= add;\n\
    \        if (k < segsz - 1) {\n            run(f, 2 * k + 1);\n            run(f,\
    \ 2 * k + 2);\n        } else if (k - (segsz - 1) < Q) {\n            int query_index\
    \ = k - (segsz - 1);\n            f(query_index);\n        }\n        for (auto\
    \ &e : seg[k]) {\n            uf.undo();\n        }\n        comp += add;\n  \
    \  }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/graph/UnionFindUndo.hpp
  isVerificationFile: false
  path: src/graph/OfflineDynamicConnectivity.hpp
  requiredBy: []
  timestamp: '2022-05-22 00:24:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/OfflineDynamicConnectivity.hpp
layout: document
redirect_from:
- /library/src/graph/OfflineDynamicConnectivity.hpp
- /library/src/graph/OfflineDynamicConnectivity.hpp.html
title: src/graph/OfflineDynamicConnectivity.hpp
---
