---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':warning:'
    path: src/datastructure/bit_vector.hpp
    title: src/datastructure/bit_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc281/submissions/37200871
    - https://drken1215.hatenablog.com/entry/2023/10/20/020039
    - https://twitter.com/US_kyopro/status/1601792850886242304
  bundledCode: "#line 2 \"src/base.hpp\"\n// UF\u306E\u7A7A\u30E9\u30E0\u30C0\u6E21\
    \u3057\u3066\u308B\u6240\u306E\u5F15\u6570\u3067\u6587\u53E5\u8A00\u308F\u308C\
    \u308B\u306E\u3092\u9ED9\u3089\u305B\u308B\n#pragma GCC diagnostic ignored \"\
    -Wunused-parameter\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#line 3 \"src/datastructure/bit_vector.hpp\"\n#include <immintrin.h>\n\
    \nstruct bit_vector {\n    using u32 = uint32_t;\n    using i64 = int64_t;\n \
    \   using u64 = uint64_t;\n\n    static constexpr u32 w = 64;\n    vector<u64>\
    \ block;\n    vector<u32> count;\n    u32 n, zeros;\n\n    inline u32 get(u32\
    \ i) const { return u32(block[i / w] >> (i % w)) & 1u; }\n    inline void set(u32\
    \ i) { block[i / w] |= 1LL << (i % w); }\n\n    bit_vector() {}\n    bit_vector(int\
    \ _n) { init(_n); }\n    __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\n        n = zeros = _n;\n        block.resize(n / w + 1, 0);\n\
    \        count.resize(block.size(), 0);\n    }\n\n    __attribute__((target(\"\
    popcnt\"))) void build() {\n        for (u32 i = 1; i < block.size(); ++i)\n \
    \           count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n        zeros\
    \ = rank0(n);\n    }\n\n    inline u32 rank0(u32 i) const { return i - rank1(i);\
    \ }\n    __attribute__((target(\"bmi2,popcnt\"))) inline u32 rank1(u32 i) const\
    \ {\n        return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w], i %\
    \ w));\n    }\n};\n#line 5 \"src/datastructure/WeightedWaveletMatrix.hpp\"\n\n\
    // \u91CD\u307F\u4ED8\u304DWavelet Matrix\n// see: https://drken1215.hatenablog.com/entry/2023/10/20/020039\n\
    // \u30FB(x,y)\u3078\u306E\u70B9\u306B\u91CD\u307Fval\u3092\u4ED8\u3051\u3089\u308C\
    \u308B\u3002\ntemplate<typename T, typename U>\nstruct WeightedWaveletMatrix {\n\
    \    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \n    int n, lg;\n    vector<T> a;\n    vector<U> dat;\n    vector<bit_vector>\
    \ bv;\n    vector<vector<U>> sum;\n\n    WeightedWaveletMatrix(u32 _n) : n(max<u32>(_n,\
    \ 1)), a(n), dat(n) {}\n\n    WeightedWaveletMatrix(const vector<T> &_a, const\
    \ vector<U> &_dat)\n        : n(_a.size()),\n          a(_a),\n          dat(_dat)\
    \ {\n        build();\n    }\n\n    __attribute__((optimize(\"O3\"))) void build()\
    \ {\n        lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\n     \
    \   bv.assign(lg, n);\n        sum.assign(lg + 1, vector<U>(n + 1, (U)0));\n \
    \       vector<int> l(n), r(n), ord(n);\n        iota(begin(ord), end(ord), 0);\n\
    \        for (int h = lg - 1; h >= 0; --h) {\n            int left = 0, right\
    \ = 0;\n            for (int i = 0; i < n; ++i) {\n                if ((a[ord[i]]\
    \ >> h) & 1) {\n                    bv[h].set(i);\n                    r[right++]\
    \ = ord[i];\n                } else {\n                    l[left++] = ord[i];\n\
    \                }\n            }\n            bv[h].build();\n            swap(ord,\
    \ l);\n            for (int i = 0; i < right; i++) {\n                ord[left\
    \ + i] = r[i];\n            }\n            for (int i = 0; i < n; i++) {\n   \
    \             sum[h][i + 1] = sum[h][i] + dat[ord[i]];\n            }\n      \
    \  }\n        // \u5168\u4F53\u306E\u7D2F\u7A4D\u548C\u3092\u6301\u3063\u3066\u304A\
    \u304F\n        for (int i = 0; i < n; i++) {\n            sum[lg][i + 1] = sum[lg][i]\
    \ + dat[i];\n        }\n        return;\n    }\n\n    // \u4F4D\u7F6E(x,y)\u306B\
    \u91CD\u3055val\u306E\u70B9\u3092\u30BB\u30C3\u30C8\u3059\u308B\n    // (x\u306F\
    \u91CD\u8907\u3067\u304D\u306A\u3044\u306E\u3067\u3001id\u3068\u30DA\u30A2\u3067\
    \u5EA7\u5727\u3059\u308B\u306A\u3069\u3067\u5BFE\u5FDC\u3059\u308B)\n    void\
    \ set(u32 x, const T &y, const U &val) {\n        assert(x >= 0 && y >= 0);\n\
    \        a[x] = y;\n        dat[x] = val;\n    }\n\n    inline pair<u32, u32>\
    \ succ0(int l, int r, int h) const {\n        return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n    }\n\n    inline pair<u32, u32> succ1(int l, int r, int\
    \ h) const {\n        u32 l0 = bv[h].rank0(l);\n        u32 r0 = bv[h].rank0(r);\n\
    \        u32 zeros = bv[h].zeros;\n        return make_pair(l + zeros - l0, r\
    \ + zeros - r0);\n    }\n\n    // return a[k]\n    T access(u32 k) const {\n \
    \       T ret = 0;\n        for (int h = lg - 1; h >= 0; --h) {\n            u32\
    \ f = bv[h].get(k);\n            ret |= f ? T(1) << h : 0;\n            k = f\
    \ ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n        }\n        return\
    \ ret;\n    }\n\n    // k-th (0-indexed) smallest number in a[l, r)\n    T kth_smallest(u32\
    \ l, u32 r, u32 k) const {\n        T res = 0;\n        for (int h = lg - 1; h\
    \ >= 0; --h) {\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n  \
    \          if (k < r0 - l0) l = l0, r = r0;\n            else {\n            \
    \    k -= r0 - l0;\n                res |= (T)1 << h;\n                l += bv[h].zeros\
    \ - l0;\n                r += bv[h].zeros - r0;\n            }\n        }\n  \
    \      return res;\n    }\n\n    // k-th (0-indexed) largest number in a[l, r)\n\
    \    T kth_largest(int l, int r, int k) {\n        return kth_smallest(l, r, r\
    \ - l - k - 1);\n    }\n\n    // \u53C2\u8003\uFF1Ahttps://twitter.com/US_kyopro/status/1601792850886242304\n\
    \    // \u3000\u3000\u3000https://atcoder.jp/contests/abc281/submissions/37200871\n\
    \    // sum of [0,k)th smallest elements([l, r))\n    T kth_smallest_sum(int l,\
    \ int r, int k) const {\n        assert(0 <= l && l <= r && r <= n);\n       \
    \ assert(0 <= k && k <= r - l);\n        T res = 0;\n        for (int h = lg -\
    \ 1; h >= 0; h--) {\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \            if (k < r0 - l0) {\n                l = l0, r = r0;\n           \
    \ } else {\n                k -= r0 - l0;\n                res += sum[h][r0] -\
    \ sum[h][l0];\n                l += bv[h].zeros - l0;\n                r += bv[h].zeros\
    \ - r0;\n            }\n        }\n        if (k) res += sum[0][l + k] - sum[0][l];\n\
    \        return res;\n    }\n\n    // sum of [0,k)th largest elements([l, r))\n\
    \    T kth_largest_sum(int l, int r, int k) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        assert(0 <= k && k <= r - l);\n        return kth_smallest_sum(l,\
    \ r, r - l) -\n               kth_smallest_sum(l, r, r - l - k);\n    }\n\n  \
    \  // count i s.t. (l <= i < r) && (v[i] < upper)\n    int range_freq(int l, int\
    \ r, T upper) {\n        if (upper >= (T(1) << lg)) return r - l;\n        int\
    \ ret = 0;\n        for (int h = lg - 1; h >= 0; --h) {\n            bool f =\
    \ (upper >> h) & 1;\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \            if (f) {\n                ret += r0 - l0;\n                l += bv[h].zeros\
    \ - l0;\n                r += bv[h].zeros - r0;\n            } else {\n      \
    \          l = l0;\n                r = r0;\n            }\n        }\n      \
    \  return ret;\n    }\n\n    T range_freq_sum(int l, int r, T upper) {\n     \
    \   if (upper >= (T(1) << lg)) return sum[lg][r] - sum[lg][l];\n        T ret\
    \ = 0;\n        for (int h = lg - 1; h >= 0; --h) {\n            bool f = (upper\
    \ >> h) & 1;\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n    \
    \        if (f) {\n                l += bv[h].zeros - l0;\n                r +=\
    \ bv[h].zeros - r0;\n                ret += sum[h][r0] - sum[h][l0];\n       \
    \     } else {\n                l = l0;\n                r = r0;\n           \
    \ }\n        }\n        return ret;\n    }\n\n    // l <= x < r and lower <= y\
    \ < upper \u306A\u8981\u7D20\u306E\u500B\u6570\n    int range_freq(int l, int\
    \ r, T lower, T upper) {\n        return range_freq(l, r, upper) - range_freq(l,\
    \ r, lower);\n    }\n\n    // l <= x < r and lower <= y < upper \u306A\u8981\u7D20\
    \u306E\u7DCF\u548C\n    T range_freq_sum(int l, int r, T lower, T upper) {\n \
    \       return range_freq_sum(l, r, upper) - range_freq_sum(l, r, lower);\n  \
    \  }\n\n    // max v[i] s.t. (l <= i < r) && (v[i] < upper)\n    T prev_value(int\
    \ l, int r, T upper) {\n        int cnt = range_freq(l, r, upper);\n        return\
    \ cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n    }\n\n    // min v[i] s.t.\
    \ (l <= i < r) && (lower <= v[i])\n    T next_value(int l, int r, T lower) {\n\
    \        int cnt = range_freq(l, r, lower);\n        return cnt == r - l ? T(-1)\
    \ : kth_smallest(l, r, cnt);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"bit_vector.hpp\"\n#include\
    \ <immintrin.h>\n\n// \u91CD\u307F\u4ED8\u304DWavelet Matrix\n// see: https://drken1215.hatenablog.com/entry/2023/10/20/020039\n\
    // \u30FB(x,y)\u3078\u306E\u70B9\u306B\u91CD\u307Fval\u3092\u4ED8\u3051\u3089\u308C\
    \u308B\u3002\ntemplate<typename T, typename U>\nstruct WeightedWaveletMatrix {\n\
    \    using u32 = uint32_t;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n\
    \n    int n, lg;\n    vector<T> a;\n    vector<U> dat;\n    vector<bit_vector>\
    \ bv;\n    vector<vector<U>> sum;\n\n    WeightedWaveletMatrix(u32 _n) : n(max<u32>(_n,\
    \ 1)), a(n), dat(n) {}\n\n    WeightedWaveletMatrix(const vector<T> &_a, const\
    \ vector<U> &_dat)\n        : n(_a.size()),\n          a(_a),\n          dat(_dat)\
    \ {\n        build();\n    }\n\n    __attribute__((optimize(\"O3\"))) void build()\
    \ {\n        lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\n     \
    \   bv.assign(lg, n);\n        sum.assign(lg + 1, vector<U>(n + 1, (U)0));\n \
    \       vector<int> l(n), r(n), ord(n);\n        iota(begin(ord), end(ord), 0);\n\
    \        for (int h = lg - 1; h >= 0; --h) {\n            int left = 0, right\
    \ = 0;\n            for (int i = 0; i < n; ++i) {\n                if ((a[ord[i]]\
    \ >> h) & 1) {\n                    bv[h].set(i);\n                    r[right++]\
    \ = ord[i];\n                } else {\n                    l[left++] = ord[i];\n\
    \                }\n            }\n            bv[h].build();\n            swap(ord,\
    \ l);\n            for (int i = 0; i < right; i++) {\n                ord[left\
    \ + i] = r[i];\n            }\n            for (int i = 0; i < n; i++) {\n   \
    \             sum[h][i + 1] = sum[h][i] + dat[ord[i]];\n            }\n      \
    \  }\n        // \u5168\u4F53\u306E\u7D2F\u7A4D\u548C\u3092\u6301\u3063\u3066\u304A\
    \u304F\n        for (int i = 0; i < n; i++) {\n            sum[lg][i + 1] = sum[lg][i]\
    \ + dat[i];\n        }\n        return;\n    }\n\n    // \u4F4D\u7F6E(x,y)\u306B\
    \u91CD\u3055val\u306E\u70B9\u3092\u30BB\u30C3\u30C8\u3059\u308B\n    // (x\u306F\
    \u91CD\u8907\u3067\u304D\u306A\u3044\u306E\u3067\u3001id\u3068\u30DA\u30A2\u3067\
    \u5EA7\u5727\u3059\u308B\u306A\u3069\u3067\u5BFE\u5FDC\u3059\u308B)\n    void\
    \ set(u32 x, const T &y, const U &val) {\n        assert(x >= 0 && y >= 0);\n\
    \        a[x] = y;\n        dat[x] = val;\n    }\n\n    inline pair<u32, u32>\
    \ succ0(int l, int r, int h) const {\n        return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n    }\n\n    inline pair<u32, u32> succ1(int l, int r, int\
    \ h) const {\n        u32 l0 = bv[h].rank0(l);\n        u32 r0 = bv[h].rank0(r);\n\
    \        u32 zeros = bv[h].zeros;\n        return make_pair(l + zeros - l0, r\
    \ + zeros - r0);\n    }\n\n    // return a[k]\n    T access(u32 k) const {\n \
    \       T ret = 0;\n        for (int h = lg - 1; h >= 0; --h) {\n            u32\
    \ f = bv[h].get(k);\n            ret |= f ? T(1) << h : 0;\n            k = f\
    \ ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n        }\n        return\
    \ ret;\n    }\n\n    // k-th (0-indexed) smallest number in a[l, r)\n    T kth_smallest(u32\
    \ l, u32 r, u32 k) const {\n        T res = 0;\n        for (int h = lg - 1; h\
    \ >= 0; --h) {\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n  \
    \          if (k < r0 - l0) l = l0, r = r0;\n            else {\n            \
    \    k -= r0 - l0;\n                res |= (T)1 << h;\n                l += bv[h].zeros\
    \ - l0;\n                r += bv[h].zeros - r0;\n            }\n        }\n  \
    \      return res;\n    }\n\n    // k-th (0-indexed) largest number in a[l, r)\n\
    \    T kth_largest(int l, int r, int k) {\n        return kth_smallest(l, r, r\
    \ - l - k - 1);\n    }\n\n    // \u53C2\u8003\uFF1Ahttps://twitter.com/US_kyopro/status/1601792850886242304\n\
    \    // \u3000\u3000\u3000https://atcoder.jp/contests/abc281/submissions/37200871\n\
    \    // sum of [0,k)th smallest elements([l, r))\n    T kth_smallest_sum(int l,\
    \ int r, int k) const {\n        assert(0 <= l && l <= r && r <= n);\n       \
    \ assert(0 <= k && k <= r - l);\n        T res = 0;\n        for (int h = lg -\
    \ 1; h >= 0; h--) {\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \            if (k < r0 - l0) {\n                l = l0, r = r0;\n           \
    \ } else {\n                k -= r0 - l0;\n                res += sum[h][r0] -\
    \ sum[h][l0];\n                l += bv[h].zeros - l0;\n                r += bv[h].zeros\
    \ - r0;\n            }\n        }\n        if (k) res += sum[0][l + k] - sum[0][l];\n\
    \        return res;\n    }\n\n    // sum of [0,k)th largest elements([l, r))\n\
    \    T kth_largest_sum(int l, int r, int k) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        assert(0 <= k && k <= r - l);\n        return kth_smallest_sum(l,\
    \ r, r - l) -\n               kth_smallest_sum(l, r, r - l - k);\n    }\n\n  \
    \  // count i s.t. (l <= i < r) && (v[i] < upper)\n    int range_freq(int l, int\
    \ r, T upper) {\n        if (upper >= (T(1) << lg)) return r - l;\n        int\
    \ ret = 0;\n        for (int h = lg - 1; h >= 0; --h) {\n            bool f =\
    \ (upper >> h) & 1;\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \            if (f) {\n                ret += r0 - l0;\n                l += bv[h].zeros\
    \ - l0;\n                r += bv[h].zeros - r0;\n            } else {\n      \
    \          l = l0;\n                r = r0;\n            }\n        }\n      \
    \  return ret;\n    }\n\n    T range_freq_sum(int l, int r, T upper) {\n     \
    \   if (upper >= (T(1) << lg)) return sum[lg][r] - sum[lg][l];\n        T ret\
    \ = 0;\n        for (int h = lg - 1; h >= 0; --h) {\n            bool f = (upper\
    \ >> h) & 1;\n            u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n    \
    \        if (f) {\n                l += bv[h].zeros - l0;\n                r +=\
    \ bv[h].zeros - r0;\n                ret += sum[h][r0] - sum[h][l0];\n       \
    \     } else {\n                l = l0;\n                r = r0;\n           \
    \ }\n        }\n        return ret;\n    }\n\n    // l <= x < r and lower <= y\
    \ < upper \u306A\u8981\u7D20\u306E\u500B\u6570\n    int range_freq(int l, int\
    \ r, T lower, T upper) {\n        return range_freq(l, r, upper) - range_freq(l,\
    \ r, lower);\n    }\n\n    // l <= x < r and lower <= y < upper \u306A\u8981\u7D20\
    \u306E\u7DCF\u548C\n    T range_freq_sum(int l, int r, T lower, T upper) {\n \
    \       return range_freq_sum(l, r, upper) - range_freq_sum(l, r, lower);\n  \
    \  }\n\n    // max v[i] s.t. (l <= i < r) && (v[i] < upper)\n    T prev_value(int\
    \ l, int r, T upper) {\n        int cnt = range_freq(l, r, upper);\n        return\
    \ cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n    }\n\n    // min v[i] s.t.\
    \ (l <= i < r) && (lower <= v[i])\n    T next_value(int l, int r, T lower) {\n\
    \        int cnt = range_freq(l, r, lower);\n        return cnt == r - l ? T(-1)\
    \ : kth_smallest(l, r, cnt);\n    }\n};"
  dependsOn:
  - src/base.hpp
  - src/datastructure/bit_vector.hpp
  isVerificationFile: false
  path: src/datastructure/WeightedWaveletMatrix.hpp
  requiredBy: []
  timestamp: '2024-05-31 16:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/WeightedWaveletMatrix.hpp
layout: document
redirect_from:
- /library/src/datastructure/WeightedWaveletMatrix.hpp
- /library/src/datastructure/WeightedWaveletMatrix.hpp.html
title: src/datastructure/WeightedWaveletMatrix.hpp
---
