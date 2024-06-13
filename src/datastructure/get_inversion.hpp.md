---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/common/Compress.hpp
    title: src/common/Compress.hpp
  - icon: ':heavy_check_mark:'
    path: src/common/bisect.hpp
    title: src/common/bisect.hpp
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
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/common/bisect.hpp\"\n\ntemplate<typename T>\n\
    int bisect_left(const vector<T> &A, T val, int lo = 0) {\n    return lower_bound(A.begin()\
    \ + lo, A.end(), val) - A.begin();\n}\n\ntemplate<typename T>\nint bisect_right(const\
    \ vector<T> &A, T val, int lo = 0) {\n    return upper_bound(A.begin() + lo, A.end(),\
    \ val) - A.begin();\n}\n#line 3 \"src/macros.hpp\"\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\nusing pll = pair<ll,\
    \ ll>;\nusing pii = pair<int, int>;\nusing pli = pair<ll, int>;\nusing pil = pair<int,\
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
    \ ld EPS = 1e-10;\n    constexpr ld PI = M_PI;\n#endif\n#line 4 \"src/common/Compress.hpp\"\
    \n\n// \u5EA7\u6A19\u5727\u7E2E(\u4E8C\u5206\u63A2\u7D22\u30D9\u30FC\u30B9)\n\
    template<typename T>\nstruct Compress {\n    int N;\n    vector<T> dat;\n    bool\
    \ built = false;\n\n    Compress() {}\n\n    Compress(const vector<T> &A) : dat(A)\
    \ {\n        build();\n    }\n\n    void build() {\n        sort(dat.begin(),\
    \ dat.end());\n        dat.erase(unique(dat.begin(), dat.end()), dat.end());\n\
    \        N = dat.size();\n        built = true;\n    }\n\n    void add(T x) {\n\
    \        assert(not built);\n        dat.emplace_back(x);\n    }\n\n    // \u53EF\
    \u5909\u9577\u5F15\u6570\u3001cp.add(l, r); \u3068\u304B\u3067\u304D\u308B\n \
    \   template<typename... Ts>\n    void add(const T val, Ts... ts) {\n        dat.emplace_back(val);\n\
    \        if constexpr (sizeof...(Ts) > 0) {\n            add(ts...);\n       \
    \ }\n    }\n\n    void add(const vector<T> &A) {\n        for (auto a : A) {\n\
    \            add(a);\n        }\n    }\n\n    int zip(T x) {\n        assert(built);\n\
    \        return bisect_left(dat, x);\n    }\n\n    T unzip(int x) {\n        assert(built);\n\
    \        return dat[x];\n    }\n\n    int operator[](T x) {\n        return zip(x);\n\
    \    }\n\n    int size() {\n        assert(built);\n        return dat.size();\n\
    \    }\n\n    // \u5EA7\u5727\u5F8C\u306E\u4F4D\u7F6E[i,i+1)\u306E\u5EA7\u5727\
    \u524D\u306E\u5927\u304D\u3055\u3092\u8FD4\u3059\n    T size(int i) {\n      \
    \  assert(built and 0 <= i and i < N);\n        if (i == N - 1) {\n          \
    \  return 1;\n        } else {\n            return unzip(i + 1) - unzip(i);\n\
    \        }\n    }\n\n    vector<T> zip(const vector<T> &A) {\n        int M =\
    \ A.size();\n        vector<T> res(M);\n        for (int i = 0; i < M; i++) {\n\
    \            res[i] = zip(A[i]);\n        }\n        return res;\n    }\n};\n\n\
    // \u5EA7\u6A19\u5727\u7E2E(map\u30D9\u30FC\u30B9)(\u65E7)\n// template<typename\
    \ T>\n// pair<map<T, int>, vector<T>> compress(vector<T> unzipped) {\n//     map<T,\
    \ int> zipped;\n//     sort(unzipped.begin(), unzipped.end());\n//     unzipped.erase(unique(unzipped.begin(),\
    \ unzipped.end()), unzipped.end());\n//     for (int i = 0; i < unzipped.size();\
    \ i++) {\n//         zipped[unzipped[i]] = i;\n//     }\n//     return {zipped,\
    \ unzipped};\n// }\n#line 3 \"src/datastructure/BIT.hpp\"\n\n// Binary Indexed\
    \ Tree\ntemplate<typename T>\nclass BIT {\nprotected:\n    int n;\n    vector<T>\
    \ dat;\n\npublic:\n    BIT() = default;\n\n    explicit BIT(int n) : n(n) {\n\
    \        dat.assign(n + 1, T());\n    }\n\n    explicit BIT(const vector<T> &v)\
    \ : BIT((int)v.size()) {\n        build(v);\n    }\n\n    virtual void build(const\
    \ vector<T> &v) {\n        assert(n == (int)v.size());\n        for (int i = 1;\
    \ i <= n; i++) {\n            dat[i] = v[i - 1];\n        }\n        for (int\
    \ i = 1; i <= n; i++) {\n            int j = i + (i & -i);\n            if (j\
    \ <= n) dat[j] += dat[i];\n        }\n    }\n\n    // [0, r)\u3092\u5408\u8A08\
    \u3059\u308B\n    virtual T sum(int r) {\n        T s = T();\n        for (; r\
    \ > 0; r -= r & -r) {\n            s += dat[r];\n        }\n        return s;\n\
    \    }\n\n    virtual void add(int k, const T &x) {\n        for (++k; k <= n;\
    \ k += k & -k) {\n            dat[k] += x;\n        }\n    }\n\n    // \u533A\u9593\
    \u548C\u306E\u53D6\u5F97 [l, r)\n    T query(int l, int r) {\n        if (l >=\
    \ r) return T();\n        return sum(r) - sum(l);\n    }\n\n    virtual T get(int\
    \ i) {\n        // return query(i, i + 1);\n        // BIT\u306E\u9AD8\u901F\u306A\
    1\u70B9\u53D6\u5F97\n        // see: https://twitter.com/KakurenboUni/status/1643832177690550273\n\
    \        T s = this->dat[i + 1];\n        if (i & 1) {\n            int j = i;\n\
    \            i++;\n            i -= i & -i;\n            for (; j > i; j -= j\
    \ & -j) {\n                s -= this->dat[j];\n            }\n        }\n    \
    \    return s;\n    }\n\n    void update(int i, T x) {\n        add(i, x - this->get(i));\n\
    \    }\n\n    T operator[](int i) {\n        return this->get(i);\n    }\n\n \
    \   int size() {\n        return n;\n    }\n\n    // log2\u3064\u306E\u65E7\u4ED5\
    \u69D8\u3002\u65B0\u4ED5\u69D8\u3067\u3042\u308B\u7A0B\u5EA6\u78BA\u8A8D\u304C\
    \u53D6\u308C\u305F\u3089\u524A\u9664\u3002\n    // ll bisearch_fore(int l, int\
    \ r, ll x) {\n    //     if (l > r) return -1;\n    //     ll l_sm = sum(l);\n\
    \    //     int ok = r + 1;\n    //     int ng = l - 1;\n    //     while (ng+1\
    \ < ok) {\n    //         int mid = (ok+ng) / 2;\n    //         if (sum(mid+1)\
    \ - l_sm >= x) {\n    //             ok = mid;\n    //         } else {\n    //\
    \             ng = mid;\n    //         }\n    //     }\n    //     if (ok !=\
    \ r+1) {\n    //         return ok;\n    //     } else {\n    //         return\
    \ -1;\n    //     }\n    // }\n    // ll bisearch_back(int l, int r, ll x) {\n\
    \    //     if (l > r) return -1;\n    //     ll r_sm = sum(r+1);\n    //    \
    \ int ok = l - 1;\n    //     int ng = r + 1;\n    //     while (ok+1 < ng) {\n\
    \    //         int mid = (ok+ng) / 2;\n    //         if (r_sm - sum(mid) >=\
    \ x) {\n    //             ok = mid;\n    //         } else {\n    //        \
    \     ng = mid;\n    //         }\n    //     }\n    //     if (ok != l-1) {\n\
    \    //         return ok;\n    //     } else {\n    //         return -1;\n \
    \   //     }\n    // }\n\n    // \u533A\u9593[l, r]\u3092\u5DE6\u304B\u3089\u53F3\
    \u306B\u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\
    \u7F6E(log1\u3064\u7248)\n    int bisearch_fore(int l, int r, T x) {\n       \
    \ if (l > r) return -1;\n        assert(l >= 0 and r < n);\n        x += query(0,\
    \ l);\n        int k = lower_bound(x);\n        assert(l <= k);\n        if (k\
    \ > r) {\n            return -1;\n        } else {\n            return k;\n  \
    \      }\n    }\n\n    // \u533A\u9593[l, r]\u3092\u53F3\u304B\u3089\u5DE6\u306B\
    \u5411\u304B\u3063\u3066x\u756A\u76EE\u306E\u5024\u304C\u3042\u308B\u4F4D\u7F6E\
    (log1\u3064\u7248)\n    int bisearch_back(int l, int r, T x) {\n        if (l\
    \ > r) return -1;\n        assert(l >= 0 and r < n);\n        T total = query(0,\
    \ r + 1);\n        if (total - x < 0) {\n            return -1;\n        }\n \
    \       int k = upper_bound(total - x);\n        assert(k <= r);\n        if (k\
    \ < l) {\n            return -1;\n        } else {\n            return k;\n  \
    \      }\n    }\n\n    // \u53C2\u8003\uFF1Ahttps://ei1333.github.io/library/structure/others/binary-indexed-tree.cpp\n\
    \    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u4EE5\u4E0A\u3068\u306A\u308B\
    \u6700\u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\
    \u52A0\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002\n   \
    \ // (log\u304C1\u3064\u306A\u306E\u3067\u3001TL\u53B3\u3057\u3044\u6642\u306F\
    \u3053\u3061\u3089\u3092\u4F7F\u3046\u3002)\n    int lower_bound(T x) const {\n\
    \        int i = 0;\n        for (int k = 1 << (__lg(n) + 1); k > 0; k >>= 1)\
    \ {\n            if (i + k <= n && dat[i + k] < x) {\n                x -= dat[i\
    \ + k];\n                i += k;\n            }\n        }\n        return i;\n\
    \    }\n\n    // \u533A\u9593[0,k]\u306E\u7DCF\u548C\u304Cx\u3092\u4E0A\u56DE\u308B\
    \u6700\u5C0F\u306Ek\u3092\u8FD4\u3059\u3002\u6570\u5217\u304C\u5358\u8ABF\u5897\
    \u52A0\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u6C42\u3059\u308B\u3002\n   \
    \ int upper_bound(T x) const {\n        int i = 0;\n        for (int k = 1 <<\
    \ (__lg(n) + 1); k > 0; k >>= 1) {\n            if (i + k <= n && dat[i + k] <=\
    \ x) {\n                x -= dat[i + k];\n                i += k;\n          \
    \  }\n        }\n        return i;\n    }\n};\n\ntemplate<typename T>\nostream\
    \ &operator<<(ostream &os, BIT<T> &bit) {\n    rep(i, bit.size()) {\n        os\
    \ << bit[i];\n        if (i != bit.size() - 1) {\n            os << ' ';\n   \
    \     }\n    }\n    return os;\n}\n#line 5 \"src/datastructure/get_inversion.hpp\"\
    \n\n// \u8EE2\u5012\u6570\u53D6\u5F97\n// comp\u306F\u9806\u5217\u3058\u3083\u306A\
    \u3051\u308C\u3070\u57FA\u672Ctrue\u3067\nll get_inversion(vector<ll> A, bool\
    \ comp = true) {\n    int M = A.size();\n    if (comp) {\n        Compress<ll>\
    \ cp(A);\n        A = cp.zip(A);\n        M = cp.size();\n    }\n    BIT<ll> bit(M);\n\
    \    ll res = 0;\n    for (auto a : A) {\n        res += bit.query(a + 1, M);\n\
    \        bit.add(a, 1);\n    }\n    return res;\n}\n\n// \u30DE\u30FC\u30B8\u30BD\
    \u30FC\u30C8\u306B\u3088\u308B\u8EE2\u5012\u6570\u53D6\u5F97\n// \u30FB\u5EA7\u5727\
    BIT\u3088\u308A\u901F\u3044\u3051\u3069\u3001\u53C2\u7167\u6E21\u3057\u3084\u3081\
    \u308B\u3068\u30D0\u30B0\u308B\u306E\u3067\u3001\n// \u3000\u5143\u306E\u5217\u3082\
    \u307E\u3060\u4F7F\u3046\u5834\u5408\u306F\u30B3\u30D4\u30FC\u3057\u3066\u304B\
    \u3089\u3084\u308B\u3053\u3068\u3002\n// \u30FB\u5EA7\u5727\u3092\u4E8C\u5206\u63A2\
    \u7D22\u30D9\u30FC\u30B9\u306B\u3057\u3066\u304B\u3089\u307E\u3060\u901F\u5EA6\
    \u6BD4\u8F03\u3057\u3066\u306A\u3044\u306E\u3067\u3001\n// \u3000\u3082\u3057\u304B\
    \u3057\u305F\u3089\u305D\u3063\u3061\u306E\u5EA7\u5727\u7248\u3060\u3063\u305F\
    \u3089\u5927\u5DEE\u306A\u3044\u304B\u3082\u3002\n// ll get_inversion(vector<ll>\
    \ &a) {\n//     int n = a.size();\n//     if (n <= 1) {\n//         return 0;\n\
    //     }\n\n//     ll cnt = 0;\n//     vector<ll> b(a.begin(), a.begin() + n /\
    \ 2);\n//     vector<ll> c(a.begin() + n / 2, a.end());\n\n//     cnt += get_inversion(b);\n\
    //     cnt += get_inversion(c);\n\n//     int ai = 0, bi = 0, ci = 0;\n//    \
    \ // merge\u306E\u51E6\u7406\n//     while (ai < n) {\n//         if (bi < b.size()\
    \ && (ci == c.size() || b[bi] <= c[ci])) {\n//             a[ai++] = b[bi++];\n\
    //         } else {\n//             cnt += n / 2 - bi;\n//             a[ai++]\
    \ = c[ci++];\n//         }\n//     }\n//     return cnt;\n// }\n"
  code: "#pragma once\n#include \"../common/Compress.hpp\"\n#include \"../macros.hpp\"\
    \n#include \"BIT.hpp\"\n\n// \u8EE2\u5012\u6570\u53D6\u5F97\n// comp\u306F\u9806\
    \u5217\u3058\u3083\u306A\u3051\u308C\u3070\u57FA\u672Ctrue\u3067\nll get_inversion(vector<ll>\
    \ A, bool comp = true) {\n    int M = A.size();\n    if (comp) {\n        Compress<ll>\
    \ cp(A);\n        A = cp.zip(A);\n        M = cp.size();\n    }\n    BIT<ll> bit(M);\n\
    \    ll res = 0;\n    for (auto a : A) {\n        res += bit.query(a + 1, M);\n\
    \        bit.add(a, 1);\n    }\n    return res;\n}\n\n// \u30DE\u30FC\u30B8\u30BD\
    \u30FC\u30C8\u306B\u3088\u308B\u8EE2\u5012\u6570\u53D6\u5F97\n// \u30FB\u5EA7\u5727\
    BIT\u3088\u308A\u901F\u3044\u3051\u3069\u3001\u53C2\u7167\u6E21\u3057\u3084\u3081\
    \u308B\u3068\u30D0\u30B0\u308B\u306E\u3067\u3001\n// \u3000\u5143\u306E\u5217\u3082\
    \u307E\u3060\u4F7F\u3046\u5834\u5408\u306F\u30B3\u30D4\u30FC\u3057\u3066\u304B\
    \u3089\u3084\u308B\u3053\u3068\u3002\n// \u30FB\u5EA7\u5727\u3092\u4E8C\u5206\u63A2\
    \u7D22\u30D9\u30FC\u30B9\u306B\u3057\u3066\u304B\u3089\u307E\u3060\u901F\u5EA6\
    \u6BD4\u8F03\u3057\u3066\u306A\u3044\u306E\u3067\u3001\n// \u3000\u3082\u3057\u304B\
    \u3057\u305F\u3089\u305D\u3063\u3061\u306E\u5EA7\u5727\u7248\u3060\u3063\u305F\
    \u3089\u5927\u5DEE\u306A\u3044\u304B\u3082\u3002\n// ll get_inversion(vector<ll>\
    \ &a) {\n//     int n = a.size();\n//     if (n <= 1) {\n//         return 0;\n\
    //     }\n\n//     ll cnt = 0;\n//     vector<ll> b(a.begin(), a.begin() + n /\
    \ 2);\n//     vector<ll> c(a.begin() + n / 2, a.end());\n\n//     cnt += get_inversion(b);\n\
    //     cnt += get_inversion(c);\n\n//     int ai = 0, bi = 0, ci = 0;\n//    \
    \ // merge\u306E\u51E6\u7406\n//     while (ai < n) {\n//         if (bi < b.size()\
    \ && (ci == c.size() || b[bi] <= c[ci])) {\n//             a[ai++] = b[bi++];\n\
    //         } else {\n//             cnt += n / 2 - bi;\n//             a[ai++]\
    \ = c[ci++];\n//         }\n//     }\n//     return cnt;\n// }\n"
  dependsOn:
  - src/common/Compress.hpp
  - src/common/bisect.hpp
  - src/base.hpp
  - src/macros.hpp
  - src/datastructure/BIT.hpp
  isVerificationFile: false
  path: src/datastructure/get_inversion.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/get_inversion.hpp
layout: document
redirect_from:
- /library/src/datastructure/get_inversion.hpp
- /library/src/datastructure/get_inversion.hpp.html
title: src/datastructure/get_inversion.hpp
---
