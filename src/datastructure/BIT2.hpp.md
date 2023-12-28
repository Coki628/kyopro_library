---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/BIT2.hpp\"\
    \n\n// \u533A\u9593\u52A0\u7B97BIT(\u533A\u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\
    \u53D6\u5F97)\ntemplate<typename T>\nstruct BIT2 {\n    int N;\n    vector<T>\
    \ data0, data1;\n\n    BIT2(){};\n\n    BIT2(int N) {\n        resize(N);\n  \
    \  }\n\n    void resize(int n) {\n        // \u6DFB\u5B570\u304C\u4F7F\u3048\u306A\
    \u3044\u306E\u3067\u3001\u5185\u90E8\u7684\u306B\u306F\u5168\u30661-indexed\u3068\
    \u3057\u3066\u6271\u3046\n        N = ++n;\n        data0.resize(N);\n       \
    \ data1.resize(N);\n    }\n\n    void _add(vector<T> &data, int k, T x) {\n  \
    \      k++;\n        while (k < N) {\n            data[k] += x;\n            k\
    \ += k & -k;\n        }\n    }\n\n    T _get(vector<T> &data, int k) {\n     \
    \   k++;\n        T s = 0;\n        while (k) {\n            s += data[k];\n \
    \           k -= k & -k;\n        }\n        return s;\n    }\n\n    // \u533A\
    \u9593[l,r)\u306B\u5024x\u3092\u52A0\u7B97\n    void add(int l, int r, T x) {\n\
    \        _add(data0, l, -x * (l - 1));\n        _add(data0, r, x * (r - 1));\n\
    \        _add(data1, l, x);\n        _add(data1, r, -x);\n    }\n\n    // 1\u70B9\
    \u52A0\u7B97\n    void add(int i, T x) {\n        add(i, i + 1, x);\n    }\n\n\
    \    // \u533A\u9593[l,r)\u306E\u548C\u3092\u53D6\u5F97\n    T query(int l, int\
    \ r) {\n        return _get(data1, r - 1) * (r - 1) + _get(data0, r - 1) -\n \
    \              _get(data1, l - 1) * (l - 1) - _get(data0, l - 1);\n    }\n\n \
    \   // 1\u70B9\u53D6\u5F97\n    T get(int i) {\n        return query(i, i + 1);\n\
    \    }\n\n    // 1\u70B9\u66F4\u65B0\n    void update(int i, T x) {\n        add(i,\
    \ i + 1, x - get(i));\n    }\n\n    T operator[](int i) {\n        return query(i,\
    \ i + 1);\n    }\n\n    void print(int n) {\n        rep(i, n) {\n           \
    \ cout << query(i, i + 1);\n            if (i == n - 1) cout << endl;\n      \
    \      else cout << ' ';\n        }\n    }\n\n    // \u533A\u9593[l, r]\u3092\u5DE6\
    \u304B\u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\
    \u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l, int r, ll x) {\n       \
    \ if (l > r) return -1;\n        ll l_sm = query(0, l);\n        int ok = r +\
    \ 1;\n        int ng = l - 1;\n        while (ng + 1 < ok) {\n            int\
    \ mid = (ok + ng) / 2;\n            if (query(0, mid + 1) - l_sm >= x) {\n   \
    \             ok = mid;\n            } else {\n                ng = mid;\n   \
    \         }\n        }\n        if (ok != r + 1) {\n            return ok;\n \
    \       } else {\n            return -1;\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll r_sm = query(0, r + 1);\n\
    \        int ok = l - 1;\n        int ng = r + 1;\n        while (ok + 1 < ng)\
    \ {\n            int mid = (ok + ng) / 2;\n            if (r_sm - query(0, mid)\
    \ >= x) {\n                ok = mid;\n            } else {\n                ng\
    \ = mid;\n            }\n        }\n        if (ok != l - 1) {\n            return\
    \ ok;\n        } else {\n            return -1;\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// \u533A\u9593\u52A0\u7B97BIT(\u533A\
    \u9593\u52A0\u7B97\u30FB\u533A\u9593\u548C\u53D6\u5F97)\ntemplate<typename T>\n\
    struct BIT2 {\n    int N;\n    vector<T> data0, data1;\n\n    BIT2(){};\n\n  \
    \  BIT2(int N) {\n        resize(N);\n    }\n\n    void resize(int n) {\n    \
    \    // \u6DFB\u5B570\u304C\u4F7F\u3048\u306A\u3044\u306E\u3067\u3001\u5185\u90E8\
    \u7684\u306B\u306F\u5168\u30661-indexed\u3068\u3057\u3066\u6271\u3046\n      \
    \  N = ++n;\n        data0.resize(N);\n        data1.resize(N);\n    }\n\n   \
    \ void _add(vector<T> &data, int k, T x) {\n        k++;\n        while (k < N)\
    \ {\n            data[k] += x;\n            k += k & -k;\n        }\n    }\n\n\
    \    T _get(vector<T> &data, int k) {\n        k++;\n        T s = 0;\n      \
    \  while (k) {\n            s += data[k];\n            k -= k & -k;\n        }\n\
    \        return s;\n    }\n\n    // \u533A\u9593[l,r)\u306B\u5024x\u3092\u52A0\
    \u7B97\n    void add(int l, int r, T x) {\n        _add(data0, l, -x * (l - 1));\n\
    \        _add(data0, r, x * (r - 1));\n        _add(data1, l, x);\n        _add(data1,\
    \ r, -x);\n    }\n\n    // 1\u70B9\u52A0\u7B97\n    void add(int i, T x) {\n \
    \       add(i, i + 1, x);\n    }\n\n    // \u533A\u9593[l,r)\u306E\u548C\u3092\
    \u53D6\u5F97\n    T query(int l, int r) {\n        return _get(data1, r - 1) *\
    \ (r - 1) + _get(data0, r - 1) -\n               _get(data1, l - 1) * (l - 1)\
    \ - _get(data0, l - 1);\n    }\n\n    // 1\u70B9\u53D6\u5F97\n    T get(int i)\
    \ {\n        return query(i, i + 1);\n    }\n\n    // 1\u70B9\u66F4\u65B0\n  \
    \  void update(int i, T x) {\n        add(i, i + 1, x - get(i));\n    }\n\n  \
    \  T operator[](int i) {\n        return query(i, i + 1);\n    }\n\n    void print(int\
    \ n) {\n        rep(i, n) {\n            cout << query(i, i + 1);\n          \
    \  if (i == n - 1) cout << endl;\n            else cout << ' ';\n        }\n \
    \   }\n\n    // \u533A\u9593[l, r]\u3092\u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\
    \u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int\
    \ l, int r, ll x) {\n        if (l > r) return -1;\n        ll l_sm = query(0,\
    \ l);\n        int ok = r + 1;\n        int ng = l - 1;\n        while (ng + 1\
    \ < ok) {\n            int mid = (ok + ng) / 2;\n            if (query(0, mid\
    \ + 1) - l_sm >= x) {\n                ok = mid;\n            } else {\n     \
    \           ng = mid;\n            }\n        }\n        if (ok != r + 1) {\n\
    \            return ok;\n        } else {\n            return -1;\n        }\n\
    \    }\n\n    // \u533A\u9593[l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\
    \u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int\
    \ l, int r, ll x) {\n        if (l > r) return -1;\n        ll r_sm = query(0,\
    \ r + 1);\n        int ok = l - 1;\n        int ng = r + 1;\n        while (ok\
    \ + 1 < ng) {\n            int mid = (ok + ng) / 2;\n            if (r_sm - query(0,\
    \ mid) >= x) {\n                ok = mid;\n            } else {\n            \
    \    ng = mid;\n            }\n        }\n        if (ok != l - 1) {\n       \
    \     return ok;\n        } else {\n            return -1;\n        }\n    }\n\
    };\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/BIT2.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/BIT2.hpp
layout: document
redirect_from:
- /library/src/datastructure/BIT2.hpp
- /library/src/datastructure/BIT2.hpp.html
title: src/datastructure/BIT2.hpp
---
