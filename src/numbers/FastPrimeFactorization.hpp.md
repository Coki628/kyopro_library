---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/RLE.hpp
    title: src/common/RLE.hpp
  - icon: ':warning:'
    path: src/common/sorted.hpp
    title: src/common/sorted.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://miller-rabin.appspot.com/
    - https://ei1333.github.io/library/math/number-theory/fast-prime-factorization.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/common/RLE.hpp\"\
    \n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\ntemplate<typename T>\n\
    vector<pair<T, int>> RLE(const vector<T> &A) {\n    if (A.empty()) return {};\n\
    \    int N = A.size();\n    vector<pair<T, int>> res;\n    T cur = A[0];\n   \
    \ int cnt = 1;\n    rep(i, 1, N) {\n        if (A[i] == A[i - 1]) {\n        \
    \    cnt++;\n        } else {\n            res.pb({cur, cnt});\n            cnt\
    \ = 1;\n            cur = A[i];\n        }\n    }\n    res.pb({cur, cnt});\n \
    \   return res;\n}\n\n// \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E(\u6587\
    \u5B57\u5217)\nvector<pair<char, int>> RLE(const string &S) {\n    if (S.empty())\
    \ return {};\n    int N = S.size();\n    vector<pair<char, int>> res;\n    char\
    \ cur = S[0];\n    int cnt = 1;\n    rep(i, 1, N) {\n        if (S[i] == S[i -\
    \ 1]) {\n            cnt++;\n        } else {\n            res.pb({cur, cnt});\n\
    \            cnt = 1;\n            cur = S[i];\n        }\n    }\n    res.pb({cur,\
    \ cnt});\n    return res;\n}\n#line 3 \"src/common/sorted.hpp\"\n\ntemplate<typename\
    \ T>\nvector<T> sorted(vector<T> A, bool reverse = false) {\n    sort(ALL(A));\n\
    \    if (reverse) std::reverse(ALL(A));\n    return A;\n}\n\nstring sorted(string\
    \ S, bool reverse = false) {\n    sort(ALL(S));\n    if (reverse) std::reverse(ALL(S));\n\
    \    return S;\n}\n#line 5 \"src/numbers/FastPrimeFactorization.hpp\"\n\n// \u53C2\
    \u8003\uFF1Ahttps://ei1333.github.io/library/math/number-theory/fast-prime-factorization.hpp\n\
    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\n// \u30FB\u3046\u3057\u3055\u3093\
    \u306E\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u3092\u30D9\u30FC\u30B9\u306B\
    \u3001\u81EA\u5206\u7528\u306E\u95A2\u6570\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3002\n// \u30FB\u4E0A\u8A18\u95A2\u6570\u306E\u540D\u524D\u304C\u7AF6\u5408\
    \u3059\u308B\u306E\u3067\u3001using name space\u306F\u4F7F\u308F\u306A\u3044\u3002\
    \n\nnamespace FastPrimeFactorization {\ntemplate<typename word, typename dword,\
    \ typename sword>\nstruct UnsafeMod {\n    UnsafeMod() : x(0) {}\n\n    UnsafeMod(word\
    \ _x) : x(init(_x)) {}\n\n    bool operator==(const UnsafeMod &rhs) const {\n\
    \        return x == rhs.x;\n    }\n\n    bool operator!=(const UnsafeMod &rhs)\
    \ const {\n        return x != rhs.x;\n    }\n\n    UnsafeMod &operator+=(const\
    \ UnsafeMod &rhs) {\n        if ((x += rhs.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n\n    UnsafeMod &operator-=(const UnsafeMod &rhs) {\n       \
    \ if (sword(x -= rhs.x) < 0) x += mod;\n        return *this;\n    }\n\n    UnsafeMod\
    \ &operator*=(const UnsafeMod &rhs) {\n        x = reduce(dword(x) * rhs.x);\n\
    \        return *this;\n    }\n\n    UnsafeMod operator+(const UnsafeMod &rhs)\
    \ const {\n        return UnsafeMod(*this) += rhs;\n    }\n\n    UnsafeMod operator-(const\
    \ UnsafeMod &rhs) const {\n        return UnsafeMod(*this) -= rhs;\n    }\n\n\
    \    UnsafeMod operator*(const UnsafeMod &rhs) const {\n        return UnsafeMod(*this)\
    \ *= rhs;\n    }\n\n    UnsafeMod pow(uint64_t e) const {\n        UnsafeMod ret(1);\n\
    \        for (UnsafeMod base = *this; e; e >>= 1, base *= base) {\n          \
    \  if (e & 1) ret *= base;\n        }\n        return ret;\n    }\n\n    word\
    \ get() const {\n        return reduce(x);\n    }\n\n    static constexpr int\
    \ word_bits = sizeof(word) * 8;\n\n    static word modulus() {\n        return\
    \ mod;\n    }\n\n    static word init(word w) {\n        return reduce(dword(w)\
    \ * r2);\n    }\n\n    static void set_mod(word m) {\n        mod = m;\n     \
    \   inv = mul_inv(mod);\n        r2 = -dword(mod) % mod;\n    }\n\n    static\
    \ word reduce(dword x) {\n        word y = word(x >> word_bits) -\n          \
    \       word((dword(word(x) * inv) * mod) >> word_bits);\n        return sword(y)\
    \ < 0 ? y + mod : y;\n    }\n\n    static word mul_inv(word n, int e = 6, word\
    \ x = 1) {\n        return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));\n    }\n\
    \n    static word mod, inv, r2;\n\n    word x;\n};\n\nusing uint128_t = __uint128_t;\n\
    \nusing Mod64 = UnsafeMod<uint64_t, uint128_t, int64_t>;\ntemplate<>\nuint64_t\
    \ Mod64::mod = 0;\ntemplate<>\nuint64_t Mod64::inv = 0;\ntemplate<>\nuint64_t\
    \ Mod64::r2 = 0;\n\nusing Mod32 = UnsafeMod<uint32_t, uint64_t, int32_t>;\ntemplate<>\n\
    uint32_t Mod32::mod = 0;\ntemplate<>\nuint32_t Mod32::inv = 0;\ntemplate<>\nuint32_t\
    \ Mod32::r2 = 0;\n\nbool miller_rabin_primality_test_uint64(uint64_t n) {\n  \
    \  Mod64::set_mod(n);\n    uint64_t d = n - 1;\n    while (d % 2 == 0) d /= 2;\n\
    \    Mod64 e{1}, rev{n - 1};\n    // http://miller-rabin.appspot.com/    < 2^64\n\
    \    for (uint64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n\
    \        if (n <= a) break;\n        uint64_t t = d;\n        Mod64 y = Mod64(a).pow(t);\n\
    \        while (t != n - 1 && y != e && y != rev) {\n            y *= y;\n   \
    \         t *= 2;\n        }\n        if (y != rev && t % 2 == 0) return false;\n\
    \    }\n    return true;\n}\n\nbool miller_rabin_primality_test_uint32(uint32_t\
    \ n) {\n    Mod32::set_mod(n);\n    uint32_t d = n - 1;\n    while (d % 2 == 0)\
    \ d /= 2;\n    Mod32 e{1}, rev{n - 1};\n    for (uint32_t a : {2, 7, 61}) {\n\
    \        if (n <= a) break;\n        uint32_t t = d;\n        Mod32 y = Mod32(a).pow(t);\n\
    \        while (t != n - 1 && y != e && y != rev) {\n            y *= y;\n   \
    \         t *= 2;\n        }\n        if (y != rev && t % 2 == 0) return false;\n\
    \    }\n    return true;\n}\n\nbool is_prime(uint64_t n) {\n    if (n == 2) return\
    \ true;\n    if (n == 1 || n % 2 == 0) return false;\n    if (n < uint64_t(1)\
    \ << 31) return miller_rabin_primality_test_uint32(n);\n    return miller_rabin_primality_test_uint64(n);\n\
    }\n\nuint64_t pollard_rho(uint64_t n) {\n    if (is_prime(n)) return n;\n    if\
    \ (n % 2 == 0) return 2;\n    Mod64::set_mod(n);\n    uint64_t d;\n    Mod64 one{1};\n\
    \    for (Mod64 c{one};; c += one) {\n        Mod64 x{2}, y{2};\n        do {\n\
    \            x = x * x + c;\n            y = y * y + c;\n            y = y * y\
    \ + c;\n            d = __gcd((x - y).get(), n);\n        } while (d == 1);\n\
    \        if (d < n) return d;\n    }\n    assert(0);\n}\n\nvector<uint64_t> prime_factor(uint64_t\
    \ n) {\n    if (n <= 1) return {};\n    uint64_t p = pollard_rho(n);\n    if (p\
    \ == n) return {p};\n    auto l = prime_factor(p);\n    auto r = prime_factor(n\
    \ / p);\n    copy(begin(r), end(r), back_inserter(l));\n    return l;\n}\n\n//\
    \ 10^18\u3067\u3082\u901A\u7528\u3059\u308B\u7D20\u56E0\u6570\u5206\u89E3\nvector<pair<uint64_t,\
    \ int>> factorize(uint64_t n) {\n    auto res = prime_factor(n);\n    return RLE(sorted(res));\n\
    }\n\n// 10^18\u3067\u3082\u901A\u7528\u3059\u308B\u7D04\u6570\u5217\u6319\nvector<uint64_t>\
    \ divisors(uint64_t n) {\n    vector<uint64_t> res = {1};\n    for (auto [p, c]\
    \ : factorize(n)) {\n        int sz = res.size();\n        rep(i, sz) {\n    \
    \        uint64_t d = res[i];\n            rep(_, c) {\n                d *= p;\n\
    \                res.eb(d);\n            }\n        }\n    }\n    return res;\n\
    }\n}; // namespace FastPrimeFactorization\n"
  code: "#pragma once\n#include \"../common/RLE.hpp\"\n#include \"../common/sorted.hpp\"\
    \n#include \"../macros.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/math/number-theory/fast-prime-factorization.hpp\n\
    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\n// \u30FB\u3046\u3057\u3055\u3093\
    \u306E\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u3092\u30D9\u30FC\u30B9\u306B\
    \u3001\u81EA\u5206\u7528\u306E\u95A2\u6570\u3092\u8FFD\u52A0\u3057\u305F\u3082\
    \u306E\u3002\n// \u30FB\u4E0A\u8A18\u95A2\u6570\u306E\u540D\u524D\u304C\u7AF6\u5408\
    \u3059\u308B\u306E\u3067\u3001using name space\u306F\u4F7F\u308F\u306A\u3044\u3002\
    \n\nnamespace FastPrimeFactorization {\ntemplate<typename word, typename dword,\
    \ typename sword>\nstruct UnsafeMod {\n    UnsafeMod() : x(0) {}\n\n    UnsafeMod(word\
    \ _x) : x(init(_x)) {}\n\n    bool operator==(const UnsafeMod &rhs) const {\n\
    \        return x == rhs.x;\n    }\n\n    bool operator!=(const UnsafeMod &rhs)\
    \ const {\n        return x != rhs.x;\n    }\n\n    UnsafeMod &operator+=(const\
    \ UnsafeMod &rhs) {\n        if ((x += rhs.x) >= mod) x -= mod;\n        return\
    \ *this;\n    }\n\n    UnsafeMod &operator-=(const UnsafeMod &rhs) {\n       \
    \ if (sword(x -= rhs.x) < 0) x += mod;\n        return *this;\n    }\n\n    UnsafeMod\
    \ &operator*=(const UnsafeMod &rhs) {\n        x = reduce(dword(x) * rhs.x);\n\
    \        return *this;\n    }\n\n    UnsafeMod operator+(const UnsafeMod &rhs)\
    \ const {\n        return UnsafeMod(*this) += rhs;\n    }\n\n    UnsafeMod operator-(const\
    \ UnsafeMod &rhs) const {\n        return UnsafeMod(*this) -= rhs;\n    }\n\n\
    \    UnsafeMod operator*(const UnsafeMod &rhs) const {\n        return UnsafeMod(*this)\
    \ *= rhs;\n    }\n\n    UnsafeMod pow(uint64_t e) const {\n        UnsafeMod ret(1);\n\
    \        for (UnsafeMod base = *this; e; e >>= 1, base *= base) {\n          \
    \  if (e & 1) ret *= base;\n        }\n        return ret;\n    }\n\n    word\
    \ get() const {\n        return reduce(x);\n    }\n\n    static constexpr int\
    \ word_bits = sizeof(word) * 8;\n\n    static word modulus() {\n        return\
    \ mod;\n    }\n\n    static word init(word w) {\n        return reduce(dword(w)\
    \ * r2);\n    }\n\n    static void set_mod(word m) {\n        mod = m;\n     \
    \   inv = mul_inv(mod);\n        r2 = -dword(mod) % mod;\n    }\n\n    static\
    \ word reduce(dword x) {\n        word y = word(x >> word_bits) -\n          \
    \       word((dword(word(x) * inv) * mod) >> word_bits);\n        return sword(y)\
    \ < 0 ? y + mod : y;\n    }\n\n    static word mul_inv(word n, int e = 6, word\
    \ x = 1) {\n        return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));\n    }\n\
    \n    static word mod, inv, r2;\n\n    word x;\n};\n\nusing uint128_t = __uint128_t;\n\
    \nusing Mod64 = UnsafeMod<uint64_t, uint128_t, int64_t>;\ntemplate<>\nuint64_t\
    \ Mod64::mod = 0;\ntemplate<>\nuint64_t Mod64::inv = 0;\ntemplate<>\nuint64_t\
    \ Mod64::r2 = 0;\n\nusing Mod32 = UnsafeMod<uint32_t, uint64_t, int32_t>;\ntemplate<>\n\
    uint32_t Mod32::mod = 0;\ntemplate<>\nuint32_t Mod32::inv = 0;\ntemplate<>\nuint32_t\
    \ Mod32::r2 = 0;\n\nbool miller_rabin_primality_test_uint64(uint64_t n) {\n  \
    \  Mod64::set_mod(n);\n    uint64_t d = n - 1;\n    while (d % 2 == 0) d /= 2;\n\
    \    Mod64 e{1}, rev{n - 1};\n    // http://miller-rabin.appspot.com/    < 2^64\n\
    \    for (uint64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n\
    \        if (n <= a) break;\n        uint64_t t = d;\n        Mod64 y = Mod64(a).pow(t);\n\
    \        while (t != n - 1 && y != e && y != rev) {\n            y *= y;\n   \
    \         t *= 2;\n        }\n        if (y != rev && t % 2 == 0) return false;\n\
    \    }\n    return true;\n}\n\nbool miller_rabin_primality_test_uint32(uint32_t\
    \ n) {\n    Mod32::set_mod(n);\n    uint32_t d = n - 1;\n    while (d % 2 == 0)\
    \ d /= 2;\n    Mod32 e{1}, rev{n - 1};\n    for (uint32_t a : {2, 7, 61}) {\n\
    \        if (n <= a) break;\n        uint32_t t = d;\n        Mod32 y = Mod32(a).pow(t);\n\
    \        while (t != n - 1 && y != e && y != rev) {\n            y *= y;\n   \
    \         t *= 2;\n        }\n        if (y != rev && t % 2 == 0) return false;\n\
    \    }\n    return true;\n}\n\nbool is_prime(uint64_t n) {\n    if (n == 2) return\
    \ true;\n    if (n == 1 || n % 2 == 0) return false;\n    if (n < uint64_t(1)\
    \ << 31) return miller_rabin_primality_test_uint32(n);\n    return miller_rabin_primality_test_uint64(n);\n\
    }\n\nuint64_t pollard_rho(uint64_t n) {\n    if (is_prime(n)) return n;\n    if\
    \ (n % 2 == 0) return 2;\n    Mod64::set_mod(n);\n    uint64_t d;\n    Mod64 one{1};\n\
    \    for (Mod64 c{one};; c += one) {\n        Mod64 x{2}, y{2};\n        do {\n\
    \            x = x * x + c;\n            y = y * y + c;\n            y = y * y\
    \ + c;\n            d = __gcd((x - y).get(), n);\n        } while (d == 1);\n\
    \        if (d < n) return d;\n    }\n    assert(0);\n}\n\nvector<uint64_t> prime_factor(uint64_t\
    \ n) {\n    if (n <= 1) return {};\n    uint64_t p = pollard_rho(n);\n    if (p\
    \ == n) return {p};\n    auto l = prime_factor(p);\n    auto r = prime_factor(n\
    \ / p);\n    copy(begin(r), end(r), back_inserter(l));\n    return l;\n}\n\n//\
    \ 10^18\u3067\u3082\u901A\u7528\u3059\u308B\u7D20\u56E0\u6570\u5206\u89E3\nvector<pair<uint64_t,\
    \ int>> factorize(uint64_t n) {\n    auto res = prime_factor(n);\n    return RLE(sorted(res));\n\
    }\n\n// 10^18\u3067\u3082\u901A\u7528\u3059\u308B\u7D04\u6570\u5217\u6319\nvector<uint64_t>\
    \ divisors(uint64_t n) {\n    vector<uint64_t> res = {1};\n    for (auto [p, c]\
    \ : factorize(n)) {\n        int sz = res.size();\n        rep(i, sz) {\n    \
    \        uint64_t d = res[i];\n            rep(_, c) {\n                d *= p;\n\
    \                res.eb(d);\n            }\n        }\n    }\n    return res;\n\
    }\n}; // namespace FastPrimeFactorization\n"
  dependsOn:
  - src/common/RLE.hpp
  - src/macros.hpp
  - src/base.hpp
  - src/common/sorted.hpp
  isVerificationFile: false
  path: src/numbers/FastPrimeFactorization.hpp
  requiredBy: []
  timestamp: '2023-12-04 17:57:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/FastPrimeFactorization.hpp
layout: document
redirect_from:
- /library/src/numbers/FastPrimeFactorization.hpp
- /library/src/numbers/FastPrimeFactorization.hpp.html
title: src/numbers/FastPrimeFactorization.hpp
---
