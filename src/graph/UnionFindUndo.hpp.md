---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/OfflineDynamicConnectivity.hpp
    title: src/graph/OfflineDynamicConnectivity.hpp
  - icon: ':warning:'
    path: src/graph/_OfflineDynamicConnectivity.hpp
    title: src/graph/_OfflineDynamicConnectivity.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/union-find/union-find-undo.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/graph/UnionFindUndo.hpp\"\n\n// undo\u53EF\u80FD\
    UF\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/union-find/union-find-undo.cpp\n\
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
    \ {\n        while (history.size()) undo();\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// undo\u53EF\u80FDUF\n// \u53C2\
    \u8003\uFF1Ahttps://ei1333.github.io/library/structure/union-find/union-find-undo.cpp\n\
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
    \ {\n        while (history.size()) undo();\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/UnionFindUndo.hpp
  requiredBy:
  - src/graph/OfflineDynamicConnectivity.hpp
  - src/graph/_OfflineDynamicConnectivity.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/UnionFindUndo.hpp
layout: document
redirect_from:
- /library/src/graph/UnionFindUndo.hpp
- /library/src/graph/UnionFindUndo.hpp.html
title: src/graph/UnionFindUndo.hpp
---
