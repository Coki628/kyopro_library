---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc339/editorial/9206
    - https://ei1333.github.io/library/math/combinatorics/arbitrary-mod-int.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/combinatorics/DynamicModInt.hpp\"\n\n// \u52D5\
    \u7684ModInt\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/math/combinatorics/arbitrary-mod-int.cpp\n\
    // \u30FBDynamicModInt::set_mod(mod) \u306E\u3088\u3046\u306Bstatic\u30E1\u30BD\
    \u30C3\u30C9\u3067MOD\u3092\u30BB\u30C3\u30C8\u3057\u3066\u4F7F\u3046\u3002\n\
    // \u30FBid\u3092\u632F\u3063\u3066\u540C\u3058\u30B3\u30FC\u30C9\u5185\u3067\u8907\
    \u6570MOD\u3092\u4F5C\u308C\u308B\u3088\u3046\u306B\u3057\u305F\u3002\ntemplate<int\
    \ id = 1>\nstruct DynamicModInt {\n    int x = 0;\n\n    DynamicModInt() : x(0)\
    \ {}\n\n    DynamicModInt(int64_t y)\n        : x(y >= 0 ? y % get_mod() : (get_mod()\
    \ - (-y) % get_mod()) % get_mod()) {}\n\n    // \u5927\u304D\u3044\u6570\u5B57\
    \u6587\u5B57\u5217\u304B\u3089\u306Emint\u5909\u63DB\n    // see: https://atcoder.jp/contests/abc339/editorial/9206\n\
    \    DynamicModInt(string s) {\n        auto res = 0LL;\n        for(auto &c :\
    \ s){\n            assert(isdigit(c));\n            int d = c - '0';\n       \
    \     res = (res * 10 + d) % get_mod();\n        }\n        x = res;\n    }\n\n\
    \    static int &get_mod() {\n        static int mod = 0;\n        return mod;\n\
    \    }\n\n    static void set_mod(int md) {\n        get_mod() = md;\n    }\n\n\
    \    DynamicModInt &operator++() {\n        x++;\n        if (x == get_mod())\
    \ x = 0;\n        return *this;\n    }\n\n    DynamicModInt &operator--() {\n\
    \        if (x == 0) x = get_mod();\n        x--;\n        return *this;\n   \
    \ }\n\n    DynamicModInt &operator+=(const DynamicModInt &p) {\n        if ((x\
    \ += p.x) >= get_mod()) x -= get_mod();\n        return *this;\n    }\n\n    DynamicModInt\
    \ &operator-=(const DynamicModInt &p) {\n        if ((x += get_mod() - p.x) >=\
    \ get_mod()) x -= get_mod();\n        return *this;\n    }\n\n    DynamicModInt\
    \ &operator*=(const DynamicModInt &p) {\n        x = (int)(1LL * x * p.x % get_mod());\n\
    \        return *this;\n    }\n\n    DynamicModInt &operator/=(const DynamicModInt\
    \ &p) {\n        *this *= p.inv();\n        return *this;\n    }\n\n    DynamicModInt\
    \ operator++(int) {\n        DynamicModInt result = *this;\n        ++*this;\n\
    \        return result;\n    }\n\n    DynamicModInt operator--(int) {\n      \
    \  DynamicModInt result = *this;\n        --*this;\n        return result;\n \
    \   }\n\n    DynamicModInt operator-() const {\n        return DynamicModInt(-x);\n\
    \    }\n\n    DynamicModInt operator+(const DynamicModInt &p) const {\n      \
    \  return DynamicModInt(*this) += p;\n    }\n\n    DynamicModInt operator-(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) -= p;\n    }\n\
    \n    DynamicModInt operator*(const DynamicModInt &p) const {\n        return\
    \ DynamicModInt(*this) *= p;\n    }\n\n    DynamicModInt operator/(const DynamicModInt\
    \ &p) const {\n        return DynamicModInt(*this) /= p;\n    }\n\n    bool operator==(const\
    \ DynamicModInt &p) const {\n        return x == p.x;\n    }\n\n    bool operator!=(const\
    \ DynamicModInt &p) const {\n        return x != p.x;\n    }\n\n    // \u203B\
    ModInt\u306E\u5927\u5C0F\u6BD4\u8F03\u306B\u610F\u5473\u306F\u306A\u3044\u3051\
    \u3069\u3001\u3053\u308C\u4F5C\u3063\u3068\u304F\u3068map\u306E\u30AD\u30FC\u306B\
    \u4F7F\u3048\u308B\u3088\u3046\u306B\u306A\u308B\n    bool operator<(const DynamicModInt\
    \ &p) const {\n        return x < p.x;\n    }\n\n    DynamicModInt inv() const\
    \ {\n        int a = x, b = get_mod(), u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return DynamicModInt(u);\n    }\n\n    DynamicModInt\
    \ pow(int64_t n) const {\n        DynamicModInt ret(1), mul(x);\n        while\
    \ (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n   \
    \         n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream\
    \ &operator<<(ostream &os, const DynamicModInt &p) {\n        return os << p.x;\n\
    \    }\n\n    friend istream &operator>>(istream &is, DynamicModInt &a) {\n  \
    \      int64_t t;\n        is >> t;\n        a = DynamicModInt<id>(t);\n     \
    \   return (is);\n    }\n\n    explicit operator int() const {\n        return\
    \ x;\n    }\n    explicit operator ll() const {\n        return x;\n    }\n};\n\
    // using mint = DynamicModInt;\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u52D5\u7684ModInt\n// \u53C2\
    \u8003\uFF1Ahttps://ei1333.github.io/library/math/combinatorics/arbitrary-mod-int.cpp\n\
    // \u30FBDynamicModInt::set_mod(mod) \u306E\u3088\u3046\u306Bstatic\u30E1\u30BD\
    \u30C3\u30C9\u3067MOD\u3092\u30BB\u30C3\u30C8\u3057\u3066\u4F7F\u3046\u3002\n\
    // \u30FBid\u3092\u632F\u3063\u3066\u540C\u3058\u30B3\u30FC\u30C9\u5185\u3067\u8907\
    \u6570MOD\u3092\u4F5C\u308C\u308B\u3088\u3046\u306B\u3057\u305F\u3002\ntemplate<int\
    \ id = 1>\nstruct DynamicModInt {\n    int x = 0;\n\n    DynamicModInt() : x(0)\
    \ {}\n\n    DynamicModInt(int64_t y)\n        : x(y >= 0 ? y % get_mod() : (get_mod()\
    \ - (-y) % get_mod()) % get_mod()) {}\n\n    // \u5927\u304D\u3044\u6570\u5B57\
    \u6587\u5B57\u5217\u304B\u3089\u306Emint\u5909\u63DB\n    // see: https://atcoder.jp/contests/abc339/editorial/9206\n\
    \    DynamicModInt(string s) {\n        auto res = 0LL;\n        for(auto &c :\
    \ s){\n            assert(isdigit(c));\n            int d = c - '0';\n       \
    \     res = (res * 10 + d) % get_mod();\n        }\n        x = res;\n    }\n\n\
    \    static int &get_mod() {\n        static int mod = 0;\n        return mod;\n\
    \    }\n\n    static void set_mod(int md) {\n        get_mod() = md;\n    }\n\n\
    \    DynamicModInt &operator++() {\n        x++;\n        if (x == get_mod())\
    \ x = 0;\n        return *this;\n    }\n\n    DynamicModInt &operator--() {\n\
    \        if (x == 0) x = get_mod();\n        x--;\n        return *this;\n   \
    \ }\n\n    DynamicModInt &operator+=(const DynamicModInt &p) {\n        if ((x\
    \ += p.x) >= get_mod()) x -= get_mod();\n        return *this;\n    }\n\n    DynamicModInt\
    \ &operator-=(const DynamicModInt &p) {\n        if ((x += get_mod() - p.x) >=\
    \ get_mod()) x -= get_mod();\n        return *this;\n    }\n\n    DynamicModInt\
    \ &operator*=(const DynamicModInt &p) {\n        x = (int)(1LL * x * p.x % get_mod());\n\
    \        return *this;\n    }\n\n    DynamicModInt &operator/=(const DynamicModInt\
    \ &p) {\n        *this *= p.inv();\n        return *this;\n    }\n\n    DynamicModInt\
    \ operator++(int) {\n        DynamicModInt result = *this;\n        ++*this;\n\
    \        return result;\n    }\n\n    DynamicModInt operator--(int) {\n      \
    \  DynamicModInt result = *this;\n        --*this;\n        return result;\n \
    \   }\n\n    DynamicModInt operator-() const {\n        return DynamicModInt(-x);\n\
    \    }\n\n    DynamicModInt operator+(const DynamicModInt &p) const {\n      \
    \  return DynamicModInt(*this) += p;\n    }\n\n    DynamicModInt operator-(const\
    \ DynamicModInt &p) const {\n        return DynamicModInt(*this) -= p;\n    }\n\
    \n    DynamicModInt operator*(const DynamicModInt &p) const {\n        return\
    \ DynamicModInt(*this) *= p;\n    }\n\n    DynamicModInt operator/(const DynamicModInt\
    \ &p) const {\n        return DynamicModInt(*this) /= p;\n    }\n\n    bool operator==(const\
    \ DynamicModInt &p) const {\n        return x == p.x;\n    }\n\n    bool operator!=(const\
    \ DynamicModInt &p) const {\n        return x != p.x;\n    }\n\n    // \u203B\
    ModInt\u306E\u5927\u5C0F\u6BD4\u8F03\u306B\u610F\u5473\u306F\u306A\u3044\u3051\
    \u3069\u3001\u3053\u308C\u4F5C\u3063\u3068\u304F\u3068map\u306E\u30AD\u30FC\u306B\
    \u4F7F\u3048\u308B\u3088\u3046\u306B\u306A\u308B\n    bool operator<(const DynamicModInt\
    \ &p) const {\n        return x < p.x;\n    }\n\n    DynamicModInt inv() const\
    \ {\n        int a = x, b = get_mod(), u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return DynamicModInt(u);\n    }\n\n    DynamicModInt\
    \ pow(int64_t n) const {\n        DynamicModInt ret(1), mul(x);\n        while\
    \ (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n   \
    \         n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream\
    \ &operator<<(ostream &os, const DynamicModInt &p) {\n        return os << p.x;\n\
    \    }\n\n    friend istream &operator>>(istream &is, DynamicModInt &a) {\n  \
    \      int64_t t;\n        is >> t;\n        a = DynamicModInt<id>(t);\n     \
    \   return (is);\n    }\n\n    explicit operator int() const {\n        return\
    \ x;\n    }\n    explicit operator ll() const {\n        return x;\n    }\n};\n\
    // using mint = DynamicModInt;\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/DynamicModInt.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/DynamicModInt.hpp
layout: document
redirect_from:
- /library/src/combinatorics/DynamicModInt.hpp
- /library/src/combinatorics/DynamicModInt.hpp.html
title: src/combinatorics/DynamicModInt.hpp
---
