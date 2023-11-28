---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/yesno.hpp
    title: src/common/yesno.hpp
  - icon: ':warning:'
    path: src/math/FormalPowerSeries.hpp
    title: src/math/FormalPowerSeries.hpp
  - icon: ':warning:'
    path: src/math/fps/pow.hpp
    title: src/math/fps/pow.hpp
  - icon: ':warning:'
    path: src/math/fps/pow_term2.hpp
    title: src/math/fps/pow_term2.hpp
  - icon: ':warning:'
    path: src/mystl/Deque.hpp
    title: src/mystl/Deque.hpp
  - icon: ':warning:'
    path: src/mystl/Multiset.hpp
    title: src/mystl/Multiset.hpp
  - icon: ':warning:'
    path: src/mystl/Set.hpp
    title: src/mystl/Set.hpp
  - icon: ':warning:'
    path: src/mystl/Vector.hpp
    title: src/mystl/Vector.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/UnionFind.test.cpp
    title: test/graph/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/WeightedUnionFind.test.cpp
    title: test/graph/WeightedUnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/MatPow.test.cpp
    title: test/matrix/MatPow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/print.hpp\"\
    \n\ntemplate<typename T1, typename T2>\nostream &operator<<(ostream &os, const\
    \ pair<T1, T2> &p) {\n    return os << p.first << ' ' << p.second;\n}\n\ntemplate<typename\
    \ T1, typename T2, typename T3>\nostream &operator<<(ostream &os, const tuple<T1,\
    \ T2, T3> &tp) {\n    return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);\n\
    }\n\ntemplate<typename T1, typename T2, typename T3, typename T4>\nostream &operator<<(ostream\
    \ &os, const tuple<T1, T2, T3, T4> &tp) {\n    return os << get<0>(tp) << ' '\
    \ << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp);\n}\n\ntemplate<typename\
    \ T, size_t SZ>\nostream &operator<<(ostream &os, const array<T, SZ> &arr) {\n\
    \    rep(i, arr.size()) {\n        os << arr[i];\n        if (i != (ll)arr.size()-1)\
    \ {\n            os << ' ';\n        }\n    }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &vec) {\n    rep(i, vec.size())\
    \ {\n        os << vec[i];\n        if (i != (ll)vec.size()-1) {\n           \
    \ os << ' ';\n        }\n    }\n    return os;\n}\n\nvoid print() {\n    cout\
    \ << '\\n';\n}\n\ntemplate<typename T>\nvoid print(T out) {\n    cout << out <<\
    \ '\\n';\n}\n\ntemplate<typename T1, typename T2, typename T3>\nvoid print(const\
    \ tuple<T1, T2, T3> &tp) {\n    cout << get<0>(tp) << ' ' << get<1>(tp) << ' '\
    \ << get<2>(tp) << '\\n';\n}\n\ntemplate<typename T1, typename T2, typename T3,\
    \ typename T4>\nvoid print(const tuple<T1, T2, T3, T4> &tp) { \n    cout << get<0>(tp)\
    \ << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\\n';\n}\n\
    \ntemplate<typename T>\nvoid print(const vector<T> &V, char sep=' ') {\n    rep(i,\
    \ V.size()) {\n        cout << V[i];\n        if (i != (ll)V.size()-1) cout <<\
    \ sep;\n    }\n    cout << '\\n';\n}\n\ntemplate<typename T, size_t SZ>\nvoid\
    \ print(const array<T, SZ> &arr, char sep=' ') {\n    rep(i, arr.size()) {\n \
    \       cout << arr[i];\n        if (i != (ll)arr.size()-1) cout << sep;\n   \
    \ }\n    cout << '\\n';\n}\n\n// template<typename T, size_t SZ>\n// void print(const\
    \ vector<array<T, SZ>> &V) {\n//     for (auto& arr : V) print(arr);\n// }\n\n\
    template<typename T>\nvoid print(const deque<T> &que) {\n    vector<T> V(ALL(que));\n\
    \    print(V);\n}\n\ntemplate<typename T>\nvoid print(const set<T> &se) {\n  \
    \  vector<T> V(ALL(se));\n    print(V);\n}\n\n#define debug(x) (cout << #x <<\
    \ \": \" << x << endl);\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\ntemplate<typename T1, typename\
    \ T2>\nostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n    return os\
    \ << p.first << ' ' << p.second;\n}\n\ntemplate<typename T1, typename T2, typename\
    \ T3>\nostream &operator<<(ostream &os, const tuple<T1, T2, T3> &tp) {\n    return\
    \ os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);\n}\n\ntemplate<typename\
    \ T1, typename T2, typename T3, typename T4>\nostream &operator<<(ostream &os,\
    \ const tuple<T1, T2, T3, T4> &tp) {\n    return os << get<0>(tp) << ' ' << get<1>(tp)\
    \ << ' ' << get<2>(tp) << ' ' << get<3>(tp);\n}\n\ntemplate<typename T, size_t\
    \ SZ>\nostream &operator<<(ostream &os, const array<T, SZ> &arr) {\n    rep(i,\
    \ arr.size()) {\n        os << arr[i];\n        if (i != (ll)arr.size()-1) {\n\
    \            os << ' ';\n        }\n    }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &vec) {\n    rep(i, vec.size())\
    \ {\n        os << vec[i];\n        if (i != (ll)vec.size()-1) {\n           \
    \ os << ' ';\n        }\n    }\n    return os;\n}\n\nvoid print() {\n    cout\
    \ << '\\n';\n}\n\ntemplate<typename T>\nvoid print(T out) {\n    cout << out <<\
    \ '\\n';\n}\n\ntemplate<typename T1, typename T2, typename T3>\nvoid print(const\
    \ tuple<T1, T2, T3> &tp) {\n    cout << get<0>(tp) << ' ' << get<1>(tp) << ' '\
    \ << get<2>(tp) << '\\n';\n}\n\ntemplate<typename T1, typename T2, typename T3,\
    \ typename T4>\nvoid print(const tuple<T1, T2, T3, T4> &tp) { \n    cout << get<0>(tp)\
    \ << ' ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\\n';\n}\n\
    \ntemplate<typename T>\nvoid print(const vector<T> &V, char sep=' ') {\n    rep(i,\
    \ V.size()) {\n        cout << V[i];\n        if (i != (ll)V.size()-1) cout <<\
    \ sep;\n    }\n    cout << '\\n';\n}\n\ntemplate<typename T, size_t SZ>\nvoid\
    \ print(const array<T, SZ> &arr, char sep=' ') {\n    rep(i, arr.size()) {\n \
    \       cout << arr[i];\n        if (i != (ll)arr.size()-1) cout << sep;\n   \
    \ }\n    cout << '\\n';\n}\n\n// template<typename T, size_t SZ>\n// void print(const\
    \ vector<array<T, SZ>> &V) {\n//     for (auto& arr : V) print(arr);\n// }\n\n\
    template<typename T>\nvoid print(const deque<T> &que) {\n    vector<T> V(ALL(que));\n\
    \    print(V);\n}\n\ntemplate<typename T>\nvoid print(const set<T> &se) {\n  \
    \  vector<T> V(ALL(se));\n    print(V);\n}\n\n#define debug(x) (cout << #x <<\
    \ \": \" << x << endl);\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/common/print.hpp
  requiredBy:
  - src/common/yesno.hpp
  - src/mystl/Multiset.hpp
  - src/mystl/Set.hpp
  - src/mystl/Deque.hpp
  - src/mystl/Vector.hpp
  - src/template.hpp
  - src/math/FormalPowerSeries.hpp
  - src/math/fps/pow.hpp
  - src/math/fps/pow_term2.hpp
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/matrix/MatPow.test.cpp
  - test/graph/WeightedUnionFind.test.cpp
  - test/graph/UnionFind.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/common/print.hpp
layout: document
redirect_from:
- /library/src/common/print.hpp
- /library/src/common/print.hpp.html
title: src/common/print.hpp
---
