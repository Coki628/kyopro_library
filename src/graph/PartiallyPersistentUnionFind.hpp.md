---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/graph/PartiallyPersistentUnionFind.hpp\"\n\
    \n// \u90E8\u5206\u6C38\u7D9AUF\nstruct PartiallyPersistentUnionFind {\n\n   \
    \ int n;\n    vector<int> par, last;\n    vector<vector<pair<int, int>>> history;\n\
    \n    PartiallyPersistentUnionFind(int n) : n(n) {\n        // x\u304C\u6839\u306E\
    \u3068\u304D\u306Fx\u3092\u542B\u3080\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\
    \u30BA(\u306E-1\u500D)\u3001\u305D\u3046\u3067\u306A\u3044\u3068\u304D\u306F\u89AA\
    \u30CE\u30FC\u30C9\n        par.resize(n, -1);\n        // \u6700\u5F8C\u306B\u300C\
    \u6839\u300D\u3067\u306F\u306A\u304F\u306A\u3063\u305F\u77AC\u9593\u306E\u6642\
    \u523B\n        last.resize(n, -1);\n        history.resize(n);\n        for (auto\
    \ &vec : history) vec.emplace_back(-1, -1);\n    }\n\n    PartiallyPersistentUnionFind()\
    \ {}\n\n    // \u6839\u306E\u691C\u7D22(\u30B0\u30EB\u30FC\u30D7\u756A\u53F7)\n\
    \    int find(int t, int x) {\n        // \u6839\u306A\u3089\u305D\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059\n        if (last[x] == -1 || t < last[x]) {\n      \
    \      return x;\n        } else {\n            return find(t, par[x]);\n    \
    \    }\n    }\n\n    // \u6642\u523Bt\u306Ba,b\u3092\u4F75\u5408\n    bool merge(int\
    \ t, int a, int b) {\n        // \u6839\u3092\u63A2\u3059\n        int x = find(t,\
    \ a);\n        int y = find(t, b);\n        if (x == y) {\n            return\
    \ false;\n        }\n        // \u8981\u7D20\u6570\u306E\u5C11\u306A\u3044\u65B9\
    \u3092\u4ED8\u3051\u66FF\u3048\u308B(\u30DE\u30FC\u30B8\u30C6\u30AF)\n       \
    \ if (par[x] > par[y]) {\n            swap(x, y);\n        }\n        // x\u306B\
    y\u3092\u4ED8\u3051\u308B\n        par[x] += par[y];\n        par[y] = x;\n  \
    \      last[y] = t;\n        history[x].emplace_back(t, par[x]);\n        return\
    \ true;\n    }\n\n    // \u6642\u523Bt\u306B\u540C\u3058\u96C6\u5408\u306B\u5C5E\
    \u3059\u308B\u304B\u5224\u5B9A\n    bool same(int t, int a, int b) {\n       \
    \ return find(t, a) == find(t, b);\n    }\n\n    // \u6642\u523Bt\u306B\u9802\u70B9\
    x\u3092\u542B\u3080\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\n    int size(int\
    \ t, int x) {\n        x = find(t, x);\n        return -prev(lower_bound(history[x].begin(),\
    \ history[x].end(), make_pair(t, 0)))->second;\n    }\n};\n"
  code: "#include \"../base.hpp\"\n\n// \u90E8\u5206\u6C38\u7D9AUF\nstruct PartiallyPersistentUnionFind\
    \ {\n\n    int n;\n    vector<int> par, last;\n    vector<vector<pair<int, int>>>\
    \ history;\n\n    PartiallyPersistentUnionFind(int n) : n(n) {\n        // x\u304C\
    \u6839\u306E\u3068\u304D\u306Fx\u3092\u542B\u3080\u30B0\u30EB\u30FC\u30D7\u306E\
    \u30B5\u30A4\u30BA(\u306E-1\u500D)\u3001\u305D\u3046\u3067\u306A\u3044\u3068\u304D\
    \u306F\u89AA\u30CE\u30FC\u30C9\n        par.resize(n, -1);\n        // \u6700\u5F8C\
    \u306B\u300C\u6839\u300D\u3067\u306F\u306A\u304F\u306A\u3063\u305F\u77AC\u9593\
    \u306E\u6642\u523B\n        last.resize(n, -1);\n        history.resize(n);\n\
    \        for (auto &vec : history) vec.emplace_back(-1, -1);\n    }\n\n    PartiallyPersistentUnionFind()\
    \ {}\n\n    // \u6839\u306E\u691C\u7D22(\u30B0\u30EB\u30FC\u30D7\u756A\u53F7)\n\
    \    int find(int t, int x) {\n        // \u6839\u306A\u3089\u305D\u306E\u756A\
    \u53F7\u3092\u8FD4\u3059\n        if (last[x] == -1 || t < last[x]) {\n      \
    \      return x;\n        } else {\n            return find(t, par[x]);\n    \
    \    }\n    }\n\n    // \u6642\u523Bt\u306Ba,b\u3092\u4F75\u5408\n    bool merge(int\
    \ t, int a, int b) {\n        // \u6839\u3092\u63A2\u3059\n        int x = find(t,\
    \ a);\n        int y = find(t, b);\n        if (x == y) {\n            return\
    \ false;\n        }\n        // \u8981\u7D20\u6570\u306E\u5C11\u306A\u3044\u65B9\
    \u3092\u4ED8\u3051\u66FF\u3048\u308B(\u30DE\u30FC\u30B8\u30C6\u30AF)\n       \
    \ if (par[x] > par[y]) {\n            swap(x, y);\n        }\n        // x\u306B\
    y\u3092\u4ED8\u3051\u308B\n        par[x] += par[y];\n        par[y] = x;\n  \
    \      last[y] = t;\n        history[x].emplace_back(t, par[x]);\n        return\
    \ true;\n    }\n\n    // \u6642\u523Bt\u306B\u540C\u3058\u96C6\u5408\u306B\u5C5E\
    \u3059\u308B\u304B\u5224\u5B9A\n    bool same(int t, int a, int b) {\n       \
    \ return find(t, a) == find(t, b);\n    }\n\n    // \u6642\u523Bt\u306B\u9802\u70B9\
    x\u3092\u542B\u3080\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\n    int size(int\
    \ t, int x) {\n        x = find(t, x);\n        return -prev(lower_bound(history[x].begin(),\
    \ history[x].end(), make_pair(t, 0)))->second;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/PartiallyPersistentUnionFind.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/PartiallyPersistentUnionFind.hpp
layout: document
redirect_from:
- /library/src/graph/PartiallyPersistentUnionFind.hpp
- /library/src/graph/PartiallyPersistentUnionFind.hpp.html
title: src/graph/PartiallyPersistentUnionFind.hpp
---
