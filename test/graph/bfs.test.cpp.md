---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmin.hpp
    title: src/common/chmin.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/bfs.hpp
    title: src/graph/bfs.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C
  bundledCode: "#line 1 \"test/graph/bfs.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C\"\
    \n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n\n#define CONSTANTS\n// #define CAST_MINT_TO_LL\n\
    #line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 10 \"test/graph/bfs.test.cpp\"\n\nconstexpr long long\
    \ INF = 1e18;\n// constexpr long long INF = LONG_LONG_MAX;\nconstexpr int MOD\
    \ = 1000000007;\n// constexpr int MOD = 998244353;\nconstexpr long double EPS\
    \ = 1e-10;\nconstexpr long double PI = M_PI;\n\n#line 3 \"src/macros.hpp\"\n\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using pll = pair<ll, ll>;\nusing pii = pair<int, int>;\nusing pli = pair<ll, int>;\n\
    using pil = pair<int, ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\n\
    using vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing\
    \ vvpil = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define\
    \ rep(...) name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i,\
    \ a) for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i =\
    \ a, _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b;\
    \ (c > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/common/print.hpp\"\n\nvoid print() {\n    cout << '\\n';\n}\n\ntemplate<typename\
    \ T>\nvoid print(T out) {\n    cout << out << '\\n';\n}\n\ntemplate<typename T1,\
    \ typename T2>\nvoid print(const pair<T1, T2> &p) {\n    cout << p.first << '\
    \ ' << p.second << '\\n';\n}\n\ntemplate<typename T1, typename T2, typename T3>\n\
    void print(const tuple<T1, T2, T3> &tp) {\n    cout << get<0>(tp) << ' ' << get<1>(tp)\
    \ << ' ' << get<2>(tp) << '\\n';\n}\n\ntemplate<typename T1, typename T2, typename\
    \ T3, typename T4>\nvoid print(const tuple<T1, T2, T3, T4> &tp) { \n    cout <<\
    \ get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) <<\
    \ '\\n';\n}\n\ntemplate<typename T1, typename T2>\nvoid print(const vector<pair<T1,\
    \ T2>> &V) {\n    for (auto& p : V) print(p);\n}\n\ntemplate<typename T>\nvoid\
    \ print(const vector<T> &V) {\n    rep(i, V.size()) {\n        cout << V[i];\n\
    \        if (i != V.size()-1) cout << ' ';\n    }\n    cout << '\\n';\n}\n\ntemplate<typename\
    \ T, size_t SZ>\nvoid print(const array<T, SZ> &arr) {\n    rep(i, arr.size())\
    \ {\n        cout << arr[i];\n        if (i != arr.size()-1) cout << ' ';\n  \
    \  }\n    cout << '\\n';\n}\n\ntemplate<typename T, size_t SZ>\nvoid print(const\
    \ vector<array<T, SZ>> &V) {\n    for (auto& arr : V) print(arr);\n}\n\ntemplate<typename\
    \ T>\nvoid print(const deque<T> &que) {\n    vector<T> V(ALL(que));\n    print(V);\n\
    }\n\ntemplate<typename T>\nvoid print(const set<T> &se) {\n    vector<T> V(ALL(se));\n\
    \    print(V);\n}\n\n#define debug(x) (cout << #x << \": \", print(x));\n#line\
    \ 20 \"test/graph/bfs.test.cpp\"\n\n#line 2 \"src/common/chmin.hpp\"\n\ntemplate<typename\
    \ T>\nbool chmin(T &x, T y) {\n    return (y < x) ? x = y, true : false;\n}\n\
    #line 3 \"src/graph/bfs.hpp\"\n\n// BFS\nvector<ll> bfs(const vvi &nodes, const\
    \ vector<int> &src) {\n\n    int N = nodes.size();\n    vector<ll> res(N, INF);\n\
    \    queue<int> que;\n    for (int s : src) {\n        res[s] = 0;\n        que.push(s);\n\
    \    }\n\n    while (!que.empty()) {\n        int u = que.front(); que.pop();\n\
    \        for (auto v: nodes[u]) {\n            if (chmin(res[v], res[u]+1)) {\n\
    \                que.push(v);\n            }\n        }\n    }\n    return res;\n\
    }\n#line 22 \"test/graph/bfs.test.cpp\"\n\nvoid solve() {\n    ll N;\n    cin\
    \ >> N;\n    vvi nodes(N);\n    rep(_, N) {\n        ll u;\n        cin >> u;\n\
    \        u--;\n        ll k;\n        cin >> k;\n        rep(_, 0, k) {\n    \
    \        ll v;\n            cin >> v;\n            v--;\n            nodes[u].pb(v);\n\
    \        }\n    }\n\n    auto res = bfs(nodes, {0});\n    vector<pll> ans(N);\n\
    \    rep(i, N) {\n        if (res[i] >= INF) {\n            res[i] = -1;\n   \
    \     }\n        ans[i].first = i + 1;\n        ans[i].second = res[i];\n    }\n\
    \    for (auto &p : ans) print(p);\n}\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n\n    // single test case\n    solve();\n\
    \n    // multi test cases\n    // int T;\n    // cin >> T;\n    // while (T--)\
    \ solve();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C\"\
    \n\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n\n#define CONSTANTS\n// #define CAST_MINT_TO_LL\n\
    #include \"../../src/base.hpp\"\n\nconstexpr long long INF = 1e18;\n// constexpr\
    \ long long INF = LONG_LONG_MAX;\nconstexpr int MOD = 1000000007;\n// constexpr\
    \ int MOD = 998244353;\nconstexpr long double EPS = 1e-10;\nconstexpr long double\
    \ PI = M_PI;\n\n#include \"../../src/macros.hpp\"\n#include \"../../src/common/print.hpp\"\
    \n\n#include \"../../src/graph/bfs.hpp\"\n\nvoid solve() {\n    ll N;\n    cin\
    \ >> N;\n    vvi nodes(N);\n    rep(_, N) {\n        ll u;\n        cin >> u;\n\
    \        u--;\n        ll k;\n        cin >> k;\n        rep(_, 0, k) {\n    \
    \        ll v;\n            cin >> v;\n            v--;\n            nodes[u].pb(v);\n\
    \        }\n    }\n\n    auto res = bfs(nodes, {0});\n    vector<pll> ans(N);\n\
    \    rep(i, N) {\n        if (res[i] >= INF) {\n            res[i] = -1;\n   \
    \     }\n        ans[i].first = i + 1;\n        ans[i].second = res[i];\n    }\n\
    \    for (auto &p : ans) print(p);\n}\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n\n    // single test case\n    solve();\n\
    \n    // multi test cases\n    // int T;\n    // cin >> T;\n    // while (T--)\
    \ solve();\n\n    return 0;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/macros.hpp
  - src/common/print.hpp
  - src/graph/bfs.hpp
  - src/common/chmin.hpp
  isVerificationFile: true
  path: test/graph/bfs.test.cpp
  requiredBy: []
  timestamp: '2022-03-24 14:04:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/bfs.test.cpp
layout: document
redirect_from:
- /verify/test/graph/bfs.test.cpp
- /verify/test/graph/bfs.test.cpp.html
title: test/graph/bfs.test.cpp
---
