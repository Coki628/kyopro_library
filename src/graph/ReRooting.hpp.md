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
    - https://ei1333.github.io/library/graph/tree/rerooting.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/graph/ReRooting.hpp\"\n\n// \u5168\u65B9\u4F4D\
    \u6728DP\n// see: https://ei1333.github.io/library/graph/tree/rerooting.hpp\n\
    // \u30FB\u4E3B\u306A\u4F7F\u7528\u65B9\u6CD5\n// \u3000\u30FBf1\u306F\u96C6\u5408\
    \u540C\u58EB\u306E\u30DE\u30FC\u30B8\u3001f2\u306F\u3042\u308B\u96C6\u5408\u306B\
    \u65B0\u3057\u304F\u8FBA\u3092\u53D6\u308A\u8FBC\u3080\u6642\u306E\u30DE\u30FC\
    \u30B8\u306B\u4F7F\u3046\u3002\n// \u3000\u3000\u4F8B\u3048\u3070\u666E\u901A\u306E\
    \u6728DP\u306E\u9077\u79FB\u304C dp[u] += dp[v]+1 \u3060\u3063\u305F\u3089\u3001\
    \n// \u3000\u3000f1\u304C dp[u]+dp[v] \u3067\u3001f2\u304C dp[v]+1 \u306B\u76F8\
    \u5F53\u3059\u308B\u611F\u3058\u3002\ntemplate<typename sum_t, typename key_t,\
    \ typename F1, typename F2>\nstruct ReRooting {\n    struct Edge {\n        int\
    \ to;\n        key_t data;\n        sum_t dp, ndp;\n    };\n\n    vector<vector<Edge>>\
    \ g;\n    const F1 f1;\n    const F2 f2;\n    const sum_t ident;\n    vector<sum_t>\
    \ subdp, dp;\n\n    ReRooting(int V, const F1 f1, const F2 f2, const sum_t &ident)\n\
    \        : g(V),\n          f1(f1),\n          f2(f2),\n          ident(ident),\n\
    \          subdp(V, ident),\n          dp(V, ident) {\n    }\n\n    // \u7121\u5411\
    \ u<->v\u4E21\u65B9\u5411\u3078\u306E\u9077\u79FB\u306Bd\u3092\u6E21\u3059\n \
    \   void add_edge(int u, int v, const key_t &d) {\n        g[u].emplace_back((Edge){v,\
    \ d, ident, ident});\n        g[v].emplace_back((Edge){u, d, ident, ident});\n\
    \    }\n\n    // u<-v\u3078\u306E\u9077\u79FB\u306Bd\u3001v<-u\u3078\u306E\u9077\
    \u79FB\u306Be \u3092\u6E21\u3059\n    void add_edge(int u, int v, const key_t\
    \ &d, const key_t &e) {\n        g[u].emplace_back((Edge){v, d, ident, ident});\n\
    \        g[v].emplace_back((Edge){u, e, ident, ident});\n    }\n\n    void dfs_sub(int\
    \ idx, int par) {\n        for (auto &e : g[idx]) {\n            if (e.to == par)\
    \ continue;\n            dfs_sub(e.to, idx);\n            subdp[idx] = f1(subdp[idx],\
    \ f2(subdp[e.to], e.data));\n        }\n    }\n\n    void dfs_all(int idx, int\
    \ par, const sum_t &top) {\n        sum_t buff{ident};\n        for (int i = 0;\
    \ i < (int)g[idx].size(); i++) {\n            auto &e = g[idx][i];\n         \
    \   e.ndp = buff;\n            e.dp = f2(par == e.to ? top : subdp[e.to], e.data);\n\
    \            buff = f1(buff, e.dp);\n        }\n        dp[idx] = buff;\n    \
    \    buff = ident;\n        for (int i = (int)g[idx].size() - 1; i >= 0; i--)\
    \ {\n            auto &e = g[idx][i];\n            if (e.to != par) dfs_all(e.to,\
    \ idx, f1(e.ndp, buff));\n            e.ndp = f1(e.ndp, buff);\n            buff\
    \ = f1(buff, e.dp);\n        }\n    }\n\n    vector<sum_t> build() {\n       \
    \ dfs_sub(0, -1);\n        dfs_all(0, -1, ident);\n        return dp;\n    }\n\
    };\n\ntemplate<typename sum_t, typename key_t, typename F1, typename F2>\nReRooting<sum_t,\
    \ key_t, F1, F2> get_rerooting(\n    int N, const F1 &f1, const F2 &f2, const\
    \ sum_t &M1, const key_t &M2\n) {\n    return {N, f1, f2, M1};\n}\n\n// auto f1\
    \ = [](sum_t a, sum_t b) -> sum_t {\n//     return merge(a, b);\n// };\n// auto\
    \ f2 = [](sum_t a, key_t v) -> sum_t {\n//     return add(a, v);\n// };\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u5168\u65B9\u4F4D\u6728DP\n\
    // see: https://ei1333.github.io/library/graph/tree/rerooting.hpp\n// \u30FB\u4E3B\
    \u306A\u4F7F\u7528\u65B9\u6CD5\n// \u3000\u30FBf1\u306F\u96C6\u5408\u540C\u58EB\
    \u306E\u30DE\u30FC\u30B8\u3001f2\u306F\u3042\u308B\u96C6\u5408\u306B\u65B0\u3057\
    \u304F\u8FBA\u3092\u53D6\u308A\u8FBC\u3080\u6642\u306E\u30DE\u30FC\u30B8\u306B\
    \u4F7F\u3046\u3002\n// \u3000\u3000\u4F8B\u3048\u3070\u666E\u901A\u306E\u6728\
    DP\u306E\u9077\u79FB\u304C dp[u] += dp[v]+1 \u3060\u3063\u305F\u3089\u3001\n//\
    \ \u3000\u3000f1\u304C dp[u]+dp[v] \u3067\u3001f2\u304C dp[v]+1 \u306B\u76F8\u5F53\
    \u3059\u308B\u611F\u3058\u3002\ntemplate<typename sum_t, typename key_t, typename\
    \ F1, typename F2>\nstruct ReRooting {\n    struct Edge {\n        int to;\n \
    \       key_t data;\n        sum_t dp, ndp;\n    };\n\n    vector<vector<Edge>>\
    \ g;\n    const F1 f1;\n    const F2 f2;\n    const sum_t ident;\n    vector<sum_t>\
    \ subdp, dp;\n\n    ReRooting(int V, const F1 f1, const F2 f2, const sum_t &ident)\n\
    \        : g(V),\n          f1(f1),\n          f2(f2),\n          ident(ident),\n\
    \          subdp(V, ident),\n          dp(V, ident) {\n    }\n\n    // \u7121\u5411\
    \ u<->v\u4E21\u65B9\u5411\u3078\u306E\u9077\u79FB\u306Bd\u3092\u6E21\u3059\n \
    \   void add_edge(int u, int v, const key_t &d) {\n        g[u].emplace_back((Edge){v,\
    \ d, ident, ident});\n        g[v].emplace_back((Edge){u, d, ident, ident});\n\
    \    }\n\n    // u<-v\u3078\u306E\u9077\u79FB\u306Bd\u3001v<-u\u3078\u306E\u9077\
    \u79FB\u306Be \u3092\u6E21\u3059\n    void add_edge(int u, int v, const key_t\
    \ &d, const key_t &e) {\n        g[u].emplace_back((Edge){v, d, ident, ident});\n\
    \        g[v].emplace_back((Edge){u, e, ident, ident});\n    }\n\n    void dfs_sub(int\
    \ idx, int par) {\n        for (auto &e : g[idx]) {\n            if (e.to == par)\
    \ continue;\n            dfs_sub(e.to, idx);\n            subdp[idx] = f1(subdp[idx],\
    \ f2(subdp[e.to], e.data));\n        }\n    }\n\n    void dfs_all(int idx, int\
    \ par, const sum_t &top) {\n        sum_t buff{ident};\n        for (int i = 0;\
    \ i < (int)g[idx].size(); i++) {\n            auto &e = g[idx][i];\n         \
    \   e.ndp = buff;\n            e.dp = f2(par == e.to ? top : subdp[e.to], e.data);\n\
    \            buff = f1(buff, e.dp);\n        }\n        dp[idx] = buff;\n    \
    \    buff = ident;\n        for (int i = (int)g[idx].size() - 1; i >= 0; i--)\
    \ {\n            auto &e = g[idx][i];\n            if (e.to != par) dfs_all(e.to,\
    \ idx, f1(e.ndp, buff));\n            e.ndp = f1(e.ndp, buff);\n            buff\
    \ = f1(buff, e.dp);\n        }\n    }\n\n    vector<sum_t> build() {\n       \
    \ dfs_sub(0, -1);\n        dfs_all(0, -1, ident);\n        return dp;\n    }\n\
    };\n\ntemplate<typename sum_t, typename key_t, typename F1, typename F2>\nReRooting<sum_t,\
    \ key_t, F1, F2> get_rerooting(\n    int N, const F1 &f1, const F2 &f2, const\
    \ sum_t &M1, const key_t &M2\n) {\n    return {N, f1, f2, M1};\n}\n\n// auto f1\
    \ = [](sum_t a, sum_t b) -> sum_t {\n//     return merge(a, b);\n// };\n// auto\
    \ f2 = [](sum_t a, key_t v) -> sum_t {\n//     return add(a, v);\n// };\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/ReRooting.hpp
  requiredBy: []
  timestamp: '2024-06-25 17:52:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/ReRooting.hpp
layout: document
redirect_from:
- /library/src/graph/ReRooting.hpp
- /library/src/graph/ReRooting.hpp.html
title: src/graph/ReRooting.hpp
---