---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  - icon: ':warning:'
    path: src/numbers/gcd.hpp
    title: src/numbers/gcd.hpp
  - icon: ':warning:'
    path: src/numbers/lcm.hpp
    title: src/numbers/lcm.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/numbers/gcd.hpp\"\
    \n\n// \u975E\u518D\u5E30\u7248\u4F5C\u3063\u3066\u307F\u305F\u3051\u3069\u3001\
    \u901F\u5EA6\u3042\u3093\u307E\u5909\u308F\u3089\u306A\u305D\u3046\u2026\u3002\
    \ntemplate<typename T>\nT gcd(T a, T b) {\n    while (b) {\n        T t = a %\
    \ b;\n        a = b;\n        b = t;\n    }\n    return a;\n}\n\n// template<typename\
    \ T>\n// T gcd(T a, T b) { return __gcd(a, b); }\n\ntemplate<typename T>\nT gcd(const\
    \ vector<T> &A) {\n    T res = 0;\n    for (auto a : A) res = gcd(res, a);\n \
    \   return res;\n}\n#line 4 \"src/numbers/lcm.hpp\"\n\n// \u9664\u7B97\u3092\u524D\
    \u306B\u51FA\u3057\u3066\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3092\u9632\
    \u3050\ntemplate<typename T>\nT lcm(T x, T y) { return x/gcd(x, y)*y; }\n\ntemplate<typename\
    \ T>\nT lcm(const vector<T> &A) {\n    T res = 1;\n    for (auto a : A) res =\
    \ lcm(res, a);\n    return res;\n}\n#line 4 \"src/numbers/Fraction.hpp\"\n\ntemplate<typename\
    \ T>\nstruct Fraction {\n    T numerator, denominator;\n\n    Fraction() : numerator((T)1),\
    \ denominator((T)1) {}\n\n    Fraction(T nu) : numerator(nu), denominator((T)1)\
    \ {}\n\n    Fraction(T nu, T de) : numerator(nu), denominator(de) {\n        assert(de\
    \ != (T)0);\n        // \u30DE\u30A4\u30CA\u30B9\u3092\u5206\u5B50\u5074\u306B\
    \n        if (de < (T)0) {\n            numerator *= -1;\n            denominator\
    \ *= -1;\n        }\n    }\n\n    Fraction(const Fraction<T> &a) : numerator(a.numerator),\
    \ denominator(a.denominator) {\n        assert(a.denominator != (T)0);\n    }\n\
    \n    // \u901A\u5206\n    void reduce(Fraction<T>& a) {\n        T l = lcm(denominator,\
    \ a.denominator);\n        numerator = l / denominator * numerator;\n        a.numerator\
    \ = l / a.denominator * a.numerator;\n        denominator = a.denominator = l;\n\
    \    }\n\n    // \u7D04\u5206\n    void simplify() {\n        if (denominator\
    \ == (T)1) return;\n        assert(denominator >= 1);\n        // gcd\u3084\u308B\
    \u6642\u306F\u6B63\u6570\u306B\n        T g = gcd(abs(numerator), denominator);\n\
    \        numerator /= g;\n        denominator /= g;\n    }\n\n    Fraction<T>\
    \ &operator+=(Fraction<T> a) {\n        // reduce(a);\n        // numerator +=\
    \ a.numerator;\n        numerator = numerator*a.denominator + a.numerator*denominator;\n\
    \        denominator *= a.denominator;\n        simplify();\n        return *this;\n\
    \    }\n\n    Fraction<T> &operator-=(Fraction<T> a) {\n        // reduce(a);\n\
    \        // numerator -= a.numerator;\n        numerator = numerator*a.denominator\
    \ - a.numerator*denominator;\n        denominator *= a.denominator;\n        simplify();\n\
    \        return *this;\n    }\n\n    Fraction<T> &operator*=(const Fraction<T>&\
    \ a) {\n        numerator *= a.numerator;\n        denominator *= a.denominator;\n\
    \        simplify();\n        return *this;\n    }\n\n    Fraction<T> &operator/=(const\
    \ Fraction<T>& a) {\n        assert(a.numerator != (T)0);\n        numerator *=\
    \ a.denominator;\n        denominator *= a.numerator;\n        // \u30DE\u30A4\
    \u30CA\u30B9\u3092\u5206\u5B50\u5074\u306B\n        if (a.numerator < (T)0) {\n\
    \            numerator *= -1;\n            denominator *= -1;\n        }\n   \
    \     simplify();\n        return *this;\n    }\n\n    Fraction<T> &operator++()\
    \ {\n        *this += 1;\n        return *this;\n    }\n\n    Fraction<T> &operator--()\
    \ {\n        *this -= 1;\n        return *this;\n    }\n\n    Fraction<T> operator++(int)\
    \ {\n        Fraction<T> result = *this;\n        ++*this;\n        return result;\n\
    \    }\n\n    Fraction<T> operator--(int) {\n        Fraction<T> result = *this;\n\
    \        --*this;\n        return result;\n    }\n\n    Fraction<T> operator-()\
    \ const { return {-numerator, denominator}; }\n\n    Fraction<T> operator+(const\
    \ Fraction<T>& a) const { return Fraction<T>(*this) += a; }\n\n    Fraction<T>\
    \ operator-(const Fraction<T>& a) const { return Fraction<T>(*this) -= a; }\n\n\
    \    Fraction<T> operator*(const Fraction<T>& a) const { return Fraction<T>(*this)\
    \ *= a; }\n\n    Fraction<T> operator/(const Fraction<T>& a) const { return Fraction<T>(*this)\
    \ /= a; }\n\n    bool operator==(const Fraction<T>& a) const {\n        return\
    \ numerator == a.numerator and denominator == a.denominator;\n    }\n\n    bool\
    \ operator!=(const Fraction<T>& a) const {\n        return numerator != a.numerator\
    \ or denominator != a.denominator;\n    }\n\n    bool operator<(const Fraction<T>&\
    \ a) const {\n        return numerator*a.denominator < a.numerator*denominator;\n\
    \    }\n\n    bool operator<=(const Fraction<T>& a) const {\n        return numerator*a.denominator\
    \ <= a.numerator*denominator;\n    }\n\n    bool operator>(const Fraction<T>&\
    \ a) const {\n        return numerator*a.denominator > a.numerator*denominator;\n\
    \    }\n\n    bool operator>=(const Fraction<T>& a) const {\n        return numerator*a.denominator\
    \ >= a.numerator*denominator;\n    }\n\n    friend istream &operator>>(istream&\
    \ is, Fraction<T>& a) {\n        is >> a.numerator;\n        a.denominator = 1;\n\
    \        return (is);\n    }\n\n    friend ostream& operator<<(ostream& os, const\
    \ Fraction<T>& a) {\n        return os << a.numerator << \"/\" << a.denominator;\n\
    \    }\n};\n"
  code: "#include \"../base.hpp\"\n#include \"gcd.hpp\"\n#include \"lcm.hpp\"\n\n\
    template<typename T>\nstruct Fraction {\n    T numerator, denominator;\n\n   \
    \ Fraction() : numerator((T)1), denominator((T)1) {}\n\n    Fraction(T nu) : numerator(nu),\
    \ denominator((T)1) {}\n\n    Fraction(T nu, T de) : numerator(nu), denominator(de)\
    \ {\n        assert(de != (T)0);\n        // \u30DE\u30A4\u30CA\u30B9\u3092\u5206\
    \u5B50\u5074\u306B\n        if (de < (T)0) {\n            numerator *= -1;\n \
    \           denominator *= -1;\n        }\n    }\n\n    Fraction(const Fraction<T>\
    \ &a) : numerator(a.numerator), denominator(a.denominator) {\n        assert(a.denominator\
    \ != (T)0);\n    }\n\n    // \u901A\u5206\n    void reduce(Fraction<T>& a) {\n\
    \        T l = lcm(denominator, a.denominator);\n        numerator = l / denominator\
    \ * numerator;\n        a.numerator = l / a.denominator * a.numerator;\n     \
    \   denominator = a.denominator = l;\n    }\n\n    // \u7D04\u5206\n    void simplify()\
    \ {\n        if (denominator == (T)1) return;\n        assert(denominator >= 1);\n\
    \        // gcd\u3084\u308B\u6642\u306F\u6B63\u6570\u306B\n        T g = gcd(abs(numerator),\
    \ denominator);\n        numerator /= g;\n        denominator /= g;\n    }\n\n\
    \    Fraction<T> &operator+=(Fraction<T> a) {\n        // reduce(a);\n       \
    \ // numerator += a.numerator;\n        numerator = numerator*a.denominator +\
    \ a.numerator*denominator;\n        denominator *= a.denominator;\n        simplify();\n\
    \        return *this;\n    }\n\n    Fraction<T> &operator-=(Fraction<T> a) {\n\
    \        // reduce(a);\n        // numerator -= a.numerator;\n        numerator\
    \ = numerator*a.denominator - a.numerator*denominator;\n        denominator *=\
    \ a.denominator;\n        simplify();\n        return *this;\n    }\n\n    Fraction<T>\
    \ &operator*=(const Fraction<T>& a) {\n        numerator *= a.numerator;\n   \
    \     denominator *= a.denominator;\n        simplify();\n        return *this;\n\
    \    }\n\n    Fraction<T> &operator/=(const Fraction<T>& a) {\n        assert(a.numerator\
    \ != (T)0);\n        numerator *= a.denominator;\n        denominator *= a.numerator;\n\
    \        // \u30DE\u30A4\u30CA\u30B9\u3092\u5206\u5B50\u5074\u306B\n        if\
    \ (a.numerator < (T)0) {\n            numerator *= -1;\n            denominator\
    \ *= -1;\n        }\n        simplify();\n        return *this;\n    }\n\n   \
    \ Fraction<T> &operator++() {\n        *this += 1;\n        return *this;\n  \
    \  }\n\n    Fraction<T> &operator--() {\n        *this -= 1;\n        return *this;\n\
    \    }\n\n    Fraction<T> operator++(int) {\n        Fraction<T> result = *this;\n\
    \        ++*this;\n        return result;\n    }\n\n    Fraction<T> operator--(int)\
    \ {\n        Fraction<T> result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    Fraction<T> operator-() const { return {-numerator, denominator};\
    \ }\n\n    Fraction<T> operator+(const Fraction<T>& a) const { return Fraction<T>(*this)\
    \ += a; }\n\n    Fraction<T> operator-(const Fraction<T>& a) const { return Fraction<T>(*this)\
    \ -= a; }\n\n    Fraction<T> operator*(const Fraction<T>& a) const { return Fraction<T>(*this)\
    \ *= a; }\n\n    Fraction<T> operator/(const Fraction<T>& a) const { return Fraction<T>(*this)\
    \ /= a; }\n\n    bool operator==(const Fraction<T>& a) const {\n        return\
    \ numerator == a.numerator and denominator == a.denominator;\n    }\n\n    bool\
    \ operator!=(const Fraction<T>& a) const {\n        return numerator != a.numerator\
    \ or denominator != a.denominator;\n    }\n\n    bool operator<(const Fraction<T>&\
    \ a) const {\n        return numerator*a.denominator < a.numerator*denominator;\n\
    \    }\n\n    bool operator<=(const Fraction<T>& a) const {\n        return numerator*a.denominator\
    \ <= a.numerator*denominator;\n    }\n\n    bool operator>(const Fraction<T>&\
    \ a) const {\n        return numerator*a.denominator > a.numerator*denominator;\n\
    \    }\n\n    bool operator>=(const Fraction<T>& a) const {\n        return numerator*a.denominator\
    \ >= a.numerator*denominator;\n    }\n\n    friend istream &operator>>(istream&\
    \ is, Fraction<T>& a) {\n        is >> a.numerator;\n        a.denominator = 1;\n\
    \        return (is);\n    }\n\n    friend ostream& operator<<(ostream& os, const\
    \ Fraction<T>& a) {\n        return os << a.numerator << \"/\" << a.denominator;\n\
    \    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/numbers/gcd.hpp
  - src/macros.hpp
  - src/numbers/lcm.hpp
  isVerificationFile: false
  path: src/numbers/Fraction.hpp
  requiredBy: []
  timestamp: '2023-05-22 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numbers/Fraction.hpp
layout: document
redirect_from:
- /library/src/numbers/Fraction.hpp
- /library/src/numbers/Fraction.hpp.html
title: src/numbers/Fraction.hpp
---
