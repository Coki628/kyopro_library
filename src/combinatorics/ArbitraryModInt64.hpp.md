---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
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
    - https://atcoder.jp/contests/abc339/editorial/9206
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/combinatorics/ArbitraryModInt64.hpp\"\
    \n\n// \u4EFB\u610FModInt64\u30D3\u30C3\u30C8\u7248\ntemplate<int id = 1>\nstruct\
    \ ArbitraryModInt64 {\n    ull x = 0;\n    using uint128_t = __uint128_t;\n\n\
    \    ArbitraryModInt64() : x(0) {}\n\n    ArbitraryModInt64(int64_t y)\n     \
    \   : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n\
    \n    // \u5927\u304D\u3044\u6570\u5B57\u6587\u5B57\u5217\u304B\u3089\u306Emint\u5909\
    \u63DB\n    // see: https://atcoder.jp/contests/abc339/editorial/9206\n    ArbitraryModInt64(string\
    \ s) {\n        uint128_t res = 0;\n        for(auto &c : s){\n            assert(isdigit(c));\n\
    \            int d = c - '0';\n            res = (res * 10 + d) % get_mod();\n\
    \        }\n        x = res;\n    }\n\n    static ull &get_mod() {\n        static\
    \ ull mod = 0;\n        return mod;\n    }\n\n    static void set_mod(ull md)\
    \ {\n        get_mod() = md;\n    }\n\n    ArbitraryModInt64 &operator++() {\n\
    \        x++;\n        if (x == get_mod()) x = 0;\n        return *this;\n   \
    \ }\n\n    ArbitraryModInt64 &operator--() {\n        if (x == 0) x = get_mod();\n\
    \        x--;\n        return *this;\n    }\n\n    ArbitraryModInt64 &operator+=(const\
    \ ArbitraryModInt64 &p) {\n        if ((x += p.x) >= get_mod()) x -= get_mod();\n\
    \        return *this;\n    }\n\n    ArbitraryModInt64 &operator-=(const ArbitraryModInt64\
    \ &p) {\n        if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n  \
    \      return *this;\n    }\n\n    ArbitraryModInt64 &operator*=(const ArbitraryModInt64\
    \ &p) {\n        x = (ull)((uint128_t)1 * x * p.x % get_mod());\n        return\
    \ *this;\n    }\n\n    ArbitraryModInt64 &operator/=(const ArbitraryModInt64 &p)\
    \ {\n        *this *= p.inv();\n        return *this;\n    }\n\n    ArbitraryModInt64\
    \ operator++(int) {\n        ArbitraryModInt64 result = *this;\n        ++*this;\n\
    \        return result;\n    }\n\n    ArbitraryModInt64 operator--(int) {\n  \
    \      ArbitraryModInt64 result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    ArbitraryModInt64 operator-() const {\n        return ArbitraryModInt64(-x);\n\
    \    }\n\n    ArbitraryModInt64 operator+(const ArbitraryModInt64 &p) const {\n\
    \        return ArbitraryModInt64(*this) += p;\n    }\n\n    ArbitraryModInt64\
    \ operator-(const ArbitraryModInt64 &p) const {\n        return ArbitraryModInt64(*this)\
    \ -= p;\n    }\n\n    ArbitraryModInt64 operator*(const ArbitraryModInt64 &p)\
    \ const {\n        return ArbitraryModInt64(*this) *= p;\n    }\n\n    ArbitraryModInt64\
    \ operator/(const ArbitraryModInt64 &p) const {\n        return ArbitraryModInt64(*this)\
    \ /= p;\n    }\n\n    bool operator==(const ArbitraryModInt64 &p) const {\n  \
    \      return x == p.x;\n    }\n\n    bool operator!=(const ArbitraryModInt64\
    \ &p) const {\n        return x != p.x;\n    }\n\n    // \u203BModInt\u306E\u5927\
    \u5C0F\u6BD4\u8F03\u306B\u610F\u5473\u306F\u306A\u3044\u3051\u3069\u3001\u3053\
    \u308C\u4F5C\u3063\u3068\u304F\u3068map\u306E\u30AD\u30FC\u306B\u4F7F\u3048\u308B\
    \u3088\u3046\u306B\u306A\u308B\n    bool operator<(const ArbitraryModInt64 &p)\
    \ const {\n        return x < p.x;\n    }\n\n    ArbitraryModInt64 inv() const\
    \ {\n        ull a = x, b = get_mod(), u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return ArbitraryModInt64(u);\n    }\n\n  \
    \  ArbitraryModInt64 pow(int64_t n) const {\n        ArbitraryModInt64 ret(1),\
    \ mul(x);\n        while (n > 0) {\n            if (n & 1) ret *= mul;\n     \
    \       mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n  \
    \  }\n\n    friend ostream &operator<<(ostream &os, const ArbitraryModInt64 &p)\
    \ {\n        return os << p.x;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, ArbitraryModInt64 &a) {\n        int64_t t;\n        is >> t;\n       \
    \ a = ArbitraryModInt64<id>(t);\n        return (is);\n    }\n\n    explicit operator\
    \ ull() const {\n        return x;\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u4EFB\u610FModInt64\u30D3\
    \u30C3\u30C8\u7248\ntemplate<int id = 1>\nstruct ArbitraryModInt64 {\n    ull\
    \ x = 0;\n    using uint128_t = __uint128_t;\n\n    ArbitraryModInt64() : x(0)\
    \ {}\n\n    ArbitraryModInt64(int64_t y)\n        : x(y >= 0 ? y % get_mod() :\
    \ (get_mod() - (-y) % get_mod()) % get_mod()) {}\n\n    // \u5927\u304D\u3044\u6570\
    \u5B57\u6587\u5B57\u5217\u304B\u3089\u306Emint\u5909\u63DB\n    // see: https://atcoder.jp/contests/abc339/editorial/9206\n\
    \    ArbitraryModInt64(string s) {\n        uint128_t res = 0;\n        for(auto\
    \ &c : s){\n            assert(isdigit(c));\n            int d = c - '0';\n  \
    \          res = (res * 10 + d) % get_mod();\n        }\n        x = res;\n  \
    \  }\n\n    static ull &get_mod() {\n        static ull mod = 0;\n        return\
    \ mod;\n    }\n\n    static void set_mod(ull md) {\n        get_mod() = md;\n\
    \    }\n\n    ArbitraryModInt64 &operator++() {\n        x++;\n        if (x ==\
    \ get_mod()) x = 0;\n        return *this;\n    }\n\n    ArbitraryModInt64 &operator--()\
    \ {\n        if (x == 0) x = get_mod();\n        x--;\n        return *this;\n\
    \    }\n\n    ArbitraryModInt64 &operator+=(const ArbitraryModInt64 &p) {\n  \
    \      if ((x += p.x) >= get_mod()) x -= get_mod();\n        return *this;\n \
    \   }\n\n    ArbitraryModInt64 &operator-=(const ArbitraryModInt64 &p) {\n   \
    \     if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n        return\
    \ *this;\n    }\n\n    ArbitraryModInt64 &operator*=(const ArbitraryModInt64 &p)\
    \ {\n        x = (ull)((uint128_t)1 * x * p.x % get_mod());\n        return *this;\n\
    \    }\n\n    ArbitraryModInt64 &operator/=(const ArbitraryModInt64 &p) {\n  \
    \      *this *= p.inv();\n        return *this;\n    }\n\n    ArbitraryModInt64\
    \ operator++(int) {\n        ArbitraryModInt64 result = *this;\n        ++*this;\n\
    \        return result;\n    }\n\n    ArbitraryModInt64 operator--(int) {\n  \
    \      ArbitraryModInt64 result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    ArbitraryModInt64 operator-() const {\n        return ArbitraryModInt64(-x);\n\
    \    }\n\n    ArbitraryModInt64 operator+(const ArbitraryModInt64 &p) const {\n\
    \        return ArbitraryModInt64(*this) += p;\n    }\n\n    ArbitraryModInt64\
    \ operator-(const ArbitraryModInt64 &p) const {\n        return ArbitraryModInt64(*this)\
    \ -= p;\n    }\n\n    ArbitraryModInt64 operator*(const ArbitraryModInt64 &p)\
    \ const {\n        return ArbitraryModInt64(*this) *= p;\n    }\n\n    ArbitraryModInt64\
    \ operator/(const ArbitraryModInt64 &p) const {\n        return ArbitraryModInt64(*this)\
    \ /= p;\n    }\n\n    bool operator==(const ArbitraryModInt64 &p) const {\n  \
    \      return x == p.x;\n    }\n\n    bool operator!=(const ArbitraryModInt64\
    \ &p) const {\n        return x != p.x;\n    }\n\n    // \u203BModInt\u306E\u5927\
    \u5C0F\u6BD4\u8F03\u306B\u610F\u5473\u306F\u306A\u3044\u3051\u3069\u3001\u3053\
    \u308C\u4F5C\u3063\u3068\u304F\u3068map\u306E\u30AD\u30FC\u306B\u4F7F\u3048\u308B\
    \u3088\u3046\u306B\u306A\u308B\n    bool operator<(const ArbitraryModInt64 &p)\
    \ const {\n        return x < p.x;\n    }\n\n    ArbitraryModInt64 inv() const\
    \ {\n        ull a = x, b = get_mod(), u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return ArbitraryModInt64(u);\n    }\n\n  \
    \  ArbitraryModInt64 pow(int64_t n) const {\n        ArbitraryModInt64 ret(1),\
    \ mul(x);\n        while (n > 0) {\n            if (n & 1) ret *= mul;\n     \
    \       mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n  \
    \  }\n\n    friend ostream &operator<<(ostream &os, const ArbitraryModInt64 &p)\
    \ {\n        return os << p.x;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, ArbitraryModInt64 &a) {\n        int64_t t;\n        is >> t;\n       \
    \ a = ArbitraryModInt64<id>(t);\n        return (is);\n    }\n\n    explicit operator\
    \ ull() const {\n        return x;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/ArbitraryModInt64.hpp
  requiredBy: []
  timestamp: '2024-02-06 01:26:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/ArbitraryModInt64.hpp
layout: document
redirect_from:
- /library/src/combinatorics/ArbitraryModInt64.hpp
- /library/src/combinatorics/ArbitraryModInt64.hpp.html
title: src/combinatorics/ArbitraryModInt64.hpp
---
