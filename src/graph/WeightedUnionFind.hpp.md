---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"\
    src/graph/WeightedUnionFind.hpp\"\n\n// \u91CD\u307F\u4ED8\u304DUF\ntemplate<typename\
    \ T>\nstruct WeightedUnionFind {\n\n    int n;\n    vector<int> par, rank;\n \
    \   vector<T> weight;\n    \n    WeightedUnionFind(int n) : n(n) {\n        par.resize(n);\n\
    \        rank.resize(n);\n        // \u6839\u3078\u306E\u8DDD\u96E2\u3092\u7BA1\
    \u7406\n        weight.resize(n);\n        rep(i, n) par[i] = i;\n    }\n\n  \
    \  // \u691C\u7D22\n    int find(int x) {\n        if (par[x] == x) {\n      \
    \      return x;\n        } else {\n            int y = find(par[x]);\n      \
    \      // \u89AA\u3078\u306E\u91CD\u307F\u3092\u8FFD\u52A0\u3057\u306A\u304C\u3089\
    \u6839\u307E\u3067\u8D70\u67FB\n            weight[x] += weight[par[x]];\n   \
    \         par[x] = y;\n            return y;\n        }\n    }\n\n    // \u4F75\
    \u5408\n    int merge(int x, int y, ll w) {\n        int rx = find(x);\n     \
    \   int ry = find(y);\n        if (rx == ry) return rx;\n\n        // x\u306E\u6728\
    \u306E\u9AD8\u3055 < y\u306E\u6728\u306E\u9AD8\u3055\n        if (rank[rx] < rank[ry])\
    \ {\n            par[rx] = ry;\n            weight[rx] = w - weight[x] + weight[y];\n\
    \            return ry;\n        } else {\n            par[ry] = rx;\n       \
    \     weight[ry] = - w - weight[y] + weight[x];\n            // \u6728\u306E\u9AD8\
    \u3055\u304C\u540C\u3058\u3060\u3063\u305F\u5834\u5408\u306E\u51E6\u7406\n   \
    \         if (rank[rx] == rank[ry]) {\n                rank[rx]++;\n         \
    \   }\n            return rx;\n        }\n    }\n\n    // \u540C\u3058\u96C6\u5408\
    \u306B\u5C5E\u3059\u308B\u304B\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    // x\u304B\u3089y\u3078\u306E\u30B3\u30B9\u30C8\
    \n    T diff(int x, int y) {\n        assert(same(x, y));\n        return weight[x]\
    \ - weight[y];\n    }\n};\n"
  code: "#include \"../macros.hpp\"\n\n// \u91CD\u307F\u4ED8\u304DUF\ntemplate<typename\
    \ T>\nstruct WeightedUnionFind {\n\n    int n;\n    vector<int> par, rank;\n \
    \   vector<T> weight;\n    \n    WeightedUnionFind(int n) : n(n) {\n        par.resize(n);\n\
    \        rank.resize(n);\n        // \u6839\u3078\u306E\u8DDD\u96E2\u3092\u7BA1\
    \u7406\n        weight.resize(n);\n        rep(i, n) par[i] = i;\n    }\n\n  \
    \  // \u691C\u7D22\n    int find(int x) {\n        if (par[x] == x) {\n      \
    \      return x;\n        } else {\n            int y = find(par[x]);\n      \
    \      // \u89AA\u3078\u306E\u91CD\u307F\u3092\u8FFD\u52A0\u3057\u306A\u304C\u3089\
    \u6839\u307E\u3067\u8D70\u67FB\n            weight[x] += weight[par[x]];\n   \
    \         par[x] = y;\n            return y;\n        }\n    }\n\n    // \u4F75\
    \u5408\n    int merge(int x, int y, ll w) {\n        int rx = find(x);\n     \
    \   int ry = find(y);\n        if (rx == ry) return rx;\n\n        // x\u306E\u6728\
    \u306E\u9AD8\u3055 < y\u306E\u6728\u306E\u9AD8\u3055\n        if (rank[rx] < rank[ry])\
    \ {\n            par[rx] = ry;\n            weight[rx] = w - weight[x] + weight[y];\n\
    \            return ry;\n        } else {\n            par[ry] = rx;\n       \
    \     weight[ry] = - w - weight[y] + weight[x];\n            // \u6728\u306E\u9AD8\
    \u3055\u304C\u540C\u3058\u3060\u3063\u305F\u5834\u5408\u306E\u51E6\u7406\n   \
    \         if (rank[rx] == rank[ry]) {\n                rank[rx]++;\n         \
    \   }\n            return rx;\n        }\n    }\n\n    // \u540C\u3058\u96C6\u5408\
    \u306B\u5C5E\u3059\u308B\u304B\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    // x\u304B\u3089y\u3078\u306E\u30B3\u30B9\u30C8\
    \n    T diff(int x, int y) {\n        assert(same(x, y));\n        return weight[x]\
    \ - weight[y];\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/WeightedUnionFind.hpp
layout: document
redirect_from:
- /library/src/graph/WeightedUnionFind.hpp
- /library/src/graph/WeightedUnionFind.hpp.html
title: src/graph/WeightedUnionFind.hpp
---
