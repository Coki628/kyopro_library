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
    - https://atcoder.jp/contests/abc334/submissions/48778004
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/graph/UnionFindUndo.hpp\"\n\n// undo\u53EF\
    \u80FDUF\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/union-find/union-find-undo.cpp\n\
    // \u30FB\u30AA\u30D5\u30E9\u30A4\u30F3\u30C0\u30A4\u30B3\u30CD\u306E\u6539\u4FEE\
    \u306B\u5408\u308F\u305B\u3066\u3053\u3061\u3089\u3082\u6539\u4FEE\u3057\u305F\
    \u3002\n// \u3000\u3068\u8A00\u3063\u3066\u3082\u3001\u975E\u518D\u5E30\u5316\u3057\
    \u305F\u308A\u5185\u90E8\u5B9F\u88C5\u306E\u5909\u66F4\u306A\u306E\u3067\u64CD\
    \u4F5C\u65B9\u6CD5\u306F\u5909\u308F\u3063\u3066\u306A\u3044\u3002\nstruct UnionFindUndo\
    \ {\n    vector<int> data;\n    vector<pair<pair<int, int>, int>> history;\n \
    \   int n, groupcnt;\n\n    UnionFindUndo(int sz) : n(sz), groupcnt(sz) {\n  \
    \      data.assign(sz, -1);\n    }\n\n    template<typename F>\n    int merge(int\
    \ x, int y, F f) {\n        x = find(x);\n        y = find(y);\n        if (x\
    \ == y) return -1;\n        if (data[x] > data[y]) swap(x, y);\n        f(x, y);\n\
    \        history.push_back({{x, y}, data[y]});\n        groupcnt--;\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        return x;\n    }\n\n    int merge(int\
    \ a, int b) {\n        return merge(a, b, [](int r, int ch) {});\n    }\n\n  \
    \  int find(int v) {\n        while (data[v] >= 0) v = data[v];\n        return\
    \ v;\n    }\n\n    bool same(int x, int y) {\n        return find(x) == find(y);\n\
    \    }\n\n    int size(int k) {\n        return -data[find(k)];\n    }\n\n   \
    \ int size() {\n        return groupcnt;\n    }\n\n    pair<int, int> undo() {\n\
    \        int v = history.back().first.first;\n        int w = history.back().first.second;\n\
    \        int ufw = history.back().second;\n        history.pop_back();\n     \
    \   data[w] = ufw;\n        data[v] -= data[w];\n        groupcnt++;\n       \
    \ // undo\u5F8C\u306E\u4EE3\u8868\u70B9(v,w)\u3092\u8FD4\u3059\n        return\
    \ {v, w};\n    }\n\n    // \u76F4\u524Dt\u56DE\u306E\u64CD\u4F5C\u3092\u623B\u3059\
    \n    void undo(int t) {\n        while (t--) undo();\n    }\n\n    void rollback()\
    \ {\n        while (history.size()) undo();\n    }\n};\n#line 4 \"src/graph/OfflineDynamicConnectivity.hpp\"\
    \n\n// \u30AA\u30D5\u30E9\u30A4\u30F3\u30C0\u30A4\u30B3\u30CD\n// see: https://atcoder.jp/contests/abc334/submissions/48778004\n\
    // \u4F7F\u3044\u65B9\u53CA\u3073\u65E7\u30E9\u30A4\u30D6\u30E9\u30EA\u3068\u306E\
    \u76F8\u9055\u70B9\n// \u30FB\u521D\u671F\u5316\u6642\u306B\u30AF\u30A8\u30EA\u6570\
    \u306F\u6E21\u3055\u306A\u304F\u3066\u3044\u3044\u3002\n// \u30FB\u4E00\u9023\u306E\
    \u8FBA\u306E\u4ED8\u3051\u5916\u3057\u3092add_edge,remove_edge\u3067\u8A18\u9332\
    \u3059\u308B\u3002\n// \u30FB\u3042\u3068\u3067\u72B6\u614B\u78BA\u8A8D\u3057\u305F\
    \u3044\u30BF\u30A4\u30DF\u30F3\u30B0\u3067query\u3092\u5B9F\u884C\u3057\u3066\u304A\
    \u304F\u3002\n// \u3000\u3053\u306E\u6642\u3001\u7D4C\u904E\u6642\u9593\u3092\u8FD4\
    \u3059\u306E\u3067\u3001\u5FC5\u8981\u306A\u3089\u53D6\u3063\u3066\u304A\u304F\
    \u3002\n// \u30FB\u5168\u3066\u306E\u64CD\u4F5C\u304C\u7D42\u308F\u3063\u305F\u3089\
    solve\u3092\u5B9F\u884C\u3002\n// \u3000\u524D\u3082\u3063\u3066query\u3092\u5B9F\
    \u884C\u3057\u305F\u30BF\u30A4\u30DF\u30F3\u30B0\u3067\u3001\u3053\u306E\u6642\
    \u6E21\u3057\u305F\u95A2\u6570f\u3092\u5B9F\u884C\u3057\u3066\u304F\u308C\u308B\
    \u3002\n// \u3000\u3053\u306E\u95A2\u6570f\u306E\u5F15\u6570\u306B\u306F\u7D4C\
    \u904E\u6642\u9593\u304C\u6E21\u3055\u308C\u308B\u306E\u3067\u3001\u5FC5\u8981\
    \u306B\u5FDC\u3058\u3066\u9069\u5B9C\u30AF\u30A8\u30EA\u756A\u53F7\u306A\u3069\
    \u3068\u7D10\u4ED8\u3051\u308B\u3002\n// \u30FB\u306A\u304A\u3001\u7D4C\u904E\u6642\
    \u9593\u306Fadd_edge,remove_edge,query\u3092\u4F7F\u3046\u5EA6\u306B1\u305A\u3064\
    \u5897\u3048\u308B\u3002\n// \u30FBsolve\u306B\u3001pre_add,post_remove\u3068\u3044\
    \u3046\u95A2\u6570\u3092\u30AA\u30D7\u30B7\u30E7\u30F3\u3067\u6E21\u305B\u308B\
    \u3088\u3046\u306B\u3057\u3066\u3001\n// \u3000\u30DE\u30FC\u30B8\u524D\u3068\
    undo\u5F8C\u306B\u4F55\u304B\u898B\u305F\u3044\u6642\u306B\u5BFE\u5FDC\u3067\u304D\
    \u308B\u3088\u3046\u306B\u3057\u305F\u3002\n// \u3000\u3053\u308C\u3089\u306E\u95A2\
    \u6570\u306E\u5F15\u6570\u306B\u306F\u30DE\u30FC\u30B8\u3068undo\u306B\u95A2\u308F\
    \u3063\u305F2\u3064\u306E\u4EE3\u8868\u70B9\u304C\u6E21\u3055\u308C\u308B\u3002\
    \nclass OfflineDynamicConnectivity {\nprivate:\n    struct Query {\n        int\
    \ type, v, w, otherTime;\n    };\n\n    int V, curTime;\n    vector<Query> queries;\n\
    \    vector<map<int, int>> presentEdges;\n\n    template<typename F>\n    void\
    \ solve(F f, int l, int r, const auto &pre_add, const auto &post_remove) {\n \
    \       if (l >= r) {\n            if (l == r && queries[r].type == 0) {\n   \
    \             f(r);\n            }\n            return;\n        }\n        int\
    \ m = l + (r - l) / 2;\n        int curSize = uf.history.size();\n        for\
    \ (int i = m + 1; i <= r; i++) {\n            if (queries[i].otherTime < l) {\n\
    \                pre_add(queries[i].v, queries[i].w);\n                uf.merge(queries[i].v,\
    \ queries[i].w);\n            }\n        }\n        solve(f, l, m, pre_add, post_remove);\n\
    \        while ((int)uf.history.size() > curSize) {\n            auto [v, w] =\
    \ uf.undo();\n            post_remove(v, w);\n        }\n        for (int i =\
    \ l; i <= m; i++) {\n            if (queries[i].otherTime > r) {\n           \
    \     pre_add(queries[i].v, queries[i].w);\n                uf.merge(queries[i].v,\
    \ queries[i].w);\n            }\n        }\n        solve(f, m + 1, r, pre_add,\
    \ post_remove);\n        while ((int)uf.history.size() > curSize) {\n        \
    \    auto [v, w] = uf.undo();\n            post_remove(v, w);\n        }\n   \
    \ }\n\npublic:\n    UnionFindUndo uf;\n\n    OfflineDynamicConnectivity(int V)\n\
    \        : V(V),\n          curTime(0),\n          uf(V),\n          presentEdges(V)\
    \ {\n    }\n\n    void add_edge(int v, int w) {\n        if (v > w) swap(v, w);\n\
    \        presentEdges[v][w] = curTime++;\n        queries.push_back({1, v, w,\
    \ INT_MAX});\n    }\n\n    void remove_edge(int v, int w) {\n        if (v > w)\
    \ swap(v, w);\n        int insTime = presentEdges[v][w];\n        queries.push_back({-1,\
    \ v, w, insTime});\n        queries[insTime].otherTime = curTime++;\n        presentEdges[v].erase(w);\n\
    \    }\n\n    int query() {\n        queries.push_back({0, -1, -1, curTime++});\n\
    \        return curTime - 1;\n    }\n\n    template<typename F>\n    void solve(F\
    \ f) {\n        solve(f, 0, curTime - 1, [](int v, int w) {}, [](int v, int w)\
    \ {});\n    }\n\n    template<typename F>\n    void solve(F f, const auto &pre_add,\
    \ const auto &post_remove) {\n        solve(f, 0, curTime - 1, pre_add, post_remove);\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"UnionFindUndo.hpp\"\n\n\
    // \u30AA\u30D5\u30E9\u30A4\u30F3\u30C0\u30A4\u30B3\u30CD\n// see: https://atcoder.jp/contests/abc334/submissions/48778004\n\
    // \u4F7F\u3044\u65B9\u53CA\u3073\u65E7\u30E9\u30A4\u30D6\u30E9\u30EA\u3068\u306E\
    \u76F8\u9055\u70B9\n// \u30FB\u521D\u671F\u5316\u6642\u306B\u30AF\u30A8\u30EA\u6570\
    \u306F\u6E21\u3055\u306A\u304F\u3066\u3044\u3044\u3002\n// \u30FB\u4E00\u9023\u306E\
    \u8FBA\u306E\u4ED8\u3051\u5916\u3057\u3092add_edge,remove_edge\u3067\u8A18\u9332\
    \u3059\u308B\u3002\n// \u30FB\u3042\u3068\u3067\u72B6\u614B\u78BA\u8A8D\u3057\u305F\
    \u3044\u30BF\u30A4\u30DF\u30F3\u30B0\u3067query\u3092\u5B9F\u884C\u3057\u3066\u304A\
    \u304F\u3002\n// \u3000\u3053\u306E\u6642\u3001\u7D4C\u904E\u6642\u9593\u3092\u8FD4\
    \u3059\u306E\u3067\u3001\u5FC5\u8981\u306A\u3089\u53D6\u3063\u3066\u304A\u304F\
    \u3002\n// \u30FB\u5168\u3066\u306E\u64CD\u4F5C\u304C\u7D42\u308F\u3063\u305F\u3089\
    solve\u3092\u5B9F\u884C\u3002\n// \u3000\u524D\u3082\u3063\u3066query\u3092\u5B9F\
    \u884C\u3057\u305F\u30BF\u30A4\u30DF\u30F3\u30B0\u3067\u3001\u3053\u306E\u6642\
    \u6E21\u3057\u305F\u95A2\u6570f\u3092\u5B9F\u884C\u3057\u3066\u304F\u308C\u308B\
    \u3002\n// \u3000\u3053\u306E\u95A2\u6570f\u306E\u5F15\u6570\u306B\u306F\u7D4C\
    \u904E\u6642\u9593\u304C\u6E21\u3055\u308C\u308B\u306E\u3067\u3001\u5FC5\u8981\
    \u306B\u5FDC\u3058\u3066\u9069\u5B9C\u30AF\u30A8\u30EA\u756A\u53F7\u306A\u3069\
    \u3068\u7D10\u4ED8\u3051\u308B\u3002\n// \u30FB\u306A\u304A\u3001\u7D4C\u904E\u6642\
    \u9593\u306Fadd_edge,remove_edge,query\u3092\u4F7F\u3046\u5EA6\u306B1\u305A\u3064\
    \u5897\u3048\u308B\u3002\n// \u30FBsolve\u306B\u3001pre_add,post_remove\u3068\u3044\
    \u3046\u95A2\u6570\u3092\u30AA\u30D7\u30B7\u30E7\u30F3\u3067\u6E21\u305B\u308B\
    \u3088\u3046\u306B\u3057\u3066\u3001\n// \u3000\u30DE\u30FC\u30B8\u524D\u3068\
    undo\u5F8C\u306B\u4F55\u304B\u898B\u305F\u3044\u6642\u306B\u5BFE\u5FDC\u3067\u304D\
    \u308B\u3088\u3046\u306B\u3057\u305F\u3002\n// \u3000\u3053\u308C\u3089\u306E\u95A2\
    \u6570\u306E\u5F15\u6570\u306B\u306F\u30DE\u30FC\u30B8\u3068undo\u306B\u95A2\u308F\
    \u3063\u305F2\u3064\u306E\u4EE3\u8868\u70B9\u304C\u6E21\u3055\u308C\u308B\u3002\
    \nclass OfflineDynamicConnectivity {\nprivate:\n    struct Query {\n        int\
    \ type, v, w, otherTime;\n    };\n\n    int V, curTime;\n    vector<Query> queries;\n\
    \    vector<map<int, int>> presentEdges;\n\n    template<typename F>\n    void\
    \ solve(F f, int l, int r, const auto &pre_add, const auto &post_remove) {\n \
    \       if (l >= r) {\n            if (l == r && queries[r].type == 0) {\n   \
    \             f(r);\n            }\n            return;\n        }\n        int\
    \ m = l + (r - l) / 2;\n        int curSize = uf.history.size();\n        for\
    \ (int i = m + 1; i <= r; i++) {\n            if (queries[i].otherTime < l) {\n\
    \                pre_add(queries[i].v, queries[i].w);\n                uf.merge(queries[i].v,\
    \ queries[i].w);\n            }\n        }\n        solve(f, l, m, pre_add, post_remove);\n\
    \        while ((int)uf.history.size() > curSize) {\n            auto [v, w] =\
    \ uf.undo();\n            post_remove(v, w);\n        }\n        for (int i =\
    \ l; i <= m; i++) {\n            if (queries[i].otherTime > r) {\n           \
    \     pre_add(queries[i].v, queries[i].w);\n                uf.merge(queries[i].v,\
    \ queries[i].w);\n            }\n        }\n        solve(f, m + 1, r, pre_add,\
    \ post_remove);\n        while ((int)uf.history.size() > curSize) {\n        \
    \    auto [v, w] = uf.undo();\n            post_remove(v, w);\n        }\n   \
    \ }\n\npublic:\n    UnionFindUndo uf;\n\n    OfflineDynamicConnectivity(int V)\n\
    \        : V(V),\n          curTime(0),\n          uf(V),\n          presentEdges(V)\
    \ {\n    }\n\n    void add_edge(int v, int w) {\n        if (v > w) swap(v, w);\n\
    \        presentEdges[v][w] = curTime++;\n        queries.push_back({1, v, w,\
    \ INT_MAX});\n    }\n\n    void remove_edge(int v, int w) {\n        if (v > w)\
    \ swap(v, w);\n        int insTime = presentEdges[v][w];\n        queries.push_back({-1,\
    \ v, w, insTime});\n        queries[insTime].otherTime = curTime++;\n        presentEdges[v].erase(w);\n\
    \    }\n\n    int query() {\n        queries.push_back({0, -1, -1, curTime++});\n\
    \        return curTime - 1;\n    }\n\n    template<typename F>\n    void solve(F\
    \ f) {\n        solve(f, 0, curTime - 1, [](int v, int w) {}, [](int v, int w)\
    \ {});\n    }\n\n    template<typename F>\n    void solve(F f, const auto &pre_add,\
    \ const auto &post_remove) {\n        solve(f, 0, curTime - 1, pre_add, post_remove);\n\
    \    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/graph/UnionFindUndo.hpp
  isVerificationFile: false
  path: src/graph/OfflineDynamicConnectivity.hpp
  requiredBy: []
  timestamp: '2023-12-27 10:46:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/OfflineDynamicConnectivity.hpp
layout: document
redirect_from:
- /library/src/graph/OfflineDynamicConnectivity.hpp
- /library/src/graph/OfflineDynamicConnectivity.hpp.html
title: src/graph/OfflineDynamicConnectivity.hpp
---
