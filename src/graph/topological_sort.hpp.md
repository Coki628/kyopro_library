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
    src/graph/topological_sort.hpp\"\n\n// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8(\u9802\u70B9\u6570\u3001\u8FBA\u96C6\u5408(0-indexed)) \nvector<int>\
    \ topological_sort(int N, vector<pll> edges) {\n\n    // \u3053\u3053\u304B\u3089\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u6E96\u5099\n    vector<int>\
    \ incnts(N);\n    vvi outnodes(N);\n    int M = edges.size();\n    rep(i, M) {\n\
    \        // \u6D41\u5165\u3059\u308B\u30CE\u30FC\u30C9\u6570\n        incnts[edges[i].second]++;\n\
    \        // \u6D41\u51FA\u5148\u30CE\u30FC\u30C9\u306E\u30EA\u30B9\u30C8\n   \
    \     outnodes[edges[i].first].pb(edges[i].second);\n    }\n    // \u6D41\u5165\
    \u30CE\u30FC\u30C9\u6570\u304C0\u3067\u3042\u308B\u30CE\u30FC\u30C9\u306E\u96C6\
    \u5408S\n    vector<int> S;\n    rep(i, N) {\n        if (incnts[i] == 0) {\n\
    \            S.eb(i);\n        }\n    }\n    // \u3053\u3053\u304B\u3089\u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n    vector<int> L;\n    // \u66AB\
    \u5B9A\u30BB\u30C3\u30C8\u304C\u7A7A\u306B\u306A\u308B\u307E\u3067\u30EB\u30FC\
    \u30D7\n    while (S.size()) {\n        // \u66AB\u5B9A\u30BB\u30C3\u30C8\u304B\
    \u3089\u7D50\u679C\u30EA\u30B9\u30C8\u30781\u3064\u5165\u308C\u308B\n        L.pb(S.back());\
    \ S.pop_back();\n        // \u78BA\u5B9A\u3055\u305B\u305F\u30CE\u30FC\u30C9\u304B\
    \u3089\u6D41\u51FA\u3059\u308B\u30CE\u30FC\u30C9\u3067\u30EB\u30FC\u30D7\n   \
    \     for (auto node : outnodes[L.back()]) {\n            // \u6D41\u5165\u30CE\
    \u30FC\u30C9\u6570\u30921\u6E1B\u3089\u3059\n            incnts[node]--;\n   \
    \         // \u6D41\u5165\u30CE\u30FC\u30C9\u304C0\u306A\u3089\u66AB\u5B9A\u30BB\
    \u30C3\u30C8\u3078\n            if (incnts[node] == 0) {\n                S.eb(node);\n\
    \            }\n        }\n    }\n    // \u9589\u8DEF\u304C\u3042\u3063\u3066\u6B63\
    \u3057\u304F\u30BD\u30FC\u30C8\u51FA\u6765\u306A\u304B\u3063\u305F\u5834\u5408\
    \n    if (L.size() != N) {\n        return vector<int>();\n    }\n    // \u30BD\
    \u30FC\u30C8\u3055\u308C\u305F\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\
    \u5374\n    return L;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8(\u9802\u70B9\u6570\u3001\u8FBA\u96C6\u5408(0-indexed)) \nvector<int>\
    \ topological_sort(int N, vector<pll> edges) {\n\n    // \u3053\u3053\u304B\u3089\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u6E96\u5099\n    vector<int>\
    \ incnts(N);\n    vvi outnodes(N);\n    int M = edges.size();\n    rep(i, M) {\n\
    \        // \u6D41\u5165\u3059\u308B\u30CE\u30FC\u30C9\u6570\n        incnts[edges[i].second]++;\n\
    \        // \u6D41\u51FA\u5148\u30CE\u30FC\u30C9\u306E\u30EA\u30B9\u30C8\n   \
    \     outnodes[edges[i].first].pb(edges[i].second);\n    }\n    // \u6D41\u5165\
    \u30CE\u30FC\u30C9\u6570\u304C0\u3067\u3042\u308B\u30CE\u30FC\u30C9\u306E\u96C6\
    \u5408S\n    vector<int> S;\n    rep(i, N) {\n        if (incnts[i] == 0) {\n\
    \            S.eb(i);\n        }\n    }\n    // \u3053\u3053\u304B\u3089\u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n    vector<int> L;\n    // \u66AB\
    \u5B9A\u30BB\u30C3\u30C8\u304C\u7A7A\u306B\u306A\u308B\u307E\u3067\u30EB\u30FC\
    \u30D7\n    while (S.size()) {\n        // \u66AB\u5B9A\u30BB\u30C3\u30C8\u304B\
    \u3089\u7D50\u679C\u30EA\u30B9\u30C8\u30781\u3064\u5165\u308C\u308B\n        L.pb(S.back());\
    \ S.pop_back();\n        // \u78BA\u5B9A\u3055\u305B\u305F\u30CE\u30FC\u30C9\u304B\
    \u3089\u6D41\u51FA\u3059\u308B\u30CE\u30FC\u30C9\u3067\u30EB\u30FC\u30D7\n   \
    \     for (auto node : outnodes[L.back()]) {\n            // \u6D41\u5165\u30CE\
    \u30FC\u30C9\u6570\u30921\u6E1B\u3089\u3059\n            incnts[node]--;\n   \
    \         // \u6D41\u5165\u30CE\u30FC\u30C9\u304C0\u306A\u3089\u66AB\u5B9A\u30BB\
    \u30C3\u30C8\u3078\n            if (incnts[node] == 0) {\n                S.eb(node);\n\
    \            }\n        }\n    }\n    // \u9589\u8DEF\u304C\u3042\u3063\u3066\u6B63\
    \u3057\u304F\u30BD\u30FC\u30C8\u51FA\u6765\u306A\u304B\u3063\u305F\u5834\u5408\
    \n    if (L.size() != N) {\n        return vector<int>();\n    }\n    // \u30BD\
    \u30FC\u30C8\u3055\u308C\u305F\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\
    \u5374\n    return L;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/graph/topological_sort.hpp
- /library/src/graph/topological_sort.hpp.html
title: src/graph/topological_sort.hpp
---
