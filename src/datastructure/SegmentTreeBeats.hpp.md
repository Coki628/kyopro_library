---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':question:'
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"src/datastructure/SegmentTreeBeats.hpp\"\
    \n\n// Segment Tree Beats\nclass SegmentTreeBeats {\n    static const ll inf =\
    \ 1e18;\n    struct Node {\n        Node *left, *right;\n        ll max_v, smax_v,\
    \ max_c;\n        ll min_v, smin_v, min_c;\n        ll sum;\n        ll len, ladd,\
    \ lval;\n\n        Node() : left(0), right(0), ladd(0), lval(inf) {}\n\n     \
    \   void init(ll x) {\n            max_v = min_v = sum = x;\n            smax_v\
    \ = -inf;\n            smin_v = inf;\n            max_c = min_c = 1;\n       \
    \ }\n\n        void init_empty() {\n            max_v = smax_v = -inf;\n     \
    \       min_v = smin_v = inf;\n            max_c = min_c = 0;\n        }\n\n \
    \       void update_max(ll x) {\n            sum += (x - max_v) * max_c;\n\n \
    \           if (max_v == min_v) {\n                max_v = min_v = x;\n      \
    \      } else if (max_v == smin_v) {\n                max_v = smin_v = x;\n  \
    \          } else {\n                max_v = x;\n            }\n\n           \
    \ if (lval != inf && x < lval) {\n                lval = x;\n            }\n \
    \       }\n\n        void update_min(ll x) {\n            sum += (x - min_v) *\
    \ min_c;\n\n            if (max_v == min_v) {\n                max_v = min_v =\
    \ x;\n            } else if (max_v == smin_v) {\n                min_v = smax_v\
    \ = x;\n            } else {\n                min_v = x;\n            }\n\n  \
    \          if (lval != inf && lval < x) {\n                lval = x;\n       \
    \     }\n        }\n\n        void addall(ll x) {\n            max_v += x;\n \
    \           if (smax_v != -inf) smax_v += x;\n            min_v += x;\n      \
    \      if (smin_v != inf) smin_v += x;\n\n            sum += len * x;\n      \
    \      if (lval != inf) {\n                lval += x;\n            } else {\n\
    \                ladd += x;\n            }\n        }\n\n        void updateall(ll\
    \ x) {\n            max_v = min_v = x;\n            smax_v = -inf;\n         \
    \   smin_v = inf;\n            max_c = min_c = len;\n\n            sum = len *\
    \ x;\n            lval = x;\n            ladd = 0;\n        }\n\n        void\
    \ push() {\n            if (lval != inf) {\n                left->updateall(lval);\n\
    \                right->updateall(lval);\n                lval = inf;\n      \
    \          return;\n            }\n\n            if (ladd != 0) {\n          \
    \      left->addall(ladd);\n                right->addall(ladd);\n           \
    \     ladd = 0;\n            }\n\n            if (max_v < left->max_v) {\n   \
    \             left->update_max(max_v);\n            }\n            if (left->min_v\
    \ < min_v) {\n                left->update_min(min_v);\n            }\n\n    \
    \        if (max_v < right->max_v) {\n                right->update_max(max_v);\n\
    \            }\n            if (right->min_v < min_v) {\n                right->update_min(min_v);\n\
    \            }\n        }\n\n        void update() {\n            sum = left->sum\
    \ + right->sum;\n\n            if (left->max_v < right->max_v) {\n           \
    \     max_v = right->max_v;\n                max_c = right->max_c;\n         \
    \       smax_v = max(left->max_v, right->smax_v);\n            } else if (left->max_v\
    \ > right->max_v) {\n                max_v = left->max_v;\n                max_c\
    \ = left->max_c;\n                smax_v = max(left->smax_v, right->max_v);\n\
    \            } else {\n                max_v = left->max_v;\n                max_c\
    \ = left->max_c + right->max_c;\n                smax_v = max(left->smax_v, right->smax_v);\n\
    \            }\n\n            if (left->min_v < right->min_v) {\n            \
    \    min_v = left->min_v;\n                min_c = left->min_c;\n            \
    \    smin_v = min(left->smin_v, right->min_v);\n            } else if (left->min_v\
    \ > right->min_v) {\n                min_v = right->min_v;\n                min_c\
    \ = right->min_c;\n                smin_v = min(left->min_v, right->smin_v);\n\
    \            } else {\n                min_v = left->min_v;\n                min_c\
    \ = left->min_c + right->min_c;\n                smin_v = min(left->smin_v, right->smin_v);\n\
    \            }\n        }\n    };\n\n    int n, n0;\n    Node *root;\n\n    void\
    \ _update_min(ll x, int a, int b, Node *nd, int l, int r) {\n        if (b <=\
    \ l || r <= a || nd->max_v <= x) {\n            return;\n        }\n        if\
    \ (a <= l && r <= b && nd->smax_v < x) {\n            nd->update_max(x);\n   \
    \         return;\n        }\n\n        nd->push();\n        _update_min(x, a,\
    \ b, nd->left, l, (l + r) / 2);\n        _update_min(x, a, b, nd->right, (l +\
    \ r) / 2, r);\n        nd->update();\n    }\n\n    void _update_max(ll x, int\
    \ a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <= a || x <= nd->min_v)\
    \ {\n            return;\n        }\n        if (a <= l && r <= b && x < nd->smin_v)\
    \ {\n            nd->update_min(x);\n            return;\n        }\n\n      \
    \  nd->push();\n        _update_max(x, a, b, nd->left, l, (l + r) / 2);\n    \
    \    _update_max(x, a, b, nd->right, (l + r) / 2, r);\n        nd->update();\n\
    \    }\n\n    void _add_val(ll x, int a, int b, Node *nd, int l, int r) {\n  \
    \      if (b <= l || r <= a) {\n            return;\n        }\n        if (a\
    \ <= l && r <= b) {\n            nd->addall(x);\n            return;\n       \
    \ }\n\n        nd->push();\n        _add_val(x, a, b, nd->left, l, (l + r) / 2);\n\
    \        _add_val(x, a, b, nd->right, (l + r) / 2, r);\n        nd->update();\n\
    \    }\n\n    void _update_val(ll x, int a, int b, Node *nd, int l, int r) {\n\
    \        if (b <= l || r <= a) {\n            return;\n        }\n        if (a\
    \ <= l && r <= b) {\n            nd->updateall(x);\n            return;\n    \
    \    }\n\n        nd->push();\n        _update_val(x, a, b, nd->left, l, (l +\
    \ r) / 2);\n        _update_val(x, a, b, nd->right, (l + r) / 2, r);\n       \
    \ nd->update();\n    }\n\n    ll _query_max(int a, int b, Node *nd, int l, int\
    \ r) {\n        if (b <= l || r <= a) {\n            return -inf;\n        }\n\
    \        if (a <= l && r <= b) {\n            return nd->max_v;\n        }\n \
    \       nd->push();\n        ll lv = _query_max(a, b, nd->left, l, (l + r) / 2);\n\
    \        ll rv = _query_max(a, b, nd->right, (l + r) / 2, r);\n        return\
    \ max(lv, rv);\n    }\n\n    ll _query_min(int a, int b, Node *nd, int l, int\
    \ r) {\n        if (b <= l || r <= a) {\n            return inf;\n        }\n\
    \        if (a <= l && r <= b) {\n            return nd->min_v;\n        }\n \
    \       nd->push();\n        ll lv = _query_min(a, b, nd->left, l, (l + r) / 2);\n\
    \        ll rv = _query_min(a, b, nd->right, (l + r) / 2, r);\n        return\
    \ min(lv, rv);\n    }\n\n    ll _query_sum(int a, int b, Node *nd, int l, int\
    \ r) {\n        if (b <= l || r <= a) {\n            return 0;\n        }\n  \
    \      if (a <= l && r <= b) {\n            return nd->sum;\n        }\n     \
    \   nd->push();\n        ll lv = _query_sum(a, b, nd->left, l, (l + r) / 2);\n\
    \        ll rv = _query_sum(a, b, nd->right, (l + r) / 2, r);\n        return\
    \ lv + rv;\n    }\n\npublic:\n    SegmentTreeBeats(vector<ll> a) : n(a.size())\
    \ {\n        n0 = 1;\n        while (n0 < n) n0 <<= 1;\n\n        Node *nds =\
    \ new Node[2 * n0];\n        root = nds;\n\n        nds[0].len = n0;\n       \
    \ for (int i = 0; i < n0 - 1; ++i) {\n            nds[i].left = &nds[2 * i + 1];\n\
    \            nds[i].right = &nds[2 * i + 2];\n            nds[2 * i + 1].len =\
    \ nds[2 * i + 2].len = (nds[i].len >> 1);\n        }\n\n        for (int i = 0;\
    \ i < n; ++i) nds[n0 - 1 + i].init(a[i]);\n        for (int i = n; i < n0; ++i)\
    \ nds[n0 - 1 + i].init_empty();\n        for (int i = n0 - 2; i >= 0; i--) nds[i].update();\n\
    \    }\n    SegmentTreeBeats(int n) : SegmentTreeBeats(vector<ll>(n, 0)) {\n \
    \   }\n\n    void chmin(int a, int b, ll x) {\n        _update_min(x, a, b, root,\
    \ 0, n0);\n    }\n\n    void chmax(int a, int b, ll x) {\n        _update_max(x,\
    \ a, b, root, 0, n0);\n    }\n\n    void add(int a, int b, ll x) {\n        _add_val(x,\
    \ a, b, root, 0, n0);\n    }\n\n    void update(int a, int b, ll x) {\n      \
    \  _update_val(x, a, b, root, 0, n0);\n    }\n\n    ll query_max(int a, int b)\
    \ {\n        return _query_max(a, b, root, 0, n0);\n    }\n\n    ll query_min(int\
    \ a, int b) {\n        return _query_min(a, b, root, 0, n0);\n    }\n\n    ll\
    \ query_sum(int a, int b) {\n        return _query_sum(a, b, root, 0, n0);\n \
    \   }\n\n    ll get(int i) {\n        return query_sum(i, i + 1);\n    }\n\n \
    \   ll operator[](int i) {\n        return query_sum(i, i + 1);\n    }\n\n   \
    \ void chmin(int i, ll x) {\n        chmin(i, i + 1, x);\n    }\n\n    void chmax(int\
    \ i, ll x) {\n        chmax(i, i + 1, x);\n    }\n\n    void add(int i, ll x)\
    \ {\n        add(i, i + 1, x);\n    }\n\n    void update(int i, ll x) {\n    \
    \    update(i, i + 1, x);\n    }\n\n    void print(int n) {\n        rep(i, n)\
    \ {\n            cout << query_sum(i, i + 1);\n            if (i == n - 1) cout\
    \ << endl;\n            else cout << ' ';\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../macros.hpp\"\n\n// Segment Tree Beats\nclass\
    \ SegmentTreeBeats {\n    static const ll inf = 1e18;\n    struct Node {\n   \
    \     Node *left, *right;\n        ll max_v, smax_v, max_c;\n        ll min_v,\
    \ smin_v, min_c;\n        ll sum;\n        ll len, ladd, lval;\n\n        Node()\
    \ : left(0), right(0), ladd(0), lval(inf) {}\n\n        void init(ll x) {\n  \
    \          max_v = min_v = sum = x;\n            smax_v = -inf;\n            smin_v\
    \ = inf;\n            max_c = min_c = 1;\n        }\n\n        void init_empty()\
    \ {\n            max_v = smax_v = -inf;\n            min_v = smin_v = inf;\n \
    \           max_c = min_c = 0;\n        }\n\n        void update_max(ll x) {\n\
    \            sum += (x - max_v) * max_c;\n\n            if (max_v == min_v) {\n\
    \                max_v = min_v = x;\n            } else if (max_v == smin_v) {\n\
    \                max_v = smin_v = x;\n            } else {\n                max_v\
    \ = x;\n            }\n\n            if (lval != inf && x < lval) {\n        \
    \        lval = x;\n            }\n        }\n\n        void update_min(ll x)\
    \ {\n            sum += (x - min_v) * min_c;\n\n            if (max_v == min_v)\
    \ {\n                max_v = min_v = x;\n            } else if (max_v == smin_v)\
    \ {\n                min_v = smax_v = x;\n            } else {\n             \
    \   min_v = x;\n            }\n\n            if (lval != inf && lval < x) {\n\
    \                lval = x;\n            }\n        }\n\n        void addall(ll\
    \ x) {\n            max_v += x;\n            if (smax_v != -inf) smax_v += x;\n\
    \            min_v += x;\n            if (smin_v != inf) smin_v += x;\n\n    \
    \        sum += len * x;\n            if (lval != inf) {\n                lval\
    \ += x;\n            } else {\n                ladd += x;\n            }\n   \
    \     }\n\n        void updateall(ll x) {\n            max_v = min_v = x;\n  \
    \          smax_v = -inf;\n            smin_v = inf;\n            max_c = min_c\
    \ = len;\n\n            sum = len * x;\n            lval = x;\n            ladd\
    \ = 0;\n        }\n\n        void push() {\n            if (lval != inf) {\n \
    \               left->updateall(lval);\n                right->updateall(lval);\n\
    \                lval = inf;\n                return;\n            }\n\n     \
    \       if (ladd != 0) {\n                left->addall(ladd);\n              \
    \  right->addall(ladd);\n                ladd = 0;\n            }\n\n        \
    \    if (max_v < left->max_v) {\n                left->update_max(max_v);\n  \
    \          }\n            if (left->min_v < min_v) {\n                left->update_min(min_v);\n\
    \            }\n\n            if (max_v < right->max_v) {\n                right->update_max(max_v);\n\
    \            }\n            if (right->min_v < min_v) {\n                right->update_min(min_v);\n\
    \            }\n        }\n\n        void update() {\n            sum = left->sum\
    \ + right->sum;\n\n            if (left->max_v < right->max_v) {\n           \
    \     max_v = right->max_v;\n                max_c = right->max_c;\n         \
    \       smax_v = max(left->max_v, right->smax_v);\n            } else if (left->max_v\
    \ > right->max_v) {\n                max_v = left->max_v;\n                max_c\
    \ = left->max_c;\n                smax_v = max(left->smax_v, right->max_v);\n\
    \            } else {\n                max_v = left->max_v;\n                max_c\
    \ = left->max_c + right->max_c;\n                smax_v = max(left->smax_v, right->smax_v);\n\
    \            }\n\n            if (left->min_v < right->min_v) {\n            \
    \    min_v = left->min_v;\n                min_c = left->min_c;\n            \
    \    smin_v = min(left->smin_v, right->min_v);\n            } else if (left->min_v\
    \ > right->min_v) {\n                min_v = right->min_v;\n                min_c\
    \ = right->min_c;\n                smin_v = min(left->min_v, right->smin_v);\n\
    \            } else {\n                min_v = left->min_v;\n                min_c\
    \ = left->min_c + right->min_c;\n                smin_v = min(left->smin_v, right->smin_v);\n\
    \            }\n        }\n    };\n\n    int n, n0;\n    Node *root;\n\n    void\
    \ _update_min(ll x, int a, int b, Node *nd, int l, int r) {\n        if (b <=\
    \ l || r <= a || nd->max_v <= x) {\n            return;\n        }\n        if\
    \ (a <= l && r <= b && nd->smax_v < x) {\n            nd->update_max(x);\n   \
    \         return;\n        }\n\n        nd->push();\n        _update_min(x, a,\
    \ b, nd->left, l, (l + r) / 2);\n        _update_min(x, a, b, nd->right, (l +\
    \ r) / 2, r);\n        nd->update();\n    }\n\n    void _update_max(ll x, int\
    \ a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <= a || x <= nd->min_v)\
    \ {\n            return;\n        }\n        if (a <= l && r <= b && x < nd->smin_v)\
    \ {\n            nd->update_min(x);\n            return;\n        }\n\n      \
    \  nd->push();\n        _update_max(x, a, b, nd->left, l, (l + r) / 2);\n    \
    \    _update_max(x, a, b, nd->right, (l + r) / 2, r);\n        nd->update();\n\
    \    }\n\n    void _add_val(ll x, int a, int b, Node *nd, int l, int r) {\n  \
    \      if (b <= l || r <= a) {\n            return;\n        }\n        if (a\
    \ <= l && r <= b) {\n            nd->addall(x);\n            return;\n       \
    \ }\n\n        nd->push();\n        _add_val(x, a, b, nd->left, l, (l + r) / 2);\n\
    \        _add_val(x, a, b, nd->right, (l + r) / 2, r);\n        nd->update();\n\
    \    }\n\n    void _update_val(ll x, int a, int b, Node *nd, int l, int r) {\n\
    \        if (b <= l || r <= a) {\n            return;\n        }\n        if (a\
    \ <= l && r <= b) {\n            nd->updateall(x);\n            return;\n    \
    \    }\n\n        nd->push();\n        _update_val(x, a, b, nd->left, l, (l +\
    \ r) / 2);\n        _update_val(x, a, b, nd->right, (l + r) / 2, r);\n       \
    \ nd->update();\n    }\n\n    ll _query_max(int a, int b, Node *nd, int l, int\
    \ r) {\n        if (b <= l || r <= a) {\n            return -inf;\n        }\n\
    \        if (a <= l && r <= b) {\n            return nd->max_v;\n        }\n \
    \       nd->push();\n        ll lv = _query_max(a, b, nd->left, l, (l + r) / 2);\n\
    \        ll rv = _query_max(a, b, nd->right, (l + r) / 2, r);\n        return\
    \ max(lv, rv);\n    }\n\n    ll _query_min(int a, int b, Node *nd, int l, int\
    \ r) {\n        if (b <= l || r <= a) {\n            return inf;\n        }\n\
    \        if (a <= l && r <= b) {\n            return nd->min_v;\n        }\n \
    \       nd->push();\n        ll lv = _query_min(a, b, nd->left, l, (l + r) / 2);\n\
    \        ll rv = _query_min(a, b, nd->right, (l + r) / 2, r);\n        return\
    \ min(lv, rv);\n    }\n\n    ll _query_sum(int a, int b, Node *nd, int l, int\
    \ r) {\n        if (b <= l || r <= a) {\n            return 0;\n        }\n  \
    \      if (a <= l && r <= b) {\n            return nd->sum;\n        }\n     \
    \   nd->push();\n        ll lv = _query_sum(a, b, nd->left, l, (l + r) / 2);\n\
    \        ll rv = _query_sum(a, b, nd->right, (l + r) / 2, r);\n        return\
    \ lv + rv;\n    }\n\npublic:\n    SegmentTreeBeats(vector<ll> a) : n(a.size())\
    \ {\n        n0 = 1;\n        while (n0 < n) n0 <<= 1;\n\n        Node *nds =\
    \ new Node[2 * n0];\n        root = nds;\n\n        nds[0].len = n0;\n       \
    \ for (int i = 0; i < n0 - 1; ++i) {\n            nds[i].left = &nds[2 * i + 1];\n\
    \            nds[i].right = &nds[2 * i + 2];\n            nds[2 * i + 1].len =\
    \ nds[2 * i + 2].len = (nds[i].len >> 1);\n        }\n\n        for (int i = 0;\
    \ i < n; ++i) nds[n0 - 1 + i].init(a[i]);\n        for (int i = n; i < n0; ++i)\
    \ nds[n0 - 1 + i].init_empty();\n        for (int i = n0 - 2; i >= 0; i--) nds[i].update();\n\
    \    }\n    SegmentTreeBeats(int n) : SegmentTreeBeats(vector<ll>(n, 0)) {\n \
    \   }\n\n    void chmin(int a, int b, ll x) {\n        _update_min(x, a, b, root,\
    \ 0, n0);\n    }\n\n    void chmax(int a, int b, ll x) {\n        _update_max(x,\
    \ a, b, root, 0, n0);\n    }\n\n    void add(int a, int b, ll x) {\n        _add_val(x,\
    \ a, b, root, 0, n0);\n    }\n\n    void update(int a, int b, ll x) {\n      \
    \  _update_val(x, a, b, root, 0, n0);\n    }\n\n    ll query_max(int a, int b)\
    \ {\n        return _query_max(a, b, root, 0, n0);\n    }\n\n    ll query_min(int\
    \ a, int b) {\n        return _query_min(a, b, root, 0, n0);\n    }\n\n    ll\
    \ query_sum(int a, int b) {\n        return _query_sum(a, b, root, 0, n0);\n \
    \   }\n\n    ll get(int i) {\n        return query_sum(i, i + 1);\n    }\n\n \
    \   ll operator[](int i) {\n        return query_sum(i, i + 1);\n    }\n\n   \
    \ void chmin(int i, ll x) {\n        chmin(i, i + 1, x);\n    }\n\n    void chmax(int\
    \ i, ll x) {\n        chmax(i, i + 1, x);\n    }\n\n    void add(int i, ll x)\
    \ {\n        add(i, i + 1, x);\n    }\n\n    void update(int i, ll x) {\n    \
    \    update(i, i + 1, x);\n    }\n\n    void print(int n) {\n        rep(i, n)\
    \ {\n            cout << query_sum(i, i + 1);\n            if (i == n - 1) cout\
    \ << endl;\n            else cout << ' ';\n        }\n    }\n};\n"
  dependsOn:
  - src/macros.hpp
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/SegmentTreeBeats.hpp
  requiredBy: []
  timestamp: '2023-12-04 15:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/SegmentTreeBeats.hpp
layout: document
redirect_from:
- /library/src/datastructure/SegmentTreeBeats.hpp
- /library/src/datastructure/SegmentTreeBeats.hpp.html
title: src/datastructure/SegmentTreeBeats.hpp
---
