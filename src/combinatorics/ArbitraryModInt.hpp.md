---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/math/combinatorics/arbitrary-mod-int.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 2 \"src/combinatorics/ArbitraryModInt.hpp\"\n\n//\
    \ \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/math/combinatorics/arbitrary-mod-int.cpp\n\
    // \u4EFB\u610FModInt\nstruct ArbitraryModInt {\n\n    int x;\n\n    ArbitraryModInt()\
    \ : x(0) {}\n\n    ArbitraryModInt(int64_t y) : x(y >= 0 ? y % get_mod() : (get_mod()\
    \ - (-y) % get_mod()) % get_mod()) {}\n\n    static int &get_mod() {\n       \
    \ static int mod = 0;\n        return mod;\n    }\n\n    static void set_mod(int\
    \ md) {\n        get_mod() = md;\n    }\n\n    ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n        if((x += p.x) >= get_mod()) x -= get_mod();\n\
    \        return *this;\n    }\n\n    ArbitraryModInt &operator-=(const ArbitraryModInt\
    \ &p) {\n        if((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n   \
    \     return *this;\n    }\n\n    ArbitraryModInt &operator*=(const ArbitraryModInt\
    \ &p) {\n        unsigned long long a = (unsigned long long) x * p.x;\n      \
    \  unsigned xh = (unsigned) (a >> 32), xl = (unsigned) a, d, m;\n        asm(\"\
    divl %4; \\n\\t\" : \"=a\" (d), \"=d\" (m) : \"d\" (xh), \"a\" (xl), \"r\" (get_mod()));\n\
    \        x = m;\n        return *this;\n    }\n\n    ArbitraryModInt &operator/=(const\
    \ ArbitraryModInt &p) {\n        *this *= p.inverse();\n        return *this;\n\
    \    }\n\n    ArbitraryModInt operator-() const { return ArbitraryModInt(-x);\
    \ }\n\n    ArbitraryModInt operator+(const ArbitraryModInt &p) const { return\
    \ ArbitraryModInt(*this) += p; }\n\n    ArbitraryModInt operator-(const ArbitraryModInt\
    \ &p) const { return ArbitraryModInt(*this) -= p; }\n\n    ArbitraryModInt operator*(const\
    \ ArbitraryModInt &p) const { return ArbitraryModInt(*this) *= p; }\n\n    ArbitraryModInt\
    \ operator/(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) /=\
    \ p; }\n\n    bool operator==(const ArbitraryModInt &p) const { return x == p.x;\
    \ }\n\n    bool operator!=(const ArbitraryModInt &p) const { return x != p.x;\
    \ }\n\n    ArbitraryModInt inverse() const {\n        int a = x, b = get_mod(),\
    \ u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n         \
    \   swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n      \
    \  return ArbitraryModInt(u);\n    }\n\n    ArbitraryModInt pow(int64_t n) const\
    \ {\n        ArbitraryModInt ret(1), mul(x);\n        while(n > 0) {\n       \
    \     if(n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n \
    \       }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ArbitraryModInt &p) {\n        return os << p.x;\n    }\n\n    friend\
    \ istream &operator>>(istream &is, ArbitraryModInt &a) {\n        int64_t t;\n\
    \        is >> t;\n        a = ArbitraryModInt(t);\n        return (is);\n   \
    \ }\n};\n// using mint = ArbitraryModInt;\n"
  code: "#include \"../base.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/math/combinatorics/arbitrary-mod-int.cpp\n\
    // \u4EFB\u610FModInt\nstruct ArbitraryModInt {\n\n    int x;\n\n    ArbitraryModInt()\
    \ : x(0) {}\n\n    ArbitraryModInt(int64_t y) : x(y >= 0 ? y % get_mod() : (get_mod()\
    \ - (-y) % get_mod()) % get_mod()) {}\n\n    static int &get_mod() {\n       \
    \ static int mod = 0;\n        return mod;\n    }\n\n    static void set_mod(int\
    \ md) {\n        get_mod() = md;\n    }\n\n    ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n        if((x += p.x) >= get_mod()) x -= get_mod();\n\
    \        return *this;\n    }\n\n    ArbitraryModInt &operator-=(const ArbitraryModInt\
    \ &p) {\n        if((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n   \
    \     return *this;\n    }\n\n    ArbitraryModInt &operator*=(const ArbitraryModInt\
    \ &p) {\n        unsigned long long a = (unsigned long long) x * p.x;\n      \
    \  unsigned xh = (unsigned) (a >> 32), xl = (unsigned) a, d, m;\n        asm(\"\
    divl %4; \\n\\t\" : \"=a\" (d), \"=d\" (m) : \"d\" (xh), \"a\" (xl), \"r\" (get_mod()));\n\
    \        x = m;\n        return *this;\n    }\n\n    ArbitraryModInt &operator/=(const\
    \ ArbitraryModInt &p) {\n        *this *= p.inverse();\n        return *this;\n\
    \    }\n\n    ArbitraryModInt operator-() const { return ArbitraryModInt(-x);\
    \ }\n\n    ArbitraryModInt operator+(const ArbitraryModInt &p) const { return\
    \ ArbitraryModInt(*this) += p; }\n\n    ArbitraryModInt operator-(const ArbitraryModInt\
    \ &p) const { return ArbitraryModInt(*this) -= p; }\n\n    ArbitraryModInt operator*(const\
    \ ArbitraryModInt &p) const { return ArbitraryModInt(*this) *= p; }\n\n    ArbitraryModInt\
    \ operator/(const ArbitraryModInt &p) const { return ArbitraryModInt(*this) /=\
    \ p; }\n\n    bool operator==(const ArbitraryModInt &p) const { return x == p.x;\
    \ }\n\n    bool operator!=(const ArbitraryModInt &p) const { return x != p.x;\
    \ }\n\n    ArbitraryModInt inverse() const {\n        int a = x, b = get_mod(),\
    \ u = 1, v = 0, t;\n        while(b > 0) {\n            t = a / b;\n         \
    \   swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n      \
    \  return ArbitraryModInt(u);\n    }\n\n    ArbitraryModInt pow(int64_t n) const\
    \ {\n        ArbitraryModInt ret(1), mul(x);\n        while(n > 0) {\n       \
    \     if(n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n \
    \       }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const ArbitraryModInt &p) {\n        return os << p.x;\n    }\n\n    friend\
    \ istream &operator>>(istream &is, ArbitraryModInt &a) {\n        int64_t t;\n\
    \        is >> t;\n        a = ArbitraryModInt(t);\n        return (is);\n   \
    \ }\n};\n// using mint = ArbitraryModInt;\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/combinatorics/ArbitraryModInt.hpp
  requiredBy: []
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/combinatorics/ArbitraryModInt.hpp
layout: document
redirect_from:
- /library/src/combinatorics/ArbitraryModInt.hpp
- /library/src/combinatorics/ArbitraryModInt.hpp.html
title: src/combinatorics/ArbitraryModInt.hpp
---
