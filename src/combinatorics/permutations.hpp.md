---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':x:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    src/combinatorics/permutations.hpp\"\n\n// \u9806\u5217\u5168\u5217\u6319\ntemplate<typename\
    \ T>\nvector<vector<T>> permutations(const vector<T> &A, int N=-1) {\n    if (N\
    \ == -1) N = A.size();\n    int M = A.size();\n    assert(N <= M);\n    vector<vector<T>>\
    \ comb;\n    rep(bit, 1<<M) {\n        if (popcount(bit) != N) continue;\n   \
    \     vector<T> res;\n        rep(i, M) {\n            if (bit>>i & 1) {\n   \
    \             res.pb(A[i]);\n            }\n        }\n        comb.pb(res);\n\
    \    }\n\n    vector<vector<T>> res;\n    for (auto &perm : comb) {\n        sort(ALL(perm));\n\
    \        do {\n            res.pb(perm);\n        } while (next_permutation(ALL(perm)));\n\
    \    }\n    return res;\n}\n"
  code: "#include \"../macros.hpp\"\n\n// \u9806\u5217\u5168\u5217\u6319\ntemplate<typename\
    \ T>\nvector<vector<T>> permutations(const vector<T> &A, int N=-1) {\n    if (N\
    \ == -1) N = A.size();\n    int M = A.size();\n    assert(N <= M);\n    vector<vector<T>>\
    \ comb;\n    rep(bit, 1<<M) {\n        if (popcount(bit) != N) continue;\n   \
    \     vector<T> res;\n        rep(i, M) {\n            if (bit>>i & 1) {\n   \
    \             res.pb(A[i]);\n            }\n        }\n        comb.pb(res);\n\
    \    }\n\n    vector<vector<T>> res;\n    for (auto &perm : comb) {\n        sort(ALL(perm));\n\
    \        do {\n            res.pb(perm);\n        } while (next_permutation(ALL(perm)));\n\
    \    }\n    return res;\n}\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/permutations.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/combinatorics/permutations.hpp
layout: document
redirect_from:
- /library/src/combinatorics/permutations.hpp
- /library/src/combinatorics/permutations.hpp.html
title: src/combinatorics/permutations.hpp
---
