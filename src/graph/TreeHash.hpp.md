---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/combinatorics/ModInt64.hpp
    title: src/combinatorics/ModInt64.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/chmax.hpp
    title: src/common/chmax.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/tree/tree-hash.hpp
    - https://snuke.hatenablog.com/entry/2017/02/03/054210
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing ull\
    \ = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/combinatorics/ModInt64.hpp\"\
    \n\ntemplate<ull mod>\nstruct ModInt64 {\n    ull x = 0;\n    using uint128_t\
    \ = __uint128_t;\n\n    ModInt64() : x(0) {}\n\n    ModInt64(int64_t y) : x(y\
    \ >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    // \u5927\u304D\u3044\u6570\
    \u5B57\u6587\u5B57\u5217\u304B\u3089\u306Emint\u5909\u63DB\n    // see: https://atcoder.jp/contests/abc339/editorial/9206\n\
    \    ModInt64(string s) {\n        uint128_t res = 0;\n        for(auto &c : s){\n\
    \            assert(isdigit(c));\n            int d = c - '0';\n            res\
    \ = (res * 10 + d) % mod;\n        }\n        x = res;\n    }\n\n    static ull\
    \ get_mod() {\n        return mod;\n    }\n\n    ModInt64 &operator++() {\n  \
    \      x++;\n        if (x == mod) x = 0;\n        return *this;\n    }\n\n  \
    \  ModInt64 &operator--() {\n        if (x == 0) x = mod;\n        x--;\n    \
    \    return *this;\n    }\n\n    ModInt64 &operator+=(const ModInt64 &p) {\n \
    \       if ((x += p.x) >= mod) x -= mod;\n        return *this;\n    }\n\n   \
    \ ModInt64 &operator-=(const ModInt64 &p) {\n        if ((x += mod - p.x) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n\n    ModInt64 &operator*=(const ModInt64\
    \ &p) {\n        x = (ull)((uint128_t)1 * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    ModInt64 &operator/=(const ModInt64 &p) {\n        *this *= p.inv();\n\
    \        return *this;\n    }\n\n    ModInt64 operator++(int) {\n        ModInt64\
    \ result = *this;\n        ++*this;\n        return result;\n    }\n\n    ModInt64\
    \ operator--(int) {\n        ModInt64 result = *this;\n        --*this;\n    \
    \    return result;\n    }\n\n    ModInt64 operator-() const {\n        return\
    \ ModInt64(-x);\n    }\n\n    ModInt64 operator+(const ModInt64 &p) const {\n\
    \        return ModInt64(*this) += p;\n    }\n\n    ModInt64 operator-(const ModInt64\
    \ &p) const {\n        return ModInt64(*this) -= p;\n    }\n\n    ModInt64 operator*(const\
    \ ModInt64 &p) const {\n        return ModInt64(*this) *= p;\n    }\n\n    ModInt64\
    \ operator/(const ModInt64 &p) const {\n        return ModInt64(*this) /= p;\n\
    \    }\n\n    bool operator==(const ModInt64 &p) const {\n        return x ==\
    \ p.x;\n    }\n\n    bool operator!=(const ModInt64 &p) const {\n        return\
    \ x != p.x;\n    }\n\n    // \u203BModInt\u306E\u5927\u5C0F\u6BD4\u8F03\u306B\u610F\
    \u5473\u306F\u306A\u3044\u3051\u3069\u3001\u3053\u308C\u4F5C\u3063\u3068\u304F\
    \u3068map\u306E\u30AD\u30FC\u306B\u4F7F\u3048\u308B\u3088\u3046\u306B\u306A\u308B\
    \n    bool operator<(const ModInt64 &p) const {\n        return x < p.x;\n   \
    \ }\n\n    ModInt64 inv() const {\n        ull a = x, b = mod, u = 1, v = 0, t;\n\
    \        while (b > 0) {\n            t = a / b;\n            swap(a -= t * b,\
    \ b);\n            swap(u -= t * v, v);\n        }\n        return ModInt64(u);\n\
    \    }\n\n    ModInt64 pow(int64_t n) const {\n        ModInt64 ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend ostream &operator<<(ostream &os, const ModInt64 &p) {\n        return\
    \ os << p.x;\n    }\n\n    friend istream &operator>>(istream &is, ModInt64 &a)\
    \ {\n        ull t;\n        is >> t;\n        a = ModInt64<mod>(t);\n       \
    \ return (is);\n    }\n\n    explicit operator ull() const {\n        return x;\n\
    \    }\n};\n#line 2 \"src/common/chmax.hpp\"\n\ntemplate<typename T>\nbool chmax(T\
    \ &x, T y) {\n    return (y > x) ? x = y, true : false;\n}\n#line 5 \"src/graph/TreeHash.hpp\"\
    \n\n// \u6839\u4ED8\u304D\u6728\u306E\u30CF\u30C3\u30B7\u30E5\n// \u53C2\u8003\
    \uFF1Ahttps://nyaannyaan.github.io/library/tree/tree-hash.hpp\n// \u3000\u3000\
    \u3000https://snuke.hatenablog.com/entry/2017/02/03/054210\n// \u30FB\u5B9F\u88C5\
    \u306FNyaan\u3055\u3093\u3001\u7406\u5C48\u306F\u3059\u306C\u3051\u3055\u3093\u306E\
    \u8A18\u4E8B\u3092\u53C2\u8003\u306B\u3002\n// \u30FB\u30CF\u30C3\u30B7\u30E5\u306E\
    \u5B9F\u88C5\u306F\u65E2\u5B58\u306E\u30ED\u30EA\u30CF\u304B\u3089\u30D9\u30FC\
    \u30B9\u3068\u306A\u308B\u90E8\u5206\u306F\u6D41\u7528\u3057\u305F\u3002\nstruct\
    \ TreeHash {\n    static const ull mod = (1ull << 61ull) - 1;\n    using mint64\
    \ = ModInt64<mod>;\n    int n;\n    vector<mint64> base;\n\n    TreeHash(int n)\
    \ : n(n) {\n        // 2^61-1\u4EE5\u4E0B\u306E\u4E71\u6570\u3092\u8FD4\u3059\n\
    \        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<ull> rand(1, TreeHash::mod - 1);\n        base.assign(n,\
    \ 0);\n        rep(d, n) {\n            // \u6DF1\u3055\u6BCE\u306B\u4E71\u6570\
    base\u3092\u6C7A\u3081\u3066\u304A\u304F\n            base[d] = rand(mt);\n  \
    \      }\n    }\n\n    // \u9802\u70B9root\u3092\u6839\u3068\u3057\u305F\u6728\
    nodes\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u8FD4\u3059\n    vector<mint64> get_hash(const\
    \ vvi &nodes, int root = 0) {\n        assert(nodes.size() <= this->n);\n    \
    \    int N = nodes.size();\n        // \u9802\u70B9u\u3092\u6839\u3068\u3057\u305F\
    \u90E8\u5206\u6728\u3092\u8868\u3059\u30CF\u30C3\u30B7\u30E5\n        vector<mint64>\
    \ hash(N);\n        // \u8449\u304B\u3089\u898B\u305F\u6DF1\u3055\n        vector<int>\
    \ depth(N);\n        auto dfs = [&](auto &&f, int u, int prv) -> void {\n    \
    \        for (auto v : nodes[u]) {\n                if (v == prv) continue;\n\
    \                f(f, v, u);\n                chmax(depth[u], depth[v] + 1);\n\
    \            }\n            assert(depth[u] < N);\n            hash[u] = 1;\n\
    \            for (auto v : nodes[u]) {\n                if (v == prv) continue;\n\
    \                hash[u] *= base[depth[u]] + hash[v];\n            }\n       \
    \ };\n        dfs(dfs, root, -1);\n        return hash;\n    }\n};\n"
  code: "#pragma once\n#include \"../combinatorics/ModInt64.hpp\"\n#include \"../common/chmax.hpp\"\
    \n#include \"../macros.hpp\"\n\n// \u6839\u4ED8\u304D\u6728\u306E\u30CF\u30C3\u30B7\
    \u30E5\n// \u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/tree/tree-hash.hpp\n\
    // \u3000\u3000\u3000https://snuke.hatenablog.com/entry/2017/02/03/054210\n//\
    \ \u30FB\u5B9F\u88C5\u306FNyaan\u3055\u3093\u3001\u7406\u5C48\u306F\u3059\u306C\
    \u3051\u3055\u3093\u306E\u8A18\u4E8B\u3092\u53C2\u8003\u306B\u3002\n// \u30FB\u30CF\
    \u30C3\u30B7\u30E5\u306E\u5B9F\u88C5\u306F\u65E2\u5B58\u306E\u30ED\u30EA\u30CF\
    \u304B\u3089\u30D9\u30FC\u30B9\u3068\u306A\u308B\u90E8\u5206\u306F\u6D41\u7528\
    \u3057\u305F\u3002\nstruct TreeHash {\n    static const ull mod = (1ull << 61ull)\
    \ - 1;\n    using mint64 = ModInt64<mod>;\n    int n;\n    vector<mint64> base;\n\
    \n    TreeHash(int n) : n(n) {\n        // 2^61-1\u4EE5\u4E0B\u306E\u4E71\u6570\
    \u3092\u8FD4\u3059\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<ull> rand(1, TreeHash::mod - 1);\n        base.assign(n,\
    \ 0);\n        rep(d, n) {\n            // \u6DF1\u3055\u6BCE\u306B\u4E71\u6570\
    base\u3092\u6C7A\u3081\u3066\u304A\u304F\n            base[d] = rand(mt);\n  \
    \      }\n    }\n\n    // \u9802\u70B9root\u3092\u6839\u3068\u3057\u305F\u6728\
    nodes\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u8FD4\u3059\n    vector<mint64> get_hash(const\
    \ vvi &nodes, int root = 0) {\n        assert(nodes.size() <= this->n);\n    \
    \    int N = nodes.size();\n        // \u9802\u70B9u\u3092\u6839\u3068\u3057\u305F\
    \u90E8\u5206\u6728\u3092\u8868\u3059\u30CF\u30C3\u30B7\u30E5\n        vector<mint64>\
    \ hash(N);\n        // \u8449\u304B\u3089\u898B\u305F\u6DF1\u3055\n        vector<int>\
    \ depth(N);\n        auto dfs = [&](auto &&f, int u, int prv) -> void {\n    \
    \        for (auto v : nodes[u]) {\n                if (v == prv) continue;\n\
    \                f(f, v, u);\n                chmax(depth[u], depth[v] + 1);\n\
    \            }\n            assert(depth[u] < N);\n            hash[u] = 1;\n\
    \            for (auto v : nodes[u]) {\n                if (v == prv) continue;\n\
    \                hash[u] *= base[depth[u]] + hash[v];\n            }\n       \
    \ };\n        dfs(dfs, root, -1);\n        return hash;\n    }\n};\n"
  dependsOn:
  - src/combinatorics/ModInt64.hpp
  - src/macros.hpp
  - src/base.hpp
  - src/common/chmax.hpp
  isVerificationFile: false
  path: src/graph/TreeHash.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/TreeHash.hpp
layout: document
redirect_from:
- /library/src/graph/TreeHash.hpp
- /library/src/graph/TreeHash.hpp.html
title: src/graph/TreeHash.hpp
---
