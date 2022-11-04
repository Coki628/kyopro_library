---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/datastructure/BIT.hpp
    title: src/datastructure/BIT.hpp
  - icon: ':heavy_check_mark:'
    path: src/macros.hpp
    title: src/macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://suisen-cp.github.io/cp-library-cpp/library/datastructure/fenwick_tree/persistent_fenwick_tree.hpp
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
    \    constexpr ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 3 \"\
    src/datastructure/BIT.hpp\"\n\n// Binary Indexed Tree\ntemplate<typename T>\n\
    class BIT {\nprivate:\n    int n;\n    vector<T> dat;\n\npublic:\n    BIT() =\
    \  default;\n\n    explicit BIT(int n) : n(n) {\n        dat.assign(n+1, 0);\n\
    \    }\n\n    explicit BIT(const vector<T> &v) : BIT((int)v.size()) {\n      \
    \  build(v);\n    }\n\n    virtual void build(const vector<T> &v) {\n        assert(n\
    \ == (int)v.size());\n        for (int i = 1; i <= n; i++) {\n            dat[i]\
    \ = v[i - 1];\n        }\n        for (int i = 1; i <= n; i++) {\n           \
    \ int j = i + (i & -i);\n            if (j <= n) dat[j] += dat[i];\n        }\n\
    \    }\n\n    // [0, r)\u3092\u5408\u8A08\u3059\u308B\n    virtual T sum(int r)\
    \ {\n        T s = T();\n        for (; r > 0; r -= r & -r) {\n            s +=\
    \ dat[r];\n        }\n        return s;\n    }\n\n    virtual void add(int k,\
    \ const T &x) {\n        for (++k; k <= n; k += k & -k) {\n            dat[k]\
    \ += x;\n        }\n    }\n\n    // \u533A\u9593\u548C\u306E\u53D6\u5F97 [l, r)\n\
    \    T query(int l, int r) {\n        if (l >= r) return 0;\n        return sum(r)\
    \ - sum(l);\n    }\n\n    T get(int i) {\n        return query(i, i+1);\n    }\n\
    \n    void update(int i, T x) {\n        add(i, x-get(i));\n    }\n\n    T operator[](int\
    \ i) {\n        return query(i, i+1);\n    }\n\n    void print(int n=-1) {\n \
    \       if (n == -1) n = this->n;\n        rep(i, n) {\n            cout << query(i,\
    \ i+1);\n            if (i == n-1) cout << endl;\n            else cout << ' ';\n\
    \        }\n    }\n\n    // \u533A\u9593[l, r]\u3092\u5DE6\u304B\u3089\u53F3\u306B\
    \u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\
    \n    ll bisearch_fore(int l, int r, ll x) {\n        if (l > r) return -1;\n\
    \        ll l_sm = sum(l);\n        int ok = r + 1;\n        int ng = l - 1;\n\
    \        while (ng+1 < ok) {\n            int mid = (ok+ng) / 2;\n           \
    \ if (sum(mid+1) - l_sm >= x) {\n                ok = mid;\n            } else\
    \ {\n                ng = mid;\n            }\n        }\n        if (ok != r+1)\
    \ {\n            return ok;\n        } else {\n            return -1;\n      \
    \  }\n    }\n\n    // \u533A\u9593[l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\u5411\
    \u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\n  \
    \  ll bisearch_back(int l, int r, ll x) {\n        if (l > r) return -1;\n   \
    \     ll r_sm = sum(r+1);\n        int ok = l - 1;\n        int ng = r + 1;\n\
    \        while (ok+1 < ng) {\n            int mid = (ok+ng) / 2;\n           \
    \ if (r_sm - sum(mid) >= x) {\n                ok = mid;\n            } else {\n\
    \                ng = mid;\n            }\n        }\n        if (ok != l-1) {\n\
    \            return ok;\n        } else {\n            return -1;\n        }\n\
    \    }\n\n    // \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/others/binary-indexed-tree.cpp\n\
    \    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u4EE5\u4E0A\u3068\u306A\u308B\
    \u6700\u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\
    \u52A0\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002\n   \
    \ // (log\u304C1\u3064\u306A\u306E\u3067\u3001TL\u53B3\u3057\u3044\u6642\u306F\
    \u3053\u3061\u3089\u3092\u4F7F\u3046\u3002)\n    virtual int lower_bound(T x)\
    \ const {\n        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0;\
    \ k >>= 1) {\n            if (i + k <= n && dat[i+k] < x) {\n                x\
    \ -= dat[i+k];\n                i += k;\n            }\n        }\n        return\
    \ i;\n    }\n\n    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u3092\u4E0A\u56DE\
    \u308B\u6700\u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\
    \u5897\u52A0\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002\
    (\u672Averify)\n    virtual int upper_bound(T x) const {\n        int i = 0;\n\
    \        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {\n            if (i\
    \ + k <= n && dat[i+k] <= x) {\n                x -= dat[i+k];\n             \
    \   i += k;\n            }\n        }\n        return i;\n    }\n};\n#line 3 \"\
    src/datastructure/PersistentBIT.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/datastructure/fenwick_tree/persistent_fenwick_tree.hpp\n\
    // \u6C38\u7D9ABIT\n// \u30FBBIT\u306E\u6B6F\u629C\u3051\u306E2\u5206\u6728\u3067\
    \u30BB\u30B0\u6728\u3068\u540C\u3058\u3088\u3046\u306B\u3084\u308B\u306E\u306F\
    \u96E3\u3057\u3044\u3093\u3058\u3083\u306A\u3044\u304B\u3068\u601D\u3063\u305F\
    \u3051\u3069\u3001\n// \u3000suisen\u3055\u3093\u304C\u3057\u3063\u304B\u308A\u4F5C\
    \u3063\u3066\u3044\u305F\u3002in-order\u306B\u4E26\u3079\u308B\u3068\u3046\u307E\
    \u304F\u3044\u304F\u3068\u304B\u3002\n// \u3000\u30B3\u30A2\u306E\u90E8\u5206\u3092\
    \u624B\u6301\u3061\u306E\u3082\u306E\u306B\u9069\u7528\u3055\u305B\u3066\u3001\
    \u4E00\u5FDCverify\u306F\u3067\u304D\u305F\u3002(abc253_f)\n// \u3000\u306A\u3093\
    \u3060\u3051\u3069\u3001\u30BB\u30B0\u6728\u3068\u6BD4\u3079\u3066\u3042\u3093\
    \u307E\u901F\u304F\u306A\u3063\u3066\u306F\u3044\u306A\u304F\u3066\u3001\n// \u3000\
    \u306A\u3093\u304B\u4F59\u8A08\u306Anode\u751F\u6210\u3068\u304B\u3084\u3063\u3061\
    \u3083\u3063\u3066\u308B\u304B\u3082\u3057\u308C\u306A\u3044\u3002\n\ntemplate<typename\
    \ T>\nclass PersistentBIT : public BIT<T> {\npublic:\n    struct Node {\n    \
    \    T data;\n        Node *l, *r;\n\n        Node(const T &data) : data(data),\
    \ l(nullptr), r(nullptr) {}\n        Node(Node* node) : data(node->data), l(node->l),\
    \ r(node->r) {}\n    };\nprivate:\n    int n, sz;\n    Node* root;\n    vector<Node*>\
    \ nodes;\npublic:\n    PersistentBIT() =  default;\n\n    explicit PersistentBIT(int\
    \ n) : n(n) {\n        sz = 1;\n        while (sz < n) {\n            sz <<= 1;\n\
    \        }\n        if (n == 0) sz = 0;\n        nodes.resize(n+1);\n        auto\
    \ rec = [&](auto rec, int p, int id) -> Node* {\n            if (p == 0) return\
    \ nullptr;\n            const int np = p >> 1;\n            Node* res = new Node((T)0);\n\
    \            res->l = rec(rec, np, id - np);\n            if (id + 1 <= n) res->r\
    \ = rec(rec, np, id + np);\n            if (id <= n) {\n                nodes[id]\
    \ = res;\n            }\n            return res;\n        };\n        root = rec(rec,\
    \ sz, sz);\n    }\n\n    explicit PersistentBIT(const vector<T> &v) : PersistentBIT((int)v.size())\
    \ {\n        build(v);\n    }\n\n    void build(const vector<T> &v) override {\n\
    \        assert(n == (int)v.size());\n        for (int i = 1; i <= n; i++) {\n\
    \            nodes[i]->data = v[i-1];\n        }\n        for (int i = 1; i <=\
    \ n; i++) {\n            int j = i + (i & -i);\n            if (j <= n) {\n  \
    \              nodes[j]->data += nodes[i]->data;\n            }\n        }\n \
    \   }\n\n    T sum(int r) {\n        T s = T();\n        int p = sz;\n       \
    \ Node* cur = root;\n        while (r > 0) {\n            if (r & p) {\n     \
    \           r ^= p;\n                s += cur->data;\n                cur = cur->r;\n\
    \            } else {\n                cur = cur->l;\n            }\n        \
    \    p >>= 1;\n        }\n        return s;\n    }\n\n    void add(int k, const\
    \ T &x) override {\n        k++;\n        root = new Node(root);\n        Node*\
    \ cur = root;\n        int p = sz;\n        while (1) {\n            if (k & p)\
    \ {\n                if (k ^= p) {\n                    cur = cur->r = new Node(cur->r);\n\
    \                } else {\n                    cur->data += x;\n             \
    \       break;\n                }\n            } else {\n                cur->data\
    \ += x;\n                cur = cur->l = new Node(cur->l);\n            }\n   \
    \         p >>= 1;\n        }\n    }\n\n    // (\u672Averify)\n    int lower_bound(T\
    \ x) {\n        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0; k\
    \ >>= 1) {\n            if (i + k <= n && nodes[i+k]->data < x) {\n          \
    \      x -= nodes[i+k]->data;\n                i += k;\n            }\n      \
    \  }\n        return i;\n    }\n\n    // (\u672Averify)\n    int upper_bound(T\
    \ x) {\n        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0; k\
    \ >>= 1) {\n            if (i + k <= n && nodes[i+k]->data <= x) {\n         \
    \       x -= nodes[i+k]->data;\n                i += k;\n            }\n     \
    \   }\n        return i;\n    }\n\n    Node* save() {\n        return root;\n\
    \    }\n\n    void load(Node* p) {\n        root = p;\n    }\n};\n"
  code: "#include \"../base.hpp\"\n#include \"BIT.hpp\"\n\n// \u53C2\u8003\uFF1Ahttps://suisen-cp.github.io/cp-library-cpp/library/datastructure/fenwick_tree/persistent_fenwick_tree.hpp\n\
    // \u6C38\u7D9ABIT\n// \u30FBBIT\u306E\u6B6F\u629C\u3051\u306E2\u5206\u6728\u3067\
    \u30BB\u30B0\u6728\u3068\u540C\u3058\u3088\u3046\u306B\u3084\u308B\u306E\u306F\
    \u96E3\u3057\u3044\u3093\u3058\u3083\u306A\u3044\u304B\u3068\u601D\u3063\u305F\
    \u3051\u3069\u3001\n// \u3000suisen\u3055\u3093\u304C\u3057\u3063\u304B\u308A\u4F5C\
    \u3063\u3066\u3044\u305F\u3002in-order\u306B\u4E26\u3079\u308B\u3068\u3046\u307E\
    \u304F\u3044\u304F\u3068\u304B\u3002\n// \u3000\u30B3\u30A2\u306E\u90E8\u5206\u3092\
    \u624B\u6301\u3061\u306E\u3082\u306E\u306B\u9069\u7528\u3055\u305B\u3066\u3001\
    \u4E00\u5FDCverify\u306F\u3067\u304D\u305F\u3002(abc253_f)\n// \u3000\u306A\u3093\
    \u3060\u3051\u3069\u3001\u30BB\u30B0\u6728\u3068\u6BD4\u3079\u3066\u3042\u3093\
    \u307E\u901F\u304F\u306A\u3063\u3066\u306F\u3044\u306A\u304F\u3066\u3001\n// \u3000\
    \u306A\u3093\u304B\u4F59\u8A08\u306Anode\u751F\u6210\u3068\u304B\u3084\u3063\u3061\
    \u3083\u3063\u3066\u308B\u304B\u3082\u3057\u308C\u306A\u3044\u3002\n\ntemplate<typename\
    \ T>\nclass PersistentBIT : public BIT<T> {\npublic:\n    struct Node {\n    \
    \    T data;\n        Node *l, *r;\n\n        Node(const T &data) : data(data),\
    \ l(nullptr), r(nullptr) {}\n        Node(Node* node) : data(node->data), l(node->l),\
    \ r(node->r) {}\n    };\nprivate:\n    int n, sz;\n    Node* root;\n    vector<Node*>\
    \ nodes;\npublic:\n    PersistentBIT() =  default;\n\n    explicit PersistentBIT(int\
    \ n) : n(n) {\n        sz = 1;\n        while (sz < n) {\n            sz <<= 1;\n\
    \        }\n        if (n == 0) sz = 0;\n        nodes.resize(n+1);\n        auto\
    \ rec = [&](auto rec, int p, int id) -> Node* {\n            if (p == 0) return\
    \ nullptr;\n            const int np = p >> 1;\n            Node* res = new Node((T)0);\n\
    \            res->l = rec(rec, np, id - np);\n            if (id + 1 <= n) res->r\
    \ = rec(rec, np, id + np);\n            if (id <= n) {\n                nodes[id]\
    \ = res;\n            }\n            return res;\n        };\n        root = rec(rec,\
    \ sz, sz);\n    }\n\n    explicit PersistentBIT(const vector<T> &v) : PersistentBIT((int)v.size())\
    \ {\n        build(v);\n    }\n\n    void build(const vector<T> &v) override {\n\
    \        assert(n == (int)v.size());\n        for (int i = 1; i <= n; i++) {\n\
    \            nodes[i]->data = v[i-1];\n        }\n        for (int i = 1; i <=\
    \ n; i++) {\n            int j = i + (i & -i);\n            if (j <= n) {\n  \
    \              nodes[j]->data += nodes[i]->data;\n            }\n        }\n \
    \   }\n\n    T sum(int r) {\n        T s = T();\n        int p = sz;\n       \
    \ Node* cur = root;\n        while (r > 0) {\n            if (r & p) {\n     \
    \           r ^= p;\n                s += cur->data;\n                cur = cur->r;\n\
    \            } else {\n                cur = cur->l;\n            }\n        \
    \    p >>= 1;\n        }\n        return s;\n    }\n\n    void add(int k, const\
    \ T &x) override {\n        k++;\n        root = new Node(root);\n        Node*\
    \ cur = root;\n        int p = sz;\n        while (1) {\n            if (k & p)\
    \ {\n                if (k ^= p) {\n                    cur = cur->r = new Node(cur->r);\n\
    \                } else {\n                    cur->data += x;\n             \
    \       break;\n                }\n            } else {\n                cur->data\
    \ += x;\n                cur = cur->l = new Node(cur->l);\n            }\n   \
    \         p >>= 1;\n        }\n    }\n\n    // (\u672Averify)\n    int lower_bound(T\
    \ x) {\n        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0; k\
    \ >>= 1) {\n            if (i + k <= n && nodes[i+k]->data < x) {\n          \
    \      x -= nodes[i+k]->data;\n                i += k;\n            }\n      \
    \  }\n        return i;\n    }\n\n    // (\u672Averify)\n    int upper_bound(T\
    \ x) {\n        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0; k\
    \ >>= 1) {\n            if (i + k <= n && nodes[i+k]->data <= x) {\n         \
    \       x -= nodes[i+k]->data;\n                i += k;\n            }\n     \
    \   }\n        return i;\n    }\n\n    Node* save() {\n        return root;\n\
    \    }\n\n    void load(Node* p) {\n        root = p;\n    }\n};\n"
  dependsOn:
  - src/base.hpp
  - src/datastructure/BIT.hpp
  - src/macros.hpp
  isVerificationFile: false
  path: src/datastructure/PersistentBIT.hpp
  requiredBy: []
  timestamp: '2022-11-04 15:09:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/PersistentBIT.hpp
layout: document
redirect_from:
- /library/src/datastructure/PersistentBIT.hpp
- /library/src/datastructure/PersistentBIT.hpp.html
title: src/datastructure/PersistentBIT.hpp
---
