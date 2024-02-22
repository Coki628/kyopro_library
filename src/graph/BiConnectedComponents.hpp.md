---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/graph/LowLink.hpp
    title: src/graph/LowLink.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/BlockCutTree.hpp
    title: src/graph/BlockCutTree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://kntychance.hatenablog.jp/entry/2022/09/16/161858
    - https://nyaannyaan.github.io/library/graph/biconnected-components.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/graph/LowLink.hpp\"\
    \n\n// Low Link\n// see: https://nyaannyaan.github.io/library/graph/lowlink.hpp\n\
    // \u30FB\u30B0\u30E9\u30D5\u306E\u6A4B\u3068\u95A2\u7BC0\u70B9\u3092\u5217\u6319\
    \u3059\u308B\u3002\n// \u30FB\u6A4B\uFF1A\u305D\u308C\u3092\u53D6\u308A\u9664\u304F\
    \u3068\u9023\u7D50\u3067\u306A\u304F\u306A\u308B\u3088\u3046\u306A\u8FBA\n// \u30FB\
    \u95A2\u7BC0\u70B9\uFF1A\u305D\u308C\u3092\u53D6\u308A\u9664\u304F\u3068\u9023\
    \u7D50\u3067\u306A\u304F\u306A\u308B\u3088\u3046\u306A\u9802\u70B9\n// bridge:\
    \ \u6A4B(\u8FBA(u,v)\u304Cu < v\u3068\u306A\u308B\u3088\u3046\u306B\u683C\u7D0D\
    )\n// articulations point: \u95A2\u7BC0\u70B9\nstruct LowLink {\n    const vvi\
    \ &g;\n    int N;\n    vector<int> ord, low, articulations, is_arti;\n    vector<pair<int,\
    \ int>> bridges;\n\n    LowLink(const vvi &_g) : g(_g), N(g.size()), ord(N, -1),\
    \ low(N, -1), is_arti(N) {\n        for (int i = 0, k = 0; i < N; i++) {\n   \
    \         if (ord[i] == -1) {\n                k = dfs(i, k, -1);\n          \
    \  }\n        }\n        sort(ALL(bridges));\n    }\n\n    bool is_articulation(int\
    \ u) {\n        return is_arti[u];\n    }\n\n    bool is_bridge(int u, int v)\
    \ {\n        if (u > v) swap(u, v);\n        auto itr = lower_bound(ALL(bridges),\
    \ pii{u, v});\n        return itr != bridges.end() and (*itr) == pii{u, v};\n\
    \    }\n\n    bool has_articulation() {\n        return articulations.size();\n\
    \    }\n\n    bool has_bridge() {\n        return bridges.size();\n    }\n\n \
    \   vector<int> get_articulations() {\n        return articulations;\n    }\n\n\
    \    vector<pii> get_bridges() {\n        return bridges;\n    }\n\nprivate:\n\
    \    int dfs(int idx, int k, int par) {\n        low[idx] = (ord[idx] = k++);\n\
    \        int cnt = 0;\n        bool arti = false, second = false;\n        for\
    \ (auto &to : g[idx]) {\n            if (ord[to] == -1) {\n                cnt++;\n\
    \                k = dfs(to, k, idx);\n                low[idx] = min(low[idx],\
    \ low[to]);\n                arti |= (par != -1) && (low[to] >= ord[idx]);\n \
    \               if (ord[idx] < low[to]) {\n                    bridges.emplace_back(minmax(idx,\
    \ (int)to));\n                }\n            } else if (to != par || second) {\n\
    \                low[idx] = min(low[idx], ord[to]);\n            } else {\n  \
    \              second = true;\n            }\n        }\n        arti |= par ==\
    \ -1 && cnt > 1;\n        if (arti) {\n            articulations.push_back(idx);\n\
    \            is_arti[idx] = true;\n        }\n        return k;\n    }\n};\n#line\
    \ 4 \"src/graph/BiConnectedComponents.hpp\"\n\n// \u4E8C\u91CD\u9802\u70B9\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\n// see: https://nyaannyaan.github.io/library/graph/biconnected-components.hpp\n\
    //      https://kntychance.hatenablog.jp/entry/2022/09/16/161858\n// \u30FB\u3053\
    \u308C\u5358\u4F53\u3067\u3069\u3046\u3068\u8A00\u3046\u3088\u308A\u306F\u3001\
    Block Cut Tree\u306E\u69CB\u7BC9\u306E\u305F\u3081\u306B\u5B58\u5728\u3057\u3066\
    \u308B\u611F\u3042\u308B\u3002\nstruct BiConnectedComponents : LowLink {\n   \
    \ vector<int> used;\n    vector<vector<pair<int, int>>> bc;\n    vector<pair<int,\
    \ int>> tmp;\n\n    BiConnectedComponents(const vvi &_g) : LowLink(_g) {\n   \
    \     build();\n    }\n\n    void build() {\n        used.assign(this->g.size(),\
    \ 0);\n        for (int i = 0; i < (int)used.size(); i++) {\n            if (!used[i])\
    \ dfs(i, -1);\n        }\n    }\n\n    void dfs(int idx, int par) {\n        used[idx]\
    \ = true;\n        for (auto &to : this->g[idx]) {\n            if (to == par)\
    \ continue;\n            if (!used[to] || this->ord[to] < this->ord[idx]) {\n\
    \                tmp.emplace_back(minmax<int>(idx, to));\n            }\n    \
    \        if (!used[to]) {\n                dfs(to, idx);\n                if (this->low[to]\
    \ >= this->ord[idx]) {\n                    bc.emplace_back();\n             \
    \       while (true) {\n                        auto e = tmp.back();\n       \
    \                 bc.back().emplace_back(e);\n                        tmp.pop_back();\n\
    \                        if (e.first == min<int>(idx, to) &&\n               \
    \             e.second == max<int>(idx, to)) {\n                            break;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"LowLink.hpp\"\n\n// \u4E8C\
    \u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3\n// see: https://nyaannyaan.github.io/library/graph/biconnected-components.hpp\n\
    //      https://kntychance.hatenablog.jp/entry/2022/09/16/161858\n// \u30FB\u3053\
    \u308C\u5358\u4F53\u3067\u3069\u3046\u3068\u8A00\u3046\u3088\u308A\u306F\u3001\
    Block Cut Tree\u306E\u69CB\u7BC9\u306E\u305F\u3081\u306B\u5B58\u5728\u3057\u3066\
    \u308B\u611F\u3042\u308B\u3002\nstruct BiConnectedComponents : LowLink {\n   \
    \ vector<int> used;\n    vector<vector<pair<int, int>>> bc;\n    vector<pair<int,\
    \ int>> tmp;\n\n    BiConnectedComponents(const vvi &_g) : LowLink(_g) {\n   \
    \     build();\n    }\n\n    void build() {\n        used.assign(this->g.size(),\
    \ 0);\n        for (int i = 0; i < (int)used.size(); i++) {\n            if (!used[i])\
    \ dfs(i, -1);\n        }\n    }\n\n    void dfs(int idx, int par) {\n        used[idx]\
    \ = true;\n        for (auto &to : this->g[idx]) {\n            if (to == par)\
    \ continue;\n            if (!used[to] || this->ord[to] < this->ord[idx]) {\n\
    \                tmp.emplace_back(minmax<int>(idx, to));\n            }\n    \
    \        if (!used[to]) {\n                dfs(to, idx);\n                if (this->low[to]\
    \ >= this->ord[idx]) {\n                    bc.emplace_back();\n             \
    \       while (true) {\n                        auto e = tmp.back();\n       \
    \                 bc.back().emplace_back(e);\n                        tmp.pop_back();\n\
    \                        if (e.first == min<int>(idx, to) &&\n               \
    \             e.second == max<int>(idx, to)) {\n                            break;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n        }\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/graph/LowLink.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/graph/BiConnectedComponents.hpp
  requiredBy:
  - src/graph/BlockCutTree.hpp
  timestamp: '2024-02-22 17:15:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/BiConnectedComponents.hpp
layout: document
redirect_from:
- /library/src/graph/BiConnectedComponents.hpp
- /library/src/graph/BiConnectedComponents.hpp.html
title: src/graph/BiConnectedComponents.hpp
---
