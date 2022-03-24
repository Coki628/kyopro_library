---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/common/bisect.test.cpp
    title: test/common/bisect.test.cpp
  - icon: ':x:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
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
    src/segment/BIT.hpp\"\n\n// Binary Indexed Tree\ntemplate<typename T>\nstruct\
    \ BIT {\n\n    int sz;\n    vector<T> tree;\n\n    BIT(int n) {\n        // 0-indexed\n\
    \        n++;\n        sz = 1;\n        while (sz < n) {\n            sz *= 2;\n\
    \        }\n        tree.resize(sz);\n    }\n\n    // [0, i]\u3092\u5408\u8A08\
    \u3059\u308B\n    T sum(int i) {\n        T s = 0;\n        i++;\n        while\
    \ (i > 0) {\n            s += tree[i-1];\n            i -= i & -i;\n        }\n\
    \        return s;\n    }\n\n    void add(int i, T x) {\n        i++;\n      \
    \  while (i <= sz) {\n            tree[i-1] += x;\n            i += i & -i;\n\
    \        }\n    }\n\n    // \u533A\u9593\u548C\u306E\u53D6\u5F97 [l, r)\n    T\
    \ query(int l, int r) {\n        return sum(r-1) - sum(l-1);\n    }\n\n    T get(int\
    \ i) {\n        return query(i, i+1);\n    }\n\n    void update(int i, T x) {\n\
    \        add(i, x - get(i));\n    }\n\n    T operator[](int i) {\n        return\
    \ query(i, i+1);\n    }\n\n    void print(int n) {\n        rep(i, n) {\n    \
    \        cout << query(i, i+1);\n            if (i == n-1) cout << endl;\n   \
    \         else cout << ' ';\n        }\n    }\n\n    // \u533A\u9593[l, r]\u3092\
    \u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\
    \u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l, int r, ll x) {\n \
    \       if (l > r) return -1;\n        ll l_sm = sum(l-1);\n        int ok = r\
    \ + 1;\n        int ng = l - 1;\n        while (ng+1 < ok) {\n            int\
    \ mid = (ok+ng) / 2;\n            if (sum(mid) - l_sm >= x) {\n              \
    \  ok = mid;\n            } else {\n                ng = mid;\n            }\n\
    \        }\n        if (ok != r+1) {\n            return ok;\n        } else {\n\
    \            return -1;\n        }\n    }\n\n    // \u533A\u9593[l, r]\u3092\u53F3\
    \u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\
    \u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int l, int r, ll x) {\n       \
    \ if (l > r) return -1;\n        ll r_sm = sum(r);\n        int ok = l - 1;\n\
    \        int ng = r + 1;\n        while (ok+1 < ng) {\n            int mid = (ok+ng)\
    \ / 2;\n            if (r_sm - sum(mid-1) >= x) {\n                ok = mid;\n\
    \            } else {\n                ng = mid;\n            }\n        }\n \
    \       if (ok != l-1) {\n            return ok;\n        } else {\n         \
    \   return -1;\n        }\n    }\n};\n"
  code: "#include \"../macros.hpp\"\n\n// Binary Indexed Tree\ntemplate<typename T>\n\
    struct BIT {\n\n    int sz;\n    vector<T> tree;\n\n    BIT(int n) {\n       \
    \ // 0-indexed\n        n++;\n        sz = 1;\n        while (sz < n) {\n    \
    \        sz *= 2;\n        }\n        tree.resize(sz);\n    }\n\n    // [0, i]\u3092\
    \u5408\u8A08\u3059\u308B\n    T sum(int i) {\n        T s = 0;\n        i++;\n\
    \        while (i > 0) {\n            s += tree[i-1];\n            i -= i & -i;\n\
    \        }\n        return s;\n    }\n\n    void add(int i, T x) {\n        i++;\n\
    \        while (i <= sz) {\n            tree[i-1] += x;\n            i += i &\
    \ -i;\n        }\n    }\n\n    // \u533A\u9593\u548C\u306E\u53D6\u5F97 [l, r)\n\
    \    T query(int l, int r) {\n        return sum(r-1) - sum(l-1);\n    }\n\n \
    \   T get(int i) {\n        return query(i, i+1);\n    }\n\n    void update(int\
    \ i, T x) {\n        add(i, x - get(i));\n    }\n\n    T operator[](int i) {\n\
    \        return query(i, i+1);\n    }\n\n    void print(int n) {\n        rep(i,\
    \ n) {\n            cout << query(i, i+1);\n            if (i == n-1) cout <<\
    \ endl;\n            else cout << ' ';\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u5DE6\u304B\u3089\u53F3\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_fore(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll l_sm = sum(l-1);\n      \
    \  int ok = r + 1;\n        int ng = l - 1;\n        while (ng+1 < ok) {\n   \
    \         int mid = (ok+ng) / 2;\n            if (sum(mid) - l_sm >= x) {\n  \
    \              ok = mid;\n            } else {\n                ng = mid;\n  \
    \          }\n        }\n        if (ok != r+1) {\n            return ok;\n  \
    \      } else {\n            return -1;\n        }\n    }\n\n    // \u533A\u9593\
    [l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\
    \u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n    ll bisearch_back(int l, int r,\
    \ ll x) {\n        if (l > r) return -1;\n        ll r_sm = sum(r);\n        int\
    \ ok = l - 1;\n        int ng = r + 1;\n        while (ok+1 < ng) {\n        \
    \    int mid = (ok+ng) / 2;\n            if (r_sm - sum(mid-1) >= x) {\n     \
    \           ok = mid;\n            } else {\n                ng = mid;\n     \
    \       }\n        }\n        if (ok != l-1) {\n            return ok;\n     \
    \   } else {\n            return -1;\n        }\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/segment/BIT.hpp
  requiredBy:
  - src/template.hpp
  timestamp: '2022-03-24 10:49:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/common/bisect.test.cpp
  - test/graph/bfs.test.cpp
documentation_of: src/segment/BIT.hpp
layout: document
redirect_from:
- /library/src/segment/BIT.hpp
- /library/src/segment/BIT.hpp.html
title: src/segment/BIT.hpp
---
