---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/datastructure/Imos.hpp
    title: src/datastructure/Imos.hpp
  - icon: ':warning:'
    path: src/template.hpp
    title: src/template.hpp
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
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\ntemplate<typename T>\nusing vv = vector<vector<T>>;\n\
    #define name4(i, a, b, c, d, e, ...) e\n#define rep(...) name4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a) for (ll i = 0, _aa = a; i\
    \ < _aa; i++)\n#define rep2(i, a, b) for (ll i = a, _bb = b; i < _bb; i++)\n#define\
    \ rep3(i, a, b, c) for (ll i = a, _bb = b; (c > 0 && a <= i && i < _bb) or (c\
    \ < 0 && a >= i && i > _bb); i += c)\n#define rrep(i, a, b) for (ll i=(a); i>(b);\
    \ i--)\n#define pb push_back\n#define eb emplace_back\n#define mkp make_pair\n\
    #define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)), A.erase(unique(ALL(A)),\
    \ A.end())\n#define elif else if\n#define tostr to_string\n\n#ifndef CONSTANTS\n\
    \    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n    constexpr\
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/Accumulate.hpp\"\
    \n\n// \u7D2F\u7A4D\u548C\ntemplate<typename T>\nstruct Accumulate {\n    vector<T>\
    \ dat;\n    int N;\n    bool built = false;\n\n    Accumulate(int N) : N(N) {\n\
    \        dat.resize(N);\n    }\n\n    Accumulate(const vector<T> &A) : N(A.size()),\
    \ dat(A) {\n        build();\n    }\n\n    void set(int i, T a) {\n        dat[i]\
    \ = a;\n    }\n\n    void add(int i, T a) {\n        dat[i] += a;\n    }\n\n \
    \   void build() {\n        rep(i, N-1) {\n            dat[i+1] += dat[i];\n \
    \       }\n        dat.insert(dat.begin(), 0);\n        built = true;\n    }\n\
    \n    virtual T query(int l, int r) {\n        assert(built);\n        assert(0\
    \ <= l and l <= N and 0 <= r and r <= N);\n        return dat[r] - dat[l];\n \
    \   }\n\n    T get(int i) {\n        return query(i, i+1);\n    }\n\n    T operator[](int\
    \ i) {\n        return query(i, i+1);\n    }\n\n    // \u533A\u9593[l, r]\u3092\
    \u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\
    \u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l, int r, ll x) {\n \
    \       if (l > r) return -1;\n        ll l_sm = query(0, l);\n        int ok\
    \ = r + 1;\n        int ng = l - 1;\n        while (ng+1 < ok) {\n           \
    \ int mid = (ok+ng) / 2;\n            if (query(0, mid+1) - l_sm >= x) {\n   \
    \             ok = mid;\n            } else {\n                ng = mid;\n   \
    \         }\n        }\n        if (ok != r+1) {\n            return ok;\n   \
    \     } else {\n            return -1;\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll r_sm = query(0, r+1);\n \
    \       int ok = l - 1;\n        int ng = r + 1;\n        while (ok+1 < ng) {\n\
    \            int mid = (ok+ng) / 2;\n            if (r_sm - query(0, mid) >= x)\
    \ {\n                ok = mid;\n            } else {\n                ng = mid;\n\
    \            }\n        }\n        if (ok != l-1) {\n            return ok;\n\
    \        } else {\n            return -1;\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u7D2F\u7A4D\u548C\ntemplate<typename\
    \ T>\nstruct Accumulate {\n    vector<T> dat;\n    int N;\n    bool built = false;\n\
    \n    Accumulate(int N) : N(N) {\n        dat.resize(N);\n    }\n\n    Accumulate(const\
    \ vector<T> &A) : N(A.size()), dat(A) {\n        build();\n    }\n\n    void set(int\
    \ i, T a) {\n        dat[i] = a;\n    }\n\n    void add(int i, T a) {\n      \
    \  dat[i] += a;\n    }\n\n    void build() {\n        rep(i, N-1) {\n        \
    \    dat[i+1] += dat[i];\n        }\n        dat.insert(dat.begin(), 0);\n   \
    \     built = true;\n    }\n\n    virtual T query(int l, int r) {\n        assert(built);\n\
    \        assert(0 <= l and l <= N and 0 <= r and r <= N);\n        return dat[r]\
    \ - dat[l];\n    }\n\n    T get(int i) {\n        return query(i, i+1);\n    }\n\
    \n    T operator[](int i) {\n        return query(i, i+1);\n    }\n\n    // \u533A\
    \u9593[l, r]\u3092\u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\
    \u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l,\
    \ int r, ll x) {\n        if (l > r) return -1;\n        ll l_sm = query(0, l);\n\
    \        int ok = r + 1;\n        int ng = l - 1;\n        while (ng+1 < ok) {\n\
    \            int mid = (ok+ng) / 2;\n            if (query(0, mid+1) - l_sm >=\
    \ x) {\n                ok = mid;\n            } else {\n                ng =\
    \ mid;\n            }\n        }\n        if (ok != r+1) {\n            return\
    \ ok;\n        } else {\n            return -1;\n        }\n    }\n\n    // \u533A\
    \u9593[l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\
    \u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int l,\
    \ int r, ll x) {\n        if (l > r) return -1;\n        ll r_sm = query(0, r+1);\n\
    \        int ok = l - 1;\n        int ng = r + 1;\n        while (ok+1 < ng) {\n\
    \            int mid = (ok+ng) / 2;\n            if (r_sm - query(0, mid) >= x)\
    \ {\n                ok = mid;\n            } else {\n                ng = mid;\n\
    \            }\n        }\n        if (ok != l-1) {\n            return ok;\n\
    \        } else {\n            return -1;\n        }\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/Accumulate.hpp
  requiredBy:
  - src/datastructure/Imos.hpp
  - src/template.hpp
  timestamp: '2023-02-28 01:25:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/Accumulate.hpp
layout: document
redirect_from:
- /library/src/datastructure/Accumulate.hpp
- /library/src/datastructure/Accumulate.hpp.html
title: src/datastructure/Accumulate.hpp
---
