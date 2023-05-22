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
    - https://ei1333.github.io/library/math/combinatorics/mod-int.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/combinatorics/ModInt.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/math/combinatorics/mod-int.cpp\n// ModInt\n\
    template<int mod>\nstruct ModInt {\n    int x = 0;\n\n    ModInt() : x(0) {}\n\
    \n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n\
    \    ModInt &operator++() {\n        x++;\n        if (x == mod) x = 0;\n    \
    \    return *this;\n    }\n\n    ModInt &operator--() {\n        if (x == 0) x\
    \ = mod;\n        x--;\n        return *this;\n    }\n\n    ModInt &operator+=(const\
    \ ModInt &p) {\n        if((x += p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    ModInt &operator-=(const ModInt &p) {\n        if((x += mod - p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator*=(const\
    \ ModInt &p) {\n        x = (int) (1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    ModInt &operator/=(const ModInt &p) {\n        *this *= p.inv();\n\
    \        return *this;\n    }\n\n    ModInt operator++(int) {\n        ModInt\
    \ result = *this;\n        ++*this;\n        return result;\n    }\n\n    ModInt\
    \ operator--(int) {\n        ModInt result = *this;\n        --*this;\n      \
    \  return result;\n    }\n\n    ModInt operator-() const { return ModInt(-x);\
    \ }\n\n    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p;\
    \ }\n\n    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p;\
    \ }\n\n    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p;\
    \ }\n\n    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p;\
    \ }\n\n    bool operator==(const ModInt &p) const { return x == p.x; }\n\n   \
    \ bool operator!=(const ModInt &p) const { return x != p.x; }\n\n    ModInt inv()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return ModInt(u);\n    }\n\n    ModInt pow(int64_t\
    \ n) const {\n        ModInt ret(1), mul(x);\n        while(n > 0) {\n       \
    \     if(n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n \
    \       }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ModInt &p) {\n        return os << p.x;\n    }\n\n    friend istream\
    \ &operator>>(istream &is, ModInt &a) {\n        int64_t t;\n        is >> t;\n\
    \        a = ModInt< mod >(t);\n        return (is);\n    }\n\n    static int\
    \ get_mod() { return mod; }\n\n    #ifdef CAST_MINT_TO_LL\n        // mint\u304B\
    \u3089\u623B\u3057\u305F\u3044\u5834\u9762\u304C\u3042\u3063\u305F\u3089\u30B3\
    \u30E1\u30F3\u30C8\u5916\u3059\n        // operator int() const { return x; }\n\
    \        operator ll() const { return x; }\n    #endif\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/math/combinatorics/mod-int.cpp\n\
    // ModInt\ntemplate<int mod>\nstruct ModInt {\n    int x = 0;\n\n    ModInt()\
    \ : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod)\
    \ % mod) {}\n\n    ModInt &operator++() {\n        x++;\n        if (x == mod)\
    \ x = 0;\n        return *this;\n    }\n\n    ModInt &operator--() {\n       \
    \ if (x == 0) x = mod;\n        x--;\n        return *this;\n    }\n\n    ModInt\
    \ &operator+=(const ModInt &p) {\n        if((x += p.x) >= mod) x -= mod;\n  \
    \      return *this;\n    }\n\n    ModInt &operator-=(const ModInt &p) {\n   \
    \     if((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n    }\n\n\
    \    ModInt &operator*=(const ModInt &p) {\n        x = (int) (1LL * x * p.x %\
    \ mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const ModInt &p)\
    \ {\n        *this *= p.inv();\n        return *this;\n    }\n\n    ModInt operator++(int)\
    \ {\n        ModInt result = *this;\n        ++*this;\n        return result;\n\
    \    }\n\n    ModInt operator--(int) {\n        ModInt result = *this;\n     \
    \   --*this;\n        return result;\n    }\n\n    ModInt operator-() const {\
    \ return ModInt(-x); }\n\n    ModInt operator+(const ModInt &p) const { return\
    \ ModInt(*this) += p; }\n\n    ModInt operator-(const ModInt &p) const { return\
    \ ModInt(*this) -= p; }\n\n    ModInt operator*(const ModInt &p) const { return\
    \ ModInt(*this) *= p; }\n\n    ModInt operator/(const ModInt &p) const { return\
    \ ModInt(*this) /= p; }\n\n    bool operator==(const ModInt &p) const { return\
    \ x == p.x; }\n\n    bool operator!=(const ModInt &p) const { return x != p.x;\
    \ }\n\n    ModInt inv() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n\
    \        while(b > 0) {\n            t = a / b;\n            swap(a -= t * b,\
    \ b);\n            swap(u -= t * v, v);\n        }\n        return ModInt(u);\n\
    \    }\n\n    ModInt pow(int64_t n) const {\n        ModInt ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const ModInt &p) {\n        return os << p.x;\n\
    \    }\n\n    friend istream &operator>>(istream &is, ModInt &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = ModInt< mod >(t);\n        return (is);\n\
    \    }\n\n    static int get_mod() { return mod; }\n\n    #ifdef CAST_MINT_TO_LL\n\
    \        // mint\u304B\u3089\u623B\u3057\u305F\u3044\u5834\u9762\u304C\u3042\u3063\
    \u305F\u3089\u30B3\u30E1\u30F3\u30C8\u5916\u3059\n        // operator int() const\
    \ { return x; }\n        operator ll() const { return x; }\n    #endif\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/ModInt.hpp
  requiredBy:
  - src/math/fps/pow_term2.hpp
  - src/math/garner.hpp
  timestamp: '2022-08-29 14:43:01+09:00'
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
