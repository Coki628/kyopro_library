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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 2 \"src/datastructure/DynamicLiChaoTree.hpp\"\
    \n\n// Li Chao Tree\ntemplate<typename T>\nstruct DynamicLiChaoTree {\n\n    const\
    \ ll x_low;\n    const ll x_high;\n    const T id;\n    const bool is_min;\n\n\
    \    struct Line {\n        T a, b;\n\n        Line(T a, T b) : a(a), b(b) {}\n\
    \n        inline T get(ll x) const { return a * x + b; }\n    };\n\n    struct\
    \ Node {\n        Line x;\n        Node *l, *r;\n\n        Node(const Line &x)\
    \ : x{x}, l{nullptr}, r{nullptr} {}\n    };\n\n    Node *root;\n\n    // x_low,x_high\u306F\
    (\u591A\u5206)\u534A\u958B\u533A\u9593[x_low,x_high)\u3042\u308C\u3070\u5927\u4E08\
    \u592B\u3002\n    // \u5358\u4F4D\u5143id\u306F\u5E38\u306B(max\u7528\u3067\u3082\
    )INF\u3067\u3088\u3055\u305D\u3046\u3002x_high\u306Fid\u3088\u308A\u5C0F\u3055\
    \u304F\u3057\u305F\u65B9\u304C\u3088\u3055\u305D\u3046\u3002\n    DynamicLiChaoTree(ll\
    \ x_low, ll x_high, T id, bool is_min=true) : root{nullptr}, x_low(x_low), x_high(x_high),\
    \ id(id), is_min(is_min) {}\n\n    Node *add_line(Node *t, Line &x, const ll &l,\
    \ const ll &r, const T &x_l, const T &x_r) {\n        if(!t) return new Node(x);\n\
    \n        T t_l = t->x.get(l), t_r = t->x.get(r);\n\n        if(t_l <= x_l &&\
    \ t_r <= x_r) {\n            return t;\n        } else if(t_l >= x_l && t_r >=\
    \ x_r) {\n        t->x = x;\n            return t;\n        } else {\n       \
    \     ll m = (l + r) / 2;\n            if(m == r) --m;\n            T t_m = t->x.get(m),\
    \ x_m = x.get(m);\n            if(t_m > x_m) {\n                swap(t->x, x);\n\
    \                if(x_l >= t_l) t->l = add_line(t->l, x, l, m, t_l, t_m);\n  \
    \              else t->r = add_line(t->r, x, m + 1, r, t_m + x.a, t_r);\n    \
    \        } else {\n                if(t_l >= x_l) t->l = add_line(t->l, x, l,\
    \ m, x_l, x_m);\n                else t->r = add_line(t->r, x, m + 1, r, x_m +\
    \ x.a, x_r);\n            }\n            return t;\n        }\n    }\n\n    void\
    \ add_line(T a, T b) {\n        if (!is_min) a *= -1, b *= -1;\n        Line x(a,\
    \ b);\n        root = add_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));\n\
    \    }\n\n    Node *add_segment(Node *t, Line &x, const ll &a, const ll &b, const\
    \ ll &l, const ll &r, const T &x_l, const T &x_r) {\n        if(r < a || b < l)\
    \ return t;\n        if(a <= l && r <= b) {\n            Line y{x};\n        \
    \    return add_line(t, y, l, r, x_l, x_r);\n        }\n        if(t) {\n    \
    \        T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l &&\
    \ t_r <= x_r) return t;\n        } else {\n            t = new Node(Line(0, id));\n\
    \        }\n        ll m = (l + r) / 2;\n        if(m == r) --m;\n        T x_m\
    \ = x.get(m);\n        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);\n  \
    \      t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n        return\
    \ t;\n    }\n\n    void add_segment(const ll &l, const ll &r, T a, T b) {\n  \
    \      if (!is_min) a *= -1, b *= -1;\n        Line x(a, b);\n        root = add_segment(root,\
    \ x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));\n    }\n\n    T query(const\
    \ Node *t, const ll &l, const ll &r, const T &x) const {\n        if(!t) return\
    \ id;\n        if(l == r) return t->x.get(x);\n        ll m = (l + r) / 2;\n \
    \       if(m == r) --m;\n        if(x <= m) return min(t->x.get(x), query(t->l,\
    \ l, m, x));\n        else return min(t->x.get(x), query(t->r, m + 1, r, x));\n\
    \    }\n\n    T query(const T &x) const {\n        if (is_min) return query(root,\
    \ x_low, x_high, x);\n        return -query(root, x_low, x_high, x);\n    }\n\
    };\n"
  code: "#include \"../macros.hpp\"\n\n// Li Chao Tree\ntemplate<typename T>\nstruct\
    \ DynamicLiChaoTree {\n\n    const ll x_low;\n    const ll x_high;\n    const\
    \ T id;\n    const bool is_min;\n\n    struct Line {\n        T a, b;\n\n    \
    \    Line(T a, T b) : a(a), b(b) {}\n\n        inline T get(ll x) const { return\
    \ a * x + b; }\n    };\n\n    struct Node {\n        Line x;\n        Node *l,\
    \ *r;\n\n        Node(const Line &x) : x{x}, l{nullptr}, r{nullptr} {}\n    };\n\
    \n    Node *root;\n\n    // x_low,x_high\u306F(\u591A\u5206)\u534A\u958B\u533A\
    \u9593[x_low,x_high)\u3042\u308C\u3070\u5927\u4E08\u592B\u3002\n    // \u5358\u4F4D\
    \u5143id\u306F\u5E38\u306B(max\u7528\u3067\u3082)INF\u3067\u3088\u3055\u305D\u3046\
    \u3002x_high\u306Fid\u3088\u308A\u5C0F\u3055\u304F\u3057\u305F\u65B9\u304C\u3088\
    \u3055\u305D\u3046\u3002\n    DynamicLiChaoTree(ll x_low, ll x_high, T id, bool\
    \ is_min=true) : root{nullptr}, x_low(x_low), x_high(x_high), id(id), is_min(is_min)\
    \ {}\n\n    Node *add_line(Node *t, Line &x, const ll &l, const ll &r, const T\
    \ &x_l, const T &x_r) {\n        if(!t) return new Node(x);\n\n        T t_l =\
    \ t->x.get(l), t_r = t->x.get(r);\n\n        if(t_l <= x_l && t_r <= x_r) {\n\
    \            return t;\n        } else if(t_l >= x_l && t_r >= x_r) {\n      \
    \  t->x = x;\n            return t;\n        } else {\n            ll m = (l +\
    \ r) / 2;\n            if(m == r) --m;\n            T t_m = t->x.get(m), x_m =\
    \ x.get(m);\n            if(t_m > x_m) {\n                swap(t->x, x);\n   \
    \             if(x_l >= t_l) t->l = add_line(t->l, x, l, m, t_l, t_m);\n     \
    \           else t->r = add_line(t->r, x, m + 1, r, t_m + x.a, t_r);\n       \
    \     } else {\n                if(t_l >= x_l) t->l = add_line(t->l, x, l, m,\
    \ x_l, x_m);\n                else t->r = add_line(t->r, x, m + 1, r, x_m + x.a,\
    \ x_r);\n            }\n            return t;\n        }\n    }\n\n    void add_line(T\
    \ a, T b) {\n        if (!is_min) a *= -1, b *= -1;\n        Line x(a, b);\n \
    \       root = add_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));\n\
    \    }\n\n    Node *add_segment(Node *t, Line &x, const ll &a, const ll &b, const\
    \ ll &l, const ll &r, const T &x_l, const T &x_r) {\n        if(r < a || b < l)\
    \ return t;\n        if(a <= l && r <= b) {\n            Line y{x};\n        \
    \    return add_line(t, y, l, r, x_l, x_r);\n        }\n        if(t) {\n    \
    \        T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l &&\
    \ t_r <= x_r) return t;\n        } else {\n            t = new Node(Line(0, id));\n\
    \        }\n        ll m = (l + r) / 2;\n        if(m == r) --m;\n        T x_m\
    \ = x.get(m);\n        t->l = add_segment(t->l, x, a, b, l, m, x_l, x_m);\n  \
    \      t->r = add_segment(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n        return\
    \ t;\n    }\n\n    void add_segment(const ll &l, const ll &r, T a, T b) {\n  \
    \      if (!is_min) a *= -1, b *= -1;\n        Line x(a, b);\n        root = add_segment(root,\
    \ x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));\n    }\n\n    T query(const\
    \ Node *t, const ll &l, const ll &r, const T &x) const {\n        if(!t) return\
    \ id;\n        if(l == r) return t->x.get(x);\n        ll m = (l + r) / 2;\n \
    \       if(m == r) --m;\n        if(x <= m) return min(t->x.get(x), query(t->l,\
    \ l, m, x));\n        else return min(t->x.get(x), query(t->r, m + 1, r, x));\n\
    \    }\n\n    T query(const T &x) const {\n        if (is_min) return query(root,\
    \ x_low, x_high, x);\n        return -query(root, x_low, x_high, x);\n    }\n\
    };\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/DynamicLiChaoTree.hpp
  requiredBy: []
  timestamp: '2023-07-05 11:04:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/DynamicLiChaoTree.hpp
layout: document
redirect_from:
- /library/src/datastructure/DynamicLiChaoTree.hpp
- /library/src/datastructure/DynamicLiChaoTree.hpp.html
title: src/datastructure/DynamicLiChaoTree.hpp
---
