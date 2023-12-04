---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/combinatorics/ModTools.hpp
    title: src/combinatorics/ModTools.hpp
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
    - https://ei1333.github.io/library/math/combinatorics/lagrange-polynomial-2.cpp
    - https://ei1333.github.io/library/math/combinatorics/lagrange-polynomial.cpp
    - https://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/combinatorics/ModTools.hpp\"\
    \n\n// Mod\u6570\u3048\u4E0A\u3052\u6F14\u7B97\u30C4\u30FC\u30EB\ntemplate<typename\
    \ Mint>\nstruct ModTools {\nprivate:\n    int MAX;\n    vector<Mint> _fact, _factinv,\
    \ inv;\n\npublic:\n    // nCr\u306A\u3089n\u3001nHr\u306A\u3089n+r\u307E\u3067\
    \u4F5C\u308B\n    ModTools(int mx) : MAX(++mx) {\n        _fact.resize(MAX);\n\
    \        _factinv.resize(MAX);\n        inv.resize(MAX);\n        _fact[0] = _fact[1]\
    \ = 1;\n        rep(i, 2, MAX) {\n            _fact[i] = _fact[i - 1] * (Mint)i;\n\
    \        }\n        _factinv[MAX - 1] = (Mint)1 / _fact[MAX - 1];\n        rep(i,\
    \ MAX - 2, -1, -1) {\n            _factinv[i] = _factinv[i + 1] * (Mint)(i + 1);\n\
    \        }\n        rep(i, MAX - 1, 0, -1) {\n            inv[i] = _factinv[i]\
    \ * _fact[i - 1];\n        }\n    }\n\n    // \u6E96\u5099O(N)\u3001\u64CD\u4F5C\
    O(1)\u3067log\u304C\u4E57\u3089\u306A\u3044mod\u9664\u7B97\n    Mint div(Mint\
    \ a, int b) {\n        return a * inv[b];\n    }\n\n    Mint fact(int x) {\n \
    \       assert(x < MAX);\n        return _fact[x];\n    }\n\n    Mint factinv(int\
    \ x) {\n        assert(x < MAX);\n        return _factinv[x];\n    }\n\n    Mint\
    \ nCr(int n, int r) {\n        if (n < r or r < 0) return 0;\n        r = min(r,\
    \ n - r);\n        Mint num = _fact[n];\n        Mint den = _factinv[r] * _factinv[n\
    \ - r];\n        return num * den;\n    }\n\n    Mint nHr(int n, int r) {\n  \
    \      assert(r + n - 1 < MAX);\n        return nCr(r + n - 1, r);\n    }\n\n\
    \    Mint nPr(int n, int r) {\n        if (n < r or r < 0) return 0;\n       \
    \ return _fact[n] * _factinv[n - r];\n    }\n\n    // \u4E8C\u91CD\u968E\u4E57\
    \n    // \u53C2\u8003\uFF1Ahttps://ja.wikipedia.org/wiki/%E4%BA%8C%E9%87%8D%E9%9A%8E%E4%B9%97\n\
    \    Mint double_factorial(int n) {\n        if (n % 2 == 0) {\n            int\
    \ k = n / 2;\n            return Mint(2).pow(k) * fact(k);\n        } else {\n\
    \            int k = (n + 1) / 2;\n            return fact(2 * k) / Mint(2).pow(k)\
    \ / fact(k);\n        }\n    }\n};\n#line 4 \"src/math/lagrange_polynomial.hpp\"\
    \n\n// \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\uFF1A\u5024\u3092\u6C42\
    \u3081\u308B\n// \u53C2\u8003\uFF1Ahttps://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93\n\
    // \u3000\u3000\u3000https://ei1333.github.io/library/math/combinatorics/lagrange-polynomial.cpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u5F15\u6570\uFF1Ax=0,1,2...\u306E\u6642\u306E\
    y\u3092\u683C\u7D0D\u3057\u305F\u30EA\u30B9\u30C8(N\u6B21\u5F0F\u306A\u3089\u9577\
    \u3055N+1)\u3068\u3001\u6C42\u3081\u305F\u3044f(t)\u306Et\n// \u30FB\u623B\u308A\
    \u5024\uFF1Af(t)\u306E\u6642\u306E\u5024\n// \u30FB\u8A08\u7B97\u91CF\uFF1AO(Nlog(mod))\
    \ \u203B\u968E\u4E57\u9006\u5143\u3092\u3061\u3083\u3093\u3068\u524D\u8A08\u7B97\
    \u3057\u3066\u308C\u3070O(N)\u3063\u307D\u3044\u3002\ntemplate<typename T>\nT\
    \ lagrange_polynomial(const vector<T> &y, int64_t t) {\n    int N = y.size() -\
    \ 1;\n    ModTools<T> mt(N);\n    if (t <= N) return y[t];\n    T ret(0);\n  \
    \  vector<T> dp(N + 1, 1), pd(N + 1, 1);\n    for (int i = 0; i < N; i++) dp[i\
    \ + 1] = dp[i] * (t - i);\n    for (int i = N; i > 0; i--) pd[i - 1] = pd[i] *\
    \ (t - i);\n    for (int i = 0; i <= N; i++) {\n        T tmp = y[i] * dp[i] *\
    \ pd[i] * mt.factinv[i] * mt.factinv[N - i];\n        if ((N - i) & 1) ret -=\
    \ tmp;\n        else ret += tmp;\n    }\n    return ret;\n}\n\n// \u30E9\u30B0\
    \u30E9\u30F3\u30B8\u30E5\u88DC\u9593\uFF1A\u4FC2\u6570\u3092\u6C42\u3081\u308B\
    \n// \u53C2\u8003\uFF1Ahttps://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93\n\
    // \u3000\u3000\u3000https://ei1333.github.io/library/math/combinatorics/lagrange-polynomial-2.cpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u5F15\u6570\uFF1Ay=f(x)\u306E(x,y)\u306E\u30DA\
    \u30A2\u3092\u683C\u7D0D\u3057\u305F\u30EA\u30B9\u30C8X,Y\n// \u30FB\u623B\u308A\
    \u5024\uFF1Af(x)=ax^0+bx^1+cx^2+...\u306Ea,b,c...\u3092\u683C\u7D0D\u3057\u305F\
    \u30EA\u30B9\u30C8\n// \u30FB\u8A08\u7B97\u91CF\uFF1AO(N^2)\ntemplate<typename\
    \ T>\nvector<T> lagrange_polynomial(const vector<T> &x, const vector<T> &y) {\n\
    \    int k = (int)x.size() - 1;\n\n    vector<T> f(k + 1), dp(k + 2);\n    dp[0]\
    \ = 1;\n    for (int j = 0; j <= k; j++) {\n        for (int l = k + 1; l > 0;\
    \ l--) {\n            dp[l] = dp[l] * -x[j] + dp[l - 1];\n        }\n        dp[0]\
    \ *= -x[j];\n    }\n\n    for (int i = 0; i <= k; i++) {\n        T d = 1;\n \
    \       for (int j = 0; j <= k; j++) {\n            if (i != j) {\n          \
    \      d *= x[i] - x[j];\n            }\n        }\n        T mul = y[i] / d;\n\
    \        if (x[i] == 0) {\n            for (int j = 0; j <= k; j++) {\n      \
    \          f[j] += dp[j + 1] * mul;\n            }\n        } else {\n       \
    \     T inv = T(1) / (-x[i]), pre = 0;\n            for (int j = 0; j <= k; j++)\
    \ {\n                T cur = (dp[j] - pre) * inv;\n                f[j] += cur\
    \ * mul;\n                pre = cur;\n            }\n        }\n    }\n    return\
    \ f;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../combinatorics/ModTools.hpp\"\
    \n\n// \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\uFF1A\u5024\u3092\u6C42\
    \u3081\u308B\n// \u53C2\u8003\uFF1Ahttps://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93\n\
    // \u3000\u3000\u3000https://ei1333.github.io/library/math/combinatorics/lagrange-polynomial.cpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u5F15\u6570\uFF1Ax=0,1,2...\u306E\u6642\u306E\
    y\u3092\u683C\u7D0D\u3057\u305F\u30EA\u30B9\u30C8(N\u6B21\u5F0F\u306A\u3089\u9577\
    \u3055N+1)\u3068\u3001\u6C42\u3081\u305F\u3044f(t)\u306Et\n// \u30FB\u623B\u308A\
    \u5024\uFF1Af(t)\u306E\u6642\u306E\u5024\n// \u30FB\u8A08\u7B97\u91CF\uFF1AO(Nlog(mod))\
    \ \u203B\u968E\u4E57\u9006\u5143\u3092\u3061\u3083\u3093\u3068\u524D\u8A08\u7B97\
    \u3057\u3066\u308C\u3070O(N)\u3063\u307D\u3044\u3002\ntemplate<typename T>\nT\
    \ lagrange_polynomial(const vector<T> &y, int64_t t) {\n    int N = y.size() -\
    \ 1;\n    ModTools<T> mt(N);\n    if (t <= N) return y[t];\n    T ret(0);\n  \
    \  vector<T> dp(N + 1, 1), pd(N + 1, 1);\n    for (int i = 0; i < N; i++) dp[i\
    \ + 1] = dp[i] * (t - i);\n    for (int i = N; i > 0; i--) pd[i - 1] = pd[i] *\
    \ (t - i);\n    for (int i = 0; i <= N; i++) {\n        T tmp = y[i] * dp[i] *\
    \ pd[i] * mt.factinv[i] * mt.factinv[N - i];\n        if ((N - i) & 1) ret -=\
    \ tmp;\n        else ret += tmp;\n    }\n    return ret;\n}\n\n// \u30E9\u30B0\
    \u30E9\u30F3\u30B8\u30E5\u88DC\u9593\uFF1A\u4FC2\u6570\u3092\u6C42\u3081\u308B\
    \n// \u53C2\u8003\uFF1Ahttps://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93\n\
    // \u3000\u3000\u3000https://ei1333.github.io/library/math/combinatorics/lagrange-polynomial-2.cpp\n\
    // \u4F7F\u3044\u65B9\n// \u30FB\u5F15\u6570\uFF1Ay=f(x)\u306E(x,y)\u306E\u30DA\
    \u30A2\u3092\u683C\u7D0D\u3057\u305F\u30EA\u30B9\u30C8X,Y\n// \u30FB\u623B\u308A\
    \u5024\uFF1Af(x)=ax^0+bx^1+cx^2+...\u306Ea,b,c...\u3092\u683C\u7D0D\u3057\u305F\
    \u30EA\u30B9\u30C8\n// \u30FB\u8A08\u7B97\u91CF\uFF1AO(N^2)\ntemplate<typename\
    \ T>\nvector<T> lagrange_polynomial(const vector<T> &x, const vector<T> &y) {\n\
    \    int k = (int)x.size() - 1;\n\n    vector<T> f(k + 1), dp(k + 2);\n    dp[0]\
    \ = 1;\n    for (int j = 0; j <= k; j++) {\n        for (int l = k + 1; l > 0;\
    \ l--) {\n            dp[l] = dp[l] * -x[j] + dp[l - 1];\n        }\n        dp[0]\
    \ *= -x[j];\n    }\n\n    for (int i = 0; i <= k; i++) {\n        T d = 1;\n \
    \       for (int j = 0; j <= k; j++) {\n            if (i != j) {\n          \
    \      d *= x[i] - x[j];\n            }\n        }\n        T mul = y[i] / d;\n\
    \        if (x[i] == 0) {\n            for (int j = 0; j <= k; j++) {\n      \
    \          f[j] += dp[j + 1] * mul;\n            }\n        } else {\n       \
    \     T inv = T(1) / (-x[i]), pre = 0;\n            for (int j = 0; j <= k; j++)\
    \ {\n                T cur = (dp[j] - pre) * inv;\n                f[j] += cur\
    \ * mul;\n                pre = cur;\n            }\n        }\n    }\n    return\
    \ f;\n}\n"
  dependsOn:
  - src/base.hpp
  - src/combinatorics/ModTools.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/math/lagrange_polynomial.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/lagrange_polynomial.hpp
layout: document
redirect_from:
- /library/src/math/lagrange_polynomial.hpp
- /library/src/math/lagrange_polynomial.hpp.html
title: src/math/lagrange_polynomial.hpp
---
