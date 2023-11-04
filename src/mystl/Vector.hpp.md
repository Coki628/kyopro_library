---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/print.hpp
    title: src/common/print.hpp
  - icon: ':heavy_check_mark:'
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
    \ \": \" << x << endl);\n#line 4 \"src/mystl/Vector.hpp\"\n\ntemplate<typename\
    \ _Tp>\nstruct Vector : vector<_Tp> {\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u306E\u7D99\u627F\n    using vector<_Tp>::vector;\n    _Tp pop() {\n  \
    \      _Tp res = this->back();\n        this->pop_back();\n        return res;\n\
    \    }\n\n    template<typename F>\n    auto map(F f) {\n        Vector<decltype(f(_Tp()))>\
    \ res;\n        for (auto& val : *this) {\n            res.eb(f(val));\n     \
    \   }\n        return res;\n    }\n};\n\ntemplate<typename T>\nvoid print(const\
    \ Vector<T> &A) {\n    vector<T> V(A.begin(), A.end());\n    print(V);\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../common/print.hpp\"\n\
    \ntemplate<typename _Tp>\nstruct Vector : vector<_Tp> {\n    // \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u306E\u7D99\u627F\n    using vector<_Tp>::vector;\n \
    \   _Tp pop() {\n        _Tp res = this->back();\n        this->pop_back();\n\
    \        return res;\n    }\n\n    template<typename F>\n    auto map(F f) {\n\
    \        Vector<decltype(f(_Tp()))> res;\n        for (auto& val : *this) {\n\
    \            res.eb(f(val));\n        }\n        return res;\n    }\n};\n\ntemplate<typename\
    \ T>\nvoid print(const Vector<T> &A) {\n    vector<T> V(A.begin(), A.end());\n\
    \    print(V);\n}\n"
  dependsOn:
  - src/base.hpp
  - src/common/print.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/mystl/Vector.hpp
  requiredBy: []
  timestamp: '2023-10-10 14:57:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/mystl/Vector.hpp
layout: document
redirect_from:
- /library/src/mystl/Vector.hpp
- /library/src/mystl/Vector.hpp.html
title: src/mystl/Vector.hpp
---