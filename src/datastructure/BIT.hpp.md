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
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://ei1333.github.io/library/structure/others/binary-indexed-tree.cpp
  bundledCode: "#line 2 \"src/base.hpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll, ll>;\n\
    using pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
    \ ll>;\nusing vvl = vector<vector<ll>>;\nusing vvi = vector<vector<int>>;\nusing\
    \ vvpll = vector<vector<pll>>;\nusing vvpli = vector<vector<pli>>;\nusing vvpil\
    \ = vector<vector<pil>>;\n#define name4(i, a, b, c, d, e, ...) e\n#define rep(...)\
    \ name4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rep1(i, a)\
    \ for (ll i = 0, _aa = a; i < _aa; i++)\n#define rep2(i, a, b) for (ll i = a,\
    \ _bb = b; i < _bb; i++)\n#define rep3(i, a, b, c) for (ll i = a, _bb = b; (c\
    \ > 0 && a <= i && i < _bb) or (c < 0 && a >= i && i > _bb); i += c)\n#define\
    \ rrep(i, a, b) for (ll i=(a); i>(b); i--)\n#define pb push_back\n#define eb emplace_back\n\
    #define mkp make_pair\n#define ALL(A) A.begin(), A.end()\n#define UNIQUE(A) sort(ALL(A)),\
    \ A.erase(unique(ALL(A)), A.end())\n#define elif else if\n#define tostr to_string\n\
    \n#ifndef CONSTANTS\n    constexpr ll INF = 1e18;\n    constexpr int MOD = 1000000007;\n\
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"\
    src/datastructure/BIT.hpp\"\n\n// Binary Indexed Tree\ntemplate<typename T>\n\
    class BIT {\nprivate:\n    int n;\n    vector<T> dat;\n\npublic:\n    BIT() =\
    \  default;\n\n    explicit BIT(int n) : n(n) {\n        dat.assign(n+1, 0);\n\
    \    }\n\n    explicit BIT(const vector<T> &v) : BIT((int)v.size()) {\n      \
    \  build(v);\n    }\n\n    void build(const vector<T> &v) {\n        assert(n\
    \ == (int)v.size());\n        for (int i = 1; i <= n; i++) {\n            dat[i]\
    \ = v[i - 1];\n        }\n        for (int i = 1; i <= n; i++) {\n           \
    \ int j = i + (i & -i);\n            if (j <= n) dat[j] += dat[i];\n        }\n\
    \    }\n\n    // [0, r)\u3092\u5408\u8A08\u3059\u308B\n    T sum(int r) {\n  \
    \      T s = T();\n        for (; r > 0; r -= r & -r) {\n            s += dat[r];\n\
    \        }\n        return s;\n    }\n\n    void add(int k, const T &x) {\n  \
    \      for (++k; k <= n; k += k & -k) {\n            dat[k] += x;\n        }\n\
    \    }\n\n    // \u533A\u9593\u548C\u306E\u53D6\u5F97 [l, r)\n    T query(int\
    \ l, int r) {\n        if (l >= r) return 0;\n        return sum(r) - sum(l);\n\
    \    }\n\n    T get(int i) {\n        return query(i, i+1);\n    }\n\n    void\
    \ update(int i, T x) {\n        add(i, x-get(i));\n    }\n\n    T operator[](int\
    \ i) {\n        return query(i, i+1);\n    }\n\n    void print() {\n        rep(i,\
    \ n) {\n            cout << query(i, i+1);\n            if (i == n-1) cout <<\
    \ endl;\n            else cout << ' ';\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll l_sm = sum(l);\n        int\
    \ ok = r + 1;\n        int ng = l - 1;\n        while (ng+1 < ok) {\n        \
    \    int mid = (ok+ng) / 2;\n            if (sum(mid+1) - l_sm >= x) {\n     \
    \           ok = mid;\n            } else {\n                ng = mid;\n     \
    \       }\n        }\n        if (ok != r+1) {\n            return ok;\n     \
    \   } else {\n            return -1;\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll r_sm = sum(r+1);\n      \
    \  int ok = l - 1;\n        int ng = r + 1;\n        while (ok+1 < ng) {\n   \
    \         int mid = (ok+ng) / 2;\n            if (r_sm - sum(mid) >= x) {\n  \
    \              ok = mid;\n            } else {\n                ng = mid;\n  \
    \          }\n        }\n        if (ok != l-1) {\n            return ok;\n  \
    \      } else {\n            return -1;\n        }\n    }\n\n    // \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/structure/others/binary-indexed-tree.cpp\n\
    \    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u4EE5\u4E0A\u3068\u306A\u308B\
    \u6700\u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\
    \u52A0\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002\n   \
    \ // (log\u304C1\u3064\u306A\u306E\u3067\u3001TL\u53B3\u3057\u3044\u6642\u306F\
    \u3053\u3061\u3089\u3092\u4F7F\u3046\u3002)\n    int lower_bound(T x) const {\n\
    \        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1)\
    \ {\n            if (i + k <= n && dat[i+k] < x) {\n                x -= dat[i+k];\n\
    \                i += k;\n            }\n        }\n        return i;\n    }\n\
    \n    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u3092\u4E0A\u56DE\u308B\u6700\
    \u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\u52A0\
    \u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002(\u672Averify)\n\
    \    int upper_bound(T x) const {\n        int i = 0;\n        for (int k = 1\
    \ << (__lg(n) + 1); k > 0; k >>= 1) {\n            if (i + k <= n && dat[i+k]\
    \ <= x) {\n                x -= dat[i+k];\n                i += k;\n         \
    \   }\n        }\n        return i;\n    }\n};\n"
  code: "#include \"../macros.hpp\"\n\n// Binary Indexed Tree\ntemplate<typename T>\n\
    class BIT {\nprivate:\n    int n;\n    vector<T> dat;\n\npublic:\n    BIT() =\
    \  default;\n\n    explicit BIT(int n) : n(n) {\n        dat.assign(n+1, 0);\n\
    \    }\n\n    explicit BIT(const vector<T> &v) : BIT((int)v.size()) {\n      \
    \  build(v);\n    }\n\n    void build(const vector<T> &v) {\n        assert(n\
    \ == (int)v.size());\n        for (int i = 1; i <= n; i++) {\n            dat[i]\
    \ = v[i - 1];\n        }\n        for (int i = 1; i <= n; i++) {\n           \
    \ int j = i + (i & -i);\n            if (j <= n) dat[j] += dat[i];\n        }\n\
    \    }\n\n    // [0, r)\u3092\u5408\u8A08\u3059\u308B\n    T sum(int r) {\n  \
    \      T s = T();\n        for (; r > 0; r -= r & -r) {\n            s += dat[r];\n\
    \        }\n        return s;\n    }\n\n    void add(int k, const T &x) {\n  \
    \      for (++k; k <= n; k += k & -k) {\n            dat[k] += x;\n        }\n\
    \    }\n\n    // \u533A\u9593\u548C\u306E\u53D6\u5F97 [l, r)\n    T query(int\
    \ l, int r) {\n        if (l >= r) return 0;\n        return sum(r) - sum(l);\n\
    \    }\n\n    T get(int i) {\n        return query(i, i+1);\n    }\n\n    void\
    \ update(int i, T x) {\n        add(i, x-get(i));\n    }\n\n    T operator[](int\
    \ i) {\n        return query(i, i+1);\n    }\n\n    void print() {\n        rep(i,\
    \ n) {\n            cout << query(i, i+1);\n            if (i == n-1) cout <<\
    \ endl;\n            else cout << ' ';\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll l_sm = sum(l);\n        int\
    \ ok = r + 1;\n        int ng = l - 1;\n        while (ng+1 < ok) {\n        \
    \    int mid = (ok+ng) / 2;\n            if (sum(mid+1) - l_sm >= x) {\n     \
    \           ok = mid;\n            } else {\n                ng = mid;\n     \
    \       }\n        }\n        if (ok != r+1) {\n            return ok;\n     \
    \   } else {\n            return -1;\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll r_sm = sum(r+1);\n      \
    \  int ok = l - 1;\n        int ng = r + 1;\n        while (ok+1 < ng) {\n   \
    \         int mid = (ok+ng) / 2;\n            if (r_sm - sum(mid) >= x) {\n  \
    \              ok = mid;\n            } else {\n                ng = mid;\n  \
    \          }\n        }\n        if (ok != l-1) {\n            return ok;\n  \
    \      } else {\n            return -1;\n        }\n    }\n\n    // \u53C2\u8003\
    \uFF1Ahttps://ei1333.github.io/library/structure/others/binary-indexed-tree.cpp\n\
    \    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u4EE5\u4E0A\u3068\u306A\u308B\
    \u6700\u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\
    \u52A0\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002\n   \
    \ // (log\u304C1\u3064\u306A\u306E\u3067\u3001TL\u53B3\u3057\u3044\u6642\u306F\
    \u3053\u3061\u3089\u3092\u4F7F\u3046\u3002)\n    int lower_bound(T x) const {\n\
    \        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1)\
    \ {\n            if (i + k <= n && dat[i+k] < x) {\n                x -= dat[i+k];\n\
    \                i += k;\n            }\n        }\n        return i;\n    }\n\
    \n    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u3092\u4E0A\u56DE\u308B\u6700\
    \u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\u52A0\
    \u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002(\u672Averify)\n\
    \    int upper_bound(T x) const {\n        int i = 0;\n        for (int k = 1\
    \ << (__lg(n) + 1); k > 0; k >>= 1) {\n            if (i + k <= n && dat[i+k]\
    \ <= x) {\n                x -= dat[i+k];\n                i += k;\n         \
    \   }\n        }\n        return i;\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/BIT.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-10-18 16:39:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/BIT.hpp
layout: document
redirect_from:
- /library/src/datastructure/BIT.hpp
- /library/src/datastructure/BIT.hpp.html
title: src/datastructure/BIT.hpp
---
