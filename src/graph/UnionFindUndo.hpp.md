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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/union-find/union-find-undo.cpp
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
    \n    void rollback() {\n        while (history.size()) undo();\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/union-find/union-find-undo.cpp\n\
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
    \n    void rollback() {\n        while (history.size()) undo();\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/UnionFindUndo.hpp
  requiredBy:
  - src/graph/OfflineDynamicConnectivity.hpp
  timestamp: '2022-05-22 00:24:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/UnionFindUndo.hpp
layout: document
redirect_from:
- /library/src/graph/UnionFindUndo.hpp
- /library/src/graph/UnionFindUndo.hpp.html
title: src/graph/UnionFindUndo.hpp
---
