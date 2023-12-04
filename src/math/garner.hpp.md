---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':x:'
    path: src/combinatorics/ModInt.hpp
    title: src/combinatorics/ModInt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/combinatorics/ModInt.hpp\"\n\n// \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/math/combinatorics/mod-int.cpp\n// ModInt\n\
    template<int mod>\nstruct ModInt {\n    int x = 0;\n\n    ModInt() : x(0) {}\n\
    \n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n\
    \    ModInt &operator++() {\n        x++;\n        if (x == mod) x = 0;\n    \
    \    return *this;\n    }\n\n    ModInt &operator--() {\n        if (x == 0) x\
    \ = mod;\n        x--;\n        return *this;\n    }\n\n    ModInt &operator+=(const\
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
    \        return (is);\n    }\n\n    static int get_mod() {\n        return mod;\n\
    \    }\n\n#ifdef CAST_MINT_TO_LL\n    // mint\u304B\u3089\u623B\u3057\u305F\u3044\
    \u5834\u9762\u304C\u3042\u3063\u305F\u3089\u30B3\u30E1\u30F3\u30C8\u5916\u3059\
    \n    // operator int() const { return x; }\n    operator ll() const {\n     \
    \   return x;\n    }\n#endif\n};\n#line 3 \"src/math/garner.hpp\"\n\nconstexpr\
    \ int m1 = 998244353;\nconstexpr int m2 = 1004535809;\nconstexpr int inv_m1_mod_m2\
    \ = 669690699;\nusing mint1 = ModInt<m1>;\nusing mint2 = ModInt<m2>;\n\n// MOD\u5FA9\
    \u5143\n// \u30FBint\u8D85ll\u4EE5\u5185\u307F\u305F\u3044\u306A\u6570\u3048\u4E0A\
    \u3052\u3092FPS\u3084BM\u3067\u6BB4\u308B\u6642\u306B\u4F7F\u3046\u3002\n// \u30FB\
    \u591A\u5206\u305D\u308C\u306F\u305D\u3046\u306A\u3093\u3060\u3051\u3069\u3001\
    \u8CA0\u6570\u306B\u306F\u4F7F\u3048\u306A\u3044\u3063\u307D\u3044\u3002\n// \u30FB\
    FPS\u914D\u5217\u30922\u3064\u7528\u610F\u3057\u3066\u305D\u308C\u305E\u308C\u306E\
    mod\u3067\u7B54\u3048\u3092\u51FA\u3057\u3066\u3001garner\u306B\u7A81\u3063\u8FBC\
    \u3080\u3002\n// \u30FBmint -> ll \u306E\u578B\u5909\u63DB\u3092\u4E00\u6642\u7684\
    \u306B\u6709\u52B9\u306B\u3057\u3066\u4F7F\u3046\u3002\nlong long garner(long\
    \ long r1, long long r2) {\n    long long t = (r2 - r1) * inv_m1_mod_m2;\n   \
    \ while (t < 0) t += m2;\n    t %= m2;\n    r1 += t * m1;\n    return r1;\n}\n"
  code: "#pragma once\n#include \"../combinatorics/ModInt.hpp\"\n\nconstexpr int m1\
    \ = 998244353;\nconstexpr int m2 = 1004535809;\nconstexpr int inv_m1_mod_m2 =\
    \ 669690699;\nusing mint1 = ModInt<m1>;\nusing mint2 = ModInt<m2>;\n\n// MOD\u5FA9\
    \u5143\n// \u30FBint\u8D85ll\u4EE5\u5185\u307F\u305F\u3044\u306A\u6570\u3048\u4E0A\
    \u3052\u3092FPS\u3084BM\u3067\u6BB4\u308B\u6642\u306B\u4F7F\u3046\u3002\n// \u30FB\
    \u591A\u5206\u305D\u308C\u306F\u305D\u3046\u306A\u3093\u3060\u3051\u3069\u3001\
    \u8CA0\u6570\u306B\u306F\u4F7F\u3048\u306A\u3044\u3063\u307D\u3044\u3002\n// \u30FB\
    FPS\u914D\u5217\u30922\u3064\u7528\u610F\u3057\u3066\u305D\u308C\u305E\u308C\u306E\
    mod\u3067\u7B54\u3048\u3092\u51FA\u3057\u3066\u3001garner\u306B\u7A81\u3063\u8FBC\
    \u3080\u3002\n// \u30FBmint -> ll \u306E\u578B\u5909\u63DB\u3092\u4E00\u6642\u7684\
    \u306B\u6709\u52B9\u306B\u3057\u3066\u4F7F\u3046\u3002\nlong long garner(long\
    \ long r1, long long r2) {\n    long long t = (r2 - r1) * inv_m1_mod_m2;\n   \
    \ while (t < 0) t += m2;\n    t %= m2;\n    r1 += t * m1;\n    return r1;\n}\n"
  dependsOn:
  - src/combinatorics/ModInt.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/math/garner.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/garner.hpp
layout: document
redirect_from:
- /library/src/math/garner.hpp
- /library/src/math/garner.hpp.html
title: src/math/garner.hpp
---
