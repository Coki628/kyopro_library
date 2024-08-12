---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/math/fps/pow_term2.hpp
    title: src/math/fps/pow_term2.hpp
  - icon: ':warning:'
    path: src/math/garner.hpp
    title: src/math/garner.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix/MatPow.test.cpp
    title: test/matrix/MatPow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc339/editorial/9206
    - https://ei1333.github.io/library/math/combinatorics/mod-int.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/combinatorics/ModInt.hpp\"\n\n// \u53C2\u8003\uFF1A\
    https://ei1333.github.io/library/math/combinatorics/mod-int.cpp\n// ModInt\ntemplate<int\
    \ mod>\nstruct ModInt {\n    int x = 0;\n\n    ModInt() : x(0) {}\n\n    ModInt(int64_t\
    \ y)\n        : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n    // \u5927\
    \u304D\u3044\u6570\u5B57\u6587\u5B57\u5217\u304B\u3089\u306Emint\u5909\u63DB\n\
    \    // see: https://atcoder.jp/contests/abc339/editorial/9206\n    ModInt(string\
    \ s) {\n        auto res = 0LL;\n        for(auto &c : s){\n            assert(isdigit(c));\n\
    \            int d = c - '0';\n            res = (res * 10 + d) % mod;\n     \
    \   }\n        x = res;\n    }\n\n    static int get_mod() {\n        return mod;\n\
    \    }\n\n    ModInt &operator++() {\n        x++;\n        if (x == mod) x =\
    \ 0;\n        return *this;\n    }\n\n    ModInt &operator--() {\n        if (x\
    \ == 0) x = mod;\n        x--;\n        return *this;\n    }\n\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    ModInt &operator-=(const ModInt &p) {\n        if ((x += mod - p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (int)(1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inv();\n\
    \        return *this;\n    }\n\n    ModInt operator++(int) {\n        ModInt\
    \ result = *this;\n        ++*this;\n        return result;\n    }\n\n    ModInt\
    \ operator--(int) {\n        ModInt result = *this;\n        --*this;\n      \
    \  return result;\n    }\n\n    ModInt operator-() const {\n        return ModInt(-x);\n\
    \    }\n\n    ModInt operator+(const ModInt &p) const {\n        return ModInt(*this)\
    \ += p;\n    }\n\n    ModInt operator-(const ModInt &p) const {\n        return\
    \ ModInt(*this) -= p;\n    }\n\n    ModInt operator*(const ModInt &p) const {\n\
    \        return ModInt(*this) *= p;\n    }\n\n    ModInt operator/(const ModInt\
    \ &p) const {\n        return ModInt(*this) /= p;\n    }\n\n    bool operator==(const\
    \ ModInt &p) const {\n        return x == p.x;\n    }\n\n    bool operator!=(const\
    \ ModInt &p) const {\n        return x != p.x;\n    }\n\n    // \u203BModInt\u306E\
    \u5927\u5C0F\u6BD4\u8F03\u306B\u610F\u5473\u306F\u306A\u3044\u3051\u3069\u3001\
    \u3053\u308C\u4F5C\u3063\u3068\u304F\u3068map\u306E\u30AD\u30FC\u306B\u4F7F\u3048\
    \u308B\u3088\u3046\u306B\u306A\u308B\n    bool operator<(const ModInt &p) const\
    \ {\n        return x < p.x;\n    }\n\n    ModInt inv() const {\n        int a\
    \ = x, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t = a /\
    \ b;\n            swap(a -= t * b, b);\n            swap(u -= t * v, v);\n   \
    \     }\n        return ModInt(u);\n    }\n\n    ModInt pow(int64_t n) const {\n\
    \        ModInt ret(1), mul(x);\n        while (n > 0) {\n            if (n &\
    \ 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n \
    \       return ret;\n    }\n\n    friend ostream &operator<<(ostream &os, const\
    \ ModInt &p) {\n        return os << p.x;\n    }\n\n    friend istream &operator>>(istream\
    \ &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n        a = ModInt<mod>(t);\n\
    \        return (is);\n    }\n\n    explicit operator int() const {\n        return\
    \ x;\n    }\n    explicit operator ll() const {\n        return x;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/math/combinatorics/mod-int.cpp\n\
    // ModInt\ntemplate<int mod>\nstruct ModInt {\n    int x = 0;\n\n    ModInt()\
    \ : x(0) {}\n\n    ModInt(int64_t y)\n        : x(y >= 0 ? y % mod : (mod - (-y)\
    \ % mod) % mod) {}\n\n    // \u5927\u304D\u3044\u6570\u5B57\u6587\u5B57\u5217\u304B\
    \u3089\u306Emint\u5909\u63DB\n    // see: https://atcoder.jp/contests/abc339/editorial/9206\n\
    \    ModInt(string s) {\n        auto res = 0LL;\n        for(auto &c : s){\n\
    \            assert(isdigit(c));\n            int d = c - '0';\n            res\
    \ = (res * 10 + d) % mod;\n        }\n        x = res;\n    }\n\n    static int\
    \ get_mod() {\n        return mod;\n    }\n\n    ModInt &operator++() {\n    \
    \    x++;\n        if (x == mod) x = 0;\n        return *this;\n    }\n\n    ModInt\
    \ &operator--() {\n        if (x == 0) x = mod;\n        x--;\n        return\
    \ *this;\n    }\n\n    ModInt &operator+=(const ModInt &p) {\n        if ((x +=\
    \ p.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const\
    \ ModInt &p) {\n        if ((x += mod - p.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n\n    ModInt &operator*=(const ModInt &p) {\n        x = (int)(1LL\
    \ * x * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt &p) {\n        *this *= p.inv();\n        return *this;\n    }\n\n  \
    \  ModInt operator++(int) {\n        ModInt result = *this;\n        ++*this;\n\
    \        return result;\n    }\n\n    ModInt operator--(int) {\n        ModInt\
    \ result = *this;\n        --*this;\n        return result;\n    }\n\n    ModInt\
    \ operator-() const {\n        return ModInt(-x);\n    }\n\n    ModInt operator+(const\
    \ ModInt &p) const {\n        return ModInt(*this) += p;\n    }\n\n    ModInt\
    \ operator-(const ModInt &p) const {\n        return ModInt(*this) -= p;\n   \
    \ }\n\n    ModInt operator*(const ModInt &p) const {\n        return ModInt(*this)\
    \ *= p;\n    }\n\n    ModInt operator/(const ModInt &p) const {\n        return\
    \ ModInt(*this) /= p;\n    }\n\n    bool operator==(const ModInt &p) const {\n\
    \        return x == p.x;\n    }\n\n    bool operator!=(const ModInt &p) const\
    \ {\n        return x != p.x;\n    }\n\n    // \u203BModInt\u306E\u5927\u5C0F\u6BD4\
    \u8F03\u306B\u610F\u5473\u306F\u306A\u3044\u3051\u3069\u3001\u3053\u308C\u4F5C\
    \u3063\u3068\u304F\u3068map\u306E\u30AD\u30FC\u306B\u4F7F\u3048\u308B\u3088\u3046\
    \u306B\u306A\u308B\n    bool operator<(const ModInt &p) const {\n        return\
    \ x < p.x;\n    }\n\n    ModInt inv() const {\n        int a = x, b = mod, u =\
    \ 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n            swap(a\
    \ -= t * b, b);\n            swap(u -= t * v, v);\n        }\n        return ModInt(u);\n\
    \    }\n\n    ModInt pow(int64_t n) const {\n        ModInt ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend ostream &operator<<(ostream &os, const ModInt &p) {\n        return os\
    \ << p.x;\n    }\n\n    friend istream &operator>>(istream &is, ModInt &a) {\n\
    \        int64_t t;\n        is >> t;\n        a = ModInt<mod>(t);\n        return\
    \ (is);\n    }\n\n    explicit operator int() const {\n        return x;\n   \
    \ }\n    explicit operator ll() const {\n        return x;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/ModInt.hpp
  requiredBy:
  - src/math/garner.hpp
  - src/math/fps/pow_term2.hpp
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/MatPow.test.cpp
documentation_of: src/combinatorics/ModInt.hpp
layout: document
redirect_from:
- /library/src/combinatorics/ModInt.hpp
- /library/src/combinatorics/ModInt.hpp.html
title: src/combinatorics/ModInt.hpp
---