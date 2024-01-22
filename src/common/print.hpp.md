---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmax.hpp
    title: src/common/chmax.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/common/yesno.hpp
    title: src/common/yesno.hpp
  - icon: ':warning:'
    path: src/graph/AuxiliaryTree.hpp
    title: src/graph/AuxiliaryTree.hpp
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
    links:
    - https://blog.naskya.net/post/meu0vkh5cpl1/
    - https://gist.github.com/naskya/1e5e5cd269cfe16a76988378a60e2ca3#file-debug_print-hpp-L150
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/common/chmax.hpp\"\
    \n\ntemplate<typename T>\nbool chmax(T &x, T y) {\n    return (y > x) ? x = y,\
    \ true : false;\n}\n#line 4 \"src/common/print.hpp\"\n\n// \u203B\u5185\u5074\u3067\
    \u547C\u3070\u308C\u305D\u3046\u306A\u3082\u306E\u307B\u3069\u4E0A\u306B\u66F8\
    \u3044\u3066\u304A\u304F\u3002\n\n// pair\ntemplate<typename T1, typename T2>\n\
    ostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n    return os << p.first\
    \ << ' ' << p.second;\n}\n\n// tuple\n// see: https://gist.github.com/naskya/1e5e5cd269cfe16a76988378a60e2ca3#file-debug_print-hpp-L150\n\
    template<class T, size_t... Is>\nvoid print_tuple(ostream &os, const T &arg, index_sequence<Is...>)\
    \ {\n    static_cast<void>(((os << (Is == 0 ? \"\" : \" \"), os << get<Is>(arg)),\
    \ ...));\n}\ntemplate<class... Ts>\nostream &operator<<(ostream &os, const tuple<Ts...>\
    \ &arg) {\n    print_tuple(os, arg, make_index_sequence<sizeof...(Ts)>());\n \
    \   return os;\n}\n\n// \u65E7\u4ED5\u69D8\u3002\u65B0\u4ED5\u69D8\u3067\u3042\
    \u308B\u7A0B\u5EA6\u52D5\u4F5C\u554F\u984C\u306A\u3044\u78BA\u8A8D\u304C\u53D6\
    \u308C\u305F\u3089\u524A\u9664\n// template<typename T1, typename T2, typename\
    \ T3>\n// ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &tp) {\n//\
    \     return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);\n// }\n\
    // template<typename T1, typename T2, typename T3, typename T4>\n// ostream &operator<<(ostream\
    \ &os, const tuple<T1, T2, T3, T4> &tp) {\n//     return os << get<0>(tp) << '\
    \ ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp);\n// }\n// template<typename\
    \ T1, typename T2, typename T3>\n// void print(const tuple<T1, T2, T3> &tp) {\n\
    //     cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\\n';\n\
    // }\n// template<typename T1, typename T2, typename T3, typename T4>\n// void\
    \ print(const tuple<T1, T2, T3, T4> &tp) {\n//     cout << get<0>(tp) << ' ' <<\
    \ get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\\n';\n// }\n\n// array\n\
    template<typename T, size_t N>\nostream &operator<<(ostream &os, const array<T,\
    \ N> &arr) {\n    rep(i, N) {\n        os << arr[i];\n        if (i != (int)N\
    \ - 1) {\n            os << ' ';\n        }\n    }\n    return os;\n}\ntemplate<typename\
    \ T, size_t N>\nvoid print(const array<T, N> &arr, string sep = \" \") {\n   \
    \ rep(i, N) {\n        cout << arr[i];\n        if (i != (int)N - 1) cout << sep;\n\
    \    }\n    cout << '\\n';\n}\n\n// vector\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &vec) {\n    rep(i, vec.size()) {\n        os << vec[i];\n\
    \        if (i != (int)vec.size() - 1) {\n            os << ' ';\n        }\n\
    \    }\n    return os;\n}\ntemplate<typename T>\nvoid print(const vector<T> &vec,\
    \ string sep = \" \") {\n    rep(i, vec.size()) {\n        cout << vec[i];\n \
    \       if (i != (int)vec.size() - 1) cout << sep;\n    }\n    cout << '\\n';\n\
    }\n\n// deque\ntemplate<typename T>\nvoid print(const deque<T> &que, string sep\
    \ = \" \") {\n    vector<T> vec(ALL(que));\n    print(vec, sep);\n}\n\n// set\n\
    template<typename T>\nvoid print(const set<T> &se, string sep = \" \") {\n   \
    \ vector<T> vec(ALL(se));\n    print(vec, sep);\n}\n\n// set, multiset, deque,\
    \ etc...\n// \u203B\u3068\u3066\u3082\u6C4E\u7528\u6027\u9AD8\u3044\u3093\u3060\
    \u3051\u3069\u3001string\u307E\u3067\u53D6\u308A\u8FBC\u307E\u308C\u3066vector\u306B\
    \u3055\u308C\u3066\u3057\u307E\u3046\u306E\u3067\u4F7F\u308F\u306A\u3044\n// template<template<typename\
    \ T>class Container, typename T>\n// void print(const Container<T>& con, string\
    \ sep=\" \") {\n//     vector<T> V(ALL(con));\n//     print(V, sep);\n// }\n\n\
    // initializer_list (\u300Cprint({1, 2, 3, 4});\u300D\u3068\u304B\u3067\u304D\u308B\
    )\ntemplate<typename T>\nvoid print(const initializer_list<T> &li, string sep\
    \ = \" \") {\n    vector<T> V(ALL(li));\n    print(V, sep);\n}\n\n// \u53EF\u5909\
    \u9577\u5F15\u6570\u3002operator<<\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3055\u3048\
    \u3044\u308C\u3070\u3001\u578B\u304C\u9055\u3046\u540C\u58EB\u3067\u3082\u96D1\
    \u591A\u306B\u4E26\u3079\u3066\u51FA\u529B\u3067\u304D\u308B\n// \u203Bprint(vector,\
    \ \"\\n\")\u3068\u304B\u3082\u3053\u3053\u306B\u6765\u3066\u3057\u307E\u3063\u305F\
    \u306E\u3067\u4E00\u65E6\u4E2D\u6B62\n// template<typename T, typename... Ts>\n\
    // void print(const T val, Ts... ts) {\n//     if constexpr (sizeof...(Ts) ==\
    \ 0) {\n//         cout << val << '\\n';\n//     } else {\n//         cout <<\
    \ val << ' ';\n//         print(ts...);\n//     }\n// }\n\n// \u6539\u884C\u306E\
    \u307F\nvoid print() {\n    cout << '\\n';\n}\n\n// \u305D\u306E\u4ED6 (pair,tuple,string\u7B49\
    \u3082\u3053\u3053\u306B\u6765\u3066operator<<\u306B\u6E21\u3055\u308C\u308B)\n\
    template<typename T>\nvoid print(T out) {\n    cout << out << '\\n';\n}\n\n//\
    \ debug (\u5909\u6570\u540D\u4ED8\u304D\u3067\u51FA\u529B\u3001stderr\u306A\u306E\
    \u3067\u63D0\u51FA\u3092\u90AA\u9B54\u3057\u306A\u3044)\n// #define debug(x) (cerr\
    \ << #x << \": \" << x << endl);\n// \u53EF\u5909\u9577\u5F15\u6570\u5BFE\u5FDC\
    \u7248\n// see: https://blog.naskya.net/post/meu0vkh5cpl1/\n#define debug(...)\
    \ multi_debug(#__VA_ARGS__, __VA_ARGS__)\n\n// \u30B0\u30EA\u30C3\u30C9\u3060\u3051\
    \u898B\u3084\u3059\u304F\u306A\u308B\u3088\u3046\u306B\u3061\u3087\u3063\u3068\
    \u500B\u5225\u5BFE\u5FDC\ntemplate<typename T>\nvoid multi_debug(string name,\
    \ const vv<T> &grid) {\n    cerr << name << \":\" << endl;\n    int H = grid.size();\n\
    \    int W = grid[0].size();\n    // \u5217\u6BCE\u306B\u6700\u5927\u5E45\u3092\
    \u53D6\u3063\u3066\u304A\u304F\n    vector<int> mxlen(W);\n    rep(h, H) {\n \
    \       rep(w, W) {\n            chmax(mxlen[w], (int)tostr(grid[h][w]).size());\n\
    \        }\n    }\n    rep(h, H) {\n        rep(w, W) {\n            int pad =\
    \ mxlen[w] - (int)tostr(grid[h][w]).size();\n            cerr << string(pad, '\
    \ ') << grid[h][w];\n            if (w == W - 1) {\n                cerr << endl;\n\
    \            } else {\n                cerr << ' ';\n            }\n        }\n\
    \    }\n}\n\ntemplate<class Tp, class... Ts>\nvoid multi_debug(string names, Tp\
    \ arg, Ts... args) {\n    // args...\u306E\u30D1\u30E9\u30E1\u30FC\u30BF\u304C\
    0\u500B\u306E\u3068\u304D\u3001\u5358\u306Barg\u3060\u3051\u3092\u51FA\u529B\u3057\
    \u3066\u7D42\u4E86\n    if constexpr (sizeof...(Ts) == 0) {\n        while (names.back()\
    \ == ' ') {\n            names.pop_back();\n        }\n        cerr << names <<\
    \ \": \" << arg << endl;\n    } else {\n        // names\u306B\u306F\u5168\u90E8\
    \u306E\u5909\u6570\u306E\u540D\u524D\u304C\u683C\u7D0D\u3055\u308C\u3066\u3044\
    \u308B\u306E\u3067\u30011\u3064\u76EE\u306E\u5909\u6570\u540D\u306E\u7D42\u308F\
    \u308A\u306E','\u306E\u4F4D\u7F6E\u3092\u63A2\u3059\n        int n = names.size(),\
    \ comma_pos = -1, paren_depth = 0,\n            inside_quote = false;\n      \
    \  rep(i, n) {\n            if (not inside_quote and paren_depth == 0 and names[i]\
    \ == ',') {\n                comma_pos = i;\n                break;\n        \
    \    }\n            if (names[i] == '\\\"' or names[i] == '\\'') {\n         \
    \       if (i > 0 and names[i - 1] == '\\\\') continue;\n                inside_quote\
    \ ^= true;\n            }\n            if (not inside_quote and names[i] == '(')\
    \ {\n                paren_depth++;\n            }\n            if (not inside_quote\
    \ and names[i] == ')') {\n                paren_depth--;\n            }\n    \
    \    }\n        assert(comma_pos != -1);\n        string name = names.substr(0,\
    \ comma_pos);\n        while (name.back() == ' ') {\n            name.pop_back();\n\
    \        }\n        cerr << name << \": \" << arg << endl;\n\n        int next_begin_at\
    \ = comma_pos + 1;\n        while (names[next_begin_at] == ' ') {\n          \
    \  next_begin_at++;\n        }\n        names = names.substr(next_begin_at);\n\
    \        // \u3053\u306E\u95A2\u6570\u3092\u518D\u5E30\u7684\u306B\u547C\u3093\
    \u3067\u6B8B\u308A\u306E\u5909\u6570\u3082\u51FA\u529B\u3059\u308B\n        multi_debug(names,\
    \ args...);\n    }\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\ntemplate<typename T>\nvoid\
    \ print(const vector<T> &V, char sep) {\n    print(V, string{sep});\n}\ntemplate<typename\
    \ T, size_t N>\nvoid print(const array<T, N> &arr, char sep) {\n    print(arr,\
    \ string{sep});\n}\n\n// TODO\uFF1A\u305D\u306E\u3046\u3061\u81EA\u52D5\u5B9F\u884C\
    \u3068\u304B\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\u3002\n// test cases\
    \ for print() and cout <<\n// pair<char, int> p = {'a', 1};\n// cout << p << '\\\
    n';\n// print(p);\n// tuple<char, int, ll, string> tp = {'a', 1, 2, \"abc\"};\n\
    // cout << tp << '\\n';\n// print(tp);\n// vector<ll> vec = {1, 2, 3, 4, 5};\n\
    // cout << vec << '\\n';\n// print(vec);\n// print(vec, \"\\n\");\n// array<ll,\
    \ 5> arr = {1, 2, 3, 4, 5};\n// cout << arr << '\\n';\n// print(arr);\n// print(arr,\
    \ \"\\n\");\n// deque<ll> que = {1, 2, 3, 4, 5};\n// print(que);\n// print(que,\
    \ \"\\n\");\n// set<ll> se = {1, 2, 3, 4, 5};\n// print(se);\n// print(se, \"\\\
    n\");\n// print({1, 2, 3, 4, 5});\n// print({1, 2, 3, 4, 5}, \"\\n\");\n// print();\n\
    // ll a = 100;\n// cout << a << '\\n';\n// print(a);\n// print(100);\n// string\
    \ S = \"abc\";\n// cout << S << '\\n';\n// print(S);\n// print(\"abc\");\n// char\
    \ c = 'a';\n// cout << c << '\\n';\n// print(c);\n// print('a');\n// // print(1,\
    \ \"abc\", 22LL);\n// // print(s, c);\n\n// test cases for debug()\n// int a =\
    \ 2;\n// string b = \"agc\";\n// char c = 'z';\n// ll d = 10000;\n// debug(a,\
    \  b, \"aaa\", 'y', c,d, max((ll)a, d));\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n#include \"chmax.hpp\"\n\n// \u203B\
    \u5185\u5074\u3067\u547C\u3070\u308C\u305D\u3046\u306A\u3082\u306E\u307B\u3069\
    \u4E0A\u306B\u66F8\u3044\u3066\u304A\u304F\u3002\n\n// pair\ntemplate<typename\
    \ T1, typename T2>\nostream &operator<<(ostream &os, const pair<T1, T2> &p) {\n\
    \    return os << p.first << ' ' << p.second;\n}\n\n// tuple\n// see: https://gist.github.com/naskya/1e5e5cd269cfe16a76988378a60e2ca3#file-debug_print-hpp-L150\n\
    template<class T, size_t... Is>\nvoid print_tuple(ostream &os, const T &arg, index_sequence<Is...>)\
    \ {\n    static_cast<void>(((os << (Is == 0 ? \"\" : \" \"), os << get<Is>(arg)),\
    \ ...));\n}\ntemplate<class... Ts>\nostream &operator<<(ostream &os, const tuple<Ts...>\
    \ &arg) {\n    print_tuple(os, arg, make_index_sequence<sizeof...(Ts)>());\n \
    \   return os;\n}\n\n// \u65E7\u4ED5\u69D8\u3002\u65B0\u4ED5\u69D8\u3067\u3042\
    \u308B\u7A0B\u5EA6\u52D5\u4F5C\u554F\u984C\u306A\u3044\u78BA\u8A8D\u304C\u53D6\
    \u308C\u305F\u3089\u524A\u9664\n// template<typename T1, typename T2, typename\
    \ T3>\n// ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &tp) {\n//\
    \     return os << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp);\n// }\n\
    // template<typename T1, typename T2, typename T3, typename T4>\n// ostream &operator<<(ostream\
    \ &os, const tuple<T1, T2, T3, T4> &tp) {\n//     return os << get<0>(tp) << '\
    \ ' << get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp);\n// }\n// template<typename\
    \ T1, typename T2, typename T3>\n// void print(const tuple<T1, T2, T3> &tp) {\n\
    //     cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\\n';\n\
    // }\n// template<typename T1, typename T2, typename T3, typename T4>\n// void\
    \ print(const tuple<T1, T2, T3, T4> &tp) {\n//     cout << get<0>(tp) << ' ' <<\
    \ get<1>(tp) << ' ' << get<2>(tp) << ' ' << get<3>(tp) << '\\n';\n// }\n\n// array\n\
    template<typename T, size_t N>\nostream &operator<<(ostream &os, const array<T,\
    \ N> &arr) {\n    rep(i, N) {\n        os << arr[i];\n        if (i != (int)N\
    \ - 1) {\n            os << ' ';\n        }\n    }\n    return os;\n}\ntemplate<typename\
    \ T, size_t N>\nvoid print(const array<T, N> &arr, string sep = \" \") {\n   \
    \ rep(i, N) {\n        cout << arr[i];\n        if (i != (int)N - 1) cout << sep;\n\
    \    }\n    cout << '\\n';\n}\n\n// vector\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &vec) {\n    rep(i, vec.size()) {\n        os << vec[i];\n\
    \        if (i != (int)vec.size() - 1) {\n            os << ' ';\n        }\n\
    \    }\n    return os;\n}\ntemplate<typename T>\nvoid print(const vector<T> &vec,\
    \ string sep = \" \") {\n    rep(i, vec.size()) {\n        cout << vec[i];\n \
    \       if (i != (int)vec.size() - 1) cout << sep;\n    }\n    cout << '\\n';\n\
    }\n\n// deque\ntemplate<typename T>\nvoid print(const deque<T> &que, string sep\
    \ = \" \") {\n    vector<T> vec(ALL(que));\n    print(vec, sep);\n}\n\n// set\n\
    template<typename T>\nvoid print(const set<T> &se, string sep = \" \") {\n   \
    \ vector<T> vec(ALL(se));\n    print(vec, sep);\n}\n\n// set, multiset, deque,\
    \ etc...\n// \u203B\u3068\u3066\u3082\u6C4E\u7528\u6027\u9AD8\u3044\u3093\u3060\
    \u3051\u3069\u3001string\u307E\u3067\u53D6\u308A\u8FBC\u307E\u308C\u3066vector\u306B\
    \u3055\u308C\u3066\u3057\u307E\u3046\u306E\u3067\u4F7F\u308F\u306A\u3044\n// template<template<typename\
    \ T>class Container, typename T>\n// void print(const Container<T>& con, string\
    \ sep=\" \") {\n//     vector<T> V(ALL(con));\n//     print(V, sep);\n// }\n\n\
    // initializer_list (\u300Cprint({1, 2, 3, 4});\u300D\u3068\u304B\u3067\u304D\u308B\
    )\ntemplate<typename T>\nvoid print(const initializer_list<T> &li, string sep\
    \ = \" \") {\n    vector<T> V(ALL(li));\n    print(V, sep);\n}\n\n// \u53EF\u5909\
    \u9577\u5F15\u6570\u3002operator<<\u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3055\u3048\
    \u3044\u308C\u3070\u3001\u578B\u304C\u9055\u3046\u540C\u58EB\u3067\u3082\u96D1\
    \u591A\u306B\u4E26\u3079\u3066\u51FA\u529B\u3067\u304D\u308B\n// \u203Bprint(vector,\
    \ \"\\n\")\u3068\u304B\u3082\u3053\u3053\u306B\u6765\u3066\u3057\u307E\u3063\u305F\
    \u306E\u3067\u4E00\u65E6\u4E2D\u6B62\n// template<typename T, typename... Ts>\n\
    // void print(const T val, Ts... ts) {\n//     if constexpr (sizeof...(Ts) ==\
    \ 0) {\n//         cout << val << '\\n';\n//     } else {\n//         cout <<\
    \ val << ' ';\n//         print(ts...);\n//     }\n// }\n\n// \u6539\u884C\u306E\
    \u307F\nvoid print() {\n    cout << '\\n';\n}\n\n// \u305D\u306E\u4ED6 (pair,tuple,string\u7B49\
    \u3082\u3053\u3053\u306B\u6765\u3066operator<<\u306B\u6E21\u3055\u308C\u308B)\n\
    template<typename T>\nvoid print(T out) {\n    cout << out << '\\n';\n}\n\n//\
    \ debug (\u5909\u6570\u540D\u4ED8\u304D\u3067\u51FA\u529B\u3001stderr\u306A\u306E\
    \u3067\u63D0\u51FA\u3092\u90AA\u9B54\u3057\u306A\u3044)\n// #define debug(x) (cerr\
    \ << #x << \": \" << x << endl);\n// \u53EF\u5909\u9577\u5F15\u6570\u5BFE\u5FDC\
    \u7248\n// see: https://blog.naskya.net/post/meu0vkh5cpl1/\n#define debug(...)\
    \ multi_debug(#__VA_ARGS__, __VA_ARGS__)\n\n// \u30B0\u30EA\u30C3\u30C9\u3060\u3051\
    \u898B\u3084\u3059\u304F\u306A\u308B\u3088\u3046\u306B\u3061\u3087\u3063\u3068\
    \u500B\u5225\u5BFE\u5FDC\ntemplate<typename T>\nvoid multi_debug(string name,\
    \ const vv<T> &grid) {\n    cerr << name << \":\" << endl;\n    int H = grid.size();\n\
    \    int W = grid[0].size();\n    // \u5217\u6BCE\u306B\u6700\u5927\u5E45\u3092\
    \u53D6\u3063\u3066\u304A\u304F\n    vector<int> mxlen(W);\n    rep(h, H) {\n \
    \       rep(w, W) {\n            chmax(mxlen[w], (int)tostr(grid[h][w]).size());\n\
    \        }\n    }\n    rep(h, H) {\n        rep(w, W) {\n            int pad =\
    \ mxlen[w] - (int)tostr(grid[h][w]).size();\n            cerr << string(pad, '\
    \ ') << grid[h][w];\n            if (w == W - 1) {\n                cerr << endl;\n\
    \            } else {\n                cerr << ' ';\n            }\n        }\n\
    \    }\n}\n\ntemplate<class Tp, class... Ts>\nvoid multi_debug(string names, Tp\
    \ arg, Ts... args) {\n    // args...\u306E\u30D1\u30E9\u30E1\u30FC\u30BF\u304C\
    0\u500B\u306E\u3068\u304D\u3001\u5358\u306Barg\u3060\u3051\u3092\u51FA\u529B\u3057\
    \u3066\u7D42\u4E86\n    if constexpr (sizeof...(Ts) == 0) {\n        while (names.back()\
    \ == ' ') {\n            names.pop_back();\n        }\n        cerr << names <<\
    \ \": \" << arg << endl;\n    } else {\n        // names\u306B\u306F\u5168\u90E8\
    \u306E\u5909\u6570\u306E\u540D\u524D\u304C\u683C\u7D0D\u3055\u308C\u3066\u3044\
    \u308B\u306E\u3067\u30011\u3064\u76EE\u306E\u5909\u6570\u540D\u306E\u7D42\u308F\
    \u308A\u306E','\u306E\u4F4D\u7F6E\u3092\u63A2\u3059\n        int n = names.size(),\
    \ comma_pos = -1, paren_depth = 0,\n            inside_quote = false;\n      \
    \  rep(i, n) {\n            if (not inside_quote and paren_depth == 0 and names[i]\
    \ == ',') {\n                comma_pos = i;\n                break;\n        \
    \    }\n            if (names[i] == '\\\"' or names[i] == '\\'') {\n         \
    \       if (i > 0 and names[i - 1] == '\\\\') continue;\n                inside_quote\
    \ ^= true;\n            }\n            if (not inside_quote and names[i] == '(')\
    \ {\n                paren_depth++;\n            }\n            if (not inside_quote\
    \ and names[i] == ')') {\n                paren_depth--;\n            }\n    \
    \    }\n        assert(comma_pos != -1);\n        string name = names.substr(0,\
    \ comma_pos);\n        while (name.back() == ' ') {\n            name.pop_back();\n\
    \        }\n        cerr << name << \": \" << arg << endl;\n\n        int next_begin_at\
    \ = comma_pos + 1;\n        while (names[next_begin_at] == ' ') {\n          \
    \  next_begin_at++;\n        }\n        names = names.substr(next_begin_at);\n\
    \        // \u3053\u306E\u95A2\u6570\u3092\u518D\u5E30\u7684\u306B\u547C\u3093\
    \u3067\u6B8B\u308A\u306E\u5909\u6570\u3082\u51FA\u529B\u3059\u308B\n        multi_debug(names,\
    \ args...);\n    }\n}\n\n// \u5F8C\u65B9\u4E92\u63DB\ntemplate<typename T>\nvoid\
    \ print(const vector<T> &V, char sep) {\n    print(V, string{sep});\n}\ntemplate<typename\
    \ T, size_t N>\nvoid print(const array<T, N> &arr, char sep) {\n    print(arr,\
    \ string{sep});\n}\n\n// TODO\uFF1A\u305D\u306E\u3046\u3061\u81EA\u52D5\u5B9F\u884C\
    \u3068\u304B\u3067\u304D\u308B\u3088\u3046\u306B\u3059\u308B\u3002\n// test cases\
    \ for print() and cout <<\n// pair<char, int> p = {'a', 1};\n// cout << p << '\\\
    n';\n// print(p);\n// tuple<char, int, ll, string> tp = {'a', 1, 2, \"abc\"};\n\
    // cout << tp << '\\n';\n// print(tp);\n// vector<ll> vec = {1, 2, 3, 4, 5};\n\
    // cout << vec << '\\n';\n// print(vec);\n// print(vec, \"\\n\");\n// array<ll,\
    \ 5> arr = {1, 2, 3, 4, 5};\n// cout << arr << '\\n';\n// print(arr);\n// print(arr,\
    \ \"\\n\");\n// deque<ll> que = {1, 2, 3, 4, 5};\n// print(que);\n// print(que,\
    \ \"\\n\");\n// set<ll> se = {1, 2, 3, 4, 5};\n// print(se);\n// print(se, \"\\\
    n\");\n// print({1, 2, 3, 4, 5});\n// print({1, 2, 3, 4, 5}, \"\\n\");\n// print();\n\
    // ll a = 100;\n// cout << a << '\\n';\n// print(a);\n// print(100);\n// string\
    \ S = \"abc\";\n// cout << S << '\\n';\n// print(S);\n// print(\"abc\");\n// char\
    \ c = 'a';\n// cout << c << '\\n';\n// print(c);\n// print('a');\n// // print(1,\
    \ \"abc\", 22LL);\n// // print(s, c);\n\n// test cases for debug()\n// int a =\
    \ 2;\n// string b = \"agc\";\n// char c = 'z';\n// ll d = 10000;\n// debug(a,\
    \  b, \"aaa\", 'y', c,d, max((ll)a, d));\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  - src/common/chmax.hpp
  isVerificationFile: false
  path: src/common/print.hpp
  requiredBy:
  - src/math/fps/pow_term2.hpp
  - src/math/fps/pow.hpp
  - src/math/FormalPowerSeries.hpp
  - src/template.hpp
  - src/mystl/Deque.hpp
  - src/mystl/Multiset.hpp
  - src/mystl/Set.hpp
  - src/mystl/Vector.hpp
  - src/common/yesno.hpp
  - src/graph/AuxiliaryTree.hpp
  timestamp: '2024-01-08 14:31:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/MatPow.test.cpp
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
  - test/graph/WeightedUnionFind.test.cpp
  - test/graph/UnionFind.test.cpp
documentation_of: src/common/print.hpp
layout: document
redirect_from:
- /library/src/common/print.hpp
- /library/src/common/print.hpp.html
title: src/common/print.hpp
---
