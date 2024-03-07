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
    - https://nyaannyaan.github.io/library/tree/cartesian-tree.hpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/graph/cartesian_tree.hpp\"\n\n// Cartesian\
    \ Tree\n// see: https://nyaannyaan.github.io/library/tree/cartesian-tree.hpp\n\
    // return value : pair<graph, root>\n// \u30FB\u6E21\u3055\u308C\u305F\u6570\u5217\
    \u3092\u5143\u306B\u3001\u6839\u304B\u3089\u9806\u306B\u5024\u306E\u6607\u9806\
    \u3067\u6F5C\u3063\u3066\u3044\u304F\u3088\u3046\u306A\u4E8C\u5206\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\u3002\n// \u30FB\u4ECA\u3044\u308B\u9802\u70B9\u304C\u6700\
    \u5C0F\u5024\u3068\u306A\u308B\u7BC4\u56F2[l,r)\u304C\u5206\u304B\u308B\u3002\n\
    // \u3000(\u307E\u3042\u3053\u308C\u306Flog\u3064\u3051\u308C\u3070\u30BB\u30B0\
    \u6728\u306B\u3076\u305F\u3093\u3067\u6C42\u307E\u308B\u3093\u3060\u3051\u3069\
    \u306D)\n// \u30FB\u623B\u308A\u5024\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u306F\
    \u901A\u5E38\u306E\u30B0\u30E9\u30D5\u3068\u540C\u3058\u96A3\u63A5\u30EA\u30B9\
    \u30C8\u306E\u5F62\u306B\u3057\u305F\u306E\u3067\u3001\n// \u3000\u5FC5\u8981\u306B\
    \u5FDC\u3058\u3066\u305D\u306E\u307E\u307EHLD\u306B\u7A81\u3063\u8FBC\u3093\u3060\
    \u308A\u3067\u304D\u308B\u3002\n// \u30FB\u964D\u9806\u3067\u69CB\u7BC9\u3057\u305F\
    \u3044\u6642\u306Fis_min\u306Bfalse\u3092\u6E21\u3059\u3002\ntemplate<typename\
    \ T>\npair<vector<vector<int>>, int> cartesian_tree(vector<T> A, bool is_min =\
    \ true) {\n    int N = (int)A.size();\n    if (not is_min) {\n        for (auto\
    \ &a : A) {\n            a = -a;\n        }\n    }\n    vector<vector<int>> nodes(N);\n\
    \    vector<int> P(N, -1), st;\n    st.reserve(N);\n    for (int i = 0; i < N;\
    \ i++) {\n        int prv = -1;\n        while (!st.empty() && A[i] < A[st.back()])\
    \ {\n            prv = st.back();\n            st.pop_back();\n        }\n   \
    \     if (prv != -1) P[prv] = i;\n        if (!st.empty()) P[i] = st.back();\n\
    \        st.push_back(i);\n    }\n    int root = -1;\n    for (int i = 0; i <\
    \ N; i++) {\n        if (P[i] != -1) {\n            nodes[P[i]].push_back(i);\n\
    \        } else {\n            root = i;\n        }\n    }\n    return make_pair(nodes,\
    \ root);\n}\n\n// auto dfs = [&](auto &&f, int l, int u, int r) -> void {\n//\
    \     for (auto v : nodes[u]) {\n//         if (v < u) {\n//             f(f,\
    \ l, v, u);\n//         } else if (v > u) {\n//             f(f, u + 1, v, r);\n\
    //         }\n//     }\n// };\n// dfs(dfs, 0, root, N);\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// Cartesian Tree\n// see: https://nyaannyaan.github.io/library/tree/cartesian-tree.hpp\n\
    // return value : pair<graph, root>\n// \u30FB\u6E21\u3055\u308C\u305F\u6570\u5217\
    \u3092\u5143\u306B\u3001\u6839\u304B\u3089\u9806\u306B\u5024\u306E\u6607\u9806\
    \u3067\u6F5C\u3063\u3066\u3044\u304F\u3088\u3046\u306A\u4E8C\u5206\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\u3002\n// \u30FB\u4ECA\u3044\u308B\u9802\u70B9\u304C\u6700\
    \u5C0F\u5024\u3068\u306A\u308B\u7BC4\u56F2[l,r)\u304C\u5206\u304B\u308B\u3002\n\
    // \u3000(\u307E\u3042\u3053\u308C\u306Flog\u3064\u3051\u308C\u3070\u30BB\u30B0\
    \u6728\u306B\u3076\u305F\u3093\u3067\u6C42\u307E\u308B\u3093\u3060\u3051\u3069\
    \u306D)\n// \u30FB\u623B\u308A\u5024\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u306F\
    \u901A\u5E38\u306E\u30B0\u30E9\u30D5\u3068\u540C\u3058\u96A3\u63A5\u30EA\u30B9\
    \u30C8\u306E\u5F62\u306B\u3057\u305F\u306E\u3067\u3001\n// \u3000\u5FC5\u8981\u306B\
    \u5FDC\u3058\u3066\u305D\u306E\u307E\u307EHLD\u306B\u7A81\u3063\u8FBC\u3093\u3060\
    \u308A\u3067\u304D\u308B\u3002\n// \u30FB\u964D\u9806\u3067\u69CB\u7BC9\u3057\u305F\
    \u3044\u6642\u306Fis_min\u306Bfalse\u3092\u6E21\u3059\u3002\ntemplate<typename\
    \ T>\npair<vector<vector<int>>, int> cartesian_tree(vector<T> A, bool is_min =\
    \ true) {\n    int N = (int)A.size();\n    if (not is_min) {\n        for (auto\
    \ &a : A) {\n            a = -a;\n        }\n    }\n    vector<vector<int>> nodes(N);\n\
    \    vector<int> P(N, -1), st;\n    st.reserve(N);\n    for (int i = 0; i < N;\
    \ i++) {\n        int prv = -1;\n        while (!st.empty() && A[i] < A[st.back()])\
    \ {\n            prv = st.back();\n            st.pop_back();\n        }\n   \
    \     if (prv != -1) P[prv] = i;\n        if (!st.empty()) P[i] = st.back();\n\
    \        st.push_back(i);\n    }\n    int root = -1;\n    for (int i = 0; i <\
    \ N; i++) {\n        if (P[i] != -1) {\n            nodes[P[i]].push_back(i);\n\
    \        } else {\n            root = i;\n        }\n    }\n    return make_pair(nodes,\
    \ root);\n}\n\n// auto dfs = [&](auto &&f, int l, int u, int r) -> void {\n//\
    \     for (auto v : nodes[u]) {\n//         if (v < u) {\n//             f(f,\
    \ l, v, u);\n//         } else if (v > u) {\n//             f(f, u + 1, v, r);\n\
    //         }\n//     }\n// };\n// dfs(dfs, 0, root, N);\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2024-03-07 15:03:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/cartesian_tree.hpp
layout: document
redirect_from:
- /library/src/graph/cartesian_tree.hpp
- /library/src/graph/cartesian_tree.hpp.html
title: src/graph/cartesian_tree.hpp
---
